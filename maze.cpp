#include "maze.h"
#include "stdlib.h"
#include <ctime>
#include <vector>
#include<stack>
maze::maze(int w, int h)
{
	DrawSize = 12;
	Wall = 1;
	Load = 0;
	Path = 2;
	ActiveDfs = 2;
	WIDTH = (w % 2 == 0) ? w + 1 : w;
	HEIGHT = (h % 2 == 0) ? h + 1 : h;
	Maze.assign(HEIGHT, std::vector<int>(WIDTH, Load));
	
}


maze::~maze()
{
}

void maze::Initialize()
{
	
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1)
			{
				Maze[y][x] = Wall;
			}
			else if (y % 2 == 0 && x % 2 == 0)
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
	Start start = { 2,2 };
	Goal goal = { HEIGHT - 3 ,WIDTH - 3 };
	int WallColor = GetColor(0,255,0);
    int LoadColor = GetColor(255, 255, 255);
	
	int PathColor = GetColor(0, 0, 0);
	
	int StartColor = GetColor(0, 255, 255);
	int GoalColor = GetColor(255, 0, 0);
	
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			int x1 = x * DrawSize;
			int y1 = y * DrawSize;
			int x2 = x1 + DrawSize;
			int y2 = y1 + DrawSize;


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
			if (x == goal.x && y == goal.y)
			{
				DrawBox(x1, y1, x2, y2, GoalColor, TRUE);
			}
			if (Maze[y][x] == Path)
			{
				DrawBox(x1, y1, x2, y2, PathColor, TRUE);
			}
		}
	}
}

void maze::CreateMaze()
{
	
	Initialize(); 
	for (int y = 2; y < HEIGHT - 1; y += 2) {
		for (int x = 2; x < WIDTH - 1; x += 2) {
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
			case 0: targetY--;
				break;
			case 1: targetX++;
				break;
			case 2: targetY++;
				break;
			case 3:
				targetX--;
				break;
			} // •Ç‚ð‰ó‚·iLoad ‚É‚·‚éj
			Maze[targetY][targetX] = Wall;
		}
	}
}

bool maze::DFS(int y, int x, int goalX, int goalY, std::vector<std::vector<int>>& visited)
{
	if (y == goalY && x == goalX)
	{
		return true;
	}
	//Visited[y][x] = 1;
	Visited[y][x] = Wall;

	const int dx[4] = {1,-1, 0,  0};
	const int dy[4] = {0, 0, 1, -1};

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (Maze[ny][nx] == Load && !Visited[ny][nx])
		{
			if (DFS(ny, nx, goalX, goalY,visited))
			{
				Maze[ny][nx] = Path;
				return true;
			}
	   }
		
	}
	return false;

}

void maze::StartDFS()
{
	visited.assign(HEIGHT, std::vector<int>(WIDTH, 0));
	gx = WIDTH - 3;
	gy = HEIGHT - 3;

	while (!st.empty())
	{
		st.pop();
	}
	st.push({2,2});
	visited[2][2] = 1;
	dfsSearch = true;
	

    
}

void maze::AnimationDFS()
{
	/*std::vector<std::vector<int>> visited(HEIGHT, std::vector<int>(WIDTH, 0));
	int startX = 2;
	int startY = 2;
	int gx = WIDTH - 3;
	int gy = HEIGHT - 3;

	struct Node
	{
		int x,y;
	};
	std::stack<Node> st;
	st.push({ startX,startY });
	visited[startX][startY] = Wall;

	const int dx[4] = { 1,-1, 0,  0 };
	const int dy[4] = { 0, 0, 1, -1 };
	while (!st.empty())
	{
		Node cur = st.top();

		if (cur.x = gx & cur.y == gy)
		{
			break;
		}

		bool moved = false;

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx <= 0 || nx >= WIDTH - 1 || ny <= 0 || nx >= HEIGHT - 1)
			{
				continue;
			}

			if (Maze[ny][nx] == Load && !visited[ny][nx])
			{
				visited[ny][nx] = Wall;
				st.push({ startX,startY });

				Maze[ny][nx] = ActiveDfs;
				Draw();
				ScreenFlip();
				WaitTimer(10);
				moved = true;
				break;
			}
		}

		if (!moved)
		{
			st.pop();
		}
		while (!st.empty())
		{
			Node cur = st.top();
			st.pop();
			Maze[cur.y][cur.x] = Path;
		}
	}*/


}

void maze::UpdateDFS()
{
	if (!dfsSearch || st.empty())
	{
		return;
	}

	Node currnt = st.top();
	if (currnt.x == gx && currnt.y == gy)
	{
		dfsSearch = false;
		return;
	}

	const int dx[4] = { 1,-1,0,0 };
	const int dy[4] = { 0,0,1,-1 };

	bool moved = false;

	for (int i = 0; i < 4; i++)
	{
		int nx = currnt.x + dx[i];
		int ny = currnt.y + dy[i];

		if (Maze[ny][nx] == Load && !visited[ny][nx])
		{
			visited[ny][nx] = 1;
			st.push({ny, nx});
			Maze[ny][nx] = ActiveDfs;
			moved = true;
			break;
		}
	}

	if (!moved)
	{
		st.pop();
		Maze[currnt.x][currnt.y] = Path;
	}
}
