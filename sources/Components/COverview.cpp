// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Components/COverview.h"
#include "COverview.h"
#include <QScrollBar>

namespace UI
{
    COverview::COverview(QWidget *parent)
        : QTreeView(parent)
    {
        setModel(&model);
        initActions();

        horizontalScrollBar()->setEnabled(true);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    }

    COverview::~COverview()
    {
        
    }

    void COverview::initActions()
    {
        connect(this, &COverview::expanded, this, &COverview::on_Expanded);
        connect(this, &COverview::collapsed, this, &COverview::on_Collapsed);
    }

    void COverview::on_Expanded(const QModelIndex &index)
    {
        QStandardItem *temp = model.itemFromIndex(index);
        COverviewItem *item = static_cast<COverviewItem*>(temp);
        if(item)
        {
            if(item->isExplored)
                return;
            if(item->GetMeta().Type == APICore::ItemType::DIRECTORY)
                exploreByItem(item);
        }
        resizeColumnToContents(0);
    }

    void COverview::on_Collapsed(const QModelIndex &index)
    {
        resizeColumnToContents(0);
    }

    void COverview::exploreByItem(COverviewItem *item)
    {
        std::vector<APICore::SExplorerItem> items;
        if(APICore::ExploreFolder(item->GetMeta().FullPath, &items) == 0)
        {
            item->removeRow(0);
            for(APICore::SExplorerItem exploredItem : items)
            {
                // TODO: multithreading  
                item->appendRow(new COverviewItem(exploredItem));
                item->isExplored = true;
            }
        }   
    }
}


