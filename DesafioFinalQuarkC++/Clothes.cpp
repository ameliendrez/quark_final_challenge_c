#include "Clothes.h"

#include "ClothesFactory.h"

Clothes::Clothes(int stock, Quality* quality)
{
	this->stock = stock;
	this->quality = quality;
}

float Clothes::calculateFinalPrice()
{
	return this->price + (this->price * this->quality->getRate());
}

Quality* Clothes::getQuality()
{
	return this->quality;
}

void Clothes::setQuality(Quality* quality)
{
	this->quality = quality;
}

float Clothes::getPrice()
{
	return this->price;
}
void Clothes::setPrice(float price)
{
	this->price = price;
}

int Clothes::getStock()
{
	return this->stock;
}
void Clothes::setStock(int stock)
{
	this->stock = stock;
}