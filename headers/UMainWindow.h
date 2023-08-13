#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include "Core.h"
#include "Components.h"
#include "Components/CExplorer.h"
#include "Components/COverview.h"
#include "Components/CMainMenuBar.h"

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
    QLineEdit *pathLine;
    QLineEdit *consoleLine;
    QLineEdit *fastFindLine;
    COverview *filesOverview;
    CExplorer *filesExplorer;
    CMainMenuBar *menuBar;

private:
    UMainWindow(QWidget* parent = nullptr);

    void initWidgets();
    void initActions();

};