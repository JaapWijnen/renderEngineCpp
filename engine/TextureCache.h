//
//  TextureCache.h
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#pragma once

#include <map>

#include "GLTexture.h"

//This caches the textures so that multiple sprites can use the same textures
class TextureCache
{
public:
  TextureCache();
  ~TextureCache();

  GLTexture getTexture(std::string texturePath);

private:
  std::map<std::string, GLTexture> _textureMap;
};
