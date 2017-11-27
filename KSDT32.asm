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
; WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
; for the specific language governing rights and limitations under the
; License.
; 
; The Initial Developer of the Original Code is blindtiger.
; 
; 

.586p

INCLUDE ks386.inc
INCLUDE SyscallTable.inc

.MODEL FLAT, STDCALL
OPTION CASEMAP:NONE

SeRelocateSyscallTable PROTO

.DATA

.CODE

REFACTE_KSE_SSDT_ENTRY MACRO

    mov eax, $ + 0
    push eax
    mov eax, [SeServiceDescriptorTableCheck]
    jmp eax
DB  4 dup (0cch)

ENDM

KSE_SSDT_ENTRY MACRO OPR1, OPR2

OPR1 :

    REFACTE_KSE_SSDT_ENTRY
    ret OPR2
DB  12 dup (0cch)

PUBLIC OPR1

ENDM

KSE_SSDT_ENTRY SeZwAcceptConnectPort@24, 24
KSE_SSDT_ENTRY SeZwAccessCheck@32, 32
KSE_SSDT_ENTRY SeZwAccessCheckAndAuditAlarm@44, 44
KSE_SSDT_ENTRY SeZwAccessCheckByType@44, 44
KSE_SSDT_ENTRY SeZwAccessCheckByTypeAndAuditAlarm@64, 64
KSE_SSDT_ENTRY SeZwAccessCheckByTypeResultList@44, 44
KSE_SSDT_ENTRY SeZwAccessCheckByTypeResultListAndAuditAlarm@64, 64
KSE_SSDT_ENTRY SeZwAccessCheckByTypeResultListAndAuditAlarmByHandle@68, 68
KSE_SSDT_ENTRY SeZwAcquireCMFViewOwnership@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwAcquireProcessActivityReference@12, 12
KSE_SSDT_ENTRY SeZwAddAtom@12, 12
KSE_SSDT_ENTRY SeZwAddAtomEx@16, 16
KSE_SSDT_ENTRY SeZwAddBootEntry@8, 8
KSE_SSDT_ENTRY SeZwAddDriverEntry@8, 8
KSE_SSDT_ENTRY SeZwAdjustGroupsToken@24, 24
KSE_SSDT_ENTRY SeZwAdjustPrivilegesToken@24, 24
KSE_SSDT_ENTRY SeZwAdjustTokenClaimsAndDeviceGroups@64, 64
KSE_SSDT_ENTRY SeZwAlertResumeThread@8, 8
KSE_SSDT_ENTRY SeZwAlertThread@4, 4
KSE_SSDT_ENTRY SeZwAlertThreadByThreadId@4, 4
KSE_SSDT_ENTRY SeZwAllocateLocallyUniqueId@4, 4
KSE_SSDT_ENTRY SeZwAllocateReserveObject@12, 12
KSE_SSDT_ENTRY SeZwAllocateUserPhysicalPages@12, 12
KSE_SSDT_ENTRY SeZwAllocateUuids@16, 16
KSE_SSDT_ENTRY SeZwAllocateVirtualMemory@24, 24
KSE_SSDT_ENTRY SeZwAlpcAcceptConnectPort@36, 36
KSE_SSDT_ENTRY SeZwAlpcCancelMessage@12, 12
KSE_SSDT_ENTRY SeZwAlpcConnectPort@44, 44
KSE_SSDT_ENTRY SeZwAlpcConnectPortEx@44, 44
KSE_SSDT_ENTRY SeZwAlpcCreatePort@12, 12
KSE_SSDT_ENTRY SeZwAlpcCreatePortSection@24, 24
KSE_SSDT_ENTRY SeZwAlpcCreateResourceReserve@16, 16
KSE_SSDT_ENTRY SeZwAlpcCreateSectionView@12, 12
KSE_SSDT_ENTRY SeZwAlpcCreateSecurityContext@12, 12
KSE_SSDT_ENTRY SeZwAlpcDeletePortSection@12, 12
KSE_SSDT_ENTRY SeZwAlpcDeleteResourceReserve@12, 12
KSE_SSDT_ENTRY SeZwAlpcDeleteSectionView@12, 12
KSE_SSDT_ENTRY SeZwAlpcDeleteSecurityContext@12, 12
KSE_SSDT_ENTRY SeZwAlpcDisconnectPort@8, 8
KSE_SSDT_ENTRY SeZwAlpcImpersonateClientContainerOfPort@12, 12
KSE_SSDT_ENTRY SeZwAlpcImpersonateClientOfPort@12, 12
KSE_SSDT_ENTRY SeZwAlpcOpenSenderProcess@24, 24
KSE_SSDT_ENTRY SeZwAlpcOpenSenderThread@24, 24
KSE_SSDT_ENTRY SeZwAlpcQueryInformation@20, 20
KSE_SSDT_ENTRY SeZwAlpcQueryInformationMessage@24, 24
KSE_SSDT_ENTRY SeZwAlpcRevokeSecurityContext@12, 12
KSE_SSDT_ENTRY SeZwAlpcSendWaitReceivePort@32, 32
KSE_SSDT_ENTRY SeZwAlpcSetInformation@16, 16
KSE_SSDT_ENTRY SeZwApphelpCacheControl@8, 8
KSE_SSDT_ENTRY SeZwAreMappedFilesTheSame@8, 8
KSE_SSDT_ENTRY SeZwAssignProcessToJobObject@8, 8
KSE_SSDT_ENTRY SeZwAssociateWaitCompletionPacket@32, 32
KSE_SSDT_ENTRY SeZwCallEnclave@16, 16
KSE_SSDT_ENTRY SeZwCallbackReturn@12, 12
KSE_SSDT_ENTRY SeZwCancelDeviceWakeupRequest@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwCancelIoFile@8, 8
KSE_SSDT_ENTRY SeZwCancelIoFileEx@12, 12
KSE_SSDT_ENTRY SeZwCancelSynchronousIoFile@12, 12
KSE_SSDT_ENTRY SeZwCancelTimer@8, 8
KSE_SSDT_ENTRY SeZwCancelTimer2@8, 8
KSE_SSDT_ENTRY SeZwCancelWaitCompletionPacket@8, 8
KSE_SSDT_ENTRY SeZwClearAllSavepointsTransaction@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwClearEvent@4, 4
KSE_SSDT_ENTRY SeZwClearSavepointTransaction@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwClose@4, 4
KSE_SSDT_ENTRY SeZwCloseObjectAuditAlarm@12, 12
KSE_SSDT_ENTRY SeZwCommitComplete@8, 8
KSE_SSDT_ENTRY SeZwCommitEnlistment@8, 8
KSE_SSDT_ENTRY SeZwCommitRegistryTransaction@8, 8
KSE_SSDT_ENTRY SeZwCommitTransaction@8, 8
KSE_SSDT_ENTRY SeZwCompactKeys@8, 8
KSE_SSDT_ENTRY SeZwCompareObjects@8, 8
KSE_SSDT_ENTRY SeZwCompareSigningLevels@8, 8
KSE_SSDT_ENTRY SeZwCompareTokens@12, 12
KSE_SSDT_ENTRY SeZwCompleteConnectPort@4, 4
KSE_SSDT_ENTRY SeZwCompressKey@4, 4
KSE_SSDT_ENTRY SeZwConnectPort@32, 32
KSE_SSDT_ENTRY SeZwContinue@8, 8
KSE_SSDT_ENTRY SeZwConvertBetweenAuxiliaryCounterAndPerformanceCounter@16, 16
KSE_SSDT_ENTRY SeZwCreateDebugObject@16, 16
KSE_SSDT_ENTRY SeZwCreateDirectoryObject@12, 12
KSE_SSDT_ENTRY SeZwCreateDirectoryObjectEx@20, 20
KSE_SSDT_ENTRY SeZwCreateEnclave@36, 36
KSE_SSDT_ENTRY SeZwCreateEnlistment@32, 32
KSE_SSDT_ENTRY SeZwCreateEvent@20, 20
KSE_SSDT_ENTRY SeZwCreateEventPair@12, 12
KSE_SSDT_ENTRY SeZwCreateFile@44, 44
KSE_SSDT_ENTRY SeZwCreateIRTimer@12, 12
KSE_SSDT_ENTRY SeZwCreateIoCompletion@16, 16
KSE_SSDT_ENTRY SeZwCreateJobObject@12, 12
KSE_SSDT_ENTRY SeZwCreateJobSet@12, 12
KSE_SSDT_ENTRY SeZwCreateKey@28, 28
KSE_SSDT_ENTRY SeZwCreateKeyTransacted@32, 32
KSE_SSDT_ENTRY SeZwCreateKeyedEvent@16, 16
KSE_SSDT_ENTRY SeZwCreateLowBoxToken@36, 36
KSE_SSDT_ENTRY SeZwCreateMailslotFile@32, 32
KSE_SSDT_ENTRY SeZwCreateMutant@16, 16
KSE_SSDT_ENTRY SeZwCreateNamedPipeFile@56, 56
KSE_SSDT_ENTRY SeZwCreatePagingFile@16, 16
KSE_SSDT_ENTRY SeZwCreatePartition@16, 16
KSE_SSDT_ENTRY SeZwCreatePort@20, 20
KSE_SSDT_ENTRY SeZwCreatePrivateNamespace@16, 16
KSE_SSDT_ENTRY SeZwCreateProcess@32, 32
KSE_SSDT_ENTRY SeZwCreateProcessEx@36, 36
KSE_SSDT_ENTRY SeZwCreateProfile@36, 36
KSE_SSDT_ENTRY SeZwCreateProfileEx@40, 40
KSE_SSDT_ENTRY SeZwCreateRegistryTransaction@16, 16
KSE_SSDT_ENTRY SeZwCreateResourceManager@28, 28
KSE_SSDT_ENTRY SeZwCreateSection@28, 28
KSE_SSDT_ENTRY SeZwCreateSemaphore@20, 20
KSE_SSDT_ENTRY SeZwCreateSymbolicLinkObject@16, 16
KSE_SSDT_ENTRY SeZwCreateThread@32, 32
KSE_SSDT_ENTRY SeZwCreateThreadEx@44, 44
KSE_SSDT_ENTRY SeZwCreateTimer@16, 16
KSE_SSDT_ENTRY SeZwCreateTimer2@20, 20
KSE_SSDT_ENTRY SeZwCreateToken@52, 52
KSE_SSDT_ENTRY SeZwCreateTokenEx@68, 68
KSE_SSDT_ENTRY SeZwCreateTransaction@40, 40
KSE_SSDT_ENTRY SeZwCreateTransactionManager@24, 24
KSE_SSDT_ENTRY SeZwCreateUserProcess@44, 44
KSE_SSDT_ENTRY SeZwCreateWaitCompletionPacket@12, 12
KSE_SSDT_ENTRY SeZwCreateWaitablePort@20, 20
KSE_SSDT_ENTRY SeZwCreateWnfStateName@28, 28
KSE_SSDT_ENTRY SeZwCreateWorkerFactory@40, 40
KSE_SSDT_ENTRY SeZwDebugActiveProcess@8, 8
KSE_SSDT_ENTRY SeZwDebugContinue@12, 12
KSE_SSDT_ENTRY SeZwDelayExecution@8, 8
KSE_SSDT_ENTRY SeZwDeleteAtom@4, 4
KSE_SSDT_ENTRY SeZwDeleteBootEntry@4, 4
KSE_SSDT_ENTRY SeZwDeleteDriverEntry@4, 4
KSE_SSDT_ENTRY SeZwDeleteFile@4, 4
KSE_SSDT_ENTRY SeZwDeleteKey@4, 4
KSE_SSDT_ENTRY SeZwDeleteObjectAuditAlarm@12, 12
KSE_SSDT_ENTRY SeZwDeletePrivateNamespace@4, 4
KSE_SSDT_ENTRY SeZwDeleteValueKey@8, 8
KSE_SSDT_ENTRY SeZwDeleteWnfStateData@8, 8
KSE_SSDT_ENTRY SeZwDeleteWnfStateName@4, 4
KSE_SSDT_ENTRY SeZwDeviceIoControlFile@40, 40
KSE_SSDT_ENTRY SeZwDisableLastKnownGood@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwDisplayString@4, 4
KSE_SSDT_ENTRY SeZwDrawText@4, 4
KSE_SSDT_ENTRY SeZwDuplicateObject@28, 28
KSE_SSDT_ENTRY SeZwDuplicateToken@24, 24
KSE_SSDT_ENTRY SeZwEnableLastKnownGood@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwEnumerateBootEntries@8, 8
KSE_SSDT_ENTRY SeZwEnumerateDriverEntries@8, 8
KSE_SSDT_ENTRY SeZwEnumerateKey@24, 24
KSE_SSDT_ENTRY SeZwEnumerateSystemEnvironmentValuesEx@12, 12
KSE_SSDT_ENTRY SeZwEnumerateTransactionObject@20, 20
KSE_SSDT_ENTRY SeZwEnumerateValueKey@24, 24
KSE_SSDT_ENTRY SeZwExtendSection@8, 8
KSE_SSDT_ENTRY SeZwFilterBootOption@20, 20
KSE_SSDT_ENTRY SeZwFilterToken@24, 24
KSE_SSDT_ENTRY SeZwFilterTokenEx@56, 56
KSE_SSDT_ENTRY SeZwFindAtom@12, 12
KSE_SSDT_ENTRY SeZwFlushBuffersFile@8, 8
KSE_SSDT_ENTRY SeZwFlushBuffersFileEx@20, 20
KSE_SSDT_ENTRY SeZwFlushInstallUILanguage@8, 8
KSE_SSDT_ENTRY SeZwFlushInstructionCache@12, 12
KSE_SSDT_ENTRY SeZwFlushKey@4, 4
KSE_SSDT_ENTRY SeZwFlushProcessWriteBuffers@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwFlushVirtualMemory@16, 16
KSE_SSDT_ENTRY SeZwFlushWriteBuffer@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwFreeUserPhysicalPages@12, 12
KSE_SSDT_ENTRY SeZwFreeVirtualMemory@16, 16
KSE_SSDT_ENTRY SeZwFreezeRegistry@4, 4
KSE_SSDT_ENTRY SeZwFreezeTransactions@8, 8
KSE_SSDT_ENTRY SeZwFsControlFile@40, 40
KSE_SSDT_ENTRY SeZwGetCachedSigningLevel@24, 24
KSE_SSDT_ENTRY SeZwGetCompleteWnfStateSubscription@24, 24
KSE_SSDT_ENTRY SeZwGetContextThread@8, 8
KSE_SSDT_ENTRY SeZwGetCurrentProcessorNumber@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwGetCurrentProcessorNumberEx@4, 4
KSE_SSDT_ENTRY SeZwGetDevicePowerState@8, 8
KSE_SSDT_ENTRY SeZwGetMUIRegistryInfo@12, 12
KSE_SSDT_ENTRY SeZwGetNextProcess@20, 20
KSE_SSDT_ENTRY SeZwGetNextThread@24, 24
KSE_SSDT_ENTRY SeZwGetNlsSectionPtr@20, 20
KSE_SSDT_ENTRY SeZwGetNotificationResourceManager@28, 28
KSE_SSDT_ENTRY SeZwGetPlugPlayEvent@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwGetWriteWatch@28, 28
KSE_SSDT_ENTRY SeZwImpersonateAnonymousToken@4, 4
KSE_SSDT_ENTRY SeZwImpersonateClientOfPort@8, 8
KSE_SSDT_ENTRY SeZwImpersonateThread@12, 12
KSE_SSDT_ENTRY SeZwInitializeEnclave@20, 20
KSE_SSDT_ENTRY SeZwInitializeNlsFiles@12, 12
KSE_SSDT_ENTRY SeZwInitializeRegistry@4, 4
KSE_SSDT_ENTRY SeZwInitiatePowerAction@16, 16
KSE_SSDT_ENTRY SeZwIsProcessInJob@8, 8
KSE_SSDT_ENTRY SeZwIsSystemResumeAutomatic@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwIsUILanguageComitted@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwListTransactions@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwListenPort@8, 8
KSE_SSDT_ENTRY SeZwLoadDriver@4, 4
KSE_SSDT_ENTRY SeZwLoadEnclaveData@36, 36
KSE_SSDT_ENTRY SeZwLoadHotPatch@8, 8
KSE_SSDT_ENTRY SeZwLoadKey@8, 8
KSE_SSDT_ENTRY SeZwLoadKey2@12, 12
KSE_SSDT_ENTRY SeZwLoadKeyEx@32, 32
KSE_SSDT_ENTRY SeZwLockFile@40, 40
KSE_SSDT_ENTRY SeZwLockProductActivationKeys@8, 8
KSE_SSDT_ENTRY SeZwLockRegistryKey@4, 4
KSE_SSDT_ENTRY SeZwLockVirtualMemory@16, 16
KSE_SSDT_ENTRY SeZwMakePermanentObject@4, 4
KSE_SSDT_ENTRY SeZwMakeTemporaryObject@4, 4
KSE_SSDT_ENTRY SeZwManagePartition@20, 20
KSE_SSDT_ENTRY SeZwMapCMFModule@24, 24
KSE_SSDT_ENTRY SeZwMapUserPhysicalPages@12, 12
KSE_SSDT_ENTRY SeZwMapUserPhysicalPagesScatter@12, 12
KSE_SSDT_ENTRY SeZwMapViewOfSection@40, 40
KSE_SSDT_ENTRY SeZwMarshallTransaction@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwModifyBootEntry@4, 4
KSE_SSDT_ENTRY SeZwModifyDriverEntry@4, 4
KSE_SSDT_ENTRY SeZwNotifyChangeDirectoryFile@36, 36
KSE_SSDT_ENTRY SeZwNotifyChangeDirectoryFileEx@40, 40
KSE_SSDT_ENTRY SeZwNotifyChangeKey@40, 40
KSE_SSDT_ENTRY SeZwNotifyChangeMultipleKeys@48, 48
KSE_SSDT_ENTRY SeZwNotifyChangeSession@32, 32
KSE_SSDT_ENTRY SeZwOpenDirectoryObject@12, 12
KSE_SSDT_ENTRY SeZwOpenEnlistment@20, 20
KSE_SSDT_ENTRY SeZwOpenEvent@12, 12
KSE_SSDT_ENTRY SeZwOpenEventPair@12, 12
KSE_SSDT_ENTRY SeZwOpenFile@24, 24
KSE_SSDT_ENTRY SeZwOpenIoCompletion@12, 12
KSE_SSDT_ENTRY SeZwOpenJobObject@12, 12
KSE_SSDT_ENTRY SeZwOpenKey@12, 12
KSE_SSDT_ENTRY SeZwOpenKeyEx@16, 16
KSE_SSDT_ENTRY SeZwOpenKeyTransacted@16, 16
KSE_SSDT_ENTRY SeZwOpenKeyTransactedEx@20, 20
KSE_SSDT_ENTRY SeZwOpenKeyedEvent@12, 12
KSE_SSDT_ENTRY SeZwOpenMutant@12, 12
KSE_SSDT_ENTRY SeZwOpenObjectAuditAlarm@48, 48
KSE_SSDT_ENTRY SeZwOpenPartition@12, 12
KSE_SSDT_ENTRY SeZwOpenPrivateNamespace@16, 16
KSE_SSDT_ENTRY SeZwOpenProcess@16, 16
KSE_SSDT_ENTRY SeZwOpenProcessToken@12, 12
KSE_SSDT_ENTRY SeZwOpenProcessTokenEx@16, 16
KSE_SSDT_ENTRY SeZwOpenRegistryTransaction@12, 12
KSE_SSDT_ENTRY SeZwOpenResourceManager@20, 20
KSE_SSDT_ENTRY SeZwOpenSection@12, 12
KSE_SSDT_ENTRY SeZwOpenSemaphore@12, 12
KSE_SSDT_ENTRY SeZwOpenSession@12, 12
KSE_SSDT_ENTRY SeZwOpenSymbolicLinkObject@12, 12
KSE_SSDT_ENTRY SeZwOpenThread@16, 16
KSE_SSDT_ENTRY SeZwOpenThreadToken@16, 16
KSE_SSDT_ENTRY SeZwOpenThreadTokenEx@20, 20
KSE_SSDT_ENTRY SeZwOpenTimer@12, 12
KSE_SSDT_ENTRY SeZwOpenTransaction@20, 20
KSE_SSDT_ENTRY SeZwOpenTransactionManager@24, 24
KSE_SSDT_ENTRY SeZwPlugPlayControl@12, 12
KSE_SSDT_ENTRY SeZwPowerInformation@20, 20
KSE_SSDT_ENTRY SeZwPrePrepareComplete@8, 8
KSE_SSDT_ENTRY SeZwPrePrepareEnlistment@8, 8
KSE_SSDT_ENTRY SeZwPrepareComplete@8, 8
KSE_SSDT_ENTRY SeZwPrepareEnlistment@8, 8
KSE_SSDT_ENTRY SeZwPrivilegeCheck@12, 12
KSE_SSDT_ENTRY SeZwPrivilegeObjectAuditAlarm@24, 24
KSE_SSDT_ENTRY SeZwPrivilegedServiceAuditAlarm@20, 20
KSE_SSDT_ENTRY SeZwPropagationComplete@16, 16
KSE_SSDT_ENTRY SeZwPropagationFailed@12, 12
KSE_SSDT_ENTRY SeZwProtectVirtualMemory@20, 20
KSE_SSDT_ENTRY SeZwPullTransaction@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwPulseEvent@8, 8
KSE_SSDT_ENTRY SeZwQueryAttributesFile@8, 8
KSE_SSDT_ENTRY SeZwQueryAuxiliaryCounterFrequency@4, 4
KSE_SSDT_ENTRY SeZwQueryBootEntryOrder@8, 8
KSE_SSDT_ENTRY SeZwQueryBootOptions@8, 8
KSE_SSDT_ENTRY SeZwQueryDebugFilterState@8, 8
KSE_SSDT_ENTRY SeZwQueryDefaultLocale@8, 8
KSE_SSDT_ENTRY SeZwQueryDefaultUILanguage@4, 4
KSE_SSDT_ENTRY SeZwQueryDirectoryFile@44, 44
KSE_SSDT_ENTRY SeZwQueryDirectoryFileEx@40, 40
KSE_SSDT_ENTRY SeZwQueryDirectoryObject@28, 28
KSE_SSDT_ENTRY SeZwQueryDriverEntryOrder@8, 8
KSE_SSDT_ENTRY SeZwQueryEaFile@36, 36
KSE_SSDT_ENTRY SeZwQueryEvent@20, 20
KSE_SSDT_ENTRY SeZwQueryFullAttributesFile@8, 8
KSE_SSDT_ENTRY SeZwQueryInformationAtom@20, 20
KSE_SSDT_ENTRY SeZwQueryInformationByName@20, 20
KSE_SSDT_ENTRY SeZwQueryInformationEnlistment@20, 20
KSE_SSDT_ENTRY SeZwQueryInformationFile@20, 20
KSE_SSDT_ENTRY SeZwQueryInformationJobObject@20, 20
KSE_SSDT_ENTRY SeZwQueryInformationPort@20, 20
KSE_SSDT_ENTRY SeZwQueryInformationProcess@20, 20
KSE_SSDT_ENTRY SeZwQueryInformationResourceManager@20, 20
KSE_SSDT_ENTRY SeZwQueryInformationThread@20, 20
KSE_SSDT_ENTRY SeZwQueryInformationToken@20, 20
KSE_SSDT_ENTRY SeZwQueryInformationTransaction@20, 20
KSE_SSDT_ENTRY SeZwQueryInformationTransactionManager@20, 20
KSE_SSDT_ENTRY SeZwQueryInformationWorkerFactory@20, 20
KSE_SSDT_ENTRY SeZwQueryInstallUILanguage@4, 4
KSE_SSDT_ENTRY SeZwQueryIntervalProfile@8, 8
KSE_SSDT_ENTRY SeZwQueryIoCompletion@20, 20
KSE_SSDT_ENTRY SeZwQueryKey@20, 20
KSE_SSDT_ENTRY SeZwQueryLicenseValue@20, 20
KSE_SSDT_ENTRY SeZwQueryMultipleValueKey@24, 24
KSE_SSDT_ENTRY SeZwQueryMutant@20, 20
KSE_SSDT_ENTRY SeZwQueryObject@20, 20
KSE_SSDT_ENTRY SeZwQueryOpenSubKeys@8, 8
KSE_SSDT_ENTRY SeZwQueryOpenSubKeysEx@16, 16
KSE_SSDT_ENTRY SeZwQueryPerformanceCounter@8, 8
KSE_SSDT_ENTRY SeZwQueryPortInformationProcess@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwQueryQuotaInformationFile@36, 36
KSE_SSDT_ENTRY SeZwQuerySection@20, 20
KSE_SSDT_ENTRY SeZwQuerySecurityAttributesToken@24, 24
KSE_SSDT_ENTRY SeZwQuerySecurityObject@20, 20
KSE_SSDT_ENTRY SeZwQuerySecurityPolicy@24, 24
KSE_SSDT_ENTRY SeZwQuerySemaphore@20, 20
KSE_SSDT_ENTRY SeZwQuerySymbolicLinkObject@12, 12
KSE_SSDT_ENTRY SeZwQuerySystemEnvironmentValue@16, 16
KSE_SSDT_ENTRY SeZwQuerySystemEnvironmentValueEx@20, 20
KSE_SSDT_ENTRY SeZwQuerySystemInformation@16, 16
KSE_SSDT_ENTRY SeZwQuerySystemInformationEx@24, 24
KSE_SSDT_ENTRY SeZwQuerySystemTime@4, 4
KSE_SSDT_ENTRY SeZwQueryTimer@20, 20
KSE_SSDT_ENTRY SeZwQueryTimerResolution@12, 12
KSE_SSDT_ENTRY SeZwQueryValueKey@24, 24
KSE_SSDT_ENTRY SeZwQueryVirtualMemory@24, 24
KSE_SSDT_ENTRY SeZwQueryVolumeInformationFile@20, 20
KSE_SSDT_ENTRY SeZwQueryWnfStateData@24, 24
KSE_SSDT_ENTRY SeZwQueryWnfStateNameInformation@20, 20
KSE_SSDT_ENTRY SeZwQueueApcThread@20, 20
KSE_SSDT_ENTRY SeZwQueueApcThreadEx@24, 24
KSE_SSDT_ENTRY SeZwRaiseException@12, 12
KSE_SSDT_ENTRY SeZwRaiseHardError@24, 24
KSE_SSDT_ENTRY SeZwReadFile@36, 36
KSE_SSDT_ENTRY SeZwReadFileScatter@36, 36
KSE_SSDT_ENTRY SeZwReadOnlyEnlistment@8, 8
KSE_SSDT_ENTRY SeZwReadRequestData@24, 24
KSE_SSDT_ENTRY SeZwReadVirtualMemory@20, 20
KSE_SSDT_ENTRY SeZwRecoverEnlistment@8, 8
KSE_SSDT_ENTRY SeZwRecoverResourceManager@4, 4
KSE_SSDT_ENTRY SeZwRecoverTransactionManager@4, 4
KSE_SSDT_ENTRY SeZwRegisterProtocolAddressInformation@20, 20
KSE_SSDT_ENTRY SeZwRegisterThreadTerminatePort@4, 4
KSE_SSDT_ENTRY SeZwReleaseCMFViewOwnership@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwReleaseKeyedEvent@16, 16
KSE_SSDT_ENTRY SeZwReleaseMutant@8, 8
KSE_SSDT_ENTRY SeZwReleaseSemaphore@12, 12
KSE_SSDT_ENTRY SeZwReleaseWorkerFactoryWorker@4, 4
KSE_SSDT_ENTRY SeZwRemoveIoCompletion@20, 20
KSE_SSDT_ENTRY SeZwRemoveIoCompletionEx@24, 24
KSE_SSDT_ENTRY SeZwRemoveProcessDebug@8, 8
KSE_SSDT_ENTRY SeZwRenameKey@8, 8
KSE_SSDT_ENTRY SeZwRenameTransactionManager@8, 8
KSE_SSDT_ENTRY SeZwReplaceKey@12, 12
KSE_SSDT_ENTRY SeZwReplacePartitionUnit@12, 12
KSE_SSDT_ENTRY SeZwReplyPort@8, 8
KSE_SSDT_ENTRY SeZwReplyWaitReceivePort@16, 16
KSE_SSDT_ENTRY SeZwReplyWaitReceivePortEx@20, 20
KSE_SSDT_ENTRY SeZwReplyWaitReplyPort@8, 8
KSE_SSDT_ENTRY SeZwRequestDeviceWakeup@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwRequestPort@8, 8
KSE_SSDT_ENTRY SeZwRequestWaitReplyPort@12, 12
KSE_SSDT_ENTRY SeZwRequestWakeupLatency@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwResetEvent@8, 8
KSE_SSDT_ENTRY SeZwResetWriteWatch@12, 12
KSE_SSDT_ENTRY SeZwRestoreKey@12, 12
KSE_SSDT_ENTRY SeZwResumeProcess@4, 4
KSE_SSDT_ENTRY SeZwResumeThread@8, 8
KSE_SSDT_ENTRY SeZwRevertContainerImpersonation@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwRollbackComplete@8, 8
KSE_SSDT_ENTRY SeZwRollbackEnlistment@8, 8
KSE_SSDT_ENTRY SeZwRollbackRegistryTransaction@8, 8
KSE_SSDT_ENTRY SeZwRollbackSavepointTransaction@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwRollbackTransaction@8, 8
KSE_SSDT_ENTRY SeZwRollforwardTransactionManager@8, 8
KSE_SSDT_ENTRY SeZwSaveKey@8, 8
KSE_SSDT_ENTRY SeZwSaveKeyEx@12, 12
KSE_SSDT_ENTRY SeZwSaveMergedKeys@12, 12
KSE_SSDT_ENTRY SeZwSavepointComplete@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwSavepointTransaction@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwSecureConnectPort@36, 36
KSE_SSDT_ENTRY SeZwSerializeBoot@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwSetBootEntryOrder@8, 8
KSE_SSDT_ENTRY SeZwSetBootOptions@8, 8
KSE_SSDT_ENTRY SeZwSetCachedSigningLevel@20, 20
KSE_SSDT_ENTRY SeZwSetCachedSigningLevel2@24, 24
KSE_SSDT_ENTRY SeZwSetContextThread@8, 8
KSE_SSDT_ENTRY SeZwSetDebugFilterState@12, 12
KSE_SSDT_ENTRY SeZwSetDefaultHardErrorPort@4, 4
KSE_SSDT_ENTRY SeZwSetDefaultLocale@8, 8
KSE_SSDT_ENTRY SeZwSetDefaultUILanguage@4, 4
KSE_SSDT_ENTRY SeZwSetDriverEntryOrder@8, 8
KSE_SSDT_ENTRY SeZwSetEaFile@16, 16
KSE_SSDT_ENTRY SeZwSetEvent@8, 8
KSE_SSDT_ENTRY SeZwSetEventBoostPriority@4, 4
KSE_SSDT_ENTRY SeZwSetHighEventPair@4, 4
KSE_SSDT_ENTRY SeZwSetHighWaitLowEventPair@4, 4
KSE_SSDT_ENTRY SeZwSetIRTimer@8, 8
KSE_SSDT_ENTRY SeZwSetInformationDebugObject@20, 20
KSE_SSDT_ENTRY SeZwSetInformationEnlistment@16, 16
KSE_SSDT_ENTRY SeZwSetInformationFile@20, 20
KSE_SSDT_ENTRY SeZwSetInformationJobObject@16, 16
KSE_SSDT_ENTRY SeZwSetInformationKey@16, 16
KSE_SSDT_ENTRY SeZwSetInformationObject@16, 16
KSE_SSDT_ENTRY SeZwSetInformationProcess@16, 16
KSE_SSDT_ENTRY SeZwSetInformationResourceManager@16, 16
KSE_SSDT_ENTRY SeZwSetInformationSymbolicLink@16, 16
KSE_SSDT_ENTRY SeZwSetInformationThread@16, 16
KSE_SSDT_ENTRY SeZwSetInformationToken@16, 16
KSE_SSDT_ENTRY SeZwSetInformationTransaction@16, 16
KSE_SSDT_ENTRY SeZwSetInformationTransactionManager@16, 16
KSE_SSDT_ENTRY SeZwSetInformationVirtualMemory@24, 24
KSE_SSDT_ENTRY SeZwSetInformationWorkerFactory@16, 16
KSE_SSDT_ENTRY SeZwSetIntervalProfile@8, 8
KSE_SSDT_ENTRY SeZwSetIoCompletion@20, 20
KSE_SSDT_ENTRY SeZwSetIoCompletionEx@24, 24
KSE_SSDT_ENTRY SeZwSetLdtEntries@24, 24
KSE_SSDT_ENTRY SeZwSetLowEventPair@4, 4
KSE_SSDT_ENTRY SeZwSetLowWaitHighEventPair@4, 4
KSE_SSDT_ENTRY SeZwSetQuotaInformationFile@16, 16
KSE_SSDT_ENTRY SeZwSetSecurityObject@12, 12
KSE_SSDT_ENTRY SeZwSetSystemEnvironmentValue@8, 8
KSE_SSDT_ENTRY SeZwSetSystemEnvironmentValueEx@20, 20
KSE_SSDT_ENTRY SeZwSetSystemInformation@12, 12
KSE_SSDT_ENTRY SeZwSetSystemPowerState@12, 12
KSE_SSDT_ENTRY SeZwSetSystemTime@8, 8
KSE_SSDT_ENTRY SeZwSetThreadExecutionState@8, 8
KSE_SSDT_ENTRY SeZwSetTimer@28, 28
KSE_SSDT_ENTRY SeZwSetTimer2@16, 16
KSE_SSDT_ENTRY SeZwSetTimerEx@16, 16
KSE_SSDT_ENTRY SeZwSetTimerResolution@12, 12
KSE_SSDT_ENTRY SeZwSetUuidSeed@4, 4
KSE_SSDT_ENTRY SeZwSetValueKey@24, 24
KSE_SSDT_ENTRY SeZwSetVolumeInformationFile@20, 20
KSE_SSDT_ENTRY SeZwSetWnfProcessNotificationEvent@4, 4
KSE_SSDT_ENTRY SeZwShutdownSystem@4, 4
KSE_SSDT_ENTRY SeZwShutdownWorkerFactory@8, 8
KSE_SSDT_ENTRY SeZwSignalAndWaitForSingleObject@16, 16
KSE_SSDT_ENTRY SeZwSinglePhaseReject@8, 8
KSE_SSDT_ENTRY SeZwStartProfile@4, 4
KSE_SSDT_ENTRY SeZwStartTm@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwStopProfile@4, 4
KSE_SSDT_ENTRY SeZwSubscribeWnfStateChange@16, 16
KSE_SSDT_ENTRY SeZwSuspendProcess@4, 4
KSE_SSDT_ENTRY SeZwSuspendThread@8, 8
KSE_SSDT_ENTRY SeZwSystemDebugControl@24, 24
KSE_SSDT_ENTRY SeZwTerminateEnclave@8, 8
KSE_SSDT_ENTRY SeZwTerminateJobObject@8, 8
KSE_SSDT_ENTRY SeZwTerminateProcess@8, 8
KSE_SSDT_ENTRY SeZwTerminateThread@8, 8
KSE_SSDT_ENTRY SeZwTestAlert@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwThawRegistry@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwThawTransactions@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwTraceControl@24, 24
KSE_SSDT_ENTRY SeZwTraceEvent@16, 16
KSE_SSDT_ENTRY SeZwTranslateFilePath@16, 16
KSE_SSDT_ENTRY SeZwUmsThreadYield@4, 4
KSE_SSDT_ENTRY SeZwUnloadDriver@4, 4
KSE_SSDT_ENTRY SeZwUnloadKey@4, 4
KSE_SSDT_ENTRY SeZwUnloadKey2@8, 8
KSE_SSDT_ENTRY SeZwUnloadKeyEx@8, 8
KSE_SSDT_ENTRY SeZwUnlockFile@20, 20
KSE_SSDT_ENTRY SeZwUnlockVirtualMemory@16, 16
KSE_SSDT_ENTRY SeZwUnmapViewOfSection@8, 8
KSE_SSDT_ENTRY SeZwUnmapViewOfSectionEx@12, 12
KSE_SSDT_ENTRY SeZwUnsubscribeWnfStateChange@4, 4
KSE_SSDT_ENTRY SeZwUpdateWnfStateData@28, 28
KSE_SSDT_ENTRY SeZwVdmControl@8, 8
KSE_SSDT_ENTRY SeZwWaitForAlertByThreadId@8, 8
KSE_SSDT_ENTRY SeZwWaitForDebugEvent@16, 16
KSE_SSDT_ENTRY SeZwWaitForKeyedEvent@16, 16
KSE_SSDT_ENTRY SeZwWaitForMultipleObjects@20, 20
KSE_SSDT_ENTRY SeZwWaitForMultipleObjects32@20, 20
KSE_SSDT_ENTRY SeZwWaitForSingleObject@12, 12
KSE_SSDT_ENTRY SeZwWaitForWnfNotifications@0, 0
DB  2 dup (0cch)
KSE_SSDT_ENTRY SeZwWaitForWorkViaWorkerFactory@20, 20
KSE_SSDT_ENTRY SeZwWaitHighEventPair@4, 4
KSE_SSDT_ENTRY SeZwWaitLowEventPair@4, 4
KSE_SSDT_ENTRY SeZwWorkerFactoryWorkerReady@4, 4
KSE_SSDT_ENTRY SeZwWriteFile@36, 36
KSE_SSDT_ENTRY SeZwWriteFileGather@36, 36
KSE_SSDT_ENTRY SeZwWriteRequestData@24, 24
KSE_SSDT_ENTRY SeZwWriteVirtualMemory@20, 20
KSE_SSDT_ENTRY SeZwYieldExecution@0, 0
DB  2 dup (0cch)

SyscallInternal:

DB  0b8h
DB  4 dup (0ffh)
;mov eax, KiServiceTableIndex
DB  08dh, 054h, 024h, 004h
DB  09ch
DB  06ah, 008h
DB  0e8h
DB  4 dup (0ffh)
;call KiSystemService
DB  15 dup (0cch)

PUBLIC SyscallInternal

SeServiceDescriptorTableCheck PROC USES ECX EDX ESI EDI

    pushfd
    call SeRelocateSyscallTable
    popfd
    ret
DB  24 dup (0cch)

SeServiceDescriptorTableCheck ENDP

END
