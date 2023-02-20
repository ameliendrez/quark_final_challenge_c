#ifndef PRESENTER_H
#define PRESENTER_H
#include <string>

class Quote;
class IView;
class SalesChannel;

class Presenter
{
private:
	IView* mView = nullptr;
	SalesChannel* salesChannel = nullptr;
	std::string lastSelectedSleeve = "";
	std::string lastSelectedNeck = "";
	std::string lastSelectedPantsType = "";
	std::string lastSelectedQuality = "";
public:
	explicit Presenter(IView* view);
	~Presenter();
	void getSalesChannelName();
	void getSalesChannelAddress();
	void getSalesChannelSellerName();
	void getSalesChannelSellerId();
	void getSalesChannelQuoteHistory();
	void createQuoteShirt();
	void createQuotePant();
	void setPriceToQuote(float price);
	void setStockToQuote(int stock);
	int getCurrentStock();
	void showQuoteIntormation(Quote* quote);
	void finishQuote();
	std::string getLastSelectedSleeve();
	std::string getLastSelectedNeck();
	std::string getLastSelectedPantsType();
	std::string getLastSelectedQuality();
	void setLastSelectedSleeve(std::string selectedSleeve);
	void setLastSelectedNeck(std::string selectedNeck);
	void setLastSelectedPantsType(std::string selectedPantsType);
	void setLastSelectedQuality(std::string selectedQuality);
	void clearQuoteCreation();
};
#endif //PRESENTER_H
