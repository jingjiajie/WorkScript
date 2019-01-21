project(wsi)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#set(CMAKE_EXE_LINKER_FLAGS "-static")

##LLVM依赖相关
#find_package(LLVM REQUIRED CONFIG)
#message(STATUS "wsi Found LLVM ${LLVM_PACKAGE_VERSION}, Using LLVMConfig.cmake in: ${LLVM_DIR}")

include(${WorkScript_SOURCE_DIR}/include_directories.cmake)

include_directories(${wsi_SOURCE_DIR})

aux_source_directory(./ wsi_src)

add_executable(wsi ${wsi_src})
target_link_libraries(wsi WorkScript)