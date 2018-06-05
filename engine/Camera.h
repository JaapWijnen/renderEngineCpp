//
//  Camera.h
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
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

  glm::vec3 getPosition() { return _position; }
  void setPosition(const glm::vec3& newPosition) { _position = newPosition; _modelMatrixNeedsUpdate = true; }

  glm::vec3 getScale() { return _scale; }
  void setScale(const glm::vec3& newScale) { _scale = newScale; _modelMatrixNeedsUpdate = true; }

  glm::vec3 getRotation() { return _rotation; }
  void setRotation(const glm::vec3& newRotation) { _rotation = newRotation; _modelMatrixNeedsUpdate = true; }

  glm::mat4 getProjectionMatrix() { return _fovMatrix; }

  glm::mat4 getViewMatrix() {
    //Only update if our position or scale have changed
    if (_modelMatrixNeedsUpdate) {

      //Camera Rotation
      glm::mat4 rotateM = glm::mat4(1.0f);
      rotateM = glm::rotate(rotateM, _rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
      rotateM = glm::rotate(rotateM, _rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
      rotateM = glm::rotate(rotateM, _rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

      //Camera Translation
      glm::mat4 translateM = glm::translate(glm::mat4(1.0f), _position);

      //Camera Scale
      glm::mat4 scaleM = glm::scale(glm::mat4(1.0f), _scale);

      _viewMatrix = scaleM * rotateM * translateM;

      _modelMatrixNeedsUpdate = false;
    }

    return _viewMatrix;
  }

private:
  int _screenWidth, _screenHeight;
  bool _modelMatrixNeedsUpdate;
  glm::vec3 _scale;
  glm::vec3 _rotation;
  glm::vec3 _position;
  glm::mat4 _viewMatrix;
  glm::mat4 _fovMatrix;
};
