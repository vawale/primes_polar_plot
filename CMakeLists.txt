cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
message(STATUS "Using cmake ${CMAKE_VERSION} from ${CMAKE_COMMAND}")

project(PlotPrimes LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(CompilerOptions)
include(Dependencies)

add_subdirectory(src)
