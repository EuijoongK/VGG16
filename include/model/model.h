#ifndef MODEL_H
#define MODEL_H

#define MAX_LAYER_NUM 20

#include "../featuremap/featuremap.h"
#include "../layer/conv_layer.h"
#include "../layer/zeropadding_layer.h"
#include "../layer/maxpool_layer.h"
#include "../layer/fc_layer.h"
#include "../datahandler/datahandler.h"

#define CONV 1
#define MAXPOOL 2
#define ZEROPADD 3
#define FC 4

struct Model{
    uint32_t layer[MAX_LAYER_NUM];

    struct FeatureMap* conv_layer_list[MAX_LAYER_NUM];
    struct Kernel* conv_kernel_list[MAX_LAYER_NUM];
    uint32_t num_conv_layer;

    struct arr1D* fc_layer_list[MAX_LAYER_NUM];
    struct kernel1D* fc_kernel_list[MAX_LAYER_NUM];
    uint32_t num_fc_layer;
};

void add_input(
    struct Model* model,
    struct FeatureMap* input
);

void add_conv_layer(
    struct Model* model,
    struct Kernel* kernel
);

void run_conv_layer(
    struct Model* model,
    convst uint32_t index,
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