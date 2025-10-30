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
		//1:壁 0：通路 
		const int MapX = 15;
		const int MapY = 15;
		const int WIN_WIDTH = 1000;
		const int WIN_HIEGHT = 800;
		int MHandle = LoadGraph("block.png");
		const int IMAGE_SIZE = 32;
		int rnd = 0;
		int map[MapX][MapY] ={  {1,1,1,1,1,1,1,1,1,1,1},
			/*入口(上)*/   /*Y*/{1,0,0,0,0,0,0,0,0,0,1},
								{1,0,0,0,0,0,0,0,0,0,1},
								{1,0,0,0,0,0,0,0,0,0,1},
								{1,0,0,0,0,0,0,0,0,0,1},//下
								{1,0,0,0,0,0,0,0,0,0,1},
								{1,0,0,0,0,0,0,0,0,0,1},
								{1,0,0,0,0,0,0,0,0,0,1},
								{1,0,0,0,0,0,0,0,0,0,1},
								{1,0,0,0,0,0,0,0,0,0,1},
								{1,0,0,0,0,0,0,0,0,0,1},
								{1,1,1,1,1,1,1,1,1,1,1},};
		srand((unsigned)time(NULL));
		
			// 1 3  1  4  6   0 7 9 1  10 12 0
			              
		while (1)                        /* 出口*/
		{
			ClearDrawScreen();


			rnd = rand() % 12 + 1;



			for (int i = 0; i < MapY; i++)
			{
				for (int j = 0; j < MapX; j++)
				{
					if (map[i][j] == 1)
					{
						DrawGraph(0  + IMAGE_SIZE * i,0+ IMAGE_SIZE * j,MHandle,TRUE);
				    }
				    
					if (map[i][j] == 0)
					{
						if (rnd % 2 == 1)
						{
							map[i][j] = 1;
						}
					}
				}
			}
			
				//for (int j = 0; j < WIN_HIEGHT; j++)
				//{
				//	DrawGraph(0 + (j * IMAGE_SIZE), 0, MHandle, TRUE);
				//	DrawGraph(0 + (j * IMAGE_SIZE), WIN_HIEGHT - IMAGE_SIZE, MHandle, TRUE);
				//}
				//for (int i = 0; i < WIN_WIDTH; i++)
				//{
				//	DrawGraph(0, IMAGE_SIZE * i, MHandle, TRUE); //左
				//	DrawGraph(WIN_WIDTH - 32,WIN_HIEGHT - 32 * i,MHandle,TRUE);//右
				//}
				
			ScreenFlip();
			WaitTimer(16);
		}
		DxLib_End();           // ＤＸライブラリ使用の終了処理
		return 0;                // ソフトの終了
}
