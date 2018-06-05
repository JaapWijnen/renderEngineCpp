//
//  Camera.cpp
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#include "Camera.h"

#include <iostream>

Camera::Camera() :
  _position(0.0f, 0.0f, 0.0f),
  _rotation(0.0f, 0.0f, 0.0f),
  _scale(1.0f),
  _viewMatrix(1.0f),
  _fovMatrix(1.0f),
  _modelMatrixNeedsUpdate(true),
  _screenWidth(500),
  _screenHeight(500)
{
}

Camera::~Camera()
{
}

void Camera::init(int screenWidth, int screenHeight, float fov) {
  _screenWidth = screenWidth;
  _screenHeight = screenHeight;

  float aspect = (float)_screenWidth / (float)_screenHeight;
  const float degrees = 60.0f;
  const float PI = 3.1415927;
  fov = fov / 360.0f * 2.0f * PI;
  _fovMatrix = glm::perspective(fov, aspect, 0.1f, 100.0f);
}
