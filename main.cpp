#include "DxLib.h"
#include "stdlib.h"
#include <ctime>
#include "maze.h"
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstansce, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowText("迷路");
	SetGraphMode(600, 480, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);
	maze* Maze = new maze(43,43);
	
	
	//迷路生成
	
	Maze->Initialize();
	while (1)                    
	{
		ClearDrawScreen();
		//迷路描画
	
		Maze->CreateMaze();
		Maze->Draw();
		ScreenFlip();
		WaitTimer(16);
	}
	DxLib_End();           // ＤＸライブラリ使用の終了処理
	return 0;                // ソフトの終了
}