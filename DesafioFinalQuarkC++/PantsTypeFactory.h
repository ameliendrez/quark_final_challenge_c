#ifndef PANTS_TYPE_FACTORY
#define PANTS_TYPE_FACTORY

#include <map>

class PantsType;
enum class PantsTypeType { Common = 1, Chupin = 2 };
class PantsTypeFactory
{
public:
	PantsTypeFactory();
	~PantsTypeFactory() = default;
	static PantsType* GetPantsType(PantsTypeType pantsTypeSelected);
	static std::map<PantsTypeType, PantsType*> getPantsTypeList();
};

#endif //PANTS_TYPE_FACTORY
