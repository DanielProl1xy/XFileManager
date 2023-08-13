// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Func/AFileExplore.h"

using namespace boost::filesystem;

namespace ACore
{
    AFileExplore::AFileExplore(std::string defaultPath)
    {
        if(defaultPath.empty())
        {
            currentPath = ROOT_PATH;
        }
        else
        {
            currentPath = defaultPath;
        }
    }

    AFileExplore::~AFileExplore()
    {

    }

    std::vector<SExplorerItem> AFileExplore::ExploreFolder(std::string folder)
    {
        std::vector<SExplorerItem> result = std::vector<SExplorerItem>();

        path explorePath(folder);

        if(exists(explorePath))
        {
            if(is_directory(explorePath))
            {
                for(directory_entry& x : directory_iterator(explorePath))
                {
                    SExplorerItem itm;
                    itm.Name = x.path().filename().string();
                    itm.Type = is_directory(x.path()) ? ItemType::DIRECTORY : ItemType::FILE;
                    itm.FullPath = x.path().string();
                    result.push_back(itm);
                }
            }
        }

        currentPath = folder;
        return result;
    }
}