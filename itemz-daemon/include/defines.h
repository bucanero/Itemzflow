#pragma once

/*
    ES2_goodness, a GLES2 playground on EGL

    2019-2021 masterzorag & LM

    here follows the parts:
*/

// nfs or local stdio
//#define USE_NFS  (1)
#if defined (USE_NFS)
#include <orbisNfs.h>
#endif

// common
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "net.h"
#include <stdbool.h>
#include <utils.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include "log.h"
#include <libkernel.h>  //sceKernelIccSetBuzzer

#define HOME_TITLE_ID "ITEM00001"
#define PS_BUTTON 0x10000
#define SCE_LNC_UTIL_ERROR_ALREADY_RUNNING 0x8094000c
#define SCE_SYSMODULE_INTERNAL_COMMON_DIALOG 0x80000018
#define SCE_SYSMODULE_INTERNAL_SYSUTIL 0x80000018
#define SCE_LNC_ERROR_APP_NOT_FOUND 0x80940031 // Usually happens if you to launch an app not in app.db
#define SCE_LNC_UTIL_ERROR_ALREADY_INITIALIZED 0x80940018
#define SCE_LNC_UTIL_ERROR_ALREADY_RUNNING 0x8094000c
#define SCE_LNC_UTIL_ERROR_ALREADY_RUNNING_KILL_NEEDED 0x80940010
#define SCE_LNC_UTIL_ERROR_ALREADY_RUNNING_SUSPEND_NEEDED 0x80940011
#define SCE_LNC_UTIL_ERROR_APP_ALREADY_RESUMED 0x8094001e
#define SCE_LNC_UTIL_ERROR_APP_ALREADY_SUSPENDED 0x8094001d
#define SCE_LNC_UTIL_ERROR_APP_NOT_IN_BACKGROUND 0x80940015
#define SCE_LNC_UTIL_ERROR_APPHOME_EBOOTBIN_NOT_FOUND 0x80940008
#define SCE_LNC_UTIL_ERROR_APPHOME_PARAMSFO_NOT_FOUND 0x80940009
#define SCE_LNC_UTIL_ERROR_CANNOT_RESUME_INITIAL_USER_NEEDED 0x80940012
#define SCE_LNC_UTIL_ERROR_DEVKIT_EXPIRED 0x8094000b
#define SCE_LNC_UTIL_ERROR_IN_LOGOUT_PROCESSING 0x8094001a
#define SCE_LNC_UTIL_ERROR_IN_SPECIAL_RESUME 0x8094001b
#define SCE_LNC_UTIL_ERROR_INVALID_PARAM 0x80940005
#define SCE_LNC_UTIL_ERROR_INVALID_STATE 0x80940019
#define SCE_LNC_UTIL_ERROR_INVALID_TITLE_ID 0x8094001c
#define SCE_LNC_UTIL_ERROR_LAUNCH_DISABLED_BY_MEMORY_MODE 0x8094000d
#define SCE_LNC_UTIL_ERROR_NO_APP_INFO 0x80940004
#define SCE_LNC_UTIL_ERROR_NO_LOGIN_USER 0x8094000a
#define SCE_LNC_UTIL_ERROR_NO_SESSION_MEMORY 0x80940002
#define SCE_LNC_UTIL_ERROR_NO_SFOKEY_IN_APP_INFO 0x80940014
#define SCE_LNC_UTIL_ERROR_NO_SHELL_UI 0x8094000e
#define SCE_LNC_UTIL_ERROR_NOT_ALLOWED 0x8094000f
#define SCE_LNC_UTIL_ERROR_NOT_INITIALIZED 0x80940001
#define SCE_LNC_UTIL_ERROR_OPTICAL_DISC_DRIVE 0x80940013
#define SCE_LNC_UTIL_ERROR_SETUP_FS_SANDBOX 0x80940006
#define SCE_LNC_UTIL_ERROR_SUSPEND_BLOCK_TIMEOUT 0x80940017
#define SCE_LNC_UTIL_ERROR_VIDEOOUT_NOT_SUPPORTED 0x80940016
#define SCE_LNC_UTIL_ERROR_WAITING_READY_FOR_SUSPEND_TIMEOUT 0x80940021
#define SCE_SYSCORE_ERROR_LNC_INVALID_STATE 0x80aa000a
#define SCE_LNC_UTIL_ERROR_NOT_INITIALIZED 0x80940001
#define SCE_SYSMODULE_INTERNAL_SYS_CORE 0x80000004
#define SCE_SYSMODULE_INTERNAL_NETCTL 0x80000009
#define SCE_SYSMODULE_INTERNAL_HTTP 0x8000000A
#define SCE_SYSMODULE_INTERNAL_SSL 0x8000000B
#define SCE_SYSMODULE_INTERNAL_NP_COMMON 0x8000000C
#define SCE_SYSMODULE_INTERNAL_SYSTEM_SERVICE 0x80000010
#define SCE_SYSMODULE_INTERNAL_USER_SERVICE 0x80000011
#define SCE_SYSMODULE_INTERNAL_APPINSTUTIL 0x80000014
#define SCE_SYSMODULE_INTERNAL_NET 0x8000001C
#define SCE_SYSMODULE_INTERNAL_IPMI 0x8000001D
#define SCE_SYSMODULE_INTERNAL_VIDEO_OUT 0x80000022
#define SCE_SYSMODULE_INTERNAL_BGFT 0x8000002A
#define SCE_SYSMODULE_INTERNAL_PRECOMPILED_SHADERS 0x80000064

#define BUILD_YEAR_CH0 (__DATE__[ 7])
#define BUILD_YEAR_CH1 (__DATE__[ 8])
#define BUILD_YEAR_CH2 (__DATE__[ 9])
#define BUILD_YEAR_CH3 (__DATE__[10])


#define BUILD_MONTH_IS_JAN (__DATE__[0] == 'J' && __DATE__[1] == 'a' && __DATE__[2] == 'n')
#define BUILD_MONTH_IS_FEB (__DATE__[0] == 'F')
#define BUILD_MONTH_IS_MAR (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'r')
#define BUILD_MONTH_IS_APR (__DATE__[0] == 'A' && __DATE__[1] == 'p')
#define BUILD_MONTH_IS_MAY (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'y')
#define BUILD_MONTH_IS_JUN (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'n')
#define BUILD_MONTH_IS_JUL (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'l')
#define BUILD_MONTH_IS_AUG (__DATE__[0] == 'A' && __DATE__[1] == 'u')
#define BUILD_MONTH_IS_SEP (__DATE__[0] == 'S')
#define BUILD_MONTH_IS_OCT (__DATE__[0] == 'O')
#define BUILD_MONTH_IS_NOV (__DATE__[0] == 'N')
#define BUILD_MONTH_IS_DEC (__DATE__[0] == 'D')


#define BUILD_MONTH_CH0 \
    ((BUILD_MONTH_IS_OCT || BUILD_MONTH_IS_NOV || BUILD_MONTH_IS_DEC) ? '1' : '0')

#define BUILD_MONTH_CH1 \
    ( \
        (BUILD_MONTH_IS_JAN) ? '1' : \
        (BUILD_MONTH_IS_FEB) ? '2' : \
        (BUILD_MONTH_IS_MAR) ? '3' : \
        (BUILD_MONTH_IS_APR) ? '4' : \
        (BUILD_MONTH_IS_MAY) ? '5' : \
        (BUILD_MONTH_IS_JUN) ? '6' : \
        (BUILD_MONTH_IS_JUL) ? '7' : \
        (BUILD_MONTH_IS_AUG) ? '8' : \
        (BUILD_MONTH_IS_SEP) ? '9' : \
        (BUILD_MONTH_IS_OCT) ? '0' : \
        (BUILD_MONTH_IS_NOV) ? '1' : \
        (BUILD_MONTH_IS_DEC) ? '2' : \
        /* error default */    '?' \
    )

#define BUILD_DAY_CH0 ((__DATE__[4] >= '0') ? (__DATE__[4]) : '0')
#define BUILD_DAY_CH1 (__DATE__[ 5])



// Example of __TIME__ string: "21:06:19"
//                              01234567

#define BUILD_HOUR_CH0 (__TIME__[0])
#define BUILD_HOUR_CH1 (__TIME__[1])

#define BUILD_MIN_CH0 (__TIME__[3])
#define BUILD_MIN_CH1 (__TIME__[4])

#define BUILD_SEC_CH0 (__TIME__[6])
#define BUILD_SEC_CH1 (__TIME__[7])


#if VERSION_MAJOR > 100

#define VERSION_MAJOR_INIT \
    ((VERSION_MAJOR / 100) + '0'), \
    (((VERSION_MAJOR % 100) / 10) + '0'), \
    ((VERSION_MAJOR % 10) + '0')

#elif VERSION_MAJOR > 10

#define VERSION_MAJOR_INIT \
    ((VERSION_MAJOR / 10) + '0'), \
    ((VERSION_MAJOR % 10) + '0')

#else

#define VERSION_MAJOR_INIT \
    (VERSION_MAJOR + '0')

#endif

#if VERSION_MINOR > 100

#define VERSION_MINOR_INIT \
    ((VERSION_MINOR / 100) + '0'), \
    (((VERSION_MINOR % 100) / 10) + '0'), \
    ((VERSION_MINOR % 10) + '0')

#elif VERSION_MINOR > 10

#define VERSION_MINOR_INIT \
    ((VERSION_MINOR / 10) + '0'), \
    ((VERSION_MINOR % 10) + '0')

#else

#define VERSION_MINOR_INIT \
    (VERSION_MINOR + '0')
#endif
