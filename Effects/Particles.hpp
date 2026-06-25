#ifndef PICOLEDEFFECT_PARTICLES_H
#define PICOLEDEFFECT_PARTICLES_H

#include <vector>
#include "PicoLed.hpp"
#include "Effects/EffectBase.hpp"

using std::vector;

namespace PicoLed {

class Particles: public EffectBase {

    public:
        struct ParticleSource {
            uint pixelIndex;
            double spawnRate;
            double spawnValue;
            double spawnSpeed;
        };

        struct Particle {
            double offset;
            double speed;
            uint8_t heat;
        };
        
        Particles(PicoLedController &controller, vector<Color> palette);
        Particles(PicoLedController &controller, vector<Color> palette, double spreadFactor);
        Particles(PicoLedController &controller, vector<Color> palette, double spreadFactor, double coolingRate);
        ~Particles();
        // Owns `heat` via raw new[]/delete[]; the default copy ctor/assignment
        // would shallow-copy that pointer and cause a double-free/use-after-free.
        Particles(const Particles&) = delete;
        Particles& operator=(const Particles&) = delete;

        void addSource(uint pixelIndex, double spawnRate);
        void addSource(uint pixelIndex, double spawnRate, double spawnSpeed);
        void addParticle(double offset, double speed, uint8_t heat);

    protected:
        vector<Color> palette;
        vector<ParticleSource> sources;
        vector<Particle> particles;
        uint8_t* heat;
        vector<uint> heatNew;
        double spreadFactor;

        uint8_t getHeatSpread(uint index);
        Color getHeatColor(uint8_t value);
        bool fadePixels(uint32_t timeNow);
        bool update(uint32_t timeGone, uint32_t timeNow);

};

}

#endif