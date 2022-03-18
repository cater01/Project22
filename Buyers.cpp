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


void Buyers::buyer_manu()//�˵�
{
	cout << "=======================================================================================" << endl;
	cout << "1.�鿴��Ʒ�б� 2.������Ʒ 3.������Ʒ 4.�鿴��ʷ���� 5.�鿴��Ʒ��ϸ��Ϣ 6.�����û�������" << endl;
	cout << "=======================================================================================" << endl;
	cout << endl;
}
void Buyer_Moudle(int i)
{	
	Buyers liu;
	while (true)
	{
		liu.buyer_manu();
		cout << "�����������";
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
			cout << "����������......" << endl;
			return;
		}
		default:cout << "�������������:" << endl;
			; break;
		}
	}
}
void Buyers::Buyer_checkgoods()
{
	int i = goodchuanru();
	cout << "***************************************************" << endl;
	cout << "��ƷID   ����    �۸�    ����     �ϼ�ʱ��     ����ID" << endl;
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
	cout << "��������Ʒ���ƣ�" ;
	string g_name1;
	cin >> g_name1;
	while (g_name1.length() > 20)
	{
		cout << "��Ʒ�����������������Ƿ���ȷ��" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> g_name1;
	}
	int count = 0;
	for (int j = 0; j < i; j++)
	{

		if (g_name1 == good[j].g_name&&good[j].g_sta!="removed")
		{
			cout << "��ƷID   ��Ʒ����   ��Ʒ�۸�  ��Ʒ����   �ϼ�ʱ��    ����ID " << endl;
			cout << good[j].g_id << " " << good[j].g_name << " " << good[j].g_price << 
				" " << good[j].g_number <<"  " << good[j].g_time << " "<< good[j].seller_id <<  endl;
			count++;
		}
	}
	if (count == 0)
	{
		cout << "**********************************" << endl;
		cout << "û���ҵ�����Ҫ����Ʒ�����س�ʼ����" << endl;
		cout << "**********************************" << endl;
		cout << endl;
	}
}
void Buyers::Buyer_checkorders(int i)
{
	int a = orderchuanru();
	cout << "*******************************************************" << endl;
	cout << "����ID  ��ƷID   ���׵���    ����    ����ʱ��    ����ID" << endl;
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
	cout << "��������ƷID:" ;
	string id;
	cin >> id;
	while (id.length() > 5)
	{
		cout << "��Ʒ���Ƹ�ʽ�������������룺";
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
		cout << "û���ҵ�����Ҫ����Ʒ�����س�ʼ����" << endl;
		cout << "**********************************" << endl;
		cout << endl;
	}
	else
	{
		cout << "������������";
		int num;
		cin >> num;
		while (num > good[j].g_number)
		{
			cout << "��Ʒ�������㣬���������빺��������";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> num;
		}
		while (user[i].u_balance < num * good[j].g_price)
		{
			cout << "�������㣬���������빺��������";
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
		cout << "�������ѣ�" << endl;
		cout << "����ʱ�䣺" << ch<< endl;
		cout << "���׵���:" << good[j].g_price << endl;
		cout << "��������:" << num << endl;
		cout << "���׳ɹ�!" << endl;	
		cout << "�������:" << user[i].u_balance << endl;
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
	cout << "��������Ҫ�鿴����ƷID��";
	cin >> tempid;
	int i = goodchuanru(), j = 0;
	for (j = 0; j < i; j++)
	{
		if (tempid == good[j].g_id)
		{
			cout << "*******************************" << endl;
			cout << "��ƷID�� " << good[j].g_id << endl;
			cout << "��Ʒ���ƣ� " << good[j].g_name << endl;
			cout << "��Ʒ�۸� " << good[j].g_price << endl;
			cout << "�ϼ�ʱ�䣺 " << good[j].g_time << endl;
			cout << "��Ʒ������ " << good[j].g_info << endl;
			cout << "��Ʒ���ң� " << good[j].seller_id << endl;
			cout << "*******************************" << endl;
		}
	}
}
