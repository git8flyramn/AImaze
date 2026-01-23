#include "maze.h"
#include "stdlib.h"
#include "time.h"
#include <vector>
#include <utility>
namespace
{
	const int MapLow = 15;
	const int MapColom = 15;
	const int DrawSize = 20;
	int map[MapLow][MapColom];
	const int Wall = 1;
	const int Load = 0;
	int crave_load;
	int r;
	int x, y;
	//int crave_east;
}

maze::maze()
{
	WIN_WIDTH = 640;
	WIN_HEIGHT = 320;
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
	for (int x = 0; x < MapColom; x++)
	{
		map[0][x] = Load;
		map[MapLow - 1][x] = Load;
    }

	for (int y = 0; y < MapLow; y++)
	{
		map[y][0] = Load;
		map[y][MapColom -1] = Load;
	}
}

void maze::Draw()
{
	int WallColor = GetColor(255,  0,0);
	int LoadColor = GetColor(255, 255, 255);
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

			if (map[y][x] == Wall)
			{
				DrawBox(x1 + 5, y1 + 5, x2 + 5, y2 + 5, LoadColor, TRUE);
			}
			else if(map[y][x] == Load)
			{
				DrawBox(x1 + 5, y1+ 5, x2 + 5, y2 + 5,WallColor, TRUE);
			}
			
		}
	}
}

void maze::CreateMaze()
{
	y = 2;
	srand((unsigned)time(NULL));
	for (int x = 2; x < MapColom-1; x += 2)
	{
		r = (rand() % 12) + 1;
		map[y][x] = Wall;

		if (r >= 1 && r <= 3)
		{
			if (map[y - 1][x] == Load)
			{
				map[y - 1][x] = Wall;
			}
			else if (map[y - 1][x] == Wall)
			{
				x = x - 2;
			}
		}

		if (r >= 4 && r <= 6)
		{
			if (map[y + 1][x] == Load)
			{
				map[y + 1][x] = Wall;
			}
			else if (map[y + 1][x] == Wall)
			{
				x = x - 2;
			}
		}
		if (r >= 7 && r <= 9)
		{
			if (map[y + 1][x] == Load)
			{
				map[y][x - 1] = Wall;
			}
			else if (map[y][x - 1] == Wall)
			{
				x = x - 2;
			}
		}

		if (r >= 10 && r <= 12)
		{
			if (map[y][x + 1] == Load)
			{
				map[y][x + 1] = Wall;
			}
			else if (map[y][x + 1] == Wall)
			{
				x = x - 2;
			}
		}
	}
	

	for (int y = 4; y < MapLow - 1; y += 2)
	{
		for (int x = 2; x < MapColom - 1; x += 2)
		{
			r = (rand() % 12) + 1;
			map[y][x] = Wall;

			if (r >= 1 && r <= 3)
			{
				if (map[y - 1][x] == Load)
				{
					map[y - 1][x] = Wall;
				}
				else if (map[y - 1][x] == Wall)
				{
					x = x - 2;
				}
			}

			if (r >= 4 && r <= 6)
			{
				if (map[y + 1][x] == Load)
				{
					map[y + 1][x] = Wall;
				}
				else if (map[y + 1][x] == Wall)
				{
					x = x - 2;
				}
			}
			if (r >= 7 && r <= 9)
			{
				if (map[y + 1][x] == Load)
				{
					map[y][x - 1] = Wall;
				}
				else if (map[y][x - 1] == Wall)
				{
					x = x - 2;
				}
			}

			if (r >= 10 && r <= 12)
			{
				if (map[y][x + 1] == Load)
				{
					map[y][x + 1] = Wall;
				}
				else if (map[y][x + 1] == Wall)
				{
					x = x - 2;
				}
			}
		}
	}
	map[0][1] = Load;
	map[MapColom - 1][MapLow - 2] = Load;


}
