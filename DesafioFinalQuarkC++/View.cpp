#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "View.h"
#include "Presenter.h"
#include <algorithm>
#include <vector>

class Clothes;
const std::string ANY_KEY_MESSAGE = "Escribe cualquier tecla para continuar.";
const std::string INVALID_OPTION_MESSAGE = "La opcion ingresada es invalida, por favor reintente.";

View::View()
{
	SetConsoleTitleW(L"Clothes Sales Channel");
	setlocale(LC_ALL, "es_Es");
	presenter = new Presenter(this);
	showMainMenu();
}

View::~View()
{
	delete presenter;
}

void View::showText(const char* text)
{
	std::cout << text << std::endl;
}

// Polymorphism Rules, BUT DRY? 
void View::showText(const std::string& text)
{
	std::cout << text << std::endl;
}

void View::showText(float text)
{
	std::cout << text << std::endl;
}

void View::showText(int text)
{
	std::cout << text << std::endl;
}


void View::showTextInLine(const char* text)
{
	std::cout << text;
}

// Polymorphism Rules, BUT DRY? 
void View::showTextInLine(const std::string& text)
{
	std::cout << text;
}

void View::showTextInLine(int text)
{
	std::cout << text;
}

void View::showTitleQuote()
{
	std::system("cls");
	showText("-== Cotizador Express - Cotizar ==-");
}

void View::showBackToMenuMessage()
{
	showTextSeparator();
	showText("Presiona 3 para volver al menu principal");
	showTextSeparator();
}

void View::showTextSeparator()
{
	showText("--------------------------------------------------");
}

std::istream operator>>(const std::istream& cin, float* const& rhs);

int View::showMenuStock(int currentStock)
{
	int stock;
	do
	{
		showTitleQuote();
		showTextSeparator();
		//showBackToMenuMessage();
		showText("");
		showText("INFORMACION:");
		showTextInLine("EXISTE ");
		
		showTextInLine(currentStock);
		showText(" CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA");
		showText("");
		showText("Paso 5: ingrese la cantidad de unidades a cotizar");

		std::cin >> stock;
		std::cin.get();
	} while (!std::cin || std::cin.fail());

	return stock;
}

float View::showMenuPrice()
{
	float price;
	do
	{
		showTitleQuote();
		showTextSeparator();
		//showBackToMenuMessage();
		showText("PASO 4: ingrese precio unitario de la prenda a cotizar");

		showTextSeparator();

		std::cin >> price;
		std::cin.get();
	} while (!std::cin || std::cin.fail());

	return price;
}

void View::showMenuCreateQuoteShirt(std::string optionSleeve, const char* optionNeck, std::string optionQuality)
{
	this->presenter->createQuoteShirt(optionSleeve, optionNeck, optionQuality);

	float price = showMenuPrice();
	this->presenter->setPriceToQuote(price);

	int currentStock = this->presenter->getCurrentStock();
	int stock = showMenuStock(currentStock);

	if (stock < currentStock)
	{
		this->presenter->setStockToQuote(stock);
	}

	finishQuote();
}

void View::showMenuCreateQuotePant(const char* optionType, const char* optionQuality)
{
	this->presenter->createQuotePant(optionType, optionQuality);

	float price = showMenuPrice();
	this->presenter->setPriceToQuote(price);

	int currentStock = this->presenter->getCurrentStock();
	int stock = showMenuStock(currentStock);

	if (stock < currentStock)
	{
		this->presenter->setStockToQuote(stock);
	}

	finishQuote();
}

void View::finishQuote()
{
	showTitleQuote();
	showBackToMenuMessage();
	this->presenter->finishQuote();
	showBackToMenuMessage();
	
	std::string optionString = "";
	bool isValidOption = true;
	
	do
	{
		std::cin >> optionString;
		backToMenu(optionString.c_str(), isValidOption);
		std::cin.get();
	} while (!isValidOption);

	showMainMenu();
}

void View::showMenuTakeQuality(std::string optionQuality)
{
	std::string optionString = "";
	bool isValidOption = true;
	do
	{
		showTitleQuote();
		showBackToMenuMessage();
		showText("PASO 3: Seleccione la calidad de la prenda");

		showText("1) Standard");
		showText("2) Premium");

		showTextSeparator();

		std::cin >> optionString;
		selectTypeOfQuality(optionString, isValidOption);
		std::cin.get();
	} while (!isValidOption);

	if (optionString.c_str() == "3")
	{
		showMainMenu();
	}
}

void View::selectTypeOfQuality(std::string option, bool& isValidOption)
{
	if (option == "1" || option == "2")
	{
		this->presenter->setCurrentQuality(option);
		isValidOption = true;
		std::cin.get();
	}
	else if (option == "3")
	{
		isValidOption = true;
		std::cin.get();
	}
	else
	{
		isValidOption = false;
	}

	if (!isValidOption)
	{
		std::system("cls");
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
	}
}

void View::showMenuTakeNeck(std::string optionSleeve)
{
	std::string optionString = "";
	std::string optionQuality = "";
	bool isValidOption = true;
	do
	{
		showTitleQuote();
		showBackToMenuMessage();
		showText("PASO 2.b: La camisa a cotizar, ¿Es Cuello Mao?");

		showText("1) Si");
		showText("2) No");

		showTextSeparator();

		std::cin >> optionString;
		selectTypeOfNeck(optionString.c_str(), isValidOption, optionQuality);
		std::cin.get();
	} while (!isValidOption);

	std::string oq = this->presenter->getCurrentCuality();
	
	//(oq == "1" || oq == "2")
	//
		showMenuCreateQuoteShirt("1", "1", "1");
	//

	if (optionString.c_str() == "3")
	{
		showMainMenu();
	}
}

void View::selectTypeOfNeck(std::string option, bool& isValidOption, std::string &optionQuality)
{
	if (option == "1" || option == "2")
	{
		showMenuTakeQuality(optionQuality);
		isValidOption = true;
		std::cin.get();
	}
	else if (option == "3")
	{
		isValidOption = true;
		std::cin.get();
	}
	else
	{
		isValidOption = false;
	}

	if (!isValidOption)
	{
		std::system("cls");
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
	}
}

void View::showMenuTakeSleeve()
{
	std::string optionString = "";
	bool isValidOption = true;
	do
	{
		showTitleQuote();
		showBackToMenuMessage();
		showText("PASO 2.a: La camisa a cotizar, ¿Es Manga Corta?");

		showText("1) Si");
		showText("2) No");

		showTextSeparator();

		std::cin >> optionString;
		selectTypeOfSleeve(optionString.c_str(), isValidOption);
		std::cin.get();
	} while (!isValidOption);

	if (optionString.c_str() == "3")
	{
		showMainMenu();
	}
}

void View::selectTypeOfSleeve(std::string option, bool& isValidOption)
{
	if (option == "1" || option == "2")
	{
		showMenuTakeNeck(option);
		isValidOption = true;
		std::cin.get();
	}
	else if (option == "3")
	{
		isValidOption = true;
		std::cin.get();
	}
	else
	{
		isValidOption = false;
	}

	if (!isValidOption)
	{
		std::system("cls");
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
	}
}

void View::showMenuTakeTypePants()
{
	std::string optionString = "";
	bool isValidOption = true;
	const char* optionQuality = "";
	do
	{
		showTitleQuote();
		showBackToMenuMessage();
		showText("PASO 2: El pantalon a cotizar a cotizar, ¿Es chupin?");

		showText("1) Si");
		showText("2) No");

		showTextSeparator();

		std::cin >> optionString;
		selectTypeOfPants(optionString.c_str(), isValidOption, optionQuality);
		std::cin.get();
	} while (!isValidOption);

	if (optionQuality == "1" || optionQuality == "2")
	{
		showMenuCreateQuotePant( optionString.c_str(), optionQuality);
	}

	if (optionString.c_str() == "3")
	{
		showMainMenu();
	}
}

void View::selectTypeOfPants(std::string option, bool& isValidOption, std::string optionQuality)
{
	if (option == "1" || option == "2")
	{
		showMenuTakeQuality(optionQuality);
		isValidOption = true;
		std::cin.get();
	}
	else if (option == "3")
	{
		isValidOption = true;
		std::cin.get();
	}
	else
	{
		isValidOption = false;
	}

	if (!isValidOption)
	{
		std::system("cls");
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
	}
}

void View::showMenuCreateQuote()
{
	std::string optionString = "";
	bool isValidOption = true;
	do
	{
		std::system("cls");
		showText("-== Cotizador Express - Cotizar ==-");
		showBackToMenuMessage();
		showText("PASO 1: Selecciona la prenda a cotizar");

		showText("1) Camisa");
		showText("2) Pantalon");

		showTextSeparator();

		std::cin >> optionString;
		selectTypeOfClothes(optionString, isValidOption);
		std::cin.get();
	} while (!isValidOption);

	if (optionString.c_str() == "3")
	{
		showMainMenu();
	}
}

void View::selectTypeOfClothes(std::string option, bool& isValidOption)
{
	if (option == "1")
	{
		showMenuTakeSleeve();
		isValidOption = true;
		std::cin.get();
	}
	else if (option == "2")
	{
		showMenuTakeTypePants();
		isValidOption = true;
		std::cin.get();
	}
	else if (option == "3")
	{
		isValidOption = true;
		std::cin.get();
	}
	else
	{
		isValidOption = false;
	}

	if (!isValidOption)
	{
		std::system("cls");
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
	}
}


void View::showQuotesHistory()
{
	std::string optionString = "";
	bool isValidOption = true;
	do
	{
		std::system("cls");
		showText("-== Cotizador Express - Historial de cotizaciones ==-");
		showBackToMenuMessage();

		// mostramos el historial de cotizaciones
		presenter->getSalesChannelQuoteHistory();

		showBackToMenuMessage();
		
		std::cin >> optionString;

		backToMenu(optionString.c_str(), isValidOption);
		
		if (optionString == "3")
		{
			isValidOption = true;
		}
		//backToMenu(optionString.c_str(), isValidOption);
		std::cin.get();
	} while (!isValidOption);

	if (optionString.c_str() == "3")
	{
		showMainMenu();
	}
	
}

void View::backToMenu(std::string option, bool& isValidOption)
{
	if (option == "3")
	{
		isValidOption = true;
		std::cin.get();
	}
	else
	{
		isValidOption = false;
	}
	
	if (!isValidOption)
	{
		std::system("cls");
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
	}
}

void View::showMainMenu()
{
	std::string option;
	bool exitCondition = false;

	do
	{
		std::system("cls");

		showText("-== Cotizador Express - Menu Principal ==-");
		showTextSeparator();
		this->presenter->getSalesChannelName();
		showTextInLine(" | ");
		this->presenter->getSalesChannelAddress();
		showTextSeparator();

		this->presenter->getSalesChannelSellerName();
		showTextInLine(" | ");
		this->presenter->getSalesChannelSellerId();
		showTextSeparator();
		
		showText("");
		showText("SELECCIONE UNA OPCION DEL MENU");
		showText("");
		
		showText("1) Historial de cotizaciones");
		showText("2) Realizar cotizacion");
		showText("3) Salir");
		std::cin >> option;
		std::system("cls");
		runOption(option.c_str(), exitCondition);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();
	} while (!exitCondition);
}

void View::runOption(const char* option, bool& exitCondition)
{
	auto str_option = std::string(option);

	if (str_option == "1")
	{
		showQuotesHistory();
		exitCondition = false;
	}
	else if (str_option == "2")
	{
		showMenuCreateQuote();
		exitCondition = false;
	}
	else if (str_option == "3")
	{
		std::cout.flush();
		exit(EXIT_SUCCESS);
	}
	else
	{
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
		exitCondition = false;
	}
}
