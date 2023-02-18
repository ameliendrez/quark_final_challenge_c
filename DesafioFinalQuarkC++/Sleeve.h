#ifndef SLEEVE
#define SLEEVE

#include <map>
#include "SleeveFactory.h"

class Sleeve
{
	friend class ShortSleeve;
	friend class LongSleeve;
public:
	virtual ~Sleeve() = default;
	const char* getName() const;
	float getRate();
	void setRate(float rate);
	static Sleeve* selectSleeve(int SleeveSelected);
	static std::map<SleeveType, Sleeve*> getConstants();
protected:
	float rate;
private:
	const char* name;
};

#endif //SLEEVE