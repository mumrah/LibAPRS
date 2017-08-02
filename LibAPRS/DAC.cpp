#include "Arduino.h"
#include "DAC.h"

#if DAC_MODE == PORT_DAC
void DAC_init() {
  DAC_DDR |= 0xF8;
}

void DAC_analogWrite(uint16_t value) {
  DAC_PORT = value; 
}
#endif

#if DAC_MODE == SPI_DAC
void DAC_init() {
  digitalWrite(DAC_SPI_CS, HIGH);
  SPI.begin();
}

void DAC_analogWrite(uint16_t value) {
  value = (value & 0x3ff) << 2;
  digitalWrite(DAC_SPI_CS, LOW);
  SPI.transfer16(value);
  digitalWrite(DAC_SPI_CS, HIGH);
}
#endif

#if DAC_MODE == USER_DAC
// User must supply method
#endif