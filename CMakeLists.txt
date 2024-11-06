cmake_minimum_required(VERSION 3.28)
project(Spectra)

set(CMAKE_CXX_STANDARD 20)

add_library(Spectra STATIC libspectra.cpp)

add_executable(SpectraTest test.cpp)
target_link_libraries(SpectraTest PRIVATE Spectra)
