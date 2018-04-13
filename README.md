SyscallTable is a library to call windows kernel SysStubs (Windows 7 - Windows 10), 
both support x86 and x64, it is very convenient to use.

## Build steps :
	Copy code file to you source directory.
	Import file to you project. 
	Declaring function with "Stub" prefix, it is not use "Zw" or "Nt" to prevent conflicts.
	Use it like sample code, needn't include any header file.
	
## Sample :

	extern
	NTSTATUS
	NTAPI
	StubProtectVirtualMemory(
	    __in HANDLE ProcessHandle,
	    __inout PVOID *BaseAddress,
	    __inout PSIZE_T RegionSize,
	    __in ULONG NewProtect,
	    __out PULONG OldProtect
	);

	// ...
		
	NTSTATUS
	NTAPI
	ProtectVirtualMemory(
	    __inout PVOID BaseAddress,
	    __inout SIZE_T RegionSize,
	    __in ULONG NewProtect,
	    __out PULONG OldProtect
	)
	{
	    NTSTATUS Status = STATUS_SUCCESS;

	    Status = StubProtectVirtualMemory(
		ZwCurrentProcess(),
		&BaseAddress,
		&RegionSize,
		NewProtect,
		OldProtect);

	    return Status;
	}

	// ...
	