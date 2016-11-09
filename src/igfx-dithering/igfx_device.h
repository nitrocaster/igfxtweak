#pragma once
#include "config.h"
#include <stdint.h>

int igfx_device_find(uint32_t *address, uint16_t *ven, uint16_t *dev);
int igfx_device_get_iobase32(uint32_t address, uint32_t bar0, uint32_t bar1, uint32_t *iobase);
int igfx_device_get_iobase64(uint32_t address, uint32_t bar0, uint32_t bar1, uint64_t *iobase);
