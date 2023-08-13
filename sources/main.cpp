#include <QApplication>
#include <UMainWindow.h>
#include "Core.h"
#include "Func/AFileExplore.h"

using namespace UI;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);    

    UMainWindow *mainWindow = UMainWindow::GetInstance();
    mainWindow->show();

    return app.exec();
}