#ifndef SHIRT
#define SHIRT

#include <string>
#include <map>
#include "Clothes.h"
#include "Neck.h"
#include "Sleeve.h"
#include "Quality.h"

class Shirt : public Clothes
{
public:
	Shirt(Neck* neck, Sleeve* sleeve, Quality* quality);
	virtual ~Shirt() = default;
	const std::string* getName() const;
	float getRate();
	void setRate(float rate);
	static Shirt* selectShirt(int shirtSelected);
	void setNeck(Neck* neck);
	void setSleeve(Sleeve* sleeve);
	//static std::map<ShirtType, Shirt*> getConstants();
protected:
	float rate;
	Neck neck;
	Sleeve sleeve;
private:
	const std::string* name;
};

#endif //SHIRT