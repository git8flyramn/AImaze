#include "maze.h"
#include "stdlib.h"
#include <ctime>
#include <vector>
maze::maze(int w, int h)
{
    DrawSize = 12;
	Wall = 1;
    Load = 0;
	WIDTH = w;
	HEIGHT = h;
	Maze.assign(HEIGHT, std::vector<int>(WIDTH, HEIGHT));
}

maze::~maze()
{
}

void maze::Initialize()
{
	for (int y = 0; y < WIDTH; ++y)
	{
		for (int x = 0; x < HEIGHT; ++x)
		{
			Maze[y][x] = Load;
			if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1)
			{
				Maze[y][x] = Wall;
			}
		}
	}
}

void maze::Draw()
{
	int WallColor = GetColor(0,255,0);
	int LoadColor = GetColor(0, 0, 255);

	for (int y = 0; y < WIDTH; y++)
	{
		for (int x = 0; x < HEIGHT; x++)
		{
			int x1 = x * DrawSize;
			int y1 = y * DrawSize;
			int x2 = (x + 1) * DrawSize;
			int y2 = (y + 1) * DrawSize;


			if (Maze[y][x] == Wall)
			{
				DrawBox(x1 * DrawSize, y1 * DrawSize, DrawSize + (x2 + 1), DrawSize + (y2 + 1), WallColor,TRUE);
			}
			else if(Maze[y][x] == Load)
			{
				DrawBox(x1 * DrawSize, y1 * DrawSize, DrawSize + (x2 + 1), DrawSize + (y2 + 1), LoadColor, TRUE);
			}
		}
	}
}

void maze::CreateMaze()
{
	for (int y = 2; y < HEIGHT - 1; y += 2)
	{
		for (int x = 2; x < WIDTH - 1; x += 2)
		{
			Maze[y][x] = Wall;
		}
    }

	for (int y = 2; y < HEIGHT - 1; y += 2)
	{
		for (int x = 2; x < WIDTH - 1; x += 2)
		{
			//“|‚·•ûŒü
			bool down = true;

			while (down)
			{
				int direction;
				if (y == 2)
				{
					direction = rand() % 4;
				}
				else
				{
					direction = rand() % 3 + 1;
				}
				int nextX = x, nextY = y;
				if (direction == 0)
				{
					nextY--;
				}
				else if (direction == 1)
				{
					nextX++;
				}
				else if (direction == 2)
				{
					nextY++;
				}
				else if (direction == 3)
				{
					nextX--;
				}
				if (Maze[nextY][nextX] == Load)
				{
					Maze[y][x] = Wall;
					Maze[nextY][nextX] = Wall;
					down = false;
				}
			}
		}
	}
}
