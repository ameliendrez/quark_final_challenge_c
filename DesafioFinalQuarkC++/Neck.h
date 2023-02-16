#ifndef NECK
#define NECK

#include <string>
#include <map>
#include "NeckFactory.h"

class Neck
{
public:
	virtual ~Neck() = default;
	const std::string* getName() const;
	float getRate();
	void setRate(float rate);
	static Neck* selectNeck(int neckSelected);
	static std::map<NeckType, Neck*> getConstants();
protected:
	float rate;
private:
	const std::string* name;
};

#endif //NECK