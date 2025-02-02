cmake_minimum_required(VERSION 3.10)
project(chess
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD          11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS       OFF)

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



find_library(SDL2_LIBRARY NAMES SDL2 libSDL2 PATHS ${SDL2_DIR}/lib)
find_library(SDL2_IMAGE_LIBRARY NAMES SDL2_image libSDL2_image PATHS ${SDL2_IMAGE_DIR}/lib)
find_library(SDL2_TTF_LIBRARY NAMES SDL2_ttf libSDL2_ttf PATHS ${SDL2_TTF_DIR}/lib)

# Include FetchContent module
include(FetchContent)
set(SDL2_LIB_NAME SDL2)
set(SDL2_IMAGE_LIB_NAME SDL2_IMAGE)
set(SDL2_TTF_LIB_NAME SDL2_TTF)

if(NOT SDL2_LIB_NAME)
    message(STATUS "SDL2 not found, fetching it ...")
    FetchContent_Declare(
        ${SDL2_LIB_NAME}
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.30.0
        GIT_SHALLOW FALSE
    )
    FetchContent_MakeAvailable(${SDL_LIB_NAME})
else()
    message(STATUS "SDL2 found")
endif()


if(NOT SDL2_IMAGE_LIB_NAME)
    message(STATUS "SDL2_IMAGE not found, fetching it ...")
    FetchContent_Declare(
        ${SDL2_IMAGE_LIB_NAME}
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image
        GIT_TAG release-2.8.2
        GIT_SHALLOW FALSE
    )
    FetchContent_MakeAvailable(${SDL_IMAGE_LIB_NAME})
else()
    message(STATUS "SDL2_IMAGE found")
endif()


if(NOT SDL2_TTF_LIB_NAME)
    message(STATUS "SDL2_TTF not found, fetching it ...")
    FetchContent_Declare(
        ${SDL2_TTF_LIB_NAME}
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf
        GIT_TAG release-2.22.0
        GIT_SHALLOW FALSE
    )
    FetchContent_MakeAvailable(${SDL2_TTF_LIB_NAME})
else()
    message(STATUS "SDL2_TTF found")
endif()


# Add the executable and link libraries
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})