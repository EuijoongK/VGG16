#include "../../include/model/model.h"

void add_input(
    struct Model* model,
    struct FeatureMap* input
){
    model -> conv_layer_list[0] = input;
    model -> num_conv_layer = 0;
    model -> num_fc_layer = 0;
    return;
}

void add_conv_layer(
    struct Model* model,
    struct Kernel* kernel
){
    model -> num_conv_layer++;
    uint32_t index = model -> num_conv_layer - 1;
    model -> conv_kernel_list[index] = kernel;
    return;
}

void run_conv_layer(
    struct Model* model,
    const uint32_t index,
    const uint32_t stride_row,
    const uint32_t stride_col,
    const uint32_t padding_num,
    const uint32_t relu_opt
){
    struct FeatureMap* input = model -> conv_layer_list[index];
    struct Kernel* kernel = model -> conv_kernel_list[index];
    struct FeatureMap* output = Conv3D(input, kernel, stride_row,
                                    stride_col, padding_num, relu_opt);
    model -> conv_layer_list[index + 1] = output;
    return;
}

void add_fc_layer(
    struct Model* model,
    struct kernel1D* kernel
){
    model -> num_fc_layer++;
    uint32_t index = model -> num_fc_layer;
    model -> fc_kernel_list[index] = kernel;
    return;
}

void run_fc_layer(
    struct Model* model,
    const uint32_t index,
    const uint32_t relu_opt
){
    struct arr1D* input = model -> fc_layer_list[index];
    struct kernel1D* kernel = model -> fc_kernel_list[index];
    struct arr1D* output = Fullyconnect(input, kernel);
    model -> fc_layer_list[index + 1] = output;
    return;
}

void run_model(struct Model* model){
    const uint32_t num_conv_layer = model -> num_conv_layer;
    const uint32_t num_fc_layer = model -> num_fc_layer;
    uint32_t i;
    for(i = 0; i < num_conv_layer; ++i){
        run_conv_layer(model, i, 1, 1, 1, 1);
    }
    struct arr1D* flattened_layer = cvt_featuremap2arr1d(model -> conv_layer_list[num_conv_layer]);
    model -> fc_layer_list[0] = flattened_layer;
    for(i = 0; i < num_fc_layer; ++i){
        run_fc_layer(model, i, 1);
    }
    return;
}

struct arr1D* get_model_output(struct Model* model){
    return model -> fc_layer_list[model -> num_fc_layer];
}

void freeModel(struct Model* model){
    for(uint32_t i = 0; i < model -> num_conv_layer; ++i){
        free(model -> conv_layer_list[i]);
        free(model -> conv_kernel_list[i]);
    }
    for(uint32_t i = 0; i < model -> num_fc_layer; ++i){
        free(model -> fc_layer_list[i]);
        free(model -> fc_kernel_list[i]);
    }
    free(model);
    return;
}