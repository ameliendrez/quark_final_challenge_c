#include "Shirt.h"

Shirt::Shirt(int stock, Quality* quality, Neck* neck, Sleeve* sleeve): Clothes(stock, quality)
{
	this->neck = neck;
	this->sleeve = sleeve;
}

float Shirt::calculateFinalPrice()
{
	//float rate = this->neck->getRate() + this->sleeve->getRate();
	//return this->price + (this->price * rate);
	auto const finalPrice = this->price + (this->price * this->neck->getRate()) + (this->price * this->sleeve->getRate());
	
	return finalPrice + (finalPrice * this->quality->getRate());
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

