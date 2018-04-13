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
* WITHOUT WARRANTY OF ANY KIND, either express or implied. SEe the License
* for the specific language governing rights and limitations under the
* License.
*
* The Initial Developer of the Original e is blindtiger.
*
*/

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <ntifs.h>
#include <intrin.h>
#include <ntddk.h>
#include <ntimage.h>
#include <ntddkbd.h>
#include <ntddmou.h>
#include <wmilib.h>
#include <ntstrsafe.h>

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

#include "Defines.h"
#include "NtApi.h"

#ifndef LOCK
#define LOCK(e) (ExEnterCriticalRegionAndAcquireResourceExclusive(e))
#endif // !LOCK

#ifndef UNLOCK
#define UNLOCK(e) (ExReleaseResourceAndLeaveCriticalRegion(e))
#endif // !UNLOCK

#ifdef VMP
#include "VMProtectDDK.h"
#endif // _VMP

#endif // !_GLOBAL_H_
