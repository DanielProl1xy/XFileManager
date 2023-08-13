#pragma once

#include "Components.h"
#include "Core.h"
#include "Func/AFileExplore.h"
#include <QListWidget>
#include <QListWidgetItem>

class CExplorerItem : public QListWidgetItem
{

private:
    ACore::SExplorerItem itemMeta;
public:
    CExplorerItem(ACore::SExplorerItem meta);
    ~CExplorerItem();
};

class UI::CExplorer : public QListWidget
{
    
    Q_OBJECT
    
private:
    ACore::AFileExplore m_explorer;

public:
    CExplorer(QWidget *parent = nullptr);
    ~CExplorer();
};