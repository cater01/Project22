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
string zhuan(int n) //����ת�ַ���
{
	char s[6];
	sprintf_s(s, "%03d", n);//unsafe
	return s;
}

void Users::user_manu() 
{	
	cout << "================================================" << endl;
	cout << "1.������� 2.�������� 3.������Ϣ���� 4.ע����¼" << endl;
	cout << "================================================" << endl;
}
void User_login()
{	
	Users liu;
	string u_tempid;
	string u_tempkey;
	cout << "�������û�����";
	cin >> u_tempid;
	cout << "���������룺";
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
		cout << "�û������������" << endl;
		return;
	}
	else if (i != j && user[j].u_State == "inactive")
	{
		cout << "�û��ѱ������" << endl;
		return;
	}
	else 
	{
		cout << endl;
		cout << "-------��¼�ɹ�-------" << endl;
		cout << endl;
	}
	while (true)
	{
		liu.user_manu();
		cout << "�����������";
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
			cout << "����������......" << endl;
			return;
		}
		default:cout << "������������ԣ�" << endl;
		 break;
		}
	}
}
void User_register() 
{
	int i = userchuanru();
	cout << "�������û���(������10���ַ������ֻ�Ӣ����ĸ����";
	cin >> user[i].u_name;
	while (user[i].u_name.length() > 10)
	{
		cout << "�û�������������������:" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> user[i].u_name;
	}
	cout << endl;
	cout << "����������(������20���ַ���ֻ��Сд��ĸ���������)��";
	cin >> user[i].u_password;
	while (user[i].u_password.length() > 10)
	{
		cout << "�������������������:" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> user[i].u_password;
	}
	cout << endl;
	cout << "������������ϵ��ʽ(������20���ַ������������)��";
	cin >> user[i].u_phone;
	while (user[i].u_phone.length() > 20)
	{
		cout << "��ϵ��ʽ��������������:" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> user[i].u_phone;
	}
	cout << endl;
	cout << "���������ĵ�ַ(������40���ַ���Ӣ����ĸ)��";
	cin >> user[i].u_address;
	while (user[i].u_address.length() > 40)
	{
		cout << "��ϵ��ʽ��������������:" << endl;
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
	cout << "ע��ɹ���" << endl;
	return;

}
void Users::self_manage(int i)//������Ϣ����
{
	while (true)
	{	
		cout << "=============================================" << endl;
		cout << "1.�鿴��Ϣ 2.�޸���Ϣ 3.��ֵ 4.�����û�������" << endl;
		cout << "=============================================" << endl;
		cout << "�����������" << endl;
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
		{	cout << "����������......" << endl;
		return; }
		default:cout << "������������ԣ�" << endl;
			cin >> opt; break;
		}
	}
}
void Users::check_info(int i)
{
	cout << "***********************" << endl;
	cout << "�û�����" <<user[i].u_id<< endl;
	cout << "��ϵ��ʽ��" << user[i].u_phone << endl;
	cout << "��ַ��" << user[i].u_address << endl;
	cout << "Ǯ����" << user[i].u_balance << endl;
	cout << "***********************" << endl;
}
void Users::Modify_info(int i)
{
	Users liu;
	cout << "��ѡ���޸ĵ����ԣ�1.�û��� 2.��ϵ��ʽ 3.��ַ��:" << endl;
	int opt;
	cin >> opt;
	cin.clear();
	cin.ignore(100, '\n');
	switch (opt)
	{
	case 1:liu.Modify_name(i); break;
	case 2:liu.Modify_phone(i);break;
	case 3:liu.Modify_address(i);break;
	default:cout << "������������ԣ�" << endl;
		cin >> opt; break;
	}
}
void Users::Modify_name(int i)
{
	cout << "��ѡ���޸ĺ���û�����" << endl;
	while (true)
	{
		string tempname;
		cin >> tempname;
		while (tempname.length() > 11)
		{
			cout << "�û���������Χ�������벻����10���ַ������ֻ�Ӣ����ĸ��" << endl;
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
			cout << "�û����ظ�!!!" << endl;
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
			cout << "�޸ĳɹ���" << endl;
			return;
		}
	}
}
void Users::Modify_phone(int i)
{
	cout <<"��������ϵ��ʽ��������20���ַ�����������ɣ�"<<endl;
	string tempp;
	cin >> tempp;
	while(tempp.length() > 20)
	{
		cout << "������Χ�����������룺" ;
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
	cout << "�޸ĳɹ���" << endl;
	return;
}
void Users::Modify_address(int i)
{
	cout << "�������ַ��������40���ַ���Ӣ����ĸ����";
	string tempadd;
	cin >>tempadd;
	while (tempadd.length() > 40)
	{
		cout << "������Χ�����������룺";
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
	cout << "�޸ĳɹ���" << endl;
	return;
}
void Users::Modify_money(int i)
{	
	int k = userchuanru();
	cout << "�������ֵ��";
	int a = 0;
	cin >> a;
	while (a == 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "��ʽ���������������ֵ��";
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
	cout << "��ֵ�ɹ��� ��ǰ��" << user[i].u_balance << endl;
	return;
}

