#include "SalesChannel.h"
#include <iostream>
#include <ctime>

#include "Presenter.h"

SalesChannel::SalesChannel(std::string name, std::string address, Seller* seller)
{
	this->name = name;
	this->address = address;
	this->seller = seller;
}

std::string SalesChannel::getName()
{
	return this->name;
}

std::string SalesChannel::getAddress()
{
	return this->address;
}

Seller* SalesChannel::getCurrentSeller()
{
	return this->seller;
}

void SalesChannel::setCurrentSeller(Seller* seller)
{
	this->seller = seller;
}

void SalesChannel::createQuote(Clothes* item)
{
	int quoteId = this->quotes.size() + 1;
	Quote* quote = new Quote(quoteId, this->seller, time(0), item);
	this->setCurrentQuote(quote);
}

std::list<Quote*> SalesChannel::getQuotes()
{
	return this->quotes;
}

Clothes* SalesChannel::selectClothes(int clothesSelected)
{
	return ClothesFactory::GetClothes((ClothesType)clothesSelected);
}

std::map<ClothesType, Clothes*> SalesChannel::getConstants()
{
	return ClothesFactory::getClothesList();
}

Quote* SalesChannel::getCurrentQuote()
{
	return this->currentQuote;
}

void SalesChannel::setCurrentQuote(Quote* quote)
{
	this->currentQuote = quote;
}

Quote* SalesChannel::saveLastQuote()
{
	Quote* quote = this->currentQuote;
	this->currentQuote = nullptr;
	this->quotes.push_front(quote);

	return quote;
}

void SalesChannel::setPriceToQuote(float price)
{
	this->currentQuote->setPrice(price);
}

void SalesChannel::setStockToQuote(int stock)
{
	this->currentQuote->setQuantity(stock);
}

void SalesChannel::clearCurrentQuote()
{
	Quote* quote = this->currentQuote;
	this->currentQuote = nullptr;
	delete quote;
}


int SalesChannel::getPantId(std::string optionType, std::string optionQuality)
{
	int id;
	if (optionType == "1" && optionQuality == "1")
	{
		id = 2;
	}
	else if (optionType == "1" && optionQuality == "2")
	{
		id = 4;
	}
	else if (optionType == "2" && optionQuality == "1")
	{
		id = 1;
	}
	else if (optionType == "2" && optionQuality == "2")
	{
		id = 3;
	}

	return id;
}

int SalesChannel::getShirtId(std::string optionSleeve, std::string optionNeck, std::string optionQuality)
{
	int id;

	if (optionSleeve == "1" && optionNeck == "1" && optionQuality == "1")
	{
		id = 5;
	}
	else if (optionSleeve == "1" && optionNeck == "1" && optionQuality == "2")
	{
		id = 9;
	}
	else if (optionSleeve == "1" && optionNeck == "2" && optionQuality == "1")
	{
		id = 6;
	}
	else if (optionSleeve == "1" && optionNeck == "2" && optionQuality == "2")
	{
		id = 10;
	}
	else if (optionSleeve == "2" && optionNeck == "1" && optionQuality == "1")
	{
		id = 7;
	}
	else if (optionSleeve == "2" && optionNeck == "1" && optionQuality == "2")
	{
		id = 11;
	}
	else if (optionSleeve == "2" && optionNeck == "2" && optionQuality == "1")
	{
		id = 8;
	}
	else if (optionSleeve == "2" && optionNeck == "2" && optionQuality == "2")
	{
		id = 12;
	}

	return id;
}