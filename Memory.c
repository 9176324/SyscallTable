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

#include "Global.h"
#include "Memory.h"
#include "Log.h"
#include "SafeString.h"

#ifndef _KERNEL_MODE

NTSYSCALLAPI
PPEB
NTAPI
RtlGetCurrentPeb(
    VOID
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtAllocateVirtualMemory(
    __in HANDLE ProcessHandle,
    __inout PVOID * BaseAddress,
    __in ULONG_PTR ZeroBits,
    __inout PSIZE_T RegionSize,
    __in ULONG AllocationType,
    __in ULONG Protect
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtFreeVirtualMemory(
    __in HANDLE ProcessHandle,
    __inout PVOID * BaseAddress,
    __inout PSIZE_T RegionSize,
    __in ULONG FreeType
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtReadVirtualMemory(
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __out_bcount(BufferSize) PVOID Buffer,
    __in SIZE_T BufferSize,
    __out_opt PSIZE_T NumberOfBytesRead
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtWriteVirtualMemory(
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __in_bcount(BufferSize) CONST VOID * Buffer,
    __in SIZE_T BufferSize,
    __out_opt PSIZE_T NumberOfBytesWritten
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtProtectVirtualMemory(
    __in HANDLE ProcessHandle,
    __inout PVOID *BaseAddress,
    __inout PSIZE_T RegionSize,
    __in ULONG NewProtect,
    __out PULONG OldProtect
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtFlushInstructionCache(
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __in SIZE_T Length
);

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryVirtualMemory(
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress,
    __in SE_MEMORY_INFORMATION_CLASS MemoryInformationClass,
    __out_bcount(MemoryInformationLength) PVOID MemoryInformation,
    __in SIZE_T MemoryInformationLength,
    __out_opt PSIZE_T ReturnLength
);

#else

SE_EXTERN
NTSTATUS
NTAPI
SeZwAllocateVirtualMemory(
    __in HANDLE ProcessHandle,
    __inout PVOID * BaseAddress,
    __in ULONG_PTR ZeroBits,
    __inout PSIZE_T RegionSize,
    __in ULONG AllocationType,
    __in ULONG Protect
);

SE_EXTERN
NTSTATUS
NTAPI
SeZwFreeVirtualMemory(
    __in HANDLE ProcessHandle,
    __inout PVOID * BaseAddress,
    __inout PSIZE_T RegionSize,
    __in ULONG FreeType
);

SE_EXTERN
NTSTATUS
NTAPI
SeZwReadVirtualMemory(
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __out_bcount(BufferSize) PVOID Buffer,
    __in SIZE_T BufferSize,
    __out_opt PSIZE_T NumberOfBytesRead
);

SE_EXTERN
NTSTATUS
NTAPI
SeZwWriteVirtualMemory(
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __in_bcount(BufferSize) CONST VOID * Buffer,
    __in SIZE_T BufferSize,
    __out_opt PSIZE_T NumberOfBytesWritten
);

SE_EXTERN
NTSTATUS
NTAPI
SeZwProtectVirtualMemory(
    __in HANDLE ProcessHandle,
    __inout PVOID *BaseAddress,
    __inout PSIZE_T RegionSize,
    __in ULONG NewProtect,
    __out PULONG OldProtect
);

SE_EXTERN
NTSTATUS
NTAPI
SeZwFlushInstructionCache(
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __in SIZE_T Length
);

SE_EXTERN
NTSTATUS
NTAPI
SeZwQueryVirtualMemory(
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress,
    __in SE_MEMORY_INFORMATION_CLASS MemoryInformationClass,
    __out_bcount(MemoryInformationLength) PVOID MemoryInformation,
    __in SIZE_T MemoryInformationLength,
    __out_opt PSIZE_T ReturnLength
);

#endif // !_KERNEL_MODE

#ifndef _KERNEL_MODE

PVOID
NTAPI
SeGetProcessHeap(
    VOID
)
{
    HANDLE HeapHanlde = NULL;
    PSE_PEB Peb = NULL;

    Peb = SE_TO_TYPE(
        PSE_PEB,
        RtlGetCurrentPeb());

    if (Peb)
    {
        HeapHanlde = SE_TO_TYPE(
            HANDLE,
            Peb->ProcessHeap);
    }

    return HeapHanlde;
}

#endif // !_KERNEL_MODE

PVOID
NTAPI
SeAllocateVirtualMemory(
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress,
    __in SIZE_T RegionSize,
    __in ULONG AllocationType,
    __in ULONG Protect
)
{
    NTSTATUS Status = STATUS_SUCCESS;

#ifndef _KERNEL_MODE
    Status = NtAllocateVirtualMemory(
#else
    Status = SeZwAllocateVirtualMemory(
#endif // !_KERNEL_MODE
        ProcessHandle,
        &BaseAddress,
        0,
        &RegionSize,
        AllocationType,
        Protect);

    return BaseAddress;
}

NTSTATUS
NTAPI
SeFreeVirtualMemory(
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress,
    __inout SIZE_T RegionSize,
    __in ULONG FreeType
)
{
    NTSTATUS Status = STATUS_SUCCESS;

#ifndef _KERNEL_MODE
    Status = NtFreeVirtualMemory(
#else
    Status = SeZwFreeVirtualMemory(
#endif // !_KERNEL_MODE
        ProcessHandle,
        &BaseAddress,
        &RegionSize,
        FreeType);

    return Status;
}

NTSTATUS
NTAPI
SeProtectVirtualMemory(
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress,
    __in SIZE_T RegionSize,
    __in ULONG NewProtect,
    __out PULONG OldProtect
)
{
    NTSTATUS Status = STATUS_SUCCESS;

#ifndef _KERNEL_MODE
    Status = NtProtectVirtualMemory(
#else
    Status = SeZwProtectVirtualMemory(
#endif // !_KERNEL_MODE
        ProcessHandle,
        &BaseAddress,
        &RegionSize,
        NewProtect,
        OldProtect);

    return Status;
}

NTSTATUS
NTAPI
SeReadVirtualMemory(
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __out_bcount(BufferSize) PVOID Buffer,
    __in SIZE_T BufferSize,
    __out_opt PSIZE_T NumberOfBytesRead
)
{
    NTSTATUS Status = STATUS_SUCCESS;

#ifndef _KERNEL_MODE
    Status = NtReadVirtualMemory(
#else
    Status = SeZwReadVirtualMemory(
#endif // !_KERNEL_MODE
        ProcessHandle,
        BaseAddress,
        Buffer,
        BufferSize,
        NumberOfBytesRead);

    return Status;
}

NTSTATUS
NTAPI
SeWriteVirtualMemory(
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __in_bcount(BufferSize) CONST VOID * Buffer,
    __in SIZE_T BufferSize,
    __out_opt PSIZE_T NumberOfBytesWritten
)
{
    NTSTATUS Status = STATUS_SUCCESS;

#ifndef _KERNEL_MODE
    Status = NtWriteVirtualMemory(
#else
    Status = SeZwWriteVirtualMemory(
#endif // !_KERNEL_MODE
        ProcessHandle,
        BaseAddress,
        Buffer,
        BufferSize,
        NumberOfBytesWritten);

    return Status;
}

NTSTATUS
NTAPI
SeFlushInstructionCache(
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress,
    __in SIZE_T Length
)
{
    SE_PAGED_CODE();

    NTSTATUS Status = STATUS_SUCCESS;

#ifndef _KERNEL_MODE
    Status = NtFlushInstructionCache(
#else
    Status = SeZwFlushInstructionCache(
#endif // !_KERNEL_MODE
        ProcessHandle,
        BaseAddress,
        Length);

    return Status;
}

NTSTATUS
NTAPI
SeForceWriteVirtualMemory(
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __in_bcount(BufferSize) CONST VOID * Buffer,
    __in SIZE_T BufferSize
)
{
    SE_PAGED_CODE();

    NTSTATUS Status = STATUS_SUCCESS;
    ULONG Protect = 0;
    SIZE_T NumberOfBytesWritten = 0;

#ifndef _KERNEL_MODE

    Status = SeProtectVirtualMemory(
        ProcessHandle,
        BaseAddress,
        BufferSize,
        PAGE_EXECUTE_READWRITE,
        &Protect);

    if (SE_SUCCESS(
        Status))
    {
        Status = SeWriteVirtualMemory(
            ProcessHandle,
            BaseAddress,
            Buffer,
            BufferSize,
            &NumberOfBytesWritten);

        SeProtectVirtualMemory(
            ProcessHandle,
            BaseAddress,
            BufferSize,
            Protect,
            &Protect);

        SeFlushInstructionCache(
            ProcessHandle,
            BaseAddress,
            BufferSize);
    }

#else

    PHYSICAL_ADDRESS PhysicalAddress = { 0 };
    PVOID VirtualAddress = { 0 };

    if (BaseAddress > MM_HIGHEST_USER_ADDRESS)
    {
        PhysicalAddress = MmGetPhysicalAddress(
            BaseAddress);

        VirtualAddress = MmMapIoSpace(
            PhysicalAddress,
            BufferSize,
            MmNonCached);

        if (VirtualAddress)
        {
            RtlCopyMemory(
                VirtualAddress,
                Buffer,
                BufferSize);

            MmUnmapIoSpace(
                VirtualAddress,
                BufferSize);

            VirtualAddress = NULL;
        }
    }
    else
    {
        Status = SeProtectVirtualMemory(
            ProcessHandle,
            BaseAddress,
            BufferSize,
            PAGE_EXECUTE_READWRITE,
            &Protect);

        if (SE_SUCCESS(
            Status))
        {
            Status = SeWriteVirtualMemory(
                ProcessHandle,
                BaseAddress,
                Buffer,
                BufferSize,
                &NumberOfBytesWritten);

            SeProtectVirtualMemory(
                ProcessHandle,
                BaseAddress,
                BufferSize,
                Protect,
                &Protect);

            SeFlushInstructionCache(
                ProcessHandle,
                BaseAddress,
                BufferSize);
        }
    }

#endif // _KERNEL_MODE

    return Status;
}

#ifdef _KERNEL_MODE

PVOID
NTAPI
SeAllocatePoolWithTag(
    __in POOL_TYPE PoolType,
    __in SIZE_T NumberOfBytes,
    __in ULONG Tag
)
{
    SE_PAGED_CODE();

    PVOID BaseAddress = NULL;

    BaseAddress = ExAllocatePoolWithTag(
        PoolType,
        NumberOfBytes,
        Tag);

    if (BaseAddress)
    {
        RtlZeroMemory(
            BaseAddress,
            NumberOfBytes);
    }

    return BaseAddress;
}

VOID
NTAPI
SeFreePoolWithTag(
    __in PVOID BaseAddress,
    __in ULONG Tag
)
{
    SE_PAGED_CODE();

    if (BaseAddress)
    {
        ExFreePoolWithTag(
            BaseAddress, 
            Tag);
    }
}

PVOID
NTAPI
SeAllocateContiguousMemory(
    __in SIZE_T NumberOfBytes
)
{
    SE_PAGED_CODE();

    PHYSICAL_ADDRESS HighestAcceptableAddress = { 0 };
    PVOID BaseAddress = NULL;

    HighestAcceptableAddress.QuadPart = -1;

    BaseAddress = MmAllocateContiguousMemory(
        NumberOfBytes,
        HighestAcceptableAddress);

    if (BaseAddress)
    {
        RtlZeroMemory(
            BaseAddress,
            NumberOfBytes);
    }

    return BaseAddress;
}

VOID
NTAPI
SeFreeContiguousMemory(
    __in PVOID BaseAddress
)
{
    SE_PAGED_CODE();

    if (BaseAddress)
    {
        MmFreeContiguousMemory(
            BaseAddress);
    }
}

#endif // _KERNEL_MODE
