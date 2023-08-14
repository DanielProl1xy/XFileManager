// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include "Core.h"
#include <boost/filesystem.hpp>
#include <boost/chrono.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/thread.hpp>

#define THREADS_COUNT 4

using namespace boost::filesystem;
using namespace boost::algorithm;

class APICore::ASmartSearch
{
public:

    // Starts searching thread with given request
    // Returns FindResult::REQUEST_INVALID if the request is incorrect
    // Returns FindResult::REQUEST_ACCEPTED if the request is correct
    FindResult SearchFor(SFindRequest request); 
    
    // Returns in *item next element which was found in search thread
    // Returns FindResult::FOUND if element found
    // Returns FindResult::NOT_FOUND if next element not found, but keep searching
    // Returns FindResult::FINISHED if no found elements anymore and searching stopped
    FindResult SearchGetNext(SExplorerItem *item);

    // Stops searching thread if started
    void SearchStop();

private:
    std::vector<SExplorerItem> mResults;
    int mLastIndex;

    SFindRequest mRequest;
    boost::thread mSearchThread;
    bool finished;
private:

    void execSearchThread();
    
    // Starts searching in given folder for elements by specifed request
    // Returns in *folders list of found folders inside this folder
    void searchIn(path folder, int recurs, std::vector<path> *folders);
};