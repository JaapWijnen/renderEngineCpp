//
//  Node.h
//  renderEngineCpp
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
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <vector>

#include "GLSLProgram.h"

//A 2D quad that can be rendered to the screen
class Node
{
public:
  Node();
  ~Node();

  glm::vec3 getPosition() { return _position; }
  void setPosition(const glm::vec3& newPosition) { _position = newPosition; _modelMatrixNeedsUpdate = true; }

  glm::vec3 getRotation() { return _rotation; }
  void setRotation(const glm::vec3& newRotation) { _rotation = newRotation; _modelMatrixNeedsUpdate = true; }

  glm::vec3 getScale() { return _scale; }
  void setScale(const glm::vec3& newScale) { _scale = newScale; _modelMatrixNeedsUpdate = true; }

  glm::mat4 getModelMatrix() {
    if (_modelMatrixNeedsUpdate) {
      glm::mat4 scale = glm::scale(glm::mat4(1.0f), _scale);

      glm::mat4 rotateX = glm::rotate(glm::mat4(1.0f), _rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
      glm::mat4 rotateY = glm::rotate(glm::mat4(1.0f), _rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
      glm::mat4 rotateZ = glm::rotate(glm::mat4(1.0f), _rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

      glm::mat4 translate = glm::translate(glm::mat4(1.0f), _position);

      _modelMatrix = translate * rotateZ * rotateY * rotateX * scale;

      _modelMatrixNeedsUpdate = false;
    }

    return _modelMatrix;
  }

  std::string getName() { return _name; }
  void setName(std::string name) { _name = name; }

  void addChild(Node *child);
  void setParent(Node *parent);

  int getChildCount();

  void deleteChildren();

  bool hasChildren();
  bool hasParent();

  // run render on the current node and its children
  void render(GLSLProgram textureProgram, glm::mat4 parentModelViewMatrix);

protected:
  // render the node to screen
  virtual void doRender(GLSLProgram, glm::mat4 modelViewMatrix);

private:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;

  bool _modelMatrixNeedsUpdate;
  glm::mat4 _modelMatrix;

  std::string _name;
  Node * _parent;
  std::vector<Node *> _children;
};
