project(VGG_16)
cmake_minimum_required(VERSION 3.22)

set(SRC_DIR src)

set(FEATUREMAP_LIB_SRC
    ${SRC_DIR}/featuremap/featuremap.c
)

set(LAYER_LIB_SRC
    ${SRC_DIR}/layer/conv_layer.c
    ${SRC_DIR}/layer/zeropadding_layer.c
    ${SRC_DIR}/layer/maxpool_layer.c
    ${SRC_DIR}/layer/fc_layer.c
)

set(MODEL_LIB_SRC
    ${SRC_DIR}/model/model.c
)

set(DATAHANDLER_LIB_SRC
    ${SRC_DIR}/datahandler/datahandler.c
)

include_directories(include)

add_library(featuremap STATIC ${FEATUREMAP_LIB_SRC})
set_target_properties(featuremap PROPERTIES ARCHIVE_OUTPUT_DIRECTORY lib)

add_library(layer STATIC ${LAYER_LIB_SRC})
target_link_libraries(layer featuremap)
set_target_properties(layer PROPERTIES ARCHIVE_OUTPUT_DIRECTORY lib)

add_library(datahandler STATIC ${DATAHANDLER_LIB_SRC})
target_link_libraries(datahandler featuremap)
set_target_properties(datahandler PROPERTIES ARCHIVE_OUTPUT_DIRECTORY lib)

add_library(model STATIC ${MODEL_LIB_SRC})
target_link_libraries(model layer featuremap)
set_target_properties(model PROPERTIES ARCHIVE_OUTPUT_DIRECTORY lib)

add_executable(test test.c)
target_link_libraries(test featuremap layer model datahandler)