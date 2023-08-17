// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Func/AFileExplorer.h"

using namespace boost::filesystem;

namespace APICore
{
    ExploreResult AFileExplorer::ExploreFolder(std::string folder, std::vector<SExplorerItem> *result)
    {
        path explorePath(folder);

        if(exists(explorePath) && is_directory(explorePath))
        {
            try
            {
                for(directory_entry& x : directory_iterator(explorePath))
                {
                    SExplorerItem itm;
                    itm.Name = x.path().filename().string();
                    itm.Type = is_directory(x.path()) ? ItemType::DIRECTORY : ItemType::FILE;
                    itm.FullPath = x.path().string();
                    result->push_back(itm);
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return ExploreResult::FAILED;
            }                       
        }
        else
        {
            return ExploreResult::FAILED;
        }

        return ExploreResult::SUCCESS;
    }
}