// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "UMainWindow.h"

namespace UI
{

    UMainWindow::UMainWindow(const char *startPath, QWidget* parent)
        : QMainWindow(parent)
    {
        setWindowTitle(TITLE);
        initWidgets();
        initActions();
        qDebug("window created");

        filesExplorer->ExploreFolder(startPath);
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

        pathLine = new CInputLine();
        pathLine->setText("C:\\Users\\danil");
        pathLine->setMinimumHeight(30);
        pathLine->setMinimumWidth(600);
        
        fastFindLine = new CInputLine();
        fastFindLine->setText("example: \"myfile.txt\"");
        fastFindLine->setMinimumHeight(30);
        fastFindLine->setMinimumWidth(150);

        filesExplorer = new CExplorer();
        filesExplorer->setMinimumHeight(400);
        filesExplorer->setMinimumWidth(750);

        consoleLine = new CInputLine();
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
        connect(filesExplorer, &CExplorer::UpdateExplorerPath, pathLine, &QLineEdit::setText);
        connect(pathLine, &CInputLine::UserTypedInput, this, &UMainWindow::on_PathLineAccepted);
        connect(fastFindLine, &CInputLine::UserTypedInput, this, &UMainWindow::on_FindLineAccepted);
        connect(this, &UMainWindow::UserTypedPath, filesExplorer, &CExplorer::on_UserTypedPath);
    }
    
    void UMainWindow::on_PathLineAccepted()
    {
        emit UserTypedPath(pathLine->text().toStdString());
    }

    void UMainWindow::on_FindLineAccepted()
    {
        APICore::SFindRequest request;
        request.RecursionLimit = 10;
        request.Request = fastFindLine->text().toStdString();
        request.SearchPath = filesExplorer->GetCurrentPath();
        filesExplorer->StartSearch(request);
    }
}