//
//  FPSLimiter.h
//  renderEngineCpp
//  https://github.com/JaapWijnen/renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#pragma once

///Calculates FPS and also limits FPS
class FpsLimiter {
public:
  FpsLimiter();

  // Initializes the FPS limiter. For now, this is
  // analogous to setMaxFPS
  void init(float maxFPS);

  // Sets the desired max FPS
  void setMaxFPS(float maxFPS);

  void begin();

  // end() will return the current FPS as a float
  float end();
private:
  // Calculates the current FPS
  void calculateFPS();

  // Variables
  float _fps;
  float _maxFPS;
  float _frameTime;
  unsigned int _startTicks;
};
