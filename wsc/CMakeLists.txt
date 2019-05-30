project(wsc)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG "/source-charset:utf-8 /MTd /Zi /Ob0 /Od /RTC1")
    set(CMAKE_CXX_FLAGS_RELEASE "/source-charset:utf-8 /MT /GL /GF /Ot /O2 /Ob2 /DNDEBUG")
	set(WSI_MSVC_DEFINITIONS "/DWIN32 /D_WINDOWS /D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING /D_CRT_SECURE_NO_WARNINGS")
    set(CMAKE_CXX_FLAGS "/MP /GR /EHsc ${WSI_MSVC_DEFINITIONS}")
else ()
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_EXE_LINKER_FLAGS "")
endif ()

#LLVM依赖相关
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIR})
add_definitions(${LLVM_DEFINITIONS})
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4244 /wd4624 /wd4267 /wd4291 /wd4141 /wd4146")
endif ()


include(${WorkScript_SOURCE_DIR}/include_directories.cmake)
include_directories(${wsc_SOURCE_DIR})
include_directories(${utils_SOURCE_DIR})

aux_source_directory(./ wsc_src)

add_executable(wsc ${wsc_src})
target_link_libraries(wsc utils)
target_link_libraries(wsc WorkScript)

INSTALL(
        TARGETS wsc
        RUNTIME DESTINATION bin
)