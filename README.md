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
├── parsing/
├── rendering/
├── hooks/
├── utils/
├── mlx/
├── maps/
├── textures/
├── includes/
├── libft/
└── main.c
```

---

# Technical Overview

The project is divided into several modules:

- **Parsing** – Reads and validates the `.cub` configuration file.
- **Rendering** – Implements the raycasting algorithm and draws the scene.
- **Textures** – Loads XPM textures and maps them onto walls.
- **Hooks** – Handles keyboard events and player movement.
- **Utils** – Auxiliary functions used throughout the project.

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