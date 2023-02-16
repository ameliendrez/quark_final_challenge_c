#include "ShirtFactory.h"
#include "Shirt.h"
#include "CommonShirt.h"
#include "ChupinShirt.h"

ShirtFactory::ShirtFactory() = default;

Shirt* ShirtFactory::GetShirt(ShirtType ShirtSelected)
{
	auto Shirts = getShirtList();
	if (Shirts.count(ShirtSelected) == 0) {
		return nullptr;
	}
	auto item = Shirts[ShirtSelected];
	return item;
}

std::map<ShirtType, Shirt*> ShirtFactory::getShirtList()
{
	auto commonShirt = new CommonShirt();
	auto chupinShirt = new ChupinShirt();

	return std::map<ShirtType, Shirt*> {
		{ ShirtType::Common, commonShirt },
		{ ShirtType::Chupin, chupinShirt },
	};
}
