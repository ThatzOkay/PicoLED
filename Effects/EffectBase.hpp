#ifndef PICOLEDEFFECT_EFFECTBASE_H
#define PICOLEDEFFECT_EFFECTBASE_H

#include "PicoLedEffect.hpp"

namespace PicoLed {

class EffectBase: public PicoLedEffect {

    public:
        EffectBase(PicoLedController &controller, Color color, double fadeRate);

        void reset();

    protected:
        Color fadeColor;
        double fadeRate;
        uint32_t fadeLastTick;

        bool fadePixels(uint32_t timeNow);

};

}

#endif
