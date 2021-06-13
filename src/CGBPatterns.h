#pragma once

#include <bitset>

#define NOISE_FINE_LEN 32767
#define NOISE_ROUGH_LEN 127

namespace CGBPatterns
{
    // sample patterns
    extern const float pat_sq12[];
    extern const float pat_sq25[];
    extern const float pat_sq50[];
    extern const float pat_sq75[];
    
    // LUT for noise channel frequency
    extern const uint8_t NoiseKeyToFreqLUT[];

    extern const std::bitset<NOISE_FINE_LEN> pat_noise_fine;
    extern const std::bitset<NOISE_ROUGH_LEN> pat_noise_rough;
};
