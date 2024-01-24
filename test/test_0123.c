#include "../include/datahandler/datahandler.h"
#include "../include/datahandler/export_data.h"
#include "../include/layer/conv_layer.h"

int main(){
    struct FeatureMap* input = load_input_binary("../sample/lenaBGR.bin", 512, 512, 3);

    float weight[] = {-1, -1, -1,
                    0, 0, 0,
                    1, 1, 1,
                    -2, -2, -2,
                    0, 0, 0,
                    2, 2, 2,
                    -1, -1, -1,
                    0, 0, 0,
                    1, 1, 1};
    float bias[] = {0};

    struct Kernel kernel;
    kernel.row = 3;
    kernel.col = 3;
    kernel.channel = 3;
    kernel.num = 1;
    kernel.weight = weight;
    kernel.bias = bias;

    struct FeatureMap* output = Conv3D2(
        input,
        &kernel,
        1, 1, 0, 0
    );

    export_featuremap_binary("../sample/convBGR.bin", output);

    freeFeatureMap(output);
    freeFeatureMap(input);
}