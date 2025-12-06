#pragma once

#include <oc/common/Types.hpp>

namespace oc::common {

struct ButtonDef {
    ButtonID id;
    GpioPin pin;
    bool activeLow = true;
};

}  // namespace oc::common
