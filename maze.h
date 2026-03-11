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
	int g, h, f;
	Node* parent;
};

struct Compare
{
	bool operator()(const Node& a, const Node& b) const {
		return  a.cost > b.cost;
	}
};

struct NodeCmp
{
	bool operator()(const Node* a, const Node* b) const {
		return a->f > b->f;
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
	void UpdateDijkstra(const std::vector<std::pair<int, int>>& path);
	void StartAstar(int sx, int sy, int gx, int gy);
	void UpdateAstar();
	void DrawAstarState();
	std::vector<POINT> AStar(const std::vector<std::vector<int>>& maze, int sx, int sy,int gx, int gy);
	std::vector<std::pair<int, int>> buildPath(int sx, int sy, int gx, int gy);
	std::vector<std::vector<int>> Maze;
	
private:
	int WIDTH;
	int HEIGHT;
	int Path;
	std::stack<Node> st;
	std::vector<std::vector<int>>visited;
	std::vector < std::vector<bool>> close;
	std::vector<std::vector<std::pair<int, int>>> prevPos;
	int Wall;
	int Load;
	int goalx;
	int goaly;
	int DrawSize;
	int ActiveDfs;
	bool dfsSearch = false;
	bool finished = false;
	
	
	

};