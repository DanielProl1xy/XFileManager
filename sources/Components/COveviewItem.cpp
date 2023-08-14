// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Components/COverview.h"

COverviewItem::COverviewItem(APICore::SExplorerItem meta)
    : QStandardItem(QString(meta.Name.c_str())),
    itemMeta(meta)
{
    setEditable(false);
    isExplored = false;
    if(itemMeta.Type == APICore::ItemType::DIRECTORY)
    {
        appendRow(nullptr);
    }
}