#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include <stdio.h>
#include "UI.h"
#include "whenfunction.h"


// 主函数
int main()
{
	// 绘图窗口初始化
	initgraph(1180, 800);
	Background();


	do {
		if (State == 1)
		{
			whenState_1();
		}
		else if (State == 2)
		{
			whenState_2();
		}
		else if (State == 3)
		{
			whenState_3();
		}
		else if (State == 4)
		{
			whenState_4();
		}
		else if (State == 5)
		{
			whenState_5();
		}
		else if (State == 0)
		{
			break;
		}
		//MapSearch();
	} while (1);

	// 按任意键退出
	//_getch();
	EndBatchDraw();
	closegraph();
}
