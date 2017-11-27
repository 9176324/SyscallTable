/*
*
* Copyright (c) 2015-2017 by blindtiger ( blindtiger@foxmail.com )
*
* The contents of this file are subject to the Mozilla Public License Version
* 2.0 (the "License"); you may not use this file except in compliance with
* the License. You may obtain a copy of the License at
* http://www.mozilla.org/MPL/
*
* Software distributed under the License is distributed on an "AS IS" basis,
* WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
* for the specific language governing rights and limitations under the
* License.
*
* The Initial Developer of the Original Code is blindtiger.
*
*/

#ifndef _KERNEL_MODE_GLOBAL_H_
#define _KERNEL_MODE_GLOBAL_H_

//#ifndef VMP
//#define VMP
//#endif // !VMP

#ifndef SE_TO_TYPE
#define SE_TO_TYPE(_t_, _v_) \
            ((_t_)(ULONG_PTR)(_v_))
#endif // !SE_TO_TYPE

#ifndef _KERNEL_MODE

#define UMDF_USING_NTSTATUS

#include <windows.h>
#include <windowsx.h>
#include <intrin.h>
#include <ntstatus.h>
#include <winternl.h>
#include <psapi.h>

#pragma comment(lib, "ntdllp.lib")

#ifndef VMP
#define SE_VMP_BEGIN(_x_) __noop
#define SE_VMP_END __nop
#else
#define SE_VMP_BEGIN(_x_) VMProtectBeginUltra(_x_)
#define SE_VMP_END VMProtectEnd
#include "..\ThirdParty\VMProtect\Include\VMProtectSDK.h"
#ifndef _WIN64
#pragma comment(lib, "..\\ThirdParty\\VMProtect\\Lib\\VMProtectSDK32.lib")
#else
#pragma comment(lib, "..\\ThirdParty\\VMProtect\\Lib\\VMProtectSDK64.lib")
#endif // !_WIN64
#endif // VMP

#ifndef NtCurrentProcess
#define NtCurrentProcess() \
            SE_TO_TYPE(HANDLE, (-1L))
#endif // !NtCurrentProcess

#ifndef NtCurrentThread
#define NtCurrentThread() \
            SE_TO_TYPE(HANDLE, (-2L))
#endif // !NtCurrentThread

#ifndef NtCurrentSession
#define NtCurrentSession() \
            SE_TO_TYPE(HANDLE, (-3L))
#endif // !NtCurrentSession

#else

#include <ntifs.h>
#include <intrin.h>
#include <ntddk.h>
#include <ntimage.h>
#include <ntddkbd.h>
#include <ntddmou.h>
#include <wmilib.h>
#include <ntstrsafe.h>

#ifndef VMP
#define SE_VMP_BEGIN(_x_) __noop
#define SE_VMP_END __nop
#else
#define SE_VMP_BEGIN(_x_) VMProtectBeginUltra(_x_)
#define SE_VMP_END VMProtectEnd
#include "..\ThirdParty\VMProtect\Include\VMProtectDDK.h"
#ifndef _WIN64
#pragma comment(lib, "..\\ThirdParty\\VMProtect\\Lib\\VMProtectDDK32.lib")
#else
#pragma comment(lib, "..\\ThirdParty\\VMProtect\\Lib\\VMProtectDDK64.lib")
#endif // !_WIN64
#endif // VMP

#ifndef ZwCurrentProcess
#define ZwCurrentProcess() \
            SE_TO_TYPE(HANDLE, (-1L))
#endif // !ZwCurrentProcess

#ifndef ZwCurrentThread
#define ZwCurrentThread() \
            SE_TO_TYPE(HANDLE, (-2L))
#endif // !NtCurrentThread

#ifndef ZwCurrentSession
#define ZwCurrentSession() \
            SE_TO_TYPE(HANDLE, (-3L))
#endif // !ZwCurrentSession

#endif // _KERNEL_MODE

#ifndef _KERNEL_MODE
#define SE_PAGED_CODE() __noop
#else
#define SE_PAGED_CODE() PAGED_CODE()
#endif // _KERNEL_MODE

#ifndef SE_PLATFORM_SUFFIX86
#define SE_PLATFORM_SUFFIX86 (L"x86")
#endif // !SE_PLATFORM_SUFFIX86

#ifndef SE_PLATFORM_SUFFIX64
#define SE_PLATFORM_SUFFIX64 (L"x64")
#endif // !SE_PLATFORM_SUFFIX64

#ifndef SE_PLATFORM_SUFFIX_LENGTH
#define SE_PLATFORM_SUFFIX_LENGTH 3
#endif // !SE_PLATFORM_SUFFIX_LENGTH

#ifndef SE_CODE32_ALIGNMENT
#define SE_CODE32_ALIGNMENT (0x20)
#endif // !SE_CODE32_ALIGNMENT

#ifndef SE_CODE64_ALIGNMENT
#define SE_CODE64_ALIGNMENT (0x40)
#endif // !SE_CODE64_ALIGNMENT

#ifndef SE_CODE_ALIGNMENT
#ifndef _WIN64
#define SE_CODE_ALIGNMENT (0x20)
#else
#define SE_CODE_ALIGNMENT (0x40)
#endif // !_WIN64
#endif // !SE_CODE_ALIGNMENT

#ifndef SE_ADD_POINTER
#define SE_ADD_POINTER(_p1_, _p2_) \
            SE_TO_TYPE( \
                PVOID, \
                SE_TO_TYPE(ULONG_PTR, (_p1_)) + \
                SE_TO_TYPE(ULONG_PTR, (_p2_)))
#endif // !SE_ADD_POINTER

#ifndef SE_SUB_POINTER
#define SE_SUB_POINTER(_p1_, _p2_) \
            SE_TO_TYPE( \
                PVOID, \
                SE_TO_TYPE(ULONG_PTR, (_p1_)) - \
                SE_TO_TYPE(ULONG_PTR, (_p2_)))
#endif // !SE_SUB_POINTER

#ifndef SE_JMP_TO_VA
#define SE_JMP_TO_VA(_p_) \
            SE_ADD_POINTER( \
                SE_ADD_POINTER( \
                    (_p_), \
                    *SE_TO_TYPE( \
                        PLONG, (_p_))), \
                04L)
#endif // !SE_JMP_TO_VA

#ifndef SE_VA_TO_JMP
#define SE_VA_TO_JMP(_p1_, _p2_) \
            SE_TO_TYPE( \
                LONG, \
                SE_SUB_POINTER( \
                    SE_SUB_POINTER( \
                        (_p2_), (_p1_)), \
                    04L))
#endif // !SE_VA_TO_JMP

#ifndef SE_OFFSETOF
#define SE_OFFSETOF(s, m) \
            ((SIZE_T)&(((s*)0)->m))
#endif // !SE_OFFSETOF

#ifndef SE_EXTERN
#define SE_EXTERN extern
#endif // !SE_EXTERN

#ifndef SE_STATIC
#define SE_STATIC static
#endif // !SE_STATIC

#ifndef SE_REGISTER
#define SE_REGISTER register
#endif // !SE_REGISTER

#ifndef SE_CDECL
#define SE_CDECL __cdecl
#endif // !SE_CDECL

#ifndef SE_LOBYTE
#define SE_LOBYTE(_x_) \
            SE_TO_TYPE( \
                UCHAR, ((ULONG_PTR)(_x_)) & 0xff)
#endif // !SE_LOBYTE

#ifndef SE_HIBYTE
#define SE_HIBYTE(_x_) \
            SE_TO_TYPE( \
                UCHAR, ((ULONG_PTR)(_x_) >> 8) & 0xff)
#endif // !SE_HIBYTE

#ifndef SE_LOWORD
#define SE_LOWORD(_x_) \
            SE_TO_TYPE( \
                USHORT, ((ULONG_PTR)(_x_)) & 0xffff)
#endif // !SE_LOWORD

#ifndef SE_HIWORD
#define SE_HIWORD(_x_) \
            SE_TO_TYPE( \
                USHORT, ((ULONG_PTR)(_x_) >> 16) & 0xffff)
#endif // !SE_HIWORD

#ifndef SE_LODWOWD
#define SE_LODWOWD(_x_) \
            SE_TO_TYPE( \
                ULONG, ((ULONG_PTR)(_x_)) & 0xffffffff)
#endif // !SE_LODWOWD

#ifndef SE_HIDWOWD
#define SE_HIDWOWD(_x_) \
            SE_TO_TYPE( \
                ULONG, ((ULONG_PTR)(_x_) >> 32) & 0xffffffff)
#endif // !SE_HIDWOWD

#ifndef SE_TYPE32
#define SE_TYPE32(x) ULONG
#endif // !SE_TYPE32

#ifndef SE_TYPE64
#define SE_TYPE64(x) ULONGLONG
#endif // !SE_TYPE64

#ifndef SE_TYPE_PTR
#ifndef _WIN64
#define SE_TYPE_PTR(x) ULONG
#else
#define SE_TYPE_PTR(x) ULONGLONG
#endif // !_WIN64
#endif // !SE_TYPE_PTR

#ifndef SE_COUNTOF
#define SE_COUNTOF(_x_) \
     (sizeof(_x_) / sizeof(_x_[0]))
#endif // !SE_COUNTOF

#ifndef SE_MAX_PATH
#define SE_MAX_PATH 260
#endif // !SE_MAX_PATH

#ifndef SE_MAGIC_MASK
#define SE_MAGIC_MASK 0xf0f0f0f0
#endif // !SE_MAGIC_MASK

#endif // !_KERNEL_MODE_GLOBAL_H_
