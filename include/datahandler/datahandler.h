#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "../featuremap/featuremap.h"

struct Kernel* load_con_kernel(
    char* file_weight,
    char* file_bias,
    uint32_t kernel_row,
    uint32_t kernel_col,
    uint32_t kernel_channel,
    uint32_t kernel_num
);

struct FeatureMap* load_input(
    char* file_name,
    uint32_t input_row,
    uint32_t input_col,
    uint32_t input_channel
);

#endif