// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include "Core.h"
#include <iostream>
#include <vector>
#include <boost/filesystem.hpp>


class APICore::AFileExplorer 
{
public:
    // Returns in *result list of elements inside  the folder specified by the given path.
    // Returns ExploreResult::FAILED if the path is incorrect or if there is an error.
    ExploreResult ExploreFolder(std::string path, std::vector<SExplorerItem> *result);

    // TODO: GetDevices to get list of connected filesystem devices
};