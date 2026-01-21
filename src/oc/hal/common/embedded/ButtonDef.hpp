#pragma once

#include <type_traits>

#include <oc/hal/common/embedded/Types.hpp>
#include <oc/hal/common/embedded/GpioPin.hpp>

namespace oc::hal::common::embedded {

/**
 * @brief Hardware definition for a physical button
 *
 * Describes the mapping between a logical button ID and its physical
 * GPIO connection. Used during hardware initialization to configure
 * the button subsystem.
 *
 * ## ID Types
 *
 * Supports both raw uint16_t IDs and enum class types. Using enum class
 * is recommended for IDE autocompletion and type safety:
 *
 * @code
 * // Define your button IDs
 * enum class ButtonID : uint16_t {
 *     PLAY = 10,
 *     STOP = 11,
 *     REC = 12
 * };
 *
 * // Use enum class (recommended)
 * constexpr ButtonDef buttons[] = {
 *     {ButtonID::PLAY, {9, Source::MUX}, true},
 *     {ButtonID::STOP, {10, Source::MUX}, true},
 *     {ButtonID::REC, {11, Source::MUX}, true}
 * };
 *
 * // Or use raw uint16_t
 * constexpr ButtonDef button{10, {9, Source::MUX}, true};
 * @endcode
 *
 * ## Active Low vs Active High
 *
 * Most buttons are active-low (pressed = LOW, released = HIGH) because
 * they connect to ground when pressed with an internal pull-up resistor.
 * Set activeLow=false for active-high buttons.
 *
 * @see GpioPin
 * @see ButtonAPI
 */
struct ButtonDef {
    ButtonID id{};          ///< Logical button identifier
    GpioPin pin{};          ///< Physical GPIO pin configuration
    bool activeLow = true;  ///< true: pressed=LOW, false: pressed=HIGH

    /// Default constructor
    constexpr ButtonDef() = default;

    /// Constructor with raw uint16_t ID
    constexpr ButtonDef(ButtonID id_, GpioPin pin_, bool activeLow_ = true)
        : id(id_), pin(pin_), activeLow(activeLow_) {}

    /// Constructor with enum class ID (enables IDE autocompletion)
    template <typename EnumT,
              typename = std::enable_if_t<std::is_enum_v<EnumT> &&
                                          std::is_same_v<std::underlying_type_t<EnumT>, uint16_t>>>
    constexpr ButtonDef(EnumT id_, GpioPin pin_, bool activeLow_ = true)
        : id(static_cast<ButtonID>(id_)), pin(pin_), activeLow(activeLow_) {}
};

}  // namespace oc::hal::common::embedded
