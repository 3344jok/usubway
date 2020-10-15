#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include "routesearch.h"
#include "UI.h"
#include "whenfunction.h"


#define CBUTTON_X 150
#define CBUTTON_Y 300
#define SHUOMING_Y 90

//����һ��ȫ�ֱ�����¼��ǰ״̬
//1Ϊ��ʼ����
//2Ϊϵͳ������
//3Ϊ��Ʊ����
//4Ϊ��ͼ��ѯ����
//5Ϊϵͳ˵��
int State = 1;

int Three_state = 0;

//���������Ϣ
MOUSEMSG m;

/*int MapSearch();

//ִ��״̬1����ʼ����ĺ���
int whenState_1();

//ִ��״̬2����ʼ����ĺ���
int whenState_2();

//ִ��״̬3��ʹ��˵���ĺ���
int whenState_3();

//ִ��״̬4��ʹ��˵���ĺ���
int whenState_4();

//ִ��״̬5��ʹ��˵���ĺ���
int whenState_5();*/

//��char����ת��Ϊwchar_t����
TCHAR* CharToWchar_t(char* str);

//��wchar_t����ת��Ϊchar����
char* Wchar_tToChar(TCHAR* str);

bool swith;

//·���Ƽ���·�߲�ѯ
int MapSearch()
{
	char first_station[20] = {};
	char last_station[20] = {};
	scanf("%s", first_station);
	printf("%s\n", first_station);
	scanf("%s", last_station);
	printf("%s\n", last_station);
	secondmain(first_station, last_station);
	return 0;
}

//ִ��״̬1����ʼ����ĺ���
int whenState_1()
{
	welCome();
	buttonRo(0, false);
	BeginBatchDraw();
	static int sleeptime = 120;
	while (MouseHit())
	{
		m = GetMouseMsg();
		int PostionX = m.x;
		int PostionY = m.y;
		if (m.uMsg == WM_LBUTTONUP)
		{
			if (PostionX > 770 && PostionX < 870)
			{
				if (PostionY > 360 && PostionY < 460)
				{
					MidAnimation();
					State = 2;
				}
			}
		}
		if ((PostionX > 770 && PostionX < 870) && (PostionY > 360 && PostionY < 460))
		{
			sleeptime = 30;
		}
		else
		{
			sleeptime = 120;
		}
		FlushMouseMsgBuffer();
	}
	Sleep(sleeptime);
	return 0;
}

//ִ��״̬2����ʼ����ĺ���
int whenState_2()
{
	static bool a = false;
	static int sleeptime = 120;
	buttonRo(420, false);
	while (MouseHit())
	{
		m = GetMouseMsg();
		int PostionX = m.x;
		int PostionY = m.y;
		//��Ʊ
		if ((PostionX > 900 && PostionX < 1100) && (PostionY > 150 && PostionY < 250))
		{
			button_anmi_2(1, false);
			if (m.uMsg == WM_LBUTTONUP)
			{
				State = 3;
				Three_state = 0;
				MidAnimation_b(3);
			}
			a = true;
		}
		//��ͼ��ѯ
		else if ((PostionX > 900 && PostionX < 1100) && (PostionY > 300 && PostionY < 400))
		{
			button_anmi_2(2, false);
			if (m.uMsg == WM_LBUTTONUP)
			{
				swith = false;
				MidAnimation_b(4);
				State = 4;
			}
			a = true;
		}
		//�˳�ϵͳ
		else if ((PostionX > 900 && PostionX < 1100) && (PostionY > 450 && PostionY < 550))
		{
			button_anmi_2(3, false);
			if (m.uMsg == WM_LBUTTONUP)
			{
				State = 0;
			}
			a = true;
		}
		//ʹ��˵��
		else if ((PostionX > 900 && PostionX < 1100) && (PostionY > 600 && PostionY < 750))
		{
			button_anmi_2(4, false);
			if (m.uMsg == WM_LBUTTONUP)
			{
				MidAnimation_b(5);
				State = 5;
			}
			a = true;
		}
		else
		{
			if (a == true)
			{
				button_anmi_2(0, true);
				whenstate_2();
				a = false;
			}
			else if (a == false)
			{

			}
			if ((PostionX > 770 - 21 * 20 && PostionX < 870 - 21 * 20) && (PostionY > 360 && PostionY < 460))
			{
				sleeptime = 30;
				if (m.uMsg == WM_LBUTTONUP)
				{
					MidAnimation_b(0);
					State = 1;
				}
			}
			else
			{
				sleeptime = 120;
			}
		}
		FlushMouseMsgBuffer();
	}
	Sleep(sleeptime);
	return 0;
}

//ִ��״̬3��ʹ��˵���ĺ���
int whenState_3()
{
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 26;
	settextstyle(&f);
	static int PostionX = 0;
	static int PostionY = 0;
	static int fin_fee=0;
	static int ticket_num = 1;
	static TCHAR input_num[] = _T("1");
	static int qiY = 174;
	static int zhongY = 276;
	static bool choice_1 = false;
	static bool choice_2 = false;
	static bool queding = false;
	static bool fir_sw = false;
	static bool sec_sw = false;
	static bool Tuijian = false;
	static bool Toubi = false;
	static bool Quxiao = false;
	static TCHAR firstation[100];
	static TCHAR secstation[100];
	static bool tui_sw = false;
	static TCHAR No1_dis[20];
	static TCHAR No2_dis[20];
	static TCHAR No3_dis[20];
	static TCHAR No1_fee[20];
	static TCHAR No2_fee[20];
	static TCHAR No3_fee[20];
	TCHAR sta_number[] = _T("վ��ţ�");
	TCHAR is_mid[] = _T("�Ƿ���תվ��");
	TCHAR con_num[] = _T("��·�ţ�");
	TCHAR yes[] = _T("��");
	TCHAR no[] = _T("��");
	TCHAR fir_sta_number[10];
	TCHAR fir_con_number[20];
	TCHAR sec_sta_number[10];
	TCHAR sec_con_number[20];
	TCHAR per_pay[20];
	TCHAR all_pay[20];
	//����ʼĩվ
	if (Three_state == 0)
	{
		f.lfHeight = 48;
		settextstyle(&f);
		putimage(21 * 20 - 21 * 20, 0, &background);
		outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
		putimage(84, qiY, &qi_z, SRCAND);
		putimage(84, qiY, &qi, SRCPAINT);
		putimage(90, zhongY, &zhong_z, SRCAND);
		putimage(90, zhongY, &zhong, SRCPAINT);
		putimage(90 + 20, 180, &input_z, SRCAND);
		putimage(90 + 20, 180, &input, SRCPAINT);
		putimage(90 + 20, 260, &input_z, SRCAND);
		putimage(90 + 20, 260, &input, SRCPAINT);
		if (queding == false)
		{
			f.lfHeight = 26;
			settextstyle(&f);
			putimage(110 + 30, 380, &c_button);
			outtextxy(170, 385, _T("ȷ��"));
		}
		else if (queding == true)
		{
			f.lfHeight = 30;
			settextstyle(&f);
			putimage(110 + 30 - 15, 380 - 4.5, &c_button_2);
			outtextxy(165, 382, _T("ȷ��"));
		}
		f.lfHeight = 26;
		settextstyle(&f);
		if (fir_sw == false)
		{
			outtextxy(140 + 20, 217, _T("������ʼվ"));
		}
		else if (fir_sw == true)
		{
			outtextxy(140 + 20, 217, firstation);
		}
		if (sec_sw == false)
		{
			outtextxy(140 + 20, 297, _T("�����յ�վ"));
		}
		else if (sec_sw == true)
		{
			outtextxy(140 + 20, 297, secstation);
		}
	}
	//��ʾվ����Ϣ
	else if (Three_state == 1)
	{
		wsprintf(fir_sta_number, L"%d", Fir_station->station_number);
		wsprintf(sec_sta_number, L"%d", Las_station->station_number);
		int i = 0;
		int j = 0;
		if (Fir_station->is_mid_station == true)
		{
			do {
				if (i == 0)
				{
					wsprintf(fir_con_number, L"%d",Fir_station->con_amount[i]);
				}
				else
				{
					wsprintf(fir_con_number, L"%s%d", fir_con_number, Fir_station->con_amount[i]);
				}
				i++;
				if (Fir_station->con_amount[i] != 0)
				{
					wsprintf(fir_con_number, L"%s��", fir_con_number);
				}
			} while (Fir_station->con_amount[i] != 0);
		}
		else if (Fir_station->is_mid_station == false)
		{
			wsprintf(fir_con_number, L"%d", Fir_station->route_number);
		}
		if (Las_station->is_mid_station == true)
		{
			do {
				if (j == 0)
				{
					wsprintf(sec_con_number, L"%d",  Las_station->con_amount[j]);
				}
				else
				{
					wsprintf(sec_con_number, L"%s%d", sec_con_number, Las_station->con_amount[j]);
				}
				j++;
				if (Las_station->con_amount[j] != 0)
				{
					wsprintf(sec_con_number, L"%s��",sec_con_number);
				}
			} while (Las_station->con_amount[j] != 0);
		}
		else if (Las_station->is_mid_station == false)
		{
			wsprintf(sec_con_number, L"%d", Las_station->route_number);
		}
		f.lfHeight = 48;
		settextstyle(&f);
		putimage(21 * 20 - 21 * 20, 0, &background);
		outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
		putimage(84 - 4 * 10, qiY, &qi_z, SRCAND);
		putimage(84 - 4 * 10, qiY, &qi, SRCPAINT);
		putimage(90 - 4 * 10, zhongY + 17 * 10, &zhong_z, SRCAND);
		putimage(90 - 4 * 10, zhongY + 17 * 10, &zhong, SRCPAINT);
		putimage(90 - 4 * 10 + 20, 180, &input_z, SRCAND);
		putimage(90 - 4 * 10 + 20, 180, &input, SRCPAINT);
		putimage(90 - 4 * 10 + 20, 260 + 17 * 10, &input_z, SRCAND);
		putimage(90 - 4 * 10 + 20, 260 + 17 * 10, &input, SRCPAINT);
		putimage(730.9, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
		putimage(730.9, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
		f.lfHeight = 26;
		settextstyle(&f);
		outtextxy(140 + 20 - 4 * 10, 217, firstation);
		outtextxy(140 + 20 - 4 * 10, 297 + 17 * 10, secstation);
		f.lfHeight = 26;
		settextstyle(&f);
		outtextxy(320, 217, sta_number);
		outtextxy(470, 217, fir_sta_number);
		outtextxy(320, 287, is_mid);
		if (Fir_station->is_mid_station == true)
		{
			outtextxy(470, 287, yes);
		}
		else if (Fir_station->is_mid_station == false)
		{
			outtextxy(470, 287, no);
		}
		outtextxy(320, 357, con_num);
		outtextxy(470, 357, fir_con_number);
		outtextxy(320, 297 + 17 * 10, sta_number);
		outtextxy(470, 297 + 17 * 10, sec_sta_number);
		outtextxy(320, 297 + 17 * 10+70, is_mid);
		if (Las_station->is_mid_station == true)
		{
			outtextxy(470, 297 + 17 * 10 + 70, yes);
		}
		else if (Las_station->is_mid_station == false)
		{
			outtextxy(470, 297 + 17 * 10 + 70, no);
		}
		outtextxy(320, 297 + 17 * 10 + 140, con_num);
		outtextxy(470, 297 + 17 * 10 + 140, sec_con_number);
		if (Tuijian == false)
		{
			putimage(120 + 100, 717 - 60, &c_button);
			f.lfHeight = 24;
			settextstyle(&f);
			outtextxy(230, 717 - 55, _T("�Ƽ�·��"));
		}
		else if (Tuijian == true)
		{
			putimage(120 + 100-15, 717 - 60-4.5, &c_button_2);
			f.lfHeight = 30;
			settextstyle(&f);
			outtextxy(220, 717 - 60, _T("�Ƽ�·��"));
		}
	}
	//��ʾ·���Ƽ�
	else if (Three_state == 2)
	{
		if (tui_sw == true)
		{
			if (Get_state == 1)
			{
				int fee = ticket(One_dis);
				TCHAR Fee[20];
				wsprintf(No1_dis, L"%d����", One_dis);
				wsprintf(Fee, L"%dԪ/��", fee);
				for (int i = 0; i <= 20; i++)
				{
					f.lfHeight = 48;
					settextstyle(&f);
					putimage(21 * 20 - 21 * 20, 0, &background);
					outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
					f.lfHeight = 20;
					settextstyle(&f);
					putimage(-40, 40+800-40*i, &Word_z, SRCAND);
					putimage(-40, 40+800-40*i, &Word, SRCPAINT);
					TCHAR* pwszUnicode = CharToWchar_t(No_1str);
					RECT r = { 100,252 + 800 - 40 * i,1000 + 100,479 + 800 - 40 * i };
					drawtext(pwszUnicode, &r, DT_LEFT);
					outtextxy(100, 380 + 800 - 40 * i, _T("·�̣�"));
					outtextxy(150, 380 + 800 - 40 * i, No1_dis);
					outtextxy(100, 410 + 800 - 40 * i, _T("Ʊ�ۣ�"));
					outtextxy(150, 410 + 800 - 40 * i, Fee);
					putimage(300, 385 + 800 - 40 * i, &c_button);
					outtextxy(300 + 9, 385 + 8 + 800 - 40 * i, _T("ѡ���·��"));
					FlushBatchDraw();
					Sleep(8);
				}
			}
			else if (Get_state == 2)
			{
				int fee_1 = ticket(Two_dis);
				TCHAR Fee_1[20];
				int fee_2 = ticket(Three_dis);
				TCHAR Fee_2[20];
				wsprintf(No2_dis, L"%d����", Two_dis);
				wsprintf(No3_dis, L"%d����", Three_dis);
				wsprintf(Fee_1, L"%dԪ/��", fee_1);
				wsprintf(Fee_2, L"%dԪ/��", fee_2);
				for (int i = 0; i <= 20; i++)
				{
					f.lfHeight = 48;
					settextstyle(&f);
					putimage(21 * 20 - 21 * 20, 0, &background);
					outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
					f.lfHeight = 20;
					settextstyle(&f);
					putimage(-40, 40 + 800 - 40 * i, &Word_z, SRCAND);
					putimage(-40, 40 + 800 - 40 * i, &Word, SRCPAINT);
					putimage(-40, 25 + 300 + 800 - 40 * i, &Word_z, SRCAND);
					putimage(-40, 25 + 300 + 800 - 40 * i, &Word, SRCPAINT);
					TCHAR* pwszUnicode_1 = CharToWchar_t(No_2str_All);
					RECT r = { 100,240 + 800 - 40 * i,1000 + 100,479 + 800 - 40 * i };
					drawtext(pwszUnicode_1, &r, DT_LEFT);
					TCHAR* pwszUnicode_2 = CharToWchar_t(No_3str_All);
					RECT s = { 100,0 + 500 + 8 + 800 - 40 * i,1000 + 300,479 + 300 + 800 - 40 * i };
					drawtext(pwszUnicode_2, &s, DT_LEFT);
					outtextxy(100, 380 + 800 - 40 * i, _T("·�̣�"));
					outtextxy(150, 380 + 800 - 40 * i, No2_dis);
					outtextxy(100, 410 + 800 - 40 * i, _T("Ʊ�ۣ�"));
					outtextxy(150, 410 + 800 - 40 * i, Fee_1);
					outtextxy(100, 380 + 285 + 800 - 40 * i, _T("·�̣�"));
					outtextxy(150, 380 + 285 + 800 - 40 * i, No3_dis);
					outtextxy(100, 410 + 285 + 800 - 40 * i, _T("Ʊ�ۣ�"));
					outtextxy(150, 410 + 285 + 800 - 40 * i, Fee_2);
					putimage(300, 385 + 800 - 40 * i, &c_button);
					putimage(300, 385 + 285 + 800 - 40 * i, &c_button);
					outtextxy(300 + 9, 385 + 8 + 800 - 40 * i, _T("ѡ���·��"));
					outtextxy(300 + 9, 385 + 285 + 8 + 800 - 40 * i, _T("ѡ���·��"));
					FlushBatchDraw();
					Sleep(8);
				}
			}
			tui_sw = false;
		}
		else if(tui_sw==false)
		{ 
			f.lfHeight = 48;
			settextstyle(&f);
			putimage(21 * 20 - 21 * 20, 0, &background);
			outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
			f.lfHeight = 20;
			settextstyle(&f);
			if (Get_state == 1)
			{
				int fee = ticket(One_dis);
				TCHAR Fee[20];
				wsprintf(No1_dis, L"%d����", One_dis);
				wsprintf(Fee, L"%dԪ/��", fee);
				putimage(-40, 40, &Word_z, SRCAND);
				putimage(-40, 40, &Word, SRCPAINT);
				TCHAR* pwszUnicode = CharToWchar_t(No_1str);
				RECT r = { 100,252,1000 + 100,479 };
				drawtext(pwszUnicode, &r, DT_LEFT);
				outtextxy(100, 380, _T("·�̣�"));
				outtextxy(150, 380, No1_dis);
				outtextxy(100, 410, _T("Ʊ�ۣ�"));
				outtextxy(150, 410, Fee);
				if (choice_1 == false)
				{
					f.lfHeight = 20;
					settextstyle(&f);
					putimage(300, 385, &c_button);
					outtextxy(300 + 9, 385 + 8, _T("ѡ���·��"));
				}
				else if (choice_1 == true)
				{
					f.lfHeight = 25;
					settextstyle(&f);
					putimage(300-15, 385-4.5, &c_button_2);
					outtextxy(300 -5, 385 + 6, _T("ѡ���·��"));
				}
			}
			else if (Get_state == 2)
			{
				int fee_1 = ticket(Two_dis);
				TCHAR Fee_1[20];
				int fee_2 = ticket(Three_dis);
				TCHAR Fee_2[20];
				wsprintf(No2_dis, L"%d����", Two_dis);
				wsprintf(No3_dis, L"%d����", Three_dis);
				wsprintf(Fee_1, L"%dԪ/��", fee_1);
				wsprintf(Fee_2, L"%dԪ/��", fee_2);
				putimage(-40, 40, &Word_z, SRCAND);
				putimage(-40, 40, &Word, SRCPAINT);
				putimage(-40, 25 + 300, &Word_z, SRCAND);
				putimage(-40, 25 + 300, &Word, SRCPAINT);
				TCHAR* pwszUnicode_1 = CharToWchar_t(No_2str_All);
				RECT r = { 100,240,1000 + 100,479 };
				drawtext(pwszUnicode_1, &r, DT_LEFT);
				TCHAR* pwszUnicode_2 = CharToWchar_t(No_3str_All);
				RECT s = { 100,0 + 500 + 8,1000 + 300,479 + 300 };
				drawtext(pwszUnicode_2, &s, DT_LEFT);
				outtextxy(100, 380, _T("·�̣�"));
				outtextxy(150, 380, No2_dis);
				outtextxy(100, 410, _T("Ʊ�ۣ�"));
				outtextxy(150, 410, Fee_1);
				outtextxy(100, 380+285, _T("·�̣�"));
				outtextxy(150, 380+285, No3_dis);
				outtextxy(100, 410+285, _T("Ʊ�ۣ�"));
				outtextxy(150, 410+285, Fee_2);
				putimage(300, 385+285, &c_button);
				outtextxy(300+9, 385+285+8, _T("ѡ���·��"));
				if (choice_1 == false)
				{
					f.lfHeight = 20;
					settextstyle(&f);
					putimage(300, 385, &c_button);
					outtextxy(300 + 9, 385 + 8, _T("ѡ���·��"));
				}
				else if (choice_1 == true)
				{
					f.lfHeight = 25;
					settextstyle(&f);
					putimage(300 - 15, 385 - 4.5, &c_button_2);
					outtextxy(300 - 5, 385 + 6, _T("ѡ���·��"));
				}
				if (choice_2 == false)
				{
					f.lfHeight = 20;
					settextstyle(&f);
					putimage(300, 385 + 285, &c_button);
					outtextxy(300 + 9, 385 + 285 + 8, _T("ѡ���·��"));
				}
				else if (choice_2 == true)
				{
					f.lfHeight = 25;
					settextstyle(&f);
					putimage(300 - 15, 385 +285- 4.5, &c_button_2);
					outtextxy(300 - 5, 385 + 285+6, _T("ѡ���·��"));
				}
			}
			ticket_num = 1;
			wsprintf(input_num, L"1");
			FlushBatchDraw();
		}
	}
	//ѡ��Ʊ��
	else if (Three_state == 3)
	{	
		f.lfHeight = 48;
		settextstyle(&f);
		putimage(21 * 20 - 21 * 20, 0, &background);
		outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
		f.lfHeight = 36;
		settextstyle(&f);
		outtextxy(150,250, _T("����Ʊ����"));
		outtextxy(150, 320, _T("����Ʊ�ۣ�"));
		outtextxy(150, 390, _T("�ܼ�Ʊ�ۣ�"));
		wsprintf(per_pay,L"%dԪ/��", fin_fee);
		wsprintf(all_pay, L"%dԪ", fin_fee*ticket_num);
		putimage(320, 220, &input_z, SRCAND);
		putimage(320, 220, &input, SRCPAINT);
		outtextxy(360, 320, per_pay);
		outtextxy(360, 390, all_pay);
		outtextxy(360+50, 250, input_num);
		if (Toubi == false)
		{
			f.lfHeight = 24;
			settextstyle(&f);
			putimage(150 + 30, 460, &c_button);
			outtextxy(180+12, 465, _T("ȷ��Ͷ��"));
		}
		else if (Toubi == true)
		{
			f.lfHeight = 30;
			settextstyle(&f);			
			putimage(150 + 30-15, 460-4.5, &c_button_2);
			outtextxy(180 , 460, _T("ȷ��Ͷ��"));
		}
		if (Quxiao == false)
		{
			f.lfHeight = 24;
			settextstyle(&f);
			putimage(320 + 30, 460, &c_button);
			outtextxy(350+35, 465, _T("ȡ��"));
		}
		else if (Quxiao == true)
		{
			f.lfHeight = 30;
			settextstyle(&f);
			putimage(320 + 30-15, 460-4.5, &c_button_2);
			outtextxy(350 + 25, 460, _T("ȡ��"));
		}
	}	
	//Ͷ��
	else if (Three_state == 4)
	{
		f.lfHeight = 48;
		settextstyle(&f);
		putimage(21 * 20 - 21 * 20, 0, &background);
		outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
		f.lfHeight = 36;
		settextstyle(&f);
		putimage(200-50, 300-50, &word_2_z, SRCAND);
		putimage(200-50, 300-50, &word_2, SRCPAINT);
		outtextxy(295-50, 380-50, _T("����ɹ���"));
		if (queding == false)
		{
			f.lfHeight = 26;
			settextstyle(&f);
			putimage(110 + 30 + 115, 380 + 120, &c_button);
			outtextxy(170+115, 385+120, _T("ȷ��"));
		}
		else if (queding == true)
		{
			f.lfHeight = 30;
			settextstyle(&f);
			putimage(110 + 30 - 15+115, 380 - 4.5+120, &c_button_2);
			outtextxy(165+115, 382+120, _T("ȷ��"));
		}
	}
	static int sleeptime = 120;
	buttonRo(0, false);
	while (MouseHit())
	{
		m = GetMouseMsg();
		PostionX = m.x;
		PostionY = m.y;
		if (m.uMsg == WM_LBUTTONUP)
		{
			if (PostionX > 770 && PostionX < 870)
			{
				if (PostionY > 360 && PostionY < 460)
				{
					MidAnimation();
					State = 2;
				}
			}
		}
		if (Three_state == 0)
		{
			if ((PostionX > 80 && PostionX < 80 + 250) && (PostionY > 200 && PostionY < 180 + 75))
			{
				queding = false;
				qiY = 164;
				zhongY = 276;
				if (m.uMsg == WM_LBUTTONUP)
				{
					f.lfHeight = 26;
					settextstyle(&f);
					InputBox(firstation, 10, L"���վ");
					fir_sw = true;
				}
			}
			else if ((PostionX > 80 && PostionX < 80 + 250) && (PostionY > 200 + 80 && PostionY < 180 + 75 + 80))
			{
				queding = false;
				zhongY = 266;
				qiY = 174;
				if (m.uMsg == WM_LBUTTONUP)
				{
					f.lfHeight = 26;
					settextstyle(&f);
					InputBox(secstation, 10, L"�յ�վ");
					sec_sw = true;
				}
			}
			else if ((PostionX > 140 && PostionX < 140 + 120) && (PostionY > 380 && PostionY < 380 + 36))
			{
				queding = true;
				qiY = 174;
				zhongY = 276;
				if (m.uMsg == WM_LBUTTONUP)
				{

					if (fir_sw == true && sec_sw == true)
					{
						queding = false;
						char* Firstation = Wchar_tToChar(firstation);
						char* Secstation = Wchar_tToChar(secstation);
						secondmain(Firstation, Secstation);
						fir_sw = false;
						sec_sw = false;
						if (Get_state == 1 || Get_state == 2)
						{
							Three_state = 1;
							wsprintf(fir_sta_number, L"%d", Fir_station->station_number);
							wsprintf(sec_sta_number, L"%d", Las_station->station_number);
							int i = 0;
							int j = 0;
							if (Fir_station->is_mid_station == true)
							{
								do {
									if (i == 0)
									{
										wsprintf(fir_con_number, L"%d", Fir_station->con_amount[i]);
									}
									else
									{
										wsprintf(fir_con_number, L"%s%d", fir_con_number, Fir_station->con_amount[i]);
									}
									i++;
									if (Fir_station->con_amount[i] != 0)
									{
										wsprintf(fir_con_number, L"%s��", fir_con_number);
									}
								} while (Fir_station->con_amount[i] != 0);
							}
							else if (Fir_station->is_mid_station == false)
							{
								wsprintf(fir_con_number, L"%d",Fir_station->route_number);
							}
							if (Las_station->is_mid_station == true)
							{
								do {
									if (j == 0)
									{
										wsprintf(sec_con_number, L"%d", Las_station->con_amount[j]);
									}
									else
									{
										wsprintf(sec_con_number, L"%s%d", sec_con_number, Las_station->con_amount[j]);
									}
									j++;
									if (Las_station->con_amount[j] != 0)
									{
										wsprintf(sec_con_number, L"%s��", sec_con_number);
									}
								} while (Las_station->con_amount[j] != 0);
							}
							else if (Las_station->is_mid_station == false)
							{
								wsprintf(sec_con_number, L"%d", Las_station->route_number);
							}
							for (int i = 0; i <= 10; i++)
							{
								f.lfHeight = 48;
								settextstyle(&f);
								putimage(21 * 20 - 21 * 20, 0, &background);
								outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
								putimage(84 - 4 * i, qiY, &qi_z, SRCAND);
								putimage(84 - 4 * i, qiY, &qi, SRCPAINT);
								putimage(90 - 4 * i, zhongY + 17 * i, &zhong_z, SRCAND);
								putimage(90 - 4 * i, zhongY + 17 * i, &zhong, SRCPAINT);
								putimage(90 - 4 * i + 20, 180, &input_z, SRCAND);
								putimage(90 - 4 * i + 20, 180, &input, SRCPAINT);
								putimage(90 - 4 * i + 20, 260 + 17 * i, &input_z, SRCAND);
								putimage(90 - 4 * i + 20, 260 + 17 * i, &input, SRCPAINT);
								putimage(730.9, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
								putimage(730.9, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
								f.lfHeight = 26;
								settextstyle(&f);
								outtextxy(140 + 20 - 4 * i, 217, firstation);
								outtextxy(140 + 20 - 4 * i, 297 + 17 * i, secstation);
								f.lfHeight = 26;
								settextstyle(&f);
								outtextxy(320, 217 + 500 - 50 * i, sta_number);
								outtextxy(470, 217 + 500 - 50 * i, fir_sta_number);
								outtextxy(320, 287 + 500 - 50 * i, is_mid);
								if (Fir_station->is_mid_station == true)
								{
									outtextxy(470, 287 + 500 - 50 * i, yes);
								}
								else if (Fir_station->is_mid_station == false)
								{
									outtextxy(470, 287 + 500 - 50 * i, no);
								}
								outtextxy(320, 357 + 500 - 50 * i, con_num);
								outtextxy(470, 357 + 500 - 50 * i, fir_con_number);
								outtextxy(320, 297 + 17 * 10 + 500 - 50 * i, sta_number);
								outtextxy(470, 297 + 17 * 10 + 500 - 50 * i, sec_sta_number);
								outtextxy(320, 297 + 17 * 10 + 70 + 500 - 50 * i, is_mid);
								if (Las_station->is_mid_station == true)
								{
									outtextxy(470, 297 + 17 * 10 + 70 + 500 - 50 * i, yes);
								}
								else if (Las_station->is_mid_station == false)
								{
									outtextxy(470, 297 + 17 * 10 + 70 + 500 - 50 * i, no);
								}
								outtextxy(320, 297 + 17 * 10 + 140 + 500 - 50 * i, con_num);
								outtextxy(470, 297 + 17 * 10 + 140 + 500 - 50 * i, sec_con_number);
								putimage(120 + 100, 717 - 60+300-30*i, &c_button);
								f.lfHeight = 24;
								settextstyle(&f);
								outtextxy(230, 717 - 55+300-30*i, _T("�Ƽ�·��"));
								Sleep(10);
								FlushBatchDraw();
							}
						}
						else if (Get_state == 0)
						{
							f.lfHeight = 36;
							settextstyle(&f);
							putimage(400, 300, &word_2_z, SRCAND);
							putimage(400, 300, &word_2, SRCPAINT);
							settextcolor(RED);
							outtextxy(460, 380, _T("վ���������"));
							f.lfHeight = 26;
							settextcolor(WHITE);
							settextstyle(&f);
							Sleep(2000);
						}
					}
				}
			}
			else
			{
				queding = false;
				qiY = 174;
				zhongY = 276;
			}
		}
		else if (Three_state == 1)
		{
			if ((PostionX > 220 && PostionX < 220+120) && (PostionY > 717-60 && PostionY < 717-60+36))
			{
				Tuijian = true;
				if (m.uMsg == WM_LBUTTONUP)
				{
					Three_state = 2;
					tui_sw = true;
					Tuijian = false;
				}
			}
			else
			{
				Tuijian = false;
			}
		}
		else if (Three_state == 2)
		{
			if ((PostionX > 300 && PostionX < 300+120) && (PostionY > 385 && PostionY < 385+36))
			{
				choice_1 = true;
				choice_2 = false;
				if (m.uMsg == WM_LBUTTONUP)
				{
					if (Get_state == 1)
					{
						fin_fee = ticket(One_dis);
					}
					else if (Get_state == 2)
					{
						fin_fee = ticket(Two_dis);
					}
					Three_state = 3;
					wsprintf(per_pay, L"%dԪ/��", fin_fee);
					wsprintf(all_pay, L"%dԪ", fin_fee* ticket_num);
					coin_mid(per_pay, all_pay, ticket_num, fin_fee,true);
				}
			}
			else if ((PostionX > 300 && PostionX < 300+120) && (PostionY > 385+285 && PostionY < 385+285+36))
			{
				if(Get_state==2)
				{
					choice_1 = false;
					choice_2 = true;
					if (m.uMsg == WM_LBUTTONUP)
					{
						fin_fee = ticket(Three_dis);
						Three_state = 3; 
						wsprintf(per_pay, L"%dԪ/��", fin_fee);
						wsprintf(all_pay, L"%dԪ", fin_fee* ticket_num);
						coin_mid(per_pay, all_pay, ticket_num, fin_fee,true);
					}
				}
			}
			else
			{
				choice_1 = false;
				choice_2 = false;
			}
		}
		else if (Three_state == 3)
		{
			if ((PostionX >180 && PostionX <180+120) && (PostionY >460 && PostionY < 460+36))
			{
				Toubi = true;
				Quxiao = false;
				if (m.uMsg == WM_LBUTTONUP)
				{
					Three_state = 4;
					coin_mid(per_pay, all_pay, ticket_num, fin_fee, false);
					for (int i = 0; i <= 10; i++)
					{
						f.lfHeight = 48;
						settextstyle(&f);
						putimage(21 * 20 - 21 * 20, 0, &background);
						outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
						f.lfHeight = 36;
						settextstyle(&f);
						putimage(200 - 50, 300 - 50+600-60*i, &word_2_z, SRCAND);
						putimage(200 - 50, 300 - 50 + 600 - 60 * i, &word_2, SRCPAINT);
						outtextxy(295 - 50, 380 - 50 + 600 - 60 * i, _T("����ɹ���"));
						f.lfHeight = 26;
						settextstyle(&f);
						putimage(110 + 30 + 115, 380 + 120 + 600 - 60 * i, &c_button);
						outtextxy(170 + 115, 385 + 120 + 600 - 60 * i, _T("ȷ��"));
						Sleep(8);
						FlushBatchDraw();
					}
				}
			}
			else if ((PostionX > 350 && PostionX < 350 + 120) && (PostionY > 460 && PostionY < 460 + 36))
			{
				Toubi = false;
				Quxiao = true;
				if (m.uMsg == WM_LBUTTONUP)
				{
					Three_state = 2;
					tui_sw = true;
					coin_mid(per_pay, all_pay, ticket_num, fin_fee, false);
				}
			}
			else if ((PostionX > 350 && PostionX < 350 + 180) && (PostionY > 240 && PostionY < 250 + 40))
			{
				if (m.uMsg == WM_LBUTTONUP)
				{
					InputBox(input_num, 10, L"��Ʊ��");
					ticket_num = _wtoi(input_num);
				}
			}
			else
			{
				Toubi = false;
				Quxiao = false;
			}
		}
		else if (Three_state == 4)
		{
			if ((PostionX > 110 + 30 + 115 && PostionX < 110 + 30 + 115+120) && (PostionY > 380 + 120 && PostionY < 380 + 120+36))
			{
				queding = true;
				if (m.uMsg == WM_LBUTTONUP)
				{
					for (int i = 0; i <= 10; i++)
					{
						f.lfHeight = 48;
						settextstyle(&f);
						putimage(21 * 20 - 21 * 20, 0, &background);
						outtextxy(100, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
						f.lfHeight = 36;
						settextstyle(&f);
						putimage(200 - 50, 300 - 50 + 60 * i, &word_2_z, SRCAND);
						putimage(200 - 50, 300 - 50 + 60 * i, &word_2, SRCPAINT);
						outtextxy(295 - 50, 380 - 50 + 60 * i, _T("����ɹ���"));
						f.lfHeight = 26;
						settextstyle(&f);
						putimage(110 + 30 + 115, 380 + 120 + 60 * i, &c_button);
						outtextxy(170 + 115, 385 + 120 +60 * i, _T("ȷ��"));
						Sleep(8);
						FlushBatchDraw();
					}
					MidAnimation();
					State = 2;
				}
			}
			else {
				queding = false;
			}
		 }
		if ((PostionX > 770 && PostionX < 870) && (PostionY > 360 && PostionY < 460))
		{
			sleeptime = 30;
		}
		else
		{
			sleeptime = 120;
		}
		FlushMouseMsgBuffer();
	}
	Sleep(sleeptime);
	return 0;
}

//ִ��״̬4��ʹ��˵���ĺ���
int whenState_4()
{
	static int four_state = 0;
	static int sleeptime = 120;
	static int pos = 0;
	static bool a = false;
	BeginBatchDraw();
	if (swith == false)
	{
		four_state = 0;
		swith = true;
	}
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	settextstyle(&f);
	if (four_state == 0)
	{
		//showstate4();
		buttonRo(0, false);
		while (MouseHit())
		{
			m = GetMouseMsg();
			int PostionX = m.x;
			int PostionY = m.y;
			if (four_state == 0)
			{
				if ((PostionX > CBUTTON_X && PostionX < CBUTTON_X + 120) &&
					(PostionY > CBUTTON_Y + 625 / 400 && PostionY < CBUTTON_Y + 625 / 400 + 36))
				{
					if (pos != 1)
					{
						showstate4();
						pos = 1;
					}
					f.lfHeight = 30;
					settextstyle(&f);
					a = true;
					putimage(CBUTTON_X - 15, CBUTTON_Y + 625 / 400 - 4.5, &c_button_2);
					outtextxy(CBUTTON_X + 20, CBUTTON_Y + 625 / 400 + 3, _T("1����"));
					if (m.uMsg == WM_LBUTTONUP)
					{
						four_state = 1;
						for (int i = 0; i <= 20; i++)
						{
							putimage(21 * 20 - 21 * 20 + 12.4 * i, 0, &background);
							f.lfHeight = 48;
							settextstyle(&f);
							outtextxy(100, SHUOMING_Y, _T("·�����顪��1����"));
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
							putimage(-1000 + 50 * i, 197, &line1);
							Sleep(8);
							FlushBatchDraw();
						}
					}
				}
				else if ((PostionX > CBUTTON_X && PostionX < CBUTTON_X + 120) &&
					(PostionY > CBUTTON_Y + 50 + 625 / 400 && PostionY < CBUTTON_Y + +50 + 625 / 400 + 36))
				{
					if (pos != 3)
					{
						showstate4();
						pos = 3;
					}
					f.lfHeight = 30;
					settextstyle(&f);
					a = true;
					putimage(CBUTTON_X - 15, CBUTTON_Y + 50 + 625 / 400 - 4.5, &c_button_2);
					outtextxy(CBUTTON_X + 20, CBUTTON_Y + 50 + 625 / 400 + 3, _T("3����"));
					if (m.uMsg == WM_LBUTTONUP)
					{
						four_state = 3;
						for (int i = 0; i <= 20; i++)
						{
							putimage(21 * 20 - 21 * 20 + 12.4 * i, 0, &background);
							f.lfHeight = 48;
							settextstyle(&f);
							outtextxy(100, SHUOMING_Y, _T("·�����顪��3����"));
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
							putimage(-1000 + 50 * i, 197 - 39, &line3);
							Sleep(8);
							FlushBatchDraw();
						}
					}
				}
				else if ((PostionX > CBUTTON_X && PostionX < CBUTTON_X + 120) &&
					(PostionY > CBUTTON_Y + 100 + 625 / 400 && PostionY < CBUTTON_Y + 100 + 625 / 400 + 36))
				{
					if (pos != 5)
					{
						showstate4();
						pos = 5;
					}
					f.lfHeight = 30;
					settextstyle(&f);
					a = true;
					putimage(CBUTTON_X - 15, CBUTTON_Y + 100 + 625 / 400 - 4.5, &c_button_2);
					outtextxy(CBUTTON_X + 20, CBUTTON_Y + 100 + 625 / 400 + 3, _T("5����"));
					if (m.uMsg == WM_LBUTTONUP)
					{
						four_state = 5;
						for (int i = 0; i <= 20; i++)
						{
							putimage(21 * 20 - 21 * 20 + 12.4 * i, 0, &background);
							f.lfHeight = 48;
							settextstyle(&f);
							outtextxy(100, SHUOMING_Y, _T("·�����顪��5����"));
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
							putimage(-1000 + 50 * i, 197, &line5);
							Sleep(8);
							FlushBatchDraw();
						}
					}
				}
				else if ((PostionX > CBUTTON_X && PostionX < CBUTTON_X + 120) &&
					(PostionY > CBUTTON_Y + 150 + 625 / 400 && PostionY < CBUTTON_Y + 150 + 625 / 400 + 36))
				{
					if (pos != 9)
					{
						showstate4();
						pos = 9;
					}
					f.lfHeight = 30;
					settextstyle(&f);
					a = true;
					putimage(CBUTTON_X - 15, CBUTTON_Y + 150 + 625 / 400 - 4.5, &c_button_2);
					outtextxy(CBUTTON_X + 20, CBUTTON_Y + 150 + 625 / 400 + 3, _T("9����"));
					if (m.uMsg == WM_LBUTTONUP)
					{
						four_state = 9;
						for (int i = 0; i <= 20; i++)
						{
							putimage(21 * 20 - 21 * 20 + 12.4 * i, 0, &background);
							f.lfHeight = 48;
							settextstyle(&f);
							outtextxy(100, SHUOMING_Y, _T("·�����顪��9����"));
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
							putimage(-1000 + 50 * i, 197, &line9);
							Sleep(8);
							FlushBatchDraw();
						}
					}
				}
				else if ((PostionX > CBUTTON_X + 180 && PostionX < CBUTTON_X + 120 + 180) &&
					(PostionY > CBUTTON_Y + 625 / 400 && PostionY < CBUTTON_Y + 625 / 400 + 36))
				{
					if (pos != 2)
					{
						showstate4();
						pos = 2;
					}
					f.lfHeight = 30;
					settextstyle(&f);
					a = true;
					putimage(CBUTTON_X - 15 + 180, CBUTTON_Y + 625 / 400 - 4.5, &c_button_2);
					outtextxy(CBUTTON_X + 20 + 180, CBUTTON_Y + 625 / 400 + 3, _T("2����"));
					if (m.uMsg == WM_LBUTTONUP)
					{
						four_state = 2;
						for (int i = 0; i <= 20; i++)
						{
							putimage(21 * 20 - 21 * 20 + 12.4 * i, 0, &background);
							f.lfHeight = 48;
							settextstyle(&f);
							outtextxy(100, SHUOMING_Y, _T("·�����顪��2����"));
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
							putimage(-1000 + 50 * i, 197, &line2);
							Sleep(8);
							FlushBatchDraw();
						}
					}
				}
				else if ((PostionX > CBUTTON_X + 180 && PostionX < CBUTTON_X + 120 + 180) &&
					(PostionY > CBUTTON_Y + 50 + 625 / 400 && PostionY < CBUTTON_Y + +50 + 625 / 400 + 36))
				{
					if (pos != 4)
					{
						showstate4();
						pos = 4;
					}
					f.lfHeight = 30;
					settextstyle(&f);
					a = true;
					putimage(CBUTTON_X - 15 + 180, CBUTTON_Y + 50 + 625 / 400 - 4.5, &c_button_2);
					outtextxy(CBUTTON_X + 20 + 180, CBUTTON_Y + 50 + 625 / 400 + 3, _T("4����"));
					if (m.uMsg == WM_LBUTTONUP)
					{
						four_state = 4;
						for (int i = 0; i <= 20; i++)
						{
							putimage(0, 0, &background);
							putimage(21 * 20 - 21 * 20 + 12.4 * i, 0, &background);
							f.lfHeight = 48;
							settextstyle(&f);
							outtextxy(100, SHUOMING_Y, _T("·�����顪��4����"));
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
							putimage(-200 + 10 * i + 100, 140, &line4);
							Sleep(8);
							FlushBatchDraw();
						}
					}
				}
				else if ((PostionX > CBUTTON_X + 180 && PostionX < CBUTTON_X + 120 + 180) &&
					(PostionY > CBUTTON_Y + 100 + 625 / 400 && PostionY < CBUTTON_Y + 100 + 625 / 400 + 36))
				{
					if (pos != 7)
					{
						showstate4();
						pos = 7;
					}
					f.lfHeight = 30;
					settextstyle(&f);
					a = true;
					putimage(CBUTTON_X - 15 + 180, CBUTTON_Y + 100 + 625 / 400 - 4.5, &c_button_2);
					outtextxy(CBUTTON_X + 20 + 180, CBUTTON_Y + 100 + 625 / 400 + 3, _T("7����"));
					if (m.uMsg == WM_LBUTTONUP)
					{
						four_state = 7;
						for (int i = 0; i <= 20; i++)
						{
							putimage(21 * 20 - 21 * 20 + 12.4 * i, 0, &background);
							f.lfHeight = 48;
							settextstyle(&f);
							outtextxy(100, SHUOMING_Y, _T("·�����顪��7����"));
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
							putimage(-1000 + 50 * i, 197, &line7);
							Sleep(8);
							FlushBatchDraw();
						}
					}
				}
				else if ((PostionX > CBUTTON_X + 180 && PostionX < CBUTTON_X + 120 + 180) &&
					(PostionY > CBUTTON_Y + 150 + 625 / 400 && PostionY < CBUTTON_Y + 150 + 625 / 400 + 36))
				{
					if (pos != 11)
					{
						showstate4();
						pos = 11;
					}
					f.lfHeight = 30;
					settextstyle(&f);
					a = true;
					putimage(CBUTTON_X - 15 + 180, CBUTTON_Y + 150 + 625 / 400 - 4.5, &c_button_2);
					outtextxy(CBUTTON_X + 20 + 180, CBUTTON_Y + 150 + 625 / 400 + 3, _T("11����"));
					if (m.uMsg == WM_LBUTTONUP)
					{
						four_state = 11;
						for (int i = 0; i <= 20; i++)
						{
							putimage(0, 0, &background);
							putimage(21 * 20 - 21 * 20 + 12.4 * i, 0, &background);
							f.lfHeight = 48;
							settextstyle(&f);
							outtextxy(100, SHUOMING_Y, _T("·�����顪��11����"));
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
							putimage(-200 + 10 * i + 100, 140, &line11);
							Sleep(8);
							FlushBatchDraw();
						}
					}
				}
				else if ((PostionX > CBUTTON_X + 86 && PostionX < CBUTTON_X + 120 + 86) &&
					(PostionY > CBUTTON_Y + 250 + 625 / 400 && PostionY < CBUTTON_Y + 250 + 625 / 400 + 36))
				{
					if (pos != 0)
					{
						showstate4();
						pos = 0;
					}
					f.lfHeight = 30;
					settextstyle(&f);
					a = true;
					putimage(CBUTTON_X - 15 + 86, CBUTTON_Y + 250 + 625 / 400 - 4.5, &c_button_2);
					outtextxy(CBUTTON_X + 15 + 86, CBUTTON_Y + 250 + 625 / 400 + 3, _T("��·��"));
					if (m.uMsg == WM_LBUTTONUP)
					{
						four_state = 100;
						for (int i = 0; i <= 20; i++)
						{
							putimage(21 * 20 - 21 * 20 + 12.4 * i, 0, &background);
							f.lfHeight = 48;
							settextstyle(&f);
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
							putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * i, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
							putimage(-300 + 10 * i + 100, 0, &line_all);
							Sleep(8);
							FlushBatchDraw();
						}
					}
				}
				else if ((PostionX > 770 && PostionX < 870) && (PostionY > 360 && PostionY < 460))
				{
					sleeptime = 30;
					if (m.uMsg == WM_LBUTTONUP)
					{
						MidAnimation();
						State = 2;
					}
				}
				else
				{
					if (a == true)
					{
						showstate4();
						a = false;
					}
					sleeptime = 120;
				}
			}
			FlushMouseMsgBuffer();
		}
	}
	else
	{
		if (four_state == 1)
		{
			putimage(21 * 20 - 21 * 20 + 12.4 * 20, 0, &background);
			f.lfHeight = 48;
			settextstyle(&f);
			outtextxy(100, SHUOMING_Y, _T("·�����顪��1����"));
			putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * 20, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
			putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * 20, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
			putimage(-1000 + 50 * 20, 197, &line1);
		}
		else if (four_state == 2)
		{

		}
		else if (four_state == 3)
		{

		}
		else if (four_state == 4)
		{

		}
		else if (four_state == 5)
		{

		}
		else if (four_state == 7)
		{

		}
		else if (four_state == 9)
		{

		}
		else if (four_state == 11)
		{

		}
		else if (four_state == 100)
		{

		}
		buttonRo(-248, false);
		while (MouseHit())
		{
			m = GetMouseMsg();
			int PostionX = m.x;
			int PostionY = m.y;
			if ((PostionX > 770 + 248 && PostionX < 870 + 248) && (PostionY > 360 && PostionY < 460))
			{
				sleeptime = 30;
				if (m.uMsg == WM_LBUTTONUP)
				{
					four_state = 0;
					for (int i = 0; i <= 20; i++)
					{
						putimage(21 * 20 - 21 * 20 + 12.4 * 20 - 12.4 * i, 0, &background);
						f.lfHeight = 48;
						settextstyle(&f);
						outtextxy(100 + 200 - 10 * i, SHUOMING_Y, _T("���ڵ���������Ʊϵͳ"));
						putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * 20 - 12.4 * i, 348, 180, 134.5, &a_button_1_z, 0, 0, SRCAND);
						putimage(730.9 + 21 * 20 - 21 * 20 + 12.4 * 20 - 12.4 * i, 348, 180, 134.5, &a_button_1, 0, 0, SRCPAINT);
						Sleep(8);
						FlushBatchDraw();
					}
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
			}
			else
			{
				sleeptime = 120;
			}
		}
		FlushBatchDraw();
	}
	Sleep(sleeptime);
	return 0;
}

//ִ��״̬5��ʹ��˵���ĺ���
int whenState_5()
{
	static int sleeptime = 120;
	state_5();
	buttonRo(0, false);
	while (MouseHit())
	{
		m = GetMouseMsg();
		int PostionX = m.x;
		int PostionY = m.y;
		if (m.uMsg == WM_LBUTTONUP)
		{
			if (PostionX > 770 && PostionX < 870)
			{
				if (PostionY > 360 && PostionY < 460)
				{
					MidAnimation();
					State = 2;
				}
			}
		}
		if ((PostionX > 770 && PostionX < 870) && (PostionY > 360 && PostionY < 460))
		{
			sleeptime = 30;
		}
		else
		{
			sleeptime = 120;
		}
		FlushMouseMsgBuffer();
	}
	Sleep(sleeptime);
	return 0;
}

//��char����ת��Ϊwchar_t����
TCHAR* CharToWchar_t(char* str)
{
	int iSize;
	TCHAR* pwszUnicode;
	iSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	pwszUnicode = (wchar_t*)malloc(iSize * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, 0, str, -1, pwszUnicode, iSize);
	return  pwszUnicode;
}

//��wchar_t����ת��Ϊchar����
char* Wchar_tToChar(TCHAR* str)
{
	int iSize;
	char* t;
	iSize = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	t = (char*)malloc(iSize * sizeof(char));
	WideCharToMultiByte(CP_ACP, 0, str, -1, t, iSize, NULL, NULL);
	return t;
}

//����Ʊ��
int ticket(int distance)
{
	int fee=0;
	if (distance <= 4)
	{
		fee = 2;
	}
	else if (distance > 4 && distance <= 12)
	{
		fee = 2 + (distance - 4) / 4;
	}
	else if (distance > 12 && distance <= 24)
	{
		fee=2+2+ (distance - 12) / 6;
	}
	else if (distance > 24)
	{
		fee=2+2+2+ (distance - 24) / 8;
	}
	if (fee > 14)
	{
		fee = 14;
	}
	return fee;
}