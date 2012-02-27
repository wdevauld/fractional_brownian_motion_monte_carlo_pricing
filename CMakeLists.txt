cmake_minimum_required(VERSION 2.6)
# Acronym soup for Fractional Brownian Motion Monte Carlo Pricing
project(FBMMCP)

# External Libraries for generating fBM
find_library(MESCHACH 
    NAMES
        meschach matrix2
    PATHS
        /opt/local/include/meschach
        /usr/lib
        /usr/local/lib
) 
add_library(Circulant circulant.c)
add_library(Hosking hosking.c)
