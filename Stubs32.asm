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

    .XLIST
INCLUDE GLOBAL.INC
    .LIST

OPTION CASEMAP:NONE

BuildStubs PROTO STDCALL

_DATA$00 SEGMENT PAGE 'DATA'

_DATA$00 ENDS

_TEXT$00 SEGMENT ALIGN(10h) 'CODE'

SYSSTUBS_ENTRY MACRO Name, NumArgs

    _Stub&Name :
        mov eax, $ + 0          ; save caller
        push eax
        mov eax, _StubsBridge@0
        jmp eax
	
    DB  4 dup (0cch)

        ifb <NumArgs>
            ret
        DB  2 dup (0cch)
        else
            ret NumArgs
        endif

    DB  12 dup (0cch)           ; fill align 20h

    PUBLIC _Stub&Name

ENDM

_FirstStub :
PUBLIC _FirstStub

SYSSTUBS_ENTRY AcceptConnectPort@24, 24
SYSSTUBS_ENTRY AccessCheck@32, 32
SYSSTUBS_ENTRY AccessCheckAndAuditAlarm@44, 44
SYSSTUBS_ENTRY AccessCheckByType@44, 44
SYSSTUBS_ENTRY AccessCheckByTypeAndAuditAlarm@64, 64
SYSSTUBS_ENTRY AccessCheckByTypeResultList@44, 44
SYSSTUBS_ENTRY AccessCheckByTypeResultListAndAuditAlarm@64, 64
SYSSTUBS_ENTRY AccessCheckByTypeResultListAndAuditAlarmByHandle@68, 68
SYSSTUBS_ENTRY AcquireCMFViewOwnership@0
SYSSTUBS_ENTRY AcquireProcessActivityReference@12, 12
SYSSTUBS_ENTRY AddAtom@12, 12
SYSSTUBS_ENTRY AddAtomEx@16, 16
SYSSTUBS_ENTRY AddBootEntry@8, 8
SYSSTUBS_ENTRY AddDriverEntry@8, 8
SYSSTUBS_ENTRY AdjustGroupsToken@24, 24
SYSSTUBS_ENTRY AdjustPrivilegesToken@24, 24
SYSSTUBS_ENTRY AdjustTokenClaimsAndDeviceGroups@64, 64
SYSSTUBS_ENTRY AlertResumeThread@8, 8
SYSSTUBS_ENTRY AlertThread@4, 4
SYSSTUBS_ENTRY AlertThreadByThreadId@4, 4
SYSSTUBS_ENTRY AllocateLocallyUniqueId@4, 4
SYSSTUBS_ENTRY AllocateReserveObject@12, 12
SYSSTUBS_ENTRY AllocateUserPhysicalPages@12, 12
SYSSTUBS_ENTRY AllocateUuids@16, 16
SYSSTUBS_ENTRY AllocateVirtualMemory@24, 24
SYSSTUBS_ENTRY AlpcAcceptConnectPort@36, 36
SYSSTUBS_ENTRY AlpcCancelMessage@12, 12
SYSSTUBS_ENTRY AlpcConnectPort@44, 44
SYSSTUBS_ENTRY AlpcConnectPortEx@44, 44
SYSSTUBS_ENTRY AlpcCreatePort@12, 12
SYSSTUBS_ENTRY AlpcCreatePortSection@24, 24
SYSSTUBS_ENTRY AlpcCreateResourceReserve@16, 16
SYSSTUBS_ENTRY AlpcCreateSectionView@12, 12
SYSSTUBS_ENTRY AlpcCreateRecurityContext@12, 12
SYSSTUBS_ENTRY AlpcDeletePortSection@12, 12
SYSSTUBS_ENTRY AlpcDeleteResourceReserve@12, 12
SYSSTUBS_ENTRY AlpcDeleteSectionView@12, 12
SYSSTUBS_ENTRY AlpcDeleteRecurityContext@12, 12
SYSSTUBS_ENTRY AlpcDisconnectPort@8, 8
SYSSTUBS_ENTRY AlpcImpersonateClientContainerOfPort@12, 12
SYSSTUBS_ENTRY AlpcImpersonateClientOfPort@12, 12
SYSSTUBS_ENTRY AlpcOpenRenderProcess@24, 24
SYSSTUBS_ENTRY AlpcOpenRenderThread@24, 24
SYSSTUBS_ENTRY AlpcQueryInformation@20, 20
SYSSTUBS_ENTRY AlpcQueryInformationMessage@24, 24
SYSSTUBS_ENTRY AlpcRevokeRecurityContext@12, 12
SYSSTUBS_ENTRY AlpcRendWaitReceivePort@32, 32
SYSSTUBS_ENTRY AlpcSetInformation@16, 16
SYSSTUBS_ENTRY ApphelpCacheControl@8, 8
SYSSTUBS_ENTRY AreMappedFilesTheSame@8, 8
SYSSTUBS_ENTRY AssignProcessToJobObject@8, 8
SYSSTUBS_ENTRY AssociateWaitCompletionPacket@32, 32
SYSSTUBS_ENTRY CallEnclave@16, 16
SYSSTUBS_ENTRY CallbackReturn@12, 12
SYSSTUBS_ENTRY CancelDeviceWakeupRequest@0
SYSSTUBS_ENTRY CancelIoFile@8, 8
SYSSTUBS_ENTRY CancelIoFileEx@12, 12
SYSSTUBS_ENTRY CancelSynchronousIoFile@12, 12
SYSSTUBS_ENTRY CancelTimer@8, 8
SYSSTUBS_ENTRY CancelTimer2@8, 8
SYSSTUBS_ENTRY CancelWaitCompletionPacket@8, 8
SYSSTUBS_ENTRY ClearAllSavepointsTransaction@0
SYSSTUBS_ENTRY ClearEvent@4, 4
SYSSTUBS_ENTRY ClearSavepointTransaction@0
SYSSTUBS_ENTRY Close@4, 4
SYSSTUBS_ENTRY CloseObjectAuditAlarm@12, 12
SYSSTUBS_ENTRY CommitComplete@8, 8
SYSSTUBS_ENTRY CommitEnlistment@8, 8
SYSSTUBS_ENTRY CommitRegistryTransaction@8, 8
SYSSTUBS_ENTRY CommitTransaction@8, 8
SYSSTUBS_ENTRY CompactKeys@8, 8
SYSSTUBS_ENTRY CompareObjects@8, 8
SYSSTUBS_ENTRY CompareSigningLevels@8, 8
SYSSTUBS_ENTRY CompareTokens@12, 12
SYSSTUBS_ENTRY CompleteConnectPort@4, 4
SYSSTUBS_ENTRY CompressKey@4, 4
SYSSTUBS_ENTRY ConnectPort@32, 32
SYSSTUBS_ENTRY Continue@8, 8
SYSSTUBS_ENTRY ConvertBetweenAuxiliaryCounterAndPerformanceCounter@16, 16
SYSSTUBS_ENTRY CreateDebugObject@16, 16
SYSSTUBS_ENTRY CreateDirectoryObject@12, 12
SYSSTUBS_ENTRY CreateDirectoryObjectEx@20, 20
SYSSTUBS_ENTRY CreateEnclave@36, 36
SYSSTUBS_ENTRY CreateEnlistment@32, 32
SYSSTUBS_ENTRY CreateEvent@20, 20
SYSSTUBS_ENTRY CreateEventPair@12, 12
SYSSTUBS_ENTRY CreateFile@44, 44
SYSSTUBS_ENTRY CreateIRTimer@12, 12
SYSSTUBS_ENTRY CreateIoCompletion@16, 16
SYSSTUBS_ENTRY CreateJobObject@12, 12
SYSSTUBS_ENTRY CreateJobSet@12, 12
SYSSTUBS_ENTRY CreateKey@28, 28
SYSSTUBS_ENTRY CreateKeyTransacted@32, 32
SYSSTUBS_ENTRY CreateKeyedEvent@16, 16
SYSSTUBS_ENTRY CreateLowBoxToken@36, 36
SYSSTUBS_ENTRY CreateMailslotFile@32, 32
SYSSTUBS_ENTRY CreateMutant@16, 16
SYSSTUBS_ENTRY CreateNamedPipeFile@56, 56
SYSSTUBS_ENTRY CreatePagingFile@16, 16
SYSSTUBS_ENTRY CreatePartition@16, 16
SYSSTUBS_ENTRY CreatePort@20, 20
SYSSTUBS_ENTRY CreatePrivateNamespace@16, 16
SYSSTUBS_ENTRY CreateProcess@32, 32
SYSSTUBS_ENTRY CreateProcessEx@36, 36
SYSSTUBS_ENTRY CreateProfile@36, 36
SYSSTUBS_ENTRY CreateProfileEx@40, 40
SYSSTUBS_ENTRY CreateRegistryTransaction@16, 16
SYSSTUBS_ENTRY CreateResourceManager@28, 28
SYSSTUBS_ENTRY CreateSection@28, 28
SYSSTUBS_ENTRY CreateRemaphore@20, 20
SYSSTUBS_ENTRY CreateSymbolicLinkObject@16, 16
SYSSTUBS_ENTRY CreateThread@32, 32
SYSSTUBS_ENTRY CreateThreadEx@44, 44
SYSSTUBS_ENTRY CreateTimer@16, 16
SYSSTUBS_ENTRY CreateTimer2@20, 20
SYSSTUBS_ENTRY CreateToken@52, 52
SYSSTUBS_ENTRY CreateTokenEx@68, 68
SYSSTUBS_ENTRY CreateTransaction@40, 40
SYSSTUBS_ENTRY CreateTransactionManager@24, 24
SYSSTUBS_ENTRY CreateUserProcess@44, 44
SYSSTUBS_ENTRY CreateWaitCompletionPacket@12, 12
SYSSTUBS_ENTRY CreateWaitablePort@20, 20
SYSSTUBS_ENTRY CreateWnfStateName@28, 28
SYSSTUBS_ENTRY CreateWorkerFactory@40, 40
SYSSTUBS_ENTRY DebugActiveProcess@8, 8
SYSSTUBS_ENTRY DebugContinue@12, 12
SYSSTUBS_ENTRY DelayExecution@8, 8
SYSSTUBS_ENTRY DeleteAtom@4, 4
SYSSTUBS_ENTRY DeleteBootEntry@4, 4
SYSSTUBS_ENTRY DeleteDriverEntry@4, 4
SYSSTUBS_ENTRY DeleteFile@4, 4
SYSSTUBS_ENTRY DeleteKey@4, 4
SYSSTUBS_ENTRY DeleteObjectAuditAlarm@12, 12
SYSSTUBS_ENTRY DeletePrivateNamespace@4, 4
SYSSTUBS_ENTRY DeleteValueKey@8, 8
SYSSTUBS_ENTRY DeleteWnfStateData@8, 8
SYSSTUBS_ENTRY DeleteWnfStateName@4, 4
SYSSTUBS_ENTRY DeviceIoControlFile@40, 40
SYSSTUBS_ENTRY DisableLastKnownGood@0
SYSSTUBS_ENTRY DisplayString@4, 4
SYSSTUBS_ENTRY DrawText@4, 4
SYSSTUBS_ENTRY DuplicateObject@28, 28
SYSSTUBS_ENTRY DuplicateToken@24, 24
SYSSTUBS_ENTRY EnableLastKnownGood@0
SYSSTUBS_ENTRY EnumerateBootEntries@8, 8
SYSSTUBS_ENTRY EnumerateDriverEntries@8, 8
SYSSTUBS_ENTRY EnumerateKey@24, 24
SYSSTUBS_ENTRY EnumerateSystemEnvironmentValuesEx@12, 12
SYSSTUBS_ENTRY EnumerateTransactionObject@20, 20
SYSSTUBS_ENTRY EnumerateValueKey@24, 24
SYSSTUBS_ENTRY ExtendSection@8, 8
SYSSTUBS_ENTRY FilterBootOption@20, 20
SYSSTUBS_ENTRY FilterToken@24, 24
SYSSTUBS_ENTRY FilterTokenEx@56, 56
SYSSTUBS_ENTRY FindAtom@12, 12
SYSSTUBS_ENTRY FlushBuffersFile@8, 8
SYSSTUBS_ENTRY FlushBuffersFileEx@20, 20
SYSSTUBS_ENTRY FlushInstallUILanguage@8, 8
SYSSTUBS_ENTRY FlushInstructionCache@12, 12
SYSSTUBS_ENTRY FlushKey@4, 4
SYSSTUBS_ENTRY FlushProcessWriteBuffers@0
SYSSTUBS_ENTRY FlushVirtualMemory@16, 16
SYSSTUBS_ENTRY FlushWriteBuffer@0
SYSSTUBS_ENTRY FreeUserPhysicalPages@12, 12
SYSSTUBS_ENTRY FreeVirtualMemory@16, 16
SYSSTUBS_ENTRY FreezeRegistry@4, 4
SYSSTUBS_ENTRY FreezeTransactions@8, 8
SYSSTUBS_ENTRY FsControlFile@40, 40
SYSSTUBS_ENTRY GetCachedSigningLevel@24, 24
SYSSTUBS_ENTRY GetCompleteWnfStateSubscription@24, 24
SYSSTUBS_ENTRY GetContextThread@8, 8
SYSSTUBS_ENTRY GetCurrentProcessorNumber@0
SYSSTUBS_ENTRY GetCurrentProcessorNumberEx@4, 4
SYSSTUBS_ENTRY GetDevicePowerState@8, 8
SYSSTUBS_ENTRY GetMUIRegistryInfo@12, 12
SYSSTUBS_ENTRY GetNextProcess@20, 20
SYSSTUBS_ENTRY GetNextThread@24, 24
SYSSTUBS_ENTRY GetNlsSectionPtr@20, 20
SYSSTUBS_ENTRY GetNotificationResourceManager@28, 28
SYSSTUBS_ENTRY GetPlugPlayEvent@0
SYSSTUBS_ENTRY GetWriteWatch@28, 28
SYSSTUBS_ENTRY ImpersonateAnonymousToken@4, 4
SYSSTUBS_ENTRY ImpersonateClientOfPort@8, 8
SYSSTUBS_ENTRY ImpersonateThread@12, 12
SYSSTUBS_ENTRY InitializeEnclave@20, 20
SYSSTUBS_ENTRY InitializeNlsFiles@12, 12
SYSSTUBS_ENTRY InitializeRegistry@4, 4
SYSSTUBS_ENTRY InitiatePowerAction@16, 16
SYSSTUBS_ENTRY IsProcessInJob@8, 8
SYSSTUBS_ENTRY IsSystemResumeAutomatic@0
SYSSTUBS_ENTRY IsUILanguageComitted@0
SYSSTUBS_ENTRY ListTransactions@0
SYSSTUBS_ENTRY ListenPort@8, 8
SYSSTUBS_ENTRY LoadDriver@4, 4
SYSSTUBS_ENTRY LoadEnclaveData@36, 36
SYSSTUBS_ENTRY LoadHotPatch@8, 8
SYSSTUBS_ENTRY LoadKey@8, 8
SYSSTUBS_ENTRY LoadKey2@12, 12
SYSSTUBS_ENTRY LoadKeyEx@32, 32
SYSSTUBS_ENTRY LockFile@40, 40
SYSSTUBS_ENTRY LockProductActivationKeys@8, 8
SYSSTUBS_ENTRY LockRegistryKey@4, 4
SYSSTUBS_ENTRY LockVirtualMemory@16, 16
SYSSTUBS_ENTRY MakePermanentObject@4, 4
SYSSTUBS_ENTRY MakeTemporaryObject@4, 4
SYSSTUBS_ENTRY ManagePartition@20, 20
SYSSTUBS_ENTRY MapCMFModule@24, 24
SYSSTUBS_ENTRY MapUserPhysicalPages@12, 12
SYSSTUBS_ENTRY MapUserPhysicalPagesScatter@12, 12
SYSSTUBS_ENTRY MapImageSection@40, 40
SYSSTUBS_ENTRY MarshallTransaction@0
SYSSTUBS_ENTRY ModifyBootEntry@4, 4
SYSSTUBS_ENTRY ModifyDriverEntry@4, 4
SYSSTUBS_ENTRY NotifyChangeDirectoryFile@36, 36
SYSSTUBS_ENTRY NotifyChangeDirectoryFileEx@40, 40
SYSSTUBS_ENTRY NotifyChangeKey@40, 40
SYSSTUBS_ENTRY NotifyChangeMultipleKeys@48, 48
SYSSTUBS_ENTRY NotifyChangeRession@32, 32
SYSSTUBS_ENTRY OpenDirectoryObject@12, 12
SYSSTUBS_ENTRY OpenEnlistment@20, 20
SYSSTUBS_ENTRY OpenEvent@12, 12
SYSSTUBS_ENTRY OpenEventPair@12, 12
SYSSTUBS_ENTRY OpenFile@24, 24
SYSSTUBS_ENTRY OpenIoCompletion@12, 12
SYSSTUBS_ENTRY OpenJobObject@12, 12
SYSSTUBS_ENTRY OpenKey@12, 12
SYSSTUBS_ENTRY OpenKeyEx@16, 16
SYSSTUBS_ENTRY OpenKeyTransacted@16, 16
SYSSTUBS_ENTRY OpenKeyTransactedEx@20, 20
SYSSTUBS_ENTRY OpenKeyedEvent@12, 12
SYSSTUBS_ENTRY OpenMutant@12, 12
SYSSTUBS_ENTRY OpenObjectAuditAlarm@48, 48
SYSSTUBS_ENTRY OpenPartition@12, 12
SYSSTUBS_ENTRY OpenPrivateNamespace@16, 16
SYSSTUBS_ENTRY OpenProcess@16, 16
SYSSTUBS_ENTRY OpenProcessToken@12, 12
SYSSTUBS_ENTRY OpenProcessTokenEx@16, 16
SYSSTUBS_ENTRY OpenRegistryTransaction@12, 12
SYSSTUBS_ENTRY OpenResourceManager@20, 20
SYSSTUBS_ENTRY OpenSection@12, 12
SYSSTUBS_ENTRY OpenRemaphore@12, 12
SYSSTUBS_ENTRY OpenRession@12, 12
SYSSTUBS_ENTRY OpenSymbolicLinkObject@12, 12
SYSSTUBS_ENTRY OpenThread@16, 16
SYSSTUBS_ENTRY OpenThreadToken@16, 16
SYSSTUBS_ENTRY OpenThreadTokenEx@20, 20
SYSSTUBS_ENTRY OpenTimer@12, 12
SYSSTUBS_ENTRY OpenTransaction@20, 20
SYSSTUBS_ENTRY OpenTransactionManager@24, 24
SYSSTUBS_ENTRY PlugPlayControl@12, 12
SYSSTUBS_ENTRY PowerInformation@20, 20
SYSSTUBS_ENTRY PrePrepareComplete@8, 8
SYSSTUBS_ENTRY PrePrepareEnlistment@8, 8
SYSSTUBS_ENTRY PrepareComplete@8, 8
SYSSTUBS_ENTRY PrepareEnlistment@8, 8
SYSSTUBS_ENTRY PrivilegeCheck@12, 12
SYSSTUBS_ENTRY PrivilegeObjectAuditAlarm@24, 24
SYSSTUBS_ENTRY PrivilegedRerviceAuditAlarm@20, 20
SYSSTUBS_ENTRY PropagationComplete@16, 16
SYSSTUBS_ENTRY PropagationFailed@12, 12
SYSSTUBS_ENTRY ProtectVirtualMemory@20, 20
SYSSTUBS_ENTRY PullTransaction@0
SYSSTUBS_ENTRY PulseEvent@8, 8
SYSSTUBS_ENTRY QueryAttributesFile@8, 8
SYSSTUBS_ENTRY QueryAuxiliaryCounterFrequency@4, 4
SYSSTUBS_ENTRY QueryBootEntryOrder@8, 8
SYSSTUBS_ENTRY QueryBootOptions@8, 8
SYSSTUBS_ENTRY QueryDebugFilterState@8, 8
SYSSTUBS_ENTRY QueryDefaultLocale@8, 8
SYSSTUBS_ENTRY QueryDefaultUILanguage@4, 4
SYSSTUBS_ENTRY QueryDirectoryFile@44, 44
SYSSTUBS_ENTRY QueryDirectoryFileEx@40, 40
SYSSTUBS_ENTRY QueryDirectoryObject@28, 28
SYSSTUBS_ENTRY QueryDriverEntryOrder@8, 8
SYSSTUBS_ENTRY QueryEaFile@36, 36
SYSSTUBS_ENTRY QueryEvent@20, 20
SYSSTUBS_ENTRY QueryFullAttributesFile@8, 8
SYSSTUBS_ENTRY QueryInformationAtom@20, 20
SYSSTUBS_ENTRY QueryInformationByName@20, 20
SYSSTUBS_ENTRY QueryInformationEnlistment@20, 20
SYSSTUBS_ENTRY QueryInformationFile@20, 20
SYSSTUBS_ENTRY QueryInformationJobObject@20, 20
SYSSTUBS_ENTRY QueryInformationPort@20, 20
SYSSTUBS_ENTRY QueryInformationProcess@20, 20
SYSSTUBS_ENTRY QueryInformationResourceManager@20, 20
SYSSTUBS_ENTRY QueryInformationThread@20, 20
SYSSTUBS_ENTRY QueryInformationToken@20, 20
SYSSTUBS_ENTRY QueryInformationTransaction@20, 20
SYSSTUBS_ENTRY QueryInformationTransactionManager@20, 20
SYSSTUBS_ENTRY QueryInformationWorkerFactory@20, 20
SYSSTUBS_ENTRY QueryInstallUILanguage@4, 4
SYSSTUBS_ENTRY QueryIntervalProfile@8, 8
SYSSTUBS_ENTRY QueryIoCompletion@20, 20
SYSSTUBS_ENTRY QueryKey@20, 20
SYSSTUBS_ENTRY QueryLicenseValue@20, 20
SYSSTUBS_ENTRY QueryMultipleValueKey@24, 24
SYSSTUBS_ENTRY QueryMutant@20, 20
SYSSTUBS_ENTRY QueryObject@20, 20
SYSSTUBS_ENTRY QueryOpenSubKeys@8, 8
SYSSTUBS_ENTRY QueryOpenSubKeysEx@16, 16
SYSSTUBS_ENTRY QueryPerformanceCounter@8, 8
SYSSTUBS_ENTRY QueryPortInformationProcess@0
SYSSTUBS_ENTRY QueryQuotaInformationFile@36, 36
SYSSTUBS_ENTRY QuerySection@20, 20
SYSSTUBS_ENTRY QueryRecurityAttributesToken@24, 24
SYSSTUBS_ENTRY QueryRecurityObject@20, 20
SYSSTUBS_ENTRY QueryRecurityPolicy@24, 24
SYSSTUBS_ENTRY QueryRemaphore@20, 20
SYSSTUBS_ENTRY QuerySymbolicLinkObject@12, 12
SYSSTUBS_ENTRY QuerySystemEnvironmentValue@16, 16
SYSSTUBS_ENTRY QuerySystemEnvironmentValueEx@20, 20
SYSSTUBS_ENTRY QuerySystemInformation@16, 16
SYSSTUBS_ENTRY QuerySystemInformationEx@24, 24
SYSSTUBS_ENTRY QuerySystemTime@4, 4
SYSSTUBS_ENTRY QueryTimer@20, 20
SYSSTUBS_ENTRY QueryTimerResolution@12, 12
SYSSTUBS_ENTRY QueryValueKey@24, 24
SYSSTUBS_ENTRY QueryVirtualMemory@24, 24
SYSSTUBS_ENTRY QueryVolumeInformationFile@20, 20
SYSSTUBS_ENTRY QueryWnfStateData@24, 24
SYSSTUBS_ENTRY QueryWnfStateNameInformation@20, 20
SYSSTUBS_ENTRY QueueApcThread@20, 20
SYSSTUBS_ENTRY QueueApcThreadEx@24, 24
SYSSTUBS_ENTRY RaiseException@12, 12
SYSSTUBS_ENTRY RaiseHardError@24, 24
SYSSTUBS_ENTRY ReadFile@36, 36
SYSSTUBS_ENTRY ReadFileScatter@36, 36
SYSSTUBS_ENTRY ReadOnlyEnlistment@8, 8
SYSSTUBS_ENTRY ReadRequestData@24, 24
SYSSTUBS_ENTRY ReadVirtualMemory@20, 20
SYSSTUBS_ENTRY RecoverEnlistment@8, 8
SYSSTUBS_ENTRY RecoverResourceManager@4, 4
SYSSTUBS_ENTRY RecoverTransactionManager@4, 4
SYSSTUBS_ENTRY RegisterProtocolAddressInformation@20, 20
SYSSTUBS_ENTRY RegisterThreadTerminatePort@4, 4
SYSSTUBS_ENTRY ReleaseCMFViewOwnership@0
SYSSTUBS_ENTRY ReleaseKeyedEvent@16, 16
SYSSTUBS_ENTRY ReleaseMutant@8, 8
SYSSTUBS_ENTRY ReleaseRemaphore@12, 12
SYSSTUBS_ENTRY ReleaseWorkerFactoryWorker@4, 4
SYSSTUBS_ENTRY RemoveIoCompletion@20, 20
SYSSTUBS_ENTRY RemoveIoCompletionEx@24, 24
SYSSTUBS_ENTRY RemoveProcessDebug@8, 8
SYSSTUBS_ENTRY RenameKey@8, 8
SYSSTUBS_ENTRY RenameTransactionManager@8, 8
SYSSTUBS_ENTRY ReplaceKey@12, 12
SYSSTUBS_ENTRY ReplacePartitionUnit@12, 12
SYSSTUBS_ENTRY ReplyPort@8, 8
SYSSTUBS_ENTRY ReplyWaitReceivePort@16, 16
SYSSTUBS_ENTRY ReplyWaitReceivePortEx@20, 20
SYSSTUBS_ENTRY ReplyWaitReplyPort@8, 8
SYSSTUBS_ENTRY RequestDeviceWakeup@0
SYSSTUBS_ENTRY RequestPort@8, 8
SYSSTUBS_ENTRY RequestWaitReplyPort@12, 12
SYSSTUBS_ENTRY RequestWakeupLatency@0
SYSSTUBS_ENTRY ResetEvent@8, 8
SYSSTUBS_ENTRY ResetWriteWatch@12, 12
SYSSTUBS_ENTRY RestoreKey@12, 12
SYSSTUBS_ENTRY ResumeProcess@4, 4
SYSSTUBS_ENTRY ResumeThread@8, 8
SYSSTUBS_ENTRY RevertContainerImpersonation@0
SYSSTUBS_ENTRY RollbackComplete@8, 8
SYSSTUBS_ENTRY RollbackEnlistment@8, 8
SYSSTUBS_ENTRY RollbackRegistryTransaction@8, 8
SYSSTUBS_ENTRY RollbackSavepointTransaction@0
SYSSTUBS_ENTRY RollbackTransaction@8, 8
SYSSTUBS_ENTRY RollforwardTransactionManager@8, 8
SYSSTUBS_ENTRY SaveKey@8, 8
SYSSTUBS_ENTRY SaveKeyEx@12, 12
SYSSTUBS_ENTRY SaveMergedKeys@12, 12
SYSSTUBS_ENTRY SavepointComplete@0
SYSSTUBS_ENTRY SavepointTransaction@0
SYSSTUBS_ENTRY RecureConnectPort@36, 36
SYSSTUBS_ENTRY RerializeBoot@0
SYSSTUBS_ENTRY SetBootEntryOrder@8, 8
SYSSTUBS_ENTRY SetBootOptions@8, 8
SYSSTUBS_ENTRY SetCachedSigningLevel@20, 20
SYSSTUBS_ENTRY SetCachedSigningLevel2@24, 24
SYSSTUBS_ENTRY SetContextThread@8, 8
SYSSTUBS_ENTRY SetDebugFilterState@12, 12
SYSSTUBS_ENTRY SetDefaultHardErrorPort@4, 4
SYSSTUBS_ENTRY SetDefaultLocale@8, 8
SYSSTUBS_ENTRY SetDefaultUILanguage@4, 4
SYSSTUBS_ENTRY SetDriverEntryOrder@8, 8
SYSSTUBS_ENTRY SetEaFile@16, 16
SYSSTUBS_ENTRY SetEvent@8, 8
SYSSTUBS_ENTRY SetEventBoostPriority@4, 4
SYSSTUBS_ENTRY SetHighEventPair@4, 4
SYSSTUBS_ENTRY SetHighWaitLowEventPair@4, 4
SYSSTUBS_ENTRY SetIRTimer@8, 8
SYSSTUBS_ENTRY SetInformationDebugObject@20, 20
SYSSTUBS_ENTRY SetInformationEnlistment@16, 16
SYSSTUBS_ENTRY SetInformationFile@20, 20
SYSSTUBS_ENTRY SetInformationJobObject@16, 16
SYSSTUBS_ENTRY SetInformationKey@16, 16
SYSSTUBS_ENTRY SetInformationObject@16, 16
SYSSTUBS_ENTRY SetInformationProcess@16, 16
SYSSTUBS_ENTRY SetInformationResourceManager@16, 16
SYSSTUBS_ENTRY SetInformationSymbolicLink@16, 16
SYSSTUBS_ENTRY SetInformationThread@16, 16
SYSSTUBS_ENTRY SetInformationToken@16, 16
SYSSTUBS_ENTRY SetInformationTransaction@16, 16
SYSSTUBS_ENTRY SetInformationTransactionManager@16, 16
SYSSTUBS_ENTRY SetInformationVirtualMemory@24, 24
SYSSTUBS_ENTRY SetInformationWorkerFactory@16, 16
SYSSTUBS_ENTRY SetIntervalProfile@8, 8
SYSSTUBS_ENTRY SetIoCompletion@20, 20
SYSSTUBS_ENTRY SetIoCompletionEx@24, 24
SYSSTUBS_ENTRY SetLdtEntries@24, 24
SYSSTUBS_ENTRY SetLowEventPair@4, 4
SYSSTUBS_ENTRY SetLowWaitHighEventPair@4, 4
SYSSTUBS_ENTRY SetQuotaInformationFile@16, 16
SYSSTUBS_ENTRY SetRecurityObject@12, 12
SYSSTUBS_ENTRY SetSystemEnvironmentValue@8, 8
SYSSTUBS_ENTRY SetSystemEnvironmentValueEx@20, 20
SYSSTUBS_ENTRY SetSystemInformation@12, 12
SYSSTUBS_ENTRY SetSystemPowerState@12, 12
SYSSTUBS_ENTRY SetSystemTime@8, 8
SYSSTUBS_ENTRY SetThreadExecutionState@8, 8
SYSSTUBS_ENTRY SetTimer@28, 28
SYSSTUBS_ENTRY SetTimer2@16, 16
SYSSTUBS_ENTRY SetTimerEx@16, 16
SYSSTUBS_ENTRY SetTimerResolution@12, 12
SYSSTUBS_ENTRY SetUuidSeed@4, 4
SYSSTUBS_ENTRY SetValueKey@24, 24
SYSSTUBS_ENTRY SetVolumeInformationFile@20, 20
SYSSTUBS_ENTRY SetWnfProcessNotificationEvent@4, 4
SYSSTUBS_ENTRY ShutdownSystem@4, 4
SYSSTUBS_ENTRY ShutdownWorkerFactory@8, 8
SYSSTUBS_ENTRY SignalAndWaitForSingleObject@16, 16
SYSSTUBS_ENTRY SinglePhaseReject@8, 8
SYSSTUBS_ENTRY StartProfile@4, 4
SYSSTUBS_ENTRY StartTm@0
SYSSTUBS_ENTRY StopProfile@4, 4
SYSSTUBS_ENTRY SubscribeWnfStateChange@16, 16
SYSSTUBS_ENTRY SuspendProcess@4, 4
SYSSTUBS_ENTRY SuspendThread@8, 8
SYSSTUBS_ENTRY SystemDebugControl@24, 24
SYSSTUBS_ENTRY TerminateEnclave@8, 8
SYSSTUBS_ENTRY TerminateJobObject@8, 8
SYSSTUBS_ENTRY TerminateProcess@8, 8
SYSSTUBS_ENTRY TerminateThread@8, 8
SYSSTUBS_ENTRY TestAlert@0
SYSSTUBS_ENTRY ThawRegistry@0
SYSSTUBS_ENTRY ThawTransactions@0
SYSSTUBS_ENTRY TraceControl@24, 24
SYSSTUBS_ENTRY TraceEvent@16, 16
SYSSTUBS_ENTRY TranslateFilePath@16, 16
SYSSTUBS_ENTRY UmsThreadYield@4, 4
SYSSTUBS_ENTRY UnloadDriver@4, 4
SYSSTUBS_ENTRY UnloadKey@4, 4
SYSSTUBS_ENTRY UnloadKey2@8, 8
SYSSTUBS_ENTRY UnloadKeyEx@8, 8
SYSSTUBS_ENTRY UnlockFile@20, 20
SYSSTUBS_ENTRY UnlockVirtualMemory@16, 16
SYSSTUBS_ENTRY UnmapViewOfSection@8, 8
SYSSTUBS_ENTRY UnmapViewOfSectionEx@12, 12
SYSSTUBS_ENTRY UnsubscribeWnfStateChange@4, 4
SYSSTUBS_ENTRY UpdateWnfStateData@28, 28
SYSSTUBS_ENTRY VdmControl@8, 8
SYSSTUBS_ENTRY WaitForAlertByThreadId@8, 8
SYSSTUBS_ENTRY WaitForDebugEvent@16, 16
SYSSTUBS_ENTRY WaitForKeyedEvent@16, 16
SYSSTUBS_ENTRY WaitForMultipleObjects@20, 20
SYSSTUBS_ENTRY WaitForMultipleObjects32@20, 20
SYSSTUBS_ENTRY WaitForSingleObject@12, 12
SYSSTUBS_ENTRY WaitForWnfNotifications@0
SYSSTUBS_ENTRY WaitForWorkViaWorkerFactory@20, 20
SYSSTUBS_ENTRY WaitHighEventPair@4, 4
SYSSTUBS_ENTRY WaitLowEventPair@4, 4
SYSSTUBS_ENTRY WorkerFactoryWorkerReady@4, 4
SYSSTUBS_ENTRY WriteFile@36, 36
SYSSTUBS_ENTRY WriteFileGather@36, 36
SYSSTUBS_ENTRY WriteRequestData@24, 24
SYSSTUBS_ENTRY WriteVirtualMemory@20, 20
SYSSTUBS_ENTRY YieldExecution@0

_StubsBridge@0 :
                        ; [esp + 4] caller
    pushfd              ; save eflag
    call BuildStubs
    popfd               ; restore eflag
    ret                 ; jmp caller (now the stubs table is ajust to system function)
DB  24 dup (0cch)

_TEXT$00 ENDS

END
