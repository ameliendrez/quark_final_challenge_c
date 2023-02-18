#pragma once
#include <list>
#include "Quote.h"
#include "Seller.h"

class SalesChannel
{
public:
	SalesChannel(std::string name, std::string address, Seller* seller);
	std::string getName();
	std::string getAddress();
	Quote* getCurrentQuote();
	Quote* setCurrentQuote(Quote* quote);
	Seller* getCurrentSeller();
	void setCurrentSeller(Seller* seller);
	void createQuote(Clothes* item);
	std::list<Quote*> getQuotes();
	static Clothes* selectClothes(int clothesSelected);
	static std::map<ClothesType, Clothes*> getConstants();
	Quote* saveLastQuote();
private:
	std::string name;
	std::string address;
	std::list<Quote*> quotes;
	Seller* seller;
	Quote* currentQuote;
};

