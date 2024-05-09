cmake_minimum_required(VERSION 3.20.0)

project()

find_package(fmt CONFIG REQUIRED)
find_package(OGRE REQUIRED COMPONENTS Bites CONFIG)

set(SOURCES
    src/main.cpp
)

add_executable(main ${SOURCES})
target_compile_features(main PRIVATE cxx_std_20)
set_target_properties(main PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(main PRIVATE fmt::fmt OgreBites)