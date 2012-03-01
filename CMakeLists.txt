cmake_minimum_required(VERSION 2.6)
# Acronym soup for Fractional Brownian Motion Monte Carlo Pricing
project(FBMMCP)

#Ensure we can find libraries installed via MacPorts
link_directories(/opt/local/lib)
include_directories(BEFORE 
	/opt/local/include 
	/opt/local/include/meschach)

# Add the Meschach library for matrix manipulations
find_library(meschach 
    NAMES
        meschach
    REQUIRED
)

# Add the libran library for random number generation
find_library(ranlib
	NAMES
		ranlib
	REQUIRED
)
add_library(Cov cov.c)

add_library(Circulant circulant.c)
target_link_libraries(Circulant meschach ranlib Cov)
add_library(Hosking hosking.c)
target_link_libraries(Hosking ranlib Cov)
add_library(FBMMCPOptions fbmmcp_options.c)

add_executable(fbmmcp fbmmcp.c fbmmcp.h)
target_link_libraries(fbmmcp meschach FBMMCPOptions Hosking Circulant)