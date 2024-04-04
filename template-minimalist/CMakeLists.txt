cmake_minimum_required(VERSION 3.20.0)

option(GLOBAL_VCPKG "Use global Vcpkg " OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (GLOBAL_VCPKG)
    set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
else()
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)
endif()

project(my-cxx-project)

find_package(fmt CONFIG REQUIRED)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE fmt::fmt)