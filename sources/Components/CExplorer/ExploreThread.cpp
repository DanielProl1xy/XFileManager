// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Components/CExplorer/ExploreThread.h"

namespace UI::Threads
{
    ExploreThread::ExploreThread(QObject *parent)
        : QThread(parent)
    {

    }

    void ExploreThread::SetPath(const std::string path)
    {
        m_folderPath = path;
    }

    void ExploreThread::run()
    {   
        
        std::vector<APICore::SExplorerItem> items;

        int err = APICore::ExploreFolder(m_folderPath, &items);
        if(err == 0)
        {
            emit ClearWidget();
            for(APICore::SExplorerItem item : items)
            {
                emit ItemFound(item);
            }
            emit ExploreCompleted(0);
            return;
        }
        emit ExploreCompleted(err);
    }
}