//
//  Cube.cpp
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#include "Cube.h"
#include "Vertex.h"
#include "ResourceManager.h"

#include <cstddef>

#include <glm/gtc/matrix_transform.hpp>

Cube::Cube()
{
}


Cube::~Cube()
{
}

void Cube::initVertices() {
  //This array will hold our vertex data.
  //We need 6 vertices, and each vertex has 2
  //floats for X and Y
  _vertexCount = 36;
  _vertexData = new Vertex[_vertexCount];

  //Front quad
  //First Triangle
  _vertexData[0].setPosition(1.0f, 1.0f, 1.0f);
  _vertexData[1].setPosition(-1.0f, 1.0f, 1.0f);
  _vertexData[2].setPosition(-1.0f, -1.0f, 1.0f);

  //Second Triangle
  _vertexData[3].setPosition(-1.0f, -1.0f, 1.0f);
  _vertexData[4].setPosition(1.0f, -1.0f, 1.0f);
  _vertexData[5].setPosition(1.0f, 1.0f, 1.0f);

  //Back Quad
  //First Triangle
  _vertexData[6].setPosition(1.0f, 1.0f, -1.0f);
  _vertexData[7].setPosition(-1.0f, 1.0f, -1.0f);
  _vertexData[8].setPosition(-1.0f, -1.0f, -1.0f);

  //Second Triangle
  _vertexData[9].setPosition(-1.0f, -1.0f, -1.0f);
  _vertexData[10].setPosition(1.0f, 1.0f, -1.0f);
  _vertexData[11].setPosition(1.0f, -1.0f, -1.0f);

  //Right quad
  //First Triangle
  _vertexData[12].setPosition(1.0f, 1.0f, 1.0f);
  _vertexData[13].setPosition(1.0f, -1.0f, 1.0f);
  _vertexData[14].setPosition(1.0f, -1.0f, -1.0f);

  //Second Triangle
  _vertexData[15].setPosition(1.0f, -1.0f, -1.0f);
  _vertexData[16].setPosition(1.0f, 1.0f, -1.0f);
  _vertexData[17].setPosition(1.0f, 1.0f, 1.0f);

  //Left quad
  //First Triangle
  _vertexData[18].setPosition(-1.0f, 1.0f, 1.0f);
  _vertexData[19].setPosition(-1.0f, -1.0f, -1.0f);
  _vertexData[20].setPosition(-1.0f, -1.0f, 1.0f);

  //Second Triangle
  _vertexData[21].setPosition(-1.0f, -1.0f, -1.0f);
  _vertexData[22].setPosition(-1.0f, 1.0f, 1.0f);
  _vertexData[23].setPosition(-1.0f, 1.0f, -1.0f);

  //Top Quad
  //First Triangle
  _vertexData[24].setPosition(1.0f, 1.0f, 1.0f);
  _vertexData[25].setPosition(-1.0f, 1.0f, -1.0f);
  _vertexData[26].setPosition(-1.0f, 1.0f, 1.0f);

  //Second Triangle
  _vertexData[27].setPosition(1.0f, 1.0f, 1.0f);
  _vertexData[28].setPosition(1.0f, 1.0f, -1.0f);
  _vertexData[29].setPosition(-1.0f, 1.0f, -1.0f);

  //Bottom Quad
  //First Triangle
  _vertexData[30].setPosition(1.0f, -1.0f, 1.0f);
  _vertexData[31].setPosition(-1.0f, -1.0f, 1.0f);
  _vertexData[32].setPosition(-1.0f, -1.0f, -1.0f);

  //Second Triangle
  _vertexData[33].setPosition(1.0f, -1.0f, 1.0f);
  _vertexData[34].setPosition(-1.0f, -1.0f, -1.0f);
  _vertexData[35].setPosition(1.0f, -1.0f, -1.0f);

  //Set all vertex colors to magenta
  int i = 0;
  for (i=0; i < 36; i++) {
    _vertexData[i].setColor(255, 255, 255, 255);
  }
  for (i = 0; i < 6; i++) {
    //_vertexData[i].setColor(255, 0, 0, 255);
    _vertexData[i].setNormal(0, 0, 1);
  }
  for (i = 6; i < 12; i++) {
    //_vertexData[i].setColor(255, 255, 0, 255);
    _vertexData[i].setNormal(0, 0, -1);
  }
  for (i = 12; i < 18; i++) {
    //_vertexData[i].setColor(0, 0, 255, 255);
    _vertexData[i].setNormal(1, 0, 0);
  }
  for (i = 18; i < 24; i++) {
    //_vertexData[i].setColor(0, 255, 0, 255);
    _vertexData[i].setNormal(-1, 0, 0);
  }
  for (i = 24; i < 30; i++) {
    //_vertexData[i].setColor(255, 0, 255, 255);
    _vertexData[i].setNormal(0, 1, 0);
  }
  for (i = 30; i < 36; i++) {
    //_vertexData[i].setColor(0, 255, 255, 255);
    _vertexData[i].setNormal(0, -1, 0);
  }
}
