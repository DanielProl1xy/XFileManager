#include "Components/CExplorer.h"

CExplorerItem::CExplorerItem(ACore::SExplorerItem meta)
    : QListWidgetItem(meta.Name.c_str())
{
    
}

CExplorerItem::~CExplorerItem()
{

}