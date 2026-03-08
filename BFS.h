#pragma once

#include "DxLib.h"
#include <queue>
#include <iostream>
#include "maze.h"

struct Position
{
	int x;
	int y;
};
class BFS
{
public:
	BFS();
	~BFS();
	void StartBFS(const std::vector<std::vector<int>>& maze, int startx, int starty);
	void UpdateBFS();
private:
	int WIDTH;
	int HEIGHT;
	std::queue<std::pair<int, int>> queue;
	
	
	
};
