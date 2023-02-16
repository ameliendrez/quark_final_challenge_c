#ifndef QUALITY_FACTORY
#define QUALITY_FACTORY

#include <map>

class Quality;
enum class QualityType {Standard = 1, Premium = 2};
class QualityFactory
{
public:
	QualityFactory();
	~QualityFactory() = default;
	static Quality* GetQuality(QualityType qualitySelected);
	static std::map<QualityType, Quality*> getQualityList();
};

#endif //QUALITY_FACTORY