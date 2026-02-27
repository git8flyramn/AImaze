#include "DepthSearch.h"

DepthSearch::DepthSearch(int x, int y)
{
	H = x;
	W = y;
	bool visited[H][W];
}

DepthSearch::~DepthSearch()
{
}

void DepthSearch::Update()
{
}

bool DepthSearch::dfs(int x, int y, int goalX, int goalY)
{
	if (x < 0 || x >= W || y < 0 || y >= W)
	{
		return false;
	}
	
	
}

