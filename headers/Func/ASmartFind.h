#pragma once

#include "Core.h"
#include <boost/filesystem.hpp>
#include <boost/chrono.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/thread.hpp>

#define THREADS_COUNT 4

using namespace boost::filesystem;
using namespace boost::algorithm;

class ACore::ASmartFind
{

public:
    FindResult SearchFor(SFindRequest request); 
    FindResult SearchGetNext(SExplorerItem* item);
    void SearchStop();
private:
    std::vector<SExplorerItem> mResults;
    int mLastIndex;
    SFindRequest mRequest;
    boost::thread mSearchThread;
    bool finished;
private:
    void execSearchThread();
    void searchIn(path folder, int recurs, std::vector<path>* folders);
};