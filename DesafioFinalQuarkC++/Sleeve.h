#ifndef SLEEVE
#define SLEEVE

#include <string>
#include <map>
#include "SleeveFactory.h"

class Sleeve
{
public:
	virtual ~Sleeve() = default;
	const std::string* getName() const;
	float getRate();
	void setRate(float rate);
	static Sleeve* selectSleeve(int SleeveSelected);
	static std::map<SleeveType, Sleeve*> getConstants();
protected:
	float rate;
private:
	const std::string* name;
};

#endif //SLEEVE