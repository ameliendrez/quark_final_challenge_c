#ifndef VIEW_H
#define VIEW_H

#include "IView.h"
#include <string>

class Quote;
class Presenter;

class View : public IView
{
private:
	Presenter* presenter;
	void showMainMenu();
	void runOption(const char* option, bool& exitCondition);
	bool checkValidOption(std::string option);
	void backToMenu(std::string option, bool& isValidOption);
	void showTitleQuote();
	void showTextSeparator();
	void showBackToMenuMessage();
	void showQuotesHistory();
	void showMenuInitQuote();
	void showMenuTakeSleeve();
	void showMenuTakeNeck();
	void showMenuTakeTypePants();
	void showMenuTakeQuality();
	float showMenuPrice();
	int showMenuStock(int currentStock);
	void showMenuOutOfStock(int currentStock, int quantitySelected);
	void showMenuCreateQuoteShirt();
	void showMenuCreateQuotePant();
	void showMenuPriceAndStock();
	void finishQuote();
public:
	View();
	~View() override;
	void showText(const char* text) override;
	void showText(const std::string& text) override;
	void showText(float text) override;
	void showText(int text) override;
	void showTextInLine(const char* text) override;
	void showTextInLine(const std::string& text) override;
	void showTextInLine(int text) override;
	void showQuoteInformation(Quote* quote) override;
};
#endif //VIEW_H
