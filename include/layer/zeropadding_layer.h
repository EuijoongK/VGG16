#ifndef ZEROPADDING_LAYER_H
#define ZEROPADDING_LAYER_H

#include "../featuremap/featuremap.h"

struct FeatureMap* Zeropadding(
    const struct FeatureMap* input,
    const uint32_t padding_num
);

struct FeatureMap* Zeropadding2(
    const struct FeatureMap* input,
    const uint32_t padding_num
);

#endif