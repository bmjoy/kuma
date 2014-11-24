//
//  trace.cpp
//  kuma
//
//  Created by Fengping Bao <jamol@live.com> on 11/12/14.
//  Copyright (c) 2014. All rights reserved.
//

#include "kmtrace.h"

#include <stdio.h>
#include <stdarg.h>

KUMA_NS_BEGIN

#ifdef KUMA_OS_WIN
#define VSNPRINTF(d, dl, fmt, ...)    _vsnprintf_s(d, dl, _TRUNCATE, fmt, ##__VA_ARGS__)
#else
#define VSNPRINTF   vsnprintf
#endif

void TracePrint(int level, const char* szMessage, ...)
{
    va_list VAList;
    char szMsgBuf[2048] = {0};
    va_start(VAList, szMessage);
    VSNPRINTF(szMsgBuf, sizeof(szMsgBuf)-1, szMessage, VAList);
    
    switch(level)
    {
        case KUMA_TRACE_LEVEL_INFO:
            printf("INFO: %s", szMsgBuf);
            break;
        case KUMA_TRACE_LEVEL_WARN:
            printf("WARN: %s", szMsgBuf);
            break;
        case KUMA_TRACE_LEVEL_ERROR:
            printf("ERROR: %s", szMsgBuf);
            break;
        case KUMA_TRACE_LEVEL_DEBUG:
            printf("DEBUG: %s", szMsgBuf);
            break;
        default:
            printf("INFO: %s", szMsgBuf);
            break;
    }
}

KUMA_NS_END