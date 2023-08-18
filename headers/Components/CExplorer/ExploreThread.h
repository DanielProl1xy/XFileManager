// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include <QThread>
#include "Core.h"
#include "Func/AFileExplorer.h"

class UI::Threads::ExploreThread : public QThread
{
    Q_OBJECT

public:
    ExploreThread(QObject *parent = nullptr);
    
    void SetPath(const std::string path);

signals:
    void ItemFound(APICore::SExplorerItem item);
    void ExploreCompleted(bool result);
    void ClearWidget();

protected:
    void run() override;

private:
    std::string m_folderPath;
};