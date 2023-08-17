// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "FileManagerApp.h"

namespace Application
{
    FileManagerApp::FileManagerApp(int argc, char *argv[])
        : QApplication(argc, argv)
    {

    }

    FileManagerApp::~FileManagerApp()
    {

    }

    void FileManagerApp::InitApplication()
    {   
        if(inited)
            return;
        int argsCount = arguments().size();
        if(argsCount > 1)
        {
            const char *startPath = arguments()[1].toStdString().c_str();
            qDebug(startPath);
            InitWindow(startPath);
        }
        else
        {
            InitWindow();
        }
        inited = true;
    }

    UI::UMainWindow *FileManagerApp::InitWindow(const char *startPath)
    {
        UI::UMainWindow *window = new UI::UMainWindow(startPath);
        if(window)
        {            
            window->show();
            mUis.append(window);
        }
        return window;
    }
}