#include "EffectBase.hpp"
#include "PicoLed.hpp"

using std::max;

namespace PicoLed {

    EffectBase::EffectBase(PicoLedController &controller, Color color, double fadeRate):
    PicoLedEffect(controller), fadeColor(color), fadeRate(fadeRate),
    fadeLastTick(to_ms_since_boot(get_absolute_time()))
    {
    }

    void EffectBase::reset() {
        PicoLedEffect::reset();
        fadeLastTick = to_ms_since_boot(get_absolute_time());
    }

    bool EffectBase::fadePixels(uint32_t timeNow) {
        uint32_t timeGone = timeNow - fadeLastTick;
        uint32_t fadeInterval = max<uint32_t>(1, 1000.0 / 255.0 / fadeRate);
        if (timeGone > fadeInterval) {
            uint8_t fadeValue = timeGone / fadeInterval;
            controller.fadeValue(fadeColor, fadeValue);
            fadeLastTick = timeNow - (timeGone % fadeInterval);
            return true;
        } else {
            return false;
        }
    }

}
