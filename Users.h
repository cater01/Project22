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
	//activeΪ���ڣ�inactiveΪ�����ڣ�������������
};

class Users
{
public :
	void user_manu();//1.������� 2.�������� 3.������Ϣ���� 4.ע����¼
	void self_manage(int i);//������Ϣ����
	void check_info(int i);//�鿴������Ϣ
	void Modify_info(int i);//�޸���Ϣ
	void Modify_money(int i);//��ֵ
	void Modify_name(int i); //�޸��û�����
	void Modify_phone(int i); //�޸��û�����
	void Modify_address(int i);//�޸ĵ�ַ
};
void User_register();//�û�ע��
void User_login();//�û���¼ �ж��û�����������ȷ��
string zhuan(int n);
#endif 