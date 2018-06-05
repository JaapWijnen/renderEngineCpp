//
//  Primitive.h
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#pragma once

#include "Node.h"
#include "Vertex.h"

class Primitive: public Node
{
public:
  Primitive();
  ~Primitive();

  void init();
  virtual void initVertices();

  void setColor(ColorRGBA8 newColor) { _color = newColor; }
  void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
    _color.r = r;
    _color.g = g;
    _color.b = b;
    _color.a = a;
  }

protected:
  int _vertexCount;
  Vertex* _vertexData;

  ColorRGBA8 _color;

private:
  GLuint _vbo;
  GLuint _vao;

  // render the node to screen
  void doRender(GLSLProgram textureProgram, glm::mat4 modelViewMatrix) override;
};
