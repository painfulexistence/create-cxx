cmake_minimum_required(VERSION 3.21)

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
