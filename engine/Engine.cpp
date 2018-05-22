//
//  Engine.cpp
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#include <SDL2/SDL.h>

#ifdef __APPLE__
  #include <OpenGL/gl3.h>
#elif __linux__
  #include <GL/glew.h>
#endif

#include "Engine.h"

int Engine::init() {
  //Initialize SDL
  SDL_Init(SDL_INIT_EVERYTHING);

  //Apple specific OpenGL setup
  #ifdef __APPLE__
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
  #endif

  //Tell SDL that we want a double buffered window so we dont get
  //any flickering
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  return 0;
}
