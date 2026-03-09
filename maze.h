#pragma once
#include "DxLib.h"
#include <vector>
#include<stack>

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
	bool operator>(const Node& other) const {
		return cost > other.cost;
	}
};
class maze
{
public:
	maze(int w,int h);
	~maze();
	void Initialize();
	void Draw();
	void CreateMaze();
	void StartDFS();//DFSの開始
	void AnimationDFS();//経路探索のアニメーション
	void UpdateDFS();//アニメーションの更新
	void StartDijkstra(Start start);
	void AnimationDijkstra(const std::vector<std::pair<int, int>>& path);
	void UpdateDijkstra();
	std::vector<POINT> buildPath(Start start, Goal goal);
private:
	int WIDTH;
    int HEIGHT;
	int Path;
	std::stack<Node> st;
	std::vector<std::vector<int>> Maze;
	std::vector<std::vector<int>>visited;
	int DrawSize;
	int Wall;
    int Load;
	int goalx;
	int goaly;
	int ActiveDfs;
	bool dfsSearch = false;
	
};
