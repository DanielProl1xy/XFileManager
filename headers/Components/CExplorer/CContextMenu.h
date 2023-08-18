// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include "Components.h"
#include <QMenu>
#include <QAction>

// Context menu which calls by clicking RMB in CExplorer widget
// Actions
// Open
// Copy
// Paste
// Delete
// Rename

class UI::CContextMenu : public QMenu
{

    Q_OBJECT

public:
    explicit CContextMenu(QWidget *parent = nullptr);
    ~CContextMenu();

public:
    QAction* Open;
    QAction* Copy;
    QAction* Paste;
    QAction* Create;
    QAction* Delete;
    QAction* Rename;

private:
    void initActions();
};