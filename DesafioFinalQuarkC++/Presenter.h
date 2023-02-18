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
public:
	explicit Presenter(IView* view);
	~Presenter();
	void getSalesChannelName();
	void getSalesChannelAddress();
	void getSalesChannelSellerName();
	void getSalesChannelSellerId();
	void getSalesChannelQuoteHistory();
	int getShirtId(std::string optionSleeve, const char* optionNeck, std::string optionQuality);
	int getPantId(const char* optionType, const char* optionQuality);
	void createQuoteShirt(std::string optionSleeve, const char* optionNeck, std::string optionQuality);
	void createQuotePant(const char* optionType, const char* optionQuality);
	void setPriceToQuote(float price);
	void setStockToQuote(int stock);
	int getCurrentStock();
	void showQuoteIntormation(Quote* quote);
	void finishQuote();
	void setCurrentQuality(std::string currentQualityId);
	std::string getCurrentCuality();
};
#endif //PRESENTER_H
