// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Components/CExplorer.h"
#include "CExplorer.h"

namespace UI 
{
    CExplorer::CExplorer(QWidget *parent)
        : QListWidget(parent)
    {
        m_explorer = APICore::AFileExplorer();
        initActions();
    }

    CExplorer::~CExplorer()
    {
        
    }

    bool CExplorer::ExploreFolder(const std::string folderPath)
    {
        std::vector<APICore::SExplorerItem> items;

        if(m_explorer.ExploreFolder(folderPath, &items) == APICore::ExploreResult::SUCCESS)
        {
            clear();
            m_currentPath = folderPath;
            for(APICore::SExplorerItem item : items)
            {
                // TODO: multithreading
                addExplorerItem(item);
            }
            emit UpdateExplorerPath(folderPath.c_str());

            return true;
        }

        return false;
    }

    void CExplorer::addExplorerItem(APICore::SExplorerItem sItem)
    {
        CExplorerItem *item = new CExplorerItem(sItem);
        addItem(item);
    }

    void CExplorer::initActions()
    {
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
}