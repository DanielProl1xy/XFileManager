// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include <Qt>
#include <string>

#define TITLE "File manager"

#ifdef _WIN32
#define ROOT_PATH "C:\\"
#else
#define ROOT_PATH "/"
#endif

// Declares all UI Elements
namespace UI
{
    class UMainWindow;

    // TODO
    class USmartFindWindow;

    // TODO
    class UFileManagmentWindow;

    // TODO
    class UScriptingWindow;
}

namespace APICore
{
    class AFileExplorer;
    
    class AFileManage;

    class ASmartSearch;

    // TODO
    class AScrpiting;

    enum class ItemType
    {
        FILE,
        DIRECTORY
    };

    enum class ExploreResult
    {
        FAILED,
        SUCCESS,
    };

    struct SExplorerItem
    {
        ItemType Type;
        std::string Name; 
        std::string FullPath;
    };

    enum class FindResult
    {
        REQUEST_ACCEPTED,
        REQUEST_INVALID,
        FOUND,
        NOT_FOUND,
        FINISHED
    };

    struct SFindRequest
    {
        std::string Request;
        std::string SearchPath;        
        size_t RecursionLimit;

        bool operator==(SFindRequest& other)
        {
            return other.Request == Request && other.SearchPath == SearchPath;
        }
    };

    struct SFindResult
    {
        ExploreResult Result;
        SExplorerItem Item;
    };
}

