#pragma once
#include "config.h"
#include <stdint.h>

enum
{
    VALUE_BOOL,
    VALUE_TOKEN,
};

typedef struct
{
    uint16_t ven_id;
    uint16_t dev_id;
    uint32_t type;
    const char *desc;
} device_entry_t;

typedef struct // option value
{
    uint32_t reg_address;
    uint32_t reg_size;
    uint32_t reg_mask;
    uint32_t reg_data;
    const char *desc_s;
    const char *desc_l;
} option_value_t;

typedef struct // option with its values
{
    const char *desc_s;
    const char *desc_l;
    int value_type;
    option_value_t *values;
} option_entry_t;

typedef struct // options for a specific device type (type is index)
{
    uint32_t bar0;
    uint32_t bar1;
    const option_entry_t *options;
} option_set_t;

extern device_entry_t device_db[];
extern option_set_t option_db[];
