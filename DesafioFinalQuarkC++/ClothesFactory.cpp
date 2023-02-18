#include "ClothesFactory.h"
#include "Neck.h"
#include "Sleeve.h"
#include "Clothes.h"
#include "Shirt.h"
#include "Pants.h"
#include "PantsType.h"

ClothesFactory::ClothesFactory() = default;

Clothes* ClothesFactory::GetClothes(ClothesType clothesSelected)
{
	auto Clothess = getClothesList();
	if (Clothess.count(clothesSelected) == 0) {
		return nullptr;
	}
	auto item = Clothess[clothesSelected];
	return item;
}

std::map<ClothesType, Clothes*> ClothesFactory::getClothesList()
{
	// GET NECKS TYPES
	auto commonNeck = Neck::selectNeck(1);
	auto maoNeck = Neck::selectNeck(2);

	// GET SELEEVES TYPES
	auto longSleeve = Sleeve::selectSleeve(1);
	auto shortSleeve = Sleeve::selectSleeve(2);

	// GET PANTS TYPES
	auto commonPantType = PantsType::selectPantsType(1);
	auto chupinPantType = PantsType::selectPantsType(2);

	// GET QUALITYS
	auto standardQuality = Quality::selectQuality(1);
	auto premiumQuality = Quality::selectQuality(2);

	// INIT COMMON PANTS
	auto commonStandardPants = new Pants(250, standardQuality, commonPantType);
	auto commonPremiumPants = new Pants(250, premiumQuality, commonPantType);

	// INIT CHUPIN PANTS
	auto chupinStandardPants = new Pants(750, standardQuality, chupinPantType);
	auto chupinPremiumPants = new Pants(750, premiumQuality, chupinPantType);

	// INIT SHIRTS SHORTS MAO
	auto shirtShortMaoStandard = new Shirt(100, standardQuality, maoNeck, shortSleeve);
	auto shirtShortMaoPremium = new Shirt(100, premiumQuality, maoNeck, shortSleeve );

	// INIT SHIRTS SHORTS COMMON
	auto shirtShortCommonStandard = new Shirt(150, standardQuality, commonNeck, shortSleeve);
	auto shirtShortCommonPremium = new Shirt(150, premiumQuality, commonNeck, shortSleeve);

	// INIT SHIRTS LONG MAO
	auto shirtLongMaoStandard = new Shirt(75, standardQuality, maoNeck, longSleeve);
	auto shirtLongMaoPremium = new Shirt(75, premiumQuality, maoNeck, longSleeve);

	// INIT SHIRTS LONG COMMON
	auto shirtLongCommonStandard = new Shirt(175, standardQuality, commonNeck, longSleeve);
	auto shirtLongCommonPremium = new Shirt(175, premiumQuality, commonNeck, longSleeve);
	
	
	return std::map<ClothesType, Clothes*> {
		{ ClothesType::CommonPantsStandard, commonStandardPants },
		{ ClothesType::CommonPantsPremium, commonPremiumPants },
		{ ClothesType::ChupinPantsStandard, chupinStandardPants },
		{ ClothesType::ChupinPantsPremium, chupinPremiumPants },
		{ ClothesType::ShirtShortMaoStandard, shirtShortMaoStandard },
		{ ClothesType::ShirtLongMaoStandard, shirtLongMaoStandard },
		{ ClothesType::ShirtShortMaoPremium, shirtShortMaoPremium },
		{ ClothesType::ShirtLongMaoPremium, shirtLongMaoPremium },
		{ ClothesType::ShirtShortCommonStandard, shirtShortCommonStandard },
		{ ClothesType::ShirtLongCommonStandard, shirtLongCommonStandard },
		{ ClothesType::ShirtShortCommonPremium, shirtShortCommonPremium },
		{ ClothesType::ShirtLongCommonPremium, shirtLongCommonPremium }
	};
}
