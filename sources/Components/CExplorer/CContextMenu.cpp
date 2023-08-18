// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Components/CExplorer/CContextMenu.h"

namespace UI
{
    CContextMenu::CContextMenu(QWidget* parent)
        : QMenu(parent)
    {   
        initActions();
    }

    CContextMenu::~CContextMenu()
    {
        delete Open;
        delete Copy;
        delete Paste;
        delete Create;
        delete Delete;
        delete Rename;
    }

    void CContextMenu::initActions()
    {
        Open = new QAction("&Open");
        Create = new QAction("&Create");
        Copy = new QAction("&Copy");
        Paste = new QAction("&Paste");
        Delete = new QAction("&Delete");
        Rename = new QAction("&Rename");

        addActions({Open, Create, Copy, Paste, Delete, Rename});
    }
}