#include "igfx_device.h"
#include "WinRing0.h"

int igfx_device_find(uint32_t *address, uint16_t *ven, uint16_t *dev)
{
    *address = FindPciDeviceByClass(3, 0, 0, 0); // 03h: display controller
    if (*address==(uint32_t)-1)
        return 1;
    if (!ReadPciConfigWordEx(*address, 0, ven))
        return 1;
    if (!ReadPciConfigWordEx(*address, 2, dev))
        return 1;
    return 0;
}

int igfx_device_get_iobase32(uint32_t address, uint32_t bar0, uint32_t bar1, uint32_t* iobase)
{
    uint32_t dummy;
    if (!ReadPciConfigDwordEx(address, bar0, iobase))
        return 1;
    if (!ReadPciConfigDwordEx(address, bar1, &dummy))
        return 1;
    return 0;
}

int igfx_device_get_iobase64(uint32_t address, uint32_t bar0, uint32_t bar1, uint64_t* iobase)
{
    if (!ReadPciConfigDwordEx(address, bar0, (uint32_t *)iobase+1))
        return 1;
    if (!ReadPciConfigDwordEx(address, bar1, (uint32_t *)iobase))
        return 1;
    return 0;
}
