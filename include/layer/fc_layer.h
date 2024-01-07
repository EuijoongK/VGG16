#ifndef FC_LAYER_H
#define FC_LAYER_H

#include "../featuremap/featuremap.h"

struct arr1D* cvt_featuremap2arr1d(
    const struct FeatureMap* input
);

struct arr1D* Fullyconnect(
    const struct arr1D* input,
    const struct kernel1D* kernel
);

#endif