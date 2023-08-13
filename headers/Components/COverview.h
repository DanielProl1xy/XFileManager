// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include "Components.h"
#include <QTreeView>

class UI::COverview : public QTreeView
{

    Q_OBJECT

public:
    COverview(QWidget* parent = nullptr);
    ~COverview();
private:


};