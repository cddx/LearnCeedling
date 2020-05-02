#ifndef I2C_H
#define I2C_H
#include <stdint.h>

uint16_t i2c_readRegister(uint8_t registerAddress);

#endif // I2C_H