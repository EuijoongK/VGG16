#ifndef EXPORT_DATA_H
#define EXPORT_DATA_H

#include "../featuremap/featuremap.h"

void export_featuremap_binary(
    char* file_name,
    struct FeatureMap* target
);

#endif