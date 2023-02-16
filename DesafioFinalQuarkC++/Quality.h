#ifndef QUALITY
#define QUALITY

#include <string>
#include <map>
#include "QualityFactory.h"

class Quality
{
public:
	virtual ~Quality() = default;
	const std::string* getName() const;
	float getRate();
	void setRate(float rate);
	static Quality* selectQuality(int qualitySelected);
	static std::map<QualityType, Quality*> getConstants();
protected:
	float rate;
private:
	const std::string* name;
};

#endif //QUALITY