//
//  Primitive.cpp
//  renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#include "Primitive.h"

#include <iostream>

#include "Errors.h"

Primitive::Primitive() : _vbo(0), _vao(0) {

}

Primitive::~Primitive() {
  //Always remember to delete your buffers when
  //you are done!
  if (_vbo != 0) {
    glDeleteBuffers(1, &_vbo);
  }

  delete[] _vertexData;
}

//Initializes the sprite VBO. x, y, width, and height are
//in the normalized device coordinate space. so, [-1, 1]
void Primitive::init() {

  //Generate the buffer if it hasn't already been generated
  if (_vbo == 0) {
    glGenBuffers(1, &_vbo);
  }

  initVertices();

  // Generate the VAO if it isn't already generated
  if (_vao == 0) {
    glGenVertexArrays(1, &_vao);
  }

  // Bind the VAO. All subsequent opengl calls will modify it's state.
  glBindVertexArray(_vao);

  //Tell opengl to bind our vertex buffer object
  glBindBuffer(GL_ARRAY_BUFFER, _vbo);
  //Upload the data to the GPU
  glBufferData(GL_ARRAY_BUFFER, _vertexCount * sizeof(Vertex), _vertexData, GL_STATIC_DRAW);

  //Unbind the buffer (optional)
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindVertexArray(0);
}

void Primitive::initVertices() {
  fatalError("initVertices not overridden in subclass");
}

// Renders the Primitve to the screen
void Primitive::doRender(GLSLProgram textureProgram, glm::mat4 modelViewMatrix) {
  // debug print statement
  // std::cout << "rendering: " + getName() << std::endl;

  // ModelMatrix uniform
  glm::mat4 modelMatrix = modelViewMatrix;
  GLint mUniform = textureProgram.getUniformLocation("M");
  glUniformMatrix4fv(mUniform, 1, GL_FALSE, &modelMatrix[0][0]);

  glBindVertexArray(_vao);

  //bind the buffer object
  glBindBuffer(GL_ARRAY_BUFFER, _vbo);

  //Tell opengl what attribute arrays we need
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);
  glEnableVertexAttribArray(3);

  //This is the position attribute pointer
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
  //This is the color attribute pointer
  glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
  //This is the UV attribute pointer
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
  //This is the normal attribute pointer
  glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

  //Draw the 6 vertices to the screen
  glDrawArrays(GL_TRIANGLES, 0, _vertexCount);

  //Disable the vertex attrib arrays. This is not optional.
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(2);
  glDisableVertexAttribArray(3);

  //Unbind the VBO
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindVertexArray(0);
}
