#pragma once
#include "DxLib.h"

class DepthSearch
{
public:
	DepthSearch(int x, int y);
	~DepthSearch();
	void Update();
	bool dfs(int x, int y, int goalX, int goalY);
private:
	int H; 
	int W;
	bool visited;
};
