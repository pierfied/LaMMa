cmake_minimum_required(VERSION 3.15)
project(LaMMa)

include(ExternalProject)

set(CMAKE_CXX_STANDARD 17)

set(HEALPIX /path/to/healpix)

# Enable optimization and use LAPACK flags.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 ${LAPACK_FLAGS}")

# Set install directory for external libraries.
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

# Add chronos library to project.
ExternalProject_Add(chronos_lib GIT_REPOSITORY https://github.com/pierfied/chronos
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION})

# Add include and lib directories for chronos and LAPACK.
include_directories(${EXTERNAL_INSTALL_LOCATION}/include ${HEALPIX}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib ${HEALPIX}/lib)

add_library(lamma SHARED src/lamma.cpp src/lamma.h)

add_dependencies(lamma chronos_lib)

target_link_libraries(lamma m libchronos.a libhealpix_cxx.a)