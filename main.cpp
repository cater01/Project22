#include<iostream>
#include "Administrator.h"
#include"Users.h"
using namespace std;

int main()
{
	while (true)
	{
		cout << "=============================================" << endl;
		cout << "1.����Ա��¼ 2.�û�ע�� 3.�û���¼ 4.�˳�����" << endl;
		cout << "=============================================" << endl;
		cout << endl;
		cout << "���������";
		int opt = 0;
		cin >> opt;
		cin.clear();
		cin.ignore(100, '\n');
		while (opt <1||opt>4)
		{
			cout << "����������������룺" ;
			cin >> opt;
		}
		switch (opt)
		{
		case 1:Adm_Moudle(); break;
		case 2:User_register(); break;//�û�ע��
		case 3:User_login(); break;//�û���¼
		case 4:exit(-1); break;
		default:cout << "����������������룺" << endl; break;
		}
	}
	return 0;
}



