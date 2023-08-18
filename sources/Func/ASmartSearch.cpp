// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Func/ASmartSearch.h"
#include <iostream>

namespace APICore
{
    FindResult ASmartSearch::SearchFor(SFindRequest request)
    {
        if(!finished && request == mRequest)
            return FindResult::REQUEST_ACCEPTED;

        mRequest = request;
        mLastIndex = 0;
        path searchPath = mRequest.SearchPath;
        
        if(exists(searchPath) && is_directory(searchPath))
        {
            mResults = std::vector<SExplorerItem>();
            mSearchThread = boost::thread([&] () { execSearchThread(); });
            return FindResult::REQUEST_ACCEPTED;
        }
        return FindResult::REQUEST_INVALID;
    }

    FindResult ASmartSearch::SearchGetNext(SExplorerItem *item)
    {
        if(mLastIndex < mResults.size())
        {
            *item = mResults[mLastIndex];
            mLastIndex += 1;
            return FindResult::FOUND;
        }
        if(finished)
        {
            mResults.clear();
            return FindResult::FINISHED;
        }
        else
        {
            return FindResult::NOT_FOUND;
        }
    }

    void ASmartSearch::SearchStop()
    {
        finished = true;
    }

    void ASmartSearch::execSearchThread()
    {
        std::cout << "exec search\n";

        path rootPath = mRequest.SearchPath;
        std::vector<path> cachedFolders = std::vector<path>();
        std::vector<path> tempCachedFolders = std::vector<path>();    


        finished = false;

        searchIn(rootPath, 0, &cachedFolders);   
          
        int recurs = 1;


        path nextPath;
        while(!finished)
        {
            while(cachedFolders.size() > 0)
            {           
                // TODO: multithreading during searching
                nextPath = cachedFolders.back();
                cachedFolders.pop_back();        
                searchIn(nextPath, recurs, &tempCachedFolders);
            }
            

            if(tempCachedFolders.empty())
            {
                SearchStop();
            }
            recurs += 1;
            cachedFolders = tempCachedFolders;
            tempCachedFolders.clear();
        }
        
        finished = true;
    }

    void ASmartSearch::searchIn(path folder, int recurs, std::vector<path>* folders)
    {
        if(recurs > mRequest.RecursionLimit || finished)
            return;
        try
        {
            bool isDir;
            if(is_empty(folder))
                return;
            for(directory_entry x : directory_iterator(folder))
            {
                isDir = is_directory(x);
                if(contains(x.path().filename().string(), mRequest.Request))
                {
                    SExplorerItem rItem;
                    rItem.FullPath = x.path().string();
                    rItem.Name = rItem.FullPath;
                    rItem.Type = isDir ? ItemType::DIRECTORY : ItemType::FILE;
                    mResults.push_back(rItem);
                }
                if(isDir)
                {
                    folders->push_back(x.path());
                }
            }
        }
        catch(const filesystem_error e)
        {
            std::cout << e.what() << std::endl;
        }          
    }
}

