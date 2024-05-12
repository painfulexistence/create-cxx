cmake_minimum_required(VERSION 3.20.0)

project()

set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib)
find_package(fmt CONFIG REQUIRED)

set(SOURCES
    src/main.cpp
)

add_executable(main ${SOURCES})
target_compile_features(main PRIVATE cxx_std_20)
set_target_properties(main PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(main PRIVATE fmt::fmt raylib)