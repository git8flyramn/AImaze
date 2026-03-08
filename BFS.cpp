#include "BFS.h"
#include <queue>
BFS::BFS()
{
	

	 
}

BFS::~BFS()
{
}

void BFS::StartBFS(const std::vector<std::vector<int>>& maze,int startx,int starty)
{
	HEIGHT = maze.size();
	WIDTH = maze[0].size();
	Position pos = {0,0};
	std::vector<std::vector<bool>> visited(HEIGHT, std::vector<bool>(WIDTH, false));
	queue.push({ startx, starty });
	visited[startx][starty] = true;
	

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	while (!queue.empty())
	{
		//ç\ë¢âªë©îõÇégÇÌÇ»Ç¢
		pos.x = queue.front().first;
		pos.y = queue.front().second;
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = pos.y + dy[i];
			int nx = pos.x + dx[i];
			if (ny < 0 || ny >= HEIGHT || nx < 0 || nx >= WIDTH)
			{
				continue;
			}
			if (maze[ny][nx] == 1)
			{
				continue;
			}

			if (visited[ny][nx])
			{
				continue;
			}

			visited[ny][nx] = true;
			queue.push({ ny,nx });
		}
	}


	
}

void BFS::UpdateBFS()
{
}
