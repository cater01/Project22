#include"Data.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Users.h"
using namespace std;
struct Good good[10];
struct order order[10];
extern struct User user[10];
void  goodxieru(int i)
{
	fstream infile("good.txt", ios::out);
	infile << "commodityID,commodityName,price,number,description,sellerID,addedDate,state" << endl;

	for (int c = 0; c < i; c++)
	{
		infile << good[c].g_id << "," << good[c].g_name << "," << good[c].g_price << "," << good[c].g_number << ","
			<< good[c].g_info << "," << good[c].seller_id << "," << good[c].g_time << "," << good[c].g_sta << endl;
	}
	infile.close();
}
void  orderxieru(int i)
{
	fstream infile("order.txt", ios::out);
	infile << "orderID,commodityID,unitPrice,number,date,sellerID,buyerID" << endl;
	for (int m = 0; m <= i; m++)
	{
		infile << order[m].order_id << "," << order[m].good_id << "," << order[m].good_price << "," << order[m].good_nmuber << ","
			<< order[m].Trade_time << "," << order[m].seller_id << "," << order[m].buyer_id << endl;
	}
	infile.close();
}
void  userxieru(int i)
{
	fstream ifile("user.txt", ios::out);
	ifile << "userID,username,password,phoneNumber,address,balance,userState" << endl;

	for (int k = 0; k < i; k++)
	{	
		ifile << user[k].u_id << "," << user[k].u_name << "," << user[k].u_password << "," << user[k].u_phone << ","
			<< user[k].u_address << "," << user[k].u_balance << "," << user[k].u_State << endl;
	}
	ifile.close();
}
int goodchuanru()
{
	fstream infile("good.txt", ios::in);
	string temp;
	infile >> temp;
	int i = 0;
	while (infile >> temp)
	{
		int j = 0;
		string tempid;
		for (; temp[j] != ','; j++)
		{
			tempid += temp[j];
		}
		good[i].g_id = tempid;
		j++;
		string tempgm;
		for (; temp[j] != ','; j++)
		{
			tempgm += temp[j];
		}
		good[i].g_name = tempgm;
		j++;
		string temp_price;
		for (; temp[j] != ','; j++)
		{
			temp_price += temp[j];
		}//stod()
		good[i].g_price = stod(temp_price);
		j++;
		string temp_number;
		for (; temp[j] != ','; j++)
		{
			temp_number += temp[j];
		}//stoi()
		good[i].g_number = stoi(temp_number);
		j++;
		string tempif;
		for (; temp[j] != ','; j++)
		{
			tempif += temp[j];
		}
		good[i].g_info = tempif;
		j++;
		string tmseller;
		for (; temp[j] != ','; j++)
		{
			tmseller += temp[j];
		}
		good[i].seller_id = tmseller;
		j++;
		string tempgtime;
		for (; temp[j] != ','; j++)
		{
			tempgtime += temp[j];
		}
		good[i].g_time = tempgtime;
		j++;
		string tempsta;
		for (; j < temp.length(); j++)
		{
			tempsta += temp[j];
		}
		good[i].g_sta = tempsta;
		i++;
	}
	infile.close();
	return i;
}

int orderchuanru()
{
	fstream infile("order.txt", ios::in);
	string temp;
	infile >> temp;
	int i = 0;
	while (infile >> temp)
	{
		int j = 0;
		string tempid;
		for (; temp[j] != ','; j++)
		{
			tempid += temp[j];
		}
		order[i].order_id = tempid;
		j++;
		string tempgid;
		for (; temp[j] != ','; j++)
		{
			tempgid += temp[j];
		}
		order[i].good_id = tempgid; j++;
		string temp_price;
		for (; temp[j] != ','; j++)
		{
			temp_price += temp[j];
		}
		order[i].good_price = stod(temp_price);
		j++;
		string temp_number;
		for (; temp[j] != ','; j++)
		{
			temp_number += temp[j];
		}//stoi()
		order[i].good_nmuber = stoi(temp_number);
		j++;
		string temptime;
		for (; temp[j] != ','; j++)
		{
			temptime += temp[j];
		}
		order[i].Trade_time = temptime; j++;
		string tempsid;
		for (; temp[j] != ','; j++)
		{
			tempsid += temp[j];
		}
		order[i].seller_id = tempsid; j++;
		string tempbuyid;
		for (; j < temp.length(); j++)
		{
			tempbuyid += temp[j];
		}
		order[i].buyer_id = tempbuyid;
		i++;
	}
	infile.close();
	return i;
}

int userchuanru()
{
	fstream infile("User.txt", ios::in);
	string temp;
	infile >> temp;
	int i = 0;
	while (infile >> temp)
	{
		int j = 0;
		string tempuid;
		for (; temp[j] != ','; j++)
		{
			tempuid += temp[j];
		}
		user[i].u_id = tempuid; j++;
		string tempuname;
		for (; temp[j] != ','; j++)
		{
			tempuname += temp[j];
		}
		user[i].u_name = tempuname; j++;
		string tempkey;
		for (; temp[j] != ','; j++)
		{
			tempkey += temp[j];
		}
		user[i].u_password = tempkey; j++;
		string tempup;
		for (; temp[j] != ','; j++)
		{
			tempup += temp[j];
		}
		user[i].u_phone = tempup; j++;
		string tempadd;
		for (; temp[j] != ','; j++)
		{
			tempadd += temp[j];
		}
		user[i].u_address = tempadd; j++;
		string temp_price;
		for (; temp[j] != ','; j++)
		{
			temp_price += temp[j];
		}
		user[i].u_balance = stod(temp_price); j++;
		string tempusta;
		for (; j < temp.length(); j++)
		{
			tempusta += temp[j];
		}
		user[i].u_State = tempusta;
		i++;
	}
	infile.close();
	return i;
}