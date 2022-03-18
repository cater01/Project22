#include<iostream>
#include"Buyers.h"
#include<string>
#include"Users.h"
#include"Administrator.h"
#include<fstream>
#include<assert.h>
#include"Data.h"
using namespace std;

extern struct Good good[10];
extern struct order order[10];
extern struct User user[10];


void Buyers::buyer_manu()//菜单
{
	cout << "=======================================================================================" << endl;
	cout << "1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.查看商品详细信息 6.返回用户主界面" << endl;
	cout << "=======================================================================================" << endl;
	cout << endl;
}
void Buyer_Moudle(int i)
{	
	Buyers liu;
	while (true)
	{
		liu.buyer_manu();
		cout << "请输入操作：";
		int opt;
		cin >> opt;
		cin.clear();
		cin.ignore(100, '\n');
		switch (opt)
		{
		case 1:liu.Buyer_checkgoods(); break;
		case 2:liu.Buying(i); break;
		case 3:liu.goodsearch(); break;
		case 4:liu.Buyer_checkorders(i); break;
		case 5:liu.one(); break;
		case 6:
		{
			cout << "返回主界面......" << endl;
			return;
		}
		default:cout << "输入错误，请重试:" << endl;
			; break;
		}
	}
}
void Buyers::Buyer_checkgoods()
{
	int i = goodchuanru();
	cout << "***************************************************" << endl;
	cout << "商品ID   名称    价格    数量     上架时间     卖家ID" << endl;
	for (int j = 0; j < i; j++)
	{
		if (good[j].g_sta == "onsale")
		{
			cout << good[j].g_id << " " << good[j].g_name << " " << good[j].g_price << " "
				<< good[j].g_number << "  " << good[j].g_time << " " << good[j].seller_id << endl;
		}
	}
	cout << "***************************************************" << endl;
}
void Buyers::goodsearch()
{
	int i = goodchuanru();
	cout << "请输入商品名称：" ;
	string g_name1;
	cin >> g_name1;
	while (g_name1.length() > 20)
	{
		cout << "商品名称有误，请检查输入是否正确！" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> g_name1;
	}
	int count = 0;
	for (int j = 0; j < i; j++)
	{

		if (g_name1 == good[j].g_name&&good[j].g_sta!="removed")
		{
			cout << "商品ID   商品名称   商品价格  商品数量   上架时间    卖家ID " << endl;
			cout << good[j].g_id << " " << good[j].g_name << " " << good[j].g_price << 
				" " << good[j].g_number <<"  " << good[j].g_time << " "<< good[j].seller_id <<  endl;
			count++;
		}
	}
	if (count == 0)
	{
		cout << "**********************************" << endl;
		cout << "没有找到您想要的商品，返回初始界面" << endl;
		cout << "**********************************" << endl;
		cout << endl;
	}
}
void Buyers::Buyer_checkorders(int i)
{
	int a = orderchuanru();
	cout << "*******************************************************" << endl;
	cout << "订单ID  商品ID   交易单价    数量    交易时间    卖家ID" << endl;
	for (int j = 0; j < a; j++)
	{
		if (order[j].buyer_id == user[i].u_id)
		{
			cout << order[j].order_id << "   " << order[j].good_id << "   " << order[j].good_price
				<< "   " << order[j].good_nmuber << "   " << order[j].Trade_time << "   " << order[j].seller_id
				<< endl;
		}
	}
	cout << "********************************************************" << endl;
}
void Buyers::Buying(int i)
{
	cout << "请输入商品ID:" ;
	string id;
	cin >> id;
	while (id.length() > 5)
	{
		cout << "商品名称格式错误，请重新输入：";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> id;
	}
	int a = goodchuanru();
	int c = userchuanru();
	int d = orderchuanru();
	int count = 0, j;
	
	for (j = 0; j < a; j++)
	{
		if (good[j].g_id == id&&good[j].g_sta=="onsale"&&good[j].seller_id!=user[i].u_id)
		{
			count++; break;
		}
	}
	if (count == 0)
	{
		cout << "**********************************" << endl;
		cout << "没有找到您想要的商品，返回初始界面" << endl;
		cout << "**********************************" << endl;
		cout << endl;
	}
	else
	{
		cout << "请输入数量：";
		int num;
		cin >> num;
		while (num > good[j].g_number)
		{
			cout << "商品数量不足，请重新输入购买数量：";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> num;
		}
		while (user[i].u_balance < num * good[j].g_price)
		{
			cout << "您的余额不足，请重新输入购买数量：";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> num;
		}
		good[j].g_number = good[j].g_number - num;
		user[i].u_balance = user[i].u_balance - num * good[j].g_price;
		if (good[j].g_number == 0)
		{
			good[j].g_sta = "removed";
		}
		goodxieru(a);
		userxieru(c);
		time_t t = time(0);
		char ch[64];
		strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
		cout << "交易提醒！" << endl;
		cout << "交易时间：" << ch<< endl;
		cout << "交易单价:" << good[j].g_price << endl;
		cout << "交易数量:" << num << endl;
		cout << "交易成功!" << endl;	
		cout << "您的余额:" << user[i].u_balance << endl;
		order[d].order_id = "T" + zhuan(d+1);
		order[d].buyer_id = user[i].u_id;
		order[d].good_id = good[j].g_id;
		order[d].good_price = good[j].g_price;
		order[d].good_nmuber = num;
		order[d].seller_id = good[j].seller_id;
		for (int g = 0; ch[g] != '\0'; g++)
		{
			order[d].Trade_time += ch[g];
		}
		orderxieru(d);
		return;
	}
}
void Buyers::one()
{
	string tempid;
	cout << "请输入想要查看的商品ID：";
	cin >> tempid;
	int i = goodchuanru(), j = 0;
	for (j = 0; j < i; j++)
	{
		if (tempid == good[j].g_id)
		{
			cout << "*******************************" << endl;
			cout << "商品ID： " << good[j].g_id << endl;
			cout << "商品名称： " << good[j].g_name << endl;
			cout << "商品价格： " << good[j].g_price << endl;
			cout << "上架时间： " << good[j].g_time << endl;
			cout << "商品描述： " << good[j].g_info << endl;
			cout << "商品卖家： " << good[j].seller_id << endl;
			cout << "*******************************" << endl;
		}
	}
}
