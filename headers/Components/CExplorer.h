// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include "Components.h"
#include "Func/AFileExplorer.h"
#include "Func/ASmartSearch.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "Core.h"

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
    bool ExploreFolder(const std::string folderPath);

private:

    // Creates CExplorerItem based on given SExplorerItem meta.
    // And adds it to this widget.
    void addExplorerItem(APICore::SExplorerItem sItem);

signals:

    // Emmitted when the current path is changed successfully.
    void UpdateExplorerPath(const char *newPath);

public slots:
    void on_UserTypedPath(const std::string newPath);

private slots:
    void on_ItemDoubleClick(QListWidgetItem *item);

private:
    void initActions();
};