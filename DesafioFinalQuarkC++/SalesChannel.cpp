#include "SalesChannel.h"
#include <iostream>
#include <ctime>

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

Quote* SalesChannel::setCurrentQuote(Quote* quote)
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
