// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include "Components.h"
#include <QMenuBar>
#include <QAction>
#include <QMenu>

class UI::CMainMenuBar : public QMenuBar
{
    Q_OBJECT

public:
    // create menu
    QAction *createAction;
    
    // search menu
    QAction *openSearchSettings;
    QAction *stopSearch;

public:
    CMainMenuBar(QWidget *parent = nullptr);
    ~CMainMenuBar();

private:
    QMenu *explorerMenu;
    QMenu *searchMenu;

private:
    void initActions();
};