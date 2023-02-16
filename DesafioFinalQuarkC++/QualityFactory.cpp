#include "QualityFactory.h"
#include "Quality.h"
#include "StandardQuality.h"
#include "PremiumQuality.h"

QualityFactory::QualityFactory() = default;

Quality* QualityFactory::GetQuality(QualityType qualitySelected)
{
	auto qualitys = getQualityList();
	if (qualitys.count(qualitySelected) == 0) {
		return nullptr;
	}
	auto item = qualitys[qualitySelected];
	return item;
}

std::map<QualityType, Quality*> QualityFactory::getQualityList()
{
	auto standarQuality = new StandardQuality();
	auto premiumQuality = new PremiumQuality();

	return std::map<QualityType, Quality*> {
		{ QualityType::Standard, standarQuality },
		{ QualityType::Premium, premiumQuality },
	};
}
