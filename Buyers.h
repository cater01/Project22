#ifndef BUYERS_H
#define BUYERS_H

#include"Users.h"
#include"Data.h"

class Buyers :public Users
{
public:
	void buyer_manu();//�˵�
	void Buying(int i);//������Ʒ
	void one();//�鿴��Ʒ��ϸ��Ϣ
	void goodsearch();//������Ʒ
	void Buyer_checkgoods();//�鿴��Ʒ
	void Buyer_checkorders(int i);//�鿴��ʷ����
};
void Buyer_Moudle(int i);

#endif
