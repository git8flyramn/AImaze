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
	maze* Maze = new maze(41,41);
	Start start = { 2,2 };
	Goal goal = { 41 - 3,41 - 3 };
	//ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0
	//迷路生成
	ClearDrawScreen();
	Maze->CreateMaze();
	//Maze->StartDFS();
	Maze->StartDijkstra(start);
	std::vector<std::pair<int, int>> path;
	path = Maze->buildPath(start, goal);
	while (1)
	{
		//迷路描画
		
		Maze->UpdateDFS();
		ScreenFlip();
		WaitTimer(16);
	}
	delete Maze;
	DxLib_End();           // ＤＸライブラリ使用の終了処理
	return 0;                // ソフトの終了
}