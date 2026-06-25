#include "Fade.hpp"
#include "PicoLed.hpp"
#include <cmath>

namespace PicoLed {

    Fade::Fade(PicoLedController &controller, Color color, double fadeRate):
    EffectBase(controller, color, fadeRate),
    breatheColorA(color), breatheColorB(color), breathing(false), speed(0.0), phase(0.0)
    {
    }

    Fade::Fade(PicoLedController &controller, Color colorA, Color colorB, double speed):
    EffectBase(controller, colorA, 1.0),
    breatheColorA(colorA), breatheColorB(colorB), breathing(true), speed(speed), phase(0.0)
    {
    }

    bool Fade::update(uint32_t timeGone, uint32_t timeNow) {
        if (!breathing) {
            return fadePixels(timeNow);
        }
        // Cap redraws to ~60fps instead of calling the blocking WS2812 show()
        // on every single core1 pass (tens of thousands of times/sec), which
        // starved everything else and looked stuttery.
        if (timeGone < 16) {
            return false;
        }
        phase += (double)timeGone / 1000.0 * speed * 2.0 * M_PI;
        double ratio = (std::sin(phase) + 1.0) / 2.0;
        controller.fill(MixColors(breatheColorB, breatheColorA, ratio));
        return true;
    }

}
