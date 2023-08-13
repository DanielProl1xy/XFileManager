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

    void AFileExplore::ExploreFolder(char *folder)
    {
        path explorePath(folder);

        if(exists(explorePath))
        {
            if(is_directory(explorePath))
            {
                for(directory_entry& x : directory_iterator(explorePath))
                {
                    std::cout << x.path() << std::endl;
                }
            }
        }
    }
}