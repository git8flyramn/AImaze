#pragma once
#include "DxLib.h"
#include <vector>


struct Goal
{
	int x;
	int y;
};
struct Start
{
	int x;
	int y;
};
class maze
{
public:
	maze(int w,int h);
	~maze();
	void Initialize();
	void Draw();
	void CreateMaze();
	bool DFS(int y, int x, int goalX, int goalY, std::vector<std::vector<int>>& visited);
	void StartDFS();
	void AnimationDFS();
private:
	int WIDTH;
    int HEIGHT;
	int Path;
	std::vector<std::vector<int>> Maze;
	std::vector<std::vector<bool>>Visited;
	int DrawSize;
	int Wall;
    int Load;
	int ActiveDfs;
	bool dfsSearch = false;
	
};
