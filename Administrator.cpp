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
	cout << "���������Ա������";
	cin >> temp;
	cout << "���������룺";
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
	cout << "1.�鿴������Ʒ 2.������Ʒ 3.�¼���Ʒ 4.�鿴���ж��� 5.�鿴�����û� 6.����û� 7.ע��" <<endl;
	cout << "====================================================================================" <<endl;
	cout << endl;
}

void Adm_Moudle()
{
	Administrator liu;
	if (liu.adm_login() != true)
	{
		cout << "----������󣬵�½ʧ�ܣ��������˵�----" << endl;
		return;
	}
	else
	{
		cout << "-----��½�ɹ�-----" << endl;
	}

	while (true)
	{
		liu.adm_manu();
		int opt = 0;
		cout << "�����������";
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
			cout << "����������......" << endl;
			return;
		}
		default:cout << "�������������!" << endl;
		 break;
		}
	}
}

void Administrator::adm_Search()
{
	//ofstream outfile("good.txt",ios::out);
	int i= goodchuanru();
	cout << "��������Ʒ���ƣ�" << endl;
	char g_name1[21];
	cin >> g_name1;
	int count = 0;
	cout << "**************************************************************" << endl;
	cout << "��ƷID   ����   �۸�     �ϼ�ʱ��     ����ID   ����   ��Ʒ״̬" << endl;
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
			infile << ch << " SELECT * FROM commodity WHERE ���� CONTAINS" << g_name1 << endl;
			infile.close();
		}
	}
	if (count == 0)
	{
		cout << "û���ҵ�����Ҫ����Ʒ�����س�ʼ����" << endl;
	}
	cout << "**************************************************************" << endl;
	
 }//������Ʒ��Ϣ

void Administrator::good_look() const
{	
	int i = goodchuanru();
	cout << "****************************************************************" << endl;
	cout << "��ƷID   ����   �۸�     �ϼ�ʱ��     ����ID   ����   ��Ʒ״̬" << endl;
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
}//���good�ļ�������

void Administrator::order_look ()const
{
	int i = orderchuanru();
	cout << "*****************************************************************" << endl;
	cout << "����ID   ��ƷID   ���׵���   ����      ����ʱ��    ����ID   ���ID" << endl;
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
}//�����������

void Administrator::users_look()const
{
	int i = userchuanru();
	cout << "**********************************************************" << endl;
	cout << "�û�ID   �û���    ��ϵ��ʽ    ��ַ    Ǯ�����   �û�״̬ " << endl;

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
}//����û���Ϣ

void Administrator::good_del()
{
	cout << "������Ҫ�¼ܵ���ƷID��";
	char tempgoodid[5];
	cin >> tempgoodid;
	cout << "ȷ��Ҫ�¼ܸ���Ʒ��" << endl;
	int count = 0;
	int i = goodchuanru();
	cout << "***********************************************************************" << endl;
	cout << "��ƷID   ��Ʒ����    �۸�   �ϼ�ʱ��    ����ID    ��������     ����״̬" << endl;
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
		cout << "û���ҵ�����Ҫ����Ʒ�����س�ʼ����" << endl;
	}
	cout << "***********************************************************************" << endl;
	if (count != 0)
	{
		cout << "��ѡ��y/n����";
	}
		char a;
		cin >> a;
	if (a != 'y' && a != 'n')
	{
		cout << "�����������������..." << endl;
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
				infile << ch << "UPDATE commodity SET ��Ʒ״̬ = ���¼� WHERE ��ƷID =" << good[j].g_id << endl;
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
		cout << "�¼ܳɹ�" << endl;
		return;
	}
	if(a=='n')
	{
		cout << "ȡ���¼�"<<endl; return;
	}
}

void Administrator::user_del()
{
	cout << "������Ҫ������û�ID��" ;
	char tempuserid[5];
	cin >> tempuserid;
	cout << "ȷ��Ҫ������û���" << endl;
	int count = 0;
	int i = userchuanru();
	int c = goodchuanru();
	cout << "******************************************************" << endl;
	cout << "�û�id    �û���   ��ϵ��ʽ        ��ַ        Ǯ����� " << endl;
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
		cout << "û���ҵ�����Ҫ�ķ�����û������س�ʼ����" << endl;
	}
	cout << "******************************************************" << endl;
	if (count != 0)
	{
		cout << "��ѡ��y/n����";
	}
	char a;
	cin >> a;
	if (a != 'y' && a != 'n')
	{
		cout << "�����������������..." << endl;
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
				infile << ch << "UPDATE user SET �û�״̬ = ��� WHERE �û�ID = " << user[j].u_id<< endl;
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
						infile << ch << "UPDATE commodity SET ��Ʒ״̬ = ���¼� WHERE ����ID =  " << good[k].seller_id << endl;
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
		cout << "����ɹ�"<<endl;
		return;
	}
	if (a == 'n')
	{
		cout << "ȡ�����"<<endl; return;
	}
}
