#ifndef PRESENTER_H
#define PRESENTER_H

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
	int getShirtId(const char* optionSleeve, const char* optionNeck, const char* optionQuality);
	int getPantId(const char* optionType, const char* optionQuality);
	void createQuoteShirt(const char* optionSleeve, const char* optionNeck, const char* optionQuality);
	void createQuotePant(const char* optionType, const char* optionQuality);
	void setPriceToQuote(float price);
	void setStockToQuote(int stock);
	int getCurrentStock();
	void showQuoteIntormation(Quote* quote);
	void finishQuote();
};
#endif //PRESENTER_H
