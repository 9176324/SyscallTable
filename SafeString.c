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
#include "SafeString.h"
#include "Log.h"

ULONG
NTAPI
SeMultiByteToWideChar(
    __in PSTR MultiByteStr,
    __in ULONG WideCharLength,
    __out_bcount(WideCharLength) PWSTR WideCharStr
)
{
    SE_PAGED_CODE();

    NTSTATUS Status = STATUS_SUCCESS;
    UNICODE_STRING UnicodeStr = { 0 };
    ANSI_STRING AnsiStr = { 0 };
    ULONG NeedLength = 0;

    RtlInitAnsiString(
        &AnsiStr,
        MultiByteStr);

    Status = RtlAnsiStringToUnicodeString(
        &UnicodeStr,
        &AnsiStr,
        TRUE);

    if (NT_SUCCESS(
        Status))
    {
        NeedLength = UnicodeStr.Length;

        if (NeedLength <= WideCharLength)
        {
            RtlZeroMemory(
                WideCharStr,
                WideCharLength);

            RtlCopyMemory(
                WideCharStr,
                SE_TO_TYPE(PWSTR, UnicodeStr.Buffer),
                NeedLength);
        }

        RtlFreeUnicodeString(
            &UnicodeStr);
    }

    return NeedLength;
}

ULONG
NTAPI
SeWideCharToMultiByte(
    __in  PWSTR WideCharStr,
    __in ULONG MultiByteLength,
    __out_bcount(MultiByteLength) PSTR MultiByteStr
)
{
    SE_PAGED_CODE();

    NTSTATUS Status = STATUS_SUCCESS;
    UNICODE_STRING UnicodeStr = { 0 };
    ANSI_STRING AnsiStr = { 0 };
    ULONG NeedLength = 0;

    RtlInitUnicodeString(
        &UnicodeStr,
        WideCharStr);

    Status = RtlUnicodeStringToAnsiString(
        &AnsiStr,
        &UnicodeStr,
        TRUE);

    if (NT_SUCCESS(
        Status))
    {
        NeedLength = UnicodeStr.Length;

        if (NeedLength <= MultiByteLength)
        {
            RtlZeroMemory(
                MultiByteStr,
                MultiByteLength);

            RtlCopyMemory(
                MultiByteStr,
                SE_TO_TYPE(PSTR, AnsiStr.Buffer),
                NeedLength);
        }

        RtlFreeAnsiString(
            &AnsiStr);
    }

    return NeedLength;
}

NTSTATUS
NTAPI
SeSplitWideCharPath(
    __in PWSTR Path,
    __in PULONG ReturnLength,
    __in ULONG DirectoryLength,
    __out_bcount(DirectoryLength) PWSTR Directory,
    __in ULONG BaseLength,
    __out_bcount(BaseLength) PWSTR Base,
    __in ULONG ExtLength,
    __out_bcount(ExtLength) PWSTR Ext
)
{
    SE_PAGED_CODE();

    NTSTATUS Status = STATUS_SUCCESS;
    PWSTR Pointer = NULL;
    PWSTR LastPointer = NULL;
    ULONG NeedLength = 0;

    LastPointer = Path + wcslen(Path);

    Pointer = wcsrchr(Path, '.');

    if (!Pointer)
    {
        Pointer = LastPointer;
    }

    NeedLength = SE_TO_TYPE(
        ULONG,
        (LastPointer - Pointer) * sizeof(WCHAR));

    if (NeedLength <= ExtLength)
    {
        RtlZeroMemory(
            Ext,
            ExtLength);

        RtlCopyMemory(
            Ext,
            Pointer,
            NeedLength);

        LastPointer = Pointer;
    }
    else
    {
        if (ReturnLength)
        {
            *ReturnLength = NeedLength;
        }

        Status = STATUS_INVALID_PARAMETER_7;
    }

    Pointer = wcsrchr(Path, '\\');

    if (Pointer)
    {
        Pointer += 1;
    }
    else
    {
        Pointer = Path;
    }

    NeedLength = SE_TO_TYPE(
        ULONG,
        (LastPointer - Pointer) * sizeof(WCHAR));

    if (NeedLength <= BaseLength)
    {
        RtlZeroMemory(
            Base,
            BaseLength);

        RtlCopyMemory(
            Base,
            Pointer,
            NeedLength);

        LastPointer = Pointer;
    }
    else
    {
        if (ReturnLength)
        {
            *ReturnLength = NeedLength;
        }

        Status = STATUS_INVALID_PARAMETER_5;
    }

    if (LastPointer > Path)
    {
        Pointer = Path;

        NeedLength = SE_TO_TYPE(
            ULONG,
            (LastPointer - Pointer) * sizeof(WCHAR));

        if (NeedLength <= DirectoryLength)
        {
            RtlZeroMemory(
                Directory,
                DirectoryLength);

            RtlCopyMemory(
                Directory,
                Pointer,
                NeedLength);

            LastPointer = Pointer;
        }
        else
        {
            if (ReturnLength)
            {
                *ReturnLength = NeedLength;
            }

            Status = STATUS_INVALID_PARAMETER_3;
        }
    }

    return Status;
}

ULONG
NTAPI
SeWideCharPathToWideCharBaseName(
    __in PWSTR Path,
    __in ULONG BufferSize,
    __out_bcount(BufferSize) PWSTR Buffer
)
{
    SE_PAGED_CODE();

    WCHAR Base[SE_MAX_PATH] = { 0 };
    WCHAR Ext[SE_MAX_PATH] = { 0 };
    WCHAR PathBuffer[SE_MAX_PATH] = { 0 };
    ULONG NeedLength = 0;

    SeSplitWideCharPath(
        Path,
        NULL,
        0,
        NULL,
        sizeof(Base),
        Base,
        sizeof(Ext),
        Ext);

    RtlZeroMemory(
        PathBuffer,
        sizeof(PathBuffer));

    wcscat_s(
        PathBuffer,
        sizeof(PathBuffer),
        Base);

    wcscat_s(
        PathBuffer,
        sizeof(PathBuffer),
        Ext);

    NeedLength = SE_TO_TYPE(
        ULONG,
        wcslen(PathBuffer) * sizeof(WCHAR));

    if (NeedLength <= BufferSize)
    {
        RtlZeroMemory(
            Buffer,
            BufferSize);

        RtlCopyMemory(
            Buffer,
            PathBuffer,
            NeedLength);
    }

    return NeedLength;
}

ULONG
NTAPI
SeWideCharPathToMultiByteBaseName(
    __in PWSTR Path,
    __in ULONG BufferSize,
    __out_bcount(BufferSize) PSTR Buffer
)
{
    WCHAR PathBuffer[SE_MAX_PATH] = { 0 };
    ULONG NeedLength = 0;

    NeedLength = SeWideCharPathToWideCharBaseName(
        Path,
        sizeof(PathBuffer),
        PathBuffer);

    NeedLength /= sizeof(WCHAR);

    if (NeedLength <= BufferSize)
    {
        SeWideCharToMultiByte(
            PathBuffer,
            BufferSize,
            Buffer);
    }

    return NeedLength;
}

ULONG
NTAPI
SeCombModulePath(
    __in PWSTR DllName,
    __in UCHAR Arch,
    __in ULONG BufferSize,
    __out_bcount(BufferSize) PWSTR Buffer
)
{
    SE_PAGED_CODE();

    WCHAR PathBuffer[SE_MAX_PATH] = { 0 };
    ULONG NeedLength = 0;

    RtlZeroMemory(
        PathBuffer,
        sizeof(PathBuffer));

#ifndef _WIN64

    if (32 == Arch)
    {
        wcscat_s(
            PathBuffer,
            sizeof(PathBuffer),
            L"\\SystemRoot\\System32\\");
    }

    wcscat_s(
        PathBuffer,
        sizeof(PathBuffer),
        DllName);

#else

    if (32 == Arch)
    {
        wcscat_s(
            PathBuffer,
            sizeof(PathBuffer),
            L"\\SystemRoot\\SysWOW64\\");
    }

    if (64 == Arch)
    {
        wcscat_s(
            PathBuffer,
            sizeof(PathBuffer),
            L"\\SystemRoot\\System32\\");
    }

    wcscat_s(
        PathBuffer,
        sizeof(PathBuffer),
        DllName);

#endif // !_WIN64

    NeedLength = SE_TO_TYPE(
        ULONG,
        wcslen(PathBuffer) * sizeof(WCHAR));

    if (NeedLength <= BufferSize)
    {
        RtlZeroMemory(
            Buffer,
            BufferSize);

        RtlCopyMemory(
            Buffer,
            PathBuffer,
            NeedLength);
    }

    return NeedLength;
}
