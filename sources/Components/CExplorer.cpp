// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Components/CExplorer.h"
#include "CExplorer.h"

namespace UI 
{
    CExplorer::CExplorer(QWidget *parent)
        : QListWidget(parent)
    {
        m_searcher = APICore::ASmartSearch();
        qRegisterMetaType<APICore::SExplorerItem>("APICore::SExplorerItem");
        initActions();
    }

    CExplorer::~CExplorer()
    {   
        m_eThread->terminate();
        m_sThread->terminate();
        
        delete m_eThread;
        delete m_sThread;
    }

    void CExplorer::ExploreFolder(const std::string folderPath)
    {    
        if(m_eThread->isRunning())
        {
            m_eThread->wait();
        }    

        if(m_sThread->isRunning())
        {
            m_searcher.SearchStop();
        }

        m_eThread->SetPath(folderPath);
        m_eThread->start();

        m_tempPath = folderPath;
    }

    void CExplorer::StartSearch(APICore::SFindRequest request)
    {    
        if(m_eThread->isRunning())
        {
            m_eThread->wait();
        } 

        if(m_sThread->isRunning())
        {
            m_searcher.SearchStop();
        }

        m_sThread->SetSearcher(&m_searcher, request);
        m_sThread->start();
    }

    void CExplorer::contextMenuEvent(QContextMenuEvent *event)
    {
        m_contextMenu->exec(event->globalPos());
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

        m_contextMenu = new CContextMenu(this);
        
        connect(m_contextMenu->Open, QAction::triggered, this, CExplorer::on_openAction);
        connect(m_contextMenu->Create, QAction::triggered, this, CExplorer::on_createAction);
        connect(m_contextMenu->Copy, QAction::triggered, this, CExplorer::on_copyAction);
        connect(m_contextMenu->Paste, QAction::triggered, this, CExplorer::on_pasteAction);
        connect(m_contextMenu->Delete, QAction::triggered, this, CExplorer::on_deleteAction);
        connect(m_contextMenu->Rename, QAction::triggered, this, CExplorer::on_renameAction);

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

    void CExplorer::on_ExploreCompleted(int result)
    {
        if(result == 0)
        {
            m_currentPath = m_tempPath;
        }        
        m_tempPath.clear();
        emit UpdateExplorerPath(m_currentPath.c_str());
    }

    void CExplorer::on_StopSearching()
    {
        if(m_sThread->isRunning())
        {
            m_searcher.SearchStop();
            m_sThread->wait();
        }
    }

   
    void CExplorer::on_openAction()
    {
        NOT_IMPLEMENTED("on_openAction");
    }

    void CExplorer::on_createAction()
    {
        NOT_IMPLEMENTED("on_createAction");
    }

    void CExplorer::on_copyAction()
    {
        NOT_IMPLEMENTED("on_copyAction");
    }

    void CExplorer::on_pasteAction()
    {
        NOT_IMPLEMENTED("on_pasteAction");
    }

    void CExplorer::on_deleteAction()
    {
        NOT_IMPLEMENTED("on_deleteAction");
    }

    void CExplorer::on_renameAction()
    {
        NOT_IMPLEMENTED("on_renameAction");
    }

    void CExplorer::on_SearchCompleted(bool result)
    {
        qDebug("search completed");
    }
}