#pragma once

#include <cstdint>

#include <oc/hal/Types.hpp>

namespace oc::common {

/**
 * @brief Common encoder definition for GPIO-based encoders
 *
 * Shared by drivers that use simple GPIO pin pairs (Arduino, Teensy, etc.).
 * Platforms with different GPIO models (e.g., port-based) may define their own.
 */
struct EncoderDef {
    hal::EncoderID id;
    uint8_t pinA;
    uint8_t pinB;
    uint16_t ppr = 24;
    uint16_t rangeAngle = 270;
    uint8_t ticksPerEvent = 4;
    bool invertDirection = false;
};

}  // namespace oc::common
