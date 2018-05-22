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
  _cameraMatrix(1.0f),
  _fovMatrix(1.0f),
  _needsMatrixUpdate(true),
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

//updates the camera matrix if needed
void Camera::update() {

  //Only update if our position or scale have changed
  if (_needsMatrixUpdate) {

    //Camera Rotation
    glm::mat4 rotateM = glm::mat4(1.0f);
    rotateM = glm::rotate(rotateM, _rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    rotateM = glm::rotate(rotateM, _rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    rotateM = glm::rotate(rotateM, _rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

    //Camera Translation
    glm::mat4 translateM = glm::translate(glm::mat4(1.0f), _position);

    //Camera Scale
    glm::mat4 scaleM = glm::scale(glm::mat4(1.0f), _scale);

    _cameraMatrix = scaleM * rotateM * translateM;

    _needsMatrixUpdate = false;
  }
}
