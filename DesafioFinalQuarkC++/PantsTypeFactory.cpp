#include "PantsTypeFactory.h"
#include "PantsType.h"
#include "CommonPants.h"
#include "ChupinPants.h"

PantsTypeFactory::PantsTypeFactory() = default;

PantsType* PantsTypeFactory::GetPantsType(PantsTypeType PantsTypeSelected)
{
	auto PantsTypes = getPantsTypeList();
	if (PantsTypes.count(PantsTypeSelected) == 0) {
		return nullptr;
	}
	auto item = PantsTypes[PantsTypeSelected];
	return item;
}

std::map<PantsTypeType, PantsType*> PantsTypeFactory::getPantsTypeList()
{
	auto commonPants = new CommonPants();
	auto chupinPants = new ChupinPants();

	return std::map<PantsTypeType, PantsType*> {
		{ PantsTypeType::Common, commonPants },
		{ PantsTypeType::Chupin, chupinPants },
	};
}
