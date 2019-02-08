/*******************************************************************************
*
*  (C) COPYRIGHT AUTHORS, 2017 - 2019
*
*  TITLE:       OBJECTS.C
*
*  VERSION:     1.72
*
*  DATE:        06 Feb 2019
*
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
* ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
* PARTICULAR PURPOSE.
*
*******************************************************************************/

#include "global.h"

//
// Convert resource image id to image list index.
//
#define ID_TO_IMAGEID(id) (id) - TYPE_RESOURCE_IMAGE_INDEX_START

/*
* ObManagerGetNameByIndex
*
* Purpose:
*
* Returns object name by index of known type.
*
*
*/
LPWSTR ObManagerGetNameByIndex(
    _In_ ULONG TypeIndex
)
{
    if (TypeIndex >= ObjectTypeMax)
        return g_ObjectTypes[ObjectTypeUnknown].Name;

    return g_ObjectTypes[TypeIndex].Name;
}

/*
* ObManagerGetImageIndexByTypeIndex
*
* Purpose:
*
* Returns object image index by index of known type.
*
*
*/
UINT ObManagerGetImageIndexByTypeIndex(
    _In_ ULONG TypeIndex
)
{
    if (TypeIndex >= ObjectTypeMax)
        return ObjectTypeUnknown;

    return ID_TO_IMAGEID(g_ObjectTypes[TypeIndex].ImageIndex);
}

/*
* ObManagerGetIndexByTypeName
*
* Purpose:
*
* Returns object index of known type.
*
*/
UINT ObManagerGetIndexByTypeName(
    _In_ LPCWSTR lpTypeName
)
{
    UINT nIndex;

    if (lpTypeName == NULL) {
        return ObjectTypeUnknown;
    }

    for (nIndex = TYPE_FIRST; nIndex < TYPE_LAST; nIndex++) {
        if (_strcmpi(lpTypeName, g_ObjectTypes[nIndex].Name) == 0)
            return nIndex;
    }

    //
    // In Win8 the following Win32k object was named 
    // CompositionSurface, in Win8.1 MS renamed it to
    // Composition, handle this.
    //
    if (_strcmpi(lpTypeName, L"CompositionSurface") == 0) {
        return ObjectTypeComposition;
    }

    //
    // In Win10 TH1 the following ntos object was named 
    // NetworkNamespace, later in Win10 updates MS renamed it to
    // NdisCmState, handle this.
    //
   /*
    if (_strcmpi(lpTypeName, L"NetworkNamespace") == 0) {
        return ObjectTypeNdisCmState;
    }
    */

    return ObjectTypeUnknown;
}

/*
* ObManagerGetImageIndexByTypeName
*
* Purpose:
*
* Returns object image index of known type.
*
*/
UINT ObManagerGetImageIndexByTypeName(
    _In_ LPCWSTR lpTypeName
)
{
    UINT nIndex;

    if (lpTypeName == NULL) {
        return ObjectTypeUnknown;
    }

    for (nIndex = TYPE_FIRST; nIndex < TYPE_LAST; nIndex++) {
        if (_strcmpi(lpTypeName, g_ObjectTypes[nIndex].Name) == 0)
            return ID_TO_IMAGEID(g_ObjectTypes[nIndex].ImageIndex);
    }

    //
    // In Win8 the following Win32k object was named 
    // CompositionSurface, in Win8.1 MS renamed it to
    // Composition, handle this.
    //
    if (_strcmpi(lpTypeName, L"CompositionSurface") == 0) {
        return ID_TO_IMAGEID(g_ObjectTypes[nIndex].ImageIndex);
    }

    //
    // In Win10 TH1 the following ntos object was named 
    // NetworkNamespace, later in Win10 updates MS renamed it to
    // NdisCmState, handle this.
    //
    /*    
    if (_strcmpi(lpTypeName, L"NetworkNamespace") == 0) {
        return ID_TO_IMAGEID(g_ObjectTypes[nIndex].ImageIndex); 
    }
    */

    return ObjectTypeUnknown;
}

/*
* ObManagerLoadImageList
*
* Purpose:
*
* Create and load image list from icon resource type.
*
*/
HIMAGELIST ObManagerLoadImageList(
    VOID
)
{
    UINT       i;
    HIMAGELIST list;
    HICON      hIcon;

    list = ImageList_Create(
        16, 
        16, 
        ILC_COLOR32 | ILC_MASK,
        TYPE_LAST, 
        8);

    if (list) {
        for (i = TYPE_FIRST; i <= TYPE_LAST; i++) { //must include ObjectTypeUnknown
                       
            hIcon = (HICON)LoadImage(g_WinObj.hInstance, 
                MAKEINTRESOURCE(g_ObjectTypes[i].ImageIndex),
                IMAGE_ICON, 
                16, 
                16, 
                LR_DEFAULTCOLOR);

            if (hIcon) {
                ImageList_ReplaceIcon(list, -1, hIcon);
                DestroyIcon(hIcon);
            }
        }
    }
    return list;
}
