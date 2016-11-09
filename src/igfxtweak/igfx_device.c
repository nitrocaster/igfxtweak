#include "igfx_device.h"
#include "WinRing0.h"
#include "InpOut.h"

static HANDLE mapped_mem_handle = NULL;
static uint8_t *mapped_phys_addr = NULL;
static uint8_t *mapped_lin_addr = NULL;
static uint32_t mapped_size = 0;

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

static uint8_t *reg_memmap(uint8_t *address, uint32_t size)
{
    uint8_t *lin_addr;
    if (address==mapped_phys_addr && size==mapped_size)
        lin_addr = mapped_lin_addr;
    else
    {
        if (mapped_mem_handle)
            UnmapPhysicalMemory(mapped_mem_handle, mapped_lin_addr);
        mapped_phys_addr = address;
        mapped_size = size;
        mapped_mem_handle = NULL;
        mapped_lin_addr = NULL;
        if (!size)
            return NULL;
        lin_addr = MapPhysToLin(address, size, &mapped_mem_handle);
        mapped_lin_addr = lin_addr;
    }
    return lin_addr;
}

int igfx_device_read(uint8_t *address, uint32_t size, uint8_t *data)
{
    uint8_t *lin_addr = reg_memmap(address, size);
    if (lin_addr)
    {
        memcpy(data, lin_addr, size);
        return 0;
    }
    return 1;
}

int igfx_device_write(uint8_t *address, uint32_t size, uint8_t *data)
{
    uint8_t *lin_addr = reg_memmap(address, size);
    if (lin_addr)
    {
        memcpy(lin_addr, data, size);
        return 0;
    }
    return 1;
}

void igfx_device_unmap(void) { reg_memmap(NULL, 0); }
