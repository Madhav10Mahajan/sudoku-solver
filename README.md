# Sudoku-Solver

# **Introduction**
These are a suite of C++ programs which deal with Sudoku Puzzles. The name might be misleading, yes, but these programs don't just solve Sudoku puzzles, they also achieve other objectives such as Sudoku Puzzle Validation and Sudoku Puzzle Generation (Under development).

# **Getting Started**
Simply download the sudokusolver_programme.cpp file found in the Sudoku-Solver/ directory. Run it using any standard C++ compiler. In case of any errors or compatibility issues, submit an issue in this git.

Once downloaded, compiled and run; the program will require the user to input the Sudoku puzzle into it.

The user can write all the values into a file, seperated by whitespaces. The file can have any name or extension. When the program is running, the user will be prompted to simply enter the name of the file (with extension). Below is an example of how the contents of such a file might look.

# **How It Works**
This particular algorithm employs the use of backtracking, one of the more common methods to solve Sudoku puzzles. I've written a simple algorithm to give an idea of how the program works.

- Start.
- We start with the first empty cell.
- We generate a list of possible valid values that can be filled in that cell.
- We iterate over this list and start with the first value. This value is placed in the required cell.
- We move on to the next cell. We again generate a list of possibilities. However, if no list can be generated, then this means that there is something wrong with the  value of the previous cell. We then move back to the previous cell and place the next value on the generated list in the cell now. We repeat this step until the current cell has a valid value placed inside it.
- We stop when we reach the 81st cell (the last cell in a Sudoku puzzle) and have placed a valid value.
- The puzzle has now been solved.
- Stop.

# **Sudoku Validator**
This is a program which validates solutions for 9x9 Sudoku puzzles. Written completely in C++ and built wholly from scratch, this program takes in input from the user or from a file containing the values. It then validates the puzzle and then displays whether it is a valid solution or not.

# **How It Works**
The workings of the Sudoku Validator are quite simple, to be honest. Here's a simple algorithm explaining them all.

- Start
- The values in all the cells are checked to see if they are in the range 1-9. If not, the puzzle is invalid.
- Every row is checked to see if it contains 1-9 atleast once. If not, the solution is invalid.
- Every column is checked to see if it contains 1-9 atleast once. If not, the solution is invalid.
- Every 3x3 grid is checked to see if it contains 1-9 atleast once. If not, the solution is invalid.
- If all the criteria have been satisfied, the solution is valid.
- Stop
