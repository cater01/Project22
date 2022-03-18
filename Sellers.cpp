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
	cout << "1.������Ʒ 2.�鿴������Ʒ 3.�޸���Ʒ��Ϣ 4.�¼���Ʒ 5.�鿴��ʷ���� 6.�����û�������" << endl;
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
		cout << "�����������";
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
			cout << "����������......" << endl;
			return;
		}
		default:cout << "�������������:" << endl;
			; break;
		}
	}
}
void Sellers::Selling(int i)
{
	cout << "��������Ʒ���ƣ�";
	string tempname;
	cin >> tempname;
	while (tempname.length() > 20)
	{
		cout << "���ƹ��������������룺";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> tempname;
	}
	double tempprice;
	cout << "��������Ʒ�۸�";
	cin >> tempprice;
	while (tempprice == 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "��ʽ����������������Ʒ�۸�";
		cin >> tempprice;
	}
	int tempnum;
	cout << "��������Ʒ������";
	cin >> tempnum;
	while (tempnum == 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "��ʽ����������������Ʒ������";
		cin >> tempnum;
	}
	string tempin;
	cout << "��������Ʒ������";
	cin >> tempin;
	while (tempin.length() > 40)
	{
		cout << "�������������������룺";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> tempin;
	}
	cout << endl;
	cout << "��ȷ�Ϸ�������Ʒ��Ϣ����" << endl;
	cout << "****************************" << endl;
	cout <<"��Ʒ���ƣ� "<<tempname << endl;
	cout << "��Ʒ�۸� " <<tempprice<< endl;
	cout << "��Ʒ������ "<<tempnum << endl;
	cout << "��Ʒ������ " <<tempin<< endl;
	cout << "****************************" << endl;
	cout << endl;
	cout << "��ȷ��Ҫ������Ʒ�𣿣�y/n��";
	string ch;
	cin >> ch;
	if (ch =="n")
	{
		cout << "����ȡ������" << endl;
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

		cout << "������Ʒ�ɹ���" << endl;
		cout << endl;
		return;
	}
	else
	{
		cout << "������󣬼������ز˵�......." << endl;
		return;
	}
}
void Sellers::Seller_checkgoods(int i)
{
	int a = goodchuanru();
	cout << "*****************************************************" << endl;
	cout << "��ƷID   ����   �۸�   ����   �ϼ�ʱ��     ��Ʒ״̬" << endl;
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
	cout << "�����뱻�޸ĵ���ƷID�� ";
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
		cout << "δ��ѯ������Ʒ" << endl;
		return;
	}
	cout << "�����뱻�޸ĵ���Ʒ���ԣ�1.�۸� 2.�������� ";
	int b = 0;
	cin >> b;
	while (b!=1&&b!=2)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "����������������룺";
		cin >> b;
	}
	if (b == 1)
	{
		cout << "�����뱻�޸ĵ���Ʒ�۸� ";
		double p;
		cin >> p;
		while (p == 0)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "����������������룺";
			cin >> p;
		}
		cout << "��ȷ���޸ĵ���Ʒ��Ϣ���� " << endl;
		cout << "*************************************" << endl;
		cout << "��ƷID�� " << good[j].g_id << endl;
		cout << "��Ʒ���ƣ� " << good[j].g_name << endl;
		cout << "��Ʒ�۸� " << p << endl;
		cout << "��Ʒ������" << good[j].g_info << endl;
		cout << "*************************************" << endl;
		cout << "ȷ���޸ģ���y/n��";
		string ch;
		cin >> ch;
		if (ch == "n")
		{
			cout << "ȡ���޸�" << endl;
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
			infile << ch << "UPDATE commodity SET�۸� = " << good[j].g_price << "WHERE ��ƷID = " << good[j].g_id << endl;
			infile.close();
			cout << "�޸ĳɹ���" << endl;
			return;
		}
		else
		{
			cout << "������󣬼������ز˵�......." << endl;
			return;
		}
	}
	else
	{
		cout << "�����뱻�޸ĵ���Ʒ������ ";
		string p;
		cin >> p;
		while (p.length() > 40)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "����������������룺";
			cin >> p;
		}
		cout << "��ȷ���޸ĵ���Ʒ��Ϣ���� " << endl;
		cout << "*************************************" << endl;
		cout << "��ƷID�� " << good[j].g_id << endl;
		cout << "��Ʒ���ƣ� " << good[j].g_name << endl;
		cout << "��Ʒ�۸� " <<good[j].g_price<< endl;
		cout << "��Ʒ������" << p << endl;
		cout << "*************************************" << endl;
		cout << "ȷ���޸ģ���y/n��";
		string ch;
		cin >> ch;
		if (ch == "n")
		{
			cout << "ȡ���޸�" << endl;
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
			infile << ch << "UPDATE commodity SET�۸� = " << good[j].g_price << "WHERE ��Ʒ���� = " << good[j].g_info << endl;
			infile.close();
			cout << "�޸ĳɹ���" << endl;
			return;
		}
		else
		{
			cout << "������󣬼������ز˵�......." << endl;
			return;
		}
	}

}
void Sellers::Deselling(int i)
{
	cout << "������Ҫ�¼ܵ���ƷID�� ";
	string id;
	cin >> id;
	int a = goodchuanru(), count = 0;
	int j = 0;
	for (j = 0; j < a; j++)
	{
		if (good[j].g_id == id && good[j].seller_id == user[i].u_id)
		{
			cout << "*****************************************************************" << endl;
			cout << "��ƷID   ����    �۸�    �ϼ�ʱ��   ����   ����ID   ��Ʒ״̬" << endl;
			cout << good[j].g_id << "   " << good[j].g_name << "   " << good[j].g_price << "   " << good[j].g_sta
				<< "   " << good[j].g_number << "   " << good[j].seller_id << "   " << good[j].g_sta << endl;
			cout << "*****************************************************************" << endl;
			count++;
			break;
		}
	}
	if (count == 0)
	{
		cout << "δ��ѯ������Ʒ" << endl;
		return;
	}
	cout << "��ѡ��y/n):";
	string ch;
	cin >> ch;
	if (ch == "n")
	{
		cout << "ȡ���¼�" << endl;
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
		infile << ch << "UPDATE commodity SET ��Ʒ״̬ =  " << good[j].g_sta<< "WHERE ��ƷID = " << good[j].g_id << endl;
		infile.close();
		cout << "�¼ܳɹ���" << endl;
		return;
	}
	else
	{
		cout << "������󣬼������ز˵�......." << endl;
		return;
	}
}
void Sellers::Seller_checkorders(int i)
{
	int a = orderchuanru();
	cout << "*******************************************************" << endl;
	cout << "����ID   ��ƷID   ���׵���   ����   ����ʱ��   ���ID" << endl;
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