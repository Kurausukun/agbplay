#pragma once

#include <cstdint>
#include <string>

// for increased quality we process in subframes (including the base frame)
#define INTERFRAMES 1

namespace agbplay
{
    enum class CGBType : int { SQ1 = 0, SQ2, WAVE, NOISE };
    enum class EnvState : int { INIT = 0, ATK, DEC, SUS, REL, DIE, DEAD };
    enum class WaveDuty : int { D12 = 0, D25, D50, D75 };
    enum class NoisePatt : int { FINE = 0, ROUGH };
    enum class ReverbType { NORMAL, GS1, GS2, MGAT, TEST, NONE };
    enum class ResamplerType { NEAREST, LINEAR, SINC, BLEP };

    ReverbType str2rev(const std::string& str);
    std::string rev2str(ReverbType t);
    ResamplerType str2res(const std::string& str);
    std::string res2str(ResamplerType t);
    bool str2mono(const std::string& str);
    std::string mono2str(bool mono);

    union CGBDef
    {
        uint8_t *wavePtr;
        WaveDuty wd;
        NoisePatt np;
    };

    struct MixingArgs
    {
        float vol;
        uint32_t fixedModeRate;
        float sampleRateReciprocal;
        float nBlocksReciprocal;
    };

    struct ChnVol
    {
        ChnVol(float fromVolLeft, float fromVolRight, float toVolLeft, float toVolRight);
        ChnVol();
        float fromVolLeft;
        float fromVolRight;
        float toVolLeft;
        float toVolRight;
    };

    struct ADSR
    {
        ADSR(uint8_t att, uint8_t dec, uint8_t sus, uint8_t rel);
        ADSR();
        uint8_t att;
        uint8_t dec;
        uint8_t sus;
        uint8_t rel;
    };

    struct Note
    {
        Note(uint8_t midiKey, uint8_t velocity, int8_t length);
        Note();
        uint8_t midiKey;
        uint8_t originalKey;
        uint8_t velocity;
        int8_t length;
    };

    struct SampleInfo
    {
        SampleInfo(int8_t *samplePtr, float midCfreq, bool loopEnabled, uint32_t loopPos, uint32_t endPos);
        SampleInfo();
        int8_t *samplePtr;
        float midCfreq;
        uint32_t loopPos;
        uint32_t endPos;
        bool loopEnabled;
    };
}
