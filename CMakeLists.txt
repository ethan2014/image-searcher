cmake_minimum_required (VERSION 3.0.2)
project (ImageSearcher)
set (CMAKE_EXPORT_COMPILE_COMMANDS "ON")
set (CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -pedantic")
set (IMAGE_SEARCHER_SRC
  src/main.cpp)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# search for pkg-config
include (FindPkgConfig)
if (NOT PKG_CONFIG_FOUND)
  message (FATAL_ERROR "pkg-config not found")
endif ()

# check for libpng
pkg_check_modules (LIBPNG libpng REQUIRED)
if (NOT LIBPNG_FOUND)
  message(FATAL_ERROR "You don't seem to have libpng development libraries installed")
else ()
  include_directories (${LIBPNG_INCLUDE_DIRS})
  link_directories (${LIBPNG_LIBRARY_DIRS})
  link_libraries (${LIBPNG_LIBRARIES})
endif ()

# check for libpng++
#pkg_check_modules (LIBPNGPP libpng++ REQUIRED)
#if (NOT LIBPNGPP_FOUND)
#  message(FATAL_ERROR "You don't seem to have libpng++ development libraries installed")
#else ()
#  include_directories (${LIBPNGPP_INCLUDE_DIRS})
#  link_directories (${LIBPNGPP_LIBRARY_DIRS})
#  link_libraries (${LIBPNGPP_LIBRARIES})
#endif ()

add_executable (image-searcher ${IMAGE_SEARCHER_SRC} ${LIBPNG_LINK_FLAGS})
