#ifndef CONV_LAYER_H
#define CONV_LAYER_H

#include "../featuremap/featuremap.h"
#include "../layer/zeropadding_layer.h"

#include <pthread.h>

void calculate_conv_sz(
    const uint32_t input_row,
    const uint32_t input_col,
    const uint32_t kernel_row,
    const uint32_t kernel_col,
    const uint32_t stride_row,
    const uint32_t stride_col,
    const uint32_t padding_num,
    uint32_t* output_row,
    uint32_t* output_col
);

float patch_convolution(
    const float* input_data,
    const float* kernel_data,
    const uint32_t input_row,
    const uint32_t input_col,
    const uint32_t kernel_row,
    const uint32_t kernel_col,
    const uint32_t channel,
    const uint32_t bias
);

struct FeatureMap* Conv3D(
    const struct FeatureMap* input,
    const struct Kernel* kernel,
    const uint32_t stride_row,
    const uint32_t stride_col,
    const uint32_t padding_num,
    const uint8_t relu_opt
);

struct FeatureMap* Conv3D2(
    const struct FeatureMap* input,
    const struct Kernel* kernel,
    const uint32_t stride_row,
    const uint32_t stride_col,
    const uint32_t padding_num,
    const uint8_t relu_opt
);

#endif