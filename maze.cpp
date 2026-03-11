#include "maze.h"
#include "stdlib.h"
#include <vector>
#include<stack>
#include <limits>
#include<queue>
#include <utility>
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
	prevPos.assign(HEIGHT, std::vector<std::pair<int, int>>(WIDTH, { -1,-1 }));
	
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

	Start start = { 1,1 };
	Goal goal = { HEIGHT - 3 ,WIDTH - 3};
	int WallColor = GetColor(0, 255, 0);
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
				DrawBox(x1, y1, x2, y2, WallColor, TRUE);
			}
			else if (Maze[y][x] == Load)
			{
				DrawBox(x1, y1, x2, y2, LoadColor, TRUE);
			}

			if (x == start.x && y == start.y)
			{
				DrawBox(x1, y1, x2, y2, StartColor, TRUE);
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

void maze::StartDFS()
{
	visited.assign(HEIGHT, std::vector<int>(WIDTH, 0));
	while (!st.empty())
	{
		st.pop();
	}
	st.push({ 1,1 });
	visited[2][2] = 1;
	dfsSearch = true;



}
void maze::UpdateDFS()
{

	if (!dfsSearch || st.empty())
	{
		return;
	}

	Node currnt = st.top();
	if (currnt.x == goalx && currnt.y == goaly)
	{
		dfsSearch = false;
		return;
	}

	const int dx[4] = { 1,-1,0, 0 };
	const int dy[4] = { 0, 0,1,-1 };

	bool moved = false;

	for (int i = 0; i < 4; i++)
	{
		int nx = currnt.x + dx[i];
		int ny = currnt.y + dy[i];

		if (Maze[ny][nx] == Load && !visited[ny][nx])
		{
			visited[ny][nx] = 1;
			st.push({ ny, nx });
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

void maze::StartDijkstra(Start start, Goal goal)
{

	const int INF = 1e9;

	std::vector<std::vector<int>> dist(HEIGHT, std::vector<int>(WIDTH, INF));
	std::priority_queue<Node, std::vector<Node>, Compare> queue;
	dist[start.y][start.x] = 0;
	queue.push({ start.x, start.y, 0 });

	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };

	while (!queue.empty())
	{
		Node cur = queue.top(); queue.pop();
		int y = cur.y;
		int x = cur.x;

		if (cur.cost > dist[y][x]) continue;
		if (y == goal.y && x == goal.x) break;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= HEIGHT || nx < 0 || nx >= WIDTH) continue;
			if (Maze[ny][nx] == Wall) continue;

			int cost = dist[y][x] + 1;

			if (cost < dist[ny][nx])
			{
				dist[ny][nx] = cost;

				prevPos[ny][nx] = { y, x };

				queue.push({ nx, ny, cost });
			}
		}
	}



}

void maze::UpdateDijkstra(const std::vector<std::pair<int, int>>& path)
{
	//ƒXƒ^[ƒg‚©‚çƒS[ƒ‹‚Ü‚Å‚ÌÅ’ZŒo˜H
	for (auto& p : path) {
		Maze[p.first][p.second] = Path; // •‚Å•`‚©‚ê‚é
		Draw();
		ScreenFlip();
		WaitTimer(30);
	}
}

void maze::StartAstar(int sx,int sy,int gx,int gy)
{
	this->goalx = gx;
	this->goaly = gy;
	std::priority_queue<Node*, std::vector<Node*>, NodeCmp> openList;
	close.assign(HEIGHT, std::vector<bool>(WIDTH, false));
	Node* start = new Node{ sx, sy, 0, 0, 0};
	start->h = abs(gx - sx) + abs(gy - sy);
	start->f = start->g + start->h;

	openList.push(start);
	finished = false;

	
	
}

void maze::UpdateAstar()
{
	const int wid = 41;
	const int hei = 41;
	std::vector<std::pair<int, int>> path;
	std::priority_queue<Node*, std::vector<Node*>, NodeCmp> openList;
	if (finished || openList.empty()) return;
	
	bool closed[hei][wid] = { false };
	Node* current = openList.top();
	openList.pop();
	
	closed[current->y][current->x] = true;

	if (current->x == goalx && current->y == goaly)
	{
		// ƒS[ƒ‹“ž’B
		finished = true;

		// Œo˜H•œŒ³
		path.clear();
		Node* n = current;

		while (n)
		{
			path.push_back({ n->x, n->y });
			n = n->parent;
		}
		std::reverse(path.begin(), path.end());
		return;
	}

	const int dx[4] = { 1,-1,0,0 };
	const int dy[4] = { 0,0,1,-1 };

	for (int i = 0; i < 4; i++)
	{
		int nx = current->x + dx[i];
		int ny = current->y + dy[i];

		if (nx < 0 || nx >= WIDTH || ny < 0 || ny >= HEIGHT) continue;
		if (Maze[ny][nx] == 1) continue;
		if (closed[ny][nx]) continue;

		Node* next = new Node{ nx, ny };
		next->g = current->g + 1;
		next->h = abs(goalx - nx) + abs(goaly - ny);
		next->f = next->g + next->h;
		next->parent = current;

		openList.push(next);
	}
}

void maze::DrawAstarState()
{
	std::vector<POINT> path;
	bool closed[41][41] = {false};
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (closed[y][x])
			{
				DrawBox(x * DrawSize, y * DrawSize,
					x * DrawSize + DrawSize, y * DrawSize + DrawSize,
					GetColor(0, 0, 255), TRUE);
			}
		}
	}
	// pathiÔj
	for (auto& p : path)
	{
		DrawBox(p.x * DrawSize, p.y * DrawSize,
			p.x * DrawSize + DrawSize, p.y * DrawSize + DrawSize,
			GetColor(255, 0, 0), TRUE);
	}
}


std::vector<POINT> maze::AStar(const std::vector<std::vector<int>>& maze, int sx, int sy, int gx, int gy)
{
	int wid = maze.size();
    int hei = maze[0].size();
	std::priority_queue<Node*, std::vector<Node*>, NodeCmp> openList;
	std::vector<std::vector<bool>> closed(hei, std::vector<bool>(wid, false));

	Node* start = new Node{ sx,sy,0,0,0 };

	start->h = abs(gx - sx) + abs(gy - sy);
	start->f = start->g + start->h;
	openList.push(start);

	Node* goalNode = nullptr;

	while (!openList.empty())
	{
		Node* current = openList.top();
		openList.pop();

		if (current->x == gx && current->y == gy) {
			goalNode = current;
			break;
		}

		closed[current->y][current->x] = true;
		const int dx[4] = { 1,-1,0,  0 };
		const int dy[4] = { 0, 0,1, -1 };

		for (int i = 0; i < 4; i++)
		{
			int nx = current->x + dx[i];
			int ny = current->y + dy[i];

			if (nx < 0 || nx >= wid || ny < 0 || ny >= hei)
			{
				continue;
			}

			if (maze[ny][nx] == 1)
			{
				continue;
			}
			if (closed[ny][nx])
			{
				continue;
			}

			Node* next = new Node{ nx,ny };
			next->g = current->g + 1;
			next->h = abs(gx - nx) + abs(gy - ny);
			next->f = next->g + next->h;
			next->parent = current;
			openList.push(next);
		}
	}
	
	std::vector<POINT> path;
	if (goalNode)
	{
		Node* n = goalNode;
		while (n)
		{
			path.push_back({ n->x,n->y });
			n = n->parent;
		}
		std::reverse(path.begin(), path.end());
	}
	return path;
}

std::vector<std::pair<int, int>> maze::buildPath(int sx, int sy, int gx, int gy)
{
	std::vector<std::pair<int, int>> path;
	int goaly = gy;
	int goalx = gx;
	while (!(goaly == sy && goalx == sx))
	{
		path.push_back({ goaly,goalx });
		auto p = prevPos[goaly][goalx];
		goaly = p.first;
		goalx = p.second;
	}
	path.push_back({ sy,sx });
	std::reverse(path.begin(), path.end());
	return path;
}