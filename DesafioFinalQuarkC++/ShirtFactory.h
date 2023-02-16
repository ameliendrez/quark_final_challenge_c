#ifndef PANTS_FACTORY
#define PANTS_FACTORY

#include <map>

class Pants;
enum class PantsType { Common = 1, Chupin = 2 };
class PantsFactory
{
public:
	PantsFactory();
	~PantsFactory() = default;
	static Pants* GetPants(PantsType pantsSelected);
	static std::map<PantsType, Pants*> getPantsList();
};

#endif //PANTS_FACTORY
