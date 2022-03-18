#include<iostream>
#include "Administrator.h"
#include"Users.h"
using namespace std;

int main()
{
	while (true)
	{
		cout << "=============================================" << endl;
		cout << "1.管理员登录 2.用户注册 3.用户登录 4.退出程序" << endl;
		cout << "=============================================" << endl;
		cout << endl;
		cout << "输入操作：";
		int opt = 0;
		cin >> opt;
		cin.clear();
		cin.ignore(100, '\n');
		while (opt <1||opt>4)
		{
			cout << "输入错误！请重新输入：" ;
			cin >> opt;
		}
		switch (opt)
		{
		case 1:Adm_Moudle(); break;
		case 2:User_register(); break;//用户注册
		case 3:User_login(); break;//用户登录
		case 4:exit(-1); break;
		default:cout << "输入错误！请重新输入：" << endl; break;
		}
	}
	return 0;
}



