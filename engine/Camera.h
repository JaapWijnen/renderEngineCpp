//
//  Camera.h
//  renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#pragma once

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
  Camera();
  ~Camera();

  //sets up the orthographic matrix and screen dimensions
  void init(int screenWidth, int screenHeight, float fov);

  //updates the camera matrix if needed
  void update();

  //setters
  void setPosition(const glm::vec3& newPosition) { _position = newPosition; _needsMatrixUpdate = true; }
  void setScale(const glm::vec3& newScale) { _scale = newScale; _needsMatrixUpdate = true; }
  void setRotation(const glm::vec3& newRotation) { _rotation = newRotation; _needsMatrixUpdate = true; }

  //getters
  glm::vec3 getPosition() { return _position; }
  glm::vec3 getScale() { return _scale; }
  glm::vec3 getRotation() { return _rotation; }
  glm::mat4 getCameraMatrix() { return _cameraMatrix; }
  glm::mat4 getProjectionMatrix() { return _fovMatrix; }

private:
  int _screenWidth, _screenHeight;
  bool _needsMatrixUpdate;
  glm::vec3 _scale;
  glm::vec3 _rotation;
  glm::vec3 _position;
  glm::mat4 _cameraMatrix;
  glm::mat4 _fovMatrix;
};
