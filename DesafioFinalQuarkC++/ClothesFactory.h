#ifndef CLOTHES_FACTORY
#define CLOTHES_FACTORY

#include <map>

class Clothes;
enum class ClothesType { CommonPantsStandard = 1, ChupinPantsStandard = 2, CommonPantsPremium = 3, ChupinPantsPremium = 4, ShirtShortMaoStandard = 5,	ShirtShortCommonStandard = 6, ShirtLongMaoStandard = 7, ShirtLongCommonStandard = 8, 	ShirtShortMaoPremium = 9, ShirtShortCommonPremium = 10, 	ShirtLongMaoPremium = 11, ShirtLongCommonPremium = 12 };
class ClothesFactory
{
public:
	ClothesFactory();
	~ClothesFactory() = default;
	static Clothes* GetClothes(ClothesType clothesSelected);
	static std::map<ClothesType, Clothes*> getClothesList();
};

#endif //CLOTHES