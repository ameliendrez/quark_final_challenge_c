#ifndef QUALITY
#define QUALITY

#include <string>
#include <map>
#include "QualityFactory.h"

class Quality
{
	friend class StandardQuality;
	friend class PremiumQuality;
public:
	virtual ~Quality() = default;
	const char* getName() const;
	float getRate();
	void setRate(float rate);
	static Quality* selectQuality(int qualitySelected);
	static std::map<QualityType, Quality*> getConstants();
protected:
	float rate;
private:
	const char* name;
};

#endif //QUALITY