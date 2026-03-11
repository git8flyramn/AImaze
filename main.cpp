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
	maze* MAZE = new maze(41,41);
	Start start = { 2,2 };
	Goal goal = { 39,39};
	//ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0
	//迷路生成
	ClearDrawScreen();
	MAZE->Initialize();
	MAZE->CreateMaze();
	//MAZE->Draw();
	//Maze->StartDFS();
	MAZE->StartDijkstra(start,goal);
	std::vector<std::pair<int, int>> path = MAZE->buildPath(start.x, start.y, goal.x, goal.y);
	MAZE->AnimationDijkstra(path);
	while (1)
	{
		//迷路描画
		//MAZE->Draw();
		//Maze->UpdateDFS();
		
		ScreenFlip();
		WaitTimer(16);
	}
	delete MAZE;
	DxLib_End();           // ＤＸライブラリ使用の終了処理
	return 0;                // ソフトの終了
}