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
	auto commonStandardPants = new Pants(commonPantType, standardQuality);
	auto commonPremiumPants = new Pants(commonPantType, premiumQuality);

	// INIT CHUPIN PANTS
	auto chupinStandardPants = new Pants(chupinPantType, standardQuality);
	auto chupinPremiumPants = new Pants(chupinPantType, premiumQuality);

	// INIT SHIRTS MAO STANDARD
	auto shirtShortMaoStandard = new Shirt(maoNeck, shortSleeve, standardQuality);
	auto shirtLongMaoStandard = new Shirt(maoNeck, longSleeve, standardQuality);

	// INIT SHIRTS MAO PREMIUM
	auto shirtShortMaoPremium = new Shirt(maoNeck, shortSleeve, premiumQuality);
	auto shirtLongMaoPremium = new Shirt(maoNeck, longSleeve, premiumQuality);

	// INIT SHIRTS COMMON STANDARD
	auto shirtShortCommonStandard = new Shirt(commonNeck, shortSleeve, standardQuality);
	auto shirtLongCommonStandard = new Shirt(commonNeck, longSleeve, standardQuality);

	// INIT SHIRTS COMMON PREMIUM
	auto shirtShortCommonPremium = new Shirt(commonNeck, shortSleeve, premiumQuality);
	auto shirtLongCommonPremium = new Shirt(commonNeck, longSleeve, premiumQuality);
	
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
