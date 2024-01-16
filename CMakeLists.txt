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

add_executable(test_0116 test/test_0116.c)
target_link_libraries(test_0116 featuremap layer model datahandler)
set_target_properties(test_0116 PROPERTIES ARCHIVE_OUTPUT_DIRECTORY bin)

add_executable(test_padding test/test_padding.c)
target_link_libraries(test_padding featuremap layer model datahandler)
set_target_properties(test_padding PROPERTIES ARCHIVE_OUTPUT_DIRECTORY bin)

add_executable(test_conv test/test_conv.c)
target_link_libraries(test_conv featuremap layer model datahandler)
set_target_properties(test_conv PROPERTIES ARCHIVE_OUTPUT_DIRECTORY bin)