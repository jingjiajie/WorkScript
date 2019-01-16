cmake_minimum_required(VERSION 3.8)
project(WorkScript)

#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

#add_definitions(-DANTLR4CPP_SHARED)
#include(ExternalAntlr4Cpp)
#include_directories(${ANTLR4_INCLUDE_DIRS})

#find_package(ANTLR REQUIRED)

#set(ANTLR_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/runtime/src)
#add_subdirectory(runtime)

#set(CMAKE_CXX_STANDARD 14)
#
#set(WorkScript_CXX_FLAGS "-Wno-unused-variable")
#set(LLVM_CXXFLAGS "-fuse-ld=gold -Wl,--no-keep-files-mapped -Wl,--no-map-whole-files -fPIC -fvisibility-inlines-hidden -Werror=date-time -Wall -W -Wno-unused-parameter -Wwrite-strings -Wcast-qual -Wno-missing-field-initializers -pedantic -Wno-long-long -Wno-maybe-uninitialized -Wdelete-non-virtual-dtor -Wno-comment -ffunction-sections -fdata-sections -O2 -DNDEBUG -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS")
#set(CMAKE_CXX_FLAGS "${LLVM_CXXFLAGS} ${WorkScript_CXX_FLAGS}")

#aux_source_directory(${PROJECT_SOURCE_DIR}/src WorkScript_SRC)
#aux_source_directory(${PROJECT_SOURCE_DIR}/src/Generated WorkScript_SRC)

#add_executable(wsi ${WorkScript_SRC})

set(ANTLR_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/ANTLR/src)

add_subdirectory(ANTLR)
add_subdirectory(src)

#target_link_libraries(wsi antlr4_shared)
#target_link_libraries(wsi LLVM-7)
