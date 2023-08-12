#include <QApplication>
#include <FMMainWindow.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    FMMainWindow *mainWindow = FMMainWindow::GetInstance();
    mainWindow->show();
    
    return app.exec();
}