#ifndef _UI_H_
#define _UI_H_


extern IMAGE background;
extern IMAGE a_button_1, a_button_1_z, a_button_2, a_button_2_z, a_button_3, a_button_3_z, a_button_4, a_button_4_z;
extern IMAGE b_button_a,b_button_b;
extern IMAGE word, word_z, word_2, word_2_z,Word,Word_z;
extern IMAGE line1, line2, line3, line4, line5, line7, line9, line11, line_all,c_button, c_button_2;
extern IMAGE input, input_z, qi, qi_z, zhong, zhong_z;

//���屳��ͼƬ���ڵı���
extern IMAGE background;

//���ر���ͼƬ
extern int Background();

//��ʾ��ӭ�Ͱ�Ȩ��Ϣ
extern int welCome();

//�ӳ�ʼ���浽ϵͳ���˵��Ĺ��ɶ���
extern int MidAnimation();

//�������ӽ��浽ϵͳ���˵��Ĺ��ɶ���
extern int MidAnimation_b(int a);

//����ť��ת����
extern int buttonRo(int a,bool b);

//״̬��ʱ��ʾͼƬ
extern int whenstate_2();

//״̬����ť��Ч
extern int button_anmi_2(int a,bool b);

//״̬5ʱ�ĺ���
extern int state_5();

//״̬4ʱ���滭��
extern int showstate4();

//����Ͷ�ҽ��涯��
extern int coin_mid(TCHAR per_pay[],TCHAR all_pay[],int ticket_num,int fin_fee,bool a);


#endif // !_UI_H_
#pragma once
