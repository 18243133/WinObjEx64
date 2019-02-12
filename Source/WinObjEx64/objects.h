/*******************************************************************************
*
*  (C) COPYRIGHT AUTHORS, 2015 - 2019
*
*  TITLE:       OBJECTS.H
*
*  VERSION:     1.72
*
*  DATE:        09 Feb 2019
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
    ObjectTypeDxgkComposition = 50,
    ObjectTypeDxgkSharedKeyedMutext = 51,
    ObjectTypeMemoryPartition = 52,
    ObjectTypeRegistryTransaction = 53,
    ObjectTypeUnknown = 54,
    ObjectTypeMax
} WOBJ_OBJECT_TYPE;

typedef struct _WOBJ_TYPE_DESC {
    LPWSTR Name;
    WOBJ_OBJECT_TYPE Index; //object type
    INT ResourceImageId; //resouce id for icon
    INT ResourceStringId; //resource id in stringtable
    UINT SelfIndex; //array index
    INT ImageIndex; //individual image id for each object type (maybe the same for few objects)
} WOBJ_TYPE_DESC, *PWOBJ_TYPE_DESC;

//
// ImageList icon index used from range TYPE_FIRST - TYPE_LAST
//
#define TYPE_FIRST 0
#define TYPE_LAST ObjectTypeUnknown

#define OBTYPE_NAME_DESKTOP         L"Desktop"
#define OBTYPE_NAME_DEVICE          L"Device"
#define OBTYPE_NAME_DRIVER          L"Driver"
#define OBTYPE_NAME_DIRECTORY       L"Directory"
#define OBTYPE_NAME_SECTION         L"Section"
#define OBTYPE_NAME_SYMBOLIC_LINK   L"SymbolicLink"
#define OBTYPE_NAME_TYPE            L"Type"
#define OBTYPE_NAME_WINSTATION      L"WindowStation"
#define OBTYPE_NAME_UNKNOWN         L""

//
// Handled object types.
//
// ObjectTypeUnknown must be always last.
//
static WOBJ_TYPE_DESC g_ObjectTypes[] = {
    {
        L"Adapter",
        ObjectTypeAdapter,
        IDI_ICON_ADAPTER,
        IDS_DESC_ADAPTER,
        0,
        I_IMAGENONE
    },
    {
        L"ALPC Port",
        ObjectTypePort,
        IDI_ICON_PORT,
        IDS_DESC_PORT,
        0,
        I_IMAGENONE
    },
    {
        L"Callback",
        ObjectTypeCallback,
        IDI_ICON_CALLBACK,
        IDS_DESC_CALLBACK,
        0,
        I_IMAGENONE
    },
    { 
        L"Composition", 
        ObjectTypeComposition, 
        IDI_ICON_COMPOSITION,
        IDS_DESC_COMPOSITION,
        0,
        I_IMAGENONE
    },
    { 
        L"Controller", 
        ObjectTypeController, 
        IDI_ICON_CONTROLLER,
        IDS_DESC_CONTROLLER,
        0,
        I_IMAGENONE
    },
    { 
        L"DebugObject", 
        ObjectTypeDebugObject, 
        IDI_ICON_DEBUGOBJECT,
        IDS_DESC_DEBUGOBJECT,
        0,
        I_IMAGENONE
    },
    { 
        OBTYPE_NAME_DESKTOP, 
        ObjectTypeDesktop, 
        IDI_ICON_DESKTOP,
        IDS_DESC_DESKTOP,
        0,
        I_IMAGENONE
    },
    { 
        OBTYPE_NAME_DEVICE, 
        ObjectTypeDevice, 
        IDI_ICON_DEVICE,
        IDS_DESC_DEVICE,
        0,
        I_IMAGENONE
    },
    { 
        OBTYPE_NAME_DIRECTORY, 
        ObjectTypeDirectory, 
        IDI_ICON_DIRECTORY,
        IDS_DESC_DIRECTORY,
        0,
        I_IMAGENONE
    },
    { 
        OBTYPE_NAME_DRIVER, 
        ObjectTypeDriver, 
        IDI_ICON_DRIVER,
        IDS_DESC_DRIVER,
        0,
        I_IMAGENONE
    },
    { 
        L"DxgkCompositionObject", 
        ObjectTypeDxgkComposition, 
        IDI_ICON_DXOBJECT,
        IDS_DESC_DXGK_COMPOSITION_OBJECT,
        0,
        I_IMAGENONE
    },
    { 
        L"DxgkCurrentDxgProcessObject", 
        ObjectTypeDxgkCurrentDxgProcessObject, 
        IDI_ICON_DXOBJECT,
        IDS_DESC_DXGK_CURRENT_DXG_PROCESS_OBJECT,
        0,
        I_IMAGENONE
    },
    { 
        L"DxgkDisplayManagerObject", 
        ObjectTypeDxgkDisplayManager, 
        IDI_ICON_DXOBJECT,
        IDS_DESC_DXGK_DISPLAY_MANAGER_OBJECT,
        0,
        I_IMAGENONE
    },
    { 
        L"DxgkSharedBundleObject", 
        ObjectTypeDxgkSharedBundle, 
        IDI_ICON_DXOBJECT,
        IDS_DESC_DXGK_SHARED_BUNDLE_OBJECT,
        0,
        I_IMAGENONE
    },
    { 
        L"DxgkSharedKeyedMutextObject", 
        ObjectTypeDxgkSharedKeyedMutext, 
        IDI_ICON_DXOBJECT,
        IDS_DESC_DXGK_SHARED_KEYED_MUTEX_OBJECT,
        0,
        I_IMAGENONE
    },
    { 
        L"DxgkSharedProtectedSessionObject", 
        ObjectTypeDxgkSharedProtectedSession, 
        IDI_ICON_DXOBJECT,
        IDS_DESC_DXGK_SHARED_PROTECTED_SESSION_OBJECT,
        0,
        I_IMAGENONE       
    },
    { 
        L"DxgkSharedResource", 
        ObjectTypeDxgkSharedResource, 
        IDI_ICON_DXOBJECT,
        IDS_DESC_DXGKSHAREDRES,
        0,
        I_IMAGENONE
    },
    { 
        L"DxgkSharedSwapChainObject", 
        ObjectTypeDxgkSharedSwapChain, 
        IDI_ICON_DXOBJECT,
        IDS_DESC_DXGKSHAREDSWAPCHAIN,
        0,
        I_IMAGENONE
    },
    { 
        L"DxgkSharedSyncObject", 
        ObjectTypeDxgkSharedSyncObject, 
        IDI_ICON_DXOBJECT,
        IDS_DESC_DXGKSHAREDSYNC,
        0,
        I_IMAGENONE
    },
    { 
        L"EtwConsumer", 
        ObjectTypeETWConsumer, 
        IDI_ICON_ETWCONSUMER,
        IDS_DESC_ETWCONSUMER,
        0,
        I_IMAGENONE
    },
    { 
        L"EtwRegistration", 
        ObjectTypeETWRegistration, 
        IDI_ICON_ETWREGISTRATION,
        IDS_DESC_ETWREGISTRATION,
        0,
        I_IMAGENONE
    },
    { 
        L"Event", 
        ObjectTypeEvent, 
        IDI_ICON_EVENT,
        IDS_DESC_EVENT,
        0,
        I_IMAGENONE
    },
    { 
        L"EventPair", 
        ObjectTypeEventPair, 
        IDI_ICON_EVENTPAIR,
        IDS_DESC_EVENTPAIR,
        0,
        I_IMAGENONE
    },
    { 
        L"File", 
        ObjectTypeFile, 
        IDI_ICON_FILE,
        IDS_DESC_FILE,
        0,
        I_IMAGENONE
    },
    { 
        L"FilterCommunicationPort", 
        ObjectTypeFltComnPort, 
        IDI_ICON_FLTCOMMPORT,
        IDS_DESC_FLT_COMM_PORT,
        0,
        I_IMAGENONE
    },
    { 
        L"FilterConnectionPort", 
        ObjectTypeFltConnPort, 
        IDI_ICON_FLTCONNPORT,
        IDS_DESC_FLT_CONN_PORT,
        0,
        I_IMAGENONE
    },
    { 
        L"IoCompletion", 
        ObjectTypeIoCompletion, 
        IDI_ICON_IOCOMPLETION,
        IDS_DESC_IOCOMPLETION,
        0,
        I_IMAGENONE
    },
    { 
        L"IRTimer", 
        ObjectTypeIRTimer, 
        IDI_ICON_IRTIMER,
        IDS_DESC_IRTIMER,
        0,
        I_IMAGENONE
    },
    { 
        L"Job", 
        ObjectTypeJob, 
        IDI_ICON_JOB,
        IDS_DESC_JOB,
        0,
        I_IMAGENONE
    },
    { 
        L"Key", 
        ObjectTypeKey, 
        IDI_ICON_KEY,
        IDS_DESC_KEY,
        0,
        I_IMAGENONE
    },
    { 
        L"KeyedEvent", 
        ObjectTypeKeyedEvent, 
        IDI_ICON_KEYEDEVENT,
        IDS_DESC_KEYEDEVENT,
        0,
        I_IMAGENONE
    },
    { 
        L"Mutant", 
        ObjectTypeMutant, 
        IDI_ICON_MUTANT,
        IDS_DESC_MUTANT,
        0,
        I_IMAGENONE
    },
    { 
        L"Partition", 
        ObjectTypeMemoryPartition, 
        IDI_ICON_MEMORYPARTITION,
        IDS_DESC_MEMORY_PARTITION,
        0,
        I_IMAGENONE
    },
    { 
        L"PcwObject", 
        ObjectTypePcwObject, 
        IDI_ICON_PCWOBJECT,
        IDS_DESC_PCWOBJECT,
        0,
        I_IMAGENONE
    },
    { 
        L"PowerRequest", 
        ObjectTypePowerRequest, 
        IDI_ICON_POWERREQUEST,
        IDS_DESC_POWERREQUEST,
        0,
        I_IMAGENONE
    },
    { 
        L"Process", 
        ObjectTypeProcess, 
        IDI_ICON_PROCESS,
        IDS_DESC_PROCESS,
        0,
        I_IMAGENONE
    },
    { 
        L"Profile", 
        ObjectTypeProfile, 
        IDI_ICON_PROFILE,
        IDS_DESC_PROFILE,
        0,
        I_IMAGENONE
    },
    { 
        L"RegistryTransaction", 
        ObjectTypeRegistryTransaction, 
        IDI_ICON_KEY,
        IDS_DESC_REGISTRY_TRANSACTION,
        0,
        I_IMAGENONE
    },
    { 
        OBTYPE_NAME_SECTION, 
        ObjectTypeSection, 
        IDI_ICON_SECTION,
        IDS_DESC_SECTION,
        0,
        I_IMAGENONE
    },
    { 
        L"Semaphore", 
        ObjectTypeSemaphore, 
        IDI_ICON_SEMAPHORE,
        IDS_DESC_SEMAPHORE,
        0,
        I_IMAGENONE
    },
    { 
        L"Session", 
        ObjectTypeSession, 
        IDI_ICON_SESSION,
        IDS_DESC_SESSION,
        0,
        I_IMAGENONE
    },
    { 
        L"SymbolicLink", 
        ObjectTypeSymbolicLink, 
        IDI_ICON_SYMLINK,
        IDS_DESC_SYMLINK,
        0,
        I_IMAGENONE
    },
    { 
        L"Thread", 
        ObjectTypeThread, 
        IDI_ICON_THREAD,
        IDS_DESC_THREAD,
        0,
        I_IMAGENONE
    },
    { 
        L"Timer", 
        ObjectTypeTimer, 
        IDI_ICON_TIMER,
        IDS_DESC_TIMER,
        0,
        I_IMAGENONE
    },
    { 
        L"TmEn", 
        ObjectTypeTmEn, 
        IDI_ICON_TMEN,
        IDS_DESC_TMEN,
        0,
        I_IMAGENONE
    },
    { 
        L"TmRm", 
        ObjectTypeTmRm, 
        IDI_ICON_TMRM,
        IDS_DESC_TMRM,
        0,
        I_IMAGENONE
    },
    { 
        L"TmTm", 
        ObjectTypeTmTm, 
        IDI_ICON_TMTM,
        IDS_DESC_TMTM,
        0,
        I_IMAGENONE
    },
    { 
        L"TmTx", 
        ObjectTypeTmTx, 
        IDI_ICON_TMTX,
        IDS_DESC_TMTX,
        0,
        I_IMAGENONE
    },
    { 
        L"Token", 
        ObjectTypeToken, 
        IDI_ICON_TOKEN,
        IDS_DESC_TOKEN,
        0,
        I_IMAGENONE
    },
    { 
        L"TpWorkerFactory", 
        ObjectTypeTpWorkerFactory, 
        IDI_ICON_TPWORKERFACTORY,
        IDS_DESC_TPWORKERFACTORY,
        0,
        I_IMAGENONE
    },
    { 
        OBTYPE_NAME_TYPE, 
        ObjectTypeType, 
        IDI_ICON_TYPE,
        IDS_DESC_TYPE,
        0,
        I_IMAGENONE
    },
    { 
        L"WaitablePort", 
        ObjectTypeWaitablePort, 
        IDI_ICON_WAITABLEPORT,
        IDS_DESC_WAITABLEPORT,
        0,
        I_IMAGENONE
    },
    { 
        OBTYPE_NAME_WINSTATION, 
        ObjectTypeWinstation, 
        IDI_ICON_WINSTATION,
        IDS_DESC_WINSTATION,
        0,
        I_IMAGENONE
    },
    { 
        L"WMIGuid", 
        ObjectTypeWMIGuid, 
        IDI_ICON_WMIGUID,
        IDS_DESC_WMIGUID,
        0,
        I_IMAGENONE
    },
    { 
        OBTYPE_NAME_UNKNOWN,
        ObjectTypeUnknown, 
        IDI_ICON_UNKNOWN,
        IDS_DESC_UNKNOWN,
        0,
        I_IMAGENONE
    }
};

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

WOBJ_TYPE_DESC *ObManagerGetEntryByTypeName(
    _In_ LPCWSTR lpTypeName);
