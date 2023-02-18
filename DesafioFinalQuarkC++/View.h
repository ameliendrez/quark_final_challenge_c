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
public:
	View();
	~View() override;
	void selectTypeOfClothes(const char* option, bool& isValidOption);
	void selectTypeOfSleeve(const char* option, bool& isValidOption);
	void selectTypeOfNeck(const char* option, bool& isValidOption, const char* &optionQuality);
	void selectTypeOfPants(const char* option, bool& isValidOption, const char* optionQuality);
	void selectTypeOfQuality(const char* option, bool& isValidOption, const char*& optionQuality);
	void backToMenu(const char* option, bool& isValidOption);
	void showTitleQuote();
	void showTextSeparator();
	void showText(const char* text) override;
	void showText(const std::string& text) override;
	void showText(float text) override;
	void showText(int text) override;
	void showTextInLine(const char* text) override;
	void showTextInLine(const std::string& text) override;
	void showTextInLine(int text) override;
	void showBackToMenuMessage() override;
	void showQuotesHistory();
	void showMenuCreateQuote();
	void showMenuTakeSleeve();
	void showMenuTakeNeck(const char* optionSleeve);
	void showMenuTakeTypePants();
	void showMenuTakeQuality(const char* optionQuality);
	float showMenuPrice();
	int showMenuStock(int currentStock);
	void showMenuCreateQuoteShirt(const char* optionSleeve, const char* optionNeck, const char* optionQuality);
	void showMenuCreateQuotePant(const char* optionType, const char* optionQuality);
	void finishQuote();
};
#endif //VIEW_H
