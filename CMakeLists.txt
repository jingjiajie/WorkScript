cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0042 NEW)
cmake_policy(SET CMP0045 NEW)
cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0059 NEW)

add_subdirectory(utils)
add_subdirectory(WorkScript)
add_subdirectory(wsc)
add_subdirectory(ws)