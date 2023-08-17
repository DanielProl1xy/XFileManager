// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QKeyEvent>
#include <QPushButton>
#include "Core.h"
#include "Components.h"
#include "Components/CExplorer.h"
#include "Components/COverview.h"
#include "Components/CMainMenuBar.h"
#include "Components/CInputLine.h"

class UI::UMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ~UMainWindow();
    UMainWindow(const char *startPath, QWidget* parent = nullptr);

signals:
    void UserTypedPath(std::string newPath);
        
private:
    QFormLayout *formLayout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *mainWidgetLayout;
    QGroupBox *widgetsBox;
    QPushButton *backButton;
    CInputLine *pathLine;
    CInputLine *consoleLine;
    CInputLine *fastFindLine;
    COverview *filesOverview;
    CExplorer *filesExplorer;
    CMainMenuBar *menuBar;

private:    
    void initWidgets();
    void initActions();

private slots:
    void on_PathLineAccepted();
    void on_FindLineAccepted();
    
};