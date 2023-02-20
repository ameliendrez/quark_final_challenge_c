#include "Quote.h"
#include <ctime>

Quote::Quote(int id, Seller* seller, time_t createdAt, Clothes* item)
{
	this->id = id;
	this->seller = seller;
	this->createdAt = createdAt;
	this->item = item;
}

int Quote::getId()
{
	return this->id;
}

std::string Quote::getDateTime()
{
	struct tm* time = new tm();
	char dateTime[64];
	localtime_s(time, &this->createdAt);
	std::strftime(dateTime, sizeof dateTime, "%d/%m/%Y %H:%M:%S", time);

	delete time;
	
	return dateTime;
}

int Quote::getSellerId()
{
	return this->seller->getId();
}

std::string Quote::getItemDescription()
{
	return this->item->getName();
}

float Quote::getItemPrice()
{
	return this->price;
}

int Quote::getQuantity()
{
	return this->quantity;
}

float Quote::getGrandTotal()
{
	return this->price * this->quantity;
}

void Quote::setQuantity(int quantity)
{
	this->quantity = quantity;
}

float Quote::getPrice()
{
	return this->price;
}

void Quote::setPrice(float price)
{
	this->item->setPrice(price);
	this->price = this->item->calculateFinalPrice();
}

int Quote::getItemStock()
{
	return this->item->getStock();
}
