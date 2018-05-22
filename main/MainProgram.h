//
//  MainProgram.h
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#pragma once

#include "Window.h"
#include "GLSLProgram.h"
#include "Camera.h"
#include "InputManager.h"
#include "Node.h"

enum class ProgramState {
  RUN,
  EXIT
};

class MainProgram
{
public:
  MainProgram();
  ~MainProgram();

  void run();

private:
  /// Initializes the core systems
  void initSystems();

  /// Initializes the shaders
  void initShaders();

  /// Main game loop for the program
  void gameLoop();

  /// Handles input processing
  void processInput();

  /// Renders the game
  void drawGame();

  /// Member Variables
  Window _window; ///< The game window

  GLSLProgram _textureProgram; ///< The shader program

  InputManager _inputManager; ///< Handles input

  Camera _camera; ///< Main Camera

  int _screenWidth, _screenHeight;

  float _fps;

  Node _rootNode;

  ProgramState _programState;
};
