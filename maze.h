#pragma once
#include "DxLib.h"
#include <vector>
#include<stack>
#include <iostream>
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
struct Node
{
	int x, y;
	int cost;
	
};

struct Compare
{
	bool operator()(const Node& a, const Node& b) const {
		return  a.cost > b.cost;
	}
};

class maze
{
public:
	maze(int w, int h);
	~maze();
	void Initialize();
	void Draw();
	void CreateMaze();
	void StartDFS();//DFSの開始
	void UpdateDFS();//DFSアニメーションの更新
	void StartDijkstra(Start start, Goal goal);
	void AnimationDijkstra(const std::vector<std::pair<int, int>>& path);
	std::vector<std::pair<int, int>> buildPath(int sx, int sy, int gx, int gy);
private:
	int WIDTH;
	int HEIGHT;
	int Path;
	std::stack<Node> st;
	std::vector<std::vector<int>> Maze;
	std::vector<std::vector<int>>visited;
	std::vector<std::vector<std::pair<int, int>>> prevPos;
	int DrawSize;
	int Wall;
	int Load;
	int goalx;
	int goaly;
	int ActiveDfs;
	bool dfsSearch = false;

};