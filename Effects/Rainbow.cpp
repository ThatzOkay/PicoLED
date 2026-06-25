#include "Rainbow.hpp"
#include "PicoLed.hpp"
#include <cmath>

namespace PicoLed {

    Rainbow::Rainbow(PicoLedController &controller, double speed):
    PicoLedEffect(controller), hue(0.0), speed(speed)
    {
    }

    bool Rainbow::update(uint32_t timeGone, uint32_t timeNow) {
        hue = std::fmod(hue + speed * (double)timeGone / 1000.0, 256.0);
        controller.fill(HSV((uint8_t)hue, 255, 255));
        return true;
    }

}
