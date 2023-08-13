#pragma once

#include <Qt>
#include <string>

#define TITLE "File manager"

QT_BEGIN_NAMESPACE
namespace UI
{
    class UMainWindow;
    class USmartFindWindow;
    class UFileManagmentWindow;
    class UScriptingWindow;
}
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace ACore
{
    class AFileExplore;
    class AFileManage;
    class ASmartFind;
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
QT_END_NAMESPACE

