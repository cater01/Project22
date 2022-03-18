#ifndef BUYERS_H
#define BUYERS_H

#include"Users.h"
#include"Data.h"

class Buyers :public Users
{
public:
	void buyer_manu();//菜单
	void Buying(int i);//购买商品
	void one();//查看商品详细信息
	void goodsearch();//搜索商品
	void Buyer_checkgoods();//查看商品
	void Buyer_checkorders(int i);//查看历史订单
};
void Buyer_Moudle(int i);

#endif
