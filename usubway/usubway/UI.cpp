#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include "UI.h"

#define DITUCHAXUN_X 1225-280
#define DITUCHAXUN_Y 340
#define TUICHUXITONG_X 1225-280
#define TUICHUXITONG_Y 490
#define SHUOMING_Y 90
#define CBUTTON_X 150
#define CBUTTON_Y 300

IMAGE background;
IMAGE a_button_1, a_button_1_z,a_button_2,a_button_2_z, a_button_3, a_button_3_z, a_button_4, a_button_4_z;
IMAGE b_button_a,b_button_b;
IMAGE word, word_z, word_2, word_2_z,Word,Word_z;
IMAGE line1, line2, line3, line4, line5, line7, line9, line11, line_all,c_button,c_button_2; 
IMAGE input, input_z, qi, qi_z, zhong, zhong_z;

int Background()
{
	loadimage(&background, _T("..\\pictures\\face\\background\\5b7f6931ecc1c.jpg"),1600,800);
	loadimage(&a_button_1, _T("..\\pictures\\face\\button\\a_button_01.png"), 360,269);
	loadimage(&a_button_1_z, _T("..\\pictures\\face\\button\\a_button_1_b.png"), 360,269);
	//
	loadimage(&a_button_2, _T("..\\pictures\\face\\button\\000002.png"), 246, 224);
	loadimage(&a_button_2_z, _T("..\\pictures\\face\\button\\000002_b.png"), 246, 224);
	//
	loadimage(&a_button_3, _T("..\\pictures\\face\\button\\000003.png"), 402, 405);
	loadimage(&a_button_3_z, _T("..\\pictures\\face\\button\\000003_b.png"), 402, 405);
	//
	loadimage(&a_button_4, _T("..\\pictures\\face\\button\\000004.png"), 318, 318);
	loadimage(&a_button_4_z, _T("..\\pictures\\face\\button\\000004_b.png"), 318, 318);
	putimage(0, 0, &background);
	putimage(730.9, 348, 180,134.5,&a_button_1_z,0,0, SRCAND);
	putimage(730.9, 348,180,134.5, &a_button_1,0,0,SRCPAINT);
	//
	loadimage(&b_button_a, _T("..\\pictures\\face\\button\\b_button _a.png"), 195, 116);
	loadimage(&b_button_b, _T("..\\pictures\\face\\button\\b_button.png"), 195, 116);
	//
	loadimage(&word, _T("..\\pictures\\face\\background\\word.png"), 600, 600);
	loadimage(&word_z, _T("..\\pictures\\face\\background\\word_z.png"), 600, 600);
	//加载地图图片
	loadimage(&line1, _T("..\\pictures\\mappictures\\line1.jpg"), 900, 511);
	loadimage(&line2, _T("..\\pictures\\mappictures\\line2.jpg"), 900, 511);
	loadimage(&line3, _T("..\\pictures\\mappictures\\line3.jpg"), 806,550 );
	loadimage(&line4, _T("..\\pictures\\mappictures\\line4.jpg"), 500, 670);
	loadimage(&line5, _T("..\\pictures\\mappictures\\line5.jpg"), 900, 511);
	loadimage(&line7, _T("..\\pictures\\mappictures\\line7.jpg"), 800, 511);
	loadimage(&line9, _T("..\\pictures\\mappictures\\line9.jpg"), 920, 390);
	loadimage(&line11, _T("..\\pictures\\mappictures\\line11.jpg"), 500, 660);
	loadimage(&line_all, _T("..\\pictures\\mappictures\\all.jpg"), 900, 800);
	loadimage(&c_button, _T("..\\pictures\\face\\button\\c_button.jpg"), 120, 36);
	loadimage(&c_button_2, _T("..\\pictures\\face\\button\\c_button.jpg"), 150, 45);
	//
	loadimage(&input, _T("..\\pictures\\face\\button\\input.png"), 220, 100); 
	loadimage(&input_z, _T("..\\pictures\\face\\button\\input_z.png"), 220, 100);
	loadimage(&qi ,_T("..\\pictures\\face\\button\\qi.png"), 59, 80);
	loadimage(&qi_z, _T("..\\pictures\\face\\button\\qi_z.png"), 59, 80);
	loadimage(&zhong, _T("..\\pictures\\face\\button\\zhong.png"), 48, 60);
	loadimage(&zhong_z, _T("..\\pictures\\face\\button\\zhong_z.png"), 48, 60);

	loadimage(&word_2, _T("..\\pictures\\face\\background\\word.png"), 350, 200);
	loadimage(&word_2_z, _T("..\\pictures\\face\\background\\word_z.png"), 350, 200);

	loadimage(&Word, _T("..\\pictures\\face\\background\\word_2.png"), 1300, 400);
	loadimage(&Word_z, _T("..\\pictures\\face\\background\\word_2_z.png"), 1300, 400);
	return 0;
}

int welCome()
{
	TCHAR s[] = _T("深圳地铁自助售票系统");
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
	f.lfHeight = 30;
	settextstyle(&f);
	outtextxy(100, 450, _T("作者：190320121张泽斌"));
	outtextxy(100, 500, _T("哈尔滨工业大学（深圳）"));

	return 0;
}

//子系统到主菜单的过渡动画
int MidAnimation()
{
	BeginBatchDraw();
	TCHAR s[] = _T("深圳地铁自助售票系统");
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
	for (int i = 1; i <= 20; i++)
	{
		putimage(-21 * i, 0, &background);
		outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
		putimage(730.9-21*i, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(730.9-21*i, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		Sleep(8);
		FlushBatchDraw();
	}
	loadimage(&b_button_a, _T("..\\pictures\\face\\button\\b_button _a.png"), 195, 116);
	loadimage(&b_button_b, _T("..\\pictures\\face\\button\\b_button.png"), 195, 116);
	for (int j = 0; j <= 10; j++)
	{
		putimage(-420, 0, &background);
		f.lfHeight = 48;
		settextstyle(&f);
		outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		putimage(1180-28*j, 150, &b_button_b, SRCAND);
		putimage(1180-28*j, 150, &b_button_a, SRCPAINT);
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(1250 - 28 * j, 190, _T("购票"));
		Sleep(10);
		FlushBatchDraw();
	}
	for (int j = 0; j <= 10; j++)
	{
		putimage(-420, 0, &background);
		f.lfHeight = 48;
		settextstyle(&f);
		outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		putimage(1180 - 280, 150, &b_button_b, SRCAND);
		putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(1250 - 280, 190, _T("购票"));
		putimage(1180 - 28 * j, 300, &b_button_b, SRCAND);
		putimage(1180 - 28 * j, 300, &b_button_a, SRCPAINT);
		outtextxy(1225 - 28 * j, DITUCHAXUN_Y, _T("地图查询"));
		Sleep(10);
		FlushBatchDraw();
	}
	for (int j = 0; j <= 10; j++)
	{
		putimage(-420, 0, &background);
		f.lfHeight = 48;
		settextstyle(&f);
		outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		putimage(1180 - 280, 150, &b_button_b, SRCAND);
		putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(1250 - 280, 190, _T("购票"));
		putimage(1180 - 280, 300, &b_button_b, SRCAND);
		putimage(1180 - 280, 300, &b_button_a, SRCPAINT);
		outtextxy(DITUCHAXUN_X, DITUCHAXUN_Y, _T("地图查询"));
		putimage(1180 - 28 * j, 450, &b_button_b, SRCAND);
		putimage(1180 - 28 * j, 450, &b_button_a, SRCPAINT);
		outtextxy(1225-28*j, TUICHUXITONG_Y, _T("退出系统"));
		Sleep(10);
		FlushBatchDraw();
	}
	for (int j = 0; j <= 10; j++)
	{
		putimage(-420, 0, &background);
		f.lfHeight = 48;
		settextstyle(&f);
		outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		putimage(1180 - 280, 150, &b_button_b, SRCAND);
		putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(1250 - 280, 190, _T("购票"));
		putimage(1180 - 280, 300, &b_button_b, SRCAND);
		putimage(1180 - 280, 300, &b_button_a, SRCPAINT);
		outtextxy(DITUCHAXUN_X, DITUCHAXUN_Y, _T("地图查询"));
		putimage(1180 - 280, 450, &b_button_b, SRCAND);
		putimage(1180 - 280, 450, &b_button_a, SRCPAINT);
		outtextxy(TUICHUXITONG_X, TUICHUXITONG_Y, _T("退出系统"));
		putimage(1180 - 28 * j, 600, &b_button_b, SRCAND);
		putimage(1180 - 28 * j, 600, &b_button_a, SRCPAINT);
		outtextxy(1225-28*j, 640, _T("使用说明"));
		Sleep(10);
		FlushBatchDraw();
	}
	f.lfHeight = 48;
	settextstyle(&f);
	EndBatchDraw();
	return 0;
}

//从主菜单到子系统的过渡动画
int MidAnimation_b(int a)
{
	BeginBatchDraw();
	TCHAR s[] = _T("深圳地铁自助售票系统");
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
	for (int i = 1; i <= 20; i++)
	{
		putimage(21 * i-21*20, 0, &background);
		outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
		putimage(730.9 + 21 * i-21*20, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(730.9 + 21 * i-21*20, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		if (a == 5)
		{
			putimage(0, 740-30*i, &word_z, SRCAND);
			putimage(0, 740-30*i, &word, SRCPAINT);
			f.lfHeight = 20;
			settextstyle(&f);
			RECT r = { 50,270 + 600 - 30 * i,600,850 + 600 - 30 * i };
			drawtext(_T("购票流程：\n1.点击购票按钮后进入购票界面；\n2.键盘键入起止站的名称，如需返回主界面，请按esc键；\n3.键盘键入购票数。如需返回重新键入起止站，请按esc\n键；\n4.根据推荐路线投币。\n\n用户须知：\n1.本系统的推荐路线均为经过计算的最短路线；\n2.在购票界面、地图查询界面和使用说明界面点击右方旋\n转的按钮均可返回主界面；\n3.票价收费标准：首4公里2元；4公里至12公里部分，每1\n元可乘坐4公里；12公里至24公里部分，每1元可乘坐6公\n里；超过24公里，每1元可乘坐8公里。普通车厢以最短路\n径原则确定计费路径，全路网普通车厢单程票价最低2元、\n最高14元。"),
				&r, DT_LEFT);
			f.lfHeight = 48;
			settextstyle(&f);
		}
		Sleep(8);
		FlushBatchDraw();
	}
	if (a == 4)
	{
		for (int j = 20; j >= -5; j--)
		{
			f.lfHeight = 48;
			settextstyle(&f);
			putimage(21 * 20 - 21 * 20, 0, &background);
			outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
			putimage(730.9 + 21 * 20 - 21 * 20, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
			putimage(730.9 + 21 * 20 - 21 * 20, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
			f.lfHeight = 24;
			settextstyle(&f);
			putimage(CBUTTON_X, CBUTTON_Y + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 28, CBUTTON_Y + (j * j * j * j) / 400 + 6, _T("1号线"));
			putimage(CBUTTON_X, CBUTTON_Y + 50 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 28, CBUTTON_Y + 50 + (j * j * j * j) / 400 + 6, _T("3号线"));
			putimage(CBUTTON_X, CBUTTON_Y + 100 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 28, CBUTTON_Y + 100 + (j * j * j * j) / 400 + 6, _T("5号线"));
			putimage(CBUTTON_X, CBUTTON_Y + 150 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 28, CBUTTON_Y + 150 + (j * j * j * j) / 400 + 6, _T("9号线"));
			putimage(CBUTTON_X + 180, CBUTTON_Y + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 180 + 28, CBUTTON_Y + (j * j * j * j) / 400 + 6, _T("2号线"));
			putimage(CBUTTON_X + 180, CBUTTON_Y + 50 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 180 + 28, CBUTTON_Y + 50 + (j * j * j * j) / 400 + 6, _T("4号线"));
			putimage(CBUTTON_X + 180, CBUTTON_Y + 100 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 180 + 28, CBUTTON_Y + 100 + (j * j * j * j) / 400 + 6, _T("7号线"));
			putimage(CBUTTON_X + 180, CBUTTON_Y + 150 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 180 + 22, CBUTTON_Y + 150 + (j * j * j * j) / 400 + 6, _T("11号线"));
			putimage(CBUTTON_X + 86, CBUTTON_Y + 250 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 86 + 23, CBUTTON_Y + 250 + (j * j * j * j) / 400 + 6, _T("总路线"));
			Sleep(25);
			FlushBatchDraw();
		}
	}
	if (a == 3)
	{
		for (int k = 0; k <= 10; k++)
		{
			f.lfHeight = 48;
			settextstyle(&f);
			putimage(21 * 20 - 21 * 20, 0, &background);
			outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
			putimage(730.9 + 21 * 20 - 21 * 20, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
			putimage(730.9 + 21 * 20 - 21 * 20, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
			putimage(64-200+k*20+20, 174, &qi_z, SRCAND);
			putimage(64-200+k*20+20, 174, &qi, SRCPAINT);
			putimage(70-200+k*20+20, 276, &zhong_z, SRCAND);
			putimage(70-200+k*20+20, 276, &zhong, SRCPAINT);
			putimage(90-200+k*20+20, 180, &input_z, SRCAND);
			putimage(90-200+k*20+20, 180, &input, SRCPAINT);
			putimage(90-200+k*20+20, 260, &input_z, SRCAND);
			putimage(90-200+k*20+20, 260, &input, SRCPAINT);
			putimage(110-200+k*20+30, 380, &c_button);
			f.lfHeight = 26;
			settextstyle(&f);
			outtextxy(140 - 200 + k * 20+20, 217, _T("输入起始站"));
			outtextxy(140 - 200 + k * 20+20, 297, _T("输入终点站"));
			outtextxy(170 - 200 + k * 20, 385, _T("确定"));
			FlushBatchDraw();
			Sleep(10);
		}
	}
	EndBatchDraw();
	f.lfHeight = 48;
	settextstyle(&f);
	return 0;
}

//主按钮旋转动画
int buttonRo(int a, bool b)
{
	static int i = 0;
	if (i == 0)
	{
		putimage(731-a, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(731-a, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		i++;
	}
	else if (i == 1)
	{
		putimage(700-a, 302, &a_button_2_z,SRCAND);
		putimage(700-a, 302,  &a_button_2, SRCPAINT);
		i++;
	}
	else if (i == 2)
	{
		putimage(620-a, 213, &a_button_3_z, SRCAND);
		putimage(620-a, 213,  &a_button_3,  SRCPAINT);
		i++;
	}
	else if (i == 3)
	{
		putimage(662-a, 257,  &a_button_4_z,  SRCAND);
		putimage(662-a, 257,  &a_button_4,  SRCPAINT);
		i = 0;
	}
	FlushBatchDraw();
	if (b == true)
	{
		Sleep(120);
	}
	return 0;
}

int whenstate_2()
{
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	putimage(-420, 0, &background);
	f.lfHeight = 48;
	settextstyle(&f);
	outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
	putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
	putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
	putimage(1180 - 280, 150, &b_button_b, SRCAND);
	putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
	f.lfHeight = 30;
	settextstyle(&f);
	outtextxy(1250 - 280, 190, _T("购票"));
	putimage(1180 - 280, 300, &b_button_b, SRCAND);
	putimage(1180 - 280, 300, &b_button_a, SRCPAINT);
	outtextxy(DITUCHAXUN_X, DITUCHAXUN_Y, _T("地图查询"));
	putimage(1180 - 280, 450, &b_button_b, SRCAND);
	putimage(1180 - 280, 450, &b_button_a, SRCPAINT);
	outtextxy(TUICHUXITONG_X, TUICHUXITONG_Y, _T("退出系统"));
	putimage(1180 - 280, 600, &b_button_b, SRCAND);
	putimage(1180 - 280, 600, &b_button_a, SRCPAINT);
	outtextxy(1225 - 280, 640, _T("使用说明"));
	return 0;
}

int button_anmi_2(int a,bool b)
{
	int X = 0;
	if (b == false)
	{
		IMAGE b_button_a_0, b_button_b_0;
		loadimage(&b_button_a_0, _T("..\\pictures\\face\\button\\b_button _a.png"), 214, 127);
		loadimage(&b_button_b_0, _T("..\\pictures\\face\\button\\b_button.png"), 214, 127);
		if (a == 1)
		{
			LOGFONT f;
			gettextstyle(&f);
			f.lfHeight = 48;
			_tcscpy(f.lfFaceName, _T("黑体"));
			f.lfQuality = ANTIALIASED_QUALITY;
			settextstyle(&f);
			setbkmode(TRANSPARENT);
			putimage(-420, 0, &background);
			f.lfHeight = 48;
			settextstyle(&f);
			outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
			f.lfHeight = 30;
			settextstyle(&f);
			putimage(1180 - 280, 300, &b_button_b, SRCAND);
			putimage(1180 - 280, 300, &b_button_a, SRCPAINT);
			outtextxy(DITUCHAXUN_X, DITUCHAXUN_Y, _T("地图查询"));
			putimage(1180 - 280, 450, &b_button_b, SRCAND);
			putimage(1180 - 280, 450, &b_button_a, SRCPAINT);
			outtextxy(TUICHUXITONG_X, TUICHUXITONG_Y, _T("退出系统"));
			putimage(1180 - 280, 600, &b_button_b, SRCAND);
			putimage(1180 - 280, 600, &b_button_a, SRCPAINT);
			outtextxy(1225 - 280, 640, _T("使用说明"));
			X = 140;
			putimage(1120 - 280, X, &b_button_b_0, SRCAND);
			putimage(1120 - 280, X, &b_button_a_0, SRCPAINT);
			f.lfHeight = 33;
			settextstyle(&f);
			outtextxy(1198 - 280, 180, _T("购票"));
		}
		else if (a == 2)
		{
			LOGFONT f;
			gettextstyle(&f);
			f.lfHeight = 48;
			_tcscpy(f.lfFaceName, _T("黑体"));
			f.lfQuality = ANTIALIASED_QUALITY;
			settextstyle(&f);
			setbkmode(TRANSPARENT);
			putimage(-420, 0, &background);
			f.lfHeight = 48;
			settextstyle(&f);
			outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
			putimage(1180 - 280, 150, &b_button_b, SRCAND);
			putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
			f.lfHeight = 30;
			settextstyle(&f);
			outtextxy(1250 - 280, 190, _T("购票"));
			putimage(1180 - 280, 450, &b_button_b, SRCAND);
			putimage(1180 - 280, 450, &b_button_a, SRCPAINT);
			outtextxy(TUICHUXITONG_X, TUICHUXITONG_Y, _T("退出系统"));
			putimage(1180 - 280, 600, &b_button_b, SRCAND);
			putimage(1180 - 280, 600, &b_button_a, SRCPAINT);
			outtextxy(1225 - 280, 640, _T("使用说明"));
			X = 290;
			putimage(1120 - 280, X, &b_button_b_0, SRCAND);
			putimage(1120 - 280, X, &b_button_a_0, SRCPAINT);
			f.lfHeight = 33;
			settextstyle(&f);
			outtextxy(1165 - 280, 330, _T("地图查询"));
		}
		else if (a == 3)
		{
			LOGFONT f;
			gettextstyle(&f);
			f.lfHeight = 48;
			_tcscpy(f.lfFaceName, _T("黑体"));
			f.lfQuality = ANTIALIASED_QUALITY;
			settextstyle(&f);
			setbkmode(TRANSPARENT);
			putimage(-420, 0, &background);
			f.lfHeight = 48;
			settextstyle(&f);
			outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
			putimage(1180 - 280, 150, &b_button_b, SRCAND);
			putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
			f.lfHeight = 30;
			settextstyle(&f);
			outtextxy(1250 - 280, 190, _T("购票"));
			putimage(1180 - 280, 300, &b_button_b, SRCAND);
			putimage(1180 - 280, 300, &b_button_a, SRCPAINT);
			outtextxy(DITUCHAXUN_X, DITUCHAXUN_Y, _T("地图查询"));
			putimage(1180 - 280, 600, &b_button_b, SRCAND);
			putimage(1180 - 280, 600, &b_button_a, SRCPAINT);
			outtextxy(1225 - 280, 640, _T("使用说明"));
			X = 440;
			putimage(1120 - 280, X, &b_button_b_0, SRCAND);
			putimage(1120 - 280, X, &b_button_a_0, SRCPAINT);
			f.lfHeight = 33;
			settextstyle(&f);
			outtextxy(1165 - 280, 480, _T("退出系统"));
		}
		else if (a == 4)
		{
			LOGFONT f;
			gettextstyle(&f);
			f.lfHeight = 48;
			_tcscpy(f.lfFaceName, _T("黑体"));
			f.lfQuality = ANTIALIASED_QUALITY;
			settextstyle(&f);
			setbkmode(TRANSPARENT);
			putimage(-420, 0, &background);
			f.lfHeight = 48;
			settextstyle(&f);
			outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
			putimage(1180 - 280, 150, &b_button_b, SRCAND);
			putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
			f.lfHeight = 30;
			settextstyle(&f);
			outtextxy(1250 - 280, 190, _T("购票"));
			putimage(1180 - 280, 300, &b_button_b, SRCAND);
			putimage(1180 - 280, 300, &b_button_a, SRCPAINT);
			outtextxy(DITUCHAXUN_X, DITUCHAXUN_Y, _T("地图查询"));
			putimage(1180 - 280, 450, &b_button_b, SRCAND);
			putimage(1180 - 280, 450, &b_button_a, SRCPAINT);
			outtextxy(TUICHUXITONG_X, TUICHUXITONG_Y, _T("退出系统"));
			X = 590;
			putimage(1120 - 280, X, &b_button_b_0, SRCAND);
			putimage(1120 - 280, X, &b_button_a_0, SRCPAINT);
			f.lfHeight = 33;
			settextstyle(&f);
			outtextxy(1165 - 280, 630, _T("使用说明"));
		}
	}
	else if (b == true)
	{

	}
	return 0;
}

//状态4时界面画面
int showstate4()
{
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	settextstyle(&f);
	putimage(21 * 20 - 21 * 20, 0, &background);
	outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
	putimage(730.9 + 21 * 20 - 21 * 20, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
	putimage(730.9 + 21 * 20 - 21 * 20, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
	f.lfHeight = 24;
	settextstyle(&f);
	putimage(CBUTTON_X, CBUTTON_Y + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 28, CBUTTON_Y + 625 / 400 + 6, _T("1号线"));
	putimage(CBUTTON_X, CBUTTON_Y + 50 + 625/ 400, &c_button);
	outtextxy(CBUTTON_X + 28, CBUTTON_Y + 50 + 625 / 400 + 6, _T("3号线"));
	putimage(CBUTTON_X, CBUTTON_Y + 100 + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 28, CBUTTON_Y + 100 + 625 / 400 + 6, _T("5号线"));
	putimage(CBUTTON_X, CBUTTON_Y + 150 + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 28, CBUTTON_Y + 150 + 625 / 400 + 6, _T("9号线"));
	putimage(CBUTTON_X + 180, CBUTTON_Y + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 180 + 28, CBUTTON_Y + 625 / 400 + 6, _T("2号线"));
	putimage(CBUTTON_X + 180, CBUTTON_Y + 50 + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 180 + 28, CBUTTON_Y + 50 + 625 / 400 + 6, _T("4号线"));
	putimage(CBUTTON_X + 180, CBUTTON_Y + 100 + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 180 + 28, CBUTTON_Y + 100 + 625 / 400 + 6, _T("7号线"));
	putimage(CBUTTON_X + 180, CBUTTON_Y + 150 + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 180 + 22, CBUTTON_Y + 150 + 625 / 400 + 6, _T("11号线"));
	putimage(CBUTTON_X + 86, CBUTTON_Y + 250 + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 86 + 23, CBUTTON_Y + 250 + 625 / 400 + 6, _T("总路线"));
	FlushBatchDraw();
	return 0;
}

//状态5时的函数
int state_5()
{
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
	putimage(0, 140,  &word_z,SRCAND);
	putimage(0, 140,  &word, SRCPAINT);
	f.lfHeight = 20;
	settextstyle(&f);
	RECT r = { 50,270,600,850 };
	drawtext(_T("购票流程：\n1.点击购票按钮后进入购票界面；\n2.键盘键入起止站的名称，如需返回主界面，请按esc键；\n3.键盘键入购票数。如需返回重新键入起止站，请按esc\n键；\n4.根据推荐路线投币。\n\n用户须知：\n1.本系统的推荐路线均为经过计算的最短路线；\n2.在购票界面、地图查询界面和使用说明界面点击右方旋\n转的按钮均可返回主界面；\n3.票价收费标准：首4公里2元；4公里至12公里部分，每1\n元可乘坐4公里；12公里至24公里部分，每1元可乘坐6公\n里；超过24公里，每1元可乘坐8公里。普通车厢以最短路\n径原则确定计费路径，全路网普通车厢单程票价最低2元、\n最高14元。"),
		&r, DT_LEFT);
	FlushBatchDraw();
	return 0;
}

//进入投币界面动画
int coin_mid(TCHAR per_pay[], TCHAR all_pay[], int ticket_num,int fin_fee,bool a)
{
	LOGFONT f;
	gettextstyle(&f);
	int j = 0;
	for (int i = 0; i <= 10; i++)
	{
		if (a == true)
		{
			j = +600 - 60 * i;
		}
		else if (a == false)
		{
			j = 60 * i;
		}
		f.lfHeight = 48;
		settextstyle(&f);
		putimage(21 * 20 - 21 * 20, 0, &background);
		outtextxy(100, SHUOMING_Y, _T("深圳地铁自助售票系统"));
		f.lfHeight = 36;
		settextstyle(&f);
		outtextxy(150, 250+j, _T("输入票数："));
		outtextxy(150, 320 + j, _T("单人票价："));
		outtextxy(150, 390 + j, _T("总计票价："));
		wsprintf(per_pay, L"%d元/人", fin_fee);
		wsprintf(all_pay, L"%d元", fin_fee * ticket_num);
		putimage(320, 220 + j, &input_z, SRCAND);
		putimage(320, 220 + j, &input, SRCPAINT);
		outtextxy(360, 320 + j, per_pay);
		outtextxy(360, 390 + j, all_pay);
		putimage(150 + 30, 460 + j, &c_button);
		putimage(320 + 30, 460 + j, &c_button);
		f.lfHeight = 24;
		settextstyle(&f);
		putimage(150 + 30, 460 + j, &c_button);
		outtextxy(180 + 12, 465 + j, _T("确定投币"));
		putimage(320 + 30, 460 + j, &c_button);
		outtextxy(350 + 35, 465 + j, _T("取消"));
		Sleep(8);
		FlushBatchDraw();
	}
	return 0;
}