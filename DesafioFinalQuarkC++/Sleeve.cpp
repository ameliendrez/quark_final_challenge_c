#include "Sleeve.h"
#include "SleeveFactory.h"

const std::string* Sleeve::getName() const
{
	return name;
}

float Sleeve::getRate()
{
	return this->rate;
}
void Sleeve::setRate(float rate)
{
	this->rate = rate;
}

Sleeve* Sleeve::selectSleeve(int sleeveSelected)
{
	return SleeveFactory::GetSleeve((SleeveType)sleeveSelected);
}

std::map<SleeveType, Sleeve*> Sleeve::getConstants()
{
	return SleeveFactory::getSleeveList();
}