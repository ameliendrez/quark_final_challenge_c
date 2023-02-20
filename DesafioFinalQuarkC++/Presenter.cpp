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

void Presenter::clearQuoteCreation()
{
	this->salesChannel->clearCurrentQuote();
}

void Presenter::createQuotePant()
{
	int id = this->salesChannel->getPantId(this->lastSelectedPantsType, this->lastSelectedQuality);
	Clothes* pant = this->salesChannel->selectClothes(id);
	this->salesChannel->createQuote(pant);
}

void Presenter::createQuoteShirt()
{
	int id = this->salesChannel->getShirtId(this->lastSelectedSleeve, this->lastSelectedNeck, this->lastSelectedQuality);
	Clothes* shirt = this->salesChannel->selectClothes(id);
	this->salesChannel->createQuote(shirt);
}

void Presenter::setPriceToQuote(float price)
{
	this->salesChannel->setPriceToQuote(price);
}

int Presenter::getCurrentStock()
{
	return this->salesChannel->getCurrentQuote()->getItemStock();
}

void Presenter::setStockToQuote(int stock)
{
	this->salesChannel->setStockToQuote(stock);
}


std::string Presenter::getLastSelectedSleeve()
{
	return this->lastSelectedSleeve;
}

std::string Presenter::getLastSelectedNeck()
{
	return this->lastSelectedNeck;
}


std::string Presenter::getLastSelectedPantsType()
{
	return this->lastSelectedPantsType;
}


std::string Presenter::getLastSelectedQuality()
{
	return this->lastSelectedQuality;
}

void Presenter::setLastSelectedSleeve(std::string selectedSleeve)
{
	this->lastSelectedSleeve = selectedSleeve;
}

void Presenter::setLastSelectedNeck(std::string selectedNeck)
{
	this->lastSelectedNeck = selectedNeck;
}

void Presenter::setLastSelectedPantsType(std::string selectedPantsType)
{
	this->lastSelectedPantsType = selectedPantsType;
}

void Presenter::setLastSelectedQuality(std::string selectedQuality)
{
	this->lastSelectedQuality = selectedQuality;
}
