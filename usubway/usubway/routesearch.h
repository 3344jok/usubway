#ifndef _ROUTESEARCH_H_
#define _ROUTESEARCH_H_

#define LITRADIUS 2//站点大图标半径
#define LARRADIUS 1//站点小图标半径


//用结构体表示各站点信息
typedef struct station_info{
	char station_name[100];//站名
	int route_number;//路线号
	int station_number;//站号
	bool is_mid_station;//是否中转站
	int con_amount[7];//经过的路线
	int pre_distance;//与前一站的距离
	int nex_distance;//与后一站的距离
	struct station_info *prev;//链表上一节
	struct station_info *next;//链表下一节
}Station_info;

//用结构体表示跨一个站的一种路线可能，并最终建立链表
typedef struct situation_1_info {
	Station_info *begstation;//出发站地址
	Station_info *mid_station;//中转站所在链表地址
	Station_info *finstation;//终点站地址
	int distance;//该种情况总距离
	struct situation_1_info *pNext;//下一个节点
}Situation_1_info;

//当跨两个个站时，使用结构体链表保存所有可能站点的信息
typedef struct situation_2_info {
	int distan;//选择这个第二中转站时，前半段的最小距离
	Station_info *station;
	struct situation_2_info *pNext;//下一个节点
}Situation_2_info;

//用结构体存储各个站点信息链表的表头
typedef struct list_info {
	Station_info *head;
	struct list_info *pNext;//下一个节点
}List_info;

//各个链表的表头
extern List_info *All_head;
extern Station_info *head_1;
extern Station_info *head_2;
extern Station_info *head_3;
extern Station_info *head_4;
extern Station_info *head_5;
extern Station_info *head_7;
extern Station_info *head_9;
extern Station_info *head_11;

//各个链表长度
extern int len_1;
extern int len_2;
extern int len_3;
extern int len_4;
extern int len_5;
extern int len_7;
extern int len_9;
extern int len_11;


//定义各站的名称数组
const char* station_name_data_1[];
const char* station_name_data_2[];
const char* station_name_data_3[];
const char* station_name_data_4[];
const char* station_name_data_5[];
const char* station_name_data_7[];
const char* station_name_data_9[];
const char* station_name_data_11[];

//各种路线推荐路线字符串
extern char *No_1str;
extern char *No_2str_a,*No_2str_b,*No_2str_All;
extern char *No_3str_a,*No_3str_b,*No_3str_c,*No_3str_All;

//各种路线距离
extern int One_dis;
extern int Two_dis;
extern int Three_dis;

extern bool Is_Not;

//起始站所在路线
extern int fir_sta_num;
//终点站所在路线
extern int las_sta_num;

//初始化始末站的结构体
extern Station_info* Fir_station;
extern Station_info* Las_station;

//是否找到对应站点
extern int Get_state;

extern int loadData();//录入数据
extern List_info *load_sta_Data();//遍历添加中转站信息
//主函数
extern int secondmain(const char* bestation, const char* finstation);
//情况一：始末站在同一线路上
extern int one_stiuation(Station_info * bestation, Station_info * finstation);
//情况二：中途中转一次
extern Situation_1_info *two_stiuation(Station_info * bestation, Station_info * finstation, Situation_1_info*Shead);
//情况三：中途中转两次
extern int three_stiuation(const char* bestation, const char* finstation);
//打印路线
extern int print_route_1(Station_info * bestation, const int n);


//情况二时找到所有中间站
extern Situation_1_info *getashead(Station_info * bestation, Station_info * finstation);


//第三种情况下，找到前半段中最小的可能性
extern Situation_1_info* Getshortest(Station_info* fir_station, Station_info* sec_station);

//建立链表
extern Station_info *creat_link1();
extern Station_info *creat_link2();
extern Station_info *creat_link3();
extern Station_info *creat_link4();
extern Station_info *creat_link5();
extern Station_info *creat_link7();
extern Station_info *creat_link9();
extern Station_info *creat_link11();

//遍历链表
extern Station_info *check_one_List(int len, Station_info *head, const char *station_name);
extern Station_info *check_all_List_for_one_name(const char *station_name);

//根据线路号和名字找到在链表的地址
extern Station_info *check_List_by_num_nam(Station_info *in_station, char *pPtr);

//当情况三时，建立一个链表存储所有可能的第二个中转站的信息
extern Situation_2_info*get_possibility(int n, Station_info *head);

//删除链表
extern int DelList(Station_info *pTemp);
extern int DelAllList();

//输入中转站数据
extern int BaoanCenter(int len,Station_info *head, const char *firstname);//宝安中心
extern int QianHaiWan(int len, Station_info *head, const char *firstname);//前海湾
extern int ShijieZhichuan(int len, Station_info *head, const char *firstname);//世界之窗
extern int ChegongMiao(int len, Station_info *head, const char *firstname);//车公庙
extern int ShopPark(int len, Station_info *head, const char *firstname);//购物公园
extern int HuizhanCenter(int len, Station_info *head, const char *firstname);//会展中心
extern int DaJuYuan(int len, Station_info *head, const char *firstname);//大剧院
extern int LaoJie(int len, Station_info *head, const char *firstname);//老街
extern int ChiWan(int len, Station_info *head, const char *firstname);//赤湾
extern int AntuoShan(int len, Station_info *head, const char *firstname);//安托山
extern int JingTian(int len, Station_info *head, const char *firstname);//景田
extern int FuTian(int len, Station_info *head, const char *firstname);//福田
extern int ShiminCenter(int len, Station_info *head, const char *firstname);//市民中心
extern int HuaQiangBei(int len, Station_info *head, const char *firstname);//华强北
extern int HuangbeiLing(int len, Station_info *head, const char *firstname);//黄贝岭
extern int Shisha(int len, Station_info *head, const char *firstname);//石厦
extern int ShaonianGong(int len, Station_info *head, const char *firstname);//少年宫
extern int Huaxin(int len, Station_info *head, const char *firstname);//华新
extern int Tianbei(int len, Station_info *head, const char *firstname);//田贝
extern int Buji(int len, Station_info *head, const char *firstname);//布吉
extern int Fumin(int len, Station_info *head, const char *firstname);//福民
extern int ShangmeiLin(int len, Station_info *head, const char *firstname);//上梅林
extern int ShenzhenBei(int len, Station_info *head, const char *firstname);//深圳北站
extern int Qianwan(int len, Station_info *head, const char *firstname);//前湾
extern int Xili(int len, Station_info *head, const char *firstname);//西丽
extern int Taian(int len, Station_info *head, const char *firstname);//太安
extern int Honglingbei(int len, Station_info *head, const char *firstname);//红岭北
extern int HongshuwanNan(int len, Station_info *head, const char *firstname);//红树湾南
extern int Hongling(int len, Station_info *head, const char *firstname);//红岭
extern int Houhai(int len, Station_info *head, const char *firstname);//后海




#endif // ROUTESEARCH_H_INCLUDED
#pragma once
