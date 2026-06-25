#ifndef PICOLEDEFFECT_PINWHEEL_H
#define PICOLEDEFFECT_PINWHEEL_H

#include <vector>
#include "PicoLedEffect.hpp"

using std::vector;

namespace PicoLed {

class Pinwheel: public PicoLedEffect {

    public:
        Pinwheel(PicoLedController &controller, vector<Color> palette, double blockLength, double speed);

    protected:
        vector<Color> palette;
        double blockLength;
        double speed;
        double offset;

        bool update(uint32_t timeGone, uint32_t timeNow);

};

}

#endif
