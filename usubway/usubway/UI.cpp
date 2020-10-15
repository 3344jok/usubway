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
	//���ص�ͼͼƬ
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
	TCHAR s[] = _T("���ڵ���������Ʊϵͳ");
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
	f.lfHeight = 30;
	settextstyle(&f);
	outtextxy(100, 450, _T("���ߣ�190320121�����"));
	outtextxy(100, 500, _T("��������ҵ��ѧ�����ڣ�"));

	return 0;
}

//��ϵͳ�����˵��Ĺ��ɶ���
int MidAnimation()
{
	BeginBatchDraw();
	TCHAR s[] = _T("���ڵ���������Ʊϵͳ");
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
	for (int i = 1; i <= 20; i++)
	{
		putimage(-21 * i, 0, &background);
		outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
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
		outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		putimage(1180-28*j, 150, &b_button_b, SRCAND);
		putimage(1180-28*j, 150, &b_button_a, SRCPAINT);
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(1250 - 28 * j, 190, _T("��Ʊ"));
		Sleep(10);
		FlushBatchDraw();
	}
	for (int j = 0; j <= 10; j++)
	{
		putimage(-420, 0, &background);
		f.lfHeight = 48;
		settextstyle(&f);
		outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		putimage(1180 - 280, 150, &b_button_b, SRCAND);
		putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(1250 - 280, 190, _T("��Ʊ"));
		putimage(1180 - 28 * j, 300, &b_button_b, SRCAND);
		putimage(1180 - 28 * j, 300, &b_button_a, SRCPAINT);
		outtextxy(1225 - 28 * j, DITUCHAXUN_Y, _T("��ͼ��ѯ"));
		Sleep(10);
		FlushBatchDraw();
	}
	for (int j = 0; j <= 10; j++)
	{
		putimage(-420, 0, &background);
		f.lfHeight = 48;
		settextstyle(&f);
		outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		putimage(1180 - 280, 150, &b_button_b, SRCAND);
		putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(1250 - 280, 190, _T("��Ʊ"));
		putimage(1180 - 280, 300, &b_button_b, SRCAND);
		putimage(1180 - 280, 300, &b_button_a, SRCPAINT);
		outtextxy(DITUCHAXUN_X, DITUCHAXUN_Y, _T("��ͼ��ѯ"));
		putimage(1180 - 28 * j, 450, &b_button_b, SRCAND);
		putimage(1180 - 28 * j, 450, &b_button_a, SRCPAINT);
		outtextxy(1225-28*j, TUICHUXITONG_Y, _T("�˳�ϵͳ"));
		Sleep(10);
		FlushBatchDraw();
	}
	for (int j = 0; j <= 10; j++)
	{
		putimage(-420, 0, &background);
		f.lfHeight = 48;
		settextstyle(&f);
		outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		putimage(1180 - 280, 150, &b_button_b, SRCAND);
		putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
		f.lfHeight = 30;
		settextstyle(&f);
		outtextxy(1250 - 280, 190, _T("��Ʊ"));
		putimage(1180 - 280, 300, &b_button_b, SRCAND);
		putimage(1180 - 280, 300, &b_button_a, SRCPAINT);
		outtextxy(DITUCHAXUN_X, DITUCHAXUN_Y, _T("��ͼ��ѯ"));
		putimage(1180 - 280, 450, &b_button_b, SRCAND);
		putimage(1180 - 280, 450, &b_button_a, SRCPAINT);
		outtextxy(TUICHUXITONG_X, TUICHUXITONG_Y, _T("�˳�ϵͳ"));
		putimage(1180 - 28 * j, 600, &b_button_b, SRCAND);
		putimage(1180 - 28 * j, 600, &b_button_a, SRCPAINT);
		outtextxy(1225-28*j, 640, _T("ʹ��˵��"));
		Sleep(10);
		FlushBatchDraw();
	}
	f.lfHeight = 48;
	settextstyle(&f);
	EndBatchDraw();
	return 0;
}

//�����˵�����ϵͳ�Ĺ��ɶ���
int MidAnimation_b(int a)
{
	BeginBatchDraw();
	TCHAR s[] = _T("���ڵ���������Ʊϵͳ");
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
	for (int i = 1; i <= 20; i++)
	{
		putimage(21 * i-21*20, 0, &background);
		outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
		putimage(730.9 + 21 * i-21*20, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(730.9 + 21 * i-21*20, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		if (a == 5)
		{
			putimage(0, 740-30*i, &word_z, SRCAND);
			putimage(0, 740-30*i, &word, SRCPAINT);
			f.lfHeight = 20;
			settextstyle(&f);
			RECT r = { 50,270 + 600 - 30 * i,600,850 + 600 - 30 * i };
			drawtext(_T("��Ʊ���̣�\n1.�����Ʊ��ť����빺Ʊ���棻\n2.���̼�����ֹվ�����ƣ����践�������棬�밴esc����\n3.���̼��빺Ʊ�������践�����¼�����ֹվ���밴esc\n����\n4.�����Ƽ�·��Ͷ�ҡ�\n\n�û���֪��\n1.��ϵͳ���Ƽ�·�߾�Ϊ������������·�ߣ�\n2.�ڹ�Ʊ���桢��ͼ��ѯ�����ʹ��˵���������ҷ���\nת�İ�ť���ɷ��������棻\n3.Ʊ���շѱ�׼����4����2Ԫ��4������12���ﲿ�֣�ÿ1\nԪ�ɳ���4���12������24���ﲿ�֣�ÿ1Ԫ�ɳ���6��\n�����24���ÿ1Ԫ�ɳ���8�����ͨ���������·\n��ԭ��ȷ���Ʒ�·����ȫ·����ͨ���ᵥ��Ʊ�����2Ԫ��\n���14Ԫ��"),
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
			outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
			putimage(730.9 + 21 * 20 - 21 * 20, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
			putimage(730.9 + 21 * 20 - 21 * 20, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
			f.lfHeight = 24;
			settextstyle(&f);
			putimage(CBUTTON_X, CBUTTON_Y + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 28, CBUTTON_Y + (j * j * j * j) / 400 + 6, _T("1����"));
			putimage(CBUTTON_X, CBUTTON_Y + 50 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 28, CBUTTON_Y + 50 + (j * j * j * j) / 400 + 6, _T("3����"));
			putimage(CBUTTON_X, CBUTTON_Y + 100 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 28, CBUTTON_Y + 100 + (j * j * j * j) / 400 + 6, _T("5����"));
			putimage(CBUTTON_X, CBUTTON_Y + 150 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 28, CBUTTON_Y + 150 + (j * j * j * j) / 400 + 6, _T("9����"));
			putimage(CBUTTON_X + 180, CBUTTON_Y + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 180 + 28, CBUTTON_Y + (j * j * j * j) / 400 + 6, _T("2����"));
			putimage(CBUTTON_X + 180, CBUTTON_Y + 50 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 180 + 28, CBUTTON_Y + 50 + (j * j * j * j) / 400 + 6, _T("4����"));
			putimage(CBUTTON_X + 180, CBUTTON_Y + 100 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 180 + 28, CBUTTON_Y + 100 + (j * j * j * j) / 400 + 6, _T("7����"));
			putimage(CBUTTON_X + 180, CBUTTON_Y + 150 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 180 + 22, CBUTTON_Y + 150 + (j * j * j * j) / 400 + 6, _T("11����"));
			putimage(CBUTTON_X + 86, CBUTTON_Y + 250 + (j * j * j * j) / 400, &c_button);
			outtextxy(CBUTTON_X + 86 + 23, CBUTTON_Y + 250 + (j * j * j * j) / 400 + 6, _T("��·��"));
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
			outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
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
			outtextxy(140 - 200 + k * 20+20, 217, _T("������ʼվ"));
			outtextxy(140 - 200 + k * 20+20, 297, _T("�����յ�վ"));
			outtextxy(170 - 200 + k * 20, 385, _T("ȷ��"));
			FlushBatchDraw();
			Sleep(10);
		}
	}
	EndBatchDraw();
	f.lfHeight = 48;
	settextstyle(&f);
	return 0;
}

//����ť��ת����
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
	_tcscpy(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	putimage(-420, 0, &background);
	f.lfHeight = 48;
	settextstyle(&f);
	outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
	putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
	putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
	putimage(1180 - 280, 150, &b_button_b, SRCAND);
	putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
	f.lfHeight = 30;
	settextstyle(&f);
	outtextxy(1250 - 280, 190, _T("��Ʊ"));
	putimage(1180 - 280, 300, &b_button_b, SRCAND);
	putimage(1180 - 280, 300, &b_button_a, SRCPAINT);
	outtextxy(DITUCHAXUN_X, DITUCHAXUN_Y, _T("��ͼ��ѯ"));
	putimage(1180 - 280, 450, &b_button_b, SRCAND);
	putimage(1180 - 280, 450, &b_button_a, SRCPAINT);
	outtextxy(TUICHUXITONG_X, TUICHUXITONG_Y, _T("�˳�ϵͳ"));
	putimage(1180 - 280, 600, &b_button_b, SRCAND);
	putimage(1180 - 280, 600, &b_button_a, SRCPAINT);
	outtextxy(1225 - 280, 640, _T("ʹ��˵��"));
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
			_tcscpy(f.lfFaceName, _T("����"));
			f.lfQuality = ANTIALIASED_QUALITY;
			settextstyle(&f);
			setbkmode(TRANSPARENT);
			putimage(-420, 0, &background);
			f.lfHeight = 48;
			settextstyle(&f);
			outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
			f.lfHeight = 30;
			settextstyle(&f);
			putimage(1180 - 280, 300, &b_button_b, SRCAND);
			putimage(1180 - 280, 300, &b_button_a, SRCPAINT);
			outtextxy(DITUCHAXUN_X, DITUCHAXUN_Y, _T("��ͼ��ѯ"));
			putimage(1180 - 280, 450, &b_button_b, SRCAND);
			putimage(1180 - 280, 450, &b_button_a, SRCPAINT);
			outtextxy(TUICHUXITONG_X, TUICHUXITONG_Y, _T("�˳�ϵͳ"));
			putimage(1180 - 280, 600, &b_button_b, SRCAND);
			putimage(1180 - 280, 600, &b_button_a, SRCPAINT);
			outtextxy(1225 - 280, 640, _T("ʹ��˵��"));
			X = 140;
			putimage(1120 - 280, X, &b_button_b_0, SRCAND);
			putimage(1120 - 280, X, &b_button_a_0, SRCPAINT);
			f.lfHeight = 33;
			settextstyle(&f);
			outtextxy(1198 - 280, 180, _T("��Ʊ"));
		}
		else if (a == 2)
		{
			LOGFONT f;
			gettextstyle(&f);
			f.lfHeight = 48;
			_tcscpy(f.lfFaceName, _T("����"));
			f.lfQuality = ANTIALIASED_QUALITY;
			settextstyle(&f);
			setbkmode(TRANSPARENT);
			putimage(-420, 0, &background);
			f.lfHeight = 48;
			settextstyle(&f);
			outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
			putimage(1180 - 280, 150, &b_button_b, SRCAND);
			putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
			f.lfHeight = 30;
			settextstyle(&f);
			outtextxy(1250 - 280, 190, _T("��Ʊ"));
			putimage(1180 - 280, 450, &b_button_b, SRCAND);
			putimage(1180 - 280, 450, &b_button_a, SRCPAINT);
			outtextxy(TUICHUXITONG_X, TUICHUXITONG_Y, _T("�˳�ϵͳ"));
			putimage(1180 - 280, 600, &b_button_b, SRCAND);
			putimage(1180 - 280, 600, &b_button_a, SRCPAINT);
			outtextxy(1225 - 280, 640, _T("ʹ��˵��"));
			X = 290;
			putimage(1120 - 280, X, &b_button_b_0, SRCAND);
			putimage(1120 - 280, X, &b_button_a_0, SRCPAINT);
			f.lfHeight = 33;
			settextstyle(&f);
			outtextxy(1165 - 280, 330, _T("��ͼ��ѯ"));
		}
		else if (a == 3)
		{
			LOGFONT f;
			gettextstyle(&f);
			f.lfHeight = 48;
			_tcscpy(f.lfFaceName, _T("����"));
			f.lfQuality = ANTIALIASED_QUALITY;
			settextstyle(&f);
			setbkmode(TRANSPARENT);
			putimage(-420, 0, &background);
			f.lfHeight = 48;
			settextstyle(&f);
			outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
			putimage(1180 - 280, 150, &b_button_b, SRCAND);
			putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
			f.lfHeight = 30;
			settextstyle(&f);
			outtextxy(1250 - 280, 190, _T("��Ʊ"));
			putimage(1180 - 280, 300, &b_button_b, SRCAND);
			putimage(1180 - 280, 300, &b_button_a, SRCPAINT);
			outtextxy(DITUCHAXUN_X, DITUCHAXUN_Y, _T("��ͼ��ѯ"));
			putimage(1180 - 280, 600, &b_button_b, SRCAND);
			putimage(1180 - 280, 600, &b_button_a, SRCPAINT);
			outtextxy(1225 - 280, 640, _T("ʹ��˵��"));
			X = 440;
			putimage(1120 - 280, X, &b_button_b_0, SRCAND);
			putimage(1120 - 280, X, &b_button_a_0, SRCPAINT);
			f.lfHeight = 33;
			settextstyle(&f);
			outtextxy(1165 - 280, 480, _T("�˳�ϵͳ"));
		}
		else if (a == 4)
		{
			LOGFONT f;
			gettextstyle(&f);
			f.lfHeight = 48;
			_tcscpy(f.lfFaceName, _T("����"));
			f.lfQuality = ANTIALIASED_QUALITY;
			settextstyle(&f);
			setbkmode(TRANSPARENT);
			putimage(-420, 0, &background);
			f.lfHeight = 48;
			settextstyle(&f);
			outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
			putimage(730.9 - 420, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
			putimage(1180 - 280, 150, &b_button_b, SRCAND);
			putimage(1180 - 280, 150, &b_button_a, SRCPAINT);
			f.lfHeight = 30;
			settextstyle(&f);
			outtextxy(1250 - 280, 190, _T("��Ʊ"));
			putimage(1180 - 280, 300, &b_button_b, SRCAND);
			putimage(1180 - 280, 300, &b_button_a, SRCPAINT);
			outtextxy(DITUCHAXUN_X, DITUCHAXUN_Y, _T("��ͼ��ѯ"));
			putimage(1180 - 280, 450, &b_button_b, SRCAND);
			putimage(1180 - 280, 450, &b_button_a, SRCPAINT);
			outtextxy(TUICHUXITONG_X, TUICHUXITONG_Y, _T("�˳�ϵͳ"));
			X = 590;
			putimage(1120 - 280, X, &b_button_b_0, SRCAND);
			putimage(1120 - 280, X, &b_button_a_0, SRCPAINT);
			f.lfHeight = 33;
			settextstyle(&f);
			outtextxy(1165 - 280, 630, _T("ʹ��˵��"));
		}
	}
	else if (b == true)
	{

	}
	return 0;
}

//״̬4ʱ���滭��
int showstate4()
{
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	settextstyle(&f);
	putimage(21 * 20 - 21 * 20, 0, &background);
	outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
	putimage(730.9 + 21 * 20 - 21 * 20, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
	putimage(730.9 + 21 * 20 - 21 * 20, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
	f.lfHeight = 24;
	settextstyle(&f);
	putimage(CBUTTON_X, CBUTTON_Y + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 28, CBUTTON_Y + 625 / 400 + 6, _T("1����"));
	putimage(CBUTTON_X, CBUTTON_Y + 50 + 625/ 400, &c_button);
	outtextxy(CBUTTON_X + 28, CBUTTON_Y + 50 + 625 / 400 + 6, _T("3����"));
	putimage(CBUTTON_X, CBUTTON_Y + 100 + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 28, CBUTTON_Y + 100 + 625 / 400 + 6, _T("5����"));
	putimage(CBUTTON_X, CBUTTON_Y + 150 + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 28, CBUTTON_Y + 150 + 625 / 400 + 6, _T("9����"));
	putimage(CBUTTON_X + 180, CBUTTON_Y + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 180 + 28, CBUTTON_Y + 625 / 400 + 6, _T("2����"));
	putimage(CBUTTON_X + 180, CBUTTON_Y + 50 + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 180 + 28, CBUTTON_Y + 50 + 625 / 400 + 6, _T("4����"));
	putimage(CBUTTON_X + 180, CBUTTON_Y + 100 + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 180 + 28, CBUTTON_Y + 100 + 625 / 400 + 6, _T("7����"));
	putimage(CBUTTON_X + 180, CBUTTON_Y + 150 + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 180 + 22, CBUTTON_Y + 150 + 625 / 400 + 6, _T("11����"));
	putimage(CBUTTON_X + 86, CBUTTON_Y + 250 + 625 / 400, &c_button);
	outtextxy(CBUTTON_X + 86 + 23, CBUTTON_Y + 250 + 625 / 400 + 6, _T("��·��"));
	FlushBatchDraw();
	return 0;
}

//״̬5ʱ�ĺ���
int state_5()
{
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
	putimage(0, 140,  &word_z,SRCAND);
	putimage(0, 140,  &word, SRCPAINT);
	f.lfHeight = 20;
	settextstyle(&f);
	RECT r = { 50,270,600,850 };
	drawtext(_T("��Ʊ���̣�\n1.�����Ʊ��ť����빺Ʊ���棻\n2.���̼�����ֹվ�����ƣ����践�������棬�밴esc����\n3.���̼��빺Ʊ�������践�����¼�����ֹվ���밴esc\n����\n4.�����Ƽ�·��Ͷ�ҡ�\n\n�û���֪��\n1.��ϵͳ���Ƽ�·�߾�Ϊ������������·�ߣ�\n2.�ڹ�Ʊ���桢��ͼ��ѯ�����ʹ��˵���������ҷ���\nת�İ�ť���ɷ��������棻\n3.Ʊ���շѱ�׼����4����2Ԫ��4������12���ﲿ�֣�ÿ1\nԪ�ɳ���4���12������24���ﲿ�֣�ÿ1Ԫ�ɳ���6��\n�����24���ÿ1Ԫ�ɳ���8�����ͨ���������·\n��ԭ��ȷ���Ʒ�·����ȫ·����ͨ���ᵥ��Ʊ�����2Ԫ��\n���14Ԫ��"),
		&r, DT_LEFT);
	FlushBatchDraw();
	return 0;
}

//����Ͷ�ҽ��涯��
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
		outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
		f.lfHeight = 36;
		settextstyle(&f);
		outtextxy(150, 250+j, _T("����Ʊ����"));
		outtextxy(150, 320 + j, _T("����Ʊ�ۣ�"));
		outtextxy(150, 390 + j, _T("�ܼ�Ʊ�ۣ�"));
		wsprintf(per_pay, L"%dԪ/��", fin_fee);
		wsprintf(all_pay, L"%dԪ", fin_fee * ticket_num);
		putimage(320, 220 + j, &input_z, SRCAND);
		putimage(320, 220 + j, &input, SRCPAINT);
		outtextxy(360, 320 + j, per_pay);
		outtextxy(360, 390 + j, all_pay);
		putimage(150 + 30, 460 + j, &c_button);
		putimage(320 + 30, 460 + j, &c_button);
		f.lfHeight = 24;
		settextstyle(&f);
		putimage(150 + 30, 460 + j, &c_button);
		outtextxy(180 + 12, 465 + j, _T("ȷ��Ͷ��"));
		putimage(320 + 30, 460 + j, &c_button);
		outtextxy(350 + 35, 465 + j, _T("ȡ��"));
		Sleep(8);
		FlushBatchDraw();
	}
	return 0;
}