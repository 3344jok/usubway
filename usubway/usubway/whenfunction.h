#ifndef _WHENFUNCTION_H_
#define _WHENFUNCTION_H_



//����һ��ȫ�ֱ�����¼��ǰ״̬
//1Ϊ��ʼ����
//2Ϊϵͳ������
//3Ϊ��Ʊ����
//4Ϊ��ͼ��ѯ����
//5Ϊϵͳ˵��
extern int State ;

extern int Three_state ;

//���������Ϣ
extern MOUSEMSG m;

extern int MapSearch();

//ִ��״̬1����ʼ����ĺ���
extern int whenState_1();

//ִ��״̬2����ʼ����ĺ���
extern int whenState_2();

//ִ��״̬3��ʹ��˵���ĺ���
extern int whenState_3();

//ִ��״̬4��ʹ��˵���ĺ���
extern int whenState_4();

//ִ��״̬5��ʹ��˵���ĺ���
extern int whenState_5();

//��char����ת��Ϊwchar_t����
extern TCHAR* CharToWchar_t(char* str);

//��wchar_t����ת��Ϊchar����
extern char* Wchar_tToChar(TCHAR* str);

extern bool swith;


//����Ʊ��
extern int ticket(int distance);


#endif // _WHENFUNCTION_H_
#pragma once
