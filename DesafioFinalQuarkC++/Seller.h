#pragma once
#include <string>

class Seller
{
public:
	std::string getName();
	std::string getLastName();
	int getId();
	void setName(std::string name);
	void setLastName(std::string lastName);
	void setId(int id);
private:
	std::string name;
	std::string lastName;
	int id;
};

