/*******************************************************************************
*
*  (C) COPYRIGHT AUTHORS, 2015 - 2019
*
*  TITLE:       OBJECTS.H
*
*  VERSION:     1.72
*
*  DATE:        06 Feb 2019
*
*  Header file for internal Windows object types handling.
*
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
* ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
* PARTICULAR PURPOSE.
*
*******************************************************************************/
#pragma once

//
// Description Resource Id string table starting index
//
// Actual id = TYPE_DESCRIPTION_START_INDEX + ObjectType*
//
#define TYPE_DESCRIPTION_START_INDEX    100

//
// Image Resource Id table starting index (for imagelist)
//
// Actual id = ObjectType.ImageIndex - TYPE_RESOURCE_IMAGE_INDEX_START
//
#define TYPE_RESOURCE_IMAGE_INDEX_START 300

//
// Object Type Indexes Used By Program Only 
// NOT RELATED TO REAL OBJECTS INDEXES
// ObjectTypeUnknown and ObjectTypeMax always end this list
//
typedef enum _WOBJ_OBJECT_TYPE {
    ObjectTypeDevice = 0,
    ObjectTypeDriver = 1,
    ObjectTypeSection = 2,
    ObjectTypePort = 3,
    ObjectTypeSymbolicLink = 4,
    ObjectTypeKey = 5,
    ObjectTypeEvent = 6,
    ObjectTypeJob = 7,
    ObjectTypeMutant = 8,
    ObjectTypeKeyedEvent = 9,
    ObjectTypeType = 10,
    ObjectTypeDirectory = 11,
    ObjectTypeWinstation = 12,
    ObjectTypeCallback = 13,
    ObjectTypeSemaphore = 14,
    ObjectTypeWaitablePort = 15,
    ObjectTypeTimer = 16,
    ObjectTypeSession = 17,
    ObjectTypeController = 18,
    ObjectTypeProfile = 19,
    ObjectTypeEventPair = 20,
    ObjectTypeDesktop = 21,
    ObjectTypeFile = 22,
    ObjectTypeWMIGuid = 23,
    ObjectTypeDebugObject = 24,
    ObjectTypeIoCompletion = 25,
    ObjectTypeProcess = 26,
    ObjectTypeAdapter = 27,
    ObjectTypeToken = 28,
    ObjectTypeETWRegistration = 29,
    ObjectTypeThread = 30,
    ObjectTypeTmTx = 31,
    ObjectTypeTmTm = 32,
    ObjectTypeTmRm = 33,
    ObjectTypeTmEn = 34,
    ObjectTypePcwObject = 35,
    ObjectTypeFltConnPort = 36,
    ObjectTypeFltComnPort = 37,
    ObjectTypePowerRequest = 38,
    ObjectTypeETWConsumer = 39,
    ObjectTypeTpWorkerFactory = 40,
    ObjectTypeComposition = 41,
    ObjectTypeIRTimer = 42,
    ObjectTypeDxgkSharedResource = 43,
    ObjectTypeDxgkSharedSwapChain = 44,
    ObjectTypeDxgkSharedSyncObject = 45,
    ObjectTypeDxgkCurrentDxgProcessObject = 46,
    ObjectTypeDxgkDisplayManager = 47,
    ObjectTypeDxgkSharedBundle = 48,
    ObjectTypeDxgkSharedProtectedSession = 49,
    ObjectTypeMemoryPartition = 50,
    ObjectTypeRegistryTransaction = 51,
    ObjectTypeUnknown = 52,
    ObjectTypeMax
} WOBJ_OBJECT_TYPE;

typedef struct _WOBJ_TYPE_DESC {
    LPWSTR Name;
    WOBJ_OBJECT_TYPE Index;
    UINT ImageIndex; //individual image id for each object type (maybe the same for few objects)
} WOBJ_TYPE_DESC, *PWOBJ_TYPE_DESC;

//
// ImageList icon index used from range TYPE_FIRST - TYPE_LAST
//
#define TYPE_FIRST ObjectTypeDevice
#define TYPE_LAST ObjectTypeUnknown

static const WOBJ_TYPE_DESC g_ObjectTypes[] = {
    { L"Device", ObjectTypeDevice, IDI_ICON_DEVICE },
    { L"Driver", ObjectTypeDriver, IDI_ICON_DRIVER },
    { L"Section", ObjectTypeSection, IDI_ICON_SECTION },
    { L"ALPC Port", ObjectTypePort, IDI_ICON_PORT },
    { L"SymbolicLink", ObjectTypeSymbolicLink, IDI_ICON_SYMLINK },
    { L"Key", ObjectTypeKey, IDI_ICON_KEY },
    { L"Event", ObjectTypeEvent, IDI_ICON_EVENT },
    { L"Job", ObjectTypeJob, IDI_ICON_JOB },
    { L"Mutant", ObjectTypeMutant, IDI_ICON_MUTANT },
    { L"KeyedEvent", ObjectTypeKeyedEvent, IDI_ICON_KEYEDEVENT },
    { L"Type", ObjectTypeType, IDI_ICON_TYPE },
    { L"Directory", ObjectTypeDirectory, IDI_ICON_DIRECTORY },
    { L"WindowStation", ObjectTypeWinstation, IDI_ICON_WINSTATION },
    { L"Callback", ObjectTypeCallback, IDI_ICON_CALLBACK },
    { L"Semaphore", ObjectTypeSemaphore, IDI_ICON_SEMAPHORE },
    { L"WaitablePort", ObjectTypeWaitablePort, IDI_ICON_WAITABLEPORT },
    { L"Timer", ObjectTypeTimer, IDI_ICON_TIMER },
    { L"Session", ObjectTypeSession, IDI_ICON_SESSION },
    { L"Controller", ObjectTypeController, IDI_ICON_CONTROLLER },
    { L"Profile", ObjectTypeProfile, IDI_ICON_PROFILE },
    { L"EventPair", ObjectTypeEventPair, IDI_ICON_EVENTPAIR },
    { L"Desktop", ObjectTypeDesktop, IDI_ICON_DESKTOP },
    { L"File", ObjectTypeFile, IDI_ICON_FILE },
    { L"WMIGuid", ObjectTypeWMIGuid, IDI_ICON_WMIGUID },
    { L"DebugObject", ObjectTypeDebugObject, IDI_ICON_DEBUGOBJECT },
    { L"IoCompletion", ObjectTypeIoCompletion, IDI_ICON_IOCOMPLETION },
    { L"Process", ObjectTypeProcess, IDI_ICON_PROCESS },
    { L"Adapter", ObjectTypeAdapter, IDI_ICON_ADAPTER },
    { L"Token", ObjectTypeToken, IDI_ICON_TOKEN },
    { L"EtwRegistration", ObjectTypeETWRegistration, IDI_ICON_ETWREGISTRATION },
    { L"Thread", ObjectTypeThread, IDI_ICON_THREAD },
    { L"TmTx", ObjectTypeTmTx, IDI_ICON_TMTX },
    { L"TmTm", ObjectTypeTmTm, IDI_ICON_TMTM },
    { L"TmRm", ObjectTypeTmRm, IDI_ICON_TMRM },
    { L"TmEn", ObjectTypeTmEn, IDI_ICON_TMEN },
    { L"PcwObject", ObjectTypePcwObject, IDI_ICON_PCWOBJECT },
    { L"FilterConnectionPort", ObjectTypeFltConnPort, IDI_ICON_FLTCONNPORT },
    { L"FilterCommunicationPort", ObjectTypeFltComnPort, IDI_ICON_FLTCOMMPORT },
    { L"PowerRequest", ObjectTypePowerRequest, IDI_ICON_POWERREQUEST },
    { L"EtwConsumer", ObjectTypeETWConsumer, IDI_ICON_ETWCONSUMER },
    { L"TpWorkerFactory", ObjectTypeTpWorkerFactory, IDI_ICON_TPWORKERFACTORY },
    { L"Composition", ObjectTypeComposition, IDI_ICON_COMPOSITION },
    { L"IRTimer", ObjectTypeIRTimer, IDI_ICON_IRTIMER },
    { L"DxgkSharedResource", ObjectTypeDxgkSharedResource, IDI_ICON_DXOBJECT },
    { L"DxgkSharedSwapChainObject", ObjectTypeDxgkSharedSwapChain, IDI_ICON_DXOBJECT },
    { L"DxgkSharedSyncObject", ObjectTypeDxgkSharedSyncObject, IDI_ICON_DXOBJECT },
    { L"DxgkCurrentDxgProcessObject", ObjectTypeDxgkCurrentDxgProcessObject, IDI_ICON_DXOBJECT },
    { L"DxgkDisplayManagerObject", ObjectTypeDxgkDisplayManager, IDI_ICON_DXOBJECT },
    { L"DxgkSharedBundleObject", ObjectTypeDxgkSharedBundle, IDI_ICON_DXOBJECT },
    { L"DxgkSharedProtectedSessionObject", ObjectTypeDxgkSharedProtectedSession, IDI_ICON_DXOBJECT },
    { L"Partition", ObjectTypeMemoryPartition, IDI_ICON_MEMORYPARTITION },
    { L"RegistryTransaction", ObjectTypeRegistryTransaction, IDI_ICON_KEY },
    { L"", ObjectTypeUnknown, IDI_ICON_UNKNOWN }
};


//
// Future use
//
/*

Usually none of these object types identities present in object directory (additionally depends on UnnamedObjectsOnly flag set).

ActivationObject
ActivityReference
CoreMessagining
DmaAdapter
DmaDomain
EnergyTracker
EtwSessionDemuxEntry
IoCompletionReserve
NdisCmState
PsSiloContextNonPaged
PsSiloContextPaged
RawInputManager
UserApcReserve
VirtualKey
VRegConfigurationContext
WaitCompletionPacket

*/


HIMAGELIST ObManagerLoadImageList(
    VOID);

UINT ObManagerGetIndexByTypeName(
    _In_ LPCWSTR lpTypeName);

LPWSTR ObManagerGetNameByIndex(
    _In_ ULONG TypeIndex);

UINT ObManagerGetImageIndexByTypeName(
    _In_ LPCWSTR lpTypeName);

UINT ObManagerGetImageIndexByTypeIndex(
    _In_ ULONG TypeIndex);
