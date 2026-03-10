#include "DxLib.h"
#include "stdlib.h"
#include <ctime>
#include "maze.h"
#include "DepthSearch.h"
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
	
	//ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0
	//迷路生成
	ClearDrawScreen();
	Maze->Initialize();
	Maze->CreateMaze();
	Maze->StartDFS();
	Maze->Draw();
	
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