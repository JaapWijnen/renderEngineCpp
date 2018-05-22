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

protected:
  int _vertexCount;
  Vertex* _vertexData;

private:
  GLuint _vbo;
  GLuint _vao;

  // render the node to screen
  void doRender(GLSLProgram textureProgram, glm::mat4 modelViewMatrix) override;
};
