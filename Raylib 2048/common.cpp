#include "common.h"

int myGetRandomValue(int _min, int _max)
{
	return rand() % (_max - _min + 1) + _min;
}

std::vector<Color> getAllCellBackground()
{
	return {
		CELL_BACKGROUND_2,
		CELL_BACKGROUND_4,
		CELL_BACKGROUND_8,
		CELL_BACKGROUND_16,
		CELL_BACKGROUND_32,
		CELL_BACKGROUND_64,
		CELL_BACKGROUND_128,
		CELL_BACKGROUND_256,
		CELL_BACKGROUND_512,
		CELL_BACKGROUND_1024,
		CELL_BACKGROUND_2048,
	};
}

Color getCellBackgroundByValue(int value)
{
	auto listColor = getAllCellBackground();
	value = (int)(log2(value + 1.0f));
	return listColor[value % (int)(listColor.size())];
}
