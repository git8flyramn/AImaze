#pragma once
#include "DxLib.h"
#include <vector>


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
private:
	int WIDTH;
    int HEIGHT;
	std::vector<std::vector<int>> Maze;
	int MAZE_SIZE;
	int DrawSize;
	int Wall;
    int Load;
};
