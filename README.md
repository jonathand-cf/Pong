# Pong Clone

A fast-paced SFML-based Pong clone built with modern C++.

## Features

- Player vs Player and Player vs AI modes
- Smooth paddle and ball physics
- Score tracking and win condition
- Retro-style pixel font and sound effects
- Written in C++17 using SFML 3

## Controls

- **Player 1:**  
  `A` - Move Left  
  `D` - Move Right

- **Player 2 / AI:**  
  `←` - Move Left  
  `→` - Move Right

- **General:**  
  `Esc` - Exit the game  
  `Enter` - Restart on win screen

## Build Instructions

### Windows (via CLion + VCPKG)

1. Install [VCPKG](https://github.com/microsoft/vcpkg)
2. Run:
   ```bash
   ./vcpkg install sfml:x64-mingw-static
   ```

3. Open in CLion.
4. Ensure the CMake triplet is set to:

   ```cmake
   set(VCPKG_TARGET_TRIPLET "x64-mingw-static")
   ```
5. Build in **Release** mode.
6. The `.exe` will be in `cmake-build-release/bin`.

### Linux

1. Install dependencies:

   ```bash
   sudo apt install libsfml-dev
   ```
2. Clone and build:

   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

## Assets

Place the following folders next to the executable:

```
Sound/
  ├── ui-pop-sound-316482.mp3
  └── tada-fanfare-a-6313.mp3

Text/
  └── PixelEmulator-xq08.ttf
```

## License

Open Source i guess
