#ifndef ADMINISTRATIOR_H
#define ADMINISTRATIOR_H

class Administrator
{
public :
	bool adm_login();
	void adm_manu() ;//�˵�
	void adm_Search();//����
	void good_del();//�¼���Ʒ
	void user_del();//����û�
	void order_look() const;//�鿴���ж���
	void users_look() const;//�鿴�����û�
	void good_look() const;//�鿴������Ʒ
private:
	char adm_name[6] =  "admin" ;
	char  adm_pass[7] = "123456";
};
void Adm_Moudle();


#endif