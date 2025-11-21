#include "maze.h"
#include "stdlib.h"
#include "time.h"
#include <vector>
#include <utility>
namespace
{
	const int MapLow = 21;
	const int MapColom = 11;
	const int DrawSize = 20;
	int map[MapLow][MapColom];
	const int wall = 1;
	const int load = 0;
}
maze::maze()
{
	WIN_WIDTH = 640;
	WIN_HEIGHT = 480;
}

maze::~maze()
{
}

void maze::Initialize()
{
	for (int y = 0; y < MapLow; y++)
	{
		for (int x = 0; x < MapColom; x++)
		{
			map[y][x] = wall;
		}
	}
}

void maze::Draw()
{
	int WallColor = GetColor(0, 255, 0);
	int LoadColor = GetColor(0, 0, 255);

	int x_offset = (WIN_WIDTH - MapColom * DrawSize) / 2;
	int y_offset = (WIN_HEIGHT - MapLow * DrawSize) / 2;
}

void maze::CreateMaze()
{
	srand((unsigned int)time(NULL));
	for (int y = 1; y < MapLow - 1; y += 2)
	{
		std::vector<std::pair<int, int>> run_set;
		for (int x = 1; x < MapColom - 1; x += 2)
		{
			map[y][x] = load;
			run_set.push_back({ y,x });
			if (x < MapColom - 2 && y < MapLow - 2)
			{
				if (rand() % 2 == 0)
				{
					map[y][x + 1] = load;
					continue;
				}
			}
			int run_size = run_set.size();
			if (run_size > 0)
			{
				int index = rand() % run_size;
				int north_y = run_set[index].first;
				int north_x = run_set[index].second;
				if (north_y > 1)
				{
					map[north_y - 1][north_x] = load;
				}
			}
			run_set.clear();
		  
		}
	}
}
