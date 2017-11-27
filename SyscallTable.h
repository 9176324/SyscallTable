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

#ifndef _KERNEL_MODE_SYSCALLTABLE_H
#define _KERNEL_MODE_SYSCALLTABLE_H

typedef enum _KSE_SERVICE_DESCRIPTOR_TABLE_CLASS
{
    SeIndexZwAcceptConnectPort,
    SeIndexZwAccessCheck,
    SeIndexZwAccessCheckAndAuditAlarm,
    SeIndexZwAccessCheckByType,
    SeIndexZwAccessCheckByTypeAndAuditAlarm,
    SeIndexZwAccessCheckByTypeResultList,
    SeIndexZwAccessCheckByTypeResultListAndAuditAlarm,
    SeIndexZwAccessCheckByTypeResultListAndAuditAlarmByHandle,
    SeIndexZwAcquireCMFViewOwnership,
    SeIndexZwAcquireProcessActivityReference,
    SeIndexZwAddAtom,
    SeIndexZwAddAtomEx,
    SeIndexZwAddBootEntry,
    SeIndexZwAddDriverEntry,
    SeIndexZwAdjustGroupsToken,
    SeIndexZwAdjustPrivilegesToken,
    SeIndexZwAdjustTokenClaimsAndDeviceGroups,
    SeIndexZwAlertResumeThread,
    SeIndexZwAlertThread,
    SeIndexZwAlertThreadByThreadId,
    SeIndexZwAllocateLocallyUniqueId,
    SeIndexZwAllocateReserveObject,
    SeIndexZwAllocateUserPhysicalPages,
    SeIndexZwAllocateUuids,
    SeIndexZwAllocateVirtualMemory,
    SeIndexZwAlpcAcceptConnectPort,
    SeIndexZwAlpcCancelMessage,
    SeIndexZwAlpcConnectPort,
    SeIndexZwAlpcConnectPortEx,
    SeIndexZwAlpcCreatePort,
    SeIndexZwAlpcCreatePortSection,
    SeIndexZwAlpcCreateResourceReserve,
    SeIndexZwAlpcCreateSectionView,
    SeIndexZwAlpcCreateSecurityContext,
    SeIndexZwAlpcDeletePortSection,
    SeIndexZwAlpcDeleteResourceReserve,
    SeIndexZwAlpcDeleteSectionView,
    SeIndexZwAlpcDeleteSecurityContext,
    SeIndexZwAlpcDisconnectPort,
    SeIndexZwAlpcImpersonateClientContainerOfPort,
    SeIndexZwAlpcImpersonateClientOfPort,
    SeIndexZwAlpcOpenSenderProcess,
    SeIndexZwAlpcOpenSenderThread,
    SeIndexZwAlpcQueryInformation,
    SeIndexZwAlpcQueryInformationMessage,
    SeIndexZwAlpcRevokeSecurityContext,
    SeIndexZwAlpcSendWaitReceivePort,
    SeIndexZwAlpcSetInformation,
    SeIndexZwApphelpCacheControl,
    SeIndexZwAreMappedFilesTheSame,
    SeIndexZwAssignProcessToJobObject,
    SeIndexZwAssociateWaitCompletionPacket,
    SeIndexZwCallEnclave,
    SeIndexZwCallbackReturn,
    SeIndexZwCancelDeviceWakeupRequest,
    SeIndexZwCancelIoFile,
    SeIndexZwCancelIoFileEx,
    SeIndexZwCancelSynchronousIoFile,
    SeIndexZwCancelTimer,
    SeIndexZwCancelTimer2,
    SeIndexZwCancelWaitCompletionPacket,
    SeIndexZwClearAllSavepointsTransaction,
    SeIndexZwClearEvent,
    SeIndexZwClearSavepointTransaction,
    SeIndexZwClose,
    SeIndexZwCloseObjectAuditAlarm,
    SeIndexZwCommitComplete,
    SeIndexZwCommitEnlistment,
    SeIndexZwCommitRegistryTransaction,
    SeIndexZwCommitTransaction,
    SeIndexZwCompactKeys,
    SeIndexZwCompareObjects,
    SeIndexZwCompareSigningLevels,
    SeIndexZwCompareTokens,
    SeIndexZwCompleteConnectPort,
    SeIndexZwCompressKey,
    SeIndexZwConnectPort,
    SeIndexZwContinue,
    SeIndexZwConvertBetweenAuxiliaryCounterAndPerformanceCounter,
    SeIndexZwCreateDebugObject,
    SeIndexZwCreateDirectoryObject,
    SeIndexZwCreateDirectoryObjectEx,
    SeIndexZwCreateEnclave,
    SeIndexZwCreateEnlistment,
    SeIndexZwCreateEvent,
    SeIndexZwCreateEventPair,
    SeIndexZwCreateFile,
    SeIndexZwCreateIRTimer,
    SeIndexZwCreateIoCompletion,
    SeIndexZwCreateJobObject,
    SeIndexZwCreateJobSet,
    SeIndexZwCreateKey,
    SeIndexZwCreateKeyTransacted,
    SeIndexZwCreateKeyedEvent,
    SeIndexZwCreateLowBoxToken,
    SeIndexZwCreateMailslotFile,
    SeIndexZwCreateMutant,
    SeIndexZwCreateNamedPipeFile,
    SeIndexZwCreatePagingFile,
    SeIndexZwCreatePartition,
    SeIndexZwCreatePort,
    SeIndexZwCreatePrivateNamespace,
    SeIndexZwCreateProcess,
    SeIndexZwCreateProcessEx,
    SeIndexZwCreateProfile,
    SeIndexZwCreateProfileEx,
    SeIndexZwCreateRegistryTransaction,
    SeIndexZwCreateResourceManager,
    SeIndexZwCreateSection,
    SeIndexZwCreateSemaphore,
    SeIndexZwCreateSymbolicLinkObject,
    SeIndexZwCreateThread,
    SeIndexZwCreateThreadEx,
    SeIndexZwCreateTimer,
    SeIndexZwCreateTimer2,
    SeIndexZwCreateToken,
    SeIndexZwCreateTokenEx,
    SeIndexZwCreateTransaction,
    SeIndexZwCreateTransactionManager,
    SeIndexZwCreateUserProcess,
    SeIndexZwCreateWaitCompletionPacket,
    SeIndexZwCreateWaitablePort,
    SeIndexZwCreateWnfStateName,
    SeIndexZwCreateWorkerFactory,
    SeIndexZwDebugActiveProcess,
    SeIndexZwDebugContinue,
    SeIndexZwDelayExecution,
    SeIndexZwDeleteAtom,
    SeIndexZwDeleteBootEntry,
    SeIndexZwDeleteDriverEntry,
    SeIndexZwDeleteFile,
    SeIndexZwDeleteKey,
    SeIndexZwDeleteObjectAuditAlarm,
    SeIndexZwDeletePrivateNamespace,
    SeIndexZwDeleteValueKey,
    SeIndexZwDeleteWnfStateData,
    SeIndexZwDeleteWnfStateName,
    SeIndexZwDeviceIoControlFile,
    SeIndexZwDisableLastKnownGood,
    SeIndexZwDisplayString,
    SeIndexZwDrawText,
    SeIndexZwDuplicateObject,
    SeIndexZwDuplicateToken,
    SeIndexZwEnableLastKnownGood,
    SeIndexZwEnumerateBootEntries,
    SeIndexZwEnumerateDriverEntries,
    SeIndexZwEnumerateKey,
    SeIndexZwEnumerateSystemEnvironmentValuesEx,
    SeIndexZwEnumerateTransactionObject,
    SeIndexZwEnumerateValueKey,
    SeIndexZwExtendSection,
    SeIndexZwFilterBootOption,
    SeIndexZwFilterToken,
    SeIndexZwFilterTokenEx,
    SeIndexZwFindAtom,
    SeIndexZwFlushBuffersFile,
    SeIndexZwFlushBuffersFileEx,
    SeIndexZwFlushInstallUILanguage,
    SeIndexZwFlushInstructionCache,
    SeIndexZwFlushKey,
    SeIndexZwFlushProcessWriteBuffers,
    SeIndexZwFlushVirtualMemory,
    SeIndexZwFlushWriteBuffer,
    SeIndexZwFreeUserPhysicalPages,
    SeIndexZwFreeVirtualMemory,
    SeIndexZwFreezeRegistry,
    SeIndexZwFreezeTransactions,
    SeIndexZwFsControlFile,
    SeIndexZwGetCachedSigningLevel,
    SeIndexZwGetCompleteWnfStateSubscription,
    SeIndexZwGetContextThread,
    SeIndexZwGetCurrentProcessorNumber,
    SeIndexZwGetCurrentProcessorNumberEx,
    SeIndexZwGetDevicePowerState,
    SeIndexZwGetMUIRegistryInfo,
    SeIndexZwGetNextProcess,
    SeIndexZwGetNextThread,
    SeIndexZwGetNlsSectionPtr,
    SeIndexZwGetNotificationResourceManager,
    SeIndexZwGetPlugPlayEvent,
    SeIndexZwGetWriteWatch,
    SeIndexZwImpersonateAnonymousToken,
    SeIndexZwImpersonateClientOfPort,
    SeIndexZwImpersonateThread,
    SeIndexZwInitializeEnclave,
    SeIndexZwInitializeNlsFiles,
    SeIndexZwInitializeRegistry,
    SeIndexZwInitiatePowerAction,
    SeIndexZwIsProcessInJob,
    SeIndexZwIsSystemResumeAutomatic,
    SeIndexZwIsUILanguageComitted,
    SeIndexZwListTransactions,
    SeIndexZwListenPort,
    SeIndexZwLoadDriver,
    SeIndexZwLoadEnclaveData,
    SeIndexZwLoadHotPatch,
    SeIndexZwLoadKey,
    SeIndexZwLoadKey2,
    SeIndexZwLoadKeyEx,
    SeIndexZwLockFile,
    SeIndexZwLockProductActivationKeys,
    SeIndexZwLockRegistryKey,
    SeIndexZwLockVirtualMemory,
    SeIndexZwMakePermanentObject,
    SeIndexZwMakeTemporaryObject,
    SeIndexZwManagePartition,
    SeIndexZwMapCMFModule,
    SeIndexZwMapUserPhysicalPages,
    SeIndexZwMapUserPhysicalPagesScatter,
    SeIndexZwMapViewOfSection,
    SeIndexZwMarshallTransaction,
    SeIndexZwModifyBootEntry,
    SeIndexZwModifyDriverEntry,
    SeIndexZwNotifyChangeDirectoryFile,
    SeIndexZwNotifyChangeDirectoryFileEx,
    SeIndexZwNotifyChangeKey,
    SeIndexZwNotifyChangeMultipleKeys,
    SeIndexZwNotifyChangeSession,
    SeIndexZwOpenDirectoryObject,
    SeIndexZwOpenEnlistment,
    SeIndexZwOpenEvent,
    SeIndexZwOpenEventPair,
    SeIndexZwOpenFile,
    SeIndexZwOpenIoCompletion,
    SeIndexZwOpenJobObject,
    SeIndexZwOpenKey,
    SeIndexZwOpenKeyEx,
    SeIndexZwOpenKeyTransacted,
    SeIndexZwOpenKeyTransactedEx,
    SeIndexZwOpenKeyedEvent,
    SeIndexZwOpenMutant,
    SeIndexZwOpenObjectAuditAlarm,
    SeIndexZwOpenPartition,
    SeIndexZwOpenPrivateNamespace,
    SeIndexZwOpenProcess,
    SeIndexZwOpenProcessToken,
    SeIndexZwOpenProcessTokenEx,
    SeIndexZwOpenRegistryTransaction,
    SeIndexZwOpenResourceManager,
    SeIndexZwOpenSection,
    SeIndexZwOpenSemaphore,
    SeIndexZwOpenSession,
    SeIndexZwOpenSymbolicLinkObject,
    SeIndexZwOpenThread,
    SeIndexZwOpenThreadToken,
    SeIndexZwOpenThreadTokenEx,
    SeIndexZwOpenTimer,
    SeIndexZwOpenTransaction,
    SeIndexZwOpenTransactionManager,
    SeIndexZwPlugPlayControl,
    SeIndexZwPowerInformation,
    SeIndexZwPrePrepareComplete,
    SeIndexZwPrePrepareEnlistment,
    SeIndexZwPrepareComplete,
    SeIndexZwPrepareEnlistment,
    SeIndexZwPrivilegeCheck,
    SeIndexZwPrivilegeObjectAuditAlarm,
    SeIndexZwPrivilegedServiceAuditAlarm,
    SeIndexZwPropagationComplete,
    SeIndexZwPropagationFailed,
    SeIndexZwProtectVirtualMemory,
    SeIndexZwPullTransaction,
    SeIndexZwPulseEvent,
    SeIndexZwQueryAttributesFile,
    SeIndexZwQueryAuxiliaryCounterFrequency,
    SeIndexZwQueryBootEntryOrder,
    SeIndexZwQueryBootOptions,
    SeIndexZwQueryDebugFilterState,
    SeIndexZwQueryDefaultLocale,
    SeIndexZwQueryDefaultUILanguage,
    SeIndexZwQueryDirectoryFile,
    SeIndexZwQueryDirectoryFileEx,
    SeIndexZwQueryDirectoryObject,
    SeIndexZwQueryDriverEntryOrder,
    SeIndexZwQueryEaFile,
    SeIndexZwQueryEvent,
    SeIndexZwQueryFullAttributesFile,
    SeIndexZwQueryInformationAtom,
    SeIndexZwQueryInformationByName,
    SeIndexZwQueryInformationEnlistment,
    SeIndexZwQueryInformationFile,
    SeIndexZwQueryInformationJobObject,
    SeIndexZwQueryInformationPort,
    SeIndexZwQueryInformationProcess,
    SeIndexZwQueryInformationResourceManager,
    SeIndexZwQueryInformationThread,
    SeIndexZwQueryInformationToken,
    SeIndexZwQueryInformationTransaction,
    SeIndexZwQueryInformationTransactionManager,
    SeIndexZwQueryInformationWorkerFactory,
    SeIndexZwQueryInstallUILanguage,
    SeIndexZwQueryIntervalProfile,
    SeIndexZwQueryIoCompletion,
    SeIndexZwQueryKey,
    SeIndexZwQueryLicenseValue,
    SeIndexZwQueryMultipleValueKey,
    SeIndexZwQueryMutant,
    SeIndexZwQueryObject,
    SeIndexZwQueryOpenSubKeys,
    SeIndexZwQueryOpenSubKeysEx,
    SeIndexZwQueryPerformanceCounter,
    SeIndexZwQueryPortInformationProcess,
    SeIndexZwQueryQuotaInformationFile,
    SeIndexZwQuerySection,
    SeIndexZwQuerySecurityAttributesToken,
    SeIndexZwQuerySecurityObject,
    SeIndexZwQuerySecurityPolicy,
    SeIndexZwQuerySemaphore,
    SeIndexZwQuerySymbolicLinkObject,
    SeIndexZwQuerySystemEnvironmentValue,
    SeIndexZwQuerySystemEnvironmentValueEx,
    SeIndexZwQuerySystemInformation,
    SeIndexZwQuerySystemInformationEx,
    SeIndexZwQuerySystemTime,
    SeIndexZwQueryTimer,
    SeIndexZwQueryTimerResolution,
    SeIndexZwQueryValueKey,
    SeIndexZwQueryVirtualMemory,
    SeIndexZwQueryVolumeInformationFile,
    SeIndexZwQueryWnfStateData,
    SeIndexZwQueryWnfStateNameInformation,
    SeIndexZwQueueApcThread,
    SeIndexZwQueueApcThreadEx,
    SeIndexZwRaiseException,
    SeIndexZwRaiseHardError,
    SeIndexZwReadFile,
    SeIndexZwReadFileScatter,
    SeIndexZwReadOnlyEnlistment,
    SeIndexZwReadRequestData,
    SeIndexZwReadVirtualMemory,
    SeIndexZwRecoverEnlistment,
    SeIndexZwRecoverResourceManager,
    SeIndexZwRecoverTransactionManager,
    SeIndexZwRegisterProtocolAddressInformation,
    SeIndexZwRegisterThreadTerminatePort,
    SeIndexZwReleaseCMFViewOwnership,
    SeIndexZwReleaseKeyedEvent,
    SeIndexZwReleaseMutant,
    SeIndexZwReleaseSemaphore,
    SeIndexZwReleaseWorkerFactoryWorker,
    SeIndexZwRemoveIoCompletion,
    SeIndexZwRemoveIoCompletionEx,
    SeIndexZwRemoveProcessDebug,
    SeIndexZwRenameKey,
    SeIndexZwRenameTransactionManager,
    SeIndexZwReplaceKey,
    SeIndexZwReplacePartitionUnit,
    SeIndexZwReplyPort,
    SeIndexZwReplyWaitReceivePort,
    SeIndexZwReplyWaitReceivePortEx,
    SeIndexZwReplyWaitReplyPort,
    SeIndexZwRequestDeviceWakeup,
    SeIndexZwRequestPort,
    SeIndexZwRequestWaitReplyPort,
    SeIndexZwRequestWakeupLatency,
    SeIndexZwResetEvent,
    SeIndexZwResetWriteWatch,
    SeIndexZwRestoreKey,
    SeIndexZwResumeProcess,
    SeIndexZwResumeThread,
    SeIndexZwRevertContainerImpersonation,
    SeIndexZwRollbackComplete,
    SeIndexZwRollbackEnlistment,
    SeIndexZwRollbackRegistryTransaction,
    SeIndexZwRollbackSavepointTransaction,
    SeIndexZwRollbackTransaction,
    SeIndexZwRollforwardTransactionManager,
    SeIndexZwSaveKey,
    SeIndexZwSaveKeyEx,
    SeIndexZwSaveMergedKeys,
    SeIndexZwSavepointComplete,
    SeIndexZwSavepointTransaction,
    SeIndexZwSecureConnectPort,
    SeIndexZwSerializeBoot,
    SeIndexZwSetBootEntryOrder,
    SeIndexZwSetBootOptions,
    SeIndexZwSetCachedSigningLevel,
    SeIndexZwSetCachedSigningLevel2,
    SeIndexZwSetContextThread,
    SeIndexZwSetDebugFilterState,
    SeIndexZwSetDefaultHardErrorPort,
    SeIndexZwSetDefaultLocale,
    SeIndexZwSetDefaultUILanguage,
    SeIndexZwSetDriverEntryOrder,
    SeIndexZwSetEaFile,
    SeIndexZwSetEvent,
    SeIndexZwSetEventBoostPriority,
    SeIndexZwSetHighEventPair,
    SeIndexZwSetHighWaitLowEventPair,
    SeIndexZwSetIRTimer,
    SeIndexZwSetInformationDebugObject,
    SeIndexZwSetInformationEnlistment,
    SeIndexZwSetInformationFile,
    SeIndexZwSetInformationJobObject,
    SeIndexZwSetInformationKey,
    SeIndexZwSetInformationObject,
    SeIndexZwSetInformationProcess,
    SeIndexZwSetInformationResourceManager,
    SeIndexZwSetInformationSymbolicLink,
    SeIndexZwSetInformationThread,
    SeIndexZwSetInformationToken,
    SeIndexZwSetInformationTransaction,
    SeIndexZwSetInformationTransactionManager,
    SeIndexZwSetInformationVirtualMemory,
    SeIndexZwSetInformationWorkerFactory,
    SeIndexZwSetIntervalProfile,
    SeIndexZwSetIoCompletion,
    SeIndexZwSetIoCompletionEx,
    SeIndexZwSetLdtEntries,
    SeIndexZwSetLowEventPair,
    SeIndexZwSetLowWaitHighEventPair,
    SeIndexZwSetQuotaInformationFile,
    SeIndexZwSetSecurityObject,
    SeIndexZwSetSystemEnvironmentValue,
    SeIndexZwSetSystemEnvironmentValueEx,
    SeIndexZwSetSystemInformation,
    SeIndexZwSetSystemPowerState,
    SeIndexZwSetSystemTime,
    SeIndexZwSetThreadExecutionState,
    SeIndexZwSetTimer,
    SeIndexZwSetTimer2,
    SeIndexZwSetTimerEx,
    SeIndexZwSetTimerResolution,
    SeIndexZwSetUuidSeed,
    SeIndexZwSetValueKey,
    SeIndexZwSetVolumeInformationFile,
    SeIndexZwSetWnfProcessNotificationEvent,
    SeIndexZwShutdownSystem,
    SeIndexZwShutdownWorkerFactory,
    SeIndexZwSignalAndWaitForSingleObject,
    SeIndexZwSinglePhaseReject,
    SeIndexZwStartProfile,
    SeIndexZwStartTm,
    SeIndexZwStopProfile,
    SeIndexZwSubscribeWnfStateChange,
    SeIndexZwSuspendProcess,
    SeIndexZwSuspendThread,
    SeIndexZwSystemDebugControl,
    SeIndexZwTerminateEnclave,
    SeIndexZwTerminateJobObject,
    SeIndexZwTerminateProcess,
    SeIndexZwTerminateThread,
    SeIndexZwTestAlert,
    SeIndexZwThawRegistry,
    SeIndexZwThawTransactions,
    SeIndexZwTraceControl,
    SeIndexZwTraceEvent,
    SeIndexZwTranslateFilePath,
    SeIndexZwUmsThreadYield,
    SeIndexZwUnloadDriver,
    SeIndexZwUnloadKey,
    SeIndexZwUnloadKey2,
    SeIndexZwUnloadKeyEx,
    SeIndexZwUnlockFile,
    SeIndexZwUnlockVirtualMemory,
    SeIndexZwUnmapViewOfSection,
    SeIndexZwUnmapViewOfSectionEx,
    SeIndexZwUnsubscribeWnfStateChange,
    SeIndexZwUpdateWnfStateData,
    SeIndexZwVdmControl,
    SeIndexZwWaitForAlertByThreadId,
    SeIndexZwWaitForDebugEvent,
    SeIndexZwWaitForKeyedEvent,
    SeIndexZwWaitForMultipleObjects,
    SeIndexZwWaitForMultipleObjects32,
    SeIndexZwWaitForSingleObject,
    SeIndexZwWaitForWnfNotifications,
    SeIndexZwWaitForWorkViaWorkerFactory,
    SeIndexZwWaitHighEventPair,
    SeIndexZwWaitLowEventPair,
    SeIndexZwWorkerFactoryWorkerReady,
    SeIndexZwWriteFile,
    SeIndexZwWriteFileGather,
    SeIndexZwWriteRequestData,
    SeIndexZwWriteVirtualMemory,
    SeIndexZwYieldExecution,
    MaxSeIndexKeServiceDescriptorTable
}KSE_SERVICE_DESCRIPTOR_TABLE_CLASS;

#define NUMBER_SERVICE_TABLES 2

#define SYSTEM_SERVICE_INDEX 0
#define WIN32K_SERVICE_INDEX 1

typedef struct _KSE_SERVICE_DESCRIPTOR_TABLE
{
    PVOID Base;
    SIZE_T Limit;
    SIZE_T Count;
    PVOID End;
} KSE_SERVICE_DESCRIPTOR_TABLE, *PKSE_SERVICE_DESCRIPTOR_TABLE;

#ifndef _WIN64

typedef struct _KSE_SSDT_ENTRY
{
#pragma pack(push, 1)
    BOOLEAN Reserved1[1];

    union
    {
        BOOLEAN Reserved2[4];
        ULONG KiServiceTableIndex;
    }u1;

    BOOLEAN Reserved3[8];

    union
    {
        BOOLEAN Reserved4[4];
        ULONG KiSystemService;
    }u2;

    BOOLEAN Ret[3];
    BOOLEAN Alignment[12];
#pragma pack(pop)
} KSE_SSDT_ENTRY, *PKSE_SSDT_ENTRY;

C_ASSERT(SE_OFFSETOF(KSE_SSDT_ENTRY, u1.KiServiceTableIndex) == 1);
C_ASSERT(SE_OFFSETOF(KSE_SSDT_ENTRY, u2.KiSystemService) == 13);
C_ASSERT(sizeof(KSE_SSDT_ENTRY) == 0x20);

#else

typedef struct _KSE_SSDT_ENTRY
{
#pragma pack(push, 1)
    BOOLEAN Reserved1[34];

    union
    {
        BOOLEAN Reserved2[8];
        ULONGLONG KiServiceLinkage;
    }u1;

    BOOLEAN Reserved3[2];

    union
    {
        BOOLEAN Reserved4[4];
        ULONG KiServiceTableIndex;
    }u2;

    BOOLEAN Reserved5[2];
    union
    {
        BOOLEAN Reserved6[8];
        ULONGLONG KiServiceInternal;
    }u3;

    BOOLEAN Reserved7[3];
    BOOLEAN Alignment[3];
#pragma pack(pop)
} KSE_SSDT_ENTRY, *PKSE_SSDT_ENTRY;

C_ASSERT(SE_OFFSETOF(KSE_SSDT_ENTRY, u1.KiServiceLinkage) == 34);
C_ASSERT(SE_OFFSETOF(KSE_SSDT_ENTRY, u2.KiServiceTableIndex) == 44);
C_ASSERT(SE_OFFSETOF(KSE_SSDT_ENTRY, u3.KiServiceInternal) == 50);
C_ASSERT(sizeof(KSE_SSDT_ENTRY) == 0x40);

#endif // !_WIN64

PVOID
NTAPI
SeGetKernelExportRoutineAddress(
    __in LPCSTR Name
);

PVOID
NTAPI
SeGetKeServiceDescriptorTableEntryPoint(
    __in LPCWSTR Name
);

#endif // !_KERNEL_MODE_SYSCALLTABLE_H_
