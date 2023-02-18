#include "Presenter.h"
#include "IView.h"
#include "SalesChannel.h"

Presenter::Presenter(IView* view) : mView(view)
{
	Seller* seller = new Seller("Agustin", "Meliendrez", 1);
	this->salesChannel = new SalesChannel("AGME ropa", "calle 123, Tandil, Buenos Aires", seller);
}

Presenter::~Presenter()
{
	delete salesChannel;
};


void Presenter::getSalesChannelName()
{
	this->mView->showTextInLine(this->salesChannel->getName());
}

void Presenter::getSalesChannelAddress()
{
	this->mView->showText(this->salesChannel->getAddress());
}

void Presenter::getSalesChannelSellerName()
{
	this->mView->showTextInLine(this->salesChannel->getCurrentSeller()->getName());
}

void Presenter::getSalesChannelSellerId()
{
	this->mView->showText(std::to_string(this->salesChannel->getCurrentSeller()->getId()));
}

void Presenter::getSalesChannelQuoteHistory()
{
	std::list<Quote*> quotes = this->salesChannel->getQuotes();

	if (!quotes.empty())
	{
		for (auto const& quote : quotes)
		{
			this->showQuoteIntormation(quote);
		}
	}
	else
	{
		this->mView->showText("No hay cotizaciones realizadas");
	}
}

void Presenter::showQuoteIntormation(Quote* quote)
{
	this->mView->showTextInLine("Numero de identificacion: ");
	this->mView->showText(quote->getId());

	this->mView->showTextInLine("Fecha y hora de la cotizacion: ");
	this->mView->showText(quote->getDateTime());

	this->mView->showTextInLine("Codigo del vendedor: ");
	this->mView->showText(quote->getSellerId());

	this->mView->showTextInLine("Prenda Cotizada: ");
	this->mView->showText(quote->getItemDescription());

	this->mView->showTextInLine("Precio unitario: $$");
	this->mView->showText(quote->getItemPrice());

	this->mView->showTextInLine("Cantidad de unidades cotizadas: ");
	this->mView->showText(quote->getQuantity());

	this->mView->showTextInLine("Precio final: $$");
	this->mView->showText(quote->getGrandTotal());
}

void Presenter::finishQuote()
{
	Quote* quote = this->salesChannel->saveLastQuote();
	this->showQuoteIntormation(quote);
}

void Presenter::createQuoteShirt(const char* optionSleeve, const char* optionNeck, const char* optionQuality)
{
	int id = getShirtId(optionSleeve, optionNeck, optionQuality);
	Clothes* shirt = this->salesChannel->selectClothes(id);
	this->salesChannel->createQuote(shirt);
}

void Presenter::createQuotePant(const char* optionType, const char* optionQuality)
{
	int id = getPantId(optionType, optionQuality);
	Clothes* pant = this->salesChannel->selectClothes(id);
	this->salesChannel->createQuote(pant);
}

void Presenter::setPriceToQuote(float price)
{
	this->salesChannel->getCurrentQuote()->setPrice(price);
}

int Presenter::getCurrentStock()
{
	return this->salesChannel->getCurrentQuote()->getItemStock();
}

void Presenter::setStockToQuote(int stock)
{
	this->salesChannel->getCurrentQuote()->setQuantity(stock);
}
int Presenter::getPantId(const char* optionType, const char* optionQuality)
{
	int id;
	if (optionType == "1" && optionQuality == "1")
	{
		id = 2;
	}
	else if(optionType == "1" && optionQuality == "2")
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
}

int Presenter::getShirtId(const char* optionSleeve, const char* optionNeck, const char* optionQuality)
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
