cmake_minimum_required(VERSION 3.20.0)

project()

set(FETCHCONTENT_QUIET FALSE)
set(SDL_SHARED_DEFAULT OFF)
set(SDL_SHARED_AVAILABLE OFF)
option(SDL_TEST_LIBRARY OFF)
find_package(sdl2 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

set(SOURCES
    src/main.cpp
)

add_executable(main ${SOURCES})
target_compile_features(main PRIVATE cxx_std_20)
set_target_properties(main PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(main PRIVATE fmt::fmt SDL2::SDL2)