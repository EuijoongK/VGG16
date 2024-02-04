#include "../include/model/model.h"

int main(){
    struct Model* model = (struct Model*)malloc(sizeof(struct Model));
    struct Kernel* kernel = (struct Kernel*)malloc(sizeof(struct Kernel));
    
    float weight[] = {1, 2, 3, 4};
    float bias[] = {0};

    kernel -> row = 2;
    kernel -> col = 2;
    kernel -> channel = 1;
    kernel -> num = 1;
    kernel -> weight = weight;
    kernel -> bias = bias;

    add_conv_layer(model, kernel, 1, 2, 3, 1);

    printf("Num of layer in model : %d\n", model -> num_layer);
    printf("Num of convolution layer in model : %d\n", model -> num_conv_layer);

    free(model);
    free(kernel);
}