#include <FMMainWindow.h>

FMMainWindow *FMMainWindow::instance = nullptr;

FMMainWindow *FMMainWindow::GetInstance()
{
    if(instance == nullptr)
        instance = new FMMainWindow;

    return instance;
}

FMMainWindow::FMMainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    qDebug("window created");
}

FMMainWindow::~FMMainWindow()
{
    qDebug("window destroyed");
}