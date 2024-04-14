cmake_minimum_required(VERSION 3.21)

option(GLOBAL_VCPKG "Use global Vcpkg " OFF)
if (GLOBAL_VCPKG)
    set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
else()
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)
endif()

option(EMSCRIPTEN "Emscripten" OFF)
if (EMSCRIPTEN)
    set(VCPKG_CHAINLOAD_TOOLCHAIN_FILE $ENV{EMSDK}/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake CACHE STRING "Emscripten toolchain file")
    set(VCPKG_TARGET_TRIPLET wasm32-emscripten)
endif()

option(CCACHE "Use ccache to speed up recompilation" ON)
if(CCACHE)
    find_program(CCACHE_FOUND ccache)
    if(CCACHE_FOUND)
        set(PATH_TO_CCACHE ccache)
    else()
        message(WARNING "Ccache path not found, disabling ccache")
    endif(CCACHE_FOUND)
    set(CXX_COMPILER_LAUNCHER PATH_TO_CCACHE)
endif(CCACHE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

find_package(SDL2 CONFIG REQUIRED)
find_package(libtcod CONFIG REQUIRED)

file(
    GLOB_RECURSE SOURCE_FILES
    CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.hpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif()
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
endif()
if (EMSCRIPTEN)
    target_link_options(${PROJECT_NAME} PRIVATE "-sEXPORTED_FUNCTIONS=_main" "--preload-file=${CMAKE_CURRENT_SOURCE_DIR}/data@data")
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 libtcod::libtcod)
