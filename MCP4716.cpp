#include "MCP4716.h"
#include <Wire.h>

void MCP4716::SetValue(unsigned int value) {
	Wire.beginTransmission(i2cAddr);
	Wire.write(value >> 6);
	Wire.write((uint8_t)value << 2);
	Wire.endTransmission();
}

void MCP4716::SetNonVolatile(VRefBits vref, PowerDownBits pd, bool gain2x, unsigned int value) {
	Wire.beginTransmission(i2cAddr);
	Wire.write(0x60 | (uint8_t)vref << 3 | (uint8_t)pd << 1 | gain2x);
	Wire.write(value >> 2);
	Wire.write((uint8_t)value << 6);
	Wire.endTransmission();
}
