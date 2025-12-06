#pragma once

#include <cstdint>

namespace oc::common {

using ButtonID = uint16_t;
using EncoderID = uint16_t;

struct GpioPin {
    enum class Source : uint8_t {
        MCU,
        MUX
    };
    uint8_t pin;
    Source source = Source::MCU;
};

}  // namespace oc::common
