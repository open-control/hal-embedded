#pragma once

#include <cstdint>
#include <type_traits>

#include <oc/hal/common/embedded/Types.hpp>

namespace oc::hal::common::embedded {

/**
 * @brief Hardware definition for a rotary encoder
 *
 * Describes the mapping between a logical encoder ID and its physical
 * configuration. Used during hardware initialization to configure
 * the encoder subsystem.
 *
 * ## ID Types
 *
 * Supports both raw uint16_t IDs and enum class types. Using enum class
 * is recommended for IDE autocompletion and type safety:
 *
 * @code
 * // Define your encoder IDs
 * enum class EncoderID : uint16_t {
 *     VOLUME = 100,
 *     PAN = 101,
 *     NAV = 200
 * };
 *
 * // Use enum class (recommended)
 * constexpr EncoderDef encoders[] = {
 *     {EncoderID::VOLUME, 22, 23, 24, 270, 4, false},
 *     {EncoderID::PAN, 24, 25, 24, 270, 4, false},
 *     {EncoderID::NAV, 26, 27, 20, 360, 1, true}
 * };
 *
 * // Or use raw uint16_t
 * constexpr EncoderDef enc{100, 22, 23, 24, 270, 4, false};
 * @endcode
 *
 * ## Configuration Parameters
 *
 * - **ppr**: Pulses per revolution - physical encoder resolution
 * - **rangeAngle**: Total rotation angle in degrees (270 for most pots)
 * - **ticksPerEvent**: Number of ticks before emitting an event (detent count)
 * - **invertDirection**: Swap clockwise/counter-clockwise direction
 *
 * @see EncoderAPI
 * @see EncoderLogic
 */
struct EncoderDef {
    EncoderID id{};                 ///< Logical encoder identifier
    uint8_t pinA{};                 ///< GPIO pin for encoder channel A
    uint8_t pinB{};                 ///< GPIO pin for encoder channel B
    uint16_t ppr = 24;              ///< Pulses per revolution
    uint16_t rangeAngle = 270;      ///< Total rotation angle in degrees
    uint8_t ticksPerEvent = 4;      ///< Ticks per emitted event (detent)
    bool invertDirection = false;   ///< Invert rotation direction

    /// Default constructor
    constexpr EncoderDef() = default;

    /// Constructor with raw uint16_t ID
    constexpr EncoderDef(EncoderID id_, uint8_t pinA_, uint8_t pinB_,
                         uint16_t ppr_ = 24, uint16_t rangeAngle_ = 270,
                         uint8_t ticksPerEvent_ = 4, bool invertDirection_ = false)
        : id(id_), pinA(pinA_), pinB(pinB_), ppr(ppr_),
          rangeAngle(rangeAngle_), ticksPerEvent(ticksPerEvent_),
          invertDirection(invertDirection_) {}

    /// Constructor with enum class ID (enables IDE autocompletion)
    template <typename EnumT,
              typename = std::enable_if_t<std::is_enum_v<EnumT> &&
                                          std::is_same_v<std::underlying_type_t<EnumT>, uint16_t>>>
    constexpr EncoderDef(EnumT id_, uint8_t pinA_, uint8_t pinB_,
                         uint16_t ppr_ = 24, uint16_t rangeAngle_ = 270,
                         uint8_t ticksPerEvent_ = 4, bool invertDirection_ = false)
        : id(static_cast<EncoderID>(id_)), pinA(pinA_), pinB(pinB_), ppr(ppr_),
          rangeAngle(rangeAngle_), ticksPerEvent(ticksPerEvent_),
          invertDirection(invertDirection_) {}
};

}  // namespace oc::hal::common::embedded
