#pragma once

#include <oc/hal/Types.hpp>

namespace oc::common {

/**
 * @brief Common button definition for GPIO-based buttons
 *
 * Shared by drivers that use GPIO pins (Arduino, Teensy, etc.).
 */
struct ButtonDef {
    hal::ButtonID id;
    hal::GpioPin pin;
    bool activeLow = true;
};

}  // namespace oc::common
