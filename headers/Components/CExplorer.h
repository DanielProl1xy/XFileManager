// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include "Components.h"
#include "Func/AFileExplorer.h"
#include "Func/ASmartSearch.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "Core.h"
#include "Components/CExplorer/ExploreThread.h"
#include "Components/CExplorer/SearchThread.h"

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

private:
    APICore::AFileExplorer m_explorer;
    APICore::ASmartSearch m_searcher;
    std::string m_currentPath;
    ExploreThread *m_eThread;
    SearchThread *m_sThread;

public:
    CExplorer(QWidget *parent = nullptr);
    ~CExplorer();

public:

    // Returns current path of explorer.
    std::string GetCurrentPath() const { return m_currentPath; }

    // Starts exploring given folderPath.
    // Adds all elements inside given folder on widget.
    // Returns true if success
    // Returns false if failed
    void ExploreFolder(const std::string folderPath);

    void StartSearch(APICore::SFindRequest request);

private slots:

    // Creates CExplorerItem based on given SExplorerItem meta.
    // And adds it to this widget.
    void addExplorerItem(APICore::SExplorerItem sItem);

signals:

    // Emmitted when the current path is changed successfully.
    void UpdateExplorerPath(const char *newPath);

public slots:
    void on_UserTypedPath(const std::string newPath);
    void on_StopSearching();

private slots:
    void on_ExploreCompleted(bool result);
    void on_ClearWidget() { clear(); }
    void on_SearchCompleted(bool result);

private slots:
    void on_ItemDoubleClick(QListWidgetItem *item);

private:
    void initActions();
};