#include<iostream>
#include"Administrator.h"
#include"Data.h"
#include<fstream>
#include<string>
#include"Users.h"
#include<assert.h>
using namespace std;
extern struct Good good[10];
extern struct order order[10];
extern struct User user[10];

bool Administrator:: adm_login()
{
	char name[6] = "admin";
	char key[7] = "123456";
	char temp[6];
	char temppass[7];
	cout << "请输入管理员姓名：";
	cin >> temp;
	cout << "请输入密码：";
	cin >> temppass;
	if (strcmp(temp, name) == 0 && strcmp(temppass, key) == 0)
	{
		return true;
	}
	else return false;	
}

void Administrator::adm_manu()
{
	cout << "====================================================================================" <<endl;
	cout << "1.查看所有商品 2.搜索商品 3.下架商品 4.查看所有订单 5.查看所有用户 6.封禁用户 7.注销" <<endl;
	cout << "====================================================================================" <<endl;
	cout << endl;
}

void Adm_Moudle()
{
	Administrator liu;
	if (liu.adm_login() != true)
	{
		cout << "----密码错误，登陆失败，返回主菜单----" << endl;
		return;
	}
	else
	{
		cout << "-----登陆成功-----" << endl;
	}

	while (true)
	{
		liu.adm_manu();
		int opt = 0;
		cout << "请输入操作：";
		cin >> opt;
		cin.clear();
		cin.ignore(100, '\n');
		switch (opt)
		{
		case 1:liu.good_look(); break;
		case 2:liu.adm_Search(); break;
		case 3:liu.good_del(); break;
		case 4:liu.order_look(); break;
		case 5:liu.users_look(); break;
		case 6:liu.user_del(); break;
		case 7:
		{
			cout << "返回主界面......" << endl;
			return;
		}
		default:cout << "输入错误，请重试!" << endl;
		 break;
		}
	}
}

void Administrator::adm_Search()
{
	//ofstream outfile("good.txt",ios::out);
	int i= goodchuanru();
	cout << "请输入商品名称：" << endl;
	char g_name1[21];
	cin >> g_name1;
	int count = 0;
	cout << "**************************************************************" << endl;
	cout << "商品ID   名称   价格     上架时间     卖家ID   数量   商品状态" << endl;
	for (int j = 0; j < i; j++)
	{	
		
		if (g_name1== good[j].g_name)
		{
			cout << good[j].g_id << " " << good[j].g_name << " " << good[j].g_price << " " << good[j].g_time << " "
				<< good[j].seller_id << " " << good[j].g_number << " " << good[j].g_sta << " " << endl;
			count++;
			fstream infile("commands.txt", ios::app);
			time_t t = time(0);
			char ch[64];
			strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
			infile << ch << " SELECT * FROM commodity WHERE 名称 CONTAINS" << g_name1 << endl;
			infile.close();
		}
	}
	if (count == 0)
	{
		cout << "没有找到您想要的商品，返回初始界面" << endl;
	}
	cout << "**************************************************************" << endl;
	
 }//搜索商品信息

void Administrator::good_look() const
{	
	int i = goodchuanru();
	cout << "****************************************************************" << endl;
	cout << "商品ID   名称   价格     上架时间     卖家ID   数量   商品状态" << endl;
	for (int j = 0; j < i; j++)
	{
		cout << good[j].g_id << " " << good[j].g_name << " " << good[j].g_price << " " << good[j].g_time << " "
			<< good[j].seller_id << " " << good[j].g_number << " " << good[j].g_sta << " " << endl;
	}
	fstream infile("commands.txt", ios::app);
	time_t t = time(0);
	char ch[64];
	strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
	infile << ch << " SELECT * FROM commodity" << endl;
	infile.close();
	cout << "****************************************************************" << endl;
}//输出good文件的内容

void Administrator::order_look ()const
{
	int i = orderchuanru();
	cout << "*****************************************************************" << endl;
	cout << "订单ID   商品ID   交易单价   数量      交易时间    卖家ID   买家ID" << endl;
	for(int j=0;j<i;j++)
	{
		cout << order[j].order_id << " " << order[j].good_id << " " << order[j].good_price << " " << order[j].good_nmuber<< " "
			<< order[j].Trade_time << " " << order[j].seller_id << " " << order[j].buyer_id<< " " << endl;
	}
	fstream infile("commands.txt", ios::app);
	time_t t = time(0);
	char ch[64];
	strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
	infile << ch << "SELECT * FROM order" << endl; 
	infile.close();
	cout << "*****************************************************************" << endl;
}//输出订单内容

void Administrator::users_look()const
{
	int i = userchuanru();
	cout << "**********************************************************" << endl;
	cout << "用户ID   用户名    联系方式    地址    钱包余额   用户状态 " << endl;

	for (int j = 0; j < i; j++)
	{
		cout << user[j].u_id << " " << user[j].u_name << " " << user[j].u_phone << " " << user[j].u_address<< " "
			<< user[j].u_balance << " " << user[j].u_State << " " <<endl;
	}
	fstream infile("commands.txt", ios::app);
	time_t t = time(0);
	char ch[64];
	strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
	infile << ch << "SELECT * FROM user" << endl;
	infile.close();
	cout << "**********************************************************" << endl;
}//输出用户信息

void Administrator::good_del()
{
	cout << "请输入要下架的商品ID：";
	char tempgoodid[5];
	cin >> tempgoodid;
	cout << "确认要下架该商品吗？" << endl;
	int count = 0;
	int i = goodchuanru();
	cout << "***********************************************************************" << endl;
	cout << "商品ID   商品名称    价格   上架时间    卖家ID    货物数量     货物状态" << endl;
	for (int j = 0; j < i; j++)
	{

		if (tempgoodid== good[j].g_id)
		{
			cout << good[j].g_id << " " << good[j].g_name << " " << good[j].g_price << " " << good[j].g_time << " "
				<< good[j].seller_id << " " << good[j].g_number << " " << good[j].g_sta << " " << endl;
			count++;
		}
	}
	if (count == 0)
	{
		cout << "没有找到您想要的商品，返回初始界面" << endl;
	}
	cout << "***********************************************************************" << endl;
	if (count != 0)
	{
		cout << "请选择（y/n）：";
	}
		char a;
		cin >> a;
	if (a != 'y' && a != 'n')
	{
		cout << "输入错误，请重新输入..." << endl;
		cin >> a;
	}
	if (a == 'y')
	{
		for (int j = 0; j <= i; j++)
		{
			if (tempgoodid== good[j].g_id)
			{
				string b = "removed";
				good[j].g_sta = b;
				fstream infile("commands.txt", ios::app);
				time_t t = time(0);
				char ch[64];
				strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
				infile << ch << "UPDATE commodity SET 商品状态 = 已下架 WHERE 商品ID =" << good[j].g_id << endl;
				infile.close();
			}
		}
		fstream infile("good.txt", ios::out);
		infile << "commodityID,commodityName,price,number,description,sellerID,addedDate,state" << endl;

		for (int j = 0; j < i; j++)
		{
			infile << good[j].g_id << "," << good[j].g_name << "," << good[j].g_price << "," << good[j].g_number << ","
				<< good[j].g_info << "," << good[j].seller_id << "," << good[j].g_time << "," << good[j].g_sta << endl;
		}
		infile.close();
		cout << "下架成功" << endl;
		return;
	}
	if(a=='n')
	{
		cout << "取消下架"<<endl; return;
	}
}

void Administrator::user_del()
{
	cout << "请输入要封禁的用户ID：" ;
	char tempuserid[5];
	cin >> tempuserid;
	cout << "确认要封禁该用户吗？" << endl;
	int count = 0;
	int i = userchuanru();
	int c = goodchuanru();
	cout << "******************************************************" << endl;
	cout << "用户id    用户名   联系方式        地址        钱包余额 " << endl;
	for (int j = 0; j <i; j++)
	{
		if (tempuserid== user[j].u_id)
		{
			cout << user[j].u_id << "  " << user[j].u_name << "  " << user[j].u_phone <<
			"  " << user[j].u_address << "  " << user[j].u_balance << "  " << user[j].u_State << endl;
			count++;
		}
	}
	if(count==0)
	{
		cout << "没有找到您想要的封禁的用户，返回初始界面" << endl;
	}
	cout << "******************************************************" << endl;
	if (count != 0)
	{
		cout << "请选择（y/n）：";
	}
	char a;
	cin >> a;
	if (a != 'y' && a != 'n')
	{
		cout << "输入错误，请重新输入..." << endl;
		cin >> a;
	}
	if (a == 'y')
	{
		for (int j = 0; j < i; j++)
		{
			if (tempuserid==user[j].u_id)
			{
				string b = "inactive";
				user[j].u_State = b;
				fstream infile("commands.txt", ios::app);
				time_t t = time(0);
				char ch[64];
				strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
				infile << ch << "UPDATE user SET 用户状态 = 封禁 WHERE 用户ID = " << user[j].u_id<< endl;
				infile.close();
				for(int k=0;k<c;k++)
				{
					if (good[k].seller_id == tempuserid)
					{
						string a = "removed";
						good[k].g_sta = a;
						fstream infile("commands.txt", ios::app);
						time_t t = time(0);
						char ch[64];
						strftime(ch, sizeof(ch), "%Y-%m-%d-%H:%M:%S", localtime(&t));
						infile << ch << "UPDATE commodity SET 商品状态 = 已下架 WHERE 卖家ID =  " << good[k].seller_id << endl;
						infile.close();
					}
				}
			fstream infile("good.txt", ios::out);
			infile << "commodityID,commodityName,price,number,description,sellerID,addedDate,state" << endl;

			for (int j = 0; j < i; j++)
			{	
				infile << good[j].g_id << "," << good[j].g_name << "," << good[j].g_price << "," << good[j].g_number << ","
				<< good[j].g_info << "," << good[j].seller_id << "," << good[j].g_time << "," << good[j].g_sta << endl;
			}
				infile.close();
			}
		}
		fstream infile("user.txt", ios::out);
		infile << "userID,username,password,phoneNumber,address,balance,userState" << endl;

		for (int j = 0; j < i; j++)
		{
			infile << user[j].u_id << "," << user[j].u_name << "," << user[j].u_password << "," << user[j].u_phone << ","
				<< user[j].u_address << "," << user[j].u_balance << "," << user[j].u_State << endl;
		}
		infile.close();
		cout << "封禁成功"<<endl;
		return;
	}
	if (a == 'n')
	{
		cout << "取消封禁"<<endl; return;
	}
}
