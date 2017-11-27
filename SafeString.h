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

#ifndef _KERNEL_MODE_SAFESTRING_H_
#define _KERNEL_MODE_SAFESTRING_H_

ULONG
NTAPI
SeMultiByteToWideChar(
    __in PSTR MultiByteStr,
    __in ULONG WideCharLength,
    __out_bcount(WideCharLength) PWSTR WideCharStr
);

ULONG
NTAPI
SeWideCharToMultiByte(
    __in  PWSTR WideCharStr,
    __in ULONG MultiByteLength,
    __out_bcount(MultiByteLength) PSTR MultiByteStr
);

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
);

ULONG
NTAPI
SeWideCharPathToWideCharBaseName(
    __in PWSTR Path,
    __in ULONG BufferSize,
    __out_bcount(BufferSize) PWSTR Buffer
);

ULONG
NTAPI
SeWideCharPathToMultiByteBaseName(
    __in PWSTR Path,
    __in ULONG BufferSize,
    __out_bcount(BufferSize) PSTR Buffer
);

ULONG
NTAPI
SeCombModulePath(
    __in PWSTR DllName,
    __in UCHAR Arch,
    __in ULONG BufferSize,
    __out_bcount(BufferSize) PWSTR Buffer
);

#endif // !_KERNEL_MODE_SAFESTRING_H_
