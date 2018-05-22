//
//  ResourceManager.h
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#pragma once

#include "TextureCache.h"

#include <string>

//This is a way for us to access all our resources, such as
//Models or textures.
class ResourceManager
{
public:
  static GLTexture getTexture(std::string texturePath);

private:
  static TextureCache _textureCache;
};
