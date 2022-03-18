#include <iostream>
using namespace std;
#include"Users.h"
#include<string>
#include"Administrator.h"
#include"Buyers.h"
#include"Sellers.h"
#include<fstream>
struct User user[10];
extern struct Good good[10];
string zhuan(int n) //数字转字符串
{
	char s[6];
	sprintf_s(s, "%03d", n);//unsafe
	return s;
}

void Users::user_manu() 
{	
	cout << "================================================" << endl;
	cout << "1.我是买家 2.我是卖家 3.个人信息管理 4.注销登录" << endl;
	cout << "================================================" << endl;
}
void User_login()
{	
	Users liu;
	string u_tempid;
	string u_tempkey;
	cout << "请输入用户名：";
	cin >> u_tempid;
	cout << "请输入密码：";
	cin >> u_tempkey;
	int i = userchuanru();
	int j;
	for (j = 0; j < i; j++)
	{
		if (user[j].u_name == u_tempid && user[j].u_password == u_tempkey)
		{
			break;
		}
	}
	if (i==j&& user[j].u_State == "active")
	{
		cout << "用户名或密码错误" << endl;
		return;
	}
	else if (i != j && user[j].u_State == "inactive")
	{
		cout << "用户已被封禁！" << endl;
		return;
	}
	else 
	{
		cout << endl;
		cout << "-------登录成功-------" << endl;
		cout << endl;
	}
	while (true)
	{
		liu.user_manu();
		cout << "请输入操作：";
		int opt = 0;
		cin >> opt;
		cin.clear();
		cin.ignore(100, '\n');
		switch (opt)
		{
		case 1:Buyer_Moudle(j); break;
		case 2:Seller_Moudle(j); break;
		case 3:liu.self_manage(j); break;
		case 4: return;
		case 5:
		{
			cout << "返回主界面......" << endl;
			return;
		}
		default:cout << "输入错误，请重试：" << endl;
		 break;
		}
	}
}
void User_register() 
{
	int i = userchuanru();
	cout << "请输入用户名(不超过10个字符，数字或英文字母）：";
	cin >> user[i].u_name;
	while (user[i].u_name.length() > 10)
	{
		cout << "用户名过长！请重新输入:" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> user[i].u_name;
	}
	cout << endl;
	cout << "请设置密码(不超过20个字符，只由小写字母和数字组成)：";
	cin >> user[i].u_password;
	while (user[i].u_password.length() > 10)
	{
		cout << "密码过长！请重新输入:" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> user[i].u_password;
	}
	cout << endl;
	cout << "请输入您的联系方式(不超过20个字符，由数字组成)：";
	cin >> user[i].u_phone;
	while (user[i].u_phone.length() > 20)
	{
		cout << "联系方式错误！请重新输入:" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> user[i].u_phone;
	}
	cout << endl;
	cout << "请输入您的地址(不超过40个字符，英文字母)：";
	cin >> user[i].u_address;
	while (user[i].u_address.length() > 40)
	{
		cout << "联系方式错误！请重新输入:" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> user[i].u_address;
	}
	cout << endl;
	user[i].u_balance = 0;
	user[i].u_State = "active";
	user[i].u_id = "U" + zhuan(i+1);
	fstream infile("user.txt", ios::out);
	infile << "userID,username,password,phoneNumber,address,balance,userState" << endl;
	for (int j = 0; j <= i; j++)
	{
		infile << user[j].u_id << "," << user[j].u_name << "," << user[j].u_password << "," << user[j].u_phone << ","
			<< user[j].u_address << "," << user[j].u_balance << "," << user[j].u_State << endl;
	}
	infile.close();
	cout << "注册成功！" << endl;
	return;

}
void Users::self_manage(int i)//个人信息管理
{
	while (true)
	{	
		cout << "=============================================" << endl;
		cout << "1.查看信息 2.修改信息 3.充值 4.返回用户主界面" << endl;
		cout << "=============================================" << endl;
		cout << "请输入操作：" << endl;
		int opt;
		cin >> opt;
		cin.clear();
		cin.ignore(100, '\n');
		switch (opt)
		{
		case 1:check_info(i); break;
		case 2:Modify_info(i); break;
		case 3:Modify_money(i);break;
		case 4:
		{	cout << "返回主界面......" << endl;
		return; }
		default:cout << "输入错误，请重试：" << endl;
			cin >> opt; break;
		}
	}
}
void Users::check_info(int i)
{
	cout << "***********************" << endl;
	cout << "用户名：" <<user[i].u_id<< endl;
	cout << "联系方式：" << user[i].u_phone << endl;
	cout << "地址：" << user[i].u_address << endl;
	cout << "钱包余额：" << user[i].u_balance << endl;
	cout << "***********************" << endl;
}
void Users::Modify_info(int i)
{
	Users liu;
	cout << "请选择修改的属性（1.用户名 2.联系方式 3.地址）:" << endl;
	int opt;
	cin >> opt;
	cin.clear();
	cin.ignore(100, '\n');
	switch (opt)
	{
	case 1:liu.Modify_name(i); break;
	case 2:liu.Modify_phone(i);break;
	case 3:liu.Modify_address(i);break;
	default:cout << "输入错误，请重试：" << endl;
		cin >> opt; break;
	}
}
void Users::Modify_name(int i)
{
	cout << "请选择修改后的用户名：" << endl;
	while (true)
	{
		string tempname;
		cin >> tempname;
		while (tempname.length() > 11)
		{
			cout << "用户名超出范围，请输入不超过10个字符，数字或英文字母！" << endl;
			cin >> tempname;
		}
		int k = userchuanru();
		int count = 0;
		for (int m = 0; m < k; m++)
		{
			if (user[m].u_name == tempname)
				count++;
		}
		if (count != 0)
		{
			cout << "用户名重复!!!" << endl;
			return;
		}
		else
		{
			user[i].u_name = tempname;
			fstream infile("user.txt", ios::out);
			infile << "userID,username,password,phoneNumber,address,balance,userState" << endl;
			for (int j = 0; j < k; j++)
			{
				infile << user[j].u_id << "," << user[j].u_name << "," << user[j].u_password << "," << user[j].u_phone << ","
					<< user[j].u_address << "," << user[j].u_balance << "," << user[j].u_State << endl;
			}
			infile.close();
			cout << "修改成功！" << endl;
			return;
		}
	}
}
void Users::Modify_phone(int i)
{
	cout <<"请输入联系方式（不超过20个字符，由数字组成）"<<endl;
	string tempp;
	cin >> tempp;
	while(tempp.length() > 20)
	{
		cout << "超出范围！请重新输入：" ;
		cin >> tempp;
	}
	int k = userchuanru();
	user[i].u_phone = tempp;
	fstream infile("user.txt", ios::out);
	infile << "userID,username,password,phoneNumber,address,balance,userState" << endl;
	for (int j = 0; j < k; j++)
	{
		infile << user[j].u_id << "," << user[j].u_name << "," << user[j].u_password << "," << user[j].u_phone << ","
			<< user[j].u_address << "," << user[j].u_balance << "," << user[j].u_State << endl;
	}
	infile.close();
	cout << "修改成功！" << endl;
	return;
}
void Users::Modify_address(int i)
{
	cout << "请输入地址（不超过40个字符，英文字母）：";
	string tempadd;
	cin >>tempadd;
	while (tempadd.length() > 40)
	{
		cout << "超出范围！请重新输入：";
		cin >> tempadd;
	}
	int k = userchuanru();
	user[i].u_address = tempadd;
	fstream infile("user.txt", ios::out);
	infile << "userID,username,password,phoneNumber,address,balance,userState" << endl;
	for (int j = 0; j < k; j++)
	{
		infile << user[j].u_id << "," << user[j].u_name << "," << user[j].u_password << "," << user[j].u_phone << ","
			<< user[j].u_address << "," << user[j].u_balance << "," << user[j].u_State << endl;
	}
	infile.close();
	cout << "修改成功！" << endl;
	return;
}
void Users::Modify_money(int i)
{	
	int k = userchuanru();
	cout << "请输入充值金额：";
	int a = 0;
	cin >> a;
	while (a == 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "格式错误！请重新输入充值金额：";
		cin >> a;
	}
	user[i].u_balance = user[i].u_balance + a;
	fstream infile("user.txt", ios::out);
	infile << "userID,username,password,phoneNumber,address,balance,userState" << endl;
	for (int j = 0; j < k; j++)
	{
		infile << user[j].u_id << "," << user[j].u_name << "," << user[j].u_password << "," << user[j].u_phone << ","
			<< user[j].u_address << "," << user[j].u_balance << "," << user[j].u_State << endl;
	}
	infile.close();
	cout << "充值成功！ 当前余额：" << user[i].u_balance << endl;
	return;
}

