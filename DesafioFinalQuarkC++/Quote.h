#ifndef QUOTE
#define QUOTE

#include <ctime>
#include "Clothes.h"
#include "Seller.h"

class Quote
{
public:
	Quote(int id, Seller* seller, time_t createdAt, Clothes* item);
	int getId();
	std::string getDateTime();
	int getSellerId();
	std::string getItemDescription();
	float getItemPrice();
	int getQuantity();
	float getGrandTotal();
	void setQuantity(int quantity);
	float getPrice();
	void setPrice(float price);
	int getItemStock();
private:
	int id;
	float price;
	Seller* seller;
	time_t createdAt;
	Clothes* item;
	int quantity;
};

#endif //QUOTE