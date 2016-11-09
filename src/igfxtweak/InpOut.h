#pragma once
#include "config.h"
#include <windows.h>

typedef BOOL
    (WINAPI *IsInpOutDriverOpen_t)(void);

typedef PBYTE
    (WINAPI *MapPhysToLin_t)(
        PBYTE pbPhysAddr,
        DWORD dwPhysSize,
        HANDLE *pPhysicalMemoryHandle
    );

typedef BOOL
    (WINAPI *UnmapPhysicalMemory_t)(
        HANDLE PhysicalMemoryHandle,
        PBYTE pbLinAddr
    );

extern IsInpOutDriverOpen_t IsInpOutDriverOpen;
extern MapPhysToLin_t MapPhysToLin;
extern UnmapPhysicalMemory_t UnmapPhysicalMemory;

BOOL InpOutInitialize(void);
BOOL InpOutDeinitialize(void);
