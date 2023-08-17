// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Components/CExplorer/ExploreThread.h"

namespace UI::Threads
{
    ExploreThread::ExploreThread(QObject *parent)
        : QThread(parent)
    {

    }

    void ExploreThread::SetExplorer(APICore::AFileExplorer *explorer, const std::string path)
    {
        m_folderPath = path;
        m_explorer = explorer;
    }

    void ExploreThread::run()
    {   
        assert(m_explorer);

        std::vector<APICore::SExplorerItem> items;

        if(m_explorer->ExploreFolder(m_folderPath, &items) == APICore::ExploreResult::SUCCESS)
        {
            emit ClearWidget();
            for(APICore::SExplorerItem item : items)
            {
                emit ItemFound(item);
            }
            emit ExploreCompleted(true);
            return;
        }
        emit ExploreCompleted(false);
    }
}