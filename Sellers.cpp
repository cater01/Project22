#include<iostream>
#include"Sellers.h"
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

void Sellers::Seller_manu()
{
	cout << "====================================================================================" << endl;
	cout << "1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.返回用户主界面" << endl;
	cout << "====================================================================================" << endl;
	cout << endl;
}
void Seller_Moudle(int i)
{
	Sellers liu;
	while (true)
	{
		liu.Seller_manu();
		cout << endl;
		cout << "请输入操作：";
		int opt;
		cin >> opt;
		cin.clear();
		cin.ignore(100, '\n');
		switch (opt)
		{
		case 1:liu.Selling(i); break;
		case 2:liu.Seller_checkgoods(i); break;
		case 3:liu.Modify_good(i); break;
		case 4:liu.Deselling(i); break;
		case 5:liu.Seller_checkorders(i); break;
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
void Sellers::Selling(int i)
{
	cout << "请输入商品名称：";
	string tempname;
	cin >> tempname;
	while (tempname.length() > 20)
	{
		cout << "名称过长，请重新输入：";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> tempname;
	}
	double tempprice;
	cout << "请输入商品价格：";
	cin >> tempprice;
	while (tempprice == 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "格式错误！请重新输入商品价格：";
		cin >> tempprice;
	}
	int tempnum;
	cout << "请输入商品数量：";
	cin >> tempnum;
	while (tempnum == 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "格式错误！请重新输入商品数量：";
		cin >> tempnum;
	}
	string tempin;
	cout << "请输入商品描述：";
	cin >> tempin;
	while (tempin.length() > 40)
	{
		cout << "描述过长，请重新输入：";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> tempin;
	}
	cout << endl;
	cout << "请确认发布的商品信息无误！" << endl;
	cout << "****************************" << endl;
	cout <<"商品名称： "<<tempname << endl;
	cout << "商品价格： " <<tempprice<< endl;
	cout << "商品数量： "<<tempnum << endl;
	cout << "商品描述： " <<tempin<< endl;
	cout << "****************************" << endl;
	cout << endl;
	cout << "您确定要发布商品吗？（y/n）";
	string ch;
	cin >> ch;
	if (ch =="n")
	{
		cout << "您已取消发布" << endl;
		return;
	}
	else if (ch == "y")
	{
		int a = goodchuanru();
		good[a].g_info = tempin;
		good[a].g_price = tempprice;
		good[a].seller_id = user[i].u_id;
		good[a].g_number = tempnum;
		good[a].g_name = tempname;
		good[a].g_id = "M" + zhuan(a + 1);
		time_t t = time(0);
		char ch[64];
		strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
		for (int g = 0; ch[g] != '\0'; g++)
		{
			good[a].g_time += ch[g];
		}
		goodxieru(a + 1);
		fstream infile("commands.txt", ios::app);
		infile << ch << "INSERT INTO commodity VALUES  " <<good[a].g_name<<good[a].g_price<<good[a].g_number<<good[a].g_info  << endl;
		infile.close();

		cout << "发布商品成功！" << endl;
		cout << endl;
		return;
	}
	else
	{
		cout << "输入错误，即将返回菜单......." << endl;
		return;
	}
}
void Sellers::Seller_checkgoods(int i)
{
	int a = goodchuanru();
	cout << "*****************************************************" << endl;
	cout << "商品ID   名称   价格   数量   上架时间     商品状态" << endl;
	for (int j = 0; j < a; j++)
	{
		if (user[i].u_id == good[j].seller_id)
		{
			cout << good[j].g_id << "   " << good[j].g_name << "   " << good[j].g_price <<
				"   " << good[j].g_number << "   " << good[j].g_time << "   " << good[j].g_sta << endl;
		}
	}
	fstream infile("commands.txt", ios::app);
	time_t t = time(0);
	char ch[64];
	strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
	infile << ch << " SELECT * FROM commodity" << endl;
	infile.close();
	cout << "*****************************************************" << endl;
	return;
}
void Sellers::Modify_good(int i)
{
	cout << "请输入被修改的商品ID： ";
	string id;
	cin >> id;
	int a = goodchuanru(), count = 0;
	int j = 0;
	for ( j = 0; j < a; j++)
	{
		if(good[j].g_id==id&&good[j].seller_id==user[i].u_id)
		{	
			count++;
			break;
		}
	}
	if (count == 0)
	{
		cout << "未查询到该商品" << endl;
		return;
	}
	cout << "请输入被修改的商品属性（1.价格 2.描述）： ";
	int b = 0;
	cin >> b;
	while (b!=1&&b!=2)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "输入错误，请重新输入：";
		cin >> b;
	}
	if (b == 1)
	{
		cout << "请输入被修改的商品价格： ";
		double p;
		cin >> p;
		while (p == 0)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "输入错误，请重新输入：";
			cin >> p;
		}
		cout << "请确认修改的商品信息无误！ " << endl;
		cout << "*************************************" << endl;
		cout << "商品ID： " << good[j].g_id << endl;
		cout << "商品名称： " << good[j].g_name << endl;
		cout << "商品价格： " << p << endl;
		cout << "商品描述：" << good[j].g_info << endl;
		cout << "*************************************" << endl;
		cout << "确认修改？（y/n）";
		string ch;
		cin >> ch;
		if (ch == "n")
		{
			cout << "取消修改" << endl;
			return;
		}
		else if (ch == "y")
		{	
			good[j].g_price = p;
			goodxieru(a);
			fstream infile("commands.txt", ios::app);
			time_t t = time(0);
			char ch[64];
			strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
			infile << ch << "UPDATE commodity SET价格 = " << good[j].g_price << "WHERE 商品ID = " << good[j].g_id << endl;
			infile.close();
			cout << "修改成功！" << endl;
			return;
		}
		else
		{
			cout << "输入错误，即将返回菜单......." << endl;
			return;
		}
	}
	else
	{
		cout << "请输入被修改的商品描述： ";
		string p;
		cin >> p;
		while (p.length() > 40)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "输入错误，请重新输入：";
			cin >> p;
		}
		cout << "请确认修改的商品信息无误！ " << endl;
		cout << "*************************************" << endl;
		cout << "商品ID： " << good[j].g_id << endl;
		cout << "商品名称： " << good[j].g_name << endl;
		cout << "商品价格： " <<good[j].g_price<< endl;
		cout << "商品描述：" << p << endl;
		cout << "*************************************" << endl;
		cout << "确认修改？（y/n）";
		string ch;
		cin >> ch;
		if (ch == "n")
		{
			cout << "取消修改" << endl;
			return;
		}
		else if (ch == "y")
		{	
			good[j].g_info = p;
			goodxieru(a);
			fstream infile("commands.txt", ios::app);
			time_t t = time(0);
			char ch[64];
			strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
			infile << ch << "UPDATE commodity SET价格 = " << good[j].g_price << "WHERE 商品描述 = " << good[j].g_info << endl;
			infile.close();
			cout << "修改成功！" << endl;
			return;
		}
		else
		{
			cout << "输入错误，即将返回菜单......." << endl;
			return;
		}
	}

}
void Sellers::Deselling(int i)
{
	cout << "请输入要下架的商品ID： ";
	string id;
	cin >> id;
	int a = goodchuanru(), count = 0;
	int j = 0;
	for (j = 0; j < a; j++)
	{
		if (good[j].g_id == id && good[j].seller_id == user[i].u_id)
		{
			cout << "*****************************************************************" << endl;
			cout << "商品ID   名称    价格    上架时间   数量   卖家ID   商品状态" << endl;
			cout << good[j].g_id << "   " << good[j].g_name << "   " << good[j].g_price << "   " << good[j].g_sta
				<< "   " << good[j].g_number << "   " << good[j].seller_id << "   " << good[j].g_sta << endl;
			cout << "*****************************************************************" << endl;
			count++;
			break;
		}
	}
	if (count == 0)
	{
		cout << "未查询到该商品" << endl;
		return;
	}
	cout << "请选择（y/n):";
	string ch;
	cin >> ch;
	if (ch == "n")
	{
		cout << "取消下架" << endl;
		return;
	}
	else if (ch == "y")
	{
		good[j].g_sta = "removed";
		goodxieru(a);
		fstream infile("commands.txt", ios::app);
		time_t t = time(0);
		char ch[64];
		strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
		infile << ch << "UPDATE commodity SET 商品状态 =  " << good[j].g_sta<< "WHERE 商品ID = " << good[j].g_id << endl;
		infile.close();
		cout << "下架成功！" << endl;
		return;
	}
	else
	{
		cout << "输入错误，即将返回菜单......." << endl;
		return;
	}
}
void Sellers::Seller_checkorders(int i)
{
	int a = orderchuanru();
	cout << "*******************************************************" << endl;
	cout << "订单ID   商品ID   交易单价   数量   交易时间   买家ID" << endl;
	for (int j = 0; j < a; j++)
	{
		if (order[j].seller_id == user[i].u_id)
		{
			cout << order[j].order_id << "   " << order[j].good_id << "   " << order[j].good_price << "   " <<
				order[j].good_nmuber << "   " << order[j].Trade_time << "   " << order[j].buyer_id << endl;
		}
	}
	fstream infile("commands.txt", ios::app);
	time_t t = time(0);
	char ch[64];
	strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
	infile << ch << "SELECT * FROM order" << endl;
	infile.close();
	cout << "*******************************************************" << endl;
	cout << endl;
	return;
}