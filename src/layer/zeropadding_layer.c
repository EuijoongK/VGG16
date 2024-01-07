#include "../../include/layer/zeropadding_layer.h"

struct FeatureMap* Zeropadding(
    const struct FeatureMap* input,
    const uint32_t padding_num
){
    struct FeatureMap* output = Zeropadd(input, padding_num);
    return output;
}