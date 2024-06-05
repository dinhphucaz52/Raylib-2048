#pragma once
#include <raylib.h>
#include <vector>
#include "common.h"
class Grid
{
public:
	Grid();
	Grid(std::vector<std::vector<int>>* grid);
	void draw();
	void moveCenter();
private:
	std::vector<std::vector<int>>* grid;
	int x;
	int y;
	Font textFont;
};

