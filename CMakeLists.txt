cmake_minimum_required(VERSION 4.0)

project(raylibTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY  https://github.com/fmtlib/fmt.git
    GIT_TAG         12.0.0
    GIT_SHALLOW     TRUE
)
FetchContent_MakeAvailable(fmt)

# https://github.com/tupini07/raylib-cpp-cmake-template/blob/11af0880cf10ecc31fc0d5d63e79650d205024a2/CMakeLists.txt
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
FetchContent_Declare(
    raylib
    GIT_REPOSITORY  https://github.com/raysan5/raylib.git
    GIT_TAG         5.5
    GIT_SHALLOW     TRUE
)
FetchContent_MakeAvailable(raylib)

set(BUILD_RAYGUI_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    raygui
    GIT_REPOSITORY  https://github.com/raysan5/raygui.git
    GIT_TAG         4.0
    GIT_SHALLOW     TRUE
    GIT_PROGRESS    TRUE
)
FetchContent_GetProperties(raygui)
if(NOT raygui_POPULATED)
    FetchContent_MakeAvailable(raygui)
    add_subdirectory(${raygui_SOURCE_DIR}/projects/CMake raygui)
    target_compile_options(raygui INTERFACE "-w")
endif()

set(SOURCES
    src/gameObject.cpp
    src/actors/actor.cpp
    src/actors/dummy.cpp
    src/actors/player.cpp
    src/components/health.cpp
    src/components/timer.cpp
)

add_executable(raylibTest   # First arg is the executable name
    src/main.cpp
    ${SOURCES}
)

target_include_directories(raylibTest
    PRIVATE
        src
        src/actors
        src/components
)

target_link_libraries(raylibTest PRIVATE fmt::fmt)
target_link_libraries(raylibTest PRIVATE raylib)
target_link_libraries(raylibTest PRIVATE raygui)