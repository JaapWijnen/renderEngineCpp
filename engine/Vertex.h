//
//  Vertex.h
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

struct ColorRGBA8 {
  ColorRGBA8() : r(0), g(0), b(0), a(0) { }
  ColorRGBA8(GLubyte R, GLubyte G, GLubyte B, GLubyte A) : r(R), g(G), b(B), a(A) { }
  GLubyte r;
  GLubyte g;
  GLubyte b;
  GLubyte a;
};

struct UV {
  float u;
  float v;
};

//The vertex definition
struct Vertex {
  //This is the position struct. When you store a struct or class
  //inside of another struct or class, it is called composition. This is
  //layed out exactly the same in memory as if we had a float position[2],
  //but doing it this way makes more sense.
  glm::vec4 position;

  //4 bytes for r g b a color.
  ColorRGBA8 color;

  //UV texture coordinates.
  UV uv;

  glm::vec3 normal;

  void setPosition(float x, float y, float z) {
    position = glm::vec4(x, y, z, 0);
  }

  glm::vec3 getPosition() {
    return glm::vec3(position);
  }

  void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
  }

  void setUV(float u, float v) {
    uv.u = u;
    uv.v = v;
  }

  void setNormal(float x, float y, float z) {
    normal = glm::vec3(x, y, z);
  }
  void setNormal(glm::vec3 vec) {
    normal = vec;
  }
};
