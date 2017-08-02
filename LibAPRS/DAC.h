#include "device.h"

#if DAC_MODE == SPI_DAC
  #include <SPI.h>
#endif

void DAC_init();
void DAC_analogWrite(uint16_t value);