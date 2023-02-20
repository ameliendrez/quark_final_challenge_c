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
	int getQuantity();
	float getGrandTotal();
	float getPrice();
	int getItemStock();
	void setPrice(float price);
	void setQuantity(int quantity);
private:
	int id;
	float price;
	Seller* seller;
	time_t createdAt;
	Clothes* item;
	int quantity;
};

#endif //QUOTE