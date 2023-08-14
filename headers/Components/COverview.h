// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include "Components.h"
#include "Core.h"
#include "Func/AFileExplorer.h"
#include <QTreeWidget>
#include <QStandardItemModel>
#include <QFileSystemModel>

class COverviewItem : public QStandardItem
{
    APICore::SExplorerItem itemMeta;
    
public:
    bool isExplored;
public:
    COverviewItem(APICore::SExplorerItem meta);
    ~COverviewItem() { }

public:
    APICore::SExplorerItem GetMeta() { return itemMeta; }
};

class UI::COverview : public QTreeView
{

    Q_OBJECT

public:
    COverview(QWidget* parent = nullptr);
    ~COverview();
private:
    QStandardItemModel model;
    APICore::AFileExplorer m_explorer;
private:
    void initActions();
    void exploreByItem(COverviewItem *item);
private slots:
    void on_Expanded(const QModelIndex &index);
    void on_Collapsed(const QModelIndex &index);
    

};