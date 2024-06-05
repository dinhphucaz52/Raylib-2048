#include "Grid.h"

Grid::Grid()
{
	grid = new std::vector<std::vector<int>>(NUM_ROWS, std::vector<int>(NUM_COLUMNS));
	x = 0;
	y = 0;
	textFont = LoadFontEx("utm_bebas.ttf", CELL_SIZE * 0.5f, nullptr, 0);
	//moveCenter();
}

Grid::Grid(std::vector<std::vector<int>>* grid) : Grid()
{
	this->grid = grid;
	for (auto row : *grid)
	{
		for (auto cell : row)
		{
			std::cout << cell << " ";
		}
		std::cout << "\n";
	}
}

void Grid::draw()
{
	for (int row = 0; row < NUM_ROWS; row++)
	{
		for (int col = 0; col < NUM_COLUMNS; col++)
		{
			DrawRectangle(x + col * CELL_SIZE + BORDER_WIDTH, y + row * CELL_SIZE + BORDER_WIDTH,
				CELL_SIZE - BORDER_WIDTH, CELL_SIZE - BORDER_WIDTH, getCellBackgroundByValue((int)(*grid)[row][col]));
			int startPadding = (int)((CELL_SIZE + 0.0f) * 0.1);
			int topPadding = (int)((CELL_SIZE + 0.0f) * 0.1);

			if ((*grid)[row][col] != 0)
			{
				DrawTextEx(textFont, std::to_string((*grid)[row][col]).c_str(),
					{
						x + col * CELL_SIZE + BORDER_WIDTH + startPadding + 0.0f,
						y + row * CELL_SIZE + BORDER_WIDTH + topPadding + 0.0f
					},
					(float)textFont.baseSize, 2, BLACK
				);
			}
		}
	}
}

void Grid::moveCenter()
{
	int gridWith = NUM_COLUMNS * CELL_SIZE + BORDER_WIDTH;
	int gridHeight = NUM_ROWS * CELL_SIZE + BORDER_WIDTH;
	x = (GetScreenWidth() - gridWith) >> 1;
	y = (GetScreenHeight() - gridHeight) >> 1;
}

