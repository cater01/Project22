#ifndef USERS_H
#define USERS_H
#include<iostream>
#include<string>
using namespace std;
struct User
{
	string u_id= { 'U' };
	string u_name;
	string u_password;
	string u_phone;
	string u_address;
	double u_balance = 0.0;
	string u_State="active";
	//active为存在，inactive为不存在，即正常与封禁。
};

class Users
{
public :
	void user_manu();//1.我是买家 2.我是卖家 3.个人信息管理 4.注销登录
	void self_manage(int i);//个人信息管理
	void check_info(int i);//查看个人信息
	void Modify_info(int i);//修改信息
	void Modify_money(int i);//充值
	void Modify_name(int i); //修改用户姓名
	void Modify_phone(int i); //修改用户号码
	void Modify_address(int i);//修改地址
};
void User_register();//用户注册
void User_login();//用户登录 判断用户名及密码正确性
string zhuan(int n);
#endif 