// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include "Core.h"
#include <iostream>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/system/detail/error_code.hpp>

namespace APICore
{

    // Returns in *result list of elements inside  the folder specified by the given path.
    // Returns not zero if the path is incorrect or if there is an error.
    int ExploreFolder(const std::string path, std::vector<SExplorerItem> *result);
    
    // TODO: GetDevices to get list of connected filesystem devices
    // int GetDevices(std::vector<SExplorerItem> *result);

    // Creates file by given path.
    // Returns not zero if the path is incorrect or if there is an error.
    int CreateFile(const std::string path);

    // Creates folder by given path.
    // Returns not zero if the path is incorrect or if there is an error.
    int CreateFolder(const std::string path); 

    int CopyFolder(const std::string from, const std::string to);

    int CopyFile(const std::string from, const std::string to);

    int Delete(const std::string path);

    int Rename(const std::string path, const std::string newName);
    
}