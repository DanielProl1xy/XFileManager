// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Components/CInputLine.h"

namespace UI
{
    CInputLine::CInputLine(QWidget *parent)
    : QLineEdit(parent)
    {
        
    }

    void CInputLine::keyPressEvent(QKeyEvent *event) 
    {
        if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
        {
            emit UserTypedInput();
        }
        else
        {
            QLineEdit::keyPressEvent(event);
        }
    }
}