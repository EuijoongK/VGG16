#ifndef MODEL_H
#define MODEL_H

#define MAX_LAYER_NUM 20

#include "../featuremap/featuremap.h"
#include "../layer/conv_layer.h"
#include "../layer/zeropadding_layer.h"
#include "../layer/maxpool_layer.h"
#include "../layer/fc_layer.h"

struct Model{
    struct FeatureMap* con_layer_list[MAX_LAYER_NUM];
    struct Kernel* con_kernel_list[MAX_LAYER_NUM];
    uint32_t num_con_layer;

    struct arr1D* fc_layer_list[MAX_LAYER_NUM];
    struct kernel1D* fc_kernel_list[MAX_LAYER_NUM];
    uint32_t num_fc_layer;
};

void add_input(
    struct Model* model,
    struct FeatureMap* input
);

void add_con_layer(
    struct Model* model,
    struct Kernel* kernel
);

void run_con_layer(
    struct Model* model,
    const uint32_t index,
    const uint32_t stride_row,
    const uint32_t stride_col,
    const uint32_t padding_num,
    const uint32_t relu_opt
);

void add_fc_layer(
    struct Model* model,
    struct kernel1D* kernel
);

void run_fc_layer(
    struct Model* model,
    const uint32_t index,
    const uint32_t relu_opt
);

void run_model(struct Model* model);
struct arr1D* get_model_output(struct Model* model);

void freeModel(struct Model* model);

#endif