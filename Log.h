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

#ifndef _KERNEL_MODE_LOG_H_
#define _KERNEL_MODE_LOG_H_

//#define _DEBUG

#ifndef SE_DEBUG_OUTPUT
#ifndef _DEBUG
#define SE_DEBUG_OUTPUT(_x_, ...) __nop()
#else
#define SE_DEBUG_OUTPUT(_x_, ...) \
            (DbgPrint( \
				"[SE][SyscallTable] " ##_x_, ##__VA_ARGS__))
#endif // !_DEBUG
#endif // !SE_DEBUG_OUTPUT

#ifndef SE_SUCCESS
#define SE_SUCCESS(_exp) \
            ((NT_SUCCESS((NTSTATUS)(_exp))) ? \
                TRUE : (SE_DEBUG_OUTPUT(\
                "%s[%d] failed : [%08x]\n", \
                __FILE__, __LINE__, _exp), FALSE))
#endif // !SE_SUCCESS

#endif // !_KERNEL_MODE_LOG_H_
