#include "NeckFactory.h"
#include "Neck.h"
#include "CommonNeck.h"
#include "MaoNeck.h"

NeckFactory::NeckFactory() = default;

Neck* NeckFactory::GetNeck(NeckType neckSelected)
{
	auto Necks = getNeckList();
	if (Necks.count(neckSelected) == 0) {
		return nullptr;
	}
	auto item = Necks[neckSelected];
	return item;
}

std::map<NeckType, Neck*> NeckFactory::getNeckList()
{
	auto commonNeck = new CommonNeck();
	auto maoNeck = new MaoNeck();

	return std::map<NeckType, Neck*> {
		{ NeckType::Common, commonNeck },
		{ NeckType::Mao, maoNeck }
	};
}
