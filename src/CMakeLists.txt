set(CMAKE_CXX_STANDARD 14)

set(WorkScript_CXX_FLAGS "-Wno-unused-variable")
set(LLVM_CXXFLAGS "-fuse-ld=gold -Wl,--no-keep-files-mapped -Wl,--no-map-whole-files -fPIC -fvisibility-inlines-hidden -Werror=date-time -Wall -W -Wno-unused-parameter -Wwrite-strings -Wcast-qual -Wno-missing-field-initializers -pedantic -Wno-long-long -Wno-maybe-uninitialized -Wdelete-non-virtual-dtor -Wno-comment -ffunction-sections -fdata-sections -O2 -DNDEBUG -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS")
set(CMAKE_CXX_FLAGS "${LLVM_CXXFLAGS} ${WorkScript_CXX_FLAGS}")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} wsi_src)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/Generated wsi_src)

include_directories(${ANTLR_INCLUDE_DIRS})

add_executable(wsi ${wsi_src})

target_link_libraries(wsi antlr4_shared)
target_link_libraries(wsi LLVM-7)
