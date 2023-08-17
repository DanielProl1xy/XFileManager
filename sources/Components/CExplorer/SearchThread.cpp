// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Components/CExplorer/SearchThread.h"


namespace UI::Threads
{
    SearchThread::SearchThread(QObject *parent)
        : QThread(parent)
    {

    }

    void SearchThread::SetSearcher(APICore::ASmartSearch *searcher, APICore::SFindRequest request)
    {
        m_request = request;
        m_searcher = searcher;
    }

    void SearchThread::run()
    {
        if(m_searcher->SearchFor(m_request) == APICore::FindResult::REQUEST_ACCEPTED)
        {
            emit ClearWidget();
            APICore::SExplorerItem item;
            APICore::FindResult res = m_searcher->SearchGetNext(&item);
            while(res != APICore::FindResult::FINISHED)
            {
                if(res == APICore::FindResult::FOUND)                
                    emit ItemFound(item);
                res = m_searcher->SearchGetNext(&item);
            }
            emit SearchCompleted(true);
            return;
        }
        emit SearchCompleted(false);
    }
}