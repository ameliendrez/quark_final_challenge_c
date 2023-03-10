#ifndef NECK
#define NECK

#include <string>
#include <map>
#include "NeckFactory.h"

class Neck
{
	friend class CommonNeck;
	friend class MaoNeck;
public:
	virtual ~Neck() = default;
	const char* getName() const;
	float getRate();
	void setRate(float rate);
	static Neck* selectNeck(int neckSelected);
	static std::map<NeckType, Neck*> getConstants();
protected:
	float rate;
private:
	const char* name;
};

#endif //NECK