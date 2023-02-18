#ifndef SHIRT
#define SHIRT

#include <string>
#include "Clothes.h"
#include "Neck.h"
#include "Sleeve.h"
#include "Quality.h"

class Shirt : public Clothes
{
public:
	Shirt(int stock, Quality* quality, Neck* neck, Sleeve* sleeve);
	virtual ~Shirt() = default;
	std::string getName() override;
	float calculateFinalPrice() override;
protected:
	Neck* neck;
	Sleeve* sleeve;
};

#endif //SHIRT