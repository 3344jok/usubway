#include <stdio.h>
#include "routesearch.h"
#include <corecrt_malloc.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4244)

//七个链表的表头
List_info *All_head = (List_info*)malloc(sizeof(List_info));
Station_info *head_1 = (Station_info*)malloc(sizeof(Station_info));
Station_info *head_2 = (Station_info*)malloc(sizeof(Station_info));
Station_info *head_3 = (Station_info*)malloc(sizeof(Station_info));
Station_info *head_4 = (Station_info*)malloc(sizeof(Station_info));
Station_info *head_5 = (Station_info*)malloc(sizeof(Station_info));
Station_info *head_7 = (Station_info*)malloc(sizeof(Station_info));
Station_info *head_9 = (Station_info*)malloc(sizeof(Station_info));
Station_info *head_11 = (Station_info*)malloc(sizeof(Station_info));

//各个链表长度
int len_1;
int len_2;
int len_3;
int len_4;
int len_5;
int len_7;
int len_9;
int len_11;

//初始化始末站的结构体
Station_info *Fir_station = (Station_info*)malloc(sizeof(Station_info));
Station_info *Las_station = (Station_info*)malloc(sizeof(Station_info));

//定义变量存储情况二的最小路线信息
Situation_1_info *min_p = (Situation_1_info*)malloc(sizeof(Situation_1_info));

//定义变量存储情况三的前半段的最小路线信息
Situation_1_info *min_L = (Situation_1_info*)malloc(sizeof(Situation_1_info));

//各种路线推荐路线字符串
char *tempStr = {};
char *No_1str = {};
char* No_2str_a = {}, * No_2str_b = {}, * No_2str_All = {};
char* No_3str_a = {}, * No_3str_b = {}, * No_3str_c = {}, *No_3str_All = {};

//各种路线距离
int One_dis=0;
int Two_dis=0;
int Three_dis=0;

//定义一个变量记录是否有相同的中转站
bool Is_Not = false;

//定义一个布尔变量记录是否在同一路线
bool same_route = false;

//是否找到对应站点
int Get_state;


//将各站的名称存入字符串数组
const char* station_name_data_1[] = {"机场东","后瑞","固戍","西乡","坪洲","宝体","宝安中心","新安","前海湾","鲤鱼门","大新","桃园","深大","高新园","白石洲","世界之窗",
	"华侨城","侨城东","竹子林","车公庙","香蜜湖","购物公园","会展中心","岗厦","华强路","科学馆","大剧院","老街","国贸","罗湖" };
const char* station_name_data_2[] = { "赤湾","蛇口港","海上世界","水湾","东角头","湾厦","海月","登良","后海","科苑","红树湾","世界之窗","桥城北","深康","安托山","侨香",
	"香蜜","香梅北","景田","莲花西","福田","市民中心","岗厦北","华强北","燕南","大剧院","湖贝","黄贝岭","新秀" };
const char* station_name_data_3[] = { "益田","石厦","购物公园","福田","少年宫","莲花村","华新","通新岭","红岭","老街","晒布","翠竹","田贝","水贝","草埔","布吉","木棉湾",
	"大芬","丹竹头","六约","塘坑","横岗","永湖","荷坳","大运","爱联","吉祥","龙城广场","南联","双龙" };
const char* station_name_data_4[] = { "福田口岸","福民","会展中心","市民中心","少年宫","莲花北","上梅林","民乐","白石龙","深圳北站","红山","上塘","龙胜","龙华","清湖" };
const char* station_name_data_5[] = { "赤湾","荔湾","铁路公园","妈湾","前湾公园","前湾","桂湾","前海湾","临海","宝华","宝安中心","翻身","灵芝","洪浪北","兴东","留仙洞",
	"西丽","大学城","塘朗","长岭陂","深圳北站","民治","五和","坂田","杨美","上水径","下水径","长龙","布吉","百鸽笼","布心","太安","怡景","黄贝岭" };
const char* station_name_data_7[] = { "太安","田贝","洪湖","笋岗","红岭北","八卦岭","黄木岗","华新","华强北","华强南","赤尾","福邻","皇岗口岸","福民","皇岗村","石厦",
	"沙尾","上沙","车公庙","农林","安托山","深云","桃源村","龙井","珠光","茶光","西丽","西丽湖" };
const char* station_name_data_9[] = { "前湾","梦海","怡海","荔林","南油西","南油","南山书城","深大南","粤海门","高新南","红树湾南","深湾","深圳湾公园","下沙","车公庙",
	"香梅","景田","梅景","下梅林","梅村","上梅林","孖岭","银湖","泥岗","红岭北","园岭","红岭","红岭南","鹿丹村","人民南","向西村","文锦" };
const char* station_name_data_11[] = { "福田","车公庙","红树湾南","后海","南山","前海湾","宝安","碧海湾","机场","机场北","福永","桥头","塘尾","马安山","沙井","后亭","松岗","碧头" };

int secondmain(const char* bestation, const char* finstation)
{
	//初始化路线数据
	loadData();
	All_head=load_sta_Data();
	No_1str = {};
	No_2str_All = {};
	No_3str_All = {};


	//获取始末站信息——链表节点
	Fir_station= check_all_List_for_one_name(bestation);
	Las_station = check_all_List_for_one_name(finstation);
	//检查是否找到站点
	if (Fir_station == NULL || Las_station == NULL)
	{
		Get_state =  0;
		return 0;
	}

	//判断是否在同一路线
	int rou_number = 0;
	if (Fir_station->route_number == Las_station->route_number)
	{
		rou_number = Fir_station->route_number;
		same_route = true;
	}
	else if (Fir_station->is_mid_station == true&&Las_station->is_mid_station==false)
	{
		int c = 0;
		do {
			if (Fir_station->con_amount[c] == Las_station->route_number)
			{
				rou_number = Las_station->route_number;
				same_route = true;
			}
			c++;
		} while (Fir_station->con_amount[c] != 0);
	}
	else if (Las_station->is_mid_station == true && Fir_station->is_mid_station == false)
	{
		int c = 0;
		do {
			if (Las_station->con_amount[c] == Fir_station->route_number)
			{
				rou_number = Fir_station->route_number;
				same_route = true;
			}
			c++;
		} while (Las_station->con_amount[c] != 0);
	}
	else if (Las_station->is_mid_station == true && Fir_station->is_mid_station == true)
	{
		int c = 0;
		do {
			int b = 0;
			do {
				if (Las_station->con_amount[b] == Fir_station->con_amount[c])
				{
					rou_number = Las_station->con_amount[b];
					same_route = true;
				}
				b++;
			} while (Las_station->con_amount[b] != 0);
			c++;
		} while (Fir_station->con_amount[c] != 0);
	}

	//当两站点在同一路线时
	if (same_route == true)
	{
		Station_info* fir_station = (Station_info*)malloc(sizeof(Station_info));
		Station_info* las_station = (Station_info*)malloc(sizeof(Station_info));
		if (rou_number == 1)
		{
			fir_station = check_one_List(len_1, head_1, Fir_station->station_name);
			las_station = check_one_List(len_1, head_1, Las_station->station_name);
		}
		else if (rou_number == 2)
		{
			fir_station = check_one_List(len_2, head_2, Fir_station->station_name);
			las_station = check_one_List(len_2, head_2, Las_station->station_name);
		}
		else if (rou_number == 3)
		{
			fir_station = check_one_List(len_3, head_3, Fir_station->station_name);
			las_station = check_one_List(len_3, head_3, Las_station->station_name);
		}
		else if (rou_number == 4)
		{
			fir_station = check_one_List(len_4, head_4, Fir_station->station_name);
			las_station = check_one_List(len_4, head_4, Las_station->station_name);
		}
		else if (rou_number == 5)
		{
			fir_station = check_one_List(len_5, head_5, Fir_station->station_name);
			las_station = check_one_List(len_5, head_5, Las_station->station_name);
		}
		else if (rou_number == 7)
		{
			fir_station = check_one_List(len_7, head_7, Fir_station->station_name);
			las_station = check_one_List(len_7, head_7, Las_station->station_name);
		}
		else if (rou_number == 9)
		{
			fir_station = check_one_List(len_9, head_9, Fir_station->station_name);
			las_station = check_one_List(len_9, head_9, Las_station->station_name);
		}
		else if (rou_number == 11)
		{
			fir_station = check_one_List(len_11, head_11, Fir_station->station_name);
			las_station = check_one_List(len_11, head_11, Las_station->station_name);
		}
		//las_station = check_List_by_num_nam(Fir_station, Las_station->station_name);
		int NO_1_station_amount = one_stiuation(fir_station, las_station);
		One_dis = print_route_1(fir_station, NO_1_station_amount);
		No_1str = tempStr;
		printf("情况一：%s  距离：%d公里", No_1str,One_dis);
		same_route = false;
		Get_state = 1;
	}

	//当两站点不在同一路线
	else
	{
		////////////////////寻找是否由跨一站的方案
		Situation_1_info *Shead = (Situation_1_info*)malloc(sizeof(Situation_1_info));
		Shead = getashead(Fir_station, Las_station);
		////////////////////

		//情况二：当两站点有相同的中转站
		if (Is_Not==true)
		{
			min_p=two_stiuation(Fir_station, Las_station, Shead);
			//printf("%s->(转%d号线)->%s	距离：%d公里\n", No_2str_a,min_p->finstation->route_number, No_2str_b,min_p->distance);
			Two_dis = min_p->distance;
			No_2str_All = (char*)malloc(strlen(No_2str_a) + strlen("->(转1号线)->") + strlen(No_2str_b));
			sprintf(No_2str_All, "%s\n->(转%d号线)->\n%s", No_2str_a, min_p->finstation->route_number, No_2str_b, min_p->distance);
			printf("情况二：%s	距离：%d公里\n", No_2str_All,Two_dis);
			Is_Not = false;
		}

		//情况三：
		//无论有无共同中转站，都寻找跨两站的方案
		//先建立一个链表存储所有可能的第二个中转站的信息
		Situation_2_info *Head = (Situation_2_info*)malloc(sizeof(Situation_2_info));
		int min_now = 0;
		if (Las_station->route_number == 1)
		{
			Head = get_possibility(len_1, head_1);
		}
		else if (Las_station->route_number == 2)
		{
			Head = get_possibility(len_2, head_2);
		}
		else if (Las_station->route_number == 3)
		{
			Head = get_possibility(len_3, head_3);
		}
		else if (Las_station->route_number == 4)
		{
			Head = get_possibility(len_4, head_4);
		}
		else if (Las_station->route_number == 5)
		{
			Head = get_possibility(len_5, head_5);
		}
		else if (Las_station->route_number == 7)
		{
			Head = get_possibility(len_7, head_7);
		}
		else if (Las_station->route_number == 9)
		{
			Head = get_possibility(len_9, head_9);
		}
		else if (Las_station->route_number == 11)
		{
			Head = get_possibility(len_11, head_11);
		}
		do {
			Situation_1_info *Temp = (Situation_1_info*)malloc(sizeof(Situation_1_info));
			Situation_1_info *Thead = (Situation_1_info*)malloc(sizeof(Situation_1_info));


			//错误，Head->station的路线还是终点站的
			//Thead = getashead(Fir_station, Head->station);

			Thead = Getshortest(Fir_station, Head->station);

			////////////////////
			/////////////////////
			//////////////////////////
			//////////////////////////
			Temp = two_stiuation(Fir_station, Thead->finstation,Thead);
			Head->distan = Temp->distance;
			printf("----%s->%s->%s 最小%d\n",Temp->begstation->station_name, Temp->mid_station->station_name, Temp->finstation->station_name,Temp->distance );
			int NO_2_station_amount = one_stiuation(Head->station, Las_station);
			Head->distan = Head->distan + print_route_1(Head->station, NO_2_station_amount);
			if (min_now == 0)
			{
				min_now = Head->distan;
				min_L = Temp;
			}
			else if(Head->distan<min_now)
			{
				min_now = Head->distan;
				min_L = Temp;
			}
			if (Head->pNext != NULL)
			{
				Head = Head->pNext;
			}
			else if (Head->pNext == NULL)
			{
				break;
			}
		} while (Head!=NULL);
		printf("%s->%s->%s 最小小小小的之%d\n", min_L->begstation->station_name, min_L->mid_station->station_name,min_L->finstation->station_name,min_L->distance);
		Station_info *firststation = check_List_by_num_nam(Fir_station, min_L->mid_station->station_name);
		Station_info *secondstation = check_List_by_num_nam(min_L->finstation, min_L->mid_station->station_name);
		int n_1 = one_stiuation(Fir_station, firststation);
		int n_2 = one_stiuation(secondstation, min_L->finstation);
		print_route_1(Fir_station, n_1);
		No_3str_a = tempStr;
		print_route_1(secondstation, n_2);
		No_3str_b = tempStr;
		Station_info* thirdstation = check_List_by_num_nam(Las_station, min_L->finstation->station_name);
		int n_3 = one_stiuation(thirdstation, Las_station);
		print_route_1(thirdstation, n_3);
		No_3str_c = tempStr;
		Three_dis = min_now;
		//printf("%s->(转)->%s->(转)->%s   距离：%d公里\n", No_3str_a, No_3str_b, No_3str_c,min_now);
		
		if (No_3str_a == NULL)
		{
			No_3str_All = (char*)malloc(strlen(No_3str_b) + strlen("\n->(转1号线)->\n") + strlen(No_3str_c));
			sprintf(No_3str_All, "%s\n->(转%d号线)->\n%s", No_3str_b, Las_station->route_number, No_3str_c);
		}
		else if(No_3str_b == NULL)
		{
			No_3str_All = (char*)malloc(strlen(No_3str_a) + strlen("\n->(转1号线)->\n") + strlen(No_3str_c));
			sprintf(No_3str_All, "%s\n->(转%d号线)->\n%s", No_3str_a,  Las_station->route_number, No_3str_c);
		}
		else if (No_3str_c == NULL)
		{
			No_3str_All = (char*)malloc(strlen(No_3str_a) + strlen("\n->(转1号线)->\n") + strlen(No_3str_b));
			sprintf(No_3str_All, "%s\n->(转%d号线)->\n%s", No_3str_a, Las_station->route_number, No_3str_b);
		}
		else
		{
			No_3str_All = (char*)malloc(strlen(No_3str_a) + strlen("\n->(转1号线)->\n") + strlen(No_3str_b) + strlen("\n->(转1号线)->\n") + strlen(No_3str_c));
			sprintf(No_3str_All, "%s\n->(转%d号线)->\n%s\n->(转%d号线)->\n%s", No_3str_a, min_L->finstation->route_number,
				No_3str_b, Las_station->route_number, No_3str_c);
		}
		printf("情况三：%s	距离：%d公里\n", No_3str_All, Three_dis);
		Get_state = 2;
	}



	return 0;
};

//第三种情况下，在某种第二个中转站的可能下，找到前半段中最小的可能性
Situation_1_info* Getshortest(Station_info* fir_station, Station_info* sec_station)
{
	int i = 0;
	Situation_1_info* Min = (Situation_1_info*)malloc(sizeof(Situation_1_info));
	Min = NULL;
	while(sec_station->con_amount[i]!=0)
	{
		Station_info* Temp = (Station_info*)malloc(sizeof(Station_info));
		Station_info* Temp_b = (Station_info*)malloc(sizeof(Station_info));
		Situation_1_info* Shead = (Situation_1_info*)malloc(sizeof(Situation_1_info));
		Shead = NULL;
		Situation_1_info* min = (Situation_1_info*)malloc(sizeof(Situation_1_info));
		min = NULL;
		if (sec_station->con_amount[i] == 1&&fir_station->route_number!=sec_station->con_amount[i])
		{
			//Temp_b = sec_station;
			//Temp_b->route_number = sec_station->con_amount[i];
			//sec_station = check_List_by_num_nam(Temp_b, sec_station->station_name);
			Temp = check_one_List(len_1, head_1, sec_station->station_name);
			Shead = getashead(fir_station, Temp);
			if (Shead != nullptr)
			{
				min = two_stiuation(fir_station, Temp, Shead);
			}
		}
		else if (sec_station->con_amount[i] == 2 && fir_station->route_number !=sec_station->con_amount[i])
		{
			Temp = check_one_List(len_2, head_2, sec_station->station_name);
			Shead = getashead(fir_station, Temp);
			if (Shead != nullptr)
			{
				min = two_stiuation(fir_station, Temp, Shead);
			}
		}
		else if (sec_station->con_amount[i] == 3 && fir_station->route_number != sec_station->con_amount[i])
		{
			Temp = check_one_List(len_3, head_3, sec_station->station_name);
			Shead = getashead(fir_station, Temp);
			if (Shead != nullptr)
			{
				min = two_stiuation(fir_station, Temp, Shead);
			}
		}
		else if (sec_station->con_amount[i] == 4 && fir_station->route_number != sec_station->con_amount[i])
		{
			Temp = check_one_List(len_4, head_4, sec_station->station_name);
			Shead = getashead(fir_station, Temp);
			if (Shead != nullptr)
			{
				min = two_stiuation(fir_station, Temp, Shead);
			}
		}
		else if (sec_station->con_amount[i] == 5 && fir_station->route_number != sec_station->con_amount[i])
		{
			Temp = check_one_List(len_5, head_5, sec_station->station_name);
			Shead = getashead(fir_station, Temp);
			if (Shead != nullptr)
			{
				min = two_stiuation(fir_station, Temp, Shead);
			}
		}
		else if (sec_station->con_amount[i] == 7 && fir_station->route_number != sec_station->con_amount[i])
		{
			Temp = check_one_List(len_7, head_7, sec_station->station_name);
			Shead = getashead(fir_station, Temp);
			if (Shead != nullptr)
			{
				min = two_stiuation(fir_station, Temp, Shead);
			}
		}
		else if (sec_station->con_amount[i] == 9 && fir_station->route_number != sec_station->con_amount[i])
		{
			Temp = check_one_List(len_9, head_9, sec_station->station_name);
			Shead = getashead(fir_station, Temp);
			if (Shead != nullptr)
			{
				min = two_stiuation(fir_station, Temp, Shead);
			}
		}
		else if (sec_station->con_amount[i] == 11 && fir_station->route_number != sec_station->con_amount[i])
		{
			Temp = check_one_List(len_11, head_11, sec_station->station_name);
			Shead = getashead(fir_station, Temp);
			if (Shead != nullptr)
			{
				min = two_stiuation(fir_station, Temp, Shead);
			}
		}
		if (min != NULL)
		{
			if (Min==NULL)
			{
				Min = min;
			}
			else if (min->distance < Min->distance)
			{
				Min = min;
			}
		}
		i++;
	}
	return Min;
}

Situation_1_info *getashead(Station_info * bestation, Station_info * finstation)
{
	Is_Not = false;
	//判断是否有共同的中转站
	List_info *p = (List_info*)malloc(sizeof(List_info));
	p = All_head;
	Situation_1_info *Shead = (Situation_1_info*)malloc(sizeof(Situation_1_info));
	do {
		Station_info *o = (Station_info*)malloc(sizeof(Station_info));
		o = p->head;
		//遍历是否有共同的中转站
		do {
			//遍历所有站点，两个布尔变量记录各个站点是否经过始末站所在的路线
			bool switch_1 = false;
			bool switch_2 = false;
			for (int i = 0; i <= 6; i++)
			{
				if (o->con_amount[i] == bestation->route_number)
				{
					//经过起始站所在的路线
					switch_1 = true;
				}
			}
			for (int j = 0; j <= 6; j++)
			{
				if (o->con_amount[j] == finstation->route_number)
				{
					//经过终点站所在的路线
					switch_2 = true;
				}
			}
			//如果同时经过这两条路线则执行下面语句
			if (switch_1 == true && switch_2 == true)
			{
				//找到所有的路线安排的可能建立一个链表存储
				if (Is_Not == false)
				{
					Shead->begstation = bestation;
					Shead->finstation = finstation;
					Shead->mid_station = o;
					Shead->pNext = NULL;
					Is_Not = true;
				}
				else
				{
					Situation_1_info *pPtr = (Situation_1_info*)malloc(sizeof(Situation_1_info));
					pPtr = Shead;
					bool first = true;
					while (pPtr != NULL)
					{
						//printf("%s-> %s->  %s\n",pPtr->begstation->station_name, pPtr->mid_station->station_name,pPtr->finstation->station_name);
						if (strcmp(pPtr->mid_station->station_name, o->station_name) == 0)
						{
							first = false;
						}
						if (pPtr->pNext != NULL)
						{
							pPtr = pPtr->pNext;
						}
						else if (pPtr->pNext == NULL)
						{
							break;
						}
					}
					if (first == true)
					{
						Situation_1_info *pTemp = (Situation_1_info*)malloc(sizeof(Situation_1_info));
						pTemp->begstation = bestation;
						pTemp->finstation = finstation;
						pTemp->mid_station = o;
						pTemp->pNext = NULL;
						pPtr->pNext = pTemp;
					}
				}
			}
			if (o->next == nullptr)
			{
				break;
			}
			else
			{
				o = o->next;
			}
		} while (o != NULL);

		if (p->pNext == nullptr)
		{
			break;
		}
		else
		{
			p = p->pNext;
		}
	} while (p != NULL);
	if (Is_Not == true)
	{
		return Shead;
	}
	else
	{
		return NULL;
	}
}
//情况一
int one_stiuation(Station_info * bestation, Station_info * finstation)
{
	Station_info *p;
	int distance = 0;
	int n = 0;
	p = bestation;
	if (bestation->station_name == finstation->station_name)
	{
		return n;
	}
	else if (bestation->station_number > finstation->station_number)
	{
		while (p != finstation)
		{
			distance += p->pre_distance;
			p = p->prev;
			n--;
		}
	}
	else if (bestation->station_number < finstation->station_number)
	{
		while (p != finstation)
		{
			distance += p->nex_distance;
			p = p->next;
			n++;
		}
	}
	return n;
};
//情况二
Situation_1_info *two_stiuation(Station_info * bestation, Station_info * finstation,Situation_1_info*Shead)
{
	Situation_1_info *pPtr = (Situation_1_info*)malloc(sizeof(Situation_1_info));
	pPtr = Shead;
	//记录最短距离
	int min_dis=0;
	//存储最短距离的路线
	Situation_1_info *Min_pPtr = (Situation_1_info*)malloc(sizeof(Situation_1_info));
	//循环是否结束
	bool over_or_not = false;

	//循环找到每种可能路线的距离
	while (pPtr!=NULL)
	{
		over:
		//定义两个变量分别存储中转站在始末站所处的链表的位置
		Station_info *firststation = (Station_info*)malloc(sizeof(Station_info));
		Station_info *secondstation = (Station_info*)malloc(sizeof(Station_info));
		if (over_or_not == false)
		{
			//找出中转站在起始站所在链表的地址
			firststation = check_List_by_num_nam(bestation, pPtr->mid_station->station_name);
			//找出中转站在终点站站所在链表的地址
			secondstation = check_List_by_num_nam(finstation, pPtr->mid_station->station_name);
			//记录在该路线上的站数
			int n_1 = one_stiuation(bestation, firststation);
			int n_2 = one_stiuation(secondstation, finstation);
			pPtr->distance = print_route_1(bestation, n_1) + print_route_1(secondstation, n_2);
			printf("**%s-> %s-> %s  %d\n", pPtr->begstation->station_name, pPtr->mid_station->station_name, pPtr->finstation->station_name, pPtr->distance);
		}
		else if (over_or_not == true)
		{
			firststation = check_List_by_num_nam(bestation, Min_pPtr->mid_station->station_name);
			secondstation = check_List_by_num_nam(finstation, Min_pPtr->mid_station->station_name);
			int n_1 = one_stiuation(bestation, firststation);
			int n_2 = one_stiuation(secondstation, finstation);
			Min_pPtr->distance = print_route_1(bestation, n_1) ;
			No_2str_a = tempStr;
			Min_pPtr->distance = Min_pPtr->distance + print_route_1(secondstation, n_2);
			No_2str_b = tempStr;
			goto out;
		}
		if(min_dis==0)
		{
			min_dis = pPtr->distance;
			Min_pPtr = pPtr;
		}
		else if (min_dis > pPtr->distance)
		{
			min_dis = pPtr->distance;
			Min_pPtr = pPtr;
		}
		if (pPtr->pNext != NULL)
		{
			pPtr = pPtr->pNext;
		}
		else
		{
			over_or_not = true;
			goto over;
		out:
			break;
		}
	}
	//printf("%s-> %s-> %s  %d最小\n", Min_pPtr->begstation->station_name, Min_pPtr->mid_station->station_name, Min_pPtr->finstation->station_name, Min_pPtr->distance);
	return Min_pPtr;
};
//情况三
int three_stiuation(const char* bestation, const char* finstation)
{
	return 0;
};

//当情况三时，建立一个链表存储所有可能的第二个中转站的信息
Situation_2_info*get_possibility(int n, Station_info *head)
{
	Station_info *pptr = (Station_info*)malloc(sizeof(Station_info));
	pptr = head;
	Situation_2_info *header = (Situation_2_info*)malloc(sizeof(Situation_2_info));
	header = NULL;
	Situation_2_info *ptemp = (Situation_2_info*)malloc(sizeof(Situation_2_info));
	for (int i = 0; i < n; i++)
	{
		if (pptr->is_mid_station == true)
		{	
			Situation_2_info *temp = (Situation_2_info*)malloc(sizeof(Situation_2_info));
			temp->station = pptr;
			temp->pNext = NULL;
			if (header == NULL)
			{
				header = temp;
				ptemp = header;
			}		
			else
			{
				ptemp->pNext = temp;
				ptemp = ptemp->pNext;
			}
		}
		pptr = pptr->next;
	}
	return header;
}

int print_route_1(Station_info * bestation, const int n)
{
	tempStr = {};
	Station_info *p;
	int distance = 0;
	int a = 0;
	p = bestation;
	if (n < 0)
	{
		while (a>=n)
		{
			distance += p->pre_distance;
			if (n == a)
			{
				if (tempStr == NULL)
				{
					tempStr = p->station_name;
				}
				else
				{
					char *sTemp = tempStr;
					tempStr = (char*)malloc(strlen(tempStr) + strlen(p->station_name));
					sprintf(tempStr, "%s->%s", sTemp, p->station_name);
				}
			}
			else
			{
				if (tempStr == NULL)
				{
					tempStr = p->station_name;
				}
				else
				{
					char *sTemp = tempStr;
					tempStr = (char*)malloc(strlen(tempStr) + strlen(p->station_name));
					sprintf(tempStr, "%s->%s", sTemp, p->station_name);
				}
			}
			p = p->prev;
			a--;
		}
	}
	else if (n > 0)
	{
		while (a<=n)
		{
			distance += p->pre_distance;
			if (n == a)
			{
				if (tempStr == NULL)
				{
					tempStr = p->station_name;
				}
				else
				{
					char *sTemp = tempStr;
					tempStr = (char*)malloc(strlen(tempStr) + strlen(p->station_name));
					sprintf(tempStr, "%s->%s", sTemp, p->station_name);
				}
			}
			else
			{
				if (tempStr == NULL)
				{
					tempStr = p->station_name;
				}
				else
				{
					char *sTemp = tempStr;
					tempStr = (char*)malloc(strlen(tempStr) + strlen(p->station_name));
					sprintf(tempStr, "%s->%s", sTemp, p->station_name);
				}
			}
			p = p->next;
			a++;
		}
	}
	return distance;
}

int loadData()
{
	head_1 = creat_link1();
	head_2 = creat_link2();
	head_3 = creat_link3();
	head_4 = creat_link4();
	head_5 = creat_link5();
	head_7 = creat_link7();
	head_9 = creat_link9();
	head_11 = creat_link11();
	return 0;
}


Station_info *creat_link1()
{
	srand(time(NULL));
	Station_info *head,  * node;
	head = (Station_info*)malloc(sizeof(Station_info));
	node = (Station_info*)malloc(sizeof(Station_info));
	//end = head;
	int n = 0;
	do {
		node= (Station_info*)malloc(sizeof(Station_info));
		node->nex_distance = (rand() % 4 +2.0)*0.5;
		node->route_number = 1;
		node->station_number = n;
		strcpy_s(node->station_name, strlen(station_name_data_1[n])+1,station_name_data_1[n]);
		node->prev = NULL;
		node->next = NULL;
		if ( n == 0 )
		{
			head = node;
			head->pre_distance = 0;
			n++;
		}
		else
		{
			Station_info  *end=head;
			while(NULL!=end->next)
			{
				end = end->next;
			}
			node->pre_distance = end->nex_distance;
			node->prev = end;
			end->next = node;
			n++;
		}
		//printf("%s  %d  %d  %d\n", node->station_name, node->station_number, node->pre_distance,node->nex_distance);
	} while (strcmp(station_name_data_1[n-1], "罗湖") != 0);
	len_1 = n;
	head->prev = nullptr;
	//end->next = nullptr;
	return head;
};

Station_info *creat_link2()
{
	srand(time(NULL));
	Station_info *head, *node;
	head = (Station_info*)malloc(sizeof(Station_info));
	node = (Station_info*)malloc(sizeof(Station_info));
	//end = head;
	int n = 0;
	do {
		node = (Station_info*)malloc(sizeof(Station_info));
		node->nex_distance = (rand() % 3 + 2.0)*0.5;
		node->route_number = 2;
		node->station_number = n;
		strcpy_s(node->station_name, strlen(station_name_data_2[n]) + 1, station_name_data_2[n]);
		node->prev = NULL;
		node->next = NULL;
		if (n == 0)
		{
			head = node;
			head->pre_distance = 0;
			n++;
		}
		else
		{
			Station_info  *end = head;
			while (NULL != end->next)
			{
				end = end->next;
			}
			node->pre_distance = end->nex_distance;
			node->prev = end;
			end->next = node;
			n++;
		}
		//printf("%s  %d  %d  %d\n", node->station_name, node->station_number, node->pre_distance, node->nex_distance);
	} while (strcmp(station_name_data_2[n-1], "新秀") != 0);
	len_2 = n;
	head->prev = nullptr;
	//end->next = nullptr;
	return head;
};

Station_info *creat_link3()
{
	srand(time(NULL));
	Station_info *head, *node;
	head = (Station_info*)malloc(sizeof(Station_info));
	node = (Station_info*)malloc(sizeof(Station_info));
	//end = head;
	int n = 0;
	do {
		node = (Station_info*)malloc(sizeof(Station_info));
		node->nex_distance = (rand() % 4 + 2.0)*0.5;
		node->route_number = 3;
		node->station_number = n;
		strcpy_s(node->station_name, strlen(station_name_data_3[n]) + 1, station_name_data_3[n]);
		node->prev = NULL;
		node->next = NULL;
		if (n == 0)
		{
			head = node;
			head->pre_distance = 0;
			n++;
		}
		else
		{
			Station_info  *end = head;
			while (NULL != end->next)
			{
				end = end->next;
			}
			node->pre_distance = end->nex_distance;
			node->prev = end;
			end->next = node;
			n++;
		}
		//printf("%s  %d  %d  %d\n", node->station_name, node->station_number, node->pre_distance, node->nex_distance);
	} while (strcmp(station_name_data_3[n-1], "双龙") != 0);
	len_3 = n;
	head->prev = nullptr;
	//end->next = nullptr;
	return head;
};

Station_info *creat_link4()
{
	srand(time(NULL));
	Station_info *head, *node;
	head = (Station_info*)malloc(sizeof(Station_info));
	node = (Station_info*)malloc(sizeof(Station_info));
	//end = head;
	int n = 0;
	do {
		node = (Station_info*)malloc(sizeof(Station_info));
		node->nex_distance = (rand() % 3 + 2.0)*0.5;
		node->route_number = 4;
		node->station_number = n;
		strcpy_s(node->station_name, strlen(station_name_data_4[n]) + 1, station_name_data_4[n]);
		node->prev = NULL;
		node->next = NULL;
		if (n == 0)
		{
			head = node;
			head->pre_distance = 0;
			n++;
		}
		else
		{
			Station_info  *end = head;
			while (NULL != end->next)
			{
				end = end->next;
			}
			node->pre_distance = end->nex_distance;
			node->prev = end;
			end->next = node;
			n++;
		}
		//printf("%s  %d  %d  %d\n", node->station_name, node->station_number, node->pre_distance, node->nex_distance);
	} while (strcmp(station_name_data_4[n - 1], "清湖") != 0);
	len_4 = n;
	head->prev = nullptr;
	//end->next = nullptr;
	return head;
};

Station_info *creat_link5()
{
	srand(time(NULL));
	Station_info *head, *node;
	head = (Station_info*)malloc(sizeof(Station_info));
	node = (Station_info*)malloc(sizeof(Station_info));
	//end = head;
	int n = 0;
	do {
		node = (Station_info*)malloc(sizeof(Station_info));
		node->nex_distance = (rand() % 2 + 2.0)*0.5;
		node->route_number = 5;
		node->station_number = n;
		strcpy_s(node->station_name, strlen(station_name_data_5[n]) + 1, station_name_data_5[n]);
		node->prev = NULL;
		node->next = NULL;
		if (n == 0)
		{
			head = node;
			head->pre_distance = 0;
			n++;
		}
		else
		{
			Station_info  *end = head;
			while (NULL != end->next)
			{
				end = end->next;
			}
			node->pre_distance = end->nex_distance;
			node->prev = end;
			end->next = node;
			n++;
		}
		//printf("%s  %d  %d  %d\n", node->station_name, node->station_number, node->pre_distance, node->nex_distance);
	} while (strcmp(station_name_data_5[n - 1], "黄贝岭") != 0);
	len_5 = n;
	head->prev = nullptr;
	//end->next = nullptr;
	return head;
};

Station_info *creat_link7()
{
	srand(time(NULL));
	Station_info *head, *node;
	head = (Station_info*)malloc(sizeof(Station_info));
	node = (Station_info*)malloc(sizeof(Station_info));
	//end = head;
	int n = 0;
	do {
		node = (Station_info*)malloc(sizeof(Station_info));
		node->nex_distance = (rand() % 4 + 2.0)*0.5;
		node->route_number = 7;
		node->station_number = n;
		strcpy_s(node->station_name, strlen(station_name_data_7[n]) + 1, station_name_data_7[n]);
		node->prev = NULL;
		node->next = NULL;
		if (n == 0)
		{
			head = node;
			head->pre_distance = 0;
			n++;
		}
		else
		{
			Station_info  *end = head;
			while (NULL != end->next)
			{
				end = end->next;
			}
			node->pre_distance = end->nex_distance;
			node->prev = end;
			end->next = node;
			n++;
		}
		//printf("%s  %d  %d  %d\n", node->station_name, node->station_number, node->pre_distance, node->nex_distance);
	} while (strcmp(station_name_data_7[n - 1], "西丽湖") != 0);
	len_7 = n;
	head->prev = nullptr;
	//end->next = nullptr;
	return head;
};

Station_info *creat_link9()
{
	srand(time(NULL));
	Station_info *head, *node;
	head = (Station_info*)malloc(sizeof(Station_info));
	node = (Station_info*)malloc(sizeof(Station_info));
	//end = head;
	int n = 0;
	do {
		node = (Station_info*)malloc(sizeof(Station_info));
		node->nex_distance = (rand() % 3 + 2.0)*0.5;
		node->route_number = 9;
		node->station_number = n;
		strcpy_s(node->station_name, strlen(station_name_data_9[n]) + 1, station_name_data_9[n]);
		node->prev = NULL;
		node->next = NULL;
		if (n == 0)
		{
			head = node;
			head->pre_distance = 0;
			n++;
		}
		else
		{
			Station_info  *end = head;
			while (NULL != end->next)
			{
				end = end->next;
			}
			node->pre_distance = end->nex_distance;
			node->prev = end;
			end->next = node;
			n++;
		}
		//printf("%s  %d  %d  %d\n", node->station_name, node->station_number, node->pre_distance, node->nex_distance);
	} while (strcmp(station_name_data_9[n - 1], "文锦") != 0);
	len_9 = n;
	head->prev = nullptr;
	//end->next = nullptr;
	return head;
};

Station_info *creat_link11()
{
	srand(time(NULL));
	Station_info *head, *node;
	head = (Station_info*)malloc(sizeof(Station_info));
	node = (Station_info*)malloc(sizeof(Station_info));
	//end = head;
	int n = 0;
	do {
		node = (Station_info*)malloc(sizeof(Station_info));
		node->nex_distance = (rand() % 4 + 2.0)*0.5;
		node->route_number = 11;
		node->station_number = n;
		strcpy_s(node->station_name, strlen(station_name_data_11[n]) + 1, station_name_data_11[n]);
		node->prev = NULL;
		node->next = NULL;
		if (n == 0)
		{
			head = node;
			head->pre_distance = 0;
			n++;
		}
		else
		{
			Station_info  *end = head;
			while (NULL != end->next)
			{
				end = end->next;
			}
			node->pre_distance = end->nex_distance;
			node->prev = end;
			end->next = node;
			n++;
		}
		//printf("%s  %d  %d  %d\n", node->station_name, node->station_number, node->pre_distance, node->nex_distance);
	} while (strcmp(station_name_data_11[n - 1], "碧头") != 0);
	len_11 = n;
	head->prev = nullptr;
	//end->next = nullptr;
	return head;
};

int DelList(Station_info *pTemp)
{
	Station_info *pPtr = (Station_info*)malloc(sizeof(Station_info));
	while (pPtr != nullptr)
	{
		pPtr = pTemp->next;
	}
	return 0;
}

int DelAllList()
{
	DelList(head_1);
	DelList(head_2);
	DelList(head_3);
	DelList(head_4);
	DelList(head_5);
	DelList(head_7);
	DelList(head_9);
	DelList(head_11);
	return 0;
}

Station_info *check_one_List(int len, Station_info *head, const char *station_name)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		//printf("   *%-8s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->route_number,
		//	p->station_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]); 
		if (strcmp(p->station_name, station_name) == 0)
		{
			break;
		}
		else
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return p;
}

Station_info *check_all_List_for_one_name(const char *station_name)
{
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p=check_one_List(len_1, head_1, station_name);
	if(p!=nullptr)
	{
		return p;
	}
	p=check_one_List(len_2, head_2, station_name);
	if (p != nullptr)
	{
		return p;
	}
	p=check_one_List(len_3, head_3, station_name);
	if (p != nullptr)
	{
		return p;
	}
	p=check_one_List(len_4, head_4, station_name);
	if (p != nullptr)
	{
		return p;
	}
	p=check_one_List(len_5, head_5, station_name);
	if (p != nullptr)
	{
		return p;
	}
	p=check_one_List(len_7, head_7, station_name);
	if (p != nullptr)
	{
		return p;
	}
	p=check_one_List(len_9, head_9, station_name);
	if (p != nullptr)
	{
		return p;
	}
	p=check_one_List(len_11, head_11, station_name);
	if (p != nullptr)
	{
		return p;
	}
	printf("无此站点，请重新输入：");
	return p;
}

Station_info *check_List_by_num_nam( Station_info *in_station, char *pPtr)
{
	Station_info *firststation = (Station_info*)malloc(sizeof(Station_info));
	//找出中转站在起始站所在链表的地址
	if (in_station->route_number == 1)
	{
		firststation = check_one_List(len_1, head_1, pPtr);
	}
	else if (in_station->route_number == 2)
	{
		firststation = check_one_List(len_2, head_2, pPtr);
	}
	else if (in_station->route_number == 3)
	{
		firststation = check_one_List(len_3, head_3, pPtr);
	}
	else if (in_station->route_number == 4)
	{
		firststation = check_one_List(len_4, head_4, pPtr);
	}
	else if (in_station->route_number == 5)
	{
		firststation = check_one_List(len_5, head_5, pPtr);
	}
	else if (in_station->route_number == 7)
	{
		firststation = check_one_List(len_7, head_7, pPtr);
	}
	else if (in_station->route_number == 9)
	{
		firststation = check_one_List(len_9, head_9, pPtr);
	}
	else if (in_station->route_number == 11)
	{
		firststation = check_one_List(len_11, head_11, pPtr);
	}
	return firststation;
}

List_info *load_sta_Data()
{
	const char* firstname = { "宝安中心" };
	BaoanCenter(len_1, head_1, firstname);
	BaoanCenter(len_2, head_2, firstname);
	BaoanCenter(len_3, head_3, firstname);
	BaoanCenter(len_4, head_4, firstname);
	BaoanCenter(len_5, head_5, firstname);
	BaoanCenter(len_7, head_7, firstname);
	BaoanCenter(len_9, head_9, firstname);
	BaoanCenter(len_11, head_11, firstname);
	const char *secondname = { "前海湾" };
	QianHaiWan(len_1, head_1, secondname);
	QianHaiWan(len_2, head_2, secondname);
	QianHaiWan(len_3, head_3, secondname);
	QianHaiWan(len_4, head_4, secondname);
	QianHaiWan(len_5, head_5, secondname);
	QianHaiWan(len_7, head_7, secondname);
	QianHaiWan(len_9, head_9, secondname);
	QianHaiWan(len_11, head_11, secondname);
	const char *thirdname = { "世界之窗" };
	ShijieZhichuan(len_1, head_1, thirdname);
	ShijieZhichuan(len_2, head_2, thirdname);
	ShijieZhichuan(len_3, head_3, thirdname);
	ShijieZhichuan(len_4, head_4, thirdname);
	ShijieZhichuan(len_5, head_5, thirdname);
	ShijieZhichuan(len_7, head_7, thirdname);
	ShijieZhichuan(len_9, head_9, thirdname);
	ShijieZhichuan(len_11, head_11, thirdname);
	const char *fourthname = { "车公庙" };
	ChegongMiao(len_1, head_1, fourthname);
	ChegongMiao(len_2, head_2, fourthname);
	ChegongMiao(len_3, head_3, fourthname);
	ChegongMiao(len_4, head_4, fourthname);
	ChegongMiao(len_5, head_5, fourthname);
	ChegongMiao(len_7, head_7, fourthname);
	ChegongMiao(len_9, head_9, fourthname);
	ChegongMiao(len_11, head_11, fourthname);
	const char *fifthname = { "购物公园" };
	ShopPark(len_1, head_1, fifthname);
	ShopPark(len_2, head_2, fifthname);
	ShopPark(len_3, head_3, fifthname);
	ShopPark(len_4, head_4, fifthname);
	ShopPark(len_5, head_5, fifthname);
	ShopPark(len_7, head_7, fifthname);
	ShopPark(len_9, head_9, fifthname);
	ShopPark(len_11, head_11, fifthname);
	const char *sixthname = { "会展中心" };
	HuizhanCenter(len_1, head_1, sixthname);
	HuizhanCenter(len_2, head_2, sixthname);
	HuizhanCenter(len_3, head_3, sixthname);
	HuizhanCenter(len_4, head_4, sixthname);
	HuizhanCenter(len_5, head_5, sixthname);
	HuizhanCenter(len_7, head_7, sixthname);
	HuizhanCenter(len_9, head_9, sixthname);
	HuizhanCenter(len_11, head_11, sixthname);
	const char *seventhname = { "大剧院" };
	DaJuYuan(len_1, head_1, seventhname);
	DaJuYuan(len_2, head_2, seventhname);
	DaJuYuan(len_3, head_3, seventhname);
	DaJuYuan(len_4, head_4, seventhname);
	DaJuYuan(len_5, head_5, seventhname);
	DaJuYuan(len_7, head_7, seventhname);
	DaJuYuan(len_9, head_9, seventhname);
	DaJuYuan(len_11, head_11, seventhname);
	const char *eighthname = { "老街" };
	LaoJie(len_1, head_1, eighthname);
	LaoJie(len_2, head_2, eighthname);
	LaoJie(len_3, head_3, eighthname);
	LaoJie(len_4, head_4, eighthname);
	LaoJie(len_5, head_5, eighthname);
	LaoJie(len_7, head_7, eighthname);
	LaoJie(len_9, head_9, eighthname);
	LaoJie(len_11, head_11, eighthname);
	const char *ninthname = { "赤湾" };
	ChiWan(len_1, head_1, ninthname);
	ChiWan(len_2, head_2, ninthname);
	ChiWan(len_3, head_3, ninthname);
	ChiWan(len_4, head_4, ninthname);
	ChiWan(len_5, head_5, ninthname);
	ChiWan(len_7, head_7, ninthname);
	ChiWan(len_9, head_9, ninthname);
	ChiWan(len_11, head_11, ninthname);
	const char *tenthname = { "安托山" };
	AntuoShan(len_1, head_1, tenthname);
	AntuoShan(len_2, head_2, tenthname);
	AntuoShan(len_3, head_3, tenthname);
	AntuoShan(len_4, head_4, tenthname);
	AntuoShan(len_5, head_5, tenthname);
	AntuoShan(len_7, head_7, tenthname);
	AntuoShan(len_9, head_9, tenthname);
	AntuoShan(len_11, head_11, tenthname);
	const char *eleventhname = { "景田" };
	JingTian(len_1, head_1, eleventhname);
	JingTian(len_2, head_2, eleventhname);
	JingTian(len_3, head_3, eleventhname);
	JingTian(len_4, head_4, eleventhname);
	JingTian(len_5, head_5, eleventhname);
	JingTian(len_7, head_7, eleventhname);
	JingTian(len_9, head_9, eleventhname);
	JingTian(len_11, head_11, eleventhname);
	const char *twelfthname = { "福田" };
	FuTian(len_1, head_1, twelfthname);
	FuTian(len_2, head_2, twelfthname);
	FuTian(len_3, head_3, twelfthname);
	FuTian(len_4, head_4, twelfthname);
	FuTian(len_5, head_5, twelfthname);
	FuTian(len_7, head_7, twelfthname);
	FuTian(len_9, head_9, twelfthname);
	FuTian(len_11, head_11, twelfthname);
	const char *thirteenthname = { "市民中心" };
	ShiminCenter(len_1, head_1, thirteenthname);
	ShiminCenter(len_2, head_2, thirteenthname);
	ShiminCenter(len_3, head_3, thirteenthname);
	ShiminCenter(len_4, head_4, thirteenthname);
	ShiminCenter(len_5, head_5, thirteenthname);
	ShiminCenter(len_7, head_7, thirteenthname);
	ShiminCenter(len_9, head_9, thirteenthname);
	ShiminCenter(len_11, head_11, thirteenthname);
	const char *fourteenthname = { "华强北" };
	HuaQiangBei(len_1, head_1, fourteenthname);
	HuaQiangBei(len_2, head_2, fourteenthname);
	HuaQiangBei(len_3, head_3, fourteenthname);
	HuaQiangBei(len_4, head_4, fourteenthname);
	HuaQiangBei(len_5, head_5, fourteenthname);
	HuaQiangBei(len_7, head_7, fourteenthname);
	HuaQiangBei(len_9, head_9, fourteenthname);
	HuaQiangBei(len_11, head_11, fourteenthname);
	const char *fifteenthname = { "黄贝岭" };
	HuangbeiLing(len_1, head_1, fifteenthname);
	HuangbeiLing(len_2, head_2, fifteenthname);
	HuangbeiLing(len_3, head_3, fifteenthname);
	HuangbeiLing(len_4, head_4, fifteenthname);
	HuangbeiLing(len_5, head_5, fifteenthname);
	HuangbeiLing(len_7, head_7, fifteenthname);
	HuangbeiLing(len_9, head_9, fifteenthname);
	HuangbeiLing(len_11, head_11, fifteenthname);
	const char *sixteenthname = { "石厦" };
	Shisha(len_1, head_1, sixteenthname);
	Shisha(len_2, head_2, sixteenthname);
	Shisha(len_3, head_3, sixteenthname);
	Shisha(len_4, head_4, sixteenthname);
	Shisha(len_5, head_5, sixteenthname);
	Shisha(len_7, head_7, sixteenthname);
	Shisha(len_9, head_9, sixteenthname);
	Shisha(len_11, head_11, sixteenthname);
	const char *seventeenthname = { "少年宫" };
	ShaonianGong(len_1, head_1, seventeenthname);
	ShaonianGong(len_2, head_2, seventeenthname);
	ShaonianGong(len_3, head_3, seventeenthname);
	ShaonianGong(len_4, head_4, seventeenthname);
	ShaonianGong(len_5, head_5, seventeenthname);
	ShaonianGong(len_7, head_7, seventeenthname);
	ShaonianGong(len_9, head_9, seventeenthname);
	ShaonianGong(len_11, head_11, seventeenthname);
	const char *eighteenthname = { "华新" };
	Huaxin(len_1, head_1, eighteenthname);
	Huaxin(len_2, head_1, eighteenthname);
	Huaxin(len_3, head_3, eighteenthname);
	Huaxin(len_4, head_4, eighteenthname);
	Huaxin(len_5, head_5, eighteenthname);
	Huaxin(len_7, head_7, eighteenthname);
	Huaxin(len_9, head_9, eighteenthname);
	Huaxin(len_11, head_11, eighteenthname);
	const char *nineteenthname = { "田贝" };
	Tianbei(len_1, head_1, nineteenthname);
	Tianbei(len_2, head_2, nineteenthname);
	Tianbei(len_3, head_3, nineteenthname);
	Tianbei(len_4, head_4, nineteenthname);
	Tianbei(len_5, head_5, nineteenthname);
	Tianbei(len_7, head_7, nineteenthname);
	Tianbei(len_9, head_9, nineteenthname);
	Tianbei(len_11, head_11, nineteenthname);
	const char *twentiethname = { "布吉" };
	Buji(len_1, head_1, twentiethname);
	Buji(len_2, head_2, twentiethname);
	Buji(len_3, head_3, twentiethname);
	Buji(len_4, head_4, twentiethname);
	Buji(len_5, head_5, twentiethname);
	Buji(len_7, head_7, twentiethname);
	Buji(len_9, head_9, twentiethname);
	Buji(len_11, head_11, twentiethname);
	const char *twe_firstname = { "福民" };
	Fumin(len_1, head_1, twe_firstname);
	Fumin(len_2, head_2, twe_firstname);
	Fumin(len_3, head_3, twe_firstname);
	Fumin(len_4, head_4, twe_firstname);
	Fumin(len_5, head_5, twe_firstname);
	Fumin(len_7, head_7, twe_firstname);
	Fumin(len_9, head_9, twe_firstname);
	Fumin(len_11, head_11, twe_firstname);
	const char *twe_secondname = { "上梅林" };
	ShangmeiLin(len_1, head_1, twe_secondname);
	ShangmeiLin(len_2, head_2, twe_secondname);
	ShangmeiLin(len_3, head_3, twe_secondname);
	ShangmeiLin(len_4, head_4, twe_secondname);
	ShangmeiLin(len_5, head_5, twe_secondname);
	ShangmeiLin(len_7, head_7, twe_secondname);
	ShangmeiLin(len_9, head_9, twe_secondname);
	ShangmeiLin(len_11, head_11, twe_secondname);
	const char *twe_thirdname = { "深圳北站" };
	ShenzhenBei(len_1, head_1, twe_thirdname);
	ShenzhenBei(len_2, head_2, twe_thirdname);
	ShenzhenBei(len_3, head_3, twe_thirdname);
	ShenzhenBei(len_4, head_4, twe_thirdname);
	ShenzhenBei(len_5, head_5, twe_thirdname);
	ShenzhenBei(len_7, head_7, twe_thirdname);
	ShenzhenBei(len_9, head_9, twe_thirdname);
	ShenzhenBei(len_11, head_11, twe_thirdname);
	const char *twe_fourname = { "前湾" };
	Qianwan(len_1, head_1, twe_fourname);
	Qianwan(len_2, head_2, twe_fourname);
	Qianwan(len_3, head_3, twe_fourname);
	Qianwan(len_4, head_4, twe_fourname);
	Qianwan(len_5, head_5, twe_fourname);
	Qianwan(len_7, head_7, twe_fourname);
	Qianwan(len_9, head_9, twe_fourname);
	Qianwan(len_11, head_11, twe_fourname);
	const char *twe_fifthname = { "西丽" };
	Xili(len_1, head_1, twe_fifthname);
	Xili(len_2, head_2, twe_fifthname);
	Xili(len_3, head_3, twe_fifthname);
	Xili(len_4, head_4, twe_fifthname);
	Xili(len_5, head_5, twe_fifthname);
	Xili(len_7, head_7, twe_fifthname);
	Xili(len_9, head_9, twe_fifthname);
	Xili(len_11, head_11, twe_fifthname);
	const char *twe_sixthname = { "太安" };
	Taian(len_1, head_1, twe_sixthname);
	Taian(len_2, head_2, twe_sixthname);
	Taian(len_3, head_3, twe_sixthname);
	Taian(len_4, head_4, twe_sixthname);
	Taian(len_5, head_5, twe_sixthname);
	Taian(len_7, head_7, twe_sixthname);
	Taian(len_9, head_9, twe_sixthname);
	Taian(len_11, head_11, twe_sixthname);
	const char *twe_seventhname = { "红岭北" };
	Honglingbei(len_1, head_1, twe_seventhname);
	Honglingbei(len_2, head_2, twe_seventhname);
	Honglingbei(len_3, head_3, twe_seventhname);
	Honglingbei(len_4, head_4, twe_seventhname);
	Honglingbei(len_5, head_5, twe_seventhname);
	Honglingbei(len_7, head_7, twe_seventhname);
	Honglingbei(len_9, head_9, twe_seventhname);
	Honglingbei(len_11, head_11, twe_seventhname);
	const char *twe_eighthname = { "红树湾南" };
	HongshuwanNan(len_1, head_1, twe_eighthname);
	HongshuwanNan(len_2, head_2, twe_eighthname);
	HongshuwanNan(len_3, head_3, twe_eighthname);
	HongshuwanNan(len_4, head_4, twe_eighthname);
	HongshuwanNan(len_5, head_5, twe_eighthname);
	HongshuwanNan(len_7, head_7, twe_eighthname);
	HongshuwanNan(len_9, head_9, twe_eighthname);
	HongshuwanNan(len_11, head_11, twe_eighthname);
	const char *twe_ninthname = { "红岭" };
	Hongling(len_1, head_1, twe_ninthname);
	Hongling(len_2, head_2, twe_ninthname);
	Hongling(len_3, head_3, twe_ninthname);
	Hongling(len_4, head_4, twe_ninthname);
	Hongling(len_5, head_5, twe_ninthname);
	Hongling(len_7, head_7, twe_ninthname);
	Hongling(len_9, head_9, twe_ninthname);
	Hongling(len_11, head_11, twe_ninthname);
	const char *thirtiethname = { "后海" };
	Houhai(len_1, head_1, thirtiethname);
	Houhai(len_2, head_2, thirtiethname);
	Houhai(len_3, head_3, thirtiethname);
	Houhai(len_4, head_4, thirtiethname);
	Houhai(len_5, head_5, thirtiethname);
	Houhai(len_7, head_7, thirtiethname);
	Houhai(len_9, head_9,thirtiethname);
	Houhai(len_11,head_11,thirtiethname);

	//将各个链表表头存储在另一链表中
	List_info *head = (List_info*)malloc(sizeof(List_info));
	head->head = head_1;
	List_info *two = (List_info*)malloc(sizeof(List_info));
	two->head = head_2;
	head->pNext = two;
	List_info *three = (List_info*)malloc(sizeof(List_info));
	three->head = head_3;
	two->pNext = three;
	List_info *four = (List_info*)malloc(sizeof(List_info));
	four->head = head_4;
	three->pNext = four;
	List_info *five = (List_info*)malloc(sizeof(List_info));
	five->head = head_5;
	four->pNext = five;
	List_info *seven = (List_info*)malloc(sizeof(List_info));
	seven->head = head_7;
	five->pNext = seven;
	List_info *nine = (List_info*)malloc(sizeof(List_info));
	nine->head = head_9;
	seven->pNext = nine;
	List_info *eleven = (List_info*)malloc(sizeof(List_info));
	eleven->head = head_11;
	nine->pNext = NULL;
	return head;
}

int BaoanCenter(int len, Station_info *head,const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 1;
			p->con_amount[1] = 5;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number, 
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int QianHaiWan(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 1;
			p->con_amount[1] = 5;
			p->con_amount[2] = 11;
			for (int i = 3; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int ShijieZhichuan(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 1;
			p->con_amount[1] = 2;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
			//p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int ChegongMiao(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 1;
			p->con_amount[1] = 7;
			p->con_amount[2] = 9;
			p->con_amount[3] = 11;
			for (int i = 4; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
			//p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2],p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int ShopPark(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 1;
			p->con_amount[1] = 3;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
			//p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int HuizhanCenter(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 1;
			p->con_amount[1] = 4;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
			//p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int DaJuYuan(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 1;
			p->con_amount[1] = 2;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
			//p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int LaoJie(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 1;
			p->con_amount[1] = 3;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
			//p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int ChiWan(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 2;
			p->con_amount[1] = 5;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
			//p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int AntuoShan(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 2;
			p->con_amount[1] = 7;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
			//p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int JingTian(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 2;
			p->con_amount[1] = 9;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
			//p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int FuTian(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 2;
			p->con_amount[1] = 3;
			p->con_amount[2] = 11;
			for (int i = 3; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int ShiminCenter(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 2;
			p->con_amount[1] = 4;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int HuaQiangBei(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 2;
			p->con_amount[1] = 7;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int HuangbeiLing(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 2;
			p->con_amount[1] = 5;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int Shisha(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 3;
			p->con_amount[1] = 7;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int ShaonianGong(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 3;
			p->con_amount[1] = 4;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int Huaxin(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 3;
			p->con_amount[1] = 7;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
			//p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int Tianbei(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 3;
			p->con_amount[1] = 7;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if(p->is_mid_station==true)
			{ }
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
			//p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int Buji(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 3;
			p->con_amount[1] = 5;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int Fumin(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 4;
			p->con_amount[1] = 7;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
			//p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int ShangmeiLin(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 4;
			p->con_amount[1] = 9;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int ShenzhenBei(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 4;
			p->con_amount[1] = 5;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int Qianwan(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 5;
			p->con_amount[1] = 9;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int Xili(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 5;
			p->con_amount[1] = 7;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int Taian(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 5;
			p->con_amount[1] = 7;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int Honglingbei(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 7;
			p->con_amount[1] = 9;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int HongshuwanNan(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 9;
			p->con_amount[1] = 11;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int Hongling(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 3;
			p->con_amount[1] = 9;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}

int Houhai(int len, Station_info *head, const char *firstname)
{
	int n = 0;
	Station_info *p = (Station_info*)malloc(sizeof(Station_info));
	p = head;
	do {
		if (strcmp(p->station_name, firstname) == 0)
		{
			p->is_mid_station = true;
			p->con_amount[0] = 2;
			p->con_amount[1] = 11;
			for (int i = 2; i <= 6; i++)
			{
				p->con_amount[i] = 0;
			}
		}
		else
		{
			if (p->is_mid_station == true)
			{
			}
			else
			{
				p->is_mid_station = false;
				for (int i = 0; i <= 6; i++)
				{
					p->con_amount[i] = 0;
				}
			}
		}
		//printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p->station_name, p->station_number,
		//	p->route_number, p->is_mid_station, p->con_amount[0], p->con_amount[1], p->con_amount[2], p->con_amount[3]);
		if (p->next != nullptr)
		{
			p = p->next;
		}
		n++;
	} while (n < len);
	return 0;
}