#include "../include/layer/conv_layer.h"
#include "../include/datahandler/datahandler.h"
#include "../include/datahandler/export_data.h"
#include "../include/featuremap/featuremap.h"

int main(){
    printf("Loading input...\n");
    struct FeatureMap* input = load_input_binary("./export/lena.bin", 512, 512, 3);
    printf("Loading input success\n");

    float weight[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1,
                        -1, 0, 1, -2, 0, 2, -1, 0, 1,
                        -1, 0, 1, -2, 0, 2, -1, 0, 1};
    float bias[] = {0};

    struct Kernel kernel;
    kernel.row = 3;
    kernel.col = 3;
    kernel.channel = 3;
    kernel.num = 1;
    kernel.weight = weight;
    kernel.bias = bias;

    printf("Convolution...\n");
    struct FeatureMap* output = Conv3D(input, &kernel, 1, 1, 0, 0);
    printf("Done\n");

    printf("Writing output in binary file...\n");
    export_featuremap_binary("./test_0121.bin", output);
    printf("Successfully written output file\n");
    
    freeFeatureMap(output);
    freeFeatureMap(input);
}