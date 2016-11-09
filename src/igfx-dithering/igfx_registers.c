#include "igfx_registers.h"
#include "InpOut.h"

static HANDLE mapped_mem_handle = NULL;
static uint8_t *mapped_phys_addr = NULL;
static uint8_t *mapped_lin_addr = NULL;
static uint32_t mapped_size = 0;

static uint8_t *reg_memmap(uint8_t *address, uint32_t size)
{
    uint8_t *lin_addr;
    if (address==mapped_phys_addr && size==mapped_size)
    {
        lin_addr = mapped_lin_addr;
    }
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

int igfx_register_read(uint8_t *address, uint32_t size, uint8_t *data)
{
    uint8_t *lin_addr = reg_memmap(address, size);
    if (lin_addr)
    {
        memcpy(data, lin_addr, size);
        return 0;
    }
    return 1;
}

int igfx_register_write(uint8_t *address, uint32_t size, uint8_t *data)
{
    uint8_t *lin_addr = reg_memmap(address, size);
    if (lin_addr)
    {
        memcpy(lin_addr, data, size);
        return 0;
    }
    return 1;
}

void igfx_register_unmap(void) { reg_memmap(NULL, 0); }
