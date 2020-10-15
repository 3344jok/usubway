#ifndef _WHENFUNCTION_H_
#define _WHENFUNCTION_H_



//定义一个全局变量记录当前状态
//1为开始界面
//2为系统主界面
//3为购票界面
//4为地图查询界面
//5为系统说明
extern int State ;

extern int Three_state ;

//定义鼠标信息
extern MOUSEMSG m;

extern int MapSearch();

//执行状态1即初始界面的函数
extern int whenState_1();

//执行状态2即初始界面的函数
extern int whenState_2();

//执行状态3即使用说明的函数
extern int whenState_3();

//执行状态4即使用说明的函数
extern int whenState_4();

//执行状态5即使用说明的函数
extern int whenState_5();

//将char类型转化为wchar_t类型
extern TCHAR* CharToWchar_t(char* str);

//将wchar_t类型转化为char类型
extern char* Wchar_tToChar(TCHAR* str);

extern bool swith;


//计算票价
extern int ticket(int distance);


#endif // _WHENFUNCTION_H_
#pragma once
