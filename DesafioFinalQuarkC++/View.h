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
	void selectTypeOfClothes(std::string option, bool& isValidOption);
	void selectTypeOfSleeve(std::string option, bool& isValidOption);
	void selectTypeOfNeck(std::string option, bool& isValidOption, std::string &optionQuality);
	void selectTypeOfPants(std::string option, bool& isValidOption, std::string optionQuality);
	void selectTypeOfQuality(std::string option, bool& isValidOption);
	void backToMenu(std::string option, bool& isValidOption);
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
	void showMenuTakeNeck(std::string optionSleeve);
	void showMenuTakeTypePants();
	void showMenuTakeQuality(std::string optionQuality);
	float showMenuPrice();
	int showMenuStock(int currentStock);
	void showMenuCreateQuoteShirt(std::string optionSleeve, const char* optionNeck, std::string optionQuality);
	void showMenuCreateQuotePant(const char* optionType, const char* optionQuality);
	void finishQuote();
};
#endif //VIEW_H
