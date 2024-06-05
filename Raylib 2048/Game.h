#pragma once
#include "Grid.h"

class Game
{
public:
	Game();
	void start();
	void addCell();
	void handleInput();
	void checkContinue();
	bool gameOver;
private:
	Position getRandomCellPostion();
	void eraseOnPostion(int postion);
	void addScore(int value);
	void setOnKeyLeftPressedListener();
	void setOnKeyRightPressedListener();
	void setOnKeyUpPressedListener();
	void setOnKeyDownPressedListener();
	int getIdByRowAndCol(int row, int col);
	void drawScore();
	void reset();
	MyIntArray arr;
	Grid grid;
	int score;
	std::vector<int> emptyCells;
	Font fontScore;
};

