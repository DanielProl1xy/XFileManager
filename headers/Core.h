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

    struct SExplorerItem
    {
        ItemType Type;
        std::string Name; 
    };
}
QT_END_NAMESPACE

