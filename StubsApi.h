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

#ifndef _STUBS_H_
#define _STUBS_H_

#ifdef __cplusplus
/* Assume byte packing throughout */
extern "C" {
#endif	/* __cplusplus */

NTKERNELAPI
NTSTATUS
NTAPI
StubDelayExecution (
    __in BOOLEAN Alertable,
    __in PLARGE_INTEGER DelayInterval
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQuerySystemEnvironmentValue (
    __in PUNICODE_STRING VariableName,
    __out_bcount(ValueLength) PWSTR VariableValue,
    __in USHORT ValueLength,
    __out_opt PUSHORT ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetSystemEnvironmentValue (
    __in PUNICODE_STRING VariableName,
    __in PUNICODE_STRING VariableValue
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQuerySystemEnvironmentValueEx (
    __in PUNICODE_STRING VariableName,
    __in LPGUID VendorGuid,
    __out_bcount_opt(*ValueLength) PVOID Value,
    __inout PULONG ValueLength,
    __out_opt PULONG Attributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetSystemEnvironmentValueEx (
    __in PUNICODE_STRING VariableName,
    __in LPGUID VendorGuid,
    __in_bcount_opt(ValueLength) PVOID Value,
    __in ULONG ValueLength,
    __in ULONG Attributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubEnumerateSystemEnvironmentValuesEx (
    __in ULONG InformationClass,
    __out PVOID Buffer,
    __inout PULONG BufferLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAddBootEntry (
    __in PBOOT_ENTRY BootEntry,
    __out_opt PULONG Id
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubDeleteBootEntry (
    __in ULONG Id
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubModifyBootEntry (
    __in PBOOT_ENTRY BootEntry
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubEnumerateBootEntries (
    __out_bcount_opt(*BufferLength) PVOID Buffer,
    __inout PULONG BufferLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryBootEntryOrder (
    __out_ecount_opt(*Count) PULONG Ids,
    __inout PULONG Count
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetBootEntryOrder (
    __in_ecount(Count) PULONG Ids,
    __in ULONG Count
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryBootOptions (
    __out_bcount_opt(*BootOptionsLength) PBOOT_OPTIONS BootOptions,
    __inout PULONG BootOptionsLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetBootOptions (
    __in PBOOT_OPTIONS BootOptions,
    __in ULONG FieldsToChange
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubTranslateFilePath (
    __in PFILE_PATH InputFilePath,
    __in ULONG OutputType,
    __out_bcount_opt(*OutputFilePathLength) PFILE_PATH OutputFilePath,
    __inout_opt PULONG OutputFilePathLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAddDriverEntry (
    __in PEFI_DRIVER_ENTRY DriverEntry,
    __out_opt PULONG Id
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubDeleteDriverEntry (
    __in ULONG Id
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubModifyDriverEntry (
    __in PEFI_DRIVER_ENTRY DriverEntry
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubEnumerateDriverEntries (
    __out_bcount(*BufferLength) PVOID Buffer,
    __inout PULONG BufferLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryDriverEntryOrder (
    __out_ecount(*Count) PULONG Ids,
    __inout PULONG Count
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetDriverEntryOrder (
    __in_ecount(Count) PULONG Ids,
    __in ULONG Count
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubClearEvent (
    __in HANDLE EventHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateEvent (
    __out PHANDLE EventHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes,
    __in EVENT_TYPE EventType,
    __in BOOLEAN InitialState
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenEvent (
    __out PHANDLE EventHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubPulseEvent (
    __in HANDLE EventHandle,
    __out_opt PLONG PreviousState
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryEvent (
    __in HANDLE EventHandle,
    __in EVENT_INFORMATION_CLASS EventInformationClass,
    __out_bcount(EventInformationLength) PVOID EventInformation,
    __in ULONG EventInformationLength,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubResetEvent (
    __in HANDLE EventHandle,
    __out_opt PLONG PreviousState
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetEvent (
    __in HANDLE EventHandle,
    __out_opt PLONG PreviousState
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetEventBoostPriority (
    __in HANDLE EventHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateEventPair (
    __out PHANDLE EventPairHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenEventPair (
    __out PHANDLE EventPairHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubWaitLowEventPair ( 
    __in HANDLE EventPairHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubWaitHighEventPair (
    __in HANDLE EventPairHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetLowWaitHighEventPair (
    __in HANDLE EventPairHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetHighWaitLowEventPair (
    __in HANDLE EventPairHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetLowEventPair (
    __in HANDLE EventPairHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetHighEventPair (
    __in HANDLE EventPairHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateMutant (
    __out PHANDLE MutantHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes,
    __in BOOLEAN InitialOwner
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenMutant (
    __out PHANDLE MutantHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryMutant (
    __in HANDLE MutantHandle,
    __in MUTANT_INFORMATION_CLASS MutantInformationClass,
    __out_bcount(MutantInformationLength) PVOID MutantInformation,
    __in ULONG MutantInformationLength,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubReleaseMutant (
    __in HANDLE MutantHandle,
    __out_opt PLONG PreviousCount
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateSemaphore (
    __out PHANDLE SemaphoreHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes,
    __in LONG InitialCount,
    __in LONG MaximumCount
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenSemaphore(
    __out PHANDLE SemaphoreHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQuerySemaphore (
    __in HANDLE SemaphoreHandle,
    __in SEMAPHORE_INFORMATION_CLASS SemaphoreInformationClass,
    __out_bcount(SemaphoreInformationLength) PVOID SemaphoreInformation,
    __in ULONG SemaphoreInformationLength,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubReleaseSemaphore(
    __in HANDLE SemaphoreHandle,
    __in LONG ReleaseCount,
    __out_opt PLONG PreviousCount
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateTimer (
    __out PHANDLE TimerHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes,
    __in TIMER_TYPE TimerType
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenTimer (
    __out PHANDLE TimerHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCancelTimer (
    __in HANDLE TimerHandle,
    __out_opt PBOOLEAN CurrentState
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryTimer (
    __in HANDLE TimerHandle,
    __in TIMER_INFORMATION_CLASS TimerInformationClass,
    __out_bcount(TimerInformationLength) PVOID TimerInformation,
    __in ULONG TimerInformationLength,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetTimer (
    __in HANDLE TimerHandle,
    __in PLARGE_INTEGER DueTime,
    __in_opt PTIMER_APC_ROUTINE TimerApcRoutine,
    __in_opt PVOID TimerContext,
    __in BOOLEAN ResumeTimer,
    __in_opt LONG Period,
    __out_opt PBOOLEAN PreviousState
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQuerySystemTime (
    __out PLARGE_INTEGER SystemTime
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetSystemTime (
    __in_opt PLARGE_INTEGER SystemTime,
    __out_opt PLARGE_INTEGER PreviousTime
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryTimerResolution (
    __out PULONG MaximumTime,
    __out PULONG MinimumTime,
    __out PULONG CurrentTime
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetTimerResolution (
    __in ULONG DesiredTime,
    __in BOOLEAN SetResolution,
    __out PULONG ActualTime
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAllocateLocallyUniqueId (
    __out PLUID Luid
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetUuidSeed (
    __in PCHAR Seed
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAllocateUuids (
    __out PULARGE_INTEGER Time,
    __out PULONG Range,
    __out PULONG Sequence,
    __out PCHAR Seed
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateProfile (
    __out PHANDLE ProfileHandle,
    __in HANDLE Process OPTIONAL,
    __in PVOID ProfileBase,
    __in SIZE_T ProfileSize,
    __in ULONG BucketSize,
    __in PULONG Buffer,
    __in ULONG BufferSize,
    __in KPROFILE_SOURCE ProfileSource,
    __in KAFFINITY Affinity
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubStartProfile (
    __in HANDLE ProfileHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubStopProfile (
    __in HANDLE ProfileHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetIntervalProfile (
    __in ULONG Interval,
    __in KPROFILE_SOURCE Source
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryIntervalProfile (
    __in KPROFILE_SOURCE ProfileSource,
    __out PULONG Interval
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryPerformanceCounter (
    __out PLARGE_INTEGER PerformanceCounter,
    __out_opt PLARGE_INTEGER PerformanceFrequency
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateKeyedEvent (
    __out PHANDLE KeyedEventHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes,
    __in ULONG Flags
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenKeyedEvent (
    __out PHANDLE KeyedEventHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubReleaseKeyedEvent (
    __in HANDLE KeyedEventHandle,
    __in PVOID KeyValue,
    __in BOOLEAN Alertable,
    __in_opt PLARGE_INTEGER Timeout
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubWaitForKeyedEvent (
    __in HANDLE KeyedEventHandle,
    __in PVOID KeyValue,
    __in BOOLEAN Alertable,
    __in_opt PLARGE_INTEGER Timeout
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQuerySystemInformation (
    __in SYSTEM_INFORMATION_CLASS SystemInformationClass,
    __out_bcount_opt(SystemInformationLength) PVOID SystemInformation,
    __in ULONG SystemInformationLength,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetSystemInformation (
    __in SYSTEM_INFORMATION_CLASS SystemInformationClass,
    __in_bcount_opt(SystemInformationLength) PVOID SystemInformation,
    __in ULONG SystemInformationLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSystemDebugControl (
    __in SYSDBG_COMMAND Command,
    __inout_bcount_opt(InputBufferLength) PVOID InputBuffer,
    __in ULONG InputBufferLength,
    __out_bcount_opt(OutputBufferLength) PVOID OutputBuffer,
    __in ULONG OutputBufferLength,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubRaiseHardError (
    __in NTSTATUS ErrorStatus,
    __in ULONG NumberOfParameters,
    __in ULONG UnicodeStringParameterMask,
    __in_ecount(NumberOfParameters) PULONG_PTR Parameters,
    __in ULONG ValidResponseOptions,
    __out PULONG Response
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryDefaultLocale (
    __in BOOLEAN UserProfile,
    __out PLCID DefaultLocaleId
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetDefaultLocale (
    __in BOOLEAN UserProfile,
    __in LCID DefaultLocaleId
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryInstallUILanguage (
    __out LANGID *InstallUILanguageId
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryDefaultUILanguage (
    __out LANGID *DefaultUILanguageId
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetDefaultUILanguage (
    __in LANGID DefaultUILanguageId
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetDefaultHardErrorPort(
    __in HANDLE DefaultHardErrorPort
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubShutdownSystem (
    __in SHUTDOWN_ACTION Action
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubDisplayString (
    __in PUNICODE_STRING String
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAddAtom (
    __in_bcount_opt(Length) PWSTR AtomName,
    __in ULONG Length,
    __out_opt PRTL_ATOM Atom
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubFindAtom (
    __in_bcount_opt(Length) PWSTR AtomName,
    __in ULONG Length,
    __out_opt PRTL_ATOM Atom
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubDeleteAtom (
    __in RTL_ATOM Atom
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryInformationAtom(
    __in RTL_ATOM Atom,
    __in ATOM_INFORMATION_CLASS AtomInformationClass,
    __out_bcount(AtomInformationLength) PVOID AtomInformation,
    __in ULONG AtomInformationLength,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCancelIoFile (
    __in HANDLE FileHandle,
    __out PIO_STATUS_BLOCK IoStatusBlock
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateNamedPipeFile (
     __out PHANDLE FileHandle,
     __in ULONG DesiredAccess,
     __in POBJECT_ATTRIBUTES ObjectAttributes,
     __out PIO_STATUS_BLOCK IoStatusBlock,
     __in ULONG ShareAccess,
     __in ULONG CreateDisposition,
     __in ULONG CreateOptions,
     __in ULONG NamedPipeType,
     __in ULONG ReadMode,
     __in ULONG CompletionMode,
     __in ULONG MaximumInstances,
     __in ULONG InboundQuota,
     __in ULONG OutboundQuota,
     __in_opt PLARGE_INTEGER DefaultTimeout
     );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateMailslotFile (
     __out PHANDLE FileHandle,
     __in ULONG DesiredAccess,
     __in POBJECT_ATTRIBUTES ObjectAttributes,
     __out PIO_STATUS_BLOCK IoStatusBlock,
     __in ULONG CreateOptions,
     __in ULONG MailslotQuota,
     __in ULONG MaximumMessageSize,
     __in PLARGE_INTEGER ReadTimeout
     );
NTKERNELAPI
NTSTATUS
NTAPI
StubDeleteFile (
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubFlushBuffersFile (
    __in HANDLE FileHandle,
    __out PIO_STATUS_BLOCK IoStatusBlock
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubNotifyChangeDirectoryFile (
    __in HANDLE FileHandle,
    __in_opt HANDLE Event,
    __in_opt PIO_APC_ROUTINE ApcRoutine,
    __in_opt PVOID ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __out_bcount(Length) PVOID Buffer,
    __in ULONG Length,
    __in ULONG CompletionFilter,
    __in BOOLEAN WatchTree
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryAttributesFile (
    __in POBJECT_ATTRIBUTES ObjectAttributes,
    __out PFILE_BASIC_INFORMATION FileInformation
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryFullAttributesFile(
    __in POBJECT_ATTRIBUTES ObjectAttributes,
    __out PFILE_NETWORK_OPEN_INFORMATION FileInformation
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryEaFile (
    __in HANDLE FileHandle,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __out_bcount(Length) PVOID Buffer,
    __in ULONG Length,
    __in BOOLEAN ReturnSingleEntry,
    __in_bcount_opt(EaListLength) PVOID EaList,
    __in ULONG EaListLength,
    __in_opt PULONG EaIndex OPTIONAL,
    __in BOOLEAN RestartScan
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateFile (
    __out PHANDLE FileHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in_opt PLARGE_INTEGER AllocationSize,
    __in ULONG FileAttributes,
    __in ULONG ShareAccess,
    __in ULONG CreateDisposition,
    __in ULONG CreateOptions,
    __in_bcount_opt(EaLength) PVOID EaBuffer,
    __in ULONG EaLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubDeviceIoControlFile (
    __in HANDLE FileHandle,
    __in_opt HANDLE Event,
    __in_opt PIO_APC_ROUTINE ApcRoutine,
    __in_opt PVOID ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in ULONG IoControlCode,
    __in_bcount_opt(InputBufferLength) PVOID InputBuffer,
    __in ULONG InputBufferLength,
    __out_bcount_opt(OutputBufferLength) PVOID OutputBuffer,
    __in ULONG OutputBufferLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubFsControlFile (
    __in HANDLE FileHandle,
    __in_opt HANDLE Event,
    __in_opt PIO_APC_ROUTINE ApcRoutine,
    __in_opt PVOID ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in ULONG FsControlCode,
    __in_bcount_opt(InputBufferLength) PVOID InputBuffer,
    __in ULONG InputBufferLength,
    __out_bcount_opt(OutputBufferLength) PVOID OutputBuffer,
    __in ULONG OutputBufferLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubLockFile (
    __in HANDLE FileHandle,
    __in_opt HANDLE Event,
    __in_opt PIO_APC_ROUTINE ApcRoutine,
    __in_opt PVOID ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in PLARGE_INTEGER ByteOffset,
    __in PLARGE_INTEGER Length,
    __in ULONG Key,
    __in BOOLEAN FailImmediately,
    __in BOOLEAN ExclusiveLock
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenFile (
    __out PHANDLE FileHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in ULONG ShareAccess,
    __in ULONG OpenOptions
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryDirectoryFile (
    __in HANDLE FileHandle,
    __in_opt HANDLE Event,
    __in_opt PIO_APC_ROUTINE ApcRoutine,
    __in_opt PVOID ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __out_bcount(Length) PVOID FileInformation,
    __in ULONG Length,
    __in FILE_INFORMATION_CLASS FileInformationClass,
    __in BOOLEAN ReturnSingleEntry,
    __in_opt PUNICODE_STRING FileName,
    __in BOOLEAN RestartScan
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryInformationFile (
    __in HANDLE FileHandle,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __out_bcount(Length) PVOID FileInformation,
    __in ULONG Length,
    __in FILE_INFORMATION_CLASS FileInformationClass
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryQuotaInformationFile (
    __in HANDLE FileHandle,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __out_bcount(Length) PVOID Buffer,
    __in ULONG Length,
    __in BOOLEAN ReturnSingleEntry,
    __in_bcount_opt(SidListLength) PVOID SidList,
    __in ULONG SidListLength,
    __in_opt PSID StartSid,
    __in BOOLEAN RestartScan
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryVolumeInformationFile (
    __in HANDLE FileHandle,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __out_bcount(Length) PVOID FsInformation,
    __in ULONG Length,
    __in FS_INFORMATION_CLASS FsInformationClass
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubReadFile (
    __in HANDLE FileHandle,
    __in_opt HANDLE Event,
    __in_opt PIO_APC_ROUTINE ApcRoutine,
    __in_opt PVOID ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __out_bcount(Length) PVOID Buffer,
    __in ULONG Length,
    __in_opt PLARGE_INTEGER ByteOffset,
    __in_opt PULONG Key
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetInformationFile (
    __in HANDLE FileHandle,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in_bcount(Length) PVOID FileInformation,
    __in ULONG Length,
    __in FILE_INFORMATION_CLASS FileInformationClass
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetQuotaInformationFile (
    __in HANDLE FileHandle,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in_bcount(Length) PVOID Buffer,
    __in ULONG Length
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetVolumeInformationFile (
    __in HANDLE FileHandle,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in_bcount(Length) PVOID FsInformation,
    __in ULONG Length,
    __in FS_INFORMATION_CLASS FsInformationClass
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubWriteFile (
    __in HANDLE FileHandle,
    __in_opt HANDLE Event,
    __in_opt PIO_APC_ROUTINE ApcRoutine,
    __in_opt PVOID ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in_bcount(Length) PVOID Buffer,
    __in ULONG Length,
    __in_opt PLARGE_INTEGER ByteOffset,
    __in_opt PULONG Key
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubUnlockFile (
    __in HANDLE FileHandle,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in PLARGE_INTEGER ByteOffset,
    __in PLARGE_INTEGER Length,
    __in ULONG Key
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubReadFileScatter (
    __in HANDLE FileHandle,
    __in_opt HANDLE Event,
    __in_opt PIO_APC_ROUTINE ApcRoutine,
    __in_opt PVOID ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in PFILE_SEGMENT_ELEMENT SegmentArray,
    __in ULONG Length,
    __in_opt PLARGE_INTEGER ByteOffset,
    __in_opt PULONG Key
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetEaFile (
    __in HANDLE FileHandle,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in_bcount(Length) PVOID Buffer,
    __in ULONG Length
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubWriteFileGather (
    __in HANDLE FileHandle,
    __in_opt HANDLE Event,
    __in_opt PIO_APC_ROUTINE ApcRoutine,
    __in_opt PVOID ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in PFILE_SEGMENT_ELEMENT SegmentArray,
    __in ULONG Length,
    __in_opt PLARGE_INTEGER ByteOffset,
    __in_opt PULONG Key
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubLoadDriver (
    __in PUNICODE_STRING DriverServiceName
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubUnloadDriver (
    __in PUNICODE_STRING DriverServiceName
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateIoCompletion (
    __out PHANDLE IoCompletionHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes,
    __in ULONG Count OPTIONAL
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenIoCompletion (
    __out PHANDLE IoCompletionHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryIoCompletion (
    __in HANDLE IoCompletionHandle,
    __in IO_COMPLETION_INFORMATION_CLASS IoCompletionInformationClass,
    __out_bcount(IoCompletionInformation) PVOID IoCompletionInformation,
    __in ULONG IoCompletionInformationLength,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetIoCompletion (
    __in HANDLE IoCompletionHandle,
    __in PVOID KeyContext,
    __in_opt PVOID ApcContext,
    __in NTSTATUS IoStatus,
    __in ULONG_PTR IoStatusInformation
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubRemoveIoCompletion (
    __in HANDLE IoCompletionHandle,
    __out PVOID *KeyContext,
    __out PVOID *ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in_opt PLARGE_INTEGER Timeout
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCallbackReturn (
    __in_bcount_opt(OutputLength) PVOID OutputBuffer,
    __in ULONG OutputLength,
    __in NTSTATUS Status
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryDebugFilterState (
    __in ULONG ComponentId,
    __in ULONG Level
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetDebugFilterState (
    __in ULONG ComponentId,
    __in ULONG Level,
    __in BOOLEAN State
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubYieldExecution (
    VOID
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreatePort(
    __out PHANDLE PortHandle,
    __in POBJECT_ATTRIBUTES ObjectAttributes,
    __in ULONG MaxConnectionInfoLength,
    __in ULONG MaxMessageLength,
    __in_opt ULONG MaxPoolUsage
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateWaitablePort(
    __out PHANDLE PortHandle,
    __in POBJECT_ATTRIBUTES ObjectAttributes,
    __in ULONG MaxConnectionInfoLength,
    __in ULONG MaxMessageLength,
    __in_opt ULONG MaxPoolUsage
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubConnectPort(
    __out PHANDLE PortHandle,
    __in PUNICODE_STRING PortName,
    __in PSECURITY_QUALITY_OF_SERVICE SecurityQos,
    __inout_opt PPORT_VIEW ClientView,
    __inout_opt PREMOTE_PORT_VIEW ServerView,
    __out_opt PULONG MaxMessageLength,
    __inout_opt PVOID ConnectionInformation,
    __inout_opt PULONG ConnectionInformationLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSecureConnectPort(
    __out PHANDLE PortHandle,
    __in PUNICODE_STRING PortName,
    __in PSECURITY_QUALITY_OF_SERVICE SecurityQos,
    __inout_opt PPORT_VIEW ClientView,
    __in_opt PSID RequiredServerSid,
    __inout_opt PREMOTE_PORT_VIEW ServerView,
    __out_opt PULONG MaxMessageLength,
    __inout_opt PVOID ConnectionInformation,
    __inout_opt PULONG ConnectionInformationLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubListenPort(
    __in HANDLE PortHandle,
    __out PPORT_MESSAGE ConnectionRequest
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAcceptConnectPort(
    __out PHANDLE PortHandle,
    __in_opt PVOID PortContext,
    __in PPORT_MESSAGE ConnectionRequest,
    __in BOOLEAN AcceptConnection,
    __inout_opt PPORT_VIEW ServerView,
    __out_opt PREMOTE_PORT_VIEW ClientView
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCompleteConnectPort(
    __in HANDLE PortHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubRequestPort(
    __in HANDLE PortHandle,
    __in PPORT_MESSAGE RequestMessage
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubRequestWaitReplyPort(
    __in HANDLE PortHandle,
    __in PPORT_MESSAGE RequestMessage,
    __out PPORT_MESSAGE ReplyMessage
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubReplyPort(
    __in HANDLE PortHandle,
    __in PPORT_MESSAGE ReplyMessage
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubReplyWaitReplyPort(
    __in HANDLE PortHandle,
    __inout PPORT_MESSAGE ReplyMessage
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubReplyWaitReceivePort(
    __in HANDLE PortHandle,
    __out_opt PVOID *PortContext ,
    __in_opt PPORT_MESSAGE ReplyMessage,
    __out PPORT_MESSAGE ReceiveMessage
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubReplyWaitReceivePortEx(
    __in HANDLE PortHandle,
    __out_opt PVOID *PortContext,
    __in_opt PPORT_MESSAGE ReplyMessage,
    __out PPORT_MESSAGE ReceiveMessage,
    __in_opt PLARGE_INTEGER Timeout
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubImpersonateClientOfPort(
    __in HANDLE PortHandle,
    __in PPORT_MESSAGE Message
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubReadRequestData(
    __in HANDLE PortHandle,
    __in PPORT_MESSAGE Message,
    __in ULONG DataEntryIndex,
    __out_bcount(BufferSize) PVOID Buffer,
    __in SIZE_T BufferSize,
    __out_opt PSIZE_T NumberOfBytesRead
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubWriteRequestData(
    __in HANDLE PortHandle,
    __in PPORT_MESSAGE Message,
    __in ULONG DataEntryIndex,
    __in_bcount(BufferSize) PVOID Buffer,
    __in SIZE_T BufferSize,
    __out_opt PSIZE_T NumberOfBytesWritten
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryInformationPort(
    __in HANDLE PortHandle,
    __in PORT_INFORMATION_CLASS PortInformationClass,
    __out_bcount(Length) PVOID PortInformation,
    __in ULONG Length,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateSection (
    __out PHANDLE SectionHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes,
    __in_opt PLARGE_INTEGER MaximumSize,
    __in ULONG SectionPageProtection,
    __in ULONG AllocationAttributes,
    __in_opt HANDLE FileHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenSection (
    __out PHANDLE SectionHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubMapViewOfSection (
    __in HANDLE SectionHandle,
    __in HANDLE ProcessHandle,
    __inout PVOID *BaseAddress,
    __in ULONG_PTR ZeroBits,
    __in SIZE_T CommitSize,
    __inout_opt PLARGE_INTEGER SectionOffset,
    __inout PSIZE_T ViewSize,
    __in SECTION_INHERIT InheritDisposition,
    __in ULONG AllocationType,
    __in ULONG Win32Protect
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubUnmapViewOfSection (
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubExtendSection (
    __in HANDLE SectionHandle,
    __inout PLARGE_INTEGER NewSectionSize
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAreMappedFilesTheSame (
    __in PVOID File1MappedAsAnImage,
    __in PVOID File2MappedAsFile
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAllocateVirtualMemory (
    __in HANDLE ProcessHandle,
    __inout PVOID *BaseAddress,
    __in ULONG_PTR ZeroBits,
    __inout PSIZE_T RegionSize,
    __in ULONG AllocationType,
    __in ULONG Protect
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubFreeVirtualMemory (
    __in HANDLE ProcessHandle,
    __inout PVOID *BaseAddress,
    __inout PSIZE_T RegionSize,
    __in ULONG FreeType
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubReadVirtualMemory (
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __out_bcount(BufferSize) PVOID Buffer,
    __in SIZE_T BufferSize,
    __out_opt PSIZE_T NumberOfBytesRead
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubWriteVirtualMemory (
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __in_bcount(BufferSize) CONST VOID *Buffer,
    __in SIZE_T BufferSize,
    __out_opt PSIZE_T NumberOfBytesWritten
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubFlushVirtualMemory (
    __in HANDLE ProcessHandle,
    __inout PVOID *BaseAddress,
    __inout PSIZE_T RegionSize,
    __out PIO_STATUS_BLOCK IoStatus
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubLockVirtualMemory (
    __in HANDLE ProcessHandle,
    __inout PVOID *BaseAddress,
    __inout PSIZE_T RegionSize,
    __in ULONG MapType
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubUnlockVirtualMemory ( 
    __in HANDLE ProcessHandle,
    __inout PVOID *BaseAddress,
    __inout PSIZE_T RegionSize,
    __in ULONG MapType
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubProtectVirtualMemory (
    __in HANDLE ProcessHandle,
    __inout PVOID *BaseAddress,
    __inout PSIZE_T RegionSize,
    __in ULONG NewProtect,
    __out PULONG OldProtect
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryVirtualMemory (
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress,
    __in MEMORY_INFORMATION_CLASS MemoryInformationClass,
    __out_bcount(MemoryInformationLength) PVOID MemoryInformation,
    __in SIZE_T MemoryInformationLength,
    __out_opt PSIZE_T ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQuerySection (
    __in HANDLE SectionHandle,
    __in SECTION_INFORMATION_CLASS SectionInformationClass,
    __out_bcount(SectionInformationLength) PVOID SectionInformation,
    __in SIZE_T SectionInformationLength,
    __out_opt PSIZE_T ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubMapUserPhysicalPages (
    __in PVOID VirtualAddress,
    __in ULONG_PTR NumberOfPages,
    __in_ecount_opt(NumberOfPages) PULONG_PTR UserPfnArray
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubMapUserPhysicalPagesScatter (
    __in_ecount(NumberOfPages) PVOID *VirtualAddresses,
    __in ULONG_PTR NumberOfPages,
    __in_ecount_opt(NumberOfPages) PULONG_PTR UserPfnArray
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAllocateUserPhysicalPages (
    __in HANDLE ProcessHandle,
    __inout PULONG_PTR NumberOfPages,
    __out_ecount(*NumberOfPages) PULONG_PTR UserPfnArray
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubFreeUserPhysicalPages (
    __in HANDLE ProcessHandle,
    __inout PULONG_PTR NumberOfPages,
    __in_ecount(*NumberOfPages) PULONG_PTR UserPfnArray
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubGetWriteWatch (
    __in HANDLE ProcessHandle,
    __in ULONG Flags,
    __in PVOID BaseAddress,
    __in SIZE_T RegionSize,
    __out_ecount(*EntriesInUserAddressArray) PVOID *UserAddressArray,
    __inout PULONG_PTR EntriesInUserAddressArray,
    __out PULONG Granularity
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubResetWriteWatch (
    __in HANDLE ProcessHandle,
    __in PVOID BaseAddress,
    __in SIZE_T RegionSize
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreatePagingFile (
    __in PUNICODE_STRING PageFileName,
    __in PLARGE_INTEGER MinimumSize,
    __in PLARGE_INTEGER MaximumSize,
    __in ULONG Priority
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubFlushInstructionCache (
    __in HANDLE ProcessHandle,
    __in_opt PVOID BaseAddress,
    __in SIZE_T Length
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubFlushWriteBuffer (
    VOID
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryObject (
    __in HANDLE Handle,
    __in OBJECT_INFORMATION_CLASS ObjectInformationClass,
    __out_bcount_opt(ObjectInformationLength) PVOID ObjectInformation,
    __in ULONG ObjectInformationLength,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetInformationObject (
    __in HANDLE Handle,
    __in OBJECT_INFORMATION_CLASS ObjectInformationClass,
    __in_bcount(ObjectInformationLength) PVOID ObjectInformation,
    __in ULONG ObjectInformationLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubDuplicateObject (
    __in HANDLE SourceProcessHandle,
    __in HANDLE SourceHandle,
    __in_opt HANDLE TargetProcessHandle,
    __out_opt PHANDLE TargetHandle,
    __in ACCESS_MASK DesiredAccess,
    __in ULONG HandleAttributes,
    __in ULONG Options
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubMakeTemporaryObject (
    __in HANDLE Handle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubMakePermanentObject (
    __in HANDLE Handle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSignalAndWaitForSingleObject (
    __in HANDLE SignalHandle,
    __in HANDLE WaitHandle,
    __in BOOLEAN Alertable,
    __in_opt PLARGE_INTEGER Timeout
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubWaitForSingleObject (
    __in HANDLE Handle,
    __in BOOLEAN Alertable,
    __in_opt PLARGE_INTEGER Timeout
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubWaitForMultipleObjects (
    __in ULONG Count,
    __in_ecount(Count) HANDLE Handles[],
    __in WAIT_TYPE WaitType,
    __in BOOLEAN Alertable,
    __in_opt PLARGE_INTEGER Timeout
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubWaitForMultipleObjects32 (
    __in ULONG Count,
    __in_ecount(Count) LONG Handles[],
    __in WAIT_TYPE WaitType,
    __in BOOLEAN Alertable,
    __in_opt PLARGE_INTEGER Timeout
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetSecurityObject (
    __in HANDLE Handle,
    __in SECURITY_INFORMATION SecurityInformation,
    __in PSECURITY_DESCRIPTOR SecurityDescriptor
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQuerySecurityObject (
    __in HANDLE Handle,
    __in SECURITY_INFORMATION SecurityInformation,
    __out_bcount_opt(Length) PSECURITY_DESCRIPTOR SecurityDescriptor,
    __in ULONG Length,
    __out PULONG LengthNeeded
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubClose (
    __in HANDLE Handle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateDirectoryObject (
    __out PHANDLE DirectoryHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenDirectoryObject (
    __out PHANDLE DirectoryHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryDirectoryObject (
    __in HANDLE DirectoryHandle,
    __out_bcount_opt(Length) PVOID Buffer,
    __in ULONG Length,
    __in BOOLEAN ReturnSingleEntry,
    __in BOOLEAN RestartScan,
    __inout PULONG Context,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateSymbolicLinkObject (
    __out PHANDLE LinkHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes,
    __in PUNICODE_STRING LinkTarget
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenSymbolicLinkObject (
    __out PHANDLE LinkHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQuerySymbolicLinkObject (
    __in HANDLE LinkHandle,
    __inout PUNICODE_STRING LinkTarget,
    __out_opt PULONG ReturnedLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubGetPlugPlayEvent (
    __in HANDLE EventHandle,
    __in_opt PVOID Context,
    __out_bcount(EventBufferSize) PPLUGPLAY_EVENT_BLOCK EventBlock,
    __in  ULONG EventBufferSize
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubPlugPlayControl(
    __in PLUGPLAY_CONTROL_CLASS PnPControlClass,
    __inout_bcount(PnPControlDataLength) PVOID PnPControlData,
    __in ULONG PnPControlDataLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubPowerInformation(
    __in POWER_INFORMATION_LEVEL InformationLevel,
    __in_bcount_opt(InputBufferLength) PVOID InputBuffer,
    __in ULONG InputBufferLength,
    __out_bcount_opt(OutputBufferLength) PVOID OutputBuffer,
    __in ULONG OutputBufferLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetThreadExecutionState(
    __in EXECUTION_STATE esFlags,               // ES_xxx flags
    __out EXECUTION_STATE *PreviousFlags
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubRequestWakeupLatency(
    __in LATENCY_TIME latency
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubInitiatePowerAction(
    __in POWER_ACTION SystemAction,
    __in SYSTEM_POWER_STATE MinSystemState,
    __in ULONG Flags,                 // POWER_ACTION_xxx flags
    __in BOOLEAN Asynchronous
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetSystemPowerState(
    __in POWER_ACTION SystemAction,
    __in SYSTEM_POWER_STATE MinSystemState,
    __in ULONG Flags                  // POWER_ACTION_xxx flags
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubGetDevicePowerState(
    __in HANDLE Device,
    __out DEVICE_POWER_STATE *State
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCancelDeviceWakeupRequest(
    __in HANDLE Device
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubRequestDeviceWakeup(
    __in HANDLE Device
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateProcess (
    __out PHANDLE ProcessHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes,
    __in HANDLE ParentProcess,
    __in BOOLEAN InheritObjectTable,
    __in_opt HANDLE SectionHandle,
    __in_opt HANDLE DebugPort,
    __in_opt HANDLE ExceptionPort
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateProcessEx (
    __out PHANDLE ProcessHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes,
    __in HANDLE ParentProcess,
    __in ULONG Flags,
    __in_opt HANDLE SectionHandle,
    __in_opt HANDLE DebugPort,
    __in_opt HANDLE ExceptionPort,
    __in ULONG JobMemberLevel
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenProcess (
    __out PHANDLE ProcessHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes,
    __in_opt PCLIENT_ID ClientId
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubTerminateProcess (
    __in_opt HANDLE ProcessHandle,
    __in NTSTATUS ExitStatus
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryInformationProcess (
    __in HANDLE ProcessHandle,
    __in PROCESSINFOCLASS ProcessInformationClass,
    __out_bcount(ProcessInformationLength) PVOID ProcessInformation,
    __in ULONG ProcessInformationLength,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubGetNextProcess (
    __in HANDLE ProcessHandle,
    __in ACCESS_MASK DesiredAccess,
    __in ULONG HandleAttributes,
    __in ULONG Flags,
    __out PHANDLE NewProcessHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubGetNextThread (
    __in HANDLE ProcessHandle,
    __in HANDLE ThreadHandle,
    __in ACCESS_MASK DesiredAccess,
    __in ULONG HandleAttributes,
    __in ULONG Flags,
    __out PHANDLE NewThreadHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryPortInformationProcess (
    VOID
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetInformationProcess (
    __in HANDLE ProcessHandle,
    __in PROCESSINFOCLASS ProcessInformationClass,
    __in_bcount(ProcessInformationLength) PVOID ProcessInformation,
    __in ULONG ProcessInformationLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateThread (
    __out PHANDLE ThreadHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes,
    __in HANDLE ProcessHandle,
    __out PCLIENT_ID ClientId,
    __in PCONTEXT ThreadContext,
    __in PINITIAL_TEB InitialTeb,
    __in BOOLEAN CreateSuspended
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenThread (
    __out PHANDLE ThreadHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes,
    __in_opt PCLIENT_ID ClientId
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubTerminateThread (
    __in_opt HANDLE ThreadHandle,
    __in NTSTATUS ExitStatus
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSuspendThread (
    __in HANDLE ThreadHandle,
    __out_opt PULONG PreviousSuspendCount
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubResumeThread (
    __in HANDLE ThreadHandle,
    __out_opt PULONG PreviousSuspendCount
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSuspendProcess (
    __in HANDLE ProcessHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubResumeProcess (
    __in HANDLE ProcessHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubGetContextThread (
    __in HANDLE ThreadHandle,
    __inout PCONTEXT ThreadContext
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetContextThread (
    __in HANDLE ThreadHandle,
    __in PCONTEXT ThreadContext
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryInformationThread (
    __in HANDLE ThreadHandle,
    __in THREADINFOCLASS ThreadInformationClass,
    __out_bcount(ThreadInformationLength) PVOID ThreadInformation,
    __in ULONG ThreadInformationLength,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetInformationThread (
    __in HANDLE ThreadHandle,
    __in THREADINFOCLASS ThreadInformationClass,
    __in_bcount(ThreadInformationLength) PVOID ThreadInformation,
    __in ULONG ThreadInformationLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAlertThread (
    __in HANDLE ThreadHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAlertResumeThread (
    __in HANDLE ThreadHandle,
    __out_opt PULONG PreviousSuspendCount
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubImpersonateThread (
    __in HANDLE ServerThreadHandle,
    __in HANDLE ClientThreadHandle,
    __in PSECURITY_QUALITY_OF_SERVICE SecurityQos
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubTestAlert (
    VOID
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubRegisterThreadTerminatePort (
    __in HANDLE PortHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetLdtEntries (
    __in ULONG Selector0,
    __in ULONG Entry0Low,
    __in ULONG Entry0Hi,
    __in ULONG Selector1,
    __in ULONG Entry1Low,
    __in ULONG Entry1Hi
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueueApcThread (
    __in HANDLE ThreadHandle,
    __in PPS_APC_ROUTINE ApcRoutine,
    __in_opt PVOID ApcArgument1,
    __in_opt PVOID ApcArgument2,
    __in_opt PVOID ApcArgument3
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateJobObject (
    __out PHANDLE JobHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenJobObject (
    __out PHANDLE JobHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAssignProcessToJobObject (
    __in HANDLE JobHandle,
    __in HANDLE ProcessHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubTerminateJobObject (
    __in HANDLE JobHandle,
    __in NTSTATUS ExitStatus
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubIsProcessInJob (
    __in HANDLE ProcessHandle,
    __in_opt HANDLE JobHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateJobSet (
    __in ULONG NumJob,
    __in_ecount(NumJob) PJOB_SET_ARRAY UserJobSet,
    __in ULONG Flags
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryInformationJobObject (
    __in_opt HANDLE JobHandle,
    __in JOBOBJECTINFOCLASS JobObjectInformationClass,
    __out_bcount(JobObjectInformationLength) PVOID JobObjectInformation,
    __in ULONG JobObjectInformationLength,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetInformationJobObject (
    __in HANDLE JobHandle,
    __in JOBOBJECTINFOCLASS JobObjectInformationClass,
    __in_bcount(JobObjectInformationLength) PVOID JobObjectInformation,
    __in ULONG JobObjectInformationLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateKey(
    __out PHANDLE KeyHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes,
    __reserved ULONG TitleIndex,
    __in_opt PUNICODE_STRING Class,
    __in ULONG CreateOptions,
    __out_opt PULONG Disposition
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubDeleteKey(
    __in HANDLE KeyHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubDeleteValueKey(
    __in HANDLE KeyHandle,
    __in PUNICODE_STRING ValueName
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubEnumerateKey(
    __in HANDLE KeyHandle,
    __in ULONG Index,
    __in KEY_INFORMATION_CLASS KeyInformationClass,
    __out_bcount_opt(Length) PVOID KeyInformation,
    __in ULONG Length,
    __out PULONG ResultLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubEnumerateValueKey(
    __in HANDLE KeyHandle,
    __in ULONG Index,
    __in KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
    __out_bcount_opt(Length) PVOID KeyValueInformation,
    __in ULONG Length,
    __out PULONG ResultLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubFlushKey(
    __in HANDLE KeyHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubInitializeRegistry(
    __in USHORT BootCondition
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubNotifyChangeKey(
    __in HANDLE KeyHandle,
    __in_opt HANDLE Event,
    __in_opt PIO_APC_ROUTINE ApcRoutine,
    __in_opt PVOID ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in ULONG CompletionFilter,
    __in BOOLEAN WatchTree,
    __out_bcount_opt(BufferSize) PVOID Buffer,
    __in ULONG BufferSize,
    __in BOOLEAN Asynchronous
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubNotifyChangeMultipleKeys(
    __in HANDLE MasterKeyHandle,
    __in_opt ULONG Count,
    __in_ecount_opt(Count) OBJECT_ATTRIBUTES SlaveObjects[],
    __in_opt HANDLE Event,
    __in_opt PIO_APC_ROUTINE ApcRoutine,
    __in_opt PVOID ApcContext,
    __out PIO_STATUS_BLOCK IoStatusBlock,
    __in ULONG CompletionFilter,
    __in BOOLEAN WatchTree,
    __out_bcount_opt(BufferSize) PVOID Buffer,
    __in ULONG BufferSize,
    __in BOOLEAN Asynchronous
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubLoadKey(
    __in POBJECT_ATTRIBUTES TargetKey,
    __in POBJECT_ATTRIBUTES SourceFile
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubLoadKey2(
    __in POBJECT_ATTRIBUTES   TargetKey,
    __in POBJECT_ATTRIBUTES   SourceFile,
    __in ULONG                Flags
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubLoadKeyEx(
    __in POBJECT_ATTRIBUTES   TargetKey,
    __in POBJECT_ATTRIBUTES   SourceFile,
    __in ULONG                Flags,
    __in_opt HANDLE           TrustClassKey 
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenKey(
    __out PHANDLE KeyHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryKey(
    __in HANDLE KeyHandle,
    __in KEY_INFORMATION_CLASS KeyInformationClass,
    __out_bcount_opt(Length) PVOID KeyInformation,
    __in ULONG Length,
    __out PULONG ResultLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryValueKey(
    __in HANDLE KeyHandle,
    __in PUNICODE_STRING ValueName,
    __in KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
    __out_bcount_opt(Length) PVOID KeyValueInformation,
    __in ULONG Length,
    __out PULONG ResultLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryMultipleValueKey(
    __in HANDLE KeyHandle,
    __inout_ecount(EntryCount) PKEY_VALUE_ENTRY ValueEntries,
    __in ULONG EntryCount,
    __out_bcount(*BufferLength) PVOID ValueBuffer,
    __inout PULONG BufferLength,
    __out_opt PULONG RequiredBufferLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubReplaceKey(
    __in POBJECT_ATTRIBUTES NewFile,
    __in HANDLE             TargetHandle,
    __in POBJECT_ATTRIBUTES OldFile
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubRenameKey(
    __in HANDLE           KeyHandle,
    __in PUNICODE_STRING  NewName
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCompactKeys(
    __in ULONG Count,
    __in_ecount(Count) HANDLE KeyArray[]
            );
NTKERNELAPI
NTSTATUS
NTAPI
StubCompressKey(
    __in HANDLE Key
            );
NTKERNELAPI
NTSTATUS
NTAPI
StubRestoreKey(
    __in HANDLE KeyHandle,
    __in HANDLE FileHandle,
    __in ULONG Flags
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSaveKey(
    __in HANDLE KeyHandle,
    __in HANDLE FileHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSaveKeyEx(
    __in HANDLE KeyHandle,
    __in HANDLE FileHandle,
    __in ULONG  Format
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSaveMergedKeys(
    __in HANDLE HighPrecedenceKeyHandle,
    __in HANDLE LowPrecedenceKeyHandle,
    __in HANDLE FileHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetValueKey(
    __in HANDLE KeyHandle,
    __in PUNICODE_STRING ValueName,
    __in_opt ULONG TitleIndex,
    __in ULONG Type,
    __in_bcount_opt(DataSize) PVOID Data,
    __in ULONG DataSize
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubUnloadKey(
    __in POBJECT_ATTRIBUTES TargetKey
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubUnloadKey2(
    __in POBJECT_ATTRIBUTES   TargetKey,
    __in ULONG                Flags
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubUnloadKeyEx(
    __in POBJECT_ATTRIBUTES TargetKey,
    __in_opt HANDLE Event
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetInformationKey(
    __in HANDLE KeyHandle,
    __in KEY_SET_INFORMATION_CLASS KeySetInformationClass,
    __in_bcount(KeySetInformationLength) PVOID KeySetInformation,
    __in ULONG KeySetInformationLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryOpenSubKeys(
    __in POBJECT_ATTRIBUTES TargetKey,
    __out PULONG  HandleCount
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryOpenSubKeysEx(
    __in POBJECT_ATTRIBUTES   TargetKey,
    __in ULONG                BufferLength,
    __out_bcount(BufferLength) PVOID               Buffer,
    __out PULONG              RequiredSize
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubLockRegistryKey(
    __in HANDLE           KeyHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubLockProductActivationKeys(
    __inout_opt ULONG   *pPrivateVer,
    __out_opt ULONG   *pSafeMode
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAccessCheck (
    __in PSECURITY_DESCRIPTOR SecurityDescriptor,
    __in HANDLE ClientToken,
    __in ACCESS_MASK DesiredAccess,
    __in PGENERIC_MAPPING GenericMapping,
    __out_bcount(*PrivilegeSetLength) PPRIVILEGE_SET PrivilegeSet,
    __inout PULONG PrivilegeSetLength,
    __out PACCESS_MASK GrantedAccess,
    __out PNTSTATUS AccessStatus
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAccessCheckByType (
    __in PSECURITY_DESCRIPTOR SecurityDescriptor,
    __in_opt PSID PrincipalSelfSid,
    __in HANDLE ClientToken,
    __in ACCESS_MASK DesiredAccess,
    __in_ecount(ObjectTypeListLength) POBJECT_TYPE_LIST ObjectTypeList,
    __in ULONG ObjectTypeListLength,
    __in PGENERIC_MAPPING GenericMapping,
    __out_bcount(*PrivilegeSetLength) PPRIVILEGE_SET PrivilegeSet,
    __inout PULONG PrivilegeSetLength,
    __out PACCESS_MASK GrantedAccess,
    __out PNTSTATUS AccessStatus
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAccessCheckByTypeResultList (
    __in PSECURITY_DESCRIPTOR SecurityDescriptor,
    __in_opt PSID PrincipalSelfSid,
    __in HANDLE ClientToken,
    __in ACCESS_MASK DesiredAccess,
    __in_ecount(ObjectTypeListLength) POBJECT_TYPE_LIST ObjectTypeList,
    __in ULONG ObjectTypeListLength,
    __in PGENERIC_MAPPING GenericMapping,
    __out_bcount(*PrivilegeSetLength) PPRIVILEGE_SET PrivilegeSet,
    __inout PULONG PrivilegeSetLength,
    __out_ecount(ObjectTypeListLength) PACCESS_MASK GrantedAccess,
    __out_ecount(ObjectTypeListLength) PNTSTATUS AccessStatus
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCreateToken(
    __out PHANDLE TokenHandle,
    __in ACCESS_MASK DesiredAccess,
    __in_opt POBJECT_ATTRIBUTES ObjectAttributes,
    __in TOKEN_TYPE TokenType,
    __in PLUID AuthenticationId,
    __in PLARGE_INTEGER ExpirationTime,
    __in PTOKEN_USER User,
    __in PTOKEN_GROUPS Groups,
    __in PTOKEN_PRIVILEGES Privileges,
    __in_opt PTOKEN_OWNER Owner,
    __in PTOKEN_PRIMARY_GROUP PrimaryGroup,
    __in_opt PTOKEN_DEFAULT_DACL DefaultDacl,
    __in PTOKEN_SOURCE TokenSource
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCompareTokens(
    __in HANDLE FirstTokenHandle,
    __in HANDLE SecondTokenHandle,
    __out PBOOLEAN Equal
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenThreadToken(
    __in HANDLE ThreadHandle,
    __in ACCESS_MASK DesiredAccess,
    __in BOOLEAN OpenAsSelf,
    __out PHANDLE TokenHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenThreadTokenEx(
    __in HANDLE ThreadHandle,
    __in ACCESS_MASK DesiredAccess,
    __in BOOLEAN OpenAsSelf,
    __in ULONG HandleAttributes,
    __out PHANDLE TokenHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenProcessToken(
    __in HANDLE ProcessHandle,
    __in ACCESS_MASK DesiredAccess,
    __out PHANDLE TokenHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenProcessTokenEx(
    __in HANDLE ProcessHandle,
    __in ACCESS_MASK DesiredAccess,
    __in ULONG HandleAttributes,
    __out PHANDLE TokenHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubDuplicateToken(
    __in HANDLE ExistingTokenHandle,
    __in ACCESS_MASK DesiredAccess,
    __in POBJECT_ATTRIBUTES ObjectAttributes,
    __in BOOLEAN EffectiveOnly,
    __in TOKEN_TYPE TokenType,
    __out PHANDLE NewTokenHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubFilterToken (
    __in HANDLE ExistingTokenHandle,
    __in ULONG Flags,
    __in_opt PTOKEN_GROUPS SidsToDisable,
    __in_opt PTOKEN_PRIVILEGES PrivilegesToDelete,
    __in_opt PTOKEN_GROUPS RestrictedSids,
    __out PHANDLE NewTokenHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubImpersonateAnonymousToken(
    __in HANDLE ThreadHandle
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubQueryInformationToken (
    __in HANDLE TokenHandle,
    __in TOKEN_INFORMATION_CLASS TokenInformationClass,
    __out_bcount_part_opt(TokenInformationLength,*ReturnLength) PVOID TokenInformation,
    __in ULONG TokenInformationLength,
    __out PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubSetInformationToken (
    __in HANDLE TokenHandle,
    __in TOKEN_INFORMATION_CLASS TokenInformationClass,
    __in_bcount(TokenInformationLength) PVOID TokenInformation,
    __in ULONG TokenInformationLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAdjustPrivilegesToken (
    __in HANDLE TokenHandle,
    __in BOOLEAN DisableAllPrivileges,
    __in_opt PTOKEN_PRIVILEGES NewState,
    __in_opt ULONG BufferLength,
    __out_bcount_part_opt(BufferLength,*ReturnLength) PTOKEN_PRIVILEGES PreviousState,
    __out_opt PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAdjustGroupsToken (
    __in HANDLE TokenHandle,
    __in BOOLEAN ResetToDefault,
    __in PTOKEN_GROUPS NewState ,
    __in_opt ULONG BufferLength ,
    __out_bcount_part_opt(BufferLength, *ReturnLength) PTOKEN_GROUPS PreviousState ,
    __out PULONG ReturnLength
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubPrivilegeCheck (
    __in HANDLE ClientToken,
    __inout PPRIVILEGE_SET RequiredPrivileges,
    __out PBOOLEAN Result
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAccessCheckAndAuditAlarm (
    __in PUNICODE_STRING SubsystemName,
    __in_opt PVOID HandleId,
    __in PUNICODE_STRING ObjectTypeName,
    __in PUNICODE_STRING ObjectName,
    __in PSECURITY_DESCRIPTOR SecurityDescriptor,
    __in ACCESS_MASK DesiredAccess,
    __in PGENERIC_MAPPING GenericMapping,
    __in BOOLEAN ObjectCreation,
    __out PACCESS_MASK GrantedAccess,
    __out PNTSTATUS AccessStatus,
    __out PBOOLEAN GenerateOnClose
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAccessCheckByTypeAndAuditAlarm (
    __in PUNICODE_STRING SubsystemName,
    __in_opt PVOID HandleId,
    __in PUNICODE_STRING ObjectTypeName,
    __in PUNICODE_STRING ObjectName,
    __in PSECURITY_DESCRIPTOR SecurityDescriptor,
    __in_opt PSID PrincipalSelfSid,
    __in ACCESS_MASK DesiredAccess,
    __in AUDIT_EVENT_TYPE AuditType,
    __in ULONG Flags,
    __in_ecount_opt(ObjectTypeListLength) POBJECT_TYPE_LIST ObjectTypeList,
    __in ULONG ObjectTypeListLength,
    __in PGENERIC_MAPPING GenericMapping,
    __in BOOLEAN ObjectCreation,
    __out PACCESS_MASK GrantedAccess,
    __out PNTSTATUS AccessStatus,
    __out PBOOLEAN GenerateOnClose
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAccessCheckByTypeResultListAndAuditAlarm (
    __in PUNICODE_STRING SubsystemName,
    __in_opt PVOID HandleId,
    __in PUNICODE_STRING ObjectTypeName,
    __in PUNICODE_STRING ObjectName,
    __in PSECURITY_DESCRIPTOR SecurityDescriptor,
    __in_opt PSID PrincipalSelfSid,
    __in ACCESS_MASK DesiredAccess,
    __in AUDIT_EVENT_TYPE AuditType,
    __in ULONG Flags,
    __in_ecount_opt(ObjectTypeListLength) POBJECT_TYPE_LIST ObjectTypeList,
    __in ULONG ObjectTypeListLength,
    __in PGENERIC_MAPPING GenericMapping,
    __in BOOLEAN ObjectCreation,
    __out_ecount(ObjectTypeListLength) PACCESS_MASK GrantedAccess,
    __out_ecount(ObjectTypeListLength) PNTSTATUS AccessStatus,
    __out PBOOLEAN GenerateOnClose
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubAccessCheckByTypeResultListAndAuditAlarmByHandle (
    __in PUNICODE_STRING SubsystemName,
    __in_opt PVOID HandleId,
    __in HANDLE ClientToken,
    __in PUNICODE_STRING ObjectTypeName,
    __in PUNICODE_STRING ObjectName,
    __in PSECURITY_DESCRIPTOR SecurityDescriptor,
    __in_opt PSID PrincipalSelfSid,
    __in ACCESS_MASK DesiredAccess,
    __in AUDIT_EVENT_TYPE AuditType,
    __in ULONG Flags,
    __in_ecount_opt(ObjectTypeListLength) POBJECT_TYPE_LIST ObjectTypeList,
    __in ULONG ObjectTypeListLength,
    __in PGENERIC_MAPPING GenericMapping,
    __in BOOLEAN ObjectCreation,
    __out_ecount(ObjectTypeListLength) PACCESS_MASK GrantedAccess,
    __out_ecount(ObjectTypeListLength) PNTSTATUS AccessStatus,
    __out PBOOLEAN GenerateOnClose
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubOpenObjectAuditAlarm (
    __in PUNICODE_STRING SubsystemName,
    __in_opt PVOID HandleId,
    __in PUNICODE_STRING ObjectTypeName,
    __in PUNICODE_STRING ObjectName,
    __in_opt PSECURITY_DESCRIPTOR SecurityDescriptor,
    __in HANDLE ClientToken,
    __in ACCESS_MASK DesiredAccess,
    __in ACCESS_MASK GrantedAccess,
    __in_opt PPRIVILEGE_SET Privileges,
    __in BOOLEAN ObjectCreation,
    __in BOOLEAN AccessGranted,
    __out PBOOLEAN GenerateOnClose
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubPrivilegeObjectAuditAlarm (
    __in PUNICODE_STRING SubsystemName,
    __in_opt PVOID HandleId,
    __in HANDLE ClientToken,
    __in ACCESS_MASK DesiredAccess,
    __in PPRIVILEGE_SET Privileges,
    __in BOOLEAN AccessGranted
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubCloseObjectAuditAlarm (
    __in PUNICODE_STRING SubsystemName,
    __in_opt PVOID HandleId,
    __in BOOLEAN GenerateOnClose
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubDeleteObjectAuditAlarm (
    __in PUNICODE_STRING SubsystemName,
    __in_opt PVOID HandleId,
    __in BOOLEAN GenerateOnClose
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubPrivilegedServiceAuditAlarm (
    __in PUNICODE_STRING SubsystemName,
    __in PUNICODE_STRING ServiceName,
    __in HANDLE ClientToken,
    __in PPRIVILEGE_SET Privileges,
    __in BOOLEAN AccessGranted
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubTraceEvent(
    __in HANDLE TraceHandle,
    __in ULONG Flags,
    __in ULONG FieldSize,
    __in PVOID Fields
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubContinue (
    __in PCONTEXT ContextRecord,
    __in BOOLEAN TestAlert
    );
NTKERNELAPI
NTSTATUS
NTAPI
StubRaiseException (
    __in PEXCEPTION_RECORD ExceptionRecord,
    __in PCONTEXT ContextRecord,
    __in BOOLEAN FirstChance
    );

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif // !_STUBS_H_
