#pragma once
#include "config.h"
#include <windows.h>

typedef DWORD // pciAddress, 0xFFFFFFFF: failure
    (WINAPI *FindPciDeviceByClass_t)(
        BYTE baseClass, // Base Class
        BYTE subClass, // Sub Class
        BYTE programIf, // Program Interface
        BYTE index // Index
    );

typedef BOOL // TRUE: success, FALSE: failure
    (WINAPI *ReadPciConfigDwordEx_t)(
        DWORD pciAddress, // PCI Device Address
        DWORD regAddress, // Configuration Address 0-whatever
        PDWORD value // Read Value
    );

typedef BOOL // TRUE: success, FALSE: failure
        (WINAPI *ReadPciConfigWordEx_t)(
        DWORD pciAddress, // PCI Device Address
        DWORD regAddress, // Configuration Address 0-whatever
        PWORD value // Read Value
    );

extern FindPciDeviceByClass_t FindPciDeviceByClass;
extern ReadPciConfigDwordEx_t ReadPciConfigDwordEx;
extern ReadPciConfigWordEx_t ReadPciConfigWordEx;

int WinRing0Initialize(void);
int WinRing0Deinitialize(void);
