#pragma once

#include "Components.h"
#include "Func/AFileExplore.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "Core.h"

class CExplorerItem : public QListWidgetItem
{

private:
    ACore::SExplorerItem itemMeta;
public:
    CExplorerItem(ACore::SExplorerItem meta);
    ~CExplorerItem();

    ACore::SExplorerItem GetMeta() const { return itemMeta; }
};

class UI::CExplorer : public QListWidget
{    
    
    Q_OBJECT

private:
    ACore::AFileExplore m_explorer;

public:
    CExplorer(QWidget *parent = nullptr);
    ~CExplorer();

public:
    std::string GetCurrentPath() const { return m_explorer.GetCurrentPath(); }
    void ExploreFolder(const std::string folderPath = ROOT_PATH);
    void AddExplorerItem(ACore::SExplorerItem sItem);

public slots:
    void on_UserTypedPath(const std::string newPath);

signals:
    void UpdateExplorerPath(const char *newPath);

private slots:
    void on_ItemDoubleClick(QListWidgetItem *item);

private:
    ACore::ExploreResult exploreFolder(const std::string folderPath);
    void initActions();
};