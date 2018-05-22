//
//  Quad.h
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#pragma once

#ifdef __APPLE__
  #include <OpenGL/gl3.h>
#elif __linux__
  #include <GL/glew.h>
#endif

#include <glm/glm.hpp>

#include "Primitive.h"

//A 2D quad that can be rendered to the screen
class Quad : public Primitive
{
public:
  Quad(int subdivs);
  ~Quad();

  void initVertices() override;

private:
  int _subdivs;
};
