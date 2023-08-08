#pragma once

#include <iostream>
#include <deque>

const int BOARD_SIZE = 9;

struct Point
{
	int x, y, value;
};

class Sudoku
{
private:
	int sudokuBoard[BOARD_SIZE][BOARD_SIZE];
	std::deque<Point> pointsBoard;

public:
    Sudoku(std::deque<Point>& startingPoints);

	int getRowSize(const int& row);
	int getColSize(const int& col);
	void playPoint(const Point& point);
	bool isValidPoint(const Point& point);
	bool solveSudoku();
	bool solveSudokuRecursive(int row, int col);
	void printBoard();
};