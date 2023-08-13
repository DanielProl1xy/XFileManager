#include "Components/CExplorer.h"

namespace UI 
{
    CExplorer::CExplorer(QWidget *parent)
        : QListWidget(parent)
    {
        m_explorer = ACore::AFileExplore();
        initActions();
    }

    CExplorer::~CExplorer()
    {
        
    }

    void CExplorer::ExploreFolder(const std::string folderPath)
    {
        if(exploreFolder(folderPath) == ACore::ExploreResult::SUCCESS)
        {
            emit UpdateExplorerPath(folderPath.c_str());
        }   
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
        if(explorerItem->GetMeta().Type == ACore::ItemType::DIRECTORY)
        {
            std::string path = m_explorer.GetCurrentPath();
            if(path[path.length() - 1] != '\\')
            {
                path += '\\';
            }
            path += explorerItem->GetMeta().Name;
            ExploreFolder(path);
        }
    }

    void CExplorer::on_UserTypedPath(const std::string newPath)
    {
        ExploreFolder(newPath);
    }

    ACore::ExploreResult CExplorer::exploreFolder(const std::string folderPath)
    {
        std::vector<ACore::SExplorerItem> items;

        try
        {
            items = m_explorer.ExploreFolder(folderPath); 
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return ACore::ExploreResult::FAILED;
        }

        clear();

        for(ACore::SExplorerItem x : items)
        {
            CExplorerItem *item = new CExplorerItem(x);
            addItem(item);
        }
        return ACore::ExploreResult::SUCCESS;    
    }
}