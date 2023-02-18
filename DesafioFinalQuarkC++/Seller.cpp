#include "Seller.h"

Seller::Seller(std::string name, std::string lastName, int id)
{
	this->name = name;
	this->lastName = lastName;
	this->id = id;
}

std::string Seller::getName()
{
	return this->name;
}

std::string Seller::getLastName()
{
	return this->lastName;
}

int Seller::getId()
{
	return this->id;
}

void Seller::setName(std::string name)
{
	this->name = name;
}

void Seller::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Seller::setId(int id)
{
	this->id = id;
}