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