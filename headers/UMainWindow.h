// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QPushButton>
#include "Core.h"
#include "Components.h"
#include "Components/CExplorer.h"
#include "Components/COverview.h"
#include "Components/CMainMenuBar.h"
#include "Func/ASmartFind.h"

class UI::UMainWindow : public QMainWindow
{
    Q_OBJECT


public:
    static UMainWindow *GetInstance();
public:
    ~UMainWindow();

private:
    static UMainWindow *instance;

private:
    QFormLayout *formLayout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *mainWidgetLayout;
    QGroupBox *widgetsBox;
    QPushButton *backButton;
    QLineEdit *pathLine;
    QLineEdit *consoleLine;
    QLineEdit *fastFindLine;
    COverview *filesOverview;
    CExplorer *filesExplorer;
    CMainMenuBar *menuBar;
    ACore::ASmartFind *finder;

private:
    UMainWindow(QWidget* parent = nullptr);

    void initWidgets();
    void initActions();

private slots:
    void on_PathLineAccepted();
    void on_FindLineAccepted();

signals:
    void UserTypedPath(std::string newPath);

};