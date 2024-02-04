#include "../../include/model/model.h"

void init(struct Model* model){
    model -> num_layer = 0;
    model -> num_conv_layer = 0;
    model -> num_fc_layer = 0;
    return;
}

void add_input(
    struct Model* model,
    struct FeatureMap* input
){
    model -> featuremap_list[0] = input;
    return;
}

void add_conv_layer(
    struct Model* model,
    struct Kernel* kernel,
    const uint32_t stride_row,
    const uint32_t stride_col,
    const uint32_t padding_num,
    const uint32_t relu_opt
){  
    uint32_t model_index = model -> num_layer;
    uint32_t conv_index = model -> num_conv_layer;

    model -> layer[model_index] = CONV;
    model -> conv_kernel_list[conv_index] = kernel;

    struct ConvParam conv_param;
    conv_param.stride_row = stride_row;
    conv_param.stride_col = stride_col;
    conv_param.padding_num = padding_num;
    conv_param.relu_opt = relu_opt;

    *(model -> conv_param + conv_index) = conv_param;

    ++(model -> num_layer);
    ++(model -> num_conv_layer);
    return;
}

void add_fc_layer(
    struct Model* model,
    struct kernel1D* kernel
){
    /*
    uint32_t index = model -> num_fc_layer;
    model -> layer[model -> num_layer++] = FC;
    model -> fc_kernel_list[index] = kernel;
    model -> num_fc_layer++;

    return;
    */
}

void run_conv_layer(
    struct Model* model,
    const uint32_t index,
    const uint32_t conv_index
){
    /*
    uint32_t stride_row = model -> stride_row_arr[conv_index];
    uint32_t stride_col = model -> stride_col_arr[conv_index];
    uint32_t padding_num = model -> padding_num_arr[conv_index];
    uint32_t relu_opt = model -> relu_opt_arr[conv_index];

    struct FeatureMap* input = model -> featuremap_list[index];
    struct Kernel* kernel = model -> conv_kernel_list[conv_index];

    struct FeatureMap* output = Conv3D(
        input, kernel, stride_row, stride_col, padding_num, relu_opt
    );

    model -> featuremap_list[index + 1] = output;
    return;
    */
}

void run_model(struct Model* model){
    /*
    uint32_t index = 0;
    uint32_t conv_index = 0;
    uint32_t fc_index = 0;
    uint32_t end_index = model -> num_layer;
    for(; index < end_index; ++index){
        if(model -> layer[index] == CONV){
            run_conv_layer(model, index, conv_index);
            ++conv_index;
        }else if(model -> layer[index] == FC){

        }else if(model -> layer[index] == MAXPOOL){

        }
    }
    */
}

struct arr1D* get_model_output(struct Model* model){
    
}

void freeModel(struct Model* model){
    /*
    for(uint32_t i = 0; i < model -> num_conv_layer; ++i){
        free(model -> conv_layer_list[i]);
        free(model -> conv_kernel_list[i]);
    }
    for(uint32_t i = 0; i < model -> num_fc_layer; ++i){
        free(model -> fc_layer_list[i]);
        free(model -> fc_kernel_list[i]);
    }
    */
    free(model);
    return;
}