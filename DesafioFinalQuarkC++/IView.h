#ifndef IVIEW_H
#define IVIEW_H
#include <map>
#include <string>

class IView
{
public:
	virtual ~IView() = default;
	virtual void showText(const char* text) = 0;
	virtual void showText(const std::string& text) = 0;
	virtual void showText(float text) = 0;
	virtual void showText(int text) = 0;
	virtual void showTextInLine(const char* text) = 0;
	virtual void showTextInLine(const std::string& text) = 0;
	virtual void showTextInLine(int text) = 0;
	virtual void showBackToMenuMessage();
	//virtual void setWeaponMenuItems(const std::map<WeaponType, Weapon*>& items) = 0;
};
#endif // IVIEW_H