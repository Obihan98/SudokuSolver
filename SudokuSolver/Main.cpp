#include <iostream>
#include <deque>

#include "Sudoku.h"

int main()
{
    std::deque<Point> startingPoints = {
        {0, 0, 1}, {0, 1, 4}, {0, 4, 7}, {0, 5, 8}, {0, 8, 2},
        {1, 3, 5}, {1, 4, 6}, {1, 6, 3},
        {2, 0, 6}, {2, 2, 3}, {2, 6, 1},
        {3, 0, 8}, {3, 1, 2}, {3, 4, 9}, {3, 7, 5},
        {4, 5, 5},
        {5, 2, 7}, {5, 4, 3}, {5, 7, 9},
        {6, 3, 9}, {6, 5, 4}, {6, 6, 5},
        {7, 3, 6}, {7, 4, 1}, {7, 7, 2},
        {8, 0, 3}, {8, 2, 1}, {8, 3, 2}, {8, 5, 7}, {8, 7, 4}
    };

    Sudoku sudoku(startingPoints);
    sudoku.printBoard();

    if (sudoku.solveSudoku())
    {
        std::cout << "Sudoku solved:" << std::endl;
        sudoku.printBoard();
    }
    else
    {
        std::cout << "No solution exists for the given Sudoku puzzle." << std::endl;
    }

	std::cin.get();
}