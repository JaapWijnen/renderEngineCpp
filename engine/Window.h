//
//  Window.h
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#pragma once

#include <GLFW/glfw3.h>

#include <string>

enum WindowFlags { INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4 };

class Window
{
public:
  Window();
  ~Window();

  int create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);

  void swapBuffer();

  int getScreenWidth() { return _screenWidth; }
  int getScreenHeight() { return _screenHeight; }
private:
  GLFWwindow* _glfwWindow;
  int _screenWidth, _screenHeight;
};
