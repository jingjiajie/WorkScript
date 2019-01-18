project(wsi)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

include_directories(../ANTLR/src)

include(${WorkScript_SOURCE_DIR}/include_directories.cmake)

include_directories(${wsi_SOURCE_DIR})
include_directories(${wsi_SOURCE_DIR}/Parser)
include_directories(${wsi_SOURCE_DIR}/Parser/Generated)

aux_source_directory(./ wsi_src)
aux_source_directory(./Parser wsi_src)
aux_source_directory(./Parser/Generated wsi_src)
add_executable(wsi ${wsi_src})
target_link_libraries(wsi WorkScript)