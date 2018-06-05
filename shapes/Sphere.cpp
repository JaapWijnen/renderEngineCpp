//
//  Sphere.cpp
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#include "Sphere.h"

#include <glm/gtc/matrix_transform.hpp>

#include <cstddef>

#include "Vertex.h"
#include "ResourceManager.h"

Sphere::Sphere(int subdivs) : _subdivs(subdivs)
{
}


Sphere::~Sphere()
{
}

void Sphere::initVertices() {
  int qVertices = _subdivs*_subdivs*6;
  _vertexCount = qVertices * 6;

  _vertexData = new Vertex[_vertexCount];

  float step = 2.0f / float(_subdivs);

  //Front
  for (int j=0; j<_subdivs; j++) {
    for (int i=0; i<_subdivs; i++) {
      //First Triangle
      _vertexData[6*(i+j*_subdivs)  ].setPosition(-1.0f + step*i,     -1.0f + step*j,     1.0f);
      _vertexData[6*(i+j*_subdivs)+1].setPosition(-1.0f + step*(i+1), -1.0f + step*j,     1.0f);
      _vertexData[6*(i+j*_subdivs)+2].setPosition(-1.0f + step*(i+1), -1.0f + step*(j+1), 1.0f);

      //Second Triangle
      _vertexData[6*(i+j*_subdivs)+3].setPosition(-1.0f + step*i,     -1.0f + step*j,     1.0f);
      _vertexData[6*(i+j*_subdivs)+4].setPosition(-1.0f + step*(i+1), -1.0f + step*(j+1), 1.0f);
      _vertexData[6*(i+j*_subdivs)+5].setPosition(-1.0f + step*i,     -1.0f + step*(j+1), 1.0f);
    }
  }

  //Back
  for (int j=0; j<_subdivs; j++) {
    for (int i=0; i<_subdivs; i++) {
      //First Triangle
      _vertexData[6*(i+j*_subdivs)   + qVertices].setPosition(-1.0f + step*i,     -1.0f + step*j,     -1.0f);
      _vertexData[6*(i+j*_subdivs)+1 + qVertices].setPosition(-1.0f + step*(i+1), -1.0f + step*j,     -1.0f);
      _vertexData[6*(i+j*_subdivs)+2 + qVertices].setPosition(-1.0f + step*(i+1), -1.0f + step*(j+1), -1.0f);

      //Second Triangle
      _vertexData[6*(i+j*_subdivs)+3 + qVertices].setPosition(-1.0f + step*i,     -1.0f + step*j,     -1.0f);
      _vertexData[6*(i+j*_subdivs)+4 + qVertices].setPosition(-1.0f + step*(i+1), -1.0f + step*(j+1), -1.0f);
      _vertexData[6*(i+j*_subdivs)+5 + qVertices].setPosition(-1.0f + step*i,     -1.0f + step*(j+1), -1.0f);
    }
  }

  //Left
  for (int j=0; j<_subdivs; j++) {
    for (int i=0; i<_subdivs; i++) {
      //First Triangle
      _vertexData[6*(i+j*_subdivs)   + 2*qVertices].setPosition(-1.0f, -1.0f + step*j,     -1.0f + step*i);
      _vertexData[6*(i+j*_subdivs)+1 + 2*qVertices].setPosition(-1.0f, -1.0f + step*j,     -1.0f + step*(i+1));
      _vertexData[6*(i+j*_subdivs)+2 + 2*qVertices].setPosition(-1.0f, -1.0f + step*(j+1), -1.0f + step*(i+1));

      //Second Triangle
      _vertexData[6*(i+j*_subdivs)+3 + 2*qVertices].setPosition(-1.0f, -1.0f + step*j,     -1.0f + step*i);
      _vertexData[6*(i+j*_subdivs)+4 + 2*qVertices].setPosition(-1.0f, -1.0f + step*(j+1), -1.0f + step*(i+1));
      _vertexData[6*(i+j*_subdivs)+5 + 2*qVertices].setPosition(-1.0f, -1.0f + step*(j+1), -1.0f + step*i);
    }
  }

  //Right
  for (int j=0; j<_subdivs; j++) {
    for (int i=0; i<_subdivs; i++) {
      //First Triangle
      _vertexData[6*(i+j*_subdivs)   + 3*qVertices].setPosition(1.0f, -1.0f + step*j,     -1.0f + step*i);
      _vertexData[6*(i+j*_subdivs)+1 + 3*qVertices].setPosition(1.0f, -1.0f + step*j,     -1.0f + step*(i+1));
      _vertexData[6*(i+j*_subdivs)+2 + 3*qVertices].setPosition(1.0f, -1.0f + step*(j+1), -1.0f + step*(i+1));

      //Second Triangle
      _vertexData[6*(i+j*_subdivs)+3 + 3*qVertices].setPosition(1.0f, -1.0f + step*j,     -1.0f + step*i);
      _vertexData[6*(i+j*_subdivs)+4 + 3*qVertices].setPosition(1.0f, -1.0f + step*(j+1), -1.0f + step*(i+1));
      _vertexData[6*(i+j*_subdivs)+5 + 3*qVertices].setPosition(1.0f, -1.0f + step*(j+1), -1.0f + step*i);
    }
  }

  //Bottom
  for (int j=0; j<_subdivs; j++) {
    for (int i=0; i<_subdivs; i++) {
      //First Triangle
      _vertexData[6*(i+j*_subdivs)   + 4*qVertices].setPosition(-1.0f + step*j,     -1.0f, -1.0f + step*i);
      _vertexData[6*(i+j*_subdivs)+1 + 4*qVertices].setPosition(-1.0f + step*j,     -1.0f, -1.0f + step*(i+1));
      _vertexData[6*(i+j*_subdivs)+2 + 4*qVertices].setPosition(-1.0f + step*(j+1), -1.0f, -1.0f + step*(i+1));

      //Second Triangle
      _vertexData[6*(i+j*_subdivs)+3 + 4*qVertices].setPosition(-1.0f + step*j,     -1.0f, -1.0f + step*i);
      _vertexData[6*(i+j*_subdivs)+4 + 4*qVertices].setPosition(-1.0f + step*(j+1), -1.0f, -1.0f + step*(i+1));
      _vertexData[6*(i+j*_subdivs)+5 + 4*qVertices].setPosition(-1.0f + step*(j+1), -1.0f, -1.0f + step*i);
    }
  }

  //Bottom
  for (int j=0; j<_subdivs; j++) {
    for (int i=0; i<_subdivs; i++) {
      //First Triangle
      _vertexData[6*(i+j*_subdivs)   + 5*qVertices].setPosition(-1.0f + step*j,     1.0f, -1.0f + step*i);
      _vertexData[6*(i+j*_subdivs)+1 + 5*qVertices].setPosition(-1.0f + step*j,     1.0f, -1.0f + step*(i+1));
      _vertexData[6*(i+j*_subdivs)+2 + 5*qVertices].setPosition(-1.0f + step*(j+1), 1.0f, -1.0f + step*(i+1));

      //Second Triangle
      _vertexData[6*(i+j*_subdivs)+3 + 5*qVertices].setPosition(-1.0f + step*j,     1.0f, -1.0f + step*i);
      _vertexData[6*(i+j*_subdivs)+4 + 5*qVertices].setPosition(-1.0f + step*(j+1), 1.0f, -1.0f + step*(i+1));
      _vertexData[6*(i+j*_subdivs)+5 + 5*qVertices].setPosition(-1.0f + step*(j+1), 1.0f, -1.0f + step*i);
    }
  }

  //Set all vertex colors to magenta
  int i = 0;
  for (int i=0; i < _vertexCount; i++) {
    _vertexData[i].setColor(_color);
    glm::vec3 pos = _vertexData[i].getPosition();
    pos = normalize(pos);
    _vertexData[i].setPosition(pos.x, pos.y, pos.z);
    _vertexData[i].setNormal(pos.x, pos.y, pos.z);
  }
}
