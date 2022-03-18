#ifndef DATA_H
#define DATA_H
#include<string>
#include<iostream>
using namespace std;
struct Good
{
	string g_id;
	string g_name;
	double g_price = 0;
	int g_number = 0;
	string g_info;
	string seller_id ;
	string g_time;
	string g_sta =  "onsale";//商品状态：onsale在售，removed下架
};

struct order
{
	string order_id ;
	string good_id;
	double good_price = 0;
	int good_nmuber = 0;
	string Trade_time;
	string seller_id;
	string buyer_id;
};
void goodxieru(int i);
void userxieru(int i);
void orderxieru(int i);
int goodchuanru();
int orderchuanru();
int userchuanru();
#endif
