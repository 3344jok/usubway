#ifndef _ROUTESEARCH_H_
#define _ROUTESEARCH_H_

#define LITRADIUS 2//վ���ͼ��뾶
#define LARRADIUS 1//վ��Сͼ��뾶


//�ýṹ���ʾ��վ����Ϣ
typedef struct station_info{
	char station_name[100];//վ��
	int route_number;//·�ߺ�
	int station_number;//վ��
	bool is_mid_station;//�Ƿ���תվ
	int con_amount[7];//������·��
	int pre_distance;//��ǰһվ�ľ���
	int nex_distance;//���һվ�ľ���
	struct station_info *prev;//������һ��
	struct station_info *next;//������һ��
}Station_info;

//�ýṹ���ʾ��һ��վ��һ��·�߿��ܣ������ս�������
typedef struct situation_1_info {
	Station_info *begstation;//����վ��ַ
	Station_info *mid_station;//��תվ���������ַ
	Station_info *finstation;//�յ�վ��ַ
	int distance;//��������ܾ���
	struct situation_1_info *pNext;//��һ���ڵ�
}Situation_1_info;

//����������վʱ��ʹ�ýṹ�����������п���վ�����Ϣ
typedef struct situation_2_info {
	int distan;//ѡ������ڶ���תվʱ��ǰ��ε���С����
	Station_info *station;
	struct situation_2_info *pNext;//��һ���ڵ�
}Situation_2_info;

//�ýṹ��洢����վ����Ϣ����ı�ͷ
typedef struct list_info {
	Station_info *head;
	struct list_info *pNext;//��һ���ڵ�
}List_info;

//��������ı�ͷ
extern List_info *All_head;
extern Station_info *head_1;
extern Station_info *head_2;
extern Station_info *head_3;
extern Station_info *head_4;
extern Station_info *head_5;
extern Station_info *head_7;
extern Station_info *head_9;
extern Station_info *head_11;

//����������
extern int len_1;
extern int len_2;
extern int len_3;
extern int len_4;
extern int len_5;
extern int len_7;
extern int len_9;
extern int len_11;


//�����վ����������
const char* station_name_data_1[];
const char* station_name_data_2[];
const char* station_name_data_3[];
const char* station_name_data_4[];
const char* station_name_data_5[];
const char* station_name_data_7[];
const char* station_name_data_9[];
const char* station_name_data_11[];

//����·���Ƽ�·���ַ���
extern char *No_1str;
extern char *No_2str_a,*No_2str_b,*No_2str_All;
extern char *No_3str_a,*No_3str_b,*No_3str_c,*No_3str_All;

//����·�߾���
extern int One_dis;
extern int Two_dis;
extern int Three_dis;

extern bool Is_Not;

//��ʼվ����·��
extern int fir_sta_num;
//�յ�վ����·��
extern int las_sta_num;

//��ʼ��ʼĩվ�Ľṹ��
extern Station_info* Fir_station;
extern Station_info* Las_station;

//�Ƿ��ҵ���Ӧվ��
extern int Get_state;

extern int loadData();//¼������
extern List_info *load_sta_Data();//���������תվ��Ϣ
//������
extern int secondmain(const char* bestation, const char* finstation);
//���һ��ʼĩվ��ͬһ��·��
extern int one_stiuation(Station_info * bestation, Station_info * finstation);
//���������;��תһ��
extern Situation_1_info *two_stiuation(Station_info * bestation, Station_info * finstation, Situation_1_info*Shead);
//���������;��ת����
extern int three_stiuation(const char* bestation, const char* finstation);
//��ӡ·��
extern int print_route_1(Station_info * bestation, const int n);


//�����ʱ�ҵ������м�վ
extern Situation_1_info *getashead(Station_info * bestation, Station_info * finstation);


//����������£��ҵ�ǰ�������С�Ŀ�����
extern Situation_1_info* Getshortest(Station_info* fir_station, Station_info* sec_station);

//��������
extern Station_info *creat_link1();
extern Station_info *creat_link2();
extern Station_info *creat_link3();
extern Station_info *creat_link4();
extern Station_info *creat_link5();
extern Station_info *creat_link7();
extern Station_info *creat_link9();
extern Station_info *creat_link11();

//��������
extern Station_info *check_one_List(int len, Station_info *head, const char *station_name);
extern Station_info *check_all_List_for_one_name(const char *station_name);

//������·�ź������ҵ�������ĵ�ַ
extern Station_info *check_List_by_num_nam(Station_info *in_station, char *pPtr);

//�������ʱ������һ������洢���п��ܵĵڶ�����תվ����Ϣ
extern Situation_2_info*get_possibility(int n, Station_info *head);

//ɾ������
extern int DelList(Station_info *pTemp);
extern int DelAllList();

//������תվ����
extern int BaoanCenter(int len,Station_info *head, const char *firstname);//��������
extern int QianHaiWan(int len, Station_info *head, const char *firstname);//ǰ����
extern int ShijieZhichuan(int len, Station_info *head, const char *firstname);//����֮��
extern int ChegongMiao(int len, Station_info *head, const char *firstname);//������
extern int ShopPark(int len, Station_info *head, const char *firstname);//���﹫԰
extern int HuizhanCenter(int len, Station_info *head, const char *firstname);//��չ����
extern int DaJuYuan(int len, Station_info *head, const char *firstname);//���Ժ
extern int LaoJie(int len, Station_info *head, const char *firstname);//�Ͻ�
extern int ChiWan(int len, Station_info *head, const char *firstname);//����
extern int AntuoShan(int len, Station_info *head, const char *firstname);//����ɽ
extern int JingTian(int len, Station_info *head, const char *firstname);//����
extern int FuTian(int len, Station_info *head, const char *firstname);//����
extern int ShiminCenter(int len, Station_info *head, const char *firstname);//��������
extern int HuaQiangBei(int len, Station_info *head, const char *firstname);//��ǿ��
extern int HuangbeiLing(int len, Station_info *head, const char *firstname);//�Ʊ���
extern int Shisha(int len, Station_info *head, const char *firstname);//ʯ��
extern int ShaonianGong(int len, Station_info *head, const char *firstname);//���깬
extern int Huaxin(int len, Station_info *head, const char *firstname);//����
extern int Tianbei(int len, Station_info *head, const char *firstname);//�ﱴ
extern int Buji(int len, Station_info *head, const char *firstname);//����
extern int Fumin(int len, Station_info *head, const char *firstname);//����
extern int ShangmeiLin(int len, Station_info *head, const char *firstname);//��÷��
extern int ShenzhenBei(int len, Station_info *head, const char *firstname);//���ڱ�վ
extern int Qianwan(int len, Station_info *head, const char *firstname);//ǰ��
extern int Xili(int len, Station_info *head, const char *firstname);//����
extern int Taian(int len, Station_info *head, const char *firstname);//̫��
extern int Honglingbei(int len, Station_info *head, const char *firstname);//���뱱
extern int HongshuwanNan(int len, Station_info *head, const char *firstname);//��������
extern int Hongling(int len, Station_info *head, const char *firstname);//����
extern int Houhai(int len, Station_info *head, const char *firstname);//��




#endif // ROUTESEARCH_H_INCLUDED
#pragma once
