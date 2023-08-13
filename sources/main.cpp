// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include <QApplication>
#include <UMainWindow.h>

using namespace UI;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);    

    UMainWindow *mainWindow = UMainWindow::GetInstance();
    mainWindow->show();

    return app.exec();
}