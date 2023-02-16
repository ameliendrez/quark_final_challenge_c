#ifndef SLEEVE_FACTORY
#define SLEEVE_FACTORY

#include <map>

class Sleeve;
enum class SleeveType { Long = 1, Short = 2 };
class SleeveFactory
{
public:
	SleeveFactory();
	~SleeveFactory() = default;
	static Sleeve* GetSleeve(SleeveType sleeveSelected);
	static std::map<SleeveType, Sleeve*> getSleeveList();
};

#endif //SLEEVE_FACTORY