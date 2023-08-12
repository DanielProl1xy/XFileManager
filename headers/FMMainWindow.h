#pragma once

#include <QMainWindow>

class FMMainWindow : public QMainWindow
{
    Q_OBJECT


public:
    static FMMainWindow *GetInstance();
public:
    ~FMMainWindow();

private:
    static FMMainWindow *instance;

private:
    FMMainWindow(QWidget* parent = nullptr);

};