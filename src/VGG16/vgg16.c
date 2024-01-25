#include "../../include/VGG16/vgg16.h"

struct Model* load_vgg16(){
    struct Model* vgg16 = (struct Model*)malloc(sizeof(struct Model));
    vgg16 -> num_conv_layer = 13;
    vgg16 -> num_fc_layer = 3;

    

    return vgg16;
}