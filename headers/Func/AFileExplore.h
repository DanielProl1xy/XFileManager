// (c) 2023 Daniel Asadullaev. All Rights Reserved.

#pragma once

#include "Core.h"
#include <iostream>
#include <vector>
#include <boost/filesystem.hpp>

#define ROOT_PATH "C:\\"

class ACore::AFileExplore 
{

private:
    std::string currentPath;

public:
    AFileExplore(std::string defaultPath = ROOT_PATH);
    ~AFileExplore();

    std::string GetCurrentPath() const { return currentPath; }

    std::vector<SExplorerItem> ExploreFolder(std::string path);
};