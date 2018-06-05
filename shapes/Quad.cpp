//
//  Quad.cpp
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#include "Quad.h"

#include <glm/gtc/matrix_transform.hpp>

#include <cstddef>

#include "Vertex.h"

Quad::Quad(int subdivs) : _subdivs(subdivs)
{
}


Quad::~Quad()
{
}

void Quad::initVertices() {
  _vertexCount = _subdivs*_subdivs*6;
  _vertexData = new Vertex[_vertexCount];

  float step = 2.0f / float(_subdivs);

  //Front
  for (int j=0; j<_subdivs; j++) {
    for (int i=0; i<_subdivs; i++) {
      //First Triangle
      _vertexData[6*(i+j*_subdivs)  ].setPosition(-1.0f + step*i,     -1.0f + step*j,     0.0f);
      _vertexData[6*(i+j*_subdivs)+1].setPosition(-1.0f + step*(i+1), -1.0f + step*j,     0.0f);
      _vertexData[6*(i+j*_subdivs)+2].setPosition(-1.0f + step*(i+1), -1.0f + step*(j+1), 0.0f);

      //Second Triangle
      _vertexData[6*(i+j*_subdivs)+3].setPosition(-1.0f + step*i,     -1.0f + step*j,     0.0f);
      _vertexData[6*(i+j*_subdivs)+4].setPosition(-1.0f + step*(i+1), -1.0f + step*(j+1), 0.0f);
      _vertexData[6*(i+j*_subdivs)+5].setPosition(-1.0f + step*i,     -1.0f + step*(j+1), 0.0f);

      for (int k=0; k<6; k++) {
        _vertexData[6*(i+j*_subdivs)+k].setNormal(0, 0, 1);
        _vertexData[6*(i+j*_subdivs)+k].setColor(_color);
      }
    }
  }
}
