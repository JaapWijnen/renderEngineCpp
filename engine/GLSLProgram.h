//
//  GLSLProgram.h
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
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

#include <string>

//This class handles the compilation, linking, and usage of a GLSL shader program.
class GLSLProgram
{
public:
  GLSLProgram();
  ~GLSLProgram();

  void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilepath);

  void linkShaders();

  void addAttribute(const std::string& attributeName);

  GLint getUniformLocation(const std::string& uniformName);

  void use();
  void unuse();
private:

  int _numAttributes;

  void compileShader(const std::string& filePath, GLuint id);

  GLuint _programID;

  GLuint _vertexShaderID;
  GLuint _fragmentShaderID;
};
