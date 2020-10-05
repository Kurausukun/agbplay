#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>

#include "Types.h"

#define AGB_FPS 59.7275005696058L
#define N_CHANNELS 2

namespace agbplay
{
    class ReverbEffect
    {
        public:
            ReverbEffect(uint8_t intesity, size_t streamRate, uint8_t numAgbBuffers);
            virtual ~ReverbEffect();
            void ProcessData(float *buffer, size_t nBlocks);
        protected:
            virtual size_t processInternal(float *buffer, size_t nBlocks);
            size_t getBlocksPerBuffer() const;
            float intensity;
            //size_t streamRate;
            std::vector<float> reverbBuffer;
            size_t bufferPos;
            size_t bufferPos2;
    };

    class ReverbGS1 : public ReverbEffect
    {
        public:
            ReverbGS1(uint8_t intensity, size_t streamRate, uint8_t numAgbBuffers);
            ~ReverbGS1() override;
        protected:
            size_t processInternal(float *buffer, size_t nBlocks) override;
            size_t getBlocksPerGsBuffer() const;
            std::vector<float> gsBuffer;
    };

    class ReverbGS2 : public ReverbEffect
    {
        public:
            ReverbGS2(uint8_t intesity, size_t streamRate, uint8_t numAgbBuffers,
                    float rPrimFac, float rSecFac);
            ~ReverbGS2() override;
        protected:
            size_t processInternal(float *buffer, size_t nBlocks) override;
            std::vector<float> gs2Buffer;
            size_t gs2Pos;
            float rPrimFac, rSecFac;
    };

    class ReverbTest : public ReverbEffect
    {
        public:
            ReverbTest(uint8_t intesity, size_t streamRate, uint8_t numAgbBuffers);
            ~ReverbTest() override;
        protected:
            size_t processInternal(float *buffer, size_t nBlocks) override;
    };
}
