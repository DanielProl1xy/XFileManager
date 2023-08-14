// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Components/CExplorer.h"

CExplorerItem::CExplorerItem(APICore::SExplorerItem meta)
    : QListWidgetItem(meta.Name.c_str())
    , itemMeta(meta)
{

}

CExplorerItem::~CExplorerItem()
{

}