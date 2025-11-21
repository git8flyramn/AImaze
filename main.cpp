#include "DxLib.h"
#include "stdlib.h"
#include "time.h"
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstansce, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowText("迷路");
	SetGraphMode(1000, 800, 32);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	


	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);
	srand((unsigned int)time(NULL));

	while (1)                    
	{
		ClearDrawScreen();
		////配列の中身の初期化
		//for (int y = 0; y < MapRow; y++)
		//{
		//	for (int x = 0; x < MapColom; x++)
		//	{
		//		map[y][x] = wall;
		//	}
		//	
		//}
		//for (int y = 1; y < MapRow - 1; y += 2)
		//{
		//	for (int x = 1; x < MapColom - 1; x += 2)
		//	{
		//		map[y][x] = load;
		//		if (x < MapColom - 2 && y < MapRow - 2)
		//		{
		//			if (rand() % 2 == 0)
		//			{
		//				map[y][x + 1] = load;
		//				continue;
		//			}
		//		}
		//	}


		//}
		ScreenFlip();
		WaitTimer(16);
	}
	DxLib_End();           // ＤＸライブラリ使用の終了処理
	return 0;                // ソフトの終了
}