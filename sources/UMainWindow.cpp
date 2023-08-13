#include "UMainWindow.h"

namespace UI
{
    UMainWindow *UMainWindow::instance = nullptr;

    UMainWindow *UMainWindow::GetInstance()
    {
        if(instance == nullptr)
            instance = new UMainWindow;

        return instance;
    }

    UMainWindow::UMainWindow(QWidget* parent)
        : QMainWindow(parent)
    {
        setWindowTitle(TITLE);
        initWidgets();
        qDebug("window created");
    }

    UMainWindow::~UMainWindow()
    {
        qDebug("window destroyed");
    }

    void UMainWindow::initWidgets()
    {
        QWidget *widget = new QWidget();
        setCentralWidget(widget);

        menuBar = new CMainMenuBar(this);
        setMenuBar(menuBar);

        filesOverview = new COverview();
        filesOverview->setMinimumHeight(300);
        filesOverview->setMinimumWidth(180);
        filesOverview->setMaximumWidth(220);

        pathLine = new QLineEdit();
        pathLine->setText("C:\\Users\\danil");
        pathLine->setMinimumHeight(30);
        pathLine->setMinimumWidth(600);
        
        fastFindLine = new QLineEdit();
        fastFindLine->setText("example: \"myfile.txt\"");
        fastFindLine->setMinimumHeight(30);
        fastFindLine->setMinimumWidth(150);

        filesExplorer = new CExplorer();
        filesExplorer->setMinimumHeight(400);
        filesExplorer->setMinimumWidth(750);

        consoleLine = new QLineEdit();
        consoleLine->setMinimumHeight(30);
        consoleLine->setMinimumWidth(750);

        vboxLayout = new QVBoxLayout();
        vboxLayout->addWidget(filesOverview);

        formLayout = new QFormLayout();
        formLayout->addRow(pathLine,fastFindLine);
        formLayout->addRow(filesExplorer);
        formLayout->addRow(consoleLine);

        mainWidgetLayout = new QHBoxLayout(widget);
        mainWidgetLayout->addLayout(vboxLayout);
        mainWidgetLayout->addLayout(formLayout);
    }

    void UMainWindow::initActions()
    {

    }
}