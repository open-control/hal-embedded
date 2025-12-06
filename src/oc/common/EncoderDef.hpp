#pragma once

#include <cstdint>

#include <oc/common/Types.hpp>

namespace oc::common {

struct EncoderDef {
    EncoderID id;
    uint8_t pinA;
    uint8_t pinB;
    uint16_t ppr = 24;
    uint16_t rangeAngle = 270;
    uint8_t ticksPerEvent = 4;
    bool invertDirection = false;
};

}  // namespace oc::common
