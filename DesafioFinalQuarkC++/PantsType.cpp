#include "PantsType.h"
#include "PantsTypeFactory.h"

const std::string* PantsType::getName() const
{
	return name;
}

float PantsType::getRate()
{
	return this->rate;
}
void PantsType::setRate(float rate)
{
	this->rate = rate;
}

PantsType* PantsType::selectPantsType(int pantsTypeSelected)
{
	return PantsTypeFactory::GetPantsType((PantsTypeType)pantsTypeSelected);
}

std::map<PantsTypeType, PantsType*> PantsType::getConstants()
{
	return PantsTypeFactory::getPantsTypeList();
}