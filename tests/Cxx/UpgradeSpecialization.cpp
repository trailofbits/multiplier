#include "UpgradeSpecialization.h"

namespace UpgradeSpecialization {

#ifdef UPGRADE_SPEC
auto x_val = TemplateClass<int>().Method();
#else
TemplateClass<int> *x_ptr;
#endif

}  // namespace UpgradeSpecialization
