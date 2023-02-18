#include "Quote.h"


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
	return std::to_string(this->createdAt);
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
	return this->item->calculateFinalPrice() * this->quantity;
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
	this->price = price;
}

int Quote::getItemStock()
{
	return this->item->getStock();
}
