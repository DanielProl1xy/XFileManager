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
       

        explorerMenu = new QMenu("&Explorer");

        createAction = new QAction("&Create");

        explorerMenu->addAction(createAction);

        searchMenu = new QMenu("&Search");

        openSearchSettings = new QAction("&Settings");
        stopSearch = new QAction("&Stop searching");

        searchMenu->addAction(openSearchSettings);
        searchMenu->addAction(stopSearch);

        addMenu(explorerMenu);
        addMenu(searchMenu);
    }
}
