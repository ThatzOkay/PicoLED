#ifndef PICOLEDEFFECT_RAINBOW_H
#define PICOLEDEFFECT_RAINBOW_H

#include "PicoLedEffect.hpp"

namespace PicoLed {

class Rainbow: public PicoLedEffect {

    public:
        Rainbow(PicoLedController &controller, double speed);

    protected:
        double hue;
        double speed;

        bool update(uint32_t timeGone, uint32_t timeNow);

};

}

#endif
