#pragma once
#include <list>

#include "ClothesFactory.h"
#include "Quote.h"
#include "Seller.h"

class SalesChannel
{
public:
	SalesChannel(std::string name, std::string address, Seller* seller);
	std::string getName();
	std::string getAddress();
	Quote* getCurrentQuote();
	void setCurrentQuote(Quote* quote);
	Seller* getCurrentSeller();
	void setCurrentSeller(Seller* seller);
	void createQuote(Clothes* item);
	std::list<Quote*> getQuotes();
	static Clothes* selectClothes(int clothesSelected);
	static std::map<ClothesType, Clothes*> getConstants();
	Quote* saveLastQuote();
	int getShirtId(std::string optionSleeve, std::string optionNeck, std::string optionQuality);
	int getPantId(std::string optionType, std::string optionQuality);
	void setPriceToQuote(float price);
	void setStockToQuote(int stock);
	void clearCurrentQuote();
private:
	std::string name;
	std::string address;
	std::list<Quote*> quotes;
	Seller* seller;
	Quote* currentQuote;
};

