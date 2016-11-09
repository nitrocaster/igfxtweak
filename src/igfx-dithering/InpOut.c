#include "InpOut.h"

IsInpOutDriverOpen_t IsInpOutDriverOpen = NULL;
MapPhysToLin_t MapPhysToLin = NULL;
UnmapPhysicalMemory_t UnmapPhysicalMemory = NULL;

static BOOL initialized = FALSE;
static HANDLE hInpOut = NULL;

static void InpOutReset(void)
{
    if (hInpOut)
        FreeLibrary(hInpOut);
    hInpOut = NULL;
    IsInpOutDriverOpen = NULL;
    MapPhysToLin = NULL;
    UnmapPhysicalMemory = NULL;
}

BOOL InpOutInitialize(void)
{
    if (initialized)
        return TRUE;
    do
    {
#if defined(_M_X64) || defined(__amd64__)
        hInpOut = LoadLibrary("inpoutx64.dll");
#else
        hInpOut = LoadLibrary("inpout32.dll");
#endif
        if (!hInpOut)
            break;
        if (!(IsInpOutDriverOpen = GetProcAddress(hInpOut, "IsInpOutDriverOpen")))
            break;
        if (!(MapPhysToLin = GetProcAddress(hInpOut, "MapPhysToLin")))
            break;
        if (!(UnmapPhysicalMemory = GetProcAddress(hInpOut, "UnmapPhysicalMemory")))
            break;
        initialized = 1;
        return TRUE;
    } while (0);
    InpOutReset();
    return FALSE;
}

BOOL InpOutDeinitialize(void)
{
    if (!initialized)
        return TRUE;
    InpOutReset();
    initialized = 0;
    return TRUE;
}
