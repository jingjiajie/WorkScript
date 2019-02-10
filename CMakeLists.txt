cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0042 NEW)
cmake_policy(SET CMP0045 NEW)
cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0059 NEW)

add_subdirectory(WorkScript)
add_subdirectory(wsi)

#TODO List:
#ANTLR语法错误的时候不能正确恢复
#AbstractContext生成函数时没考虑父级可能已经存在的函数