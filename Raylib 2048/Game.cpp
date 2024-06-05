#include "Game.h"

Game::Game()
{
	this->arr = MyIntArray(NUM_ROWS, std::vector<int>(NUM_COLUMNS, 0));
	gameOver = false;
	grid = Grid(&this->arr);
	for (int i = 0; i < NUM_ROWS * NUM_COLUMNS; i++)
		this->emptyCells.push_back(i);
	std::cout << "emptyCells: ";
	for (auto x : emptyCells)
		std::cout << x << " ";
	std::cout << "\n";
	fontScore = LoadFontEx("utm_bebas.ttf", 200, 0, 0);
	addCell();
}

void Game::start()
{
	//arr[0][0] = 2048;
	grid.draw();
	drawScore();
}

void Game::drawScore()
{
	DrawTextEx(
		fontScore,
		"SCORE",
		{
			NUM_COLUMNS * CELL_SIZE + BORDER_WIDTH + 30,
			(SCREEN_HEIGHT - NUM_ROWS * CELL_SIZE + BORDER_WIDTH) >> 1
		},
		fontScore.baseSize,
		2.0f,
		MAROON
	);
	DrawTextEx(
		fontScore,
		std::to_string(score).c_str(),
		{
			NUM_COLUMNS * CELL_SIZE + BORDER_WIDTH + 30 + 0.0f,
			((SCREEN_HEIGHT - NUM_ROWS * CELL_SIZE + BORDER_WIDTH) >> 1) + fontScore.baseSize + 10.0f
		},
		fontScore.baseSize,
		2.0f,
		MAROON
	);
}

Position Game::getRandomCellPostion()
{
	int position = myGetRandomValue(0, (int)(this->emptyCells.size()) - 1);
	//std::cout << emptyCells.size() << " " << position << "\n";
	int tmp = this->emptyCells[position];
	eraseOnPostion(position);
	return { tmp / NUM_COLUMNS, tmp % NUM_COLUMNS };
	return { 0, 0 };
}

void Game::eraseOnPostion(int postion)
{
	for (int i = postion; i + 1 < emptyCells.size(); i++)
		emptyCells[i] = emptyCells[i + 1];
	emptyCells.pop_back();
}

void Game::addScore(int value)
{
	score += value;
}

void Game::setOnKeyLeftPressedListener()
{
	this->emptyCells.clear();
	for (int row = 0; row < NUM_ROWS; row++)
	{
		std::vector<int> tmp;
		for (auto& x : arr[row])
		{
			if (x)
			{
				if (!tmp.empty() && tmp.back() == x)
				{
					x <<= 1;
					addScore(x);
					tmp.pop_back();
				}
				tmp.push_back(x);
				x = 0;
			}
		}
		for (int col = 0; col < (int)tmp.size(); col++)
			arr[row][col] = tmp[col];
		for (int col = (int)tmp.size(); col < NUM_COLUMNS; col++)
			emptyCells.push_back(getIdByRowAndCol(row, col));
	}
	addCell();
}

void Game::setOnKeyRightPressedListener()
{
	this->emptyCells.clear();
	for (int row = 0; row < NUM_ROWS; row++)
	{
		std::vector<int> tmp;
		for (int col = NUM_COLUMNS - 1; col >= 0; col--)
		{
			if (arr[row][col])
			{
				if (!tmp.empty() && tmp.back() == arr[row][col])
				{
					arr[row][col] <<= 1;
					addScore(arr[row][col]);
					tmp.pop_back();
				}
				tmp.push_back(arr[row][col]);
				arr[row][col] = 0;
			}
		}
		for (int col = 0; col < tmp.size(); col++)
			arr[row][NUM_COLUMNS - col - 1] = tmp[col];
		for (int col = (int)tmp.size(); col < NUM_COLUMNS; col++)
			emptyCells.push_back(getIdByRowAndCol(row, NUM_COLUMNS - col - 1));
	}
	addCell();
}

void Game::setOnKeyUpPressedListener()
{
	this->emptyCells.clear();
	for (int col = 0; col < NUM_COLUMNS; col++)
	{
		std::vector<int> tmp;
		for (int row = 0 ; row < NUM_ROWS; row++)
		{
			if (arr[row][col])
			{
				if (!tmp.empty() && tmp.back() == arr[row][col])
				{
					arr[row][col] <<= 1;
					addScore(arr[row][col]);
					tmp.pop_back();
				}
				tmp.push_back(arr[row][col]);
				arr[row][col] = 0;
			}
		}
		for (int row = 0; row < tmp.size(); row++)
			arr[row][col] = tmp[row];
		for (int row = (int)tmp.size(); row < NUM_ROWS; row++)
			emptyCells.push_back(getIdByRowAndCol(row, col));
	}
	addCell();
}

void Game::setOnKeyDownPressedListener()
{
	this->emptyCells.clear();
	for (int col = 0; col < NUM_COLUMNS; col++)
	{
		std::vector<int> tmp;
		for (int row = NUM_ROWS - 1; row >= 0; row--)
		{
			if (arr[row][col])
			{
				if (!tmp.empty() && tmp.back() == arr[row][col])
				{
					arr[row][col] <<= 1;
					addScore(arr[row][col]);
					tmp.pop_back();
				}
				tmp.push_back(arr[row][col]);
				arr[row][col] = 0;
			}
		}
		for (int row = 0; row < tmp.size(); row++)
			arr[NUM_ROWS - row - 1][col] = tmp[row];
		for (int row = (int)tmp.size(); row < NUM_ROWS; row++)
			emptyCells.push_back(getIdByRowAndCol(NUM_ROWS - row - 1, col));
	}
	addCell();
}

int Game::getIdByRowAndCol(int row, int col)
{
	return row * NUM_COLUMNS + col;
}

void Game::reset()
{
	for (auto& row : arr)
	{
		for (auto& cell : row)
		{
			cell = 0;
		}
	}
	gameOver = false;
	emptyCells.clear();
	for (int i = 0; i < NUM_ROWS * NUM_COLUMNS; i++)
		this->emptyCells.push_back(i);
	std::cout << "emptyCells: ";
	for (auto x : emptyCells)
		std::cout << x << " ";
	std::cout << "\n";
	addCell();
}

void Game::addCell()
{
	if (!emptyCells.empty())
	{
		Position pos = getRandomCellPostion();
		int value = GetRandomValue(1, 10);
		this->arr[pos.first][pos.second] = 1 << (value > 9 ? 2 : 1);
	}
}

void Game::handleInput() {

	int keyPressed = GetKeyPressed();
	if (keyPressed && gameOver == true)
	{
		reset();
	}
	switch (keyPressed)
	{
	case KEY_LEFT:
		setOnKeyLeftPressedListener();
		break;
	case KEY_RIGHT:
		setOnKeyRightPressedListener();
		break;
	case KEY_DOWN:
		setOnKeyDownPressedListener();
		break;
	case KEY_UP:
		setOnKeyUpPressedListener();
		break;
	}
}

void Game::checkContinue()
{

	if (!emptyCells.empty())
		return;

	bool flag = false;

	for (int row = 1; row + 1 < NUM_ROWS && !flag; row++)
	{
		for (int col = 1; col + 1< NUM_COLUMNS && !flag; col++)
		{
			for (int i = 0; i < 4 && !flag; i++)
			{
				int newRow = row + dRow[i];
				int newCol = col + dCol[i];
				if (arr[newRow][newCol] == arr[row][col])
				{
					flag = true;
					break;
				}
			}
		}
	}
	if (!flag)
		gameOver = true;
}
