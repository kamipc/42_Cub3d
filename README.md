*This project has been created as part of the 42 curriculum by sade-ara, cpinho-c.*

# cub3D

## Description

**cub3D** is a graphical project from the 42 curriculum inspired by the classic game Wolfenstein 3D. The objective is to build a simple 3D game engine using the **raycasting** technique and the **MiniLibX** graphics library.

The project focuses on understanding how a 2D map can be transformed into a real-time 3D perspective by casting rays from the player's point of view. It also reinforces concepts such as graphics programming, event handling, memory management, parsing, and mathematical calculations.

### Features

- Map parsing and validation
- Texture loading from XPM files
- Floor and ceiling rendering
- Wall rendering using raycasting
- Player movement
- Camera rotation
- Collision detection
- Keyboard controls
- Window management with MiniLibX

---

# Instructions

## Requirements

- Linux
- GCC
- Make
- MiniLibX
- X11 development libraries

## Compilation

```bash
make
```

This will generate the executable:

```bash
./cub3D
```

## Execution

Run the program with a valid `.cub` configuration file.

Example:

```bash
./cub3D maps/map.cub
```

## Controls

| Key | Action |
|------|--------|
| W | Move forward |
| S | Move backward |
| A | Strafe left |
| D | Strafe right |
| ← | Rotate left |
| → | Rotate right |
| ESC | Exit the program |

---

# Project Structure

```
.
├── execution/          # Main execution loop
├── hooks/              # Keyboard and window event handling
├── player/             # Player movement and camera
├── raycast/            # Raycasting calculations
├── render/             # Scene rendering and drawing
├── free/               # Memory cleanup
├── headers/            # Header files
├── inits/              # Program and game initialization
├── libft/              # Custom C library
├── maps/               # Example .cub maps and texture
├── minilibx-linux/     # MiniLibX library
├── parsing/            # Parsing and validation of .cub files
├── utils/              # Utility functions
├── main.c              # Program entry point
├── Makefile
└── README.md
```

---

# Technical Overview

The project is organized into independent modules to improve readability and maintenance.

- **execution/** – Controls the main game loop.
- **hooks/** – Handles keyboard input and window events.
- **player/** – Updates player movement, rotation and collision checks.
- **raycast/** – Performs the raycasting algorithm to determine visible walls.
- **render/** – Draws walls, floor, ceiling and textures using MiniLibX.
- **parsing/** – Reads, validates and stores the `.cub` configuration file.
- **inits/** – Initializes the game structures, textures and graphics.
- **free/** – Releases allocated memory and destroys resources before exiting.
- **utils/** – Shared helper functions used across the project.
- **libft/** – Custom utility library developed during the 42 curriculum.

---

# Resources

The following references were used throughout the development of the project:

- Lode Vandevenne — Raycasting Tutorial  
  https://lodev.org/cgtutor/raycasting.html

- cub3D Documentation (ibon-ira)  
  https://ibon-ira-cub3d.mintlify.app/

- MiniLibX Documentation (42 Docs)  
  https://harm-smits.github.io/42docs/libs/minilibx/images.html

---

# AI Usage

Artificial Intelligence was used as a supporting tool during the development process.

Its usage included:

- Debugging segmentation faults and memory issues.
- Explaining raycasting mathematics and rendering concepts.
- Reviewing parsing logic and edge cases.
- Clarifying MiniLibX behavior and graphics-related functions.
- Assisting with project documentation (README).

All architectural decisions, implementation, debugging validation, and final code were designed, reviewed, tested, and validated by the project authors.

---

# License

This project was developed for educational purposes as part of the 42 curriculum.