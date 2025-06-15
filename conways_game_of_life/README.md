<p align="center">
  <img src="screenshots/gol.gif" alt="Demo animation" width="1200"/>
</p>

Conway’s Game of Life
=====================

Conway’s Game of Life is a famous computer simulation created by mathematician John Conway in 1970. 
It is not a traditional game you play. Instead, it is a zero-player game: once started, it runs on its own 
based on simple rules, and you observe how the patterns evolve.

The Game of Life simulates the life and death of cells on a grid.
----------------
The grid and cells
----------------
- The world is a grid (like a checkerboard).
- Each square on the grid is called a cell.
- Each cell can be in one of two states:
  - Alive
  - Dead

- Each cell interacts with its eight neighbors:
  (above, below, left, right, and diagonal neighbors)

-------------------
Rules of the Game
-------------------
For each new generation (step), the following rules are applied to every cell at once:

1. Any live cell with fewer than two live neighbors dies (underpopulation).
2. Any live cell with two or three live neighbors survives.
3. Any live cell with more than three live neighbors dies (overpopulation).
4. Any dead cell with exactly three live neighbors becomes alive (reproduction).


The game continues updating the grid step-by-step, creating patterns that can be surprising and complex.

------------------------
Why is it interesting?
------------------------
Conway’s Game of Life shows how simple rules can lead to complex and lifelike behavior. 
It is used to study:
- Complex systems
- Emergence (how simple rules can create unexpected patterns)

It has inspired work in computer science, physics, biology, and art.


-------------------------
How to run:
------------------------  
1️⃣ Make sure you have SDL2 installed on your system.
   this program only runs on linux os
2️⃣ Compile the program (if not already done):


```bash
make run
```

Author
------------------------
rsvn

last updated on:
        jun 15 2025
