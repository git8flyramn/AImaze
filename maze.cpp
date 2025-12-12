#include "maze.h"
#include "stdlib.h"
#include "time.h"
#include <vector>
#include <utility>
namespace
{
	const int MapLow = 25;
	const int MapColom = 33;
	const int DrawSize = 18;
	int map[MapLow][MapColom];
	const int Wall = 1;
	const int Load = 0;
	//int crave_east;
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
			map[y][x] = Wall;
		}
	}

}

void maze::Draw()
{
	int WallColor = GetColor(0, 0, 255);
	int LoadColor = GetColor(255, 255, 255);
	int GoalColor = GetColor(255, 0, 0);
	int StartColor = GetColor(255, 0, 0);
	int x_offset = (WIN_WIDTH - MapColom * DrawSize) / 2;
	int y_offset = (WIN_HEIGHT - MapLow * DrawSize) / 2;

	for (int y = 0; y < MapLow; y++)
	{
		for (int x = 0; x < MapColom; x++)
		{
			int x1 = x_offset + x * DrawSize;
			int y1 = y_offset + y * DrawSize;
			int x2 = x1 + DrawSize;
			int y2 = y1 + DrawSize;

			if (map[y][x] == Load)
			{
				DrawBox(x1, y1, x2, y2, LoadColor, TRUE);
			}
			else 
			{
				DrawBox(x1, y1, x2, y2,WallColor, TRUE);
			}
			if (x == 0 && y == 1)
			{
				DrawBox(x1, y1, x2, y2, StartColor, TRUE);
			}
		}
	}
}

void maze::CreateMaze()
{
	Initialize();
	srand((unsigned int)time(NULL));
	//crave_east = rand() % 2;
	
	for (int y = 1; y < MapLow - 1; y += 2)
	{
		std::vector<std::pair<int, int>> run_set;
	   
		for (int x = 1; x < MapColom - 1; x += 2)
		{
			map[y][x] = Load;
			run_set.push_back({ y,x });

			//Å‰E’[‚Å‚Í‚È‚¢(•Ç‚Æ“¯‚¶‚Å‚Í‚È‚¢)
			if (x < MapColom - 2 && y < MapLow - 2)
			{
				if (rand() % 2 == 0)
				{
					map[y][x + 1] = Load;
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
					map[north_y - 1][north_x] = Load;
				}
			}
			run_set.clear();
		}
	}
	
}
