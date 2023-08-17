// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Components/CExplorer.h"
#include "CExplorer.h"

namespace UI 
{
    CExplorer::CExplorer(QWidget *parent)
        : QListWidget(parent)
    {
        m_explorer = APICore::AFileExplorer();
        m_searcher = APICore::ASmartSearch();
        qRegisterMetaType<APICore::SExplorerItem>("APICore::SExplorerItem");
        initActions();
    }

    CExplorer::~CExplorer()
    {
        
    }

    void CExplorer::ExploreFolder(const std::string folderPath)
    {        
        if(m_eThread->isRunning())
            m_eThread->terminate();
        m_eThread->SetExplorer(&m_explorer, folderPath);        

        m_eThread->start();

        m_currentPath = folderPath;
    }

    void CExplorer::StartSearch(APICore::SFindRequest request)
    {       
        if(m_sThread->isRunning())
            m_sThread->terminate();
        m_sThread->SetSearcher(&m_searcher, request);
        m_sThread->start();
    }

    void CExplorer::addExplorerItem(APICore::SExplorerItem sItem)
    {
        CExplorerItem *item = new CExplorerItem(sItem);
        addItem(item);
    }

    void CExplorer::initActions()
    {
        m_eThread = new ExploreThread(this);

        connect(m_eThread, &ExploreThread::ItemFound, this, &CExplorer::addExplorerItem);
        connect(m_eThread, &ExploreThread::ClearWidget, this, &CExplorer::on_ClearWidget);
        connect(m_eThread, &ExploreThread::ExploreCompleted, this, &CExplorer::on_ExploreCompleted);

        m_sThread = new SearchThread(this);

        connect(m_sThread, &SearchThread::ItemFound, this, &CExplorer::addExplorerItem);
        connect(m_sThread, &SearchThread::SearchCompleted, this, &CExplorer::on_SearchCompleted);        
        connect(m_sThread, &SearchThread::ClearWidget, this, &CExplorer::on_ClearWidget);

        connect(this, &CExplorer::itemDoubleClicked, this, &CExplorer::on_ItemDoubleClick);
    }

    void CExplorer::on_ItemDoubleClick(QListWidgetItem *item)
    {
        CExplorerItem *explorerItem = static_cast<CExplorerItem*>(item);
        if(!explorerItem)
            return;
        if(explorerItem->GetMeta().Type == APICore::ItemType::DIRECTORY)
        {
            ExploreFolder(explorerItem->GetMeta().FullPath);
        }
    }

    void CExplorer::on_UserTypedPath(const std::string newPath)
    {
        ExploreFolder(newPath);
    }

    void CExplorer::on_ExploreCompleted(bool result)
    {
        if(result)
        {
            emit UpdateExplorerPath(m_currentPath.c_str());
        }
        else
        {
            ExploreFolder(ROOT_PATH);
        }
    }

    void CExplorer::on_StopSearching()
    {
        if(m_sThread->isRunning())
            m_sThread->terminate();
    }

    void CExplorer::on_SearchCompleted(bool result)
    {
        if(result)
        {
            qDebug("Completed");
        }
        else
        {
            qDebug("Not completed");
        }
    }
}