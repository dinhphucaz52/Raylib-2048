#pragma once
#include <raylib.h>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <math.h>
#include <map>


int myGetRandomValue(int _min, int _max);

#define MyIntArray std::vector<std::vector<int>>
#define Position std::pair<int, int>
#define row first
#define col second

const int NUM_ROWS = 4;
const int NUM_COLUMNS = 4;
const int CELL_SIZE = 150;
const int SCREEN_WITH = 1000;
const int SCREEN_HEIGHT = 700;
const int BORDER_WIDTH = 10;

const Color CELL_BACKGROUND = { 205, 193, 180, 255 };
const Color GAME_BACKGROUND = { 187, 173, 160, 255 };

const Color CELL_BACKGROUND_2 = { 238, 228, 218, 255 };
const Color CELL_BACKGROUND_4 = { 237, 224, 200, 255 };
const Color CELL_BACKGROUND_8 = { 242, 177, 121, 255 };
const Color CELL_BACKGROUND_16 = { 245, 149, 99, 255 };
const Color CELL_BACKGROUND_32 = { 233, 112, 119, 255 };
const Color CELL_BACKGROUND_64 = { 246, 94, 59, 255 };
const Color CELL_BACKGROUND_128 = { 237, 207, 114, 255 };
const Color CELL_BACKGROUND_256 = { 237, 204, 97, 255 };
const Color CELL_BACKGROUND_512 = { 237, 200, 80, 255 };
const Color CELL_BACKGROUND_1024 = { 237, 197, 63, 255 };
const Color CELL_BACKGROUND_2048 = { 255, 255,255, 255 };


std::vector<Color> getAllCellBackground();

Color getCellBackgroundByValue(int value);

const int dRow[] = {-1, 0, 1, 0 };
const int dCol[] = { 0, -1, 0, 1 };

const std::map<int, int> _log2 = {
	{0, 1},
	{2, 1},
	{4, 2},
	{8, 3},
	{16, 4},
	{32, 5},
	{64, 6},
	{128, 7},
	{256, 8},
	{512, 9},
	{1024, 10},
	{2048, 11}
};