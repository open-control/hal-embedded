/**
 * @file main.cpp
 * @brief Compilation test for hal-embedded
 */
#include <Arduino.h>

#include <oc/hal/embedded/Types.hpp>
#include <oc/hal/embedded/GpioPin.hpp>
#include <oc/hal/embedded/ButtonDef.hpp>
#include <oc/hal/embedded/EncoderDef.hpp>

static_assert(sizeof(oc::hal::embedded::GpioPin) > 0, "GpioPin");
static_assert(sizeof(oc::hal::embedded::ButtonDef) > 0, "ButtonDef");
static_assert(sizeof(oc::hal::embedded::EncoderDef) > 0, "EncoderDef");

void setup() {}
void loop() {}
