//
//  Window.cpp
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#include "Window.h"
#include "Errors.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

Window::Window()
{
}


Window::~Window()
{
}

int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags) {

  //Uint32 flags = SDL_WINDOW_OPENGL;

  /*if (currentFlags & INVISIBLE) {
    flags |= SDL_WINDOW_HIDDEN;
  }
  if (currentFlags & FULLSCREEN) {
    flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
  }
  if (currentFlags & BORDERLESS) {
    flags |= SDL_WINDOW_BORDERLESS;
  }*/

  const unsigned int SCR_WIDTH = 800;
  const unsigned int SCR_HEIGHT = 600;

  _glfwWindow = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
  if (_glfwWindow == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  /*//Open an SDL window
  _sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);
  if (_sdlWindow == nullptr) {
    fatalError("SDL Window could not be created!");
  }*/

  glfwMakeContextCurrent(_glfwWindow);
  glfwSetFramebufferSizeCallback(_glfwWindow, framebuffer_size_callback);
  //Set up our OpenGL context
  /*SDL_GLContext glContext = SDL_GL_CreateContext(_sdlWindow);
  if (glContext == nullptr) {
    fatalError("SDL_GL context could not be created!");
  }*/

  /*#ifdef __linux__
  //Set up glew (optional but recommended)
  GLenum error = glewInit();
  if (error != GLEW_OK) {
    fatalError("Could not initialize glew!");
  }
  #endif */


  //Check the OpenGL version
  std::printf("***   OpenGL Version: %s   ***\n", glGetString(GL_VERSION));

  //Set the background color to blue
  glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

  //Set VSYNC
  //SDL_GL_SetSwapInterval(0);

  // Enable alpha blend
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  return 0;
}

void Window::swapBuffer() {
  glfwSwapBuffers(_glfwWindow);

  // needs a more appropriate place?
  glfwPollEvents();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
