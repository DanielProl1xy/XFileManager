// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include <QThread>
#include "Core.h"
#include "Func/ASmartSearch.h"

class UI::Threads::SearchThread : public QThread
{
    Q_OBJECT

public:
    SearchThread(QObject *parent = nullptr);
    
    void SetSearcher(APICore::ASmartSearch *searcher, APICore::SFindRequest request);

signals:
    void ItemFound(APICore::SExplorerItem item);
    void ClearWidget();
    void SearchCompleted(bool result);

protected:
    void run() override;

private:
    APICore::ASmartSearch *m_searcher;
    APICore::SFindRequest m_request;
};