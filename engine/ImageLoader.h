//
//  ImageLoader.h
//  renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#pragma once
#include "GLTexture.h"

#include <string>

//Loads images into GLTextures
class ImageLoader
{
public:
  static GLTexture loadPNG(std::string filePath);
};
