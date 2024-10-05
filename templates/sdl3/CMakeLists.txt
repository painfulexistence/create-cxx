cmake_minimum_required(VERSION 3.20.0)

project()

set(FETCHCONTENT_QUIET FALSE)
set(BUILD_SHARED_LIBS OFF)
option(SDL_TEST_LIBRARY OFF)
include(FetchContent)
FetchContent_Declare(SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    # TODO: Update to stable version when it comes out
    GIT_TAG preview-3.1.3
    GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(SDL3)
find_package(fmt CONFIG REQUIRED)

set(SOURCES
    src/main.cpp
)

add_executable(main ${SOURCES})
target_compile_features(main PRIVATE cxx_std_20)
set_target_properties(main PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(main PRIVATE fmt::fmt SDL3::SDL3)