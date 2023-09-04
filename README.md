# Sudoku Raylib Project

This is a Sudoku game project developed using the [raylib](https://www.raylib.com/) game development library. Sudoku is a popular number puzzle game, and this project allows you to play Sudoku on your computer.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Game Screenshots](#game-screenshots)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [How to Play](#how-to-play)
- [Controls](#controls)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction

This Sudoku Raylib Project is a fun and interactive way to play the classic Sudoku game. It offers a user-friendly interface and various features to make your Sudoku gaming experience enjoyable.

## Features

- Interactive Sudoku grid with mouse and keyboard controls.
- Randomly generated Sudoku puzzles with varying difficulties.
- Ability to reset the puzzle.
- Highlighting of selected cell and invalid input.
- Check for winning conditions.
- MIT License for open-source contributions.

## Game Screenshots

### Before Starting

<div align="center">
  <img src="https://github.com/Skofficial2007/Sudoku_Raylib_Project/assets/94291950/e6bdd775-8867-438b-9dfc-6c60a60128c7" width="52%" alt="Sudoku Game Before Starting">
</div>

### After Some Progress

<div align="center">
  <img src="https://github.com/Skofficial2007/Sudoku_Raylib_Project/assets/94291950/573daeba-3329-4c35-a51e-b599154c510e" width="45%" alt="Sudoku Game After Some Progress">
</div>

## Getting Started

Follow these instructions to get a copy of the project up and running on your local machine.

### Prerequisites

You need the following software installed on your computer:

- [CMake](https://cmake.org/) (version 3.0 or higher)
- A C/C++ compiler (e.g., [GCC](https://gcc.gnu.org/) or [Visual Studio](https://visualstudio.microsoft.com/))
- [raylib](https://www.raylib.com/): This project uses raylib for graphics and input handling.

### Installation

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/Skofficial2007/Sudoku_Raylib_Project.git
   ```

2. Build the project using CMake:

   ```bash
   cd Sudoku_Raylib_Project
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

3. Run the Sudoku game:

   ```bash
   ./Sudoku_Raylib_Project
   ```

## How to Play

- Use the arrow keys to navigate the Sudoku grid.
- Click on a cell to select it, and then use the number keys (1-9) or the numeric keypad keys (1-9) to input numbers.
- Press the Backspace key or Delete key to clear a cell.
- The game checks for incorrect numbers and highlights them in red.
- You can reset the puzzle to its initial state by clicking the "Reset" button.

## Controls

- Arrow keys: Move the selected cell.
- Number keys (1-9): Input numbers into the selected cell.
- Numeric keypad keys (1-9): Input numbers into the selected cell.
- Backspace key or Delete key: Clear the selected cell.
- Mouse click: Select a cell.
- Left-click on the "Reset" button: Reset the puzzle.

## Contributing

Contributions to this project are welcome! If you have any improvements, bug fixes, or new features to propose, please create a pull request. For major changes, please open an issue first to discuss the changes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

If you have any questions or suggestions regarding this project, you can contact the author:

- Email: [skbtech2021@gmail.com](mailto:skbtech2021@gmail.com)

Happy Sudoku solving!
