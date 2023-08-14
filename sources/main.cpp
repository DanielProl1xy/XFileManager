// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "FileManagerApp.h"

int main(int argc, char *argv[])
{
    Application::FileManagerApp app = Application::FileManagerApp(argc, argv);

    app.InitApplication();

    return app.exec();
}