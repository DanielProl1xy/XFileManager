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