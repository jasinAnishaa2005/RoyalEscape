<div align="center">

<img src="assets/readme-banner.svg" alt="Royal Escape — fantasy game prototype" width="100%" />

# Royal Escape 🏰

**A fantasy game prototype built with C++ and SFML.**

[![C++](https://img.shields.io/badge/C++-17-5b3828?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![SFML](https://img.shields.io/badge/Graphics-SFML-c9a27e?style=for-the-badge)](https://www.sfml-dev.org/)
[![CMake](https://img.shields.io/badge/Build-CMake-795548?style=for-the-badge&logo=cmake&logoColor=white)](https://cmake.org/)

*A work in progress — exploring game loops, player movement, and 2D game structure.*

</div>

---

## ✨ Project overview

Royal Escape is a C++ game project organized around a game loop and separate game/player components. The repository includes visual assets for backgrounds and a running player sprite.

## 🧰 Built with

- **C++17**
- **SFML** for graphics, window, and system modules
- **CMake** for project configuration

## 📁 Project structure

```
RoyalEscape/
├── assets/
│   ├── backgrounds/
│   ├── fonts/
│   └── player/
├── docs/
├── include/
├── src/
├── CMakeLists.txt
└── README.md
```

## 🖥️ Build

The current CMake configuration expects SFML graphics, window, and system components.

```bash
cmake -S . -B build
cmake --build build
```

Run the generated executable from the build directory appropriate to your platform.

> **Note:** The repository's current CMake file contains a local SFML path setting. If CMake cannot find SFML on your machine, update `SFML_DIR` in `CMakeLists.txt` to match your installation.

## 🎮 Current code areas

- Game window and main loop
- Game state handling
- Player component and movement interface
- Background and character assets

## 🌱 What's next

- Complete the gameplay loop and state transitions
- Implement player movement and collision handling
- Connect the visual assets to the game scene
- Document controls and gameplay once finalized

---

<div align="center">

**Made with C++ and curiosity.** 🤎

</div>
