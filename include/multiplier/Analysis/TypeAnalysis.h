#include <gap/core/generator.hpp>
#include <multiplier/Index.h>


enum class CastingBehaviorTags {
  SIGN_CHANGE,
  TYPE_DOWNCAST,
  TYPE_UPCAST,
};

class TypecastAnalysisImpl final {
public:
    Index index;

    inline TypecastAnalysisImpl(const Index &index_)
    : index(index_) {}

}
