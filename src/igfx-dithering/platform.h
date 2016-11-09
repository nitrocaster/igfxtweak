#pragma once
#include "config.h"

#if defined(_M_X64) || defined(__amd64__)
#define PLATFORM_X64
#else
#define PLATFORM_X86
#endif
