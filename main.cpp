#include "DxLib.h"
#include "stdlib.h"
#include <ctime>
#include "maze.h"
#include<iostream>
#include <vector>
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstansce, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("迷路");
	SetGraphMode(600, 600, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);
	srand((unsigned int)time(NULL));
	maze* MAZE = new maze(41, 41);
	
	Start start = { 2,2 };
	Goal goal = { 39,39 };
	//迷路生成
	ClearDrawScreen();
	MAZE->Initialize();
    MAZE->CreateMaze();
	
	//DFSの処理
	//MAZE->StartDFS();
		//A*の処理
	std::vector<POINT> path = MAZE->AStar(MAZE->Maze, start.x, start.y, goal.x, goal.y);
	
	

	   //ダイクストラ法の処理
		/*
		MAZE->StartDijkstra(start, goal);
		std::vector<std::pair<int, int>> path = MAZE->buildPath(start.x, start.y, goal.x, goal.y);
		MAZE->UpdateDijkstra(path);
		MAZE->Draw();*/
	
	

	while (1)
	{
	   //A*の処理
		MAZE->Draw();
		for (auto& p : path) {
			DrawBox(p.x * 12, p.y * 12, p.x * 12 + 12, p.y * 12 + 12, GetColor(255, 0, 0), TRUE);
		}
		//迷路描画
		
		/*MAZE->UpdateDFS();
		MAZE->Draw();*/
	
		ScreenFlip();
		WaitTimer(16);
	}
	delete MAZE;
	DxLib_End();           // ＤＸライブラリ使用の終了処理
	return 0;                // ソフトの終了
}