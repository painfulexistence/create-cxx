cmake_minimum_required(VERSION 3.20.0)

project()

set(FETCHCONTENT_QUIET FALSE)
set(BUILD_SHARED_LIBS OFF)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(SFML)
find_package(fmt CONFIG REQUIRED)

set(SOURCES
    src/main.cpp
)

add_executable(main ${SOURCES})
target_compile_features(main PRIVATE cxx_std_20)
set_target_properties(main PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(main PRIVATE fmt::fmt sfml-graphics sfml-audio)