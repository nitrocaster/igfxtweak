#include "WinRing0.h"
#include "platform.h"

FindPciDeviceByClass_t FindPciDeviceByClass = NULL;
ReadPciConfigDwordEx_t ReadPciConfigDwordEx = NULL;
ReadPciConfigWordEx_t ReadPciConfigWordEx = NULL;

typedef int(WINAPI *InitializeOls_t)(void);
typedef int(WINAPI *DeinitializeOls_t)(void);
static InitializeOls_t InitializeOls;
static DeinitializeOls_t DeinitializeOls;
static BOOL initialized = FALSE;
static HANDLE hWinRing0 = NULL;

static void WinRing0Reset(void)
{
    if (hWinRing0)
        FreeLibrary(hWinRing0);
    hWinRing0 = NULL;
    FindPciDeviceByClass = NULL;
    ReadPciConfigDwordEx = NULL;
    ReadPciConfigWordEx = NULL;
    InitializeOls = NULL;
    DeinitializeOls = NULL;
}

BOOL WinRing0Initialize(void)
{
    if (initialized)
        return TRUE;
    do
    {
#ifdef PLATFORM_X64
        hWinRing0 = LoadLibrary("WinRing0x64.dll");
#else
        hWinRing0 = LoadLibrary("WinRing0.dll");
#endif
        if (!hWinRing0)
            break;
        if (!(FindPciDeviceByClass = GetProcAddress(hWinRing0, "FindPciDeviceByClass")))
            break;
        if (!(ReadPciConfigDwordEx = GetProcAddress(hWinRing0, "ReadPciConfigDwordEx")))
            break;
        if (!(ReadPciConfigWordEx = GetProcAddress(hWinRing0, "ReadPciConfigWordEx")))
            break;
        if (!(InitializeOls = GetProcAddress(hWinRing0, "InitializeOls")))
            break;
        if (!(DeinitializeOls = GetProcAddress(hWinRing0, "DeinitializeOls")))
            break;
        if (!InitializeOls())
            break;
        initialized = 1;
        return TRUE;
    } while (0);
    WinRing0Reset();
    return FALSE;
}

BOOL WinRing0Deinitialize(void)
{
    if (!initialized)
        return TRUE;
    DeinitializeOls();
    WinRing0Reset();
    initialized = 0;
    return TRUE;
}
