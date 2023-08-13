// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include"Components/CMainMenuBar.h"

namespace UI
{
    CMainMenuBar::CMainMenuBar(QWidget *parent)
    : QMenuBar(parent)
    {
        initActions();
    }

    CMainMenuBar::~CMainMenuBar()
    {   

    }

    void CMainMenuBar::initActions()
    {
        createFile = new QAction("&File");
        createFolder = new QAction("&Folder");

        createMenu = new QMenu("&Create");
        createMenu->addAction(createFile);
        createMenu->addAction(createFolder);

        addMenu(createMenu);
    }
}
