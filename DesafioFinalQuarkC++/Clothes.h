#ifndef CLOTHES
#define CLOTHES

#include "ClothesFactory.h"
#include "Quality.h"
#include <string>
#include <map>

class Clothes
{
public:
	Clothes(int stock, Quality* quality);
	virtual ~Clothes() = default;
	virtual float calculateFinalPrice();
	virtual std::string getName();
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
