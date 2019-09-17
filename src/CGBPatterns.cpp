#include "CGBPatterns.h"

using namespace agbplay;

// square wave LUT

const float CGBPatterns::pat_sq12[] = {
    0.875f, -0.125f, -0.125f, -0.125f, -0.125f, -0.125f, -0.125f, -0.125f
};
const float CGBPatterns::pat_sq25[] = {
    0.75f, 0.75f, -0.25f, -0.25f, -0.25f, -0.25f, -0.25f, -0.25f
};
const float CGBPatterns::pat_sq50[] = {
    0.50f, 0.50f, 0.50f, 0.50f, -0.50f, -0.50f, -0.50f, -0.50f
};
const float CGBPatterns::pat_sq75[] = {
    0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, -0.75, -0.75f
};

// noise channel frequency LUT
const float CGBPatterns::NoiseKeyToFreqLUT[] = {
    4.571428571428571f, 5.333333333333333f, 6.4f, 8.0f, 
    9.142857142857142f, 10.666666666666666f, 12.8f, 16.0f, 
    18.285714285714285f, 21.333333333333332f, 25.6f, 32.0f, 
    36.57142857142857f, 42.666666666666664f, 51.2f, 64.0f, 
    73.14285714285714f, 85.33333333333333f, 102.4f, 128.0f, 
    146.28571428571428f, 170.66666666666666f, 204.8f, 256.0f, 
    292.57142857142856f, 341.3333333333333f, 409.6f, 512.0f, 
    585.1428571428571f, 682.6666666666666f, 819.2f, 1024.0f, 
    1170.2857142857142f, 1365.3333333333333f, 1638.4f, 2048.0f, 
    2340.5714285714284f, 2730.6666666666665f, 3276.8f, 4096.0f, 
    4681.142857142857f, 5461.333333333333f, 6553.6f, 8192.0f, 
    9362.285714285714f, 10922.666666666666f, 13107.2f, 16384.0f, 
    18724.571428571428f, 21845.333333333332f, 26214.4f, 32768.0f, 
    37449.142857142855f, 43690.666666666664f, 52428.8f, 65536.0f, 
    87381.33333333333f, 131072.0f, 262144.0f, 524288.0f
};

const std::bitset<NOISE_FINE_LEN> CGBPatterns::pat_noise_fine = []() {
    std::bitset<NOISE_FINE_LEN> patt;
    int reg = 0x4000;
    for (size_t i = 0; i < NOISE_FINE_LEN; i++) {
        if ((reg & 1) == 1) {
            reg >>= 1;
            reg ^= 0x6000;
            patt[i] = true;
        } else {
            reg >>= 1;
            patt[i] = false;
        }
    }
    return patt;
}();

const std::bitset<NOISE_ROUGH_LEN> CGBPatterns::pat_noise_rough = []() {
    std::bitset<NOISE_ROUGH_LEN> patt;
    int reg = 0x40;
    for (size_t i = 0; i < NOISE_ROUGH_LEN; i++) {
        if ((reg & 1) == 1) {
            reg >>= 1;
            reg ^= 0x60;
            patt[i] = true;
        } else {
            reg >>= 1;
            patt[i] = false;
        }
    }
    return patt;
}();
