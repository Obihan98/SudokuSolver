#include <iostream>
#include <deque>
#include "sudoku.h"

Sudoku::Sudoku(std::deque<Point>& startingPoints)
{
    // Initialize the Sudoku board with all 0s
    pointsBoard = startingPoints;

    // Initialize the Sudoku board with all 0s
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            sudokuBoard[i][j] = 0;
        }
    }

    // Fill in the starting points on the Sudoku board
    for (const Point& point : startingPoints) sudokuBoard[point.x][point.y] = point.value;
}

void Sudoku::printBoard()
{
    std::cout << "+-------+-------+-------+" << std::endl;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        std::cout << "| ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << sudokuBoard[i][j] << " ";
            if ((j + 1) % 3 == 0 && j < BOARD_SIZE - 1) {
                std::cout << "| ";
            }
        }
        std::cout << "| ";
        std::cout << std::endl;
        if ((i + 1) % 3 == 0 && i < BOARD_SIZE - 1) {
            std::cout << "|-------+-------+-------|" << std::endl;
        }
    }
    std::cout << "+-------+-------+-------+" << std::endl;
}

void Sudoku::playPoint(const Point& point)
{
    sudokuBoard[point.x][point.y] = point.value;
}

int Sudoku::getRowSize(const int& row)
{
    int rowSize = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (sudokuBoard[row][i] != 0)
        {
            rowSize += 1;
        }
    }
    return rowSize;
}

int Sudoku::getColSize(const int& col)
{
    int colSize = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (sudokuBoard[i][col] != 0)
        {
            colSize += 1;
        }
    }
    return colSize;
}

bool Sudoku::isValidPoint(const Point& point)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (sudokuBoard[i][point.y] == point.value)
        {
            return false;
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (sudokuBoard[point.x][i] == point.value)
        {
            return false;
        }
    }

    return true;
}

bool Sudoku::solveSudoku()
{
    // Find the first empty cell to start the recursion
    int row = -1;
    int col = -1;
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (sudokuBoard[i][j] == 0)
            {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1 && col != -1)
            break;
    }

    // If there are no empty cells, the puzzle is solved
    if (row == -1 && col == -1)
        return true;

    // Start the recursion to solve the puzzle
    return solveSudokuRecursive(row, col);
}

bool Sudoku::solveSudokuRecursive(int row, int col)
{
    // If we have reached the end of the board, the puzzle is solved
    if (row == BOARD_SIZE - 1 && col == BOARD_SIZE)
        return true;

    // If we have reached the end of a row, move to the next row
    if (col == BOARD_SIZE)
    {
        row++;
        col = 0;
    }

    // Skip cells that are already filled
    if (sudokuBoard[row][col] != 0)
        return solveSudokuRecursive(row, col + 1);

    // Try placing digits 1 to 9 in the current cell
    for (int num = 1; num <= 9; ++num)
    {
        Point currentPoint = { row, col, num };
        if (isValidPoint(currentPoint))
        {
            // Place the digit and recursively move to the next cell
            sudokuBoard[row][col] = num;
            if (solveSudokuRecursive(row, col + 1))
                return true;
            // If placing the digit didn't lead to a solution, backtrack
            sudokuBoard[row][col] = 0;
        }
    }

    // If no valid digit can be placed in the current cell, backtrack
    return false;
}