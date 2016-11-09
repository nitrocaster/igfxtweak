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
