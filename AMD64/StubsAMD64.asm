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

    .XLIST
INCLUDE DEFS.INC
INCLUDE KSAMD64.INC
    .LIST

OPTION CASEMAP:NONE

BuildServiceDispatchTable PROTO

_DATA$00 SEGMENT PAGE 'DATA'

_DATA$00 ENDS

_TEXT$00 SEGMENT PAGE 'CODE'

STUBS_ENTRY macro Name

    Stub&Name :

            mov rax, Stub&Name      ; save IP
            push rax
            mov rax, StubsBridge
            jmp rax

        DB  38 dup (0cch)
            
            int 3

    PUBLIC Stub&Name

ENDM

ServiceDispatchTable :
PUBLIC ServiceDispatchTable

STUBS_ENTRY AcceptConnectPort

align 40h

STUBS_ENTRY AccessCheck

align 40h

STUBS_ENTRY AccessCheckAndAuditAlarm

align 40h

STUBS_ENTRY AccessCheckByType

align 40h

STUBS_ENTRY AccessCheckByTypeAndAuditAlarm

align 40h

STUBS_ENTRY AccessCheckByTypeResultList

align 40h

STUBS_ENTRY AccessCheckByTypeResultListAndAuditAlarm

align 40h

STUBS_ENTRY AccessCheckByTypeResultListAndAuditAlarmByHandle

align 40h

STUBS_ENTRY AcquireCMFViewOwnership

align 40h

STUBS_ENTRY AcquireProcessActivityReference

align 40h

STUBS_ENTRY AddAtom

align 40h

STUBS_ENTRY AddAtomEx

align 40h

STUBS_ENTRY AddBootEntry

align 40h

STUBS_ENTRY AddDriverEntry

align 40h

STUBS_ENTRY AdjustGroupsToken

align 40h

STUBS_ENTRY AdjustPrivilegesToken

align 40h

STUBS_ENTRY AdjustTokenClaimsAndDeviceGroups

align 40h

STUBS_ENTRY AlertResumeThread

align 40h

STUBS_ENTRY AlertThread

align 40h

STUBS_ENTRY AlertThreadByThreadId

align 40h

STUBS_ENTRY AllocateLocallyUniqueId

align 40h

STUBS_ENTRY AllocateReserveObject

align 40h

STUBS_ENTRY AllocateUserPhysicalPages

align 40h

STUBS_ENTRY AllocateUuids

align 40h

STUBS_ENTRY AllocateVirtualMemory

align 40h

STUBS_ENTRY AllocateVirtualMemoryEx

align 40h

STUBS_ENTRY AlpcAcceptConnectPort

align 40h

STUBS_ENTRY AlpcCancelMessage

align 40h

STUBS_ENTRY AlpcConnectPort

align 40h

STUBS_ENTRY AlpcConnectPortEx

align 40h

STUBS_ENTRY AlpcCreatePort

align 40h

STUBS_ENTRY AlpcCreatePortSection

align 40h

STUBS_ENTRY AlpcCreateResourceReserve

align 40h

STUBS_ENTRY AlpcCreateSectionView

align 40h

STUBS_ENTRY AlpcCreateSecurityContext

align 40h

STUBS_ENTRY AlpcDeletePortSection

align 40h

STUBS_ENTRY AlpcDeleteResourceReserve

align 40h

STUBS_ENTRY AlpcDeleteSectionView

align 40h

STUBS_ENTRY AlpcDeleteSecurityContext

align 40h

STUBS_ENTRY AlpcDisconnectPort

align 40h

STUBS_ENTRY AlpcImpersonateClientContainerOfPort

align 40h

STUBS_ENTRY AlpcImpersonateClientOfPort

align 40h

STUBS_ENTRY AlpcOpenSenderProcess

align 40h

STUBS_ENTRY AlpcOpenSenderThread

align 40h

STUBS_ENTRY AlpcQueryInformation

align 40h

STUBS_ENTRY AlpcQueryInformationMessage

align 40h

STUBS_ENTRY AlpcRevokeSecurityContext

align 40h

STUBS_ENTRY AlpcSendWaitReceivePort

align 40h

STUBS_ENTRY AlpcSetInformation

align 40h

STUBS_ENTRY ApphelpCacheContro

align 40h

STUBS_ENTRY AreMappedFilesTheSame

align 40h

STUBS_ENTRY AssignProcessToJobObject

align 40h

STUBS_ENTRY AssociateWaitCompletionPacket

align 40h

STUBS_ENTRY CallEnclave

align 40h

STUBS_ENTRY CallbackReturn

align 40h

STUBS_ENTRY CancelDeviceWakeupRequest

align 40h

STUBS_ENTRY CancelIoFile

align 40h

STUBS_ENTRY CancelIoFileEx

align 40h

STUBS_ENTRY CancelSynchronousIoFile

align 40h

STUBS_ENTRY CancelTimer

align 40h

STUBS_ENTRY CancelTimer2

align 40h

STUBS_ENTRY CancelWaitCompletionPacket

align 40h

STUBS_ENTRY ClearAllSavepointsTransaction

align 40h

STUBS_ENTRY ClearEvent

align 40h

STUBS_ENTRY ClearSavepointTransaction

align 40h

STUBS_ENTRY Close

align 40h

STUBS_ENTRY CloseObjectAuditAlarm

align 40h

STUBS_ENTRY CommitComplete

align 40h

STUBS_ENTRY CommitEnlistment

align 40h

STUBS_ENTRY CommitRegistryTransaction

align 40h

STUBS_ENTRY CommitTransaction

align 40h

STUBS_ENTRY CompactKeys

align 40h

STUBS_ENTRY CompareObjects

align 40h

STUBS_ENTRY CompareSigningLevels

align 40h

STUBS_ENTRY CompareTokens

align 40h

STUBS_ENTRY CompleteConnectPort

align 40h

STUBS_ENTRY CompressKey

align 40h

STUBS_ENTRY ConnectPort

align 40h

STUBS_ENTRY Continue

align 40h

STUBS_ENTRY ConvertBetweenAuxiliaryCounterAndPerformanceCounter

align 40h

STUBS_ENTRY CreateDebugObject

align 40h

STUBS_ENTRY CreateDirectoryObject

align 40h

STUBS_ENTRY CreateDirectoryObjectEx

align 40h

STUBS_ENTRY CreateEnclave

align 40h

STUBS_ENTRY CreateEnlistment

align 40h

STUBS_ENTRY CreateEvent

align 40h

STUBS_ENTRY CreateEventPair

align 40h

STUBS_ENTRY CreateFile

align 40h

STUBS_ENTRY CreateIRTimer

align 40h

STUBS_ENTRY CreateIoCompletion

align 40h

STUBS_ENTRY CreateJobObject

align 40h

STUBS_ENTRY CreateJobSet

align 40h

STUBS_ENTRY CreateKey

align 40h

STUBS_ENTRY CreateKeyTransacted

align 40h

STUBS_ENTRY CreateKeyedEvent

align 40h

STUBS_ENTRY CreateLowBoxToken

align 40h

STUBS_ENTRY CreateMailslotFile

align 40h

STUBS_ENTRY CreateMutant

align 40h

STUBS_ENTRY CreateNamedPipeFile

align 40h

STUBS_ENTRY CreatePagingFile

align 40h

STUBS_ENTRY CreatePartition

align 40h

STUBS_ENTRY CreatePort

align 40h

STUBS_ENTRY CreatePrivateNamespace

align 40h

STUBS_ENTRY CreateProcess

align 40h

STUBS_ENTRY CreateProcessEx

align 40h

STUBS_ENTRY CreateProfile

align 40h

STUBS_ENTRY CreateProfileEx

align 40h

STUBS_ENTRY CreateRegistryTransaction

align 40h

STUBS_ENTRY CreateResourceManager

align 40h

STUBS_ENTRY CreateSection

align 40h

STUBS_ENTRY CreateSemaphore

align 40h

STUBS_ENTRY CreateSymbolicLinkObject

align 40h

STUBS_ENTRY CreateThread

align 40h

STUBS_ENTRY CreateThreadEx

align 40h

STUBS_ENTRY CreateTimer

align 40h

STUBS_ENTRY CreateTimer2

align 40h

STUBS_ENTRY CreateToken

align 40h

STUBS_ENTRY CreateTokenEx

align 40h

STUBS_ENTRY CreateTransaction

align 40h

STUBS_ENTRY CreateTransactionManager

align 40h

STUBS_ENTRY CreateUserProcess

align 40h

STUBS_ENTRY CreateWaitCompletionPacket

align 40h

STUBS_ENTRY CreateWaitablePort

align 40h

STUBS_ENTRY CreateWnfStateName

align 40h

STUBS_ENTRY CreateWorkerFactory

align 40h

STUBS_ENTRY DebugActiveProcess

align 40h

STUBS_ENTRY DebugContinue

align 40h

STUBS_ENTRY DelayExecution

align 40h

STUBS_ENTRY DeleteAtom

align 40h

STUBS_ENTRY DeleteBootEntry

align 40h

STUBS_ENTRY DeleteDriverEntry

align 40h

STUBS_ENTRY DeleteFile

align 40h

STUBS_ENTRY DeleteKey

align 40h

STUBS_ENTRY DeleteObjectAuditAlarm

align 40h

STUBS_ENTRY DeletePrivateNamespace

align 40h

STUBS_ENTRY DeleteValueKey

align 40h

STUBS_ENTRY DeleteWnfStateData

align 40h

STUBS_ENTRY DeleteWnfStateName

align 40h

STUBS_ENTRY DeviceIoControlFile

align 40h

STUBS_ENTRY DisableLastKnownGood

align 40h

STUBS_ENTRY DisplayString

align 40h

STUBS_ENTRY DrawText

align 40h

STUBS_ENTRY DuplicateObject

align 40h

STUBS_ENTRY DuplicateToken

align 40h

STUBS_ENTRY EnableLastKnownGood

align 40h

STUBS_ENTRY EnumerateBootEntries

align 40h

STUBS_ENTRY EnumerateDriverEntries

align 40h

STUBS_ENTRY EnumerateKey

align 40h

STUBS_ENTRY EnumerateSystemEnvironmentValuesEx

align 40h

STUBS_ENTRY EnumerateTransactionObject

align 40h

STUBS_ENTRY EnumerateValueKey

align 40h

STUBS_ENTRY ExtendSection

align 40h

STUBS_ENTRY FilterBootOption

align 40h

STUBS_ENTRY FilterToken

align 40h

STUBS_ENTRY FilterTokenEx

align 40h

STUBS_ENTRY FindAtom

align 40h

STUBS_ENTRY FlushBuffersFile

align 40h

STUBS_ENTRY FlushBuffersFileEx

align 40h

STUBS_ENTRY FlushInstallUILanguage

align 40h

STUBS_ENTRY FlushInstructionCache

align 40h

STUBS_ENTRY FlushKey

align 40h

STUBS_ENTRY FlushProcessWriteBuffers

align 40h

STUBS_ENTRY FlushVirtualMemory

align 40h

STUBS_ENTRY FlushWriteBuffer

align 40h

STUBS_ENTRY FreeUserPhysicalPages

align 40h

STUBS_ENTRY FreeVirtualMemory

align 40h

STUBS_ENTRY FreezeRegistry

align 40h

STUBS_ENTRY FreezeTransactions

align 40h

STUBS_ENTRY FsControlFile

align 40h

STUBS_ENTRY GetCachedSigningLeve

align 40h

STUBS_ENTRY GetCompleteWnfStateSubscription

align 40h

STUBS_ENTRY GetContextThread

align 40h

STUBS_ENTRY GetCurrentProcessorNumber

align 40h

STUBS_ENTRY GetCurrentProcessorNumberEx

align 40h

STUBS_ENTRY GetDevicePowerState

align 40h

STUBS_ENTRY GetMUIRegistryInfo

align 40h

STUBS_ENTRY GetNextProcess

align 40h

STUBS_ENTRY GetNextThread

align 40h

STUBS_ENTRY GetNlsSectionPtr

align 40h

STUBS_ENTRY GetNotificationResourceManager

align 40h

STUBS_ENTRY GetPlugPlayEvent

align 40h

STUBS_ENTRY GetWriteWatch

align 40h

STUBS_ENTRY ImpersonateAnonymousToken

align 40h

STUBS_ENTRY ImpersonateClientOfPort

align 40h

STUBS_ENTRY ImpersonateThread

align 40h

STUBS_ENTRY InitializeEnclave

align 40h

STUBS_ENTRY InitializeNlsFiles

align 40h

STUBS_ENTRY InitializeRegistry

align 40h

STUBS_ENTRY InitiatePowerAction

align 40h

STUBS_ENTRY IsProcessInJob

align 40h

STUBS_ENTRY IsSystemResumeAutomatic

align 40h

STUBS_ENTRY IsUILanguageComitted

align 40h

STUBS_ENTRY ListTransactions

align 40h

STUBS_ENTRY ListenPort

align 40h

STUBS_ENTRY LoadDriver

align 40h

STUBS_ENTRY LoadEnclaveData

align 40h

STUBS_ENTRY LoadHotPatch

align 40h

STUBS_ENTRY LoadKey

align 40h

STUBS_ENTRY LoadKey2

align 40h

STUBS_ENTRY LoadKeyEx

align 40h

STUBS_ENTRY LockFile

align 40h

STUBS_ENTRY LockProductActivationKeys

align 40h

STUBS_ENTRY LockRegistryKey

align 40h

STUBS_ENTRY LockVirtualMemory

align 40h

STUBS_ENTRY MakePermanentObject

align 40h

STUBS_ENTRY MakeTemporaryObject

align 40h

STUBS_ENTRY ManagePartition

align 40h

STUBS_ENTRY MapCMFModule

align 40h

STUBS_ENTRY MapUserPhysicalPages

align 40h

STUBS_ENTRY MapUserPhysicalPagesScatter

align 40h

STUBS_ENTRY MapViewOfSection

align 40h

STUBS_ENTRY MapViewOfSectionEx

align 40h

STUBS_ENTRY MarshallTransaction

align 40h

STUBS_ENTRY ModifyBootEntry

align 40h

STUBS_ENTRY ModifyDriverEntry

align 40h

STUBS_ENTRY NotifyChangeDirectoryFile

align 40h

STUBS_ENTRY NotifyChangeDirectoryFileEx

align 40h

STUBS_ENTRY NotifyChangeKey

align 40h

STUBS_ENTRY NotifyChangeMultipleKeys

align 40h

STUBS_ENTRY NotifyChangeSession

align 40h

STUBS_ENTRY OpenDirectoryObject

align 40h

STUBS_ENTRY OpenEnlistment

align 40h

STUBS_ENTRY OpenEvent

align 40h

STUBS_ENTRY OpenEventPair

align 40h

STUBS_ENTRY OpenFile

align 40h

STUBS_ENTRY OpenIoCompletion

align 40h

STUBS_ENTRY OpenJobObject

align 40h

STUBS_ENTRY OpenKey

align 40h

STUBS_ENTRY OpenKeyEx

align 40h

STUBS_ENTRY OpenKeyTransacted

align 40h

STUBS_ENTRY OpenKeyTransactedEx

align 40h

STUBS_ENTRY OpenKeyedEvent

align 40h

STUBS_ENTRY OpenMutant

align 40h

STUBS_ENTRY OpenObjectAuditAlarm

align 40h

STUBS_ENTRY OpenPartition

align 40h

STUBS_ENTRY OpenPrivateNamespace

align 40h

STUBS_ENTRY OpenProcess

align 40h

STUBS_ENTRY OpenProcessToken

align 40h

STUBS_ENTRY OpenProcessTokenEx

align 40h

STUBS_ENTRY OpenRegistryTransaction

align 40h

STUBS_ENTRY OpenResourceManager

align 40h

STUBS_ENTRY OpenSection

align 40h

STUBS_ENTRY OpenSemaphore

align 40h

STUBS_ENTRY OpenSession

align 40h

STUBS_ENTRY OpenSymbolicLinkObject

align 40h

STUBS_ENTRY OpenThread

align 40h

STUBS_ENTRY OpenThreadToken

align 40h

STUBS_ENTRY OpenThreadTokenEx

align 40h

STUBS_ENTRY OpenTimer

align 40h

STUBS_ENTRY OpenTransaction

align 40h

STUBS_ENTRY OpenTransactionManager

align 40h

STUBS_ENTRY PlugPlayContro

align 40h

STUBS_ENTRY PowerInformation

align 40h

STUBS_ENTRY PrePrepareComplete

align 40h

STUBS_ENTRY PrePrepareEnlistment

align 40h

STUBS_ENTRY PrepareComplete

align 40h

STUBS_ENTRY PrepareEnlistment

align 40h

STUBS_ENTRY PrivilegeCheck

align 40h

STUBS_ENTRY PrivilegeObjectAuditAlarm

align 40h

STUBS_ENTRY PrivilegedServiceAuditAlarm

align 40h

STUBS_ENTRY PropagationComplete

align 40h

STUBS_ENTRY PropagationFailed

align 40h

STUBS_ENTRY ProtectVirtualMemory

align 40h

STUBS_ENTRY PullTransaction

align 40h

STUBS_ENTRY PulseEvent

align 40h

STUBS_ENTRY QueryAttributesFile

align 40h

STUBS_ENTRY QueryAuxiliaryCounterFrequency

align 40h

STUBS_ENTRY QueryBootEntryOrder

align 40h

STUBS_ENTRY QueryBootOptions

align 40h

STUBS_ENTRY QueryDebugFilterState

align 40h

STUBS_ENTRY QueryDefaultLocale

align 40h

STUBS_ENTRY QueryDefaultUILanguage

align 40h

STUBS_ENTRY QueryDirectoryFile

align 40h

STUBS_ENTRY QueryDirectoryFileEx

align 40h

STUBS_ENTRY QueryDirectoryObject

align 40h

STUBS_ENTRY QueryDriverEntryOrder

align 40h

STUBS_ENTRY QueryEaFile

align 40h

STUBS_ENTRY QueryEvent

align 40h

STUBS_ENTRY QueryFullAttributesFile

align 40h

STUBS_ENTRY QueryInformationAtom

align 40h

STUBS_ENTRY QueryInformationByName

align 40h

STUBS_ENTRY QueryInformationEnlistment

align 40h

STUBS_ENTRY QueryInformationFile

align 40h

STUBS_ENTRY QueryInformationJobObject

align 40h

STUBS_ENTRY QueryInformationPort

align 40h

STUBS_ENTRY QueryInformationProcess

align 40h

STUBS_ENTRY QueryInformationResourceManager

align 40h

STUBS_ENTRY QueryInformationThread

align 40h

STUBS_ENTRY QueryInformationToken

align 40h

STUBS_ENTRY QueryInformationTransaction

align 40h

STUBS_ENTRY QueryInformationTransactionManager

align 40h

STUBS_ENTRY QueryInformationWorkerFactory

align 40h

STUBS_ENTRY QueryInstallUILanguage

align 40h

STUBS_ENTRY QueryIntervalProfile

align 40h

STUBS_ENTRY QueryIoCompletion

align 40h

STUBS_ENTRY QueryKey

align 40h

STUBS_ENTRY QueryLicenseValue

align 40h

STUBS_ENTRY QueryMultipleValueKey

align 40h

STUBS_ENTRY QueryMutant

align 40h

STUBS_ENTRY QueryObject

align 40h

STUBS_ENTRY QueryOpenSubKeys

align 40h

STUBS_ENTRY QueryOpenSubKeysEx

align 40h

STUBS_ENTRY QueryPerformanceCounter

align 40h

STUBS_ENTRY QueryPortInformationProcess

align 40h

STUBS_ENTRY QueryQuotaInformationFile

align 40h

STUBS_ENTRY QuerySection

align 40h

STUBS_ENTRY QuerySecurityAttributesToken

align 40h

STUBS_ENTRY QuerySecurityObject

align 40h

STUBS_ENTRY QuerySecurityPolicy

align 40h

STUBS_ENTRY QuerySemaphore

align 40h

STUBS_ENTRY QuerySymbolicLinkObject

align 40h

STUBS_ENTRY QuerySystemEnvironmentValue

align 40h

STUBS_ENTRY QuerySystemEnvironmentValueEx

align 40h

STUBS_ENTRY QuerySystemInformation

align 40h

STUBS_ENTRY QuerySystemInformationEx

align 40h

STUBS_ENTRY QuerySystemTime

align 40h

STUBS_ENTRY QueryTimer

align 40h

STUBS_ENTRY QueryTimerResolution

align 40h

STUBS_ENTRY QueryValueKey

align 40h

STUBS_ENTRY QueryVirtualMemory

align 40h

STUBS_ENTRY QueryVolumeInformationFile

align 40h

STUBS_ENTRY QueryWnfStateData

align 40h

STUBS_ENTRY QueryWnfStateNameInformation

align 40h

STUBS_ENTRY QueueApcThread

align 40h

STUBS_ENTRY QueueApcThreadEx

align 40h

STUBS_ENTRY RaiseException

align 40h

STUBS_ENTRY RaiseHardError

align 40h

STUBS_ENTRY ReadFile

align 40h

STUBS_ENTRY ReadFileScatter

align 40h

STUBS_ENTRY ReadOnlyEnlistment

align 40h

STUBS_ENTRY ReadRequestData

align 40h

STUBS_ENTRY ReadVirtualMemory

align 40h

STUBS_ENTRY RecoverEnlistment

align 40h

STUBS_ENTRY RecoverResourceManager

align 40h

STUBS_ENTRY RecoverTransactionManager

align 40h

STUBS_ENTRY RegisterProtocolAddressInformation

align 40h

STUBS_ENTRY RegisterThreadTerminatePort

align 40h

STUBS_ENTRY ReleaseCMFViewOwnership

align 40h

STUBS_ENTRY ReleaseKeyedEvent

align 40h

STUBS_ENTRY ReleaseMutant

align 40h

STUBS_ENTRY ReleaseSemaphore

align 40h

STUBS_ENTRY ReleaseWorkerFactoryWorker

align 40h

STUBS_ENTRY RemoveIoCompletion

align 40h

STUBS_ENTRY RemoveIoCompletionEx

align 40h

STUBS_ENTRY RemoveProcessDebug

align 40h

STUBS_ENTRY RenameKey

align 40h

STUBS_ENTRY RenameTransactionManager

align 40h

STUBS_ENTRY ReplaceKey

align 40h

STUBS_ENTRY ReplacePartitionUnit

align 40h

STUBS_ENTRY ReplyPort

align 40h

STUBS_ENTRY ReplyWaitReceivePort

align 40h

STUBS_ENTRY ReplyWaitReceivePortEx

align 40h

STUBS_ENTRY ReplyWaitReplyPort

align 40h

STUBS_ENTRY RequestDeviceWakeup

align 40h

STUBS_ENTRY RequestPort

align 40h

STUBS_ENTRY RequestWaitReplyPort

align 40h

STUBS_ENTRY RequestWakeupLatency

align 40h

STUBS_ENTRY ResetEvent

align 40h

STUBS_ENTRY ResetWriteWatch

align 40h

STUBS_ENTRY RestoreKey

align 40h

STUBS_ENTRY ResumeProcess

align 40h

STUBS_ENTRY ResumeThread

align 40h

STUBS_ENTRY RevertContainerImpersonation

align 40h

STUBS_ENTRY RollbackComplete

align 40h

STUBS_ENTRY RollbackEnlistment

align 40h

STUBS_ENTRY RollbackRegistryTransaction

align 40h

STUBS_ENTRY RollbackSavepointTransaction

align 40h

STUBS_ENTRY RollbackTransaction

align 40h

STUBS_ENTRY RollforwardTransactionManager

align 40h

STUBS_ENTRY SaveKey

align 40h

STUBS_ENTRY SaveKeyEx

align 40h

STUBS_ENTRY SaveMergedKeys

align 40h

STUBS_ENTRY SavepointComplete

align 40h

STUBS_ENTRY SavepointTransaction

align 40h

STUBS_ENTRY SecureConnectPort

align 40h

STUBS_ENTRY SerializeBoot

align 40h

STUBS_ENTRY SetBootEntryOrder

align 40h

STUBS_ENTRY SetBootOptions

align 40h

STUBS_ENTRY SetCachedSigningLeve

align 40h

STUBS_ENTRY SetCachedSigningLevel2

align 40h

STUBS_ENTRY SetContextThread

align 40h

STUBS_ENTRY SetDebugFilterState

align 40h

STUBS_ENTRY SetDefaultHardErrorPort

align 40h

STUBS_ENTRY SetDefaultLocale

align 40h

STUBS_ENTRY SetDefaultUILanguage

align 40h

STUBS_ENTRY SetDriverEntryOrder

align 40h

STUBS_ENTRY SetEaFile

align 40h

STUBS_ENTRY SetEvent

align 40h

STUBS_ENTRY SetEventBoostPriority

align 40h

STUBS_ENTRY SetHighEventPair

align 40h

STUBS_ENTRY SetHighWaitLowEventPair

align 40h

STUBS_ENTRY SetIRTimer

align 40h

STUBS_ENTRY SetInformationDebugObject

align 40h

STUBS_ENTRY SetInformationEnlistment

align 40h

STUBS_ENTRY SetInformationFile

align 40h

STUBS_ENTRY SetInformationJobObject

align 40h

STUBS_ENTRY SetInformationKey

align 40h

STUBS_ENTRY SetInformationObject

align 40h

STUBS_ENTRY SetInformationProcess

align 40h

STUBS_ENTRY SetInformationResourceManager

align 40h

STUBS_ENTRY SetInformationSymbolicLink

align 40h

STUBS_ENTRY SetInformationThread

align 40h

STUBS_ENTRY SetInformationToken

align 40h

STUBS_ENTRY SetInformationTransaction

align 40h

STUBS_ENTRY SetInformationTransactionManager

align 40h

STUBS_ENTRY SetInformationVirtualMemory

align 40h

STUBS_ENTRY SetInformationWorkerFactory

align 40h

STUBS_ENTRY SetIntervalProfile

align 40h

STUBS_ENTRY SetIoCompletion

align 40h

STUBS_ENTRY SetIoCompletionEx

align 40h

STUBS_ENTRY SetLdtEntries

align 40h

STUBS_ENTRY SetLowEventPair

align 40h

STUBS_ENTRY SetLowWaitHighEventPair

align 40h

STUBS_ENTRY SetQuotaInformationFile

align 40h

STUBS_ENTRY SetSecurityObject

align 40h

STUBS_ENTRY SetSystemEnvironmentValue

align 40h

STUBS_ENTRY SetSystemEnvironmentValueEx

align 40h

STUBS_ENTRY SetSystemInformation

align 40h

STUBS_ENTRY SetSystemPowerState

align 40h

STUBS_ENTRY SetSystemTime

align 40h

STUBS_ENTRY SetThreadExecutionState

align 40h

STUBS_ENTRY SetTimer

align 40h

STUBS_ENTRY SetTimer2

align 40h

STUBS_ENTRY SetTimerEx

align 40h

STUBS_ENTRY SetTimerResolution

align 40h

STUBS_ENTRY SetUuidSeed

align 40h

STUBS_ENTRY SetValueKey

align 40h

STUBS_ENTRY SetVolumeInformationFile

align 40h

STUBS_ENTRY SetWnfProcessNotificationEvent

align 40h

STUBS_ENTRY ShutdownSystem

align 40h

STUBS_ENTRY ShutdownWorkerFactory

align 40h

STUBS_ENTRY SignalAndWaitForSingleObject

align 40h

STUBS_ENTRY SinglePhaseReject

align 40h

STUBS_ENTRY StartProfile

align 40h

STUBS_ENTRY StartTm

align 40h

STUBS_ENTRY StopProfile

align 40h

STUBS_ENTRY SubscribeWnfStateChange

align 40h

STUBS_ENTRY SuspendProcess

align 40h

STUBS_ENTRY SuspendThread

align 40h

STUBS_ENTRY SystemDebugContro

align 40h

STUBS_ENTRY TerminateEnclave

align 40h

STUBS_ENTRY TerminateJobObject

align 40h

STUBS_ENTRY TerminateProcess

align 40h

STUBS_ENTRY TerminateThread

align 40h

STUBS_ENTRY TestAlert

align 40h

STUBS_ENTRY ThawRegistry

align 40h

STUBS_ENTRY ThawTransactions

align 40h

STUBS_ENTRY TraceContro

align 40h

STUBS_ENTRY TraceEvent

align 40h

STUBS_ENTRY TranslateFilePath

align 40h

STUBS_ENTRY UmsThreadYield

align 40h

STUBS_ENTRY UnloadDriver

align 40h

STUBS_ENTRY UnloadKey

align 40h

STUBS_ENTRY UnloadKey2

align 40h

STUBS_ENTRY UnloadKeyEx

align 40h

STUBS_ENTRY UnlockFile

align 40h

STUBS_ENTRY UnlockVirtualMemory

align 40h

STUBS_ENTRY UnmapViewOfSection

align 40h

STUBS_ENTRY UnmapViewOfSectionEx

align 40h

STUBS_ENTRY UnsubscribeWnfStateChange

align 40h

STUBS_ENTRY UpdateWnfStateData

align 40h

STUBS_ENTRY VdmContro

align 40h

STUBS_ENTRY WaitForAlertByThreadId

align 40h

STUBS_ENTRY WaitForDebugEvent

align 40h

STUBS_ENTRY WaitForKeyedEvent

align 40h

STUBS_ENTRY WaitForMultipleObjects

align 40h

STUBS_ENTRY WaitForMultipleObjects32

align 40h

STUBS_ENTRY WaitForSingleObject

align 40h

STUBS_ENTRY WaitForWnfNotifications

align 40h

STUBS_ENTRY WaitForWorkViaWorkerFactory

align 40h

STUBS_ENTRY WaitHighEventPair

align 40h

STUBS_ENTRY WaitLowEventPair

align 40h

STUBS_ENTRY WorkerFactoryWorkerReady

align 40h

STUBS_ENTRY WriteFile

align 40h

STUBS_ENTRY WriteFileGather

align 40h

STUBS_ENTRY WriteRequestData

align 40h

STUBS_ENTRY WriteVirtualMemory

align 40h

STUBS_ENTRY YieldExecution

align 40h

StubsBridge :

                            ; [rsp + 8] caller
    mov [rsp + 28h], r9     ;
    mov [rsp + 20h], r8     ;
    mov [rsp + 18h], rdx    ;
    mov [rsp + 10h], rcx    ; save argument register

    sub rsp, 28h

    pushfq

    call BuildServiceDispatchTable

    popfq

    add rsp, 28h

    mov rcx, [rsp + 10h]    ; restore argument register
    mov rdx, [rsp + 18h]
    mov r8, [rsp + 20h]
    mov r9, [rsp + 28h]

    ret                     ; jmp caller (now the stubs table is ajust to system function)

DB  7 dup (0cch)

align 40h

PUBLIC StubsBridge

_TEXT$00 ENDS

END
