#ifndef CLOTHES
#define CLOTHES

#include "Quality.h"
#include <string>

class Clothes
{
public:
	Clothes(int stock, Quality* quality);
	virtual ~Clothes() = default;
	virtual float calculateFinalPrice();
	virtual std::string getName() = 0;
	Quality* getQuality();
	void setQuality(Quality* quality);
	float getPrice();
	void setPrice(float price);
	int getStock();
	void setStock(int stock);
protected:
	Quality* quality;
	float price;
	int stock;
};


#endif //CLOTHES
