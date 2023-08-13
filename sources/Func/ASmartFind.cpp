#include "Func/ASmartFind.h"
#include "ASmartFind.h"
#include <iostream>

namespace ACore
{
    FindResult ASmartFind::SearchFor(SFindRequest request)
    {
        if(!finished && request == mRequest)
            return FindResult::REQUEST_ACCEPTED;


        mRequest = request;
        mLastIndex = 0;
        path searchPath = mRequest.SearchPath;
        
        if(exists(searchPath) && is_directory(searchPath))
        {
            mSearchThread = boost::thread([&] () { execSearchThread(); });
            mResults = std::vector<SExplorerItem>();
            return FindResult::REQUEST_ACCEPTED;
        }
        return FindResult::REQUEST_INVALID;
    }

    FindResult ASmartFind::SearchGetNext(SExplorerItem *item)
    {
        if(mLastIndex < mResults.size())
        {
            item = &(mResults[mLastIndex]);
            mLastIndex += 1;
            return FindResult::FOUND;
        }
        if(finished)
        {
            return FindResult::FINISHED;
        }
        else
        {
            return FindResult::NOT_FOUND;
        }
    }

    void ASmartFind::SearchStop()
    {
        finished = true;
    }

    void ASmartFind::execSearchThread()
    {
        path rootPath = mRequest.SearchPath;
        std::vector<path> cachedFolders = std::vector<path>();
        std::vector<path> tempCachedFolders = std::vector<path>();
        searchIn(rootPath, 0, &cachedFolders);        
        int i = 1;
        while(!finished)
        {
            for(path nextPath : cachedFolders)
            {                   
                searchIn(nextPath, i, &tempCachedFolders);
            }
            i += 1;
            if(tempCachedFolders.empty())
            {
                SearchStop();
            }
            cachedFolders = tempCachedFolders;
            tempCachedFolders.clear();
        }
        std::cout << "Searching end" << std::endl;
    }

    void ASmartFind::searchIn(path folder, int recurs, std::vector<path>* folders)
    {
        if(recurs == mRequest.RecursionLimit)
            return;
        recurs += 1;
        try
        {
            for(directory_entry x : directory_iterator(folder))
            {
                bool isDir = is_directory(x);
                if(contains(x.path().filename().string(), mRequest.Request))
                {
                    SExplorerItem rItem;
                    rItem.FullPath = x.path().string();
                    rItem.Name = x.path().filename().string();
                    rItem.Type = isDir ? ItemType::DIRECTORY : ItemType::FILE;
                    mResults.push_back(rItem);
                    std::cout << "Found: " << rItem.FullPath << '\n';
                }
                if(isDir)
                {
                    folders->push_back(x.path());
                }
            }
        }
        catch(const std::exception& e)
        {

        }          
    }
}

