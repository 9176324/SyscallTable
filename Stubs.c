/*
*
* Copyright (c) 2015-2017 by blindtiger ( blindtiger@foxmail.com )
*
* The contents of this file are subject to the Mozilla Public License Version
* 2.0 (the "License"); you may not use this file except in compliance with
* the License. You may obtain a copy of the License at
* http://www.mozilla.org/MPL/
*
* Software distributed under the License is distributed on an "AS IS" basis;
* WITHOUT WARRANTY OF ANY KIND; either express or implied. Rdee the License
* for the specific language governing rights and limitations under the
* License.
*
* The Initial Developer of the Original e is blindtiger.
*
*/

#include <OsDefs.h>

#include "Stubs.h"

#pragma optimize("g", off)

extern KSTUBS_ENTRY ServiceDispatchTable;
static PKSERVICE_TABLE_DESCRIPTOR ServiceDescriptorTable;
static KSPIN_LOCK Lock;

#ifndef _WIN64
/*
STUBS_ENTRY macro ServiceNumber, Name, NumArgs
    cPublicProc _Stub&Name, NumArgs
        extrn _KiSystemService : PROC

        mov eax, ServiceNumber          ; (eax) = service number
        lea edx, [esp] + 4              ; (edx) -> arguments
        pushfd                          ; EFLAGS to trap frame
        push KGDT_R0_CODE               ; CS to trap frame
        call _KiSystemService           ; EIP to trap frame and enter handler

        stdRET _Stub&Name

    stdENDP _Stub&Name

endm
*/

static CHAR StubsEntry[] = {
    0xb8, 0xff, 0xff, 0xff, 0xff,
    // mov eax, KiServiceTableIndex
    0x8d, 0x54, 0x24, 0x04,
    0x9c,
    0x6a, 0x08,
    0xe8, 0xff, 0xff, 0xff, 0xff
    // call KiSystemRervice
    // 0xcc, 0xcc, 0xcc, 0xcc,
    // 0xcc, 0xcc, 0xcc, 0xcc,
    // 0xcc, 0xcc, 0xcc, 0xcc,
    // 0xcc, 0xcc, 0xcc
};

C_ASSERT(sizeof(StubsEntry) == 0x20 - 0xf);
#else
/*
SYSSTUBS_ENTRY macro ServiceNumber, Name, NumArgs
    extern KiServiceInternal : proc
    extern KiServiceLinkage : proc

    NESTED_ENTRY Stub&Name, _TEXT$00, , NoPad

        mov [rsp + 8], rcx          ; save argument register
        mov [rsp + 10h], rdx        ;
        mov [rsp + 18h], r8         ;
        mov [rsp + 20h], r9         ;

        mov	rax, rsp                ; save stack address
        cli                         ; disable interrupts
        sub rsp, 16                 ; alignment and dummy SS selector
        push rax                    ; save previous stack pointer
        pushfq                      ; push EFLAGS on stack
        push KGDT64_R0_CODE         ; push CS selector
        lea rax, KiServiceLinkage   ; push service linkage RIP
        push rax                    ; push return address
        mov eax, ServiceNumber      ; set service number
        jmp KiServiceInternal       ; finish in service dispatcher
        push_frame                  ; mark machine frame push

        END_PROLOGUE

    NESTED_END Stub&Name, _TEXT$00

endm
*/

static CHAR StubsEntry[] = {
    0x48, 0x89, 0x4c, 0x24, 0x08,
    0x48, 0x89, 0x54, 0x24, 0x10,
    0x4c, 0x89, 0x44, 0x24, 0x18,
    0x4c, 0x89, 0x4c, 0x24, 0x20,
    0x48, 0x8b, 0xc4,
    0xfa,
    0x48, 0x83, 0xec, 0x10,
    0x50,
    0x9c,
    0x6a, 0x10,
    0x48, 0xb8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    // mov rax, KiServiceLinkage
    0x50,
    0xb8, 0xff, 0xff, 0xff, 0xff,
    // mov eax, KiServiceTableIndex
    0x49, 0xbb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    // mov r11, KiServiceInternal
    0x41, 0xff, 0xe3
    // 0xcc, 0xcc, 0xcc
};

C_ASSERT(sizeof(StubsEntry) == 0x40 - 3);
#endif // !_WIN64

// NotImplemented
static CHAR NotImplemented[] = { 0xb8, 0x02, 0x00, 0x00, 0xc0 };

C_ASSERT(sizeof(NotImplemented) == 5);

NTSTATUS
NTAPI
CopyStub(
    __in_opt PVOID BaseAddress,
    __in_bcount(BufferSize) CONST VOID * Buffer,
    __in SIZE_T BufferSize
)
{
    NTSTATUS Status = STATUS_SUCCESS;
    PHYSICAL_ADDRESS PhysicalAddress = { 0 };
    PVOID VirtualAddress = NULL;

    PhysicalAddress = MmGetPhysicalAddress(BaseAddress);
    VirtualAddress = MmMapIoSpace(PhysicalAddress, BufferSize, MmNonCached);

    if (NULL != VirtualAddress) {
        RtlCopyMemory(VirtualAddress, Buffer, BufferSize);
        MmUnmapIoSpace(VirtualAddress, BufferSize);
    }
    else {
        Status = STATUS_INVALID_ADDRESS;
    }

    return Status;
}

#ifndef _WIN64
static PVOID KiSystemService;

#define AJUST_STUBS_ENTRY32(Stub) \
            (AjustStubEntry32((PKSTUBS_ENTRY)(Stub)))

#define AJUST_STUB_ENTRY(Stub, ServiceNumber) \
            (RtlCopyMemory((PVOID)(Stub), (PVOID)StubsEntry, 8 * sizeof(PVOID)),\
                ((PKSTUBS_ENTRY)(Stub))->u1.KiServiceTableIndex = (ULONG)(ServiceNumber),\
                AJUST_STUBS_ENTRY32(Stub))

VOID
NTAPI
AjustStubEntry32(
    __in PKSTUBS_ENTRY Stub
)
{
    ULONG Offset = 0;

    Offset = (LONG)((PCHAR)KiSystemService -
        &Stub->u2.KiSystemService -
        sizeof(LONG));

    CopyStub(
        &Stub->u2.KiSystemService,
        &Offset,
        sizeof(ULONG));
}
#else
static PVOID KiServiceLinkage;
static PVOID KiServiceInternal;

#define AJUST_STUB_ENTRY(Stub, ServiceNumber) \
            (RtlCopyMemory((PVOID)(Stub), (PVOID)StubsEntry, 8 * sizeof(PVOID)),\
             ((PKSTUBS_ENTRY)(Stub))->u1.KiServiceLinkage = (ULONGLONG)KiServiceLinkage,\
             ((PKSTUBS_ENTRY)(Stub))->u2.KiServiceTableIndex = (ULONG)(ServiceNumber), \
             ((PKSTUBS_ENTRY)(Stub))->u3.KiServiceInternal = (ULONGLONG)KiServiceInternal)
#endif

static const PWSTR NameTable[] = {
    L"AcceptConnectPort",
    L"AccessCheck",
    L"AccessCheckAndAuditAlarm",
    L"AccessCheckByType",
    L"AccessCheckByTypeAndAuditAlarm",
    L"AccessCheckByTypeResultList",
    L"AccessCheckByTypeResultListAndAuditAlarm",
    L"AccessCheckByTypeResultListAndAuditAlarmByHandle",
    L"AcquireCMFViewOwnership",
    L"AcquireProcessActivityReference",
    L"AddAtom",
    L"AddAtomEx",
    L"AddBootEntry",
    L"AddDriverEntry",
    L"AdjustGroupsToken",
    L"AdjustPrivilegesToken",
    L"AdjustTokenClaimsAndDeviceGroups",
    L"AlertResumeThread",
    L"AlertThread",
    L"AlertThreadByThreadId",
    L"AllocateLocallyUniqueId",
    L"AllocateReserveObject",
    L"AllocateUserPhysicalPages",
    L"AllocateUuids",
    L"AllocateVirtualMemory",
    L"AllocateVirtualMemoryEx",
    L"AlpcAcceptConnectPort",
    L"AlpcCancelMessage",
    L"AlpcConnectPort",
    L"AlpcConnectPortEx",
    L"AlpcCreatePort",
    L"AlpcCreatePortSection",
    L"AlpcCreateResourceReserve",
    L"AlpcCreateSectionView",
    L"AlpcCreateSecurityContext",
    L"AlpcDeletePortSection",
    L"AlpcDeleteResourceReserve",
    L"AlpcDeleteSectionView",
    L"AlpcDeleteSecurityContext",
    L"AlpcDisconnectPort",
    L"AlpcImpersonateClientContainerOfPort",
    L"AlpcImpersonateClientOfPort",
    L"AlpcOpenSenderProcess",
    L"AlpcOpenSenderThread",
    L"AlpcQueryInformation",
    L"AlpcQueryInformationMessage",
    L"AlpcRevokeSecurityContext",
    L"AlpcSendWaitReceivePort",
    L"AlpcSetInformation",
    L"ApphelpCacheControl",
    L"AreMappedFilesTheSame",
    L"AssignProcessToJobObject",
    L"AssociateWaitCompletionPacket",
    L"CallEnclave",
    L"CallbackReturn",
    L"CancelDeviceWakeupRequest",
    L"CancelIoFile",
    L"CancelIoFileEx",
    L"CancelSynchronousIoFile",
    L"CancelTimer",
    L"CancelTimer2",
    L"CancelWaitCompletionPacket",
    L"ClearAllSavepointsTransaction",
    L"ClearEvent",
    L"ClearSavepointTransaction",
    L"Close",
    L"CloseObjectAuditAlarm",
    L"CommitComplete",
    L"CommitEnlistment",
    L"CommitRegistryTransaction",
    L"CommitTransaction",
    L"CompactKeys",
    L"CompareObjects",
    L"CompareSigningLevels",
    L"CompareTokens",
    L"CompleteConnectPort",
    L"CompressKey",
    L"ConnectPort",
    L"Continue",
    L"ConvertBetweenAuxiliaryCounterAndPerformanceCounter",
    L"CreateDebugObject",
    L"CreateDirectoryObject",
    L"CreateDirectoryObjectEx",
    L"CreateEnclave",
    L"CreateEnlistment",
    L"CreateEvent",
    L"CreateEventPair",
    L"CreateFile",
    L"CreateIRTimer",
    L"CreateIoCompletion",
    L"CreateJobObject",
    L"CreateJobSet",
    L"CreateKey",
    L"CreateKeyTransacted",
    L"CreateKeyedEvent",
    L"CreateLowBoxToken",
    L"CreateMailslotFile",
    L"CreateMutant",
    L"CreateNamedPipeFile",
    L"CreatePagingFile",
    L"CreatePartition",
    L"CreatePort",
    L"CreatePrivateNamespace",
    L"CreateProcess",
    L"CreateProcessEx",
    L"CreateProfile",
    L"CreateProfileEx",
    L"CreateRegistryTransaction",
    L"CreateResourceManager",
    L"CreateSection",
    L"CreateSemaphore",
    L"CreateSymbolicLinkObject",
    L"CreateThread",
    L"CreateThreadEx",
    L"CreateTimer",
    L"CreateTimer2",
    L"CreateToken",
    L"CreateTokenEx",
    L"CreateTransaction",
    L"CreateTransactionManager",
    L"CreateUserProcess",
    L"CreateWaitCompletionPacket",
    L"CreateWaitablePort",
    L"CreateWnfStateName",
    L"CreateWorkerFactory",
    L"DebugActiveProcess",
    L"DebugContinue",
    L"DelayExecution",
    L"DeleteAtom",
    L"DeleteBootEntry",
    L"DeleteDriverEntry",
    L"DeleteFile",
    L"DeleteKey",
    L"DeleteObjectAuditAlarm",
    L"DeletePrivateNamespace",
    L"DeleteValueKey",
    L"DeleteWnfStateData",
    L"DeleteWnfStateName",
    L"DeviceIoControlFile",
    L"DisableLastKnownGood",
    L"DisplayString",
    L"DrawText",
    L"DuplicateObject",
    L"DuplicateToken",
    L"EnableLastKnownGood",
    L"EnumerateBootEntries",
    L"EnumerateDriverEntries",
    L"EnumerateKey",
    L"EnumerateSystemEnvironmentValuesEx",
    L"EnumerateTransactionObject",
    L"EnumerateValueKey",
    L"ExtendSection",
    L"FilterBootOption",
    L"FilterToken",
    L"FilterTokenEx",
    L"FindAtom",
    L"FlushBuffersFile",
    L"FlushBuffersFileEx",
    L"FlushInstallUILanguage",
    L"FlushInstructionCache",
    L"FlushKey",
    L"FlushProcessWriteBuffers",
    L"FlushVirtualMemory",
    L"FlushWriteBuffer",
    L"FreeUserPhysicalPages",
    L"FreeVirtualMemory",
    L"FreezeRegistry",
    L"FreezeTransactions",
    L"FsControlFile",
    L"GetCachedSigningLevel",
    L"GetCompleteWnfStateSubscription",
    L"GetContextThread",
    L"GetCurrentProcessorNumber",
    L"GetCurrentProcessorNumberEx",
    L"GetDevicePowerState",
    L"GetMUIRegistryInfo",
    L"GetNextProcess",
    L"GetNextThread",
    L"GetNlsSectionPtr",
    L"GetNotificationResourceManager",
    L"GetPlugPlayEvent",
    L"GetWriteWatch",
    L"ImpersonateAnonymousToken",
    L"ImpersonateClientOfPort",
    L"ImpersonateThread",
    L"InitializeEnclave",
    L"InitializeNlsFiles",
    L"InitializeRegistry",
    L"InitiatePowerAction",
    L"IsProcessInJob",
    L"IsSystemResumeAutomatic",
    L"IsUILanguageComitted",
    L"ListTransactions",
    L"ListenPort",
    L"LoadDriver",
    L"LoadEnclaveData",
    L"LoadHotPatch",
    L"LoadKey",
    L"LoadKey2",
    L"LoadKeyEx",
    L"LockFile",
    L"LockProductActivationKeys",
    L"LockRegistryKey",
    L"LockVirtualMemory",
    L"MakePermanentObject",
    L"MakeTemporaryObject",
    L"ManagePartition",
    L"MapCMFModule",
    L"MapUserPhysicalPages",
    L"MapUserPhysicalPagesScatter",
    L"MapViewOfSection",
    L"MapViewOfSectionEx",
    L"MarshallTransaction",
    L"ModifyBootEntry",
    L"ModifyDriverEntry",
    L"NotifyChangeDirectoryFile",
    L"NotifyChangeDirectoryFileEx",
    L"NotifyChangeKey",
    L"NotifyChangeMultipleKeys",
    L"NotifyChangeSession",
    L"OpenDirectoryObject",
    L"OpenEnlistment",
    L"OpenEvent",
    L"OpenEventPair",
    L"OpenFile",
    L"OpenIoCompletion",
    L"OpenJobObject",
    L"OpenKey",
    L"OpenKeyEx",
    L"OpenKeyTransacted",
    L"OpenKeyTransactedEx",
    L"OpenKeyedEvent",
    L"OpenMutant",
    L"OpenObjectAuditAlarm",
    L"OpenPartition",
    L"OpenPrivateNamespace",
    L"OpenProcess",
    L"OpenProcessToken",
    L"OpenProcessTokenEx",
    L"OpenRegistryTransaction",
    L"OpenResourceManager",
    L"OpenSection",
    L"OpenSemaphore",
    L"OpenSession",
    L"OpenSymbolicLinkObject",
    L"OpenThread",
    L"OpenThreadToken",
    L"OpenThreadTokenEx",
    L"OpenTimer",
    L"OpenTransaction",
    L"OpenTransactionManager",
    L"PlugPlayControl",
    L"PowerInformation",
    L"PrePrepareComplete",
    L"PrePrepareEnlistment",
    L"PrepareComplete",
    L"PrepareEnlistment",
    L"PrivilegeCheck",
    L"PrivilegeObjectAuditAlarm",
    L"PrivilegedServiceAuditAlarm",
    L"PropagationComplete",
    L"PropagationFailed",
    L"ProtectVirtualMemory",
    L"PullTransaction",
    L"PulseEvent",
    L"QueryAttributesFile",
    L"QueryAuxiliaryCounterFrequency",
    L"QueryBootEntryOrder",
    L"QueryBootOptions",
    L"QueryDebugFilterState",
    L"QueryDefaultLocale",
    L"QueryDefaultUILanguage",
    L"QueryDirectoryFile",
    L"QueryDirectoryFileEx",
    L"QueryDirectoryObject",
    L"QueryDriverEntryOrder",
    L"QueryEaFile",
    L"QueryEvent",
    L"QueryFullAttributesFile",
    L"QueryInformationAtom",
    L"QueryInformationByName",
    L"QueryInformationEnlistment",
    L"QueryInformationFile",
    L"QueryInformationJobObject",
    L"QueryInformationPort",
    L"QueryInformationProcess",
    L"QueryInformationResourceManager",
    L"QueryInformationThread",
    L"QueryInformationToken",
    L"QueryInformationTransaction",
    L"QueryInformationTransactionManager",
    L"QueryInformationWorkerFactory",
    L"QueryInstallUILanguage",
    L"QueryIntervalProfile",
    L"QueryIoCompletion",
    L"QueryKey",
    L"QueryLicenseValue",
    L"QueryMultipleValueKey",
    L"QueryMutant",
    L"QueryObject",
    L"QueryOpenSubKeys",
    L"QueryOpenSubKeysEx",
    L"QueryPerformanceCounter",
    L"QueryPortInformationProcess",
    L"QueryQuotaInformationFile",
    L"QuerySection",
    L"QuerySecurityAttributesToken",
    L"QuerySecurityObject",
    L"QuerySecurityPolicy",
    L"QuerySemaphore",
    L"QuerySymbolicLinkObject",
    L"QuerySystemEnvironmentValue",
    L"QuerySystemEnvironmentValueEx",
    L"QuerySystemInformation",
    L"QuerySystemInformationEx",
    L"QuerySystemTime",
    L"QueryTimer",
    L"QueryTimerResolution",
    L"QueryValueKey",
    L"QueryVirtualMemory",
    L"QueryVolumeInformationFile",
    L"QueryWnfStateData",
    L"QueryWnfStateNameInformation",
    L"QueueApcThread",
    L"QueueApcThreadEx",
    L"RaiseException",
    L"RaiseHardError",
    L"ReadFile",
    L"ReadFileScatter",
    L"ReadOnlyEnlistment",
    L"ReadRequestData",
    L"ReadVirtualMemory",
    L"RecoverEnlistment",
    L"RecoverResourceManager",
    L"RecoverTransactionManager",
    L"RegisterProtocolAddressInformation",
    L"RegisterThreadTerminatePort",
    L"ReleaseCMFViewOwnership",
    L"ReleaseKeyedEvent",
    L"ReleaseMutant",
    L"ReleaseSemaphore",
    L"ReleaseWorkerFactoryWorker",
    L"RemoveIoCompletion",
    L"RemoveIoCompletionEx",
    L"RemoveProcessDebug",
    L"RenameKey",
    L"RenameTransactionManager",
    L"ReplaceKey",
    L"ReplacePartitionUnit",
    L"ReplyPort",
    L"ReplyWaitReceivePort",
    L"ReplyWaitReceivePortEx",
    L"ReplyWaitReplyPort",
    L"RequestDeviceWakeup",
    L"RequestPort",
    L"RequestWaitReplyPort",
    L"RequestWakeupLatency",
    L"ResetEvent",
    L"ResetWriteWatch",
    L"RestoreKey",
    L"ResumeProcess",
    L"ResumeThread",
    L"RevertContainerImpersonation",
    L"RollbackComplete",
    L"RollbackEnlistment",
    L"RollbackRegistryTransaction",
    L"RollbackSavepointTransaction",
    L"RollbackTransaction",
    L"RollforwardTransactionManager",
    L"SaveKey",
    L"SaveKeyEx",
    L"SaveMergedKeys",
    L"SavepointComplete",
    L"SavepointTransaction",
    L"SecureConnectPort",
    L"SerializeBoot",
    L"SetBootEntryOrder",
    L"SetBootOptions",
    L"SetCachedSigningLevel",
    L"SetCachedSigningLevel2",
    L"SetContextThread",
    L"SetDebugFilterState",
    L"SetDefaultHardErrorPort",
    L"SetDefaultLocale",
    L"SetDefaultUILanguage",
    L"SetDriverEntryOrder",
    L"SetEaFile",
    L"SetEvent",
    L"SetEventBoostPriority",
    L"SetHighEventPair",
    L"SetHighWaitLowEventPair",
    L"SetIRTimer",
    L"SetInformationDebugObject",
    L"SetInformationEnlistment",
    L"SetInformationFile",
    L"SetInformationJobObject",
    L"SetInformationKey",
    L"SetInformationObject",
    L"SetInformationProcess",
    L"SetInformationResourceManager",
    L"SetInformationSymbolicLink",
    L"SetInformationThread",
    L"SetInformationToken",
    L"SetInformationTransaction",
    L"SetInformationTransactionManager",
    L"SetInformationVirtualMemory",
    L"SetInformationWorkerFactory",
    L"SetIntervalProfile",
    L"SetIoCompletion",
    L"SetIoCompletionEx",
    L"SetLdtEntries",
    L"SetLowEventPair",
    L"SetLowWaitHighEventPair",
    L"SetQuotaInformationFile",
    L"SetSecurityObject",
    L"SetSystemEnvironmentValue",
    L"SetSystemEnvironmentValueEx",
    L"SetSystemInformation",
    L"SetSystemPowerState",
    L"SetSystemTime",
    L"SetThreadExecutionState",
    L"SetTimer",
    L"SetTimer2",
    L"SetTimerEx",
    L"SetTimerResolution",
    L"SetUuidSeed",
    L"SetValueKey",
    L"SetVolumeInformationFile",
    L"SetWnfProcessNotificationEvent",
    L"ShutdownSystem",
    L"ShutdownWorkerFactory",
    L"SignalAndWaitForSingleObject",
    L"SinglePhaseReject",
    L"StartProfile",
    L"StartTm",
    L"StopProfile",
    L"SubscribeWnfStateChange",
    L"SuspendProcess",
    L"SuspendThread",
    L"SystemDebugControl",
    L"TerminateEnclave",
    L"TerminateJobObject",
    L"TerminateProcess",
    L"TerminateThread",
    L"TestAlert",
    L"ThawRegistry",
    L"ThawTransactions",
    L"TraceControl",
    L"TraceEvent",
    L"TranslateFilePath",
    L"UmsThreadYield",
    L"UnloadDriver",
    L"UnloadKey",
    L"UnloadKey2",
    L"UnloadKeyEx",
    L"UnlockFile",
    L"UnlockVirtualMemory",
    L"UnmapViewOfSection",
    L"UnmapViewOfSectionEx",
    L"UnsubscribeWnfStateChange",
    L"UpdateWnfStateData",
    L"VdmControl",
    L"WaitForAlertByThreadId",
    L"WaitForDebugEvent",
    L"WaitForKeyedEvent",
    L"WaitForMultipleObjects",
    L"WaitForMultipleObjects32",
    L"WaitForSingleObject",
    L"WaitForWnfNotifications",
    L"WaitForWorkViaWorkerFactory",
    L"WaitHighEventPair",
    L"WaitLowEventPair",
    L"WorkerFactoryWorkerReady",
    L"WriteFile",
    L"WriteFileGather",
    L"WriteRequestData",
    L"WriteVirtualMemory",
    L"YieldExecution"
};

static const SHORT NumberTable[][20] = {
    { 0,96,0,96,428,97,1,1,2,2,2,2,2,2,2,2,2,2,2,2 },
    { 1,97,1,97,427,98,432,98,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 2,38,2,38,426,39,431,40,439,41,442,41,444,41,450,41,454,41,454,41 },
    { 3,98,3,98,425,99,430,99,438,99,441,99,443,99,449,99,453,99,453,99 },
    { 4,86,4,86,424,87,429,88,437,89,440,89,442,89,448,89,452,89,452,89 },
    { 5,99,5,99,423,100,428,100,436,100,439,100,441,100,447,100,451,100,451,100 },
    { 6,100,6,100,422,101,427,101,435,101,438,101,440,101,446,101,450,101,450,101 },
    { 7,101,7,101,421,102,426,102,434,102,437,102,439,102,445,102,449,102,449,102 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,444,103,448,103,448,103 },
    { 8,68,8,68,419,69,424,70,432,71,435,71,437,71,442,71,446,71,446,71 },
    { -1,-1,-1,-1,420,103,425,103,433,103,436,103,438,103,443,104,447,104,447,104 },
    { 9,102,9,102,418,104,423,104,431,104,434,104,436,104,441,105,445,105,445,105 },
    { 10,103,10,103,417,105,422,105,430,105,433,105,435,105,440,106,444,106,444,106 },
    { 11,104,11,104,415,106,420,106,428,106,431,106,433,106,438,107,442,107,442,107 },
    { 12,62,12,62,414,63,419,64,427,65,430,65,432,65,437,65,441,65,441,65 },
    { -1,-1,-1,-1,416,107,421,107,429,107,432,107,434,107,439,108,443,108,443,108 },
    { 13,105,13,105,413,108,418,108,426,108,429,108,431,108,436,109,440,109,440,109 },
    { 14,106,14,106,412,109,417,109,425,109,428,109,430,109,435,110,439,110,439,110 },
    { -1,-1,-1,-1,411,110,416,110,424,110,427,110,429,110,434,111,438,111,438,111 },
    { 15,107,15,107,410,111,415,111,423,111,426,111,428,111,433,112,437,112,437,112 },
    { 16,108,16,108,409,112,414,112,422,112,425,112,427,112,432,113,436,113,436,113 },
    { 17,109,17,109,408,113,413,113,421,113,424,113,426,113,431,114,435,114,435,114 },
    { 18,110,18,110,407,114,412,114,420,114,423,114,425,114,430,115,434,115,434,115 },
    { 19,21,19,21,406,22,411,23,419,24,422,24,424,24,429,24,433,24,433,24 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,460,116 },
    { 20,111,20,111,405,115,410,115,418,115,421,115,423,115,428,116,432,116,432,117 },
    { 21,112,21,112,404,116,409,116,417,116,420,116,422,116,427,117,431,117,431,118 },
    { 22,113,22,113,402,117,407,117,415,117,418,117,420,117,425,118,429,118,429,119 },
    { -1,-1,-1,-1,403,118,408,118,416,118,419,118,421,118,426,119,430,119,430,120 },
    { 23,114,23,114,401,119,406,119,414,119,417,119,419,119,424,120,428,120,428,121 },
    { 24,115,24,115,400,120,405,120,413,120,416,120,418,120,423,121,427,121,427,122 },
    { 25,116,25,116,399,121,404,121,412,121,415,121,417,121,422,122,426,122,426,123 },
    { 26,117,26,117,398,122,403,122,411,122,414,122,416,122,421,123,425,123,425,124 },
    { 27,118,27,118,397,123,402,123,410,123,413,123,415,123,420,124,424,124,424,125 },
    { 28,119,28,119,396,124,401,124,409,124,412,124,414,124,419,125,423,125,423,126 },
    { 29,120,29,120,395,125,400,125,408,125,411,125,413,125,418,126,422,126,422,127 },
    { 30,121,30,121,394,126,399,126,407,126,410,126,412,126,417,127,421,127,421,128 },
    { 31,122,31,122,393,127,398,127,406,127,409,127,411,127,416,128,420,128,420,129 },
    { 32,123,32,123,392,128,397,128,405,128,408,128,410,128,415,129,419,129,419,130 },
    { -1,-1,-1,-1,-1,-1,-1,-1,404,129,407,129,409,129,414,130,418,130,418,131 },
    { 33,124,33,124,391,129,396,129,403,130,406,130,408,130,413,131,417,131,417,132 },
    { 34,125,34,125,390,130,395,130,402,131,405,131,407,131,412,132,416,132,416,133 },
    { 35,126,35,126,389,131,394,131,401,132,404,132,406,132,411,133,415,133,415,134 },
    { 36,127,36,127,388,132,393,132,400,133,403,133,405,133,410,134,414,134,414,135 },
    { 37,128,37,128,387,133,392,133,399,134,402,134,404,134,409,135,413,135,413,136 },
    { 38,129,38,129,386,134,391,134,398,135,401,135,403,135,408,136,412,136,412,137 },
    { 39,130,39,130,385,135,390,135,397,136,400,136,402,136,407,137,411,137,411,138 },
    { 40,131,40,131,384,136,389,136,396,137,399,137,401,137,406,138,410,138,410,139 },
    { 41,73,41,73,383,74,388,75,395,76,398,76,400,76,405,76,409,76,409,76 },
    { 42,132,42,132,382,137,387,137,394,138,397,138,399,138,404,139,408,139,408,140 },
    { 43,133,43,133,381,138,386,138,393,139,396,139,398,139,403,140,407,140,407,141 },
    { -1,-1,-1,-1,380,139,385,139,392,140,395,140,397,140,402,141,406,141,406,142 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,404,142,404,143 },
    { 44,2,44,2,379,3,384,4,391,5,394,5,396,5,401,5,405,5,405,5 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 45,90,45,90,378,91,383,92,390,93,393,93,395,93,400,93,403,93,403,93 },
    { 46,134,46,134,377,140,382,140,389,141,392,141,394,141,399,142,402,143,402,144 },
    { 47,135,47,135,376,141,381,141,388,142,391,142,393,142,398,143,401,144,401,145 },
    { 48,94,48,94,375,95,380,96,387,97,390,97,392,97,397,97,400,97,400,97 },
    { -1,-1,-1,-1,-1,-1,67,142,68,143,68,143,68,143,68,144,69,145,69,146 },
    { -1,-1,-1,-1,374,142,379,143,386,144,389,144,391,144,396,145,399,146,399,147 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 49,59,49,59,373,60,378,61,385,62,388,62,390,62,395,62,398,62,398,62 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 50,12,50,12,372,13,377,14,384,15,387,15,389,15,394,15,397,15,397,15 },
    { 51,56,51,56,371,57,376,58,383,59,386,59,388,59,393,59,396,59,396,59 },
    { 52,136,52,136,370,143,375,144,382,145,385,145,387,145,392,146,395,147,395,148 },
    { 53,137,53,137,369,144,374,145,381,146,384,146,386,146,391,147,394,148,394,149 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,448,147,454,148,458,149,458,150 },
    { 54,138,54,138,368,145,373,146,380,147,383,147,385,148,390,149,393,150,393,151 },
    { 55,139,55,139,367,146,372,147,379,148,382,148,384,149,389,150,392,151,392,152 },
    { -1,-1,-1,-1,-1,-1,-1,-1,378,149,381,149,383,150,388,151,391,152,391,153 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,387,152,390,153,390,154 },
    { 56,140,56,140,366,147,371,148,377,150,380,150,382,151,386,153,389,154,389,155 },
    { 57,141,57,141,365,148,370,149,376,151,379,151,381,152,385,154,388,155,388,156 },
    { 58,142,58,142,364,149,369,150,375,152,378,152,380,153,384,155,387,156,387,157 },
    { 59,143,59,143,363,150,368,151,374,153,377,153,379,154,383,156,386,157,386,158 },
    { 60,64,60,64,362,65,367,66,373,67,376,67,378,67,382,67,385,67,385,67 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,381,157,384,158,384,159 },
    { 61,144,61,144,361,151,366,152,372,154,375,154,377,155,380,158,383,159,383,160 },
    { 62,145,62,145,360,152,365,153,371,155,374,155,376,156,379,159,382,160,382,161 },
    { -1,-1,-1,-1,359,153,364,154,370,156,373,156,375,157,378,160,381,161,381,162 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,372,157,374,158,377,161,380,162,380,163 },
    { 63,146,63,146,358,154,363,155,369,157,371,158,373,159,376,162,379,163,379,164 },
    { 64,69,64,69,357,70,362,71,368,72,370,72,372,72,375,72,378,72,378,72 },
    { 65,147,65,147,356,155,361,156,367,158,369,159,371,160,374,163,377,164,377,165 },
    { 66,82,66,82,355,83,360,84,366,85,368,85,370,85,373,85,376,85,376,85 },
    { -1,-1,-1,-1,353,156,357,157,363,159,365,160,367,161,370,164,373,165,373,166 },
    { 67,148,67,148,354,157,359,158,365,160,367,161,369,162,372,165,375,166,375,167 },
    { 68,149,68,149,352,158,356,159,362,161,364,162,366,163,369,166,372,167,372,168 },
    { 69,150,69,150,351,159,355,160,361,162,363,163,365,164,368,167,371,168,371,169 },
    { 70,26,70,26,350,27,354,28,360,29,362,29,364,29,367,29,370,29,370,29 },
    { 72,151,72,151,348,160,352,161,358,163,360,164,362,165,365,168,368,169,368,170 },
    { 71,152,71,152,349,161,353,162,359,164,361,165,363,166,366,169,369,170,369,171 },
    { -1,-1,-1,-1,329,162,333,163,339,165,341,166,343,167,346,170,349,171,349,172 },
    { 73,153,73,153,347,163,351,164,357,166,359,167,361,168,364,171,367,172,367,173 },
    { 74,154,74,154,346,164,350,165,356,167,358,168,360,169,363,172,366,173,366,174 },
    { 75,155,75,155,345,165,349,166,355,168,357,169,359,170,362,173,365,174,365,175 },
    { 76,156,76,156,344,166,348,167,354,169,356,170,358,171,361,174,364,175,364,176 },
    { -1,-1,-1,-1,-1,-1,-1,-1,330,170,332,171,334,172,337,175,340,176,340,177 },
    { 77,157,77,157,343,167,347,168,353,171,355,172,357,173,360,176,363,177,363,178 },
    { 78,158,78,158,342,168,346,169,352,172,354,173,356,174,359,177,362,178,362,179 },
    { 79,159,79,159,341,169,345,170,351,173,353,174,355,175,358,178,361,179,361,180 },
    { 80,74,80,74,340,75,344,76,350,77,352,77,354,77,357,77,360,77,360,77 },
    { 81,160,81,160,339,170,343,171,349,174,351,175,353,176,356,179,359,180,359,181 },
    { 82,161,82,161,338,171,342,172,348,175,350,176,352,177,355,180,358,181,358,182 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,446,178,452,181,456,182,456,183 },
    { 83,162,83,162,337,172,341,173,347,176,349,177,351,179,354,182,357,183,357,184 },
    { 84,71,84,71,336,72,340,73,346,74,348,74,350,74,353,74,356,74,356,74 },
    { 85,163,85,163,335,173,339,174,345,177,347,178,349,180,352,183,355,184,355,185 },
    { 86,164,86,164,334,174,338,175,344,178,346,179,348,181,351,184,354,185,354,186 },
    { 87,75,87,75,333,76,337,77,343,78,345,78,347,78,350,78,353,78,353,78 },
    { 88,165,88,165,332,175,336,176,342,179,344,180,346,182,349,185,352,186,352,187 },
    { 89,166,89,166,331,176,335,177,341,180,343,181,345,183,348,186,351,187,351,188 },
    { -1,-1,-1,-1,-1,-1,358,178,364,181,366,182,368,184,371,187,374,188,374,189 },
    { 90,167,90,167,328,177,332,179,338,182,340,183,342,185,345,188,348,189,348,190 },
    { -1,-1,-1,-1,330,178,334,180,340,183,342,184,344,186,347,189,350,190,350,191 },
    { 91,168,91,168,327,179,331,181,337,184,339,185,341,187,344,190,347,191,347,192 },
    { 92,169,92,169,326,180,330,182,336,185,338,186,340,188,343,191,346,192,346,193 },
    { 93,170,93,170,325,181,329,183,335,186,337,187,339,189,342,192,345,193,345,194 },
    { -1,-1,-1,-1,323,182,327,184,333,187,335,188,337,190,340,193,343,194,343,195 },
    { 94,171,94,171,324,183,328,185,334,188,336,189,338,191,341,194,344,195,344,196 },
    { -1,-1,-1,-1,322,184,326,186,332,189,334,190,336,192,339,195,342,196,342,197 },
    { 95,172,95,172,321,185,325,187,331,190,333,191,335,193,338,196,341,197,341,198 },
    { 96,173,96,173,320,186,324,188,329,191,331,192,333,194,336,197,339,198,339,199 },
    { 97,174,97,174,319,187,323,189,328,192,330,193,332,195,335,198,338,199,338,200 },
    { 98,49,98,49,318,50,322,51,327,52,329,52,331,52,334,52,337,52,337,52 },
    { 99,175,99,175,317,188,321,190,326,193,328,194,330,196,333,199,336,200,336,201 },
    { 100,176,100,176,316,189,320,191,325,194,327,195,329,197,332,200,335,201,335,202 },
    { 101,177,101,177,315,190,319,192,324,195,326,196,328,198,331,201,334,202,334,203 },
    { 102,178,102,178,314,191,318,193,323,196,325,197,327,199,330,202,333,203,333,204 },
    { 103,179,103,179,313,192,317,194,322,197,324,198,326,200,329,203,332,204,332,205 },
    { 104,180,104,180,312,193,316,195,321,198,323,199,325,201,328,204,331,205,331,206 },
    { 105,181,105,181,311,194,315,196,320,199,322,200,324,202,327,205,330,206,330,207 },
    { 106,182,106,182,310,195,314,197,319,200,321,201,323,203,326,206,329,207,329,208 },
    { -1,-1,-1,-1,309,196,313,198,318,201,320,202,322,204,325,207,328,208,328,209 },
    { -1,-1,-1,-1,308,197,312,199,317,202,319,203,321,205,324,208,327,209,327,210 },
    { 107,4,107,4,307,5,311,6,316,7,318,7,320,7,323,7,326,7,326,7 },
    { 108,183,108,183,306,198,310,200,315,203,317,204,319,206,322,209,325,210,325,211 },
    { 109,184,109,184,305,199,309,201,314,204,316,205,318,207,321,210,324,211,324,212 },
    { 110,185,110,185,304,200,308,202,313,205,315,206,317,208,320,211,323,212,323,213 },
    { 111,57,111,57,303,58,307,59,312,60,314,60,316,60,319,60,322,60,322,60 },
    { 112,63,112,63,302,64,306,65,311,66,313,66,315,66,318,66,321,66,321,66 },
    { 113,186,113,186,301,201,305,203,310,206,312,207,314,209,317,212,320,213,320,214 },
    { 114,187,114,187,300,202,304,204,309,207,311,208,313,210,316,213,319,214,319,215 },
    { 115,188,115,188,299,203,303,205,308,208,310,209,312,211,315,214,318,215,318,216 },
    { 116,47,116,47,298,48,302,49,307,50,309,50,311,50,314,50,317,50,317,50 },
    { 117,189,117,189,297,204,301,206,306,209,308,210,310,212,313,215,316,216,316,217 },
    { 118,190,118,190,296,205,300,207,305,210,307,211,309,213,312,216,315,217,315,218 },
    { 119,16,119,16,295,17,299,18,304,19,306,19,308,19,311,19,314,19,314,19 },
    { 120,191,120,191,294,206,298,208,303,211,305,212,307,214,310,217,313,218,313,219 },
    { -1,-1,-1,-1,293,207,297,209,302,212,304,213,306,215,309,218,312,219,312,220 },
    { 121,192,121,192,291,208,295,210,300,213,302,214,304,216,307,219,310,220,310,221 },
    { -1,-1,-1,-1,292,209,296,211,301,214,303,215,305,217,308,220,311,221,311,222 },
    { 122,17,122,17,290,18,294,19,299,20,301,20,303,20,306,20,309,20,309,20 },
    { 123,72,123,72,288,73,292,74,297,75,299,75,301,75,304,75,307,75,307,75 },
    { -1,-1,-1,-1,289,210,293,212,298,215,300,216,302,218,305,221,308,222,308,223 },
    { 124,193,124,193,287,211,291,213,296,216,298,217,300,219,303,222,306,223,306,224 },
    { 125,194,125,194,286,212,290,214,295,217,297,218,299,220,302,223,305,224,305,225 },
    { 126,195,126,195,285,213,289,215,294,218,296,219,298,221,301,224,304,225,304,226 },
    { 127,196,127,196,284,214,288,216,293,219,295,220,297,222,300,225,303,226,303,227 },
    { 128,197,128,197,283,215,287,217,292,220,294,221,296,223,299,226,302,227,302,228 },
    { 129,198,129,198,282,216,286,218,291,221,293,222,295,224,298,227,301,228,301,229 },
    { 130,199,130,199,281,217,285,219,290,222,292,223,294,225,297,228,300,229,300,230 },
    { 131,27,131,27,280,28,284,29,289,30,291,30,293,30,296,30,299,30,299,30 },
    { 132,200,132,200,279,218,283,220,288,223,290,224,292,226,295,229,298,230,298,231 },
    { 133,201,133,201,278,219,282,221,287,224,289,225,291,227,294,230,297,231,297,232 },
    { 134,54,134,54,277,55,281,56,286,57,288,57,290,57,293,57,296,57,296,57 },
    { -1,-1,-1,-1,276,220,280,222,285,225,287,226,289,228,292,231,295,232,295,233 },
    { -1,-1,-1,-1,-1,-1,279,223,284,226,286,227,288,229,291,232,294,233,294,234 },
    { 135,202,135,202,275,221,278,224,283,227,285,228,287,230,290,233,293,234,293,235 },
    { 136,203,136,203,274,222,277,225,282,228,284,229,286,231,289,234,292,235,292,236 },
    { -1,-1,-1,-1,-1,-1,-1,-1,281,229,283,230,285,232,288,235,291,236,291,237 },
    { 137,204,137,204,273,223,276,226,280,230,282,231,284,233,287,236,290,237,290,238 },
    { 138,205,138,205,272,224,275,227,279,231,281,232,283,234,286,237,289,238,289,239 },
    { 139,206,139,206,271,225,274,228,278,232,280,233,282,235,285,238,288,239,288,240 },
    { 140,207,140,207,270,226,273,229,277,233,279,234,281,236,284,239,287,240,287,241 },
    { 141,208,141,208,269,227,272,230,276,234,278,235,280,237,283,240,286,241,286,242 },
    { 142,209,142,209,268,228,271,231,275,235,277,236,279,238,282,241,285,242,285,243 },
    { 143,210,143,210,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 144,211,144,211,267,229,270,232,274,236,276,237,278,239,281,242,284,243,284,244 },
    { 145,212,145,212,266,230,269,233,273,237,275,238,277,240,280,243,283,244,283,245 },
    { 146,28,146,28,265,29,268,30,272,31,274,31,276,31,279,31,282,31,282,31 },
    { 147,213,147,213,264,231,267,234,271,238,273,239,275,241,278,244,281,245,281,246 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,272,240,274,242,277,245,280,246,280,247 },
    { 148,214,148,214,263,232,266,235,270,239,271,241,273,243,276,246,279,247,279,248 },
    { 149,215,149,215,262,233,265,236,269,240,270,242,272,244,275,247,278,248,278,249 },
    { 150,216,150,216,261,234,264,237,268,241,269,243,271,245,274,248,277,249,277,250 },
    { 151,76,151,76,260,77,263,78,267,79,268,79,270,79,273,79,276,79,276,79 },
    { 152,217,152,217,259,235,262,238,266,242,267,244,269,246,272,249,275,250,275,251 },
    { 153,218,153,218,258,236,261,239,265,243,266,245,268,247,271,250,274,251,274,252 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 154,219,154,219,257,237,260,240,264,244,265,246,267,248,270,251,273,252,273,253 },
    { 155,220,155,220,256,238,259,241,263,245,264,247,266,249,269,252,272,253,272,254 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,263,248,265,250,268,253,271,254,271,255 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,267,254,270,255,270,256 },
    { 156,221,156,221,255,239,258,242,262,246,262,249,264,251,266,255,269,256,269,257 },
    { 157,222,157,222,254,240,257,243,261,247,261,250,263,252,265,256,268,257,268,258 },
    { 158,223,158,223,253,241,256,244,260,248,260,251,262,253,264,257,267,258,267,259 },
    { 159,224,159,224,252,242,255,245,259,249,259,252,261,254,263,258,266,259,266,260 },
    { 160,225,160,225,251,243,254,246,258,250,258,253,260,255,262,259,265,260,265,261 },
    { 161,226,161,226,250,244,253,247,257,251,257,254,259,256,261,260,264,261,264,262 },
    { 162,227,162,227,249,245,252,248,256,252,256,255,258,257,260,261,263,262,263,263 },
    { 163,228,163,228,248,246,251,249,255,253,255,256,257,258,259,262,262,263,262,264 },
    { 164,229,164,229,247,247,250,250,254,254,254,257,256,259,258,263,261,264,261,265 },
    { -1,-1,-1,-1,-1,-1,-1,-1,247,255,247,258,249,260,251,264,254,265,254,266 },
    { 165,230,165,230,246,248,249,251,253,256,253,259,255,261,257,265,260,266,260,267 },
    { 166,231,166,231,245,249,248,252,252,257,252,260,254,262,256,266,259,267,259,268 },
    { 167,0,167,0,244,1,247,2,251,3,251,3,253,3,255,3,258,3,258,3 },
    { 168,37,168,37,243,38,246,39,250,40,250,40,252,40,254,40,257,40,257,40 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,461,269 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 169,232,169,232,242,250,245,253,249,258,249,261,251,263,253,267,256,268,256,270 },
    { 170,233,170,233,241,251,244,254,248,259,248,262,250,264,252,268,255,269,255,271 },
    { 171,234,171,234,240,252,243,255,246,260,246,263,248,265,250,269,252,270,252,272 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,253,271,253,273 },
    { 172,235,172,235,239,253,242,256,245,261,245,264,247,266,249,270,251,272,251,274 },
    { 173,236,173,236,238,254,241,257,244,262,244,265,246,267,248,271,250,273,250,275 },
    { 174,237,174,237,237,255,240,258,243,263,243,266,245,268,247,272,249,274,249,276 },
    { 175,85,175,85,236,86,239,87,242,88,242,88,244,88,246,88,248,88,248,88 },
    { 176,238,176,238,235,256,238,259,241,264,241,267,243,269,245,273,247,275,247,277 },
    { 177,61,177,61,234,62,237,63,240,64,240,64,242,64,244,64,246,64,246,64 },
    { 178,239,178,239,233,257,236,260,239,265,239,268,241,270,243,274,245,276,245,278 },
    { 179,48,179,48,232,49,235,50,238,51,238,51,240,51,242,51,244,51,244,51 },
    { 180,240,180,240,231,258,234,261,237,266,237,269,239,271,241,275,243,277,243,279 },
    { 181,241,181,241,230,259,233,262,236,267,236,270,238,272,240,276,242,278,242,280 },
    { 182,15,182,15,229,16,232,17,235,18,235,18,237,18,239,18,241,18,241,18 },
    { 183,242,183,242,227,260,230,263,233,268,233,271,235,273,237,277,239,279,239,281 },
    { 185,243,185,243,226,261,229,264,232,269,232,272,234,274,236,278,238,280,238,282 },
    { 186,244,186,244,225,262,228,265,231,270,231,273,233,275,235,279,237,281,237,283 },
    { 184,245,184,245,228,263,231,266,234,271,234,274,236,276,238,280,240,282,240,284 },
    { 187,246,187,246,224,264,227,267,230,272,230,275,232,277,234,281,236,283,236,285 },
    { 188,247,188,247,223,265,226,268,229,273,229,276,231,278,233,282,235,284,235,286 },
    { -1,-1,-1,-1,-1,-1,-1,-1,224,274,224,277,226,279,228,283,230,285,230,287 },
    { 189,248,189,248,222,266,225,269,228,275,228,278,230,280,232,284,234,286,234,288 },
    { 190,35,190,35,221,36,224,37,227,38,227,38,229,38,231,38,233,38,233,38 },
    { 191,249,191,249,220,267,223,270,226,276,226,279,228,281,230,285,232,287,232,289 },
    { 192,45,192,45,219,46,222,47,225,48,225,48,227,48,229,48,231,48,231,48 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,447,282,453,286,457,288,457,290 },
    { 193,250,193,250,218,268,221,271,223,277,223,280,225,283,227,287,229,289,229,291 },
    { 194,52,194,52,217,53,220,54,222,55,222,55,224,55,226,55,228,55,228,55 },
    { 195,251,195,251,216,269,219,272,221,278,221,281,223,284,225,288,227,290,227,292 },
    { 196,252,196,252,215,270,218,273,220,279,220,282,222,285,224,289,226,291,226,293 },
    { 197,253,197,253,214,271,217,274,219,280,219,283,221,286,223,290,225,292,225,294 },
    { 198,254,198,254,213,272,216,275,218,281,218,284,220,287,222,291,224,293,224,295 },
    { 199,33,199,33,212,34,215,35,217,36,217,36,219,36,221,36,223,36,223,36 },
    { 200,44,200,44,211,45,214,46,216,47,216,47,218,47,220,47,222,47,222,47 },
    { 201,255,201,255,210,273,213,276,215,282,215,285,217,288,219,292,221,294,221,296 },
    { 202,256,202,256,209,274,212,277,214,283,214,286,216,289,218,293,220,295,220,297 },
    { 203,257,203,257,208,275,211,278,213,284,213,287,215,290,217,294,219,296,219,298 },
    { 204,258,204,258,207,276,210,279,212,285,212,288,214,291,216,295,218,297,218,299 },
    { 205,92,205,92,206,93,209,94,211,95,211,95,213,95,215,95,217,95,217,95 },
    { 208,259,208,259,203,277,206,280,208,286,208,289,210,292,212,296,214,298,214,300 },
    { 209,260,209,260,202,278,205,281,207,287,207,290,209,293,211,297,213,299,213,301 },
    { 206,261,206,261,205,279,208,282,210,288,210,291,212,294,214,298,216,300,216,302 },
    { 207,262,207,262,204,280,207,283,209,289,209,292,211,295,213,299,215,301,215,303 },
    { 210,263,210,263,200,281,203,284,205,290,205,293,207,296,209,300,211,302,211,304 },
    { 212,264,212,264,198,282,201,285,203,291,203,294,205,297,207,301,209,303,209,305 },
    { 211,265,211,265,199,283,202,286,204,292,204,295,206,298,208,302,210,304,210,306 },
    { 213,266,213,266,197,284,200,287,202,293,202,296,204,299,206,303,208,305,208,307 },
    { 214,267,214,267,196,285,199,288,201,294,201,297,203,300,205,304,207,306,207,308 },
    { 215,77,215,77,195,78,198,79,200,80,200,80,202,80,204,80,206,80,206,80 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 216,268,216,268,194,286,197,289,199,295,199,298,201,301,203,305,205,307,205,309 },
    { 217,58,217,58,193,59,196,60,198,61,198,61,200,61,202,61,204,61,204,61 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,146,306,147,308,147,310 },
    { 218,269,218,269,192,287,195,290,197,296,197,299,199,302,201,307,203,309,203,311 },
    { 219,270,219,270,191,288,194,291,196,297,196,300,198,303,200,308,202,310,202,312 },
    { 220,271,220,271,190,289,193,292,195,298,195,301,197,304,199,309,201,311,201,313 },
    { 221,18,221,18,189,19,192,20,194,21,194,21,196,21,198,21,200,21,200,21 },
    { 222,65,222,65,188,66,191,67,193,68,193,68,195,68,197,68,199,68,199,68 },
    { 223,50,223,50,187,51,190,52,192,53,192,53,194,53,196,53,197,53,197,53 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,198,312,198,314 },
    { 224,272,224,272,186,290,189,293,191,299,191,302,193,305,195,310,196,313,196,315 },
    { 225,273,225,273,185,291,188,294,190,300,190,303,192,306,194,311,195,314,195,316 },
    { 226,274,226,274,184,292,187,295,189,301,189,304,191,307,193,312,194,315,194,317 },
    { 227,83,227,83,183,84,186,85,188,86,188,86,190,86,192,86,193,86,193,86 },
    { 228,275,228,275,182,293,185,296,187,302,187,305,189,308,191,313,192,316,192,318 },
    { 229,276,229,276,181,294,184,297,186,303,186,306,188,309,190,314,191,317,191,319 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,189,315,190,318,190,320 },
    { 230,277,230,277,180,295,183,298,185,304,185,307,187,310,188,316,189,319,189,321 },
    { 231,14,231,14,179,15,182,16,184,17,184,17,186,17,187,17,188,17,188,17 },
    { 232,278,232,278,178,296,181,299,183,305,183,308,185,311,186,317,187,320,187,322 },
    { 233,279,233,279,177,297,180,300,182,306,182,309,184,312,185,318,186,321,186,323 },
    { 234,22,234,22,176,23,179,24,181,25,181,25,183,25,184,25,185,25,185,25 },
    { 235,280,235,280,175,298,178,301,180,307,180,310,182,313,183,319,184,322,184,324 },
    { 236,34,236,34,174,35,177,36,179,37,179,37,181,37,182,37,183,37,183,37 },
    { 237,30,237,30,173,31,176,32,178,33,178,33,180,33,181,33,182,33,182,33 },
    { 238,281,238,281,172,299,175,302,177,308,177,311,179,314,180,320,181,323,181,325 },
    { 239,282,239,282,171,300,174,303,176,309,176,312,178,315,179,321,180,324,180,326 },
    { 240,283,240,283,170,301,173,304,175,310,175,313,177,316,178,322,179,325,179,327 },
    { 241,284,241,284,169,302,172,305,174,311,174,314,176,317,177,323,178,326,178,328 },
    { 242,285,242,285,168,303,171,306,173,312,173,315,175,318,176,324,177,327,177,329 },
    { 243,286,243,286,167,304,170,307,172,313,172,316,174,319,175,325,176,328,176,330 },
    { 244,19,244,19,166,20,169,21,171,22,171,22,173,22,174,22,175,22,175,22 },
    { 245,287,245,287,165,305,168,308,170,314,170,317,172,320,173,326,174,329,174,331 },
    { 246,288,246,288,164,306,167,309,169,315,169,318,171,321,172,327,173,330,173,332 },
    { 247,289,247,289,163,307,166,310,168,316,168,319,170,322,171,328,172,331,172,333 },
    { 248,13,248,13,162,14,165,15,167,16,167,16,169,16,170,16,171,16,171,16 },
    { 249,290,249,290,161,308,164,311,166,317,166,320,168,323,169,329,170,332,170,334 },
    { 250,291,250,291,160,309,163,312,165,318,165,321,167,324,168,330,169,333,169,335 },
    { 251,46,251,46,159,47,162,48,164,49,164,49,166,49,167,49,168,49,168,49 },
    { 252,292,252,292,158,310,161,313,163,319,163,322,165,325,166,331,167,334,167,336 },
    { 253,293,253,293,157,311,160,314,162,320,162,323,164,326,165,332,166,335,166,337 },
    { 254,78,254,78,156,79,159,80,161,81,161,81,163,81,164,81,165,81,165,81 },
    { 255,294,255,294,155,312,158,315,160,321,160,324,162,327,163,333,164,336,164,338 },
    { 256,295,256,295,154,313,157,316,159,322,159,325,161,328,162,334,163,337,163,339 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,160,329,161,335,162,338,162,340 },
    { 257,296,257,296,153,314,156,317,158,323,158,326,159,330,160,336,161,339,161,341 },
    { 258,297,258,297,152,315,155,318,157,324,157,327,158,331,159,337,160,340,160,342 },
    { 259,298,259,298,151,316,154,319,156,325,156,328,157,332,158,338,159,341,159,343 },
    { 260,299,260,299,150,317,153,320,155,326,155,329,156,333,157,339,158,342,158,344 },
    { 261,51,261,51,149,52,152,53,154,54,154,54,155,54,156,54,157,54,157,54 },
    { 262,300,262,300,148,318,151,321,153,327,153,330,154,334,155,340,156,343,156,345 },
    { 263,87,263,87,147,88,150,89,152,90,152,90,153,90,154,90,155,90,155,90 },
    { 264,53,264,53,146,54,149,55,151,56,151,56,152,56,153,56,154,56,154,56 },
    { 265,301,265,301,145,319,148,322,150,328,150,331,151,335,152,341,153,344,153,346 },
    { 266,20,266,20,144,21,147,22,149,23,149,23,150,23,151,23,152,23,152,23 },
    { 267,32,267,32,143,33,146,34,148,35,148,35,149,35,150,35,151,35,151,35 },
    { 268,70,268,70,142,71,145,72,147,73,147,73,148,73,149,73,150,73,150,73 },
    { -1,-1,-1,-1,140,320,143,323,145,329,145,332,146,336,147,342,148,345,148,347 },
    { -1,-1,-1,-1,141,321,144,324,146,330,146,333,147,337,148,343,149,346,149,348 },
    { 269,66,269,66,139,67,142,68,144,69,144,69,145,69,145,69,146,69,146,69 },
    { 270,302,270,302,138,322,141,325,143,331,143,334,144,338,144,344,145,347,145,349 },
    { 271,303,271,303,137,323,140,326,142,332,142,335,143,339,143,345,144,348,144,350 },
    { 272,304,272,304,136,324,139,327,141,333,141,336,142,340,142,346,143,349,143,351 },
    { 273,3,273,3,135,4,138,5,140,6,140,6,141,6,141,6,142,6,142,6 },
    { 274,43,274,43,134,44,137,45,139,46,139,46,140,46,140,46,141,46,141,46 },
    { 275,305,275,305,133,325,136,328,138,334,138,337,139,341,139,347,140,350,140,352 },
    { 276,81,276,81,132,82,135,83,137,84,137,84,138,84,138,84,139,84,139,84 },
    { 277,60,277,60,131,61,134,62,136,63,136,63,137,63,137,63,138,63,138,63 },
    { 278,306,278,306,130,326,133,329,135,335,135,338,136,342,136,348,137,351,137,353 },
    { 279,307,279,307,129,327,132,330,134,336,134,339,135,343,135,349,136,352,136,354 },
    { 280,308,280,308,128,328,131,331,133,337,133,340,134,344,134,350,135,353,135,355 },
    { 281,309,281,309,127,329,130,332,132,338,132,341,133,345,133,351,134,354,134,356 },
    { 282,310,282,310,126,330,129,333,131,339,131,342,132,346,132,352,133,355,133,357 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 283,311,283,311,125,331,128,334,130,340,130,343,131,347,131,353,132,356,132,358 },
    { 284,29,284,29,124,30,127,31,129,32,129,32,130,32,130,32,131,32,131,32 },
    { 285,7,285,7,123,8,126,9,128,10,128,10,129,10,129,10,130,10,130,10 },
    { 286,312,286,312,122,332,125,335,127,341,127,344,128,348,128,354,129,357,129,359 },
    { 287,6,287,6,121,7,124,8,126,9,126,9,127,9,127,9,128,9,128,9 },
    { 288,313,288,313,120,333,123,336,125,342,125,345,126,349,126,355,127,358,127,360 },
    { 289,314,289,314,119,334,122,337,124,343,124,346,125,350,125,356,126,359,126,361 },
    { 290,315,290,315,118,335,121,338,123,344,123,347,124,351,124,357,125,360,125,362 },
    { 291,316,291,316,117,336,120,339,122,345,122,348,123,352,123,358,124,361,124,363 },
    { 292,317,292,317,116,337,119,340,121,346,121,349,122,353,122,359,123,362,123,364 },
    { 293,318,293,318,115,338,118,341,120,347,120,350,121,354,121,360,122,363,122,365 },
    { 294,9,294,9,114,10,117,11,119,12,119,12,120,12,120,12,121,12,121,12 },
    { 295,8,295,8,113,9,116,10,118,11,118,11,119,11,119,11,120,11,120,11 },
    { 296,40,296,40,112,41,115,42,117,43,117,43,118,43,118,43,119,43,119,43 },
    { 297,319,297,319,111,339,114,342,116,348,116,351,117,355,117,361,118,364,118,366 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 298,320,298,320,110,340,113,343,115,349,115,352,116,356,116,362,117,365,117,367 },
    { 299,31,299,31,109,32,112,33,114,34,114,34,115,34,115,34,116,34,116,34 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 300,321,300,321,108,341,111,344,113,350,113,353,114,357,114,363,115,366,115,368 },
    { 301,322,301,322,107,342,110,345,112,351,112,354,113,358,113,364,114,367,114,369 },
    { 302,323,302,323,106,343,109,346,111,352,111,355,112,359,112,365,113,368,113,370 },
    { 303,324,303,324,105,344,108,347,110,353,110,356,111,360,111,366,112,369,112,371 },
    { 304,79,304,79,104,80,107,81,109,82,109,82,110,82,110,82,111,82,111,82 },
    { -1,-1,-1,-1,-1,-1,-1,-1,108,354,108,357,109,361,109,367,110,370,110,372 },
    { 305,325,305,325,103,345,106,348,107,355,107,358,108,362,108,368,109,371,109,373 },
    { 306,326,306,326,102,346,105,349,106,356,106,359,107,363,107,369,108,372,108,374 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,449,364,455,370,459,373,459,375 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 307,327,307,327,101,347,104,350,105,357,105,360,106,365,106,371,107,374,107,376 },
    { 308,328,308,328,100,348,103,351,104,358,104,361,105,366,105,372,106,375,106,377 },
    { 309,329,309,329,99,349,102,352,103,359,103,362,104,367,104,373,105,376,105,378 },
    { 310,330,310,330,98,350,101,353,102,360,102,363,103,368,103,374,104,377,104,379 },
    { 311,331,311,331,97,351,100,354,101,361,101,364,102,369,102,375,103,378,103,380 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 312,332,312,332,96,352,99,355,100,362,100,365,101,370,101,376,102,379,102,381 },
    { 313,333,313,333,95,353,98,356,99,363,99,366,100,371,100,377,101,380,101,382 },
    { 314,334,314,334,94,354,97,357,98,364,98,367,99,372,99,378,100,381,100,383 },
    { 315,335,315,335,93,355,96,358,97,365,97,368,98,373,98,379,99,382,99,384 },
    { -1,-1,-1,-1,92,356,95,359,96,366,96,369,97,374,97,380,98,383,98,385 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,96,375,96,381,97,384,97,386 },
    { 316,336,316,336,91,357,94,360,95,367,95,370,95,376,95,382,96,385,96,387 },
    { 317,337,317,337,90,358,93,361,94,368,94,371,94,377,94,383,95,386,95,388 },
    { 318,338,318,338,89,359,92,362,93,369,93,372,93,378,93,384,94,387,94,389 },
    { 319,339,319,339,88,360,91,363,92,370,92,373,92,379,92,385,93,388,93,390 },
    { 320,340,320,340,87,361,90,364,91,371,91,374,91,380,91,386,92,389,92,391 },
    { 321,341,321,341,86,362,89,365,90,372,90,375,90,381,90,387,91,390,91,392 },
    { 322,342,322,342,85,363,88,366,89,373,89,376,89,382,89,388,90,391,90,393 },
    { 323,11,323,11,84,12,87,13,88,14,88,14,88,14,88,14,89,14,89,14 },
    { 324,42,324,42,83,43,86,44,87,45,87,45,87,45,87,45,88,45,88,45 },
    { 325,343,325,343,82,364,85,367,86,374,86,377,86,383,86,389,87,392,87,394 },
    { 326,344,326,344,81,365,84,368,85,375,85,378,85,384,85,390,86,393,86,395 },
    { -1,-1,-1,-1,64,366,65,369,66,376,66,379,66,385,66,391,67,394,67,396 },
    { 327,345,327,345,80,367,83,370,84,377,84,380,84,386,84,392,85,395,85,397 },
    { 328,346,328,346,79,368,82,371,83,378,83,381,83,387,83,393,84,396,84,398 },
    { 329,36,329,36,78,37,81,38,82,39,82,39,82,39,82,39,83,39,83,39 },
    { 330,347,330,347,77,369,80,372,81,379,81,382,81,388,81,394,82,397,82,399 },
    { 331,348,331,348,76,370,79,373,80,380,80,383,80,389,80,395,81,398,81,400 },
    { 332,89,332,89,75,90,78,91,79,92,79,92,79,92,79,92,80,92,80,92 },
    { 333,25,333,25,74,26,77,27,78,28,78,28,78,28,78,28,79,28,79,28 },
    { 334,349,334,349,73,371,76,374,77,381,77,384,77,390,77,396,78,399,78,401 },
    { -1,-1,-1,-1,-1,-1,-1,-1,440,382,443,385,445,391,451,397,455,400,455,402 },
    { 335,10,335,10,72,11,75,12,76,13,76,13,76,13,76,13,77,13,77,13 },
    { 336,350,336,350,71,372,74,375,75,383,75,386,75,392,75,398,76,401,76,403 },
    { 337,351,337,351,70,373,73,376,74,384,74,387,74,393,74,399,75,402,75,404 },
    { 338,352,338,352,69,374,72,377,73,385,73,388,73,394,73,400,74,403,74,405 },
    { -1,-1,-1,-1,201,375,204,378,206,386,206,389,208,395,210,401,212,404,212,406 },
    { 339,353,339,353,68,376,71,379,72,387,72,390,72,396,72,402,73,405,73,407 },
    { 340,354,340,354,67,377,70,380,71,388,71,391,71,397,71,403,72,406,72,408 },
    { 341,355,341,355,66,378,69,381,70,389,70,392,70,398,70,404,71,407,71,409 },
    { 342,356,342,356,65,379,68,382,69,390,69,393,69,399,69,405,70,408,70,410 },
    { 343,357,343,357,63,380,64,383,65,391,65,394,65,400,65,406,66,409,66,411 },
    { 344,358,344,358,62,381,63,384,64,392,64,395,64,401,64,407,65,410,65,412 },
    { 345,359,345,359,61,382,62,385,63,393,63,396,63,402,63,408,64,411,64,413 },
    { 346,360,346,360,60,383,61,386,62,394,62,397,62,403,62,409,63,412,63,414 },
    { 347,361,347,361,59,384,60,387,61,395,61,398,61,404,61,410,62,413,62,415 },
    { 348,362,348,362,58,385,59,388,60,396,60,399,60,405,60,411,61,414,61,416 },
    { 349,363,349,363,57,386,58,389,59,397,59,400,59,406,59,412,60,415,60,417 },
    { 350,364,350,364,56,387,57,390,58,398,58,401,58,407,58,413,59,416,59,418 },
    { 351,365,351,365,55,388,56,391,57,399,57,402,57,408,57,414,58,417,58,419 },
    { 352,366,352,366,54,389,55,392,56,400,56,403,56,409,56,415,57,418,57,420 },
    { 353,367,353,367,53,390,54,393,55,401,55,404,55,410,55,416,56,419,56,421 },
    { 354,95,354,95,52,96,53,97,54,98,54,98,54,98,54,98,55,98,55,98 },
    { -1,-1,-1,-1,-1,-1,66,394,67,402,67,405,67,411,67,417,68,420,68,422 },
    { 355,368,355,368,51,391,52,395,53,403,53,406,53,412,53,418,54,421,54,423 },
    { 356,369,356,369,50,392,51,396,52,404,52,407,52,413,52,419,53,422,53,424 },
    { 357,370,357,370,49,393,50,397,51,405,51,408,51,414,51,420,52,423,52,425 },
    { 358,93,358,93,48,94,49,95,50,96,50,96,50,96,50,96,51,96,51,96 },
    { 359,371,359,371,47,394,48,398,49,406,49,409,49,415,49,421,50,424,50,426 },
    { -1,-1,-1,-1,-1,-1,47,399,48,407,48,410,48,416,48,422,49,425,49,427 },
    { 360,372,360,372,46,395,46,400,47,408,47,411,47,417,47,423,48,426,48,428 },
    { 361,373,361,373,45,396,45,401,46,409,46,412,46,418,46,424,47,427,47,429 },
    { 362,374,362,374,44,397,44,402,45,410,45,413,45,419,45,425,46,428,46,430 },
    { 363,375,363,375,43,398,43,403,44,411,44,414,44,420,44,426,45,429,45,431 },
    { 364,376,364,376,42,399,42,404,43,412,43,415,43,421,43,427,44,430,44,432 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 365,377,365,377,41,400,41,405,42,413,42,416,42,422,42,428,43,431,43,433 },
    { -1,-1,-1,-1,40,401,40,406,41,414,41,417,41,423,41,429,42,432,42,434 },
    { 366,378,366,378,39,402,39,407,40,415,40,418,40,424,40,430,41,433,41,435 },
    { 367,379,367,379,38,403,38,408,39,416,39,419,39,425,39,431,40,434,40,436 },
    { 368,380,368,380,37,404,37,409,38,417,38,420,38,426,38,432,39,435,39,437 },
    { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,38,436,38,438 },
    { 369,381,369,381,36,405,36,410,37,418,37,421,37,427,37,433,37,437,37,439 },
    { 370,41,370,41,35,42,35,43,36,44,36,44,36,44,36,44,36,44,36,44 },
    { 371,80,371,80,34,81,34,82,35,83,35,83,35,83,35,83,35,83,35,83 },
    { 372,382,372,382,33,406,33,411,34,419,34,422,34,428,34,434,34,438,34,440 },
    { 373,383,373,383,32,407,32,412,33,420,33,423,33,429,33,435,33,439,33,441 },
    { 374,384,374,384,31,408,31,413,32,421,32,424,32,430,32,436,32,440,32,442 },
    { 375,385,375,385,30,409,30,414,31,422,31,425,31,431,31,437,31,441,31,443 },
    { 376,91,376,91,29,92,29,93,30,94,30,94,30,94,30,94,30,94,30,94 },
    { 377,386,377,386,28,410,28,415,29,423,29,426,29,432,29,438,29,442,29,444 },
    { 378,387,378,387,27,411,27,416,28,424,28,427,28,433,28,439,28,443,28,445 },
    { 379,388,379,388,26,412,26,417,27,425,27,428,27,434,27,440,27,444,27,446 },
    { 380,389,380,389,25,413,25,418,26,426,26,429,26,435,26,441,26,445,26,447 },
    { 381,390,381,390,24,414,24,419,25,427,25,430,25,436,25,442,25,446,25,448 },
    { 382,391,382,391,23,415,23,420,24,428,24,431,24,437,24,443,24,447,24,449 },
    { 383,392,383,392,22,416,22,421,23,429,23,432,23,438,23,444,23,448,23,450 },
    { 384,393,384,393,21,417,21,422,22,430,22,433,22,439,22,445,22,449,22,451 },
    { 385,39,385,39,19,40,19,41,20,42,20,42,20,42,20,42,20,42,20,42 },
    { -1,-1,-1,-1,20,418,20,423,21,431,21,434,21,440,21,446,21,450,21,452 },
    { -1,-1,-1,-1,17,419,17,424,18,432,18,435,18,441,18,447,18,451,18,453 },
    { -1,-1,-1,-1,18,420,18,425,19,433,19,436,19,442,19,448,19,452,19,454 },
    { 386,394,386,394,16,421,16,426,17,434,17,437,17,443,17,449,17,453,17,455 },
    { -1,-1,-1,-1,15,422,15,427,16,435,16,438,16,444,16,450,16,454,16,456 },
    { 387,395,387,395,14,423,14,428,15,436,15,439,15,445,15,451,15,455,15,457 },
    { 388,396,388,396,13,424,13,429,14,437,14,440,14,446,14,452,14,456,14,458 },
    { 389,88,389,88,12,89,12,90,13,91,13,91,13,91,13,91,13,91,13,91 },
    { 390,23,390,23,11,24,11,25,12,26,12,26,12,26,12,26,12,26,12,26 },
    { 391,1,391,1,10,2,10,3,11,4,11,4,11,4,11,4,11,4,11,4 },
    { -1,-1,-1,-1,9,425,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
    { 392,397,392,397,8,426,9,430,10,438,10,441,10,447,10,453,10,457,10,459 },
    { 393,398,393,398,7,427,8,431,9,439,9,442,9,448,9,454,9,458,9,460 },
    { 394,399,394,399,6,428,7,432,8,440,8,443,8,449,8,455,8,459,8,461 },
    { 395,400,395,400,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1 },
    { 396,5,396,5,5,6,6,7,7,8,7,8,7,8,7,8,7,8,7,8 },
    { 397,24,397,24,4,25,5,26,6,27,6,27,6,27,6,27,6,27,6,27 },
    { 398,84,398,84,3,85,4,86,5,87,5,87,5,87,5,87,5,87,5,87 },
    { 399,55,399,55,2,56,3,57,4,58,4,58,4,58,4,58,4,58,4,58 },
    { 400,67,400,67,1,68,2,69,3,70,3,70,3,70,3,70,3,70,3,70 }
};

static const ULONG OsBuildTable[] = {
    7600, 7601, 9200, 9600, 10240, 10586, 14393, 15063, 16299, 17134
};

static
SHORT
NTAPI
NameToIndex(
    __in PWSTR Name
)
{
    SHORT Result = -1;
    SHORT Index = 0;

    for (Index = 0;
        Index < RTL_NUMBER_OF(NameTable);
        Index++) {
        if (0 == _wcsicmp(
            Name,
            NameTable[Index])) {
            Result = Index;
            break;
        }
    }

    return Result;
}

static
SHORT
NTAPI
NameToNumber(
    __in PWSTR Name
)
{
    NTSTATUS Status = STATUS_SUCCESS;
    ULONG BuildNumber = 0;
    SHORT Result = -1;
    CCHAR Version = -1;
    SHORT Index = -1;
    CCHAR OsSelect = 0;

    PsGetVersion(
        NULL,
        NULL,
        &BuildNumber,
        NULL);

    if (NT_SUCCESS(Status)) {
        for (OsSelect = 0;
            OsSelect < RTL_NUMBER_OF(OsBuildTable);
            OsSelect++) {
            if (BuildNumber == OsBuildTable[OsSelect]) {
#ifndef _WIN64
                Version = OsSelect * 2;
#else
                Version = OsSelect * 2 + 1;
#endif
            }
        }

        if (Version >= 0) {
            Index = NameToIndex(Name);

            if (Index >= 0) {
                Result = NumberTable[Index][Version];
            }
        }
    }

    return Result;
}

static
NTSTATUS
NTAPI
FindAddress(
    VOID
)
{
    NTSTATUS Status = STATUS_SUCCESS;
    PCHAR FoundAddress = NULL;
    UNICODE_STRING FunctionName = { 0 };
    SIZE_T Offset = 0;
    PLONG Pointer = NULL;

#ifndef _WIN64
#define SERVICE_SIGNATURE "\x6a\x08\xe8"

    RtlInitUnicodeString(
        &FunctionName,
        L"KeServiceDescriptorTable");

    ServiceDescriptorTable = (PKSERVICE_TABLE_DESCRIPTOR)
        MmGetSystemRoutineAddress(&FunctionName);

    if (FALSE != MmIsAddressValid(ServiceDescriptorTable)) {
        RtlInitUnicodeString(
            &FunctionName,
            L"ZwClose");

        FoundAddress = MmGetSystemRoutineAddress(&FunctionName);

        if (FALSE != MmIsAddressValid(FoundAddress)) {
            Status = STATUS_ENTRYPOINT_NOT_FOUND;

            for (Offset = 0;
                Offset < 0x40;
                Offset++) {
                if (sizeof(SERVICE_SIGNATURE) - 1 == RtlCompareMemory(
                    FoundAddress + Offset,
                    SERVICE_SIGNATURE,
                    sizeof(SERVICE_SIGNATURE) - 1)) {
                    Pointer = (PLONG)(FoundAddress + Offset + sizeof(SERVICE_SIGNATURE) - 1);
                    KiSystemService = (PCHAR)Pointer + *Pointer + sizeof(LONG);

                    Status = STATUS_SUCCESS;
                    break;
                }
            }
        }
        else {
            Status = STATUS_ENTRYPOINT_NOT_FOUND;
        }
    }
    else {
        Status = STATUS_ENTRYPOINT_NOT_FOUND;
    }
#else
#define _INTERNAL "\x00\x00\xe9"
#define _LINKAGE "\x48\x8d\x05"
#define _TABLE "\x4c\x8d\x15"

    RtlInitUnicodeString(
        &FunctionName,
        L"ZwClose");

    FoundAddress = MmGetSystemRoutineAddress(&FunctionName);

    if (FALSE != MmIsAddressValid(FoundAddress)) {
        Status = STATUS_ENTRYPOINT_NOT_FOUND;

        for (Offset = 0;
            Offset < sizeof(KSTUBS_ENTRY);
            Offset++) {
            if (sizeof(_INTERNAL) - 1 == RtlCompareMemory(
                FoundAddress + Offset,
                _INTERNAL,
                sizeof(_INTERNAL) - 1)) {
                Pointer = (PLONG)(FoundAddress + Offset + sizeof(_INTERNAL) - 1);
                KiServiceInternal = (PCHAR)Pointer + *Pointer + sizeof(LONG);

                for (Offset = 0;
                    Offset < sizeof(KSTUBS_ENTRY);
                    Offset++) {
                    if (sizeof(_LINKAGE) - 1 == RtlCompareMemory(
                        FoundAddress + Offset,
                        _LINKAGE,
                        sizeof(_LINKAGE) - 1)) {
                        Pointer = (PLONG)(FoundAddress + Offset + sizeof(_LINKAGE) - 1);
                        KiServiceLinkage = (PCHAR)Pointer + *Pointer + sizeof(LONG);

                        FoundAddress = KiServiceInternal;

                        for (Offset = 0;
                            Offset < PAGE_SIZE;
                            Offset++) {
                            if (sizeof(_TABLE) - 1 == RtlCompareMemory(
                                FoundAddress + Offset,
                                _TABLE,
                                sizeof(_TABLE) - 1)) {
                                Pointer = (PLONG)(FoundAddress + Offset + sizeof(_TABLE) - 1);
                                ServiceDescriptorTable = (PKSERVICE_TABLE_DESCRIPTOR)
                                    ((PCHAR)Pointer + *Pointer + sizeof(LONG));

                                Status = STATUS_SUCCESS;
                                break;
                            }
                        }

                        break;
                    }
                }

                break;
            }
        }
    }
    else {
        Status = STATUS_ENTRYPOINT_NOT_FOUND;
    }
#endif

    return Status;
}

static
PVOID
NTAPI
NameToAddress(
    __in PKSTUBS_ENTRY Table,
    __in PWSTR Name
)
{
    PVOID Address = NULL;
    SHORT Number = -1;

    Number = NameToNumber(Name);

    if (Number >= 0) {
        Address = (PCHAR)&Table[Number];
    }

    return Address;
}

NTSTATUS
NTAPI
BuildServiceDispatchTable(
    VOID
)
{
    NTSTATUS Status = STATUS_SUCCESS;
    PVOID Address = NULL;
    ULONG Index = 0;
    KIRQL OldIrql = 0;
    PKSTUBS_ENTRY TempDispatchTable = NULL;

    OldIrql = KeAcquireSpinLockForDpc(&Lock);

    if (NULL == ServiceDescriptorTable) {
        Status = FindAddress();

        if (NT_SUCCESS(Status)) {
            TempDispatchTable = ExAllocatePool(
                NonPagedPool,
                ServiceDescriptorTable->Limit * sizeof(KSTUBS_ENTRY));

            if (NULL != TempDispatchTable) {
                for (Index = 0;
                    Index < ServiceDescriptorTable->Limit;
                    Index++) {
                    AJUST_STUB_ENTRY(
                        (PCHAR)&TempDispatchTable[Index],
                        Index);
                }

                for (Index = 0;
                    Index < MaxNumberStubs;
                    Index++) {
                    Address = NameToAddress(TempDispatchTable, NameTable[Index]);

                    if (Address) {
#ifndef _WIN64
                        CopyStub(
                            &ServiceDispatchTable + Index,
                            Address,
                            FIELD_OFFSET(KSTUBS_ENTRY, Ret));

                        AJUST_STUBS_ENTRY32(&ServiceDispatchTable + Index);
#else
                        CopyStub(
                            &ServiceDispatchTable + Index,
                            Address,
                            sizeof(KSTUBS_ENTRY));
#endif // !_WIN64
                    }
                }

                ExFreePool(TempDispatchTable);
            }
        }
    }

    KeReleaseSpinLockForDpc(&Lock, OldIrql);

    return Status;
}

#pragma optimize("g", on)
