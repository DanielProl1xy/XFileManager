// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include <QLineEdit>
#include <QKeyEvent>
#include "Components.h"

class UI::CInputLine : public QLineEdit
{
    Q_OBJECT
    
public:
    CInputLine(QWidget *parent = nullptr);
    ~CInputLine() { }

signals:
    void UserTypedInput();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};