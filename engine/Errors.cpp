//
//  Errors.cpp
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#include <GLFW/glfw3.h>

#include "Errors.h"

#include <cstdlib>
#include <iostream>

//Prints out an error message and exits the game
void fatalError(std::string errorString) {
  std::cout << errorString << std::endl;
  std::cout << "Enter any key to quit...";
  int tmp;
  std::cin >> tmp;
  glfwTerminate();
  exit(69);
}
