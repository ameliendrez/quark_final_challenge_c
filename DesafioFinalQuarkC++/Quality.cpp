#include "Quality.h"
#include "QualityFactory.h"

const std::string* Quality::getName() const
{
	return name;
}

float Quality::getRate()
{
	return this->rate;
}
void Quality::setRate(float rate)
{
	this->rate = rate;
}

Quality* Quality::selectQuality(int qualitySelected)
{
	return QualityFactory::GetQuality((QualityType)qualitySelected);
}

std::map<QualityType, Quality*> Quality::getConstants()
{
	return QualityFactory::getQualityList();
}