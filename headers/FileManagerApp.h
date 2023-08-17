// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include <QApplication>
#include <QVector>
#include <QStringList>
#include <UMainWindow.h>

namespace Application
{
    class FileManagerApp : public QApplication
    {
        Q_OBJECT

        // Stores all UI::UMainWindow opened in this application
        QVector<UI::UMainWindow*> mUis;
        bool inited;

    public:
        FileManagerApp(int argc, char *argv[]);
        ~FileManagerApp();

    public:
    
        // Initializes this FileManagerApp.
        void InitApplication();

        // Initializes a new UI::UMainWindow with the given startPath.
        // The default startPatth is the root path of the file system.
        UI::UMainWindow *InitWindow(const char *startPath = ROOT_PATH);

    };
}

