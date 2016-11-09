#pragma once
#include "config.h"
#include <stdint.h>

int igfx_register_read(uint8_t *address, uint32_t size, uint8_t *data);
int igfx_register_write(uint8_t *address, uint32_t size, uint8_t *data);
void igfx_register_unmap(void);
