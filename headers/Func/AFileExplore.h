#pragma once

#include "Core.h"
#include <iostream>
#include <boost/filesystem.hpp>

#define ROOT_PATH "C:\\"

class ACore::AFileExplore 
{

    std::string currentPath;

public:
    AFileExplore(std::string defaultPath = "");
    ~AFileExplore();

    void ExploreFolder(char *path);
};