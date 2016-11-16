#include "igfx_db.h"

device_entry_t device_db[] =
{
    //Vendor ID, Device ID, Type, Desc
    {0x8086, 0x0126, 1, "Intel(R) HD Graphics 3000 (Sandy Bridge)"},
    {0x8086, 0x0152, 1, "Intel(R) HD Graphics (Ivy Bridge)"},
    {0x8086, 0x0156, 1, "Intel(R) HD Graphics (Ivy Bridge)"},
    {0x8086, 0x015a, 1, "Intel(R) HD Graphics (Ivy Bridge)"},
    {0x8086, 0x0162, 1, "Intel(R) HD Graphics 4000 (Ivy Bridge)"},
    {0x8086, 0x0166, 1, "Intel(R) HD Graphics (Ivy Bridge)"},
    {0x8086, 0x016a, 1, "Intel(R) HD Graphics (Ivy Bridge)"},
    {0x8086, 0x0402, 2, "Intel(R) HD Graphics (Haswell)"},
    {0x8086, 0x0406, 2, "Intel(R) HD Graphics (Haswell)"},
    {0x8086, 0x040a, 2, "Intel(R) HD Graphics (Haswell)"},
    {0x8086, 0x0412, 2, "Intel(R) HD Graphics 4600 (Haswell)"},
    {0x8086, 0x0416, 2, "Intel(R) HD Graphics 4600 (Haswell)"},
    {0x8086, 0x041a, 2, "Intel(R) HD Graphics P4600/P4700 (Haswell)"},
    {0x8086, 0x041e, 2, "Intel(R) HD Graphics 4400 (Haswell)"},
    {0x8086, 0x0a06, 2, "Intel(R) HD Graphics (Haswell)"},
    {0x8086, 0x0a0e, 2, "Intel(R) HD Graphics (Haswell)"},
    {0x8086, 0x0a16, 2, "Intel(R) HD Graphics Family (Haswell)"},
    {0x8086, 0x0a1e, 2, "Intel(R) HD Graphics Family (Haswell)"},
    {0x8086, 0x0a26, 2, "Intel(R) HD Graphics 5000 (Haswell)"},
    {0x8086, 0x0a2e, 2, "Intel(R) Iris(TM) Graphics 5100 (Haswell)"},
    {0x8086, 0x0d22, 2, "Intel(R) Iris(TM) Pro Graphics 5200 (Haswell)"},
    {0x8086, 0x0d26, 2, "Intel(R) Iris(TM) Pro Graphics 5200 (Haswell)"},
    {0x8086, 0x0f31, 1, "Intel(R) HD Graphics (Silvermont)"},
    {0x8086, 0x1606, 2, "Intel(R) HD Graphics (Broadwell)"},
    {0x8086, 0x160e, 2, "Intel(R) HD Graphics (Broadwell)"},
    {0x8086, 0x1612, 2, "Intel(R) HD Graphics 5600 (Broadwell)"},
    {0x8086, 0x1616, 2, "Intel(R) HD Graphics 5500 (Broadwell)"},
    {0x8086, 0x161a, 2, "Intel(R) HD Graphics P5700 (Broadwell)"},
    {0x8086, 0x161e, 2, "Intel(R) HD Graphics 5300 (Broadwell)"},
    {0x8086, 0x1622, 2, "Intel(R) Iris(TM) Pro Graphics 6200 (Broadwell)"},
    {0x8086, 0x1626, 2, "Intel(R) HD Graphics 6000 (Broadwell)"},
    {0x8086, 0x162a, 2, "Intel(R) Iris(TM) Pro Graphics P6300 (Broadwell)"},
    {0x8086, 0x162b, 2, "Intel(R) Iris(TM) Graphics 6100 (Broadwell)"},
    {0x8086, 0x1902, 2, "Intel(R) HD Graphics 510 (Skylake)"},
    {0x8086, 0x1906, 2, "Intel(R) HD Graphics 510 (Skylake)"},
    {0x8086, 0x1912, 2, "Intel(R) HD Graphics 530 (Skylake)"},
    {0x8086, 0x1916, 2, "Intel(R) HD Graphics 520 (Skylake)"},
    {0x8086, 0x191b, 2, "Intel(R) HD Graphics 530 (Skylake)"},
    {0x8086, 0x191d, 2, "Intel(R) HD Graphics P530 (Skylake)"},
    {0x8086, 0x191e, 2, "Intel(R) HD Graphics 515 (Skylake)"},
    {0x8086, 0x1921, 2, "Intel(R) HD Graphics 520 (Skylake)"},
    {0x8086, 0x1923, 2, "Intel(R) HD Graphics 535 (Skylake)"},
    {0x8086, 0x1926, 2, "Intel(R) Iris(TM) Graphics 540 (Skylake)"},
    {0x8086, 0x1927, 2, "Intel(R) Iris(TM) Graphics 550 (Skylake)"},
    {0x8086, 0x192b, 2, "Intel(R) Iris(TM) Graphics (Skylake)"},
    {0x8086, 0x193d, 2, "Intel(R) Iris(TM) Pro Graphics P580 (Skylake)"},
    {0, 0, 0, NULL}
};

static option_value_t opt_type1_dithering_a[] =
{
    {0x70008, 4, 0x0000001c, 0x00000000, "off", "Disable"},
    {0x70008, 4, 0x0000001c, 0x00000010, "sp", "Spatial"},
    {0x70008, 4, 0x0000001c, 0x00000014, "st1", "Spatio-Temporal 1"},
    {0x70008, 4, 0x0000001c, 0x00000018, "st2", "Spatio-Temporal 2"},
    {0x70008, 4, 0x0000001c, 0x0000001c, "tm", "Temporal"},
    {0, 0, 0, 0, NULL, NULL}
};

static option_value_t opt_type1_dithering_b[] =
{
    {0x71008, 4, 0x0000001c, 0x00000000, "off", "Disable"},
    {0x71008, 4, 0x0000001c, 0x00000010, "sp", "Spatial"},
    {0x71008, 4, 0x0000001c, 0x00000014, "st1", "Spatio-Temporal 1"},
    {0x71008, 4, 0x0000001c, 0x00000018, "st2", "Spatio-Temporal 2"},
    {0x71008, 4, 0x0000001c, 0x0000001c, "tm", "Temporal"},
    {0, 0, 0, 0, NULL, NULL}
};

static option_value_t opt_type1_dithering_c[] =
{
    {0x72008, 4, 0x0000001c, 0x00000000, "off", "Disable"},
    {0x72008, 4, 0x0000001c, 0x00000010, "sp", "Spatial"},
    {0x72008, 4, 0x0000001c, 0x00000014, "st1", "Spatio-Temporal 1"},
    {0x72008, 4, 0x0000001c, 0x00000018, "st2", "Spatio-Temporal 2"},
    {0x72008, 4, 0x0000001c, 0x0000001c, "tm", "Temporal"},
    {0, 0, 0, 0, NULL, NULL}
};

static option_value_t opt_type2_dithering_e[] =
{
    {0x7f008, 4, 0x0000001c, 0x00000000, "off","Disable"},
    {0x7f008, 4, 0x0000001c, 0x00000010, "sp","Spatial"},
    {0x7f008, 4, 0x0000001c, 0x00000014, "st1","Spatio-Temporal 1"},
    {0x7f008, 4, 0x0000001c, 0x00000018, "st2","Spatio-Temporal 2"},
    {0x7f008, 4, 0x0000001c, 0x0000001c, "tm","Temporal"},
    {0, 0, 0, 0, NULL, NULL}
};

static option_entry_t options_type1[] =
{
    {"dithering_a", "Dithering [Pipe A]", VALUE_TOKEN, opt_type1_dithering_a},
    {"dithering_b", "Dithering [Pipe B]", VALUE_TOKEN, opt_type1_dithering_b},
    {"dithering_c", "Dithering [Pipe C]", VALUE_TOKEN, opt_type1_dithering_c},
    {NULL, NULL, 0, NULL}
};

static option_entry_t options_type2[] =
{
    {"dithering_a", "Dithering [Pipe A]", VALUE_TOKEN, opt_type1_dithering_a},
    {"dithering_b", "Dithering [Pipe B]", VALUE_TOKEN, opt_type1_dithering_b},
    {"dithering_c", "Dithering [Pipe C]", VALUE_TOKEN, opt_type1_dithering_c},
    {"dithering_e", "Dithering [eDP]", VALUE_TOKEN, opt_type2_dithering_e},
    {NULL, NULL, 0, NULL}
};

option_set_t option_db[] =
{
    // type 1
    {0x10, 0x14, options_type1},
    // type 2
    {0x10, 0x14, options_type2},
    // none
    {0, 0, NULL}
};
