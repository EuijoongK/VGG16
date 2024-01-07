#ifndef MAXPOOL_LAYER_H
#define MAXPOOL_LAYER_H

#include "../featuremap/featuremap.h"

void calculate_maxpool_sz(
    const uint32_t input_row,
    const uint32_t input_col,
    const uint32_t kernel_row,
    const uint32_t kernel_col,
    const uint32_t stride_row,
    const uint32_t stride_col,
    uint32_t* output_row,
    uint32_t* output_col
);

struct FeatureMap* Maxpool(
    const struct FeatureMap* input,
    const uint32_t kernel_row,
    const uint32_t kernel_col,
    const uint32_t stride_row,
    const uint32_t stride_col
);

#endif