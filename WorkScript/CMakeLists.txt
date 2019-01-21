project(WorkScript)

set(WorkScript_CXX_FLAGS "-Wno-unused-variable")
set(CMAKE_CXX_FLAGS ${WorkScript_CXX_FLAGS})

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_EXE_LINKER_FLAGS "-static")

#LLVM依赖相关
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

message(STATUS "WorkScript Found LLVM ${LLVM_PACKAGE_VERSION}, Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "LLVM Library dir:${LLVM_LIBRARY_DIRS}, LLVM libs: ${llvm_libs}")


#ANTLR依赖相关
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/ANTLR/)
set(ANTLR4_ZIP_REPOSITORY ${CMAKE_CURRENT_SOURCE_DIR}/ANTLR/antlr-runtime.zip)
include(${CMAKE_CURRENT_SOURCE_DIR}/ANTLR/ExternalAntlr4Cpp.cmake)
include_directories(${ANTLR4_INCLUDE_DIRS})
find_package(ANTLR REQUIRED)

include(include_directories.cmake)

aux_source_directory(. WorkScript_src)
aux_source_directory(Parser/ WorkScript_src)
aux_source_directory(Parser/Generated/ WorkScript_src)
aux_source_directory(Exception/ WorkScript_src)
aux_source_directory(Program/ WorkScript_src)
aux_source_directory(Util/ WorkScript_src)
aux_source_directory(Context/ WorkScript_src)
aux_source_directory(SymbolTable/ WorkScript_src)
aux_source_directory(Type/ WorkScript_src)
aux_source_directory(Function/ WorkScript_src)
aux_source_directory(Tree/ WorkScript_src)

add_library(WorkScript STATIC ${WorkScript_src})

target_link_libraries(WorkScript antlr4_static)
target_link_libraries(WorkScript LLVM-7)
#target_link_libraries(WorkScript ${llvm_libs})
