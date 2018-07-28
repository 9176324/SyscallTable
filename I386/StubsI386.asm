; 
; 
; Copyright (c) 2015-2017 by blindtiger ( blindtiger@foxmail.com )
; 
; The contents of this file are subject to the Mozilla Public License Version
; 2.0 (the "License"); you may not use this file except in compliance with
; the License. You may obtain a copy of the License at
; http://www.mozilla.org/MPL/
; 
; Software distributed under the License is distributed on an "AS IS" basis,
; WITHOUT WARRANTY OF ANY KIND, either express or implied. Ree the License
; for the specific language governing rights and limitations under the
; License.
; 
; The Initial Developer of the Original e is blindtiger.
; 
; 

.686P
.XMM

OPTION CASEMAP:NONE

BuildServiceDispatchTable PROTO STDCALL

_DATA$00 SEGMENT PAGE 'DATA'

_DATA$00 ENDS

_TEXT$00 SEGMENT PAGE 'CODE'

STUBS_ENTRY MACRO Name, NumArgs

    ifb <NumArgs>
        _Stub&Name&@&0 :

            mov eax,  _Stub&Name&@&0        ; save caller
            push eax
            mov eax, _StubsBridge
            jmp eax

        DB  4 dup (0cch)
            ret

            int 3

        PUBLIC _Stub&Name&@&0
    else
        _Stub&Name&@&NumArgs :
            mov eax, _Stub&Name&@&NumArgs   ; save caller
            push eax
            mov eax, _StubsBridge
            jmp eax

        DB  4 dup (0cch)

            ret NumArgs
            
            int 3

        PUBLIC _Stub&Name&@&NumArgs
    endif

ENDM

_ServiceDispatchTable :
PUBLIC _ServiceDispatchTable

STUBS_ENTRY AcceptConnectPort, 24

align 20h

STUBS_ENTRY AccessCheck, 32

align 20h

STUBS_ENTRY AccessCheckAndAuditAlarm, 44

align 20h

STUBS_ENTRY AccessCheckByType, 44

align 20h

STUBS_ENTRY AccessCheckByTypeAndAuditAlarm, 64

align 20h

STUBS_ENTRY AccessCheckByTypeResultList, 44

align 20h

STUBS_ENTRY AccessCheckByTypeResultListAndAuditAlarm, 64

align 20h

STUBS_ENTRY AccessCheckByTypeResultListAndAuditAlarmByHandle, 68

align 20h

STUBS_ENTRY AcquireCMFViewOwnership, 12

align 20h

STUBS_ENTRY AcquireProcessActivityReference, 12

align 20h

STUBS_ENTRY AddAtom, 12

align 20h

STUBS_ENTRY AddAtomEx, 16

align 20h

STUBS_ENTRY AddBootEntry, 8

align 20h

STUBS_ENTRY AddDriverEntry, 8

align 20h

STUBS_ENTRY AdjustGroupsToken, 24

align 20h

STUBS_ENTRY AdjustPrivilegesToken, 24

align 20h

STUBS_ENTRY AdjustTokenClaimsAndDeviceGroups, 64

align 20h

STUBS_ENTRY AlertResumeThread, 8

align 20h

STUBS_ENTRY AlertThread, 4

align 20h

STUBS_ENTRY AlertThreadByThreadId, 4

align 20h

STUBS_ENTRY AllocateLocallyUniqueId, 4

align 20h

STUBS_ENTRY AllocateReserveObject, 12

align 20h

STUBS_ENTRY AllocateUserPhysicalPages, 12

align 20h

STUBS_ENTRY AllocateUuids, 16

align 20h

STUBS_ENTRY AllocateVirtualMemory, 24

align 20h

STUBS_ENTRY AllocateVirtualMemoryEx, 28

align 20h

STUBS_ENTRY AlpcAcceptConnectPort, 36

align 20h

STUBS_ENTRY AlpcCancelMessage, 12

align 20h

STUBS_ENTRY AlpcConnectPort, 44

align 20h

STUBS_ENTRY AlpcConnectPortEx, 44

align 20h

STUBS_ENTRY AlpcCreatePort, 12

align 20h

STUBS_ENTRY AlpcCreatePortSection, 24

align 20h

STUBS_ENTRY AlpcCreateResourceReserve, 16

align 20h

STUBS_ENTRY AlpcCreateSectionView, 12

align 20h

STUBS_ENTRY AlpcCreateSecurityContext, 12

align 20h

STUBS_ENTRY AlpcDeletePortSection, 12

align 20h

STUBS_ENTRY AlpcDeleteResourceReserve, 12

align 20h

STUBS_ENTRY AlpcDeleteSectionView, 12

align 20h

STUBS_ENTRY AlpcDeleteSecurityContext, 12

align 20h

STUBS_ENTRY AlpcDisconnectPort, 8

align 20h

STUBS_ENTRY AlpcImpersonateClientContainerOfPort, 12

align 20h

STUBS_ENTRY AlpcImpersonateClientOfPort, 12

align 20h

STUBS_ENTRY AlpcOpenSenderProcess, 24

align 20h

STUBS_ENTRY AlpcOpenSenderThread, 24

align 20h

STUBS_ENTRY AlpcQueryInformation, 20

align 20h

STUBS_ENTRY AlpcQueryInformationMessage, 24

align 20h

STUBS_ENTRY AlpcRevokeSecurityContext, 12

align 20h

STUBS_ENTRY AlpcSendWaitReceivePort, 32

align 20h

STUBS_ENTRY AlpcSetInformation, 16

align 20h

STUBS_ENTRY ApphelpCacheControl, 8

align 20h

STUBS_ENTRY AreMappedFilesTheSame, 8

align 20h

STUBS_ENTRY AssignProcessToJobObject, 8

align 20h

STUBS_ENTRY AssociateWaitCompletionPacket, 32

align 20h

STUBS_ENTRY CallEnclave, 16

align 20h

STUBS_ENTRY CallbackReturn, 12

align 20h

STUBS_ENTRY CancelDeviceWakeupRequest, 4

align 20h

STUBS_ENTRY CancelIoFile, 8

align 20h

STUBS_ENTRY CancelIoFileEx, 12

align 20h

STUBS_ENTRY CancelSynchronousIoFile, 12

align 20h

STUBS_ENTRY CancelTimer, 8

align 20h

STUBS_ENTRY CancelTimer2, 8

align 20h

STUBS_ENTRY CancelWaitCompletionPacket, 8

align 20h

STUBS_ENTRY ClearAllSavepointsTransaction, 4

align 20h

STUBS_ENTRY ClearEvent, 4

align 20h

STUBS_ENTRY ClearSavepointTransaction, 8

align 20h

STUBS_ENTRY Close, 4

align 20h

STUBS_ENTRY CloseObjectAuditAlarm, 12

align 20h

STUBS_ENTRY CommitComplete, 8

align 20h

STUBS_ENTRY CommitEnlistment, 8

align 20h

STUBS_ENTRY CommitRegistryTransaction, 8

align 20h

STUBS_ENTRY CommitTransaction, 8

align 20h

STUBS_ENTRY CompactKeys, 8

align 20h

STUBS_ENTRY CompareObjects, 8

align 20h

STUBS_ENTRY CompareSigningLevels, 8

align 20h

STUBS_ENTRY CompareTokens, 12

align 20h

STUBS_ENTRY CompleteConnectPort, 4

align 20h

STUBS_ENTRY CompressKey, 4

align 20h

STUBS_ENTRY ConnectPort, 32

align 20h

STUBS_ENTRY Continue, 8

align 20h

STUBS_ENTRY ConvertBetweenAuxiliaryCounterAndPerformanceCounter, 16

align 20h

STUBS_ENTRY CreateDebugObject, 16

align 20h

STUBS_ENTRY CreateDirectoryObject, 12

align 20h

STUBS_ENTRY CreateDirectoryObjectEx, 20

align 20h

STUBS_ENTRY CreateEnclave, 36

align 20h

STUBS_ENTRY CreateEnlistment, 32

align 20h

STUBS_ENTRY CreateEvent, 20

align 20h

STUBS_ENTRY CreateEventPair, 12

align 20h

STUBS_ENTRY CreateFile, 44

align 20h

STUBS_ENTRY CreateIRTimer, 12

align 20h

STUBS_ENTRY CreateIoCompletion, 16

align 20h

STUBS_ENTRY CreateJobObject, 12

align 20h

STUBS_ENTRY CreateJobSet, 12

align 20h

STUBS_ENTRY CreateKey, 28

align 20h

STUBS_ENTRY CreateKeyTransacted, 32

align 20h

STUBS_ENTRY CreateKeyedEvent, 16

align 20h

STUBS_ENTRY CreateLowBoxToken, 36

align 20h

STUBS_ENTRY CreateMailslotFile, 32

align 20h

STUBS_ENTRY CreateMutant, 16

align 20h

STUBS_ENTRY CreateNamedPipeFile, 56

align 20h

STUBS_ENTRY CreatePagingFile, 16

align 20h

STUBS_ENTRY CreatePartition, 16

align 20h

STUBS_ENTRY CreatePort, 20

align 20h

STUBS_ENTRY CreatePrivateNamespace, 16

align 20h

STUBS_ENTRY CreateProcess, 32

align 20h

STUBS_ENTRY CreateProcessEx, 36

align 20h

STUBS_ENTRY CreateProfile, 36

align 20h

STUBS_ENTRY CreateProfileEx, 40

align 20h

STUBS_ENTRY CreateRegistryTransaction, 16

align 20h

STUBS_ENTRY CreateResourceManager, 28

align 20h

STUBS_ENTRY CreateSection, 28

align 20h

STUBS_ENTRY CreateSemaphore, 20

align 20h

STUBS_ENTRY CreateSymbolicLinkObject, 16

align 20h

STUBS_ENTRY CreateThread, 32

align 20h

STUBS_ENTRY CreateThreadEx, 44

align 20h

STUBS_ENTRY CreateTimer, 16

align 20h

STUBS_ENTRY CreateTimer2, 20

align 20h

STUBS_ENTRY CreateToken, 52

align 20h

STUBS_ENTRY CreateTokenEx, 68

align 20h

STUBS_ENTRY CreateTransaction, 40

align 20h

STUBS_ENTRY CreateTransactionManager, 24

align 20h

STUBS_ENTRY CreateUserProcess, 44

align 20h

STUBS_ENTRY CreateWaitCompletionPacket, 12

align 20h

STUBS_ENTRY CreateWaitablePort, 20

align 20h

STUBS_ENTRY CreateWnfStateName, 28

align 20h

STUBS_ENTRY CreateWorkerFactory, 40

align 20h

STUBS_ENTRY DebugActiveProcess, 8

align 20h

STUBS_ENTRY DebugContinue, 12

align 20h

STUBS_ENTRY DelayExecution, 8

align 20h

STUBS_ENTRY DeleteAtom, 4

align 20h

STUBS_ENTRY DeleteBootEntry, 4

align 20h

STUBS_ENTRY DeleteDriverEntry, 4

align 20h

STUBS_ENTRY DeleteFile, 4

align 20h

STUBS_ENTRY DeleteKey, 4

align 20h

STUBS_ENTRY DeleteObjectAuditAlarm, 12

align 20h

STUBS_ENTRY DeletePrivateNamespace, 4

align 20h

STUBS_ENTRY DeleteValueKey, 8

align 20h

STUBS_ENTRY DeleteWnfStateData, 8

align 20h

STUBS_ENTRY DeleteWnfStateName, 4

align 20h

STUBS_ENTRY DeviceIoControlFile, 40

align 20h

STUBS_ENTRY DisableLastKnownGood,

align 20h

STUBS_ENTRY DisplayString, 4

align 20h

STUBS_ENTRY DrawText, 4

align 20h

STUBS_ENTRY DuplicateObject, 28

align 20h

STUBS_ENTRY DuplicateToken, 24

align 20h

STUBS_ENTRY EnableLastKnownGood,

align 20h

STUBS_ENTRY EnumerateBootEntries, 8

align 20h

STUBS_ENTRY EnumerateDriverEntries, 8

align 20h

STUBS_ENTRY EnumerateKey, 24

align 20h

STUBS_ENTRY EnumerateSystemEnvironmentValuesEx, 12

align 20h

STUBS_ENTRY EnumerateTransactionObject, 20

align 20h

STUBS_ENTRY EnumerateValueKey, 24

align 20h

STUBS_ENTRY ExtendSection, 8

align 20h

STUBS_ENTRY FilterBootOption, 20

align 20h

STUBS_ENTRY FilterToken, 24

align 20h

STUBS_ENTRY FilterTokenEx, 56

align 20h

STUBS_ENTRY FindAtom, 12

align 20h

STUBS_ENTRY FlushBuffersFile, 8

align 20h

STUBS_ENTRY FlushBuffersFileEx, 20

align 20h

STUBS_ENTRY FlushInstallUILanguage, 8

align 20h

STUBS_ENTRY FlushInstructionCache, 12

align 20h

STUBS_ENTRY FlushKey, 4

align 20h

STUBS_ENTRY FlushProcessWriteBuffers,

align 20h

STUBS_ENTRY FlushVirtualMemory, 16

align 20h

STUBS_ENTRY FlushWriteBuffer,

align 20h

STUBS_ENTRY FreeUserPhysicalPages, 12

align 20h

STUBS_ENTRY FreeVirtualMemory, 16

align 20h

STUBS_ENTRY FreezeRegistry, 4

align 20h

STUBS_ENTRY FreezeTransactions, 8

align 20h

STUBS_ENTRY FsControlFile, 40

align 20h

STUBS_ENTRY GetCachedSigningLevel, 24

align 20h

STUBS_ENTRY GetCompleteWnfStateSubscription, 24

align 20h

STUBS_ENTRY GetContextThread, 8

align 20h

STUBS_ENTRY GetCurrentProcessorNumber,

align 20h

STUBS_ENTRY GetCurrentProcessorNumberEx, 4

align 20h

STUBS_ENTRY GetDevicePowerState, 8

align 20h

STUBS_ENTRY GetMUIRegistryInfo, 12

align 20h

STUBS_ENTRY GetNextProcess, 20

align 20h

STUBS_ENTRY GetNextThread, 24

align 20h

STUBS_ENTRY GetNlsSectionPtr, 20

align 20h

STUBS_ENTRY GetNotificationResourceManager, 28

align 20h

STUBS_ENTRY GetPlugPlayEvent, 16

align 20h

STUBS_ENTRY GetWriteWatch, 28

align 20h

STUBS_ENTRY ImpersonateAnonymousToken, 4

align 20h

STUBS_ENTRY ImpersonateClientOfPort, 8

align 20h

STUBS_ENTRY ImpersonateThread, 12

align 20h

STUBS_ENTRY InitializeEnclave, 20

align 20h

STUBS_ENTRY InitializeNlsFiles, 12

align 20h

STUBS_ENTRY InitializeRegistry, 4

align 20h

STUBS_ENTRY InitiatePowerAction, 16

align 20h

STUBS_ENTRY IsProcessInJob, 8

align 20h

STUBS_ENTRY IsSystemResumeAutomatic,

align 20h

STUBS_ENTRY IsUILanguageComitted,

align 20h

STUBS_ENTRY ListTransactions, 12

align 20h

STUBS_ENTRY ListenPort, 8

align 20h

STUBS_ENTRY LoadDriver, 4

align 20h

STUBS_ENTRY LoadEnclaveData, 36

align 20h

STUBS_ENTRY LoadHotPatch, 8

align 20h

STUBS_ENTRY LoadKey, 8

align 20h

STUBS_ENTRY LoadKey2, 12

align 20h

STUBS_ENTRY LoadKeyEx, 32

align 20h

STUBS_ENTRY LockFile, 40

align 20h

STUBS_ENTRY LockProductActivationKeys, 8

align 20h

STUBS_ENTRY LockRegistryKey, 4

align 20h

STUBS_ENTRY LockVirtualMemory, 16

align 20h

STUBS_ENTRY MakePermanentObject, 4

align 20h

STUBS_ENTRY MakeTemporaryObject, 4

align 20h

STUBS_ENTRY ManagePartition, 20

align 20h

STUBS_ENTRY MapCMFModule, 24

align 20h

STUBS_ENTRY MapUserPhysicalPages, 12

align 20h

STUBS_ENTRY MapUserPhysicalPagesScatter, 12

align 20h

STUBS_ENTRY MapViewOfSection, 40

align 20h

STUBS_ENTRY MapViewOfSectionEx, 36

align 20h

STUBS_ENTRY MarshallTransaction, 24

align 20h

STUBS_ENTRY ModifyBootEntry, 4

align 20h

STUBS_ENTRY ModifyDriverEntry, 4

align 20h

STUBS_ENTRY NotifyChangeDirectoryFile, 36

align 20h

STUBS_ENTRY NotifyChangeDirectoryFileEx, 40

align 20h

STUBS_ENTRY NotifyChangeKey, 40

align 20h

STUBS_ENTRY NotifyChangeMultipleKeys, 48

align 20h

STUBS_ENTRY NotifyChangeSession, 32

align 20h

STUBS_ENTRY OpenDirectoryObject, 12

align 20h

STUBS_ENTRY OpenEnlistment, 20

align 20h

STUBS_ENTRY OpenEvent, 12

align 20h

STUBS_ENTRY OpenEventPair, 12

align 20h

STUBS_ENTRY OpenFile, 24

align 20h

STUBS_ENTRY OpenIoCompletion, 12

align 20h

STUBS_ENTRY OpenJobObject, 12

align 20h

STUBS_ENTRY OpenKey, 12

align 20h

STUBS_ENTRY OpenKeyEx, 16

align 20h

STUBS_ENTRY OpenKeyTransacted, 16

align 20h

STUBS_ENTRY OpenKeyTransactedEx, 20

align 20h

STUBS_ENTRY OpenKeyedEvent, 12

align 20h

STUBS_ENTRY OpenMutant, 12

align 20h

STUBS_ENTRY OpenObjectAuditAlarm, 48

align 20h

STUBS_ENTRY OpenPartition, 12

align 20h

STUBS_ENTRY OpenPrivateNamespace, 16

align 20h

STUBS_ENTRY OpenProcess, 16

align 20h

STUBS_ENTRY OpenProcessToken, 12

align 20h

STUBS_ENTRY OpenProcessTokenEx, 16

align 20h

STUBS_ENTRY OpenRegistryTransaction, 12

align 20h

STUBS_ENTRY OpenResourceManager, 20

align 20h

STUBS_ENTRY OpenSection, 12

align 20h

STUBS_ENTRY OpenSemaphore, 12

align 20h

STUBS_ENTRY OpenSession, 12

align 20h

STUBS_ENTRY OpenSymbolicLinkObject, 12

align 20h

STUBS_ENTRY OpenThread, 16

align 20h

STUBS_ENTRY OpenThreadToken, 16

align 20h

STUBS_ENTRY OpenThreadTokenEx, 20

align 20h

STUBS_ENTRY OpenTimer, 12

align 20h

STUBS_ENTRY OpenTransaction, 20

align 20h

STUBS_ENTRY OpenTransactionManager, 24

align 20h

STUBS_ENTRY PlugPlayControl, 12

align 20h

STUBS_ENTRY PowerInformation, 20

align 20h

STUBS_ENTRY PrePrepareComplete, 8

align 20h

STUBS_ENTRY PrePrepareEnlistment, 8

align 20h

STUBS_ENTRY PrepareComplete, 8

align 20h

STUBS_ENTRY PrepareEnlistment, 8

align 20h

STUBS_ENTRY PrivilegeCheck, 12

align 20h

STUBS_ENTRY PrivilegeObjectAuditAlarm, 24

align 20h

STUBS_ENTRY PrivilegedServiceAuditAlarm, 20

align 20h

STUBS_ENTRY PropagationComplete, 16

align 20h

STUBS_ENTRY PropagationFailed, 12

align 20h

STUBS_ENTRY ProtectVirtualMemory, 20

align 20h

STUBS_ENTRY PullTransaction, 28

align 20h

STUBS_ENTRY PulseEvent, 8

align 20h

STUBS_ENTRY QueryAttributesFile, 8

align 20h

STUBS_ENTRY QueryAuxiliaryCounterFrequency, 4

align 20h

STUBS_ENTRY QueryBootEntryOrder, 8

align 20h

STUBS_ENTRY QueryBootOptions, 8

align 20h

STUBS_ENTRY QueryDebugFilterState, 8

align 20h

STUBS_ENTRY QueryDefaultLocale, 8

align 20h

STUBS_ENTRY QueryDefaultUILanguage, 4

align 20h

STUBS_ENTRY QueryDirectoryFile, 44

align 20h

STUBS_ENTRY QueryDirectoryFileEx, 40

align 20h

STUBS_ENTRY QueryDirectoryObject, 28

align 20h

STUBS_ENTRY QueryDriverEntryOrder, 8

align 20h

STUBS_ENTRY QueryEaFile, 36

align 20h

STUBS_ENTRY QueryEvent, 20

align 20h

STUBS_ENTRY QueryFullAttributesFile, 8

align 20h

STUBS_ENTRY QueryInformationAtom, 20

align 20h

STUBS_ENTRY QueryInformationByName, 20

align 20h

STUBS_ENTRY QueryInformationEnlistment, 20

align 20h

STUBS_ENTRY QueryInformationFile, 20

align 20h

STUBS_ENTRY QueryInformationJobObject, 20

align 20h

STUBS_ENTRY QueryInformationPort, 20

align 20h

STUBS_ENTRY QueryInformationProcess, 20

align 20h

STUBS_ENTRY QueryInformationResourceManager, 20

align 20h

STUBS_ENTRY QueryInformationThread, 20

align 20h

STUBS_ENTRY QueryInformationToken, 20

align 20h

STUBS_ENTRY QueryInformationTransaction, 20

align 20h

STUBS_ENTRY QueryInformationTransactionManager, 20

align 20h

STUBS_ENTRY QueryInformationWorkerFactory, 20

align 20h

STUBS_ENTRY QueryInstallUILanguage, 4

align 20h

STUBS_ENTRY QueryIntervalProfile, 8

align 20h

STUBS_ENTRY QueryIoCompletion, 20

align 20h

STUBS_ENTRY QueryKey, 20

align 20h

STUBS_ENTRY QueryLicenseValue, 20

align 20h

STUBS_ENTRY QueryMultipleValueKey, 24

align 20h

STUBS_ENTRY QueryMutant, 20

align 20h

STUBS_ENTRY QueryObject, 20

align 20h

STUBS_ENTRY QueryOpenSubKeys, 8

align 20h

STUBS_ENTRY QueryOpenSubKeysEx, 16

align 20h

STUBS_ENTRY QueryPerformanceCounter, 8

align 20h

STUBS_ENTRY QueryPortInformationProcess,

align 20h

STUBS_ENTRY QueryQuotaInformationFile, 36

align 20h

STUBS_ENTRY QuerySection, 20

align 20h

STUBS_ENTRY QuerySecurityAttributesToken, 24

align 20h

STUBS_ENTRY QuerySecurityObject, 20

align 20h

STUBS_ENTRY QuerySecurityPolicy, 24

align 20h

STUBS_ENTRY QuerySemaphore, 20

align 20h

STUBS_ENTRY QuerySymbolicLinkObject, 12

align 20h

STUBS_ENTRY QuerySystemEnvironmentValue, 16

align 20h

STUBS_ENTRY QuerySystemEnvironmentValueEx, 20

align 20h

STUBS_ENTRY QuerySystemInformation, 16

align 20h

STUBS_ENTRY QuerySystemInformationEx, 24

align 20h

STUBS_ENTRY QuerySystemTime, 4

align 20h

STUBS_ENTRY QueryTimer, 20

align 20h

STUBS_ENTRY QueryTimerResolution, 12

align 20h

STUBS_ENTRY QueryValueKey, 24

align 20h

STUBS_ENTRY QueryVirtualMemory, 24

align 20h

STUBS_ENTRY QueryVolumeInformationFile, 20

align 20h

STUBS_ENTRY QueryWnfStateData, 24

align 20h

STUBS_ENTRY QueryWnfStateNameInformation, 20

align 20h

STUBS_ENTRY QueueApcThread, 20

align 20h

STUBS_ENTRY QueueApcThreadEx, 24

align 20h

STUBS_ENTRY RaiseException, 12

align 20h

STUBS_ENTRY RaiseHardError, 24

align 20h

STUBS_ENTRY ReadFile, 36

align 20h

STUBS_ENTRY ReadFileScatter, 36

align 20h

STUBS_ENTRY ReadOnlyEnlistment, 8

align 20h

STUBS_ENTRY ReadRequestData, 24

align 20h

STUBS_ENTRY ReadVirtualMemory, 20

align 20h

STUBS_ENTRY RecoverEnlistment, 8

align 20h

STUBS_ENTRY RecoverResourceManager, 4

align 20h

STUBS_ENTRY RecoverTransactionManager, 4

align 20h

STUBS_ENTRY RegisterProtocolAddressInformation, 20

align 20h

STUBS_ENTRY RegisterThreadTerminatePort, 4

align 20h

STUBS_ENTRY ReleaseCMFViewOwnership,

align 20h

STUBS_ENTRY ReleaseKeyedEvent, 16

align 20h

STUBS_ENTRY ReleaseMutant, 8

align 20h

STUBS_ENTRY ReleaseSemaphore, 12

align 20h

STUBS_ENTRY ReleaseWorkerFactoryWorker, 4

align 20h

STUBS_ENTRY RemoveIoCompletion, 20

align 20h

STUBS_ENTRY RemoveIoCompletionEx, 24

align 20h

STUBS_ENTRY RemoveProcessDebug, 8

align 20h

STUBS_ENTRY RenameKey, 8

align 20h

STUBS_ENTRY RenameTransactionManager, 8

align 20h

STUBS_ENTRY ReplaceKey, 12

align 20h

STUBS_ENTRY ReplacePartitionUnit, 12

align 20h

STUBS_ENTRY ReplyPort, 8

align 20h

STUBS_ENTRY ReplyWaitReceivePort, 16

align 20h

STUBS_ENTRY ReplyWaitReceivePortEx, 20

align 20h

STUBS_ENTRY ReplyWaitReplyPort, 8

align 20h

STUBS_ENTRY RequestDeviceWakeup, 4

align 20h

STUBS_ENTRY RequestPort, 8

align 20h

STUBS_ENTRY RequestWaitReplyPort, 12

align 20h

STUBS_ENTRY RequestWakeupLatency, 4

align 20h

STUBS_ENTRY ResetEvent, 8

align 20h

STUBS_ENTRY ResetWriteWatch, 12

align 20h

STUBS_ENTRY RestoreKey, 12

align 20h

STUBS_ENTRY ResumeProcess, 4

align 20h

STUBS_ENTRY ResumeThread, 8

align 20h

STUBS_ENTRY RevertContainerImpersonation,

align 20h

STUBS_ENTRY RollbackComplete, 8

align 20h

STUBS_ENTRY RollbackEnlistment, 8

align 20h

STUBS_ENTRY RollbackRegistryTransaction, 8

align 20h

STUBS_ENTRY RollbackSavepointTransaction, 8

align 20h

STUBS_ENTRY RollbackTransaction, 8

align 20h

STUBS_ENTRY RollforwardTransactionManager, 8

align 20h

STUBS_ENTRY SaveKey, 8

align 20h

STUBS_ENTRY SaveKeyEx, 12

align 20h

STUBS_ENTRY SaveMergedKeys, 12

align 20h

STUBS_ENTRY SavepointComplete, 8

align 20h

STUBS_ENTRY SavepointTransaction, 8

align 20h

STUBS_ENTRY SecureConnectPort, 36

align 20h

STUBS_ENTRY SerializeBoot,

align 20h

STUBS_ENTRY SetBootEntryOrder, 8

align 20h

STUBS_ENTRY SetBootOptions, 8

align 20h

STUBS_ENTRY SetCachedSigningLevel, 20

align 20h

STUBS_ENTRY SetCachedSigningLevel2, 24

align 20h

STUBS_ENTRY SetContextThread, 8

align 20h

STUBS_ENTRY SetDebugFilterState, 12

align 20h

STUBS_ENTRY SetDefaultHardErrorPort, 4

align 20h

STUBS_ENTRY SetDefaultLocale, 8

align 20h

STUBS_ENTRY SetDefaultUILanguage, 4

align 20h

STUBS_ENTRY SetDriverEntryOrder, 8

align 20h

STUBS_ENTRY SetEaFile, 16

align 20h

STUBS_ENTRY SetEvent, 8

align 20h

STUBS_ENTRY SetEventBoostPriority, 4

align 20h

STUBS_ENTRY SetHighEventPair, 4

align 20h

STUBS_ENTRY SetHighWaitLowEventPair, 4

align 20h

STUBS_ENTRY SetIRTimer, 8

align 20h

STUBS_ENTRY SetInformationDebugObject, 20

align 20h

STUBS_ENTRY SetInformationEnlistment, 16

align 20h

STUBS_ENTRY SetInformationFile, 20

align 20h

STUBS_ENTRY SetInformationJobObject, 16

align 20h

STUBS_ENTRY SetInformationKey, 16

align 20h

STUBS_ENTRY SetInformationObject, 16

align 20h

STUBS_ENTRY SetInformationProcess, 16

align 20h

STUBS_ENTRY SetInformationResourceManager, 16

align 20h

STUBS_ENTRY SetInformationSymbolicLink, 16

align 20h

STUBS_ENTRY SetInformationThread, 16

align 20h

STUBS_ENTRY SetInformationToken, 16

align 20h

STUBS_ENTRY SetInformationTransaction, 16

align 20h

STUBS_ENTRY SetInformationTransactionManager, 16

align 20h

STUBS_ENTRY SetInformationVirtualMemory, 24

align 20h

STUBS_ENTRY SetInformationWorkerFactory, 16

align 20h

STUBS_ENTRY SetIntervalProfile, 8

align 20h

STUBS_ENTRY SetIoCompletion, 20

align 20h

STUBS_ENTRY SetIoCompletionEx, 24

align 20h

STUBS_ENTRY SetLdtEntries, 24

align 20h

STUBS_ENTRY SetLowEventPair, 4

align 20h

STUBS_ENTRY SetLowWaitHighEventPair, 4

align 20h

STUBS_ENTRY SetQuotaInformationFile, 16

align 20h

STUBS_ENTRY SetSecurityObject, 12

align 20h

STUBS_ENTRY SetSystemEnvironmentValue, 8

align 20h

STUBS_ENTRY SetSystemEnvironmentValueEx, 20

align 20h

STUBS_ENTRY SetSystemInformation, 12

align 20h

STUBS_ENTRY SetSystemPowerState, 12

align 20h

STUBS_ENTRY SetSystemTime, 8

align 20h

STUBS_ENTRY SetThreadExecutionState, 8

align 20h

STUBS_ENTRY SetTimer, 28

align 20h

STUBS_ENTRY SetTimer2, 16

align 20h

STUBS_ENTRY SetTimerEx, 16

align 20h

STUBS_ENTRY SetTimerResolution, 12

align 20h

STUBS_ENTRY SetUuidSeed, 4

align 20h

STUBS_ENTRY SetValueKey, 24

align 20h

STUBS_ENTRY SetVolumeInformationFile, 20

align 20h

STUBS_ENTRY SetWnfProcessNotificationEvent, 4

align 20h

STUBS_ENTRY ShutdownSystem, 4

align 20h

STUBS_ENTRY ShutdownWorkerFactory, 8

align 20h

STUBS_ENTRY SignalAndWaitForSingleObject, 16

align 20h

STUBS_ENTRY SinglePhaseReject, 8

align 20h

STUBS_ENTRY StartProfile, 4

align 20h

STUBS_ENTRY StartTm,

align 20h

STUBS_ENTRY StopProfile, 4

align 20h

STUBS_ENTRY SubscribeWnfStateChange, 16

align 20h

STUBS_ENTRY SuspendProcess, 4

align 20h

STUBS_ENTRY SuspendThread, 8

align 20h

STUBS_ENTRY SystemDebugControl, 24

align 20h

STUBS_ENTRY TerminateEnclave, 8

align 20h

STUBS_ENTRY TerminateJobObject, 8

align 20h

STUBS_ENTRY TerminateProcess, 8

align 20h

STUBS_ENTRY TerminateThread, 8

align 20h

STUBS_ENTRY TestAlert,

align 20h

STUBS_ENTRY ThawRegistry,

align 20h

STUBS_ENTRY ThawTransactions,

align 20h

STUBS_ENTRY TraceControl, 24

align 20h

STUBS_ENTRY TraceEvent, 16

align 20h

STUBS_ENTRY TranslateFilePath, 16

align 20h

STUBS_ENTRY UmsThreadYield, 4

align 20h

STUBS_ENTRY UnloadDriver, 4

align 20h

STUBS_ENTRY UnloadKey, 4

align 20h

STUBS_ENTRY UnloadKey2, 8

align 20h

STUBS_ENTRY UnloadKeyEx, 8

align 20h

STUBS_ENTRY UnlockFile, 20

align 20h

STUBS_ENTRY UnlockVirtualMemory, 16

align 20h

STUBS_ENTRY UnmapViewOfSection, 8

align 20h

STUBS_ENTRY UnmapViewOfSectionEx, 12

align 20h

STUBS_ENTRY UnsubscribeWnfStateChange, 4

align 20h

STUBS_ENTRY UpdateWnfStateData, 28

align 20h

STUBS_ENTRY VdmControl, 8

align 20h

STUBS_ENTRY WaitForAlertByThreadId, 8

align 20h

STUBS_ENTRY WaitForDebugEvent, 16

align 20h

STUBS_ENTRY WaitForKeyedEvent, 16

align 20h

STUBS_ENTRY WaitForMultipleObjects, 20

align 20h

STUBS_ENTRY WaitForMultipleObjects32, 20

align 20h

STUBS_ENTRY WaitForSingleObject, 12

align 20h

STUBS_ENTRY WaitForWnfNotifications, 8

align 20h

STUBS_ENTRY WaitForWorkViaWorkerFactory, 20

align 20h

STUBS_ENTRY WaitHighEventPair, 4

align 20h

STUBS_ENTRY WaitLowEventPair, 4

align 20h

STUBS_ENTRY WorkerFactoryWorkerReady, 4

align 20h

STUBS_ENTRY WriteFile, 36

align 20h

STUBS_ENTRY WriteFileGather, 36

align 20h

STUBS_ENTRY WriteRequestData, 24

align 20h

STUBS_ENTRY WriteVirtualMemory, 20

align 20h

STUBS_ENTRY YieldExecution,

align 20h

_StubsBridge :
                        ; [esp + 4] caller
    pushfd              ; save eflag
    call BuildServiceDispatchTable
    popfd               ; restore eflag
    ret                 ; jmp caller (now the stubs table is ajust to system function)

DB  24 dup (0cch)

align 20h

_TEXT$00 ENDS

END
