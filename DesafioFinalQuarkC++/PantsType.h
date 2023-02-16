#ifndef PANTS_TYPE
#define PANTS_TYPE

#include <string>
#include <map>
#include "PantsTypeFactory.h"

class PantsType
{
public:
	virtual ~PantsType() = default;
	const std::string* getName() const;
	float getRate();
	void setRate(float rate);
	static PantsType* selectPantsType(int pantsTypeSelected);
	static std::map<PantsTypeType, PantsType*> getConstants();
protected:
	float rate;
private:
	const std::string* name;
};

#endif //PANTS_TYPE