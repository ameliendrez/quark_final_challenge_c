#ifndef PANTS
#define PANTS

#include <string>
#include <map>
#include "Clothes.h"
#include "PantsType.h"
#include "Quality.h"

class Pants : public Clothes
{
public:
	Pants(PantsType* pantsType, Quality* quality);
	virtual ~Pants() = default;
	const std::string* getName() const;
	float getRate();
	void setRate(float rate);
	static Pants* selectPants(int pantsSelected);
	void setPantsType(PantsType* pantsType);
	//static std::map<PantsType, Pants*> getConstants();
protected:
	float rate;
	PantsType pantsType;
private:
	const std::string* name;
};

#endif //PANTS