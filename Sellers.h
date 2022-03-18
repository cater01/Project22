#ifndef SELLERS_H
#define SELLERS_H

#include"Users.h"

class Sellers :public Users
{
public:
	void Seller_manu();
	void Selling(int i);
	void Deselling(int i);
	void Modify_good(int i);
	void Seller_checkgoods(int i);
	void Seller_checkorders(int i);
};
void Seller_Moudle(int i);
#endif // !SELLERS_H
