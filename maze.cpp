#include "maze.h"
#include "stdlib.h"
#include <ctime>
#include <vector>
maze::maze(int w, int h)
{
    DrawSize = 12;
	Wall = 1;
    Load = 0;
	WIDTH = (w % 2 == 0) ? w + 1 : w;
	HEIGHT = (h % 2 == 0) ? h + 1 : h;
	Maze.assign(HEIGHT, std::vector<int>(WIDTH, Load));
	
}

maze::~maze()
{
}

void maze::Initialize()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			
			if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1)
			{
				Maze[y][x] = Wall;
			}
			else
			{
				Maze[y][x] = Load;
			}
		}
	}
}

void maze::Draw()
{
	Start start = {1,5};
	int WallColor = GetColor(0,255,0);
	int LoadColor = GetColor(0, 0, 255);
	int StartColor = GetColor(0, 255, 255);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			int x1 = x * DrawSize;
			int y1 = y * DrawSize;
			int x2 = x1 * DrawSize;
			int y2 = y1 * DrawSize;


			if (Maze[y][x] == Wall)
			{
				DrawBox(x1, y1, x2,y2, WallColor,TRUE);
			}
			else if(Maze[y][x] == Load)
			{
				DrawBox(x1, y1,x2,y2 , LoadColor, TRUE);
			}

			if (x == start.x && y == start.y)
			{
				DrawBox(x1,y1,x2,y2,StartColor, TRUE);
			}
		}
	}
}

void maze::CreateMaze()
{
	for (int y = 2; y < HEIGHT - 2; y += 2)
	{
		for (int x = 2; x < WIDTH - 2; x += 2)
		{
			Maze[y][x] = Wall;
		}
    }

	for (int y = 2; y < HEIGHT - 2; y += 2)
	{
		for (int x = 2; x < WIDTH - 2; x += 2)
		{
			//“|‚·•ûŒü
			

			while (true)
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
				
				int targetX = x;
				int targetY = y;
				switch (direction)
				{
				case 0: 
					targetY--; 
					break;
				case 1:
					targetX++;
					break;
				case 2:
					targetY++;
					break;
				case 3:
					targetX--;
					break;

				}
				
				if (Maze[targetY][targetX] == Load)
				{
					Maze[targetY][targetX] = Wall;
					break;
				}
			}
		}
	}
}

/*
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
*/