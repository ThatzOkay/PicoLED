#include "Pinwheel.hpp"
#include "PicoLed.hpp"
#include <cmath>

namespace PicoLed {

    Pinwheel::Pinwheel(PicoLedController &controller, vector<Color> palette, double blockLength, double speed):
    PicoLedEffect(controller), palette(palette), blockLength(blockLength), speed(speed), offset(0.0)
    {
    }

    bool Pinwheel::update(uint32_t timeGone, uint32_t timeNow) {
        uint numLeds = controller.getNumLeds();
        double cycleLength = blockLength * (double)palette.size();
        for (uint i = 0; i < numLeds; i++) {
            double position = std::fmod((double)i + offset, cycleLength);
            if (position < 0.0) {
                position += cycleLength;
            }
            uint blockIndex = (uint)(position / blockLength) % palette.size();
            controller.setPixelColor(i, palette[blockIndex]);
        }
        offset += (double)timeGone * speed / 1000.0;
        return true;
    }

}
