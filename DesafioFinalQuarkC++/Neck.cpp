#include "Neck.h"
#include "NeckFactory.h"

const char* Neck::getName() const
{
	return name;
}

float Neck::getRate()
{
	return this->rate;
}
void Neck::setRate(float rate)
{
	this->rate = rate;
}

Neck* Neck::selectNeck(int neckSelected)
{
	return NeckFactory::GetNeck((NeckType)neckSelected);
}

std::map<NeckType, Neck*> Neck::getConstants()
{
	return NeckFactory::getNeckList();
}