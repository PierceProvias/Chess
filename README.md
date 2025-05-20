# Chess Game with SDL2

This is a simple chess game built using SDL2 and CMake for compilation. It allows two players to play chess on a graphical interface with basic features like piece movement, board setup, and game logic.

![Chess gif](https://github.com/user-attachments/assets/dbc2fccb-f822-4ecd-a1d7-1797d89b7d57)

## Requirements

- CMake (v3.10 or higher)
- SDL2 (v2.30.0 or higher)
- A C++ compiler (e.g., GCC, Clang)

### Installing Dependencies

1. **SDL2**:
    - On Ubuntu:
      ```bash
      sudo apt-get install libsdl2-dev
      ```
    - On macOS (using Homebrew):
      ```bash
      brew install sdl2
      ```
    - On Windows, you can download SDL2 from the [SDL2 website](https://libsdl.org/download-2.26.php) and follow the installation instructions.

2. **CMake**:
    - On Ubuntu:
      ```bash
      sudo apt-get install cmake
      ```
    - On macOS:
      ```bash
      brew install cmake
      ```
    - On Windows, you can download and install CMake from the [official website](https://cmake.org/download/).

## Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/PierceProvias/Chess.git
   cd chess

2. Make build folder
    ```bash
    mkdir build && cd build

3. Build project
    ```bash
    cmake -S .. -B .
    make

4. Play chess
    ```bash
    ./chess


