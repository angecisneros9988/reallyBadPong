cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)


add_executable(main src/main.cpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)
# # change this for when you dont want to download entire repo and have it run locally:
# cmake_minimum_required(VERSION 3.10)
# project(CMakeSFMLProject LANGUAGES CXX)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# set(SFML_STATIC_LIBRARIES ON)
# find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

# add_executable(main src/main.cpp)
# target_compile_features(main PRIVATE cxx_std_17)
# target_link_libraries(main PRIVATE SFML::Graphics)