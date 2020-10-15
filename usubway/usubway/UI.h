#ifndef _UI_H_
#define _UI_H_


extern IMAGE background;
extern IMAGE a_button_1, a_button_1_z, a_button_2, a_button_2_z, a_button_3, a_button_3_z, a_button_4, a_button_4_z;
extern IMAGE b_button_a,b_button_b;
extern IMAGE word, word_z, word_2, word_2_z,Word,Word_z;
extern IMAGE line1, line2, line3, line4, line5, line7, line9, line11, line_all,c_button, c_button_2;
extern IMAGE input, input_z, qi, qi_z, zhong, zhong_z;

//定义背景图片所在的变量
extern IMAGE background;

//加载背景图片
extern int Background();

//显示欢迎和版权信息
extern int welCome();

//从初始界面到系统主菜单的过渡动画
extern int MidAnimation();

//从其他子界面到系统主菜单的过渡动画
extern int MidAnimation_b(int a);

//主按钮旋转动画
extern int buttonRo(int a,bool b);

//状态二时显示图片
extern int whenstate_2();

//状态二按钮特效
extern int button_anmi_2(int a,bool b);

//状态5时的函数
extern int state_5();

//状态4时界面画面
extern int showstate4();

//进入投币界面动画
extern int coin_mid(TCHAR per_pay[],TCHAR all_pay[],int ticket_num,int fin_fee,bool a);


#endif // !_UI_H_
#pragma once
