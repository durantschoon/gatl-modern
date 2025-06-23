# Copyright (C) Leandro Augusto Frata Fernandes
#
# author     : Fernandes, Leandro A. F.
# e-mail     : laffernandes@ic.uff.br
# home page  : http://www.ic.uff.br/~laffernandes
# repository : https://github.com/laffernandes/gatl.git
#
# This file is part of The Geometric Algebra Template Library (GATL).
#
# GATL is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# GATL is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GATL. If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.20)

set(VERSION_MAJOR 2)
set(VERSION_MINOR 2)
set(VERSION_PATCH 3)

project(GATL
  VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
  DESCRIPTION "GATL: Geometric Algebra Template Library"
  LANGUAGES CXX
)

# Modernize C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the include-only library
add_library(gatl INTERFACE)
target_include_directories(gatl INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# Install headers
install(DIRECTORY ./include/ DESTINATION include FILES_MATCHING PATTERN "*.hpp")

# Optional: install CMake config files
configure_file("./cmake/GATLConfig.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/GATLConfig.cmake" @ONLY NEWLINE_STYLE UNIX)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/GATLConfig.cmake" DESTINATION lib/gatl)

configure_file("./cmake/GATLConfigVersion.cmake.in" "${CMAKE_CURRENT_BINARY_DIR}/GATLConfigVersion.cmake" @ONLY NEWLINE_STYLE UNIX)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/GATLConfigVersion.cmake" DESTINATION lib/gatl)

# ------------------------
# Test setup (doctest)
# ------------------------
enable_testing()

add_executable(gatl_tests
  tools/test/main.cpp
)

target_include_directories(gatl_tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/tools/test/external
)

target_link_libraries(gatl_tests PRIVATE gatl)

add_test(NAME gatl_tests COMMAND gatl_tests)
