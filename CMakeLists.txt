cmake_minimum_required(VERSION 2.6)
# Acronym soup for Fractional Brownian Motion Monte Carlo Pricing
project(FBMMCP)

# Allow for libraries on OSX installed by MacPorts to be found...
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /opt/local/lib)
include_directories(BEFORE /opt/local/include /opt/local/include/meschach)

# External Libraries for generating fBM
find_library(MESCHACH 
    NAMES
        meschach
    REQUIRED
) 
add_library(Circulant circulant.c)
target_link_libraries(Circulant MESCHACH)
add_library(Hosking hosking.c)

add_executable(fbmmcp fbmmcp.c)
