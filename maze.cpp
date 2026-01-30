#include "maze.h"
#include "stdlib.h"
#include <ctime>
#include <vector>
namespace
{
	const int MAZE_SIZE = 15;
	const int DrawSize = 32;
	int map[MAZE_SIZE][MAZE_SIZE];
	const int Wall = 1;
	const int Load = 0;
}

maze::maze()
{
}

maze::~maze()
{
}

void maze::Initialize()
{
	
	CreateMaze();

	
}

void maze::Draw()
{
	int WallColor = GetColor(0,255,0);
	int LoadColor = GetColor(255, 255, 255);

	for (int y = 0; y < MAZE_SIZE; y++)
	{
		for (int x = 0; x < MAZE_SIZE; x++)
		{
			
			if (map[y][x] == Wall)
			{
				DrawBox(x * DrawSize, y * DrawSize, DrawSize + (x + 1), DrawSize + (y + 1), WallColor,TRUE);
			}
		}
	}
}

void maze::CreateMaze()
{
	srand((unsigned int)time(NULL));
	for (int x = 0; x < MAZE_SIZE; x++)
	{
		for (int y = 0; y < MAZE_SIZE; y++)
		{
			if (y == 0 || y == MAZE_SIZE - 1 || x == 0 || x == MAZE_SIZE - 1)
			{
				map[y][x] = Wall;
			}
			else
			{
				map[y][x] = Load;
			}
		}
	}

	
	for (int y = 2; y < MAZE_SIZE - 2; y += 2)
	{
		for (int x = 2; x < MAZE_SIZE - 2; x += 2)
		{
			map[y][x] = Wall;

			while (true)
			{
				int direction;
				if (y == 2)
				{
					direction = rand() % 4;
				}
				else
				{
					direction = rand() % 3;
				}
				int dx = 0, dy = 0;
				switch (direction)
				{
				case 0:
					dx = 1;
					break;
				case 1:
					dy = 1;
					break;
				case 2:
					dx = -1;
					break;
				case 3:
					dy = -1;
					break;
				}

				if (map[y + dy][x + dx] == Load)
				{
					map[y + dy][x + dx] = Wall;
					break;
				}
			}
		}
	}
}
