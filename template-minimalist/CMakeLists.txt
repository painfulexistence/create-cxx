cmake_minimum_required(VERSION 3.20.0)

option(GLOBAL_VCPKG "Use global Vcpkg " OFF)
if (GLOBAL_VCPKG)
    set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
else()
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)
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

find_package(fmt CONFIG REQUIRED)

add_executable(main src/main.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 20)
target_link_libraries(main PRIVATE fmt::fmt)