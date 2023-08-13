#pragma once

#include "Components.h"
#include <QMenuBar>
#include <QAction>
#include <QMenu>

class UI::CMainMenuBar : public QMenuBar
{
    Q_OBJECT

public:
    QAction *createFile;
    QAction *createFolder;

public:
    CMainMenuBar(QWidget *parent = nullptr);
    ~CMainMenuBar();

private:
    QMenu *createMenu;

private:
    void initActions();
};