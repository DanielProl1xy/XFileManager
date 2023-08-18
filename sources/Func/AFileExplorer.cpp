// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#include "Func/AFileExplorer.h"

using namespace boost::system;
using namespace boost::filesystem;

namespace APICore
{
    int ExploreFolder(const std::string folder, std::vector<SExplorerItem> *result)
    {
        const path explorePath(folder);

        try
        {
            SExplorerItem itm;
            for(directory_entry& x : directory_iterator(explorePath))
            {
                itm.Name = x.path().filename().string();
                itm.Type = is_directory(x.path()) ? ItemType::DIRECTORY : ItemType::FILE;
                itm.FullPath = x.path().string();
                result->push_back(itm);
            }
        }
        catch(const filesystem_error e)
        {
            std::cerr << e.what() << '\n';
            return e.code().value();
        }

        return 0;
    }

    int CreateFile(const std::string path)
    {
        NOT_IMPLEMENTED("Create file");
    }

    int CreateFolder(const std::string path)
    {
        NOT_IMPLEMENTED("CreateFolder");
    }
    
    int CopyFile(const std::string from, const std::string to)
    {
        NOT_IMPLEMENTED("CopyFile");
    }

    int CopyFolder(const std::string from, const std::string to)
    {
        NOT_IMPLEMENTED("CopyFolder");
    }

    int Delete(const std::string path)
    {
        NOT_IMPLEMENTED("Delete");
    }

    int Rename(const std::string path, const std::string newName)
    {
        NOT_IMPLEMENTED("Rename");
    }
}