//
//  Window.h
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#pragma once

#include <SDL2/SDL.h>

#ifdef __APPLE__
  #include <OpenGL/gl3.h>
#elif __linux__
  #include <GL/glew.h>
#endif

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
  SDL_Window* _sdlWindow;
  int _screenWidth, _screenHeight;
};
