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
	Pants(int stock, Quality* quality, PantsType* pantsType);
	virtual ~Pants() = default;
	std::string getName() override;
	float calculateFinalPrice() override;
protected:
	PantsType* pantsType;
};

#endif //PANTS