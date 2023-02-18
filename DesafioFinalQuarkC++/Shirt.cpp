#include "Shirt.h"

Shirt::Shirt(int stock, Quality* quality, Neck* neck, Sleeve* sleeve): Clothes(stock, quality)
{
	this->neck = neck;
	this->sleeve = sleeve;
}

float Shirt::calculateFinalPrice()
{
	return this->price + (this->price * this->neck->getRate()) + (this->price * this->sleeve->getRate());
}

std::string Shirt::getName()
{
	std::string name;
	name.append(this->sleeve->getName());
	name.append(" ");
	name.append(this->neck->getName());
	name.append(" ");
	name.append(this->quality->getName());
	name.append(" Shirt.");
	
	return name;
}

