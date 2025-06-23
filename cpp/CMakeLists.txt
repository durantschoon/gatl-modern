cmake_minimum_required(VERSION 3.21)
project(GATL-Wedge-Test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find nlohmann/json
find_package(nlohmann_json 3.11.2 REQUIRED)

# Add the wedge product test executable
add_executable(wedge_product_test tools/test/wedge_product_tests.cpp)

# Link nlohmann/json
target_link_libraries(wedge_product_test PRIVATE nlohmann_json::nlohmann_json)

# Include directories
target_include_directories(wedge_product_test PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/test
)

# Add test
add_test(NAME WedgeProductTest COMMAND wedge_product_test) 