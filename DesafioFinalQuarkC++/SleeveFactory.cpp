#include "SleeveFactory.h"
#include "Sleeve.h"
#include "LongSleeve.h"
#include "ShortSleeve.h"

SleeveFactory::SleeveFactory() = default;

Sleeve* SleeveFactory::GetSleeve(SleeveType sleeveSelected)
{
	auto Sleeves = getSleeveList();
	if (Sleeves.count(sleeveSelected) == 0) {
		return nullptr;
	}
	auto item = Sleeves[sleeveSelected];
	return item;
}

std::map<SleeveType, Sleeve*> SleeveFactory::getSleeveList()
{
	auto longSleeve = new LongSleeve();
	auto shortSleeve = new ShortSleeve();

	return std::map<SleeveType, Sleeve*> {
		{ SleeveType::Long, longSleeve },
		{ SleeveType::Short, shortSleeve }
	};
}
