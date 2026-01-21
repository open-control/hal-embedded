#pragma once

#include <cstdint>

namespace oc::hal::common::embedded {

/**
 * @brief GPIO pin configuration for embedded platforms
 *
 * Describes how a pin is connected - either directly to MCU
 * or via a multiplexer.
 */
struct GpioPin {
    enum class Source : uint8_t {
        MCU,  ///< Direct MCU GPIO
        MUX   ///< Via multiplexer
    };

    uint8_t pin{};
    Source source = Source::MCU;
};

}  // namespace oc::hal::common::embedded
