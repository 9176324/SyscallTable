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

#ifndef _KERNEL_MODE_MEMORY_H_
#define _KERNEL_MODE_MEMORY_H_

#ifndef _KERNEL_MODE

#ifndef SeAllocatePool
#define SeAllocatePool(RegionSize)\
            HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, RegionSize)
#endif // !SeAllocatePool

#ifndef SeFreePool
#define SeFreePool(BaseAddress)\
            HeapFree(GetProcessHeap(), 0, BaseAddress)
#endif // !SeFreePool

NTSYSCALLAPI
PVOID
NTAPI
RtlAllocateHeap(
    __in PVOID HeapHandle,
    __in ULONG Flags,
    __in SIZE_T Size
);

NTSYSCALLAPI
BOOLEAN
NTAPI
RtlFreeHeap(
    __in PVOID HeapHandle,
    __in ULONG Flags,
    __in PVOID BaseAddress
);

PVOID
NTAPI
SeGetProcessHeap(
    VOID
);

#else

#ifndef SeAllocatePoolWithTag
#define SeAllocatePool(RegionSize) \
            SeAllocatePoolWithTag( \
                NonPagedPool, (RegionSize), 'rDeB')
#endif // !SeAllocatePool

#ifndef SeFreePool
#define SeFreePool(BaseAddress) \
            SeFreePoolWithTag( \
                SE_TO_TYPE(PVOID, (BaseAddress)), 'rDeB')
#endif // !SeFreePool

#endif // !_KENEL_MODE

typedef enum _SE_MEMORY_INFORMATION_CLASS {
    SeMemoryBasicInformation,
    SeMemoryMappedFilenameInformation,
    SeMemoryRegionInformation,
    SeMemoryWorkingSetExInformation
} SE_MEMORY_INFORMATION_CLASS;

PVOID
NTAPI
SeAllocateVirtualMemory(
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress,
    __in SIZE_T RegionSize,
    __in ULONG AllocationType,
    __in ULONG Protect
);

NTSTATUS
NTAPI
SeFreeVirtualMemory(
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress,
    __inout SIZE_T RegionSize,
    __in ULONG FreeType
);

NTSTATUS
NTAPI
SeProtectVirtualMemory(
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress,
    __in SIZE_T RegionSize,
    __in ULONG NewProtect,
    __out PULONG OldProtect
);

NTSTATUS
NTAPI
SeReadVirtualMemory(
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __out_bcount(BufferSize) PVOID Buffer,
    __in SIZE_T BufferSize,
    __out_opt PSIZE_T NumberOfBytesRead
);

NTSTATUS
NTAPI
SeWriteVirtualMemory(
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __in_bcount(BufferSize) CONST PVOID Buffer,
    __in SIZE_T BufferSize,
    __out_opt PSIZE_T NumberOfBytesWritten
);

NTSTATUS
NTAPI
SeFlushInstructionCache(
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress,
    __in SIZE_T Length
);

NTSTATUS
NTAPI
SeForceWriteVirtualMemory(
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __in_bcount(BufferSize) CONST VOID * Buffer,
    __in SIZE_T BufferSize
);

#ifdef _KERNEL_MODE

PVOID
NTAPI
SeAllocatePoolWithTag(
    __in POOL_TYPE PoolType,
    __in SIZE_T NumberOfBytes,
    __in ULONG Tag
);

VOID
NTAPI
SeFreePoolWithTag(
    __in PVOID BaseAddress,
    __in ULONG Tag
);

PVOID
NTAPI
SeAllocateContiguousMemory(
    __in SIZE_T NumberOfBytes
);

VOID
NTAPI
SeFreeContiguousMemory(
    __in PVOID BaseAddress
);

#endif // _KERNEL_MODE

#endif //!_KERNEL_MODE_MEMORY_H_
