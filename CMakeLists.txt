cmake_minimum_required(VERSION 3.10)
project(chess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(WIN32)
    message(STATUS "Operating system: Windows")
elseif(APPLE)
    message(STATUS "Operating system: MacOS")
elseif(UNIX)
    message(STATUS "Operating system: Linux")
else()
    message(FATAL_ERROR "Unknown operating system")
endif()

# Set SDL2 and SDL2_image directories
set(SDL2_DIR /opt/homebrew/Cellar/sdl2/2.30.0)
set(SDL2_IMAGE_DIR /opt/homebrew/Cellar/sdl2_image/2.8.2_1)
set(SDL2_TTF_DIR /opt/homebrew/Cellar/sdl2_ttf/2.22.0)

# Debugging messages
message(STATUS "SDL2_DIR: ${SDL2_DIR}")
message(STATUS "SDL2_IMAGE_DIR: ${SDL2_IMAGE_DIR}")
message(STATUS "SDL2_TTF_DIR: ${SDL2_TTF_DIR}")

# Manually specify the include directories and libraries
include_directories(include)
include_directories(${SDL2_DIR}/include/SDL2)
include_directories(${SDL2_IMAGE_DIR}/include)
include_directories(${SDL2_TTF_DIR}/include)

file(GLOB SOURCES "src/*.cpp")

# Find SDL2 and SDL2_image libraries
find_library(SDL2_LIBRARY NAMES SDL2 libSDL2 PATHS ${SDL2_DIR}/lib)
find_library(SDL2_IMAGE_LIBRARY NAMES SDL2_image libSDL2_image PATHS ${SDL2_IMAGE_DIR}/lib)
find_library(SDL2_TTF_LIBRARY NAMES SDL2_ttf libSDL2_ttf PATHS ${SDL2_TTF_DIR}/lib)

if(NOT SDL2_LIBRARY)
    message(FATAL_ERROR "SDL2 not found!")
endif()

if(NOT SDL2_IMAGE_LIBRARY)
    message(FATAL_ERROR "SDL2_image not found!")
endif()

if(NOT SDL2_TTF_LIBRARY)
    message(FATAL_ERROR "SDL2_ttf not found!")
endif()

# Include FetchContent module
include(FetchContent)

# Fetch SDL2 if not found
find_package(SDL2 QUIET)

if(NOT SDL2_FOUND)
    message(STATUS "SDL2 not found, fetching it using FetchContent")
    FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.28.1  # Use the appropriate tag or branch
    )
    FetchContent_MakeAvailable(SDL2)
else()
    message(STATUS "SDL2 found")
endif()

# Add the executable and link libraries
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})