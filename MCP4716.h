#ifndef MCP4716_H
#define MCP4716_H

/**
 * @brief Module for handling the MCP4716 I²C communication
 */
class MCP4716 {
public:

	enum VRefBits {
		VREF_VDD, VREF_PIN_UNBUFFERED = 2, VREF_PIN_BUFFERED = 3
	};

	enum PowerDownBits {
		PD_AWAKE, PD_SLEEP_1K, PD_SLEEP_100K, PD_SLEEP_500K
	};

	/**
	 * @brief Sets the DAC value. Lost on reset.
	 *
	 * @param value The value to write to the DAC
	 */
	void SetValue(unsigned int value);

	void SetNonVolatile(VRefBits vref, PowerDownBits pd, bool gain2x, unsigned int value);

private:
	static constexpr unsigned char i2cAddr = 0x62;  // A2 variant
};

#endif
