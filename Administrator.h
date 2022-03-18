#ifndef ADMINISTRATIOR_H
#define ADMINISTRATIOR_H

class Administrator
{
public :
	bool adm_login();
	void adm_manu() ;//菜单
	void adm_Search();//搜索
	void good_del();//下架商品
	void user_del();//封禁用户
	void order_look() const;//查看所有订单
	void users_look() const;//查看所有用户
	void good_look() const;//查看所有商品
private:
	char adm_name[6] =  "admin" ;
	char  adm_pass[7] = "123456";
};
void Adm_Moudle();


#endif