#ifndef PICOLEDEFFECT_FADE_H
#define PICOLEDEFFECT_FADE_H

#include "Effects/EffectBase.hpp"

namespace PicoLed {

class Fade: public EffectBase {

    public:
        Fade(PicoLedController &controller, Color color, double fadeRate);
        // Breathing variant: continuously fades back and forth between colorA and colorB.
        // speed is in breath cycles per second (e.g. 0.3 == one full breath every ~3.3s).
        Fade(PicoLedController &controller, Color colorA, Color colorB, double speed);

    protected:
        Color breatheColorA;
        Color breatheColorB;
        bool breathing;
        double speed;
        double phase;

        bool update(uint32_t timeGone, uint32_t timeNow);

};

}

#endif
