project(wsi)

set(CMAKE_CXX_STANDARD 14)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG "/source-charset:utf-8 /MTd /Zi /Ob0 /Od /RTC1")
    set(CMAKE_CXX_FLAGS_RELEASE "/source-charset:utf-8 /MT /GL /GF /Ot /O2 /Ob2 /DNDEBUG")
    set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /GR /EHsc")
else ()
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif ()

#LLVM依赖相关
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIR})
add_definitions(${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(llvm_libs support core irreader executionengine interpreter mcjit x86asmparser x86asmprinter x86codegen x86desc x86disassembler x86info x86utils)
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4244 /wd4624 /wd4267 /wd4291 /wd4141 /wd4146")
endif ()


include(${WorkScript_SOURCE_DIR}/include_directories.cmake)

include_directories(${wsi_SOURCE_DIR})

aux_source_directory(./ wsi_src)

add_executable(wsi ${wsi_src})
target_link_libraries(wsi WorkScript)
target_link_libraries(wsi ${llvm_libs})