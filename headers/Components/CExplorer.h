// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include "Components.h"
#include "Func/AFileExplorer.h"
#include "Func/ASmartSearch.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QContextMenuEvent>
#include "Core.h"
#include "Components/CExplorer/ExploreThread.h"
#include "Components/CExplorer/SearchThread.h"
#include "Components/CExplorer/CContextMenu.h"

using namespace UI::Threads;

class CExplorerItem : public QListWidgetItem
{

private:
    APICore::SExplorerItem itemMeta;
public:
    CExplorerItem(APICore::SExplorerItem meta);
    ~CExplorerItem();

    APICore::SExplorerItem GetMeta() const { return itemMeta; }
};

class UI::CExplorer : public QListWidget
{    
    
    Q_OBJECT


public:
    CExplorer(QWidget *parent = nullptr);
    ~CExplorer();

public:

    // Returns current path of explorer.
    std::string GetCurrentPath() const { return m_currentPath; }

    // Starts exploring given folderPath.
    // Adds all elements from given folder on widget.
    void ExploreFolder(const std::string folderPath);

    void StartSearch(APICore::SFindRequest request);

signals:

    // Emmitted when the current path is changed successfully.
    void UpdateExplorerPath(const char *newPath);

protected:

    #ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event);
    #endif

private slots:

    // Creates CExplorerItem based on given SExplorerItem meta.
    // And adds it to this widget.
    void addExplorerItem(APICore::SExplorerItem sItem);

private:
    APICore::ASmartSearch m_searcher;
    std::string m_currentPath;
    std::string m_tempPath;
    ExploreThread *m_eThread;
    SearchThread *m_sThread;
    CContextMenu *m_contextMenu;


public slots:
    void on_UserTypedPath(const std::string newPath);
    void on_StopSearching();

private slots:
    void on_openAction();
    void on_createAction();
    void on_copyAction();
    void on_pasteAction();
    void on_deleteAction();
    void on_renameAction();

    void on_ExploreCompleted(int result);
    void on_ClearWidget() { clear(); }
    void on_SearchCompleted(bool result);
    void on_ItemDoubleClick(QListWidgetItem *item);

private:
    void initActions();
};