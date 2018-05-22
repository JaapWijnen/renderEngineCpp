//
//  MainProgram.cpp
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#include "MainProgram.h"

#include <SDL2/SDL.h>

#include <random>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <map>

#include "Engine.h"
#include "FPSLimiter.h"
#include "Errors.h"
#include "IOManager.h"

#include "Sphere.h"
#include "Quad.h"
#include "Cube.h"

MainProgram::MainProgram() :
  _screenWidth(1024),
  _screenHeight(768),
  _programState(ProgramState::RUN),
  _fps(0) {
  // Empty
}

MainProgram::~MainProgram() {

}

void MainProgram::run() {

  initSystems();

  _rootNode = Node();
  _rootNode.setName("root");

  gameLoop();
}

void MainProgram::initSystems() {
  // Initialize the game engine
  Engine engine;
  engine.init();

  // Create our window
  _window.create("renderEngine", _screenWidth, _screenHeight, 0);

  // Grey background color
  glClearColor(0.7f, 0.7f, 0.7f, 1.0f);

  // Set up the shaders
  initShaders();

  SDL_SetRelativeMouseMode(SDL_TRUE);

  // Set up the camera
  _camera.init(_screenWidth, _screenHeight, 60.0f);
  _camera.setPosition(glm::vec3(0.0f, 0.0f, -5.0f));
  _camera.setRotation(glm::vec3(0.0f, 0.0f, 0.0f));
  _camera.setScale(glm::vec3(1.0f));
}

void MainProgram::initShaders() {
  // Compile our color shader
  _textureProgram.compileShaders("shaders/textureShading.vert", "shaders/textureShading.frag");
  _textureProgram.addAttribute("vertexPosition");
  _textureProgram.addAttribute("vertexColor");
  _textureProgram.addAttribute("vertexUV");
  _textureProgram.addAttribute("vertexNormal");
  _textureProgram.linkShaders();
}

void MainProgram::gameLoop() {

  const float DESIRED_FPS = 60.0f;
  const int MAX_PHYSICS_STEPS = 6;

  FpsLimiter fpsLimiter;
  fpsLimiter.setMaxFPS(60.0f);

  const float CAMERA_SPEED = 0.02f;
  const float MOUSE_SENSITIVITY = 0.002f;
  //const float CAMERA_SCALE = 1.0f; // 4.0f;

  const float MS_PER_SECOND = 1000;
  const float DESIRED_FRAMETIME = MS_PER_SECOND / DESIRED_FPS;
  const float MAX_DELTA_TIME = 1.0f;

  float previousTicks = SDL_GetTicks();

  // Main loop
  while (_programState == ProgramState::RUN) {
    fpsLimiter.begin();

    float newTicks = SDL_GetTicks();
    float frameTime = newTicks - previousTicks;
    previousTicks = newTicks;
    float totalDeltaTime = frameTime / DESIRED_FRAMETIME;

    _inputManager.update();

    processInput();

    glm::vec3 cameraPosition = _camera.getPosition();
    glm::vec3 cameraRotation = _camera.getRotation();

    int i = 0;
    while (totalDeltaTime > 0.0f && i < MAX_PHYSICS_STEPS) {
      float deltaTime = std::min(totalDeltaTime, MAX_DELTA_TIME);

      if (_inputManager.isKeyDown(SDLK_w)) {
        cameraPosition.x += sin(-cameraRotation.y) * CAMERA_SPEED * deltaTime;
        cameraPosition.z += cos(-cameraRotation.y) * CAMERA_SPEED * deltaTime;
      } else if (_inputManager.isKeyDown(SDLK_s)) {
        cameraPosition.x -= sin(-cameraRotation.y) * CAMERA_SPEED * deltaTime;
        cameraPosition.z -= cos(-cameraRotation.y) * CAMERA_SPEED * deltaTime;
      }

      if (_inputManager.isKeyDown(SDLK_a)) {
        cameraPosition.x += cos(cameraRotation.y) * CAMERA_SPEED * deltaTime;
        cameraPosition.z += sin(cameraRotation.y) * CAMERA_SPEED * deltaTime;
      } else if (_inputManager.isKeyDown(SDLK_d)) {
        cameraPosition.x -= cos(cameraRotation.y) * CAMERA_SPEED * deltaTime;
        cameraPosition.z -= sin(cameraRotation.y) * CAMERA_SPEED * deltaTime;
      }

      if(_inputManager.isKeyDown(SDLK_q)) {
        cameraPosition.y -= CAMERA_SPEED * deltaTime;
      } else if (_inputManager.isKeyDown(SDLK_e)) {
        cameraPosition.y += CAMERA_SPEED * deltaTime;
      }

      if(_inputManager.isKeyDown(SDLK_r)) {
        cameraRotation.y -= CAMERA_SPEED * deltaTime;
      } else if (_inputManager.isKeyDown(SDLK_f)) {
        cameraRotation.y += CAMERA_SPEED * deltaTime;
      }

      glm::vec2 deltaMouse = _inputManager.getDeltaMouse();
      cameraRotation.y += MOUSE_SENSITIVITY * deltaMouse.x;
      cameraRotation.x += MOUSE_SENSITIVITY * deltaMouse.y;

      totalDeltaTime -= deltaTime;
      i++;
    }

    _camera.setPosition(cameraPosition);
    _camera.setRotation(cameraRotation);

    _camera.update();

    drawGame();

    _fps = fpsLimiter.end();
    //std::cout << _fps << std::endl;
  }
}

void MainProgram::processInput() {
  if(_inputManager.isKeyDown(SDLK_ESCAPE)){
     _programState = ProgramState::EXIT;
  }
  SDL_Event evnt;
  //Will keep looping until there are no more events to process
  while (SDL_PollEvent(&evnt)) {
    switch (evnt.type) {
      case SDL_QUIT:
        _programState = ProgramState::EXIT;
        break;
      case SDL_MOUSEMOTION:
        _inputManager.setMouseCoords(evnt.motion.x, evnt.motion.y, evnt.motion.xrel, evnt.motion.yrel);
        break;
      case SDL_KEYDOWN:
        _inputManager.pressKey(evnt.key.keysym.sym);
        break;
      case SDL_KEYUP:
        _inputManager.releaseKey(evnt.key.keysym.sym);
        break;
      case SDL_MOUSEBUTTONDOWN:
        _inputManager.pressKey(evnt.button.button);
        break;
      case SDL_MOUSEBUTTONUP:
        _inputManager.releaseKey(evnt.button.button);
        break;
    }
  }
}

void MainProgram::drawGame() {
  // Set the base depth to 1.0
  glClearDepth(1.0);
  // Clear the color and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _textureProgram.use();

  // Draw code goes here
  glActiveTexture(GL_TEXTURE0);

  // Make sure the shader uses texture 0
  //GLint textureUniform = _textureProgram.getUniformLocation("mySampler");
  //glUniform1i(textureUniform, 0);

  // Grab the projection matrix
  glm::mat4 projectionMatrix = _camera.getProjectionMatrix();
  GLint pUniform = _textureProgram.getUniformLocation("P");
  glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);

  // render rootNode and all it's children (from camera perspective)
  _rootNode.render(_textureProgram, _camera.getCameraMatrix());

  // Unbind the program
  _textureProgram.unuse();

  // Swap our buffer and draw everything to the screen!
  _window.swapBuffer();
}
