#include "Components/CExplorer.h"

namespace UI 
{
    CExplorer::CExplorer(QWidget *parent)
        : QListWidget(parent)
    {
        m_explorer = ACore::AFileExplore(ROOT_PATH);
    }

    CExplorer::~CExplorer()
    {
        
    }
}