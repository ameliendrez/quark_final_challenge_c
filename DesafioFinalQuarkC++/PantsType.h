#ifndef PANTS_TYPE
#define PANTS_TYPE

#include <string>
#include <map>
#include "PantsTypeFactory.h"

class PantsType
{
	friend class ChupinPants;
	friend class CommonPants;
public:
	virtual ~PantsType() = default;
	const char* getName() const;
	float getRate();
	void setRate(float rate);
	static PantsType* selectPantsType(int pantsTypeSelected);
	static std::map<PantsTypeType, PantsType*> getConstants();
protected:
	float rate;
private:
	const char* name;
};

#endif //PANTS_TYPE