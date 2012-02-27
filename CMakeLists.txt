cmake_minimum_required(VERSION 2.6)
# Acronym soup for Fractional Brownian Motion Monte Carlo Pricing
project(FBMMCP)

# Add the Meschach library for matrix manipulations
link_directories(/opt/local/lib)
include_directories(BEFORE 
	/opt/local/include 
	/opt/local/include/meschach)
find_library(meschach 
    NAMES
        meschach
    REQUIRED
)

add_library(Circulant circulant.c)
target_link_libraries(Circulant meschach)
add_library(Hosking hosking.c)
add_library(FBMMCPOptions fbmmcp_options.c)

add_executable(fbmmcp fbmmcp.c fbmmcp.h)
target_link_libraries(fbmmcp meschach FBMMCPOptions Hosking Circulant)