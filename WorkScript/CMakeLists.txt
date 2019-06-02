project(WorkScript)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG "/source-charset:utf-8 /MTd /Zi /Ob0 /Od /RTC1")
    set(CMAKE_CXX_FLAGS_RELEASE "/source-charset:utf-8 /MT /GL /GF /Ot /O2 /Ob2 /DNDEBUG")
	set(WS_MSVC_DEFINITIONS "/DWIN32 /D_WINDOWS /D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING /D_CRT_SECURE_NO_WARNINGS")
    set(CMAKE_CXX_FLAGS "/MP /GR /EHsc ${WS_MSVC_DEFINITIONS}")
else()  
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_EXE_LINKER_FLAGS "")
endif()

include_directories(${utils_SOURCE_DIR})

#LLVM依赖相关
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIR})
add_definitions(${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(llvm_libs support core irreader executionengine interpreter mcjit x86asmparser x86asmprinter x86codegen x86desc x86disassembler x86info x86utils)
#llvm_map_components_to_libnames(llvm_libs
#        aarch64asmparser aarch64asmprinter aarch64codegen aarch64desc aarch64disassembler aarch64info aarch64utils
#        aggressiveinstcombine
#        amdgpuasmparser amdgpuasmprinter amdgpucodegen amdgpudesc amdgpudisassembler amdgpuinfo amdgpuutils
#        analysis
#        armasmparser armasmprinter armcodegen armdesc armdisassembler arminfo armutils asmparser asmprinter
#        binaryformat bitreader bitwriter
#        bpfasmparser bpfasmprinter bpfcodegen bpfdesc bpfdisassembler bpfinfo
#        codegen core coroutines coverage debuginfocodeview debuginfodwarf debuginfomsf debuginfopdb demangle
#
#        dlltooldriver executionengine fuzzmutate globalisel
#        hexagonasmparser hexagoncodegen hexagondesc hexagondisassembler hexagoninfo
#        instcombine instrumentation interpreter ipo irreader
#
#        lanaiasmparser lanaiasmprinter lanaicodegen lanaidesc lanaidisassembler lanaiinfo libdriver lineeditor
#        linker lto mc mcdisassembler mcjit mcparser
#        mipsasmparser mipsasmprinter mipscodegen mipsdesc mipsdisassembler mipsinfo
#        mirparser
#
#        msp430asmprinter msp430codegen msp430desc msp430info
#        native nativecodegen
#        nvptxasmprinter nvptxcodegen nvptxdesc nvptxinfo
#        objcarcopts object objectyaml option orcjit passes
#        powerpcasmparser powerpcasmprinter powerpccodegen powerpcdesc powerpcdisassembler powerpcinfo
#        profiledata runtimedyld scalaropts selectiondag
#        sparcasmparser sparcasmprinter sparccodegen sparcdesc sparcdisassembler sparcinfo
#        support symbolize
#        systemzasmparser systemzasmprinter systemzcodegen systemzdesc systemzdisassembler systemzinfo
#        tablegen target transformutils vectorize windowsmanifest
#        x86asmparser x86asmprinter x86codegen x86desc x86disassembler x86info x86utils
#        xcoreasmprinter xcorecodegen xcoredesc xcoredisassembler xcoreinfo)
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4244 /wd4624 /wd4267 /wd4291 /wd4141 /wd4146")
endif()

#ANTLR依赖相关
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/ANTLR/)
set(ANTLR_EXECUTABLE "${CMAKE_CURRENT_SOURCE_DIR}/ANTLR/antlr.jar")
set(ANTLR4_ZIP_REPOSITORY ${CMAKE_CURRENT_SOURCE_DIR}/ANTLR/antlr-runtime.zip)
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(ANTLR4_WITH_STATIC_CRT ON)
    add_definitions(/DANTLR4CPP_STATIC)
else()
    add_definitions(-DANTLR4CPP_STATIC)
endif()
include(${CMAKE_CURRENT_SOURCE_DIR}/ANTLR/ExternalAntlr4Cpp.cmake)
find_package(ANTLR REQUIRED)
include_directories(${ANTLR4_INCLUDE_DIRS})

include(include_directories.cmake)

aux_source_directory(. WorkScript_src)
aux_source_directory(Parser/ WorkScript_src)
aux_source_directory(Parser/Generated/ WorkScript_src)
aux_source_directory(Report/ WorkScript_src)
aux_source_directory(Exception/ WorkScript_src)
aux_source_directory(Module/ WorkScript_src)
aux_source_directory(Util/ WorkScript_src)
aux_source_directory(Context/ WorkScript_src)
aux_source_directory(SymbolTable/ WorkScript_src)
aux_source_directory(Type/ WorkScript_src)
aux_source_directory(Function/ WorkScript_src)
aux_source_directory(Tree/ WorkScript_src)
aux_source_directory(Module/ WorkScript_src)

add_library(WorkScript STATIC ${WorkScript_src})

target_link_libraries(WorkScript utils)
target_link_libraries(WorkScript antlr4_static)
target_link_libraries(WorkScript ${llvm_libs})
