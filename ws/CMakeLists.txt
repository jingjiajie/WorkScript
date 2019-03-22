project(ws)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG "/source-charset:utf-8 /MTd /Zi /Ob0 /Od /RTC1")
    set(CMAKE_CXX_FLAGS_RELEASE "/source-charset:utf-8 /MT /GL /GF /Ot /O2 /Ob2 /DNDEBUG")
    set(WSI_MSVC_DEFINITIONS "/DWIN32 /D_WINDOWS /D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING /D_CRT_SECURE_NO_WARNINGS")
    set(CMAKE_CXX_FLAGS "/MP /GR /EHsc ${WSI_MSVC_DEFINITIONS}")
else ()
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_EXE_LINKER_FLAGS "")
endif ()

include_directories(${utils_SOURCE_DIR})

aux_source_directory(./ ws_src)

add_executable(ws ${ws_src})
target_link_libraries(ws utils)