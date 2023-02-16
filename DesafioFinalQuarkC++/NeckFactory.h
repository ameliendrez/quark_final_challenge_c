#ifndef NECK_FACTORY
#define NECK_FACTORY

#include <map>

class Neck;
enum class NeckType { Common = 1, Mao = 2 };
class NeckFactory
{
public:
	NeckFactory();
	~NeckFactory() = default;
	static Neck* GetNeck(NeckType neckSelected);
	static std::map<NeckType, Neck*> getNeckList();
};

#endif //NECK_FACTORY