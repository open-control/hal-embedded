/**
 * @file main.cpp
 * @brief Compilation test for driver-common
 */
#include <Arduino.h>

#include <oc/hal/common/Types.hpp>
#include <oc/hal/common/ButtonDef.hpp>
#include <oc/hal/common/EncoderDef.hpp>

static_assert(sizeof(oc::hal::common::ButtonDef) > 0, "ButtonDef");
static_assert(sizeof(oc::hal::common::EncoderDef) > 0, "EncoderDef");

void setup() {}
void loop() {}
