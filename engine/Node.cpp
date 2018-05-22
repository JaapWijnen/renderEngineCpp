//
//  Node.cpp
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#include "Node.h"

#include <iostream>

#include "Vertex.h"

Node::Node() : _position(0), _rotation(0), _scale(1), _modelMatrix(1), _name("untitled"), _parent(NULL)
{
}

Node::~Node()
{
  for (int i=0; i<_children.size(); i++) {
    delete _children[i];
  }
}

void Node::addChild(Node *child) {
  child->setParent(this);
  _children.push_back(child);
}

void Node::setParent(Node *parent) {
  _parent = parent;
}

int Node::getChildCount() {
  return _children.size();
}

bool Node::hasChildren() {
  if (_children.size() > 0) {
    return true;
  } else {
    return false;
  }
}

void Node::deleteChildren() {
  for (int i=0; i<_children.size(); i++) {
    delete _children[i];
  }
  _children.clear();
}

bool Node::hasParent() {
  if (_parent != NULL) {
    return true;
  } else {
    return false;
  }
}

void Node::render(GLSLProgram textureProgram, glm::mat4 parentModelViewMatrix) {
  glm::mat4 modelViewMatrix = parentModelViewMatrix * getModelMatrix();

  // loop over all children
  for(std::vector<Node *>::iterator it = _children.begin(); it != _children.end(); ++it) {
    (*it)->render(textureProgram, modelViewMatrix);
  }

  // render current Node
  doRender(textureProgram, modelViewMatrix);
}

void Node::doRender(GLSLProgram textureProgram, glm::mat4 modelViewMatrix) {
  // overwritten by renderable subclass
  // debug print statement
  // std::cout << "rendering: " + getName() << std::endl;
}
