//
//  IOManager.h
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#pragma once

#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <map>

class IOManager
{
public:
    static bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
};
