#include "Pants.h"
Pants::Pants(int stock, Quality* quality, PantsType* pantsType) : Clothes(stock, quality)
{
	this->pantsType = pantsType;
}

float Pants::calculateFinalPrice()
{
	return this->price + (this->price * this->pantsType->getRate());
}

std::string Pants::getName()
{
	std::string name;
	name.append(this->pantsType->getName());
	name.append(" ");
	name.append(this->quality->getName());
	name.append(" Pants.");

	return name;
}