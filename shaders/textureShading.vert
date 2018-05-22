//
//  textureShadering.vert
//  renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#version 330
//The vertex shader operates on each vertex

//input data from the VBO.
in vec3 vertexPosition;
in vec4 vertexColor;
in vec2 vertexUV;
in vec3 vertexNormal;

out vec3 fragmentPosition;
out vec4 fragmentColor;
out vec2 fragmentUV;
out vec3 fragmentNormal;
out vec3 eyePosition;
out vec3 sunDir;

uniform mat4 P;
uniform mat4 M;

void main() {

  //sunDir = vec3(0, 0, -1);
  sunDir = vec3(0.577350, -0.577350, -0.577350);
  //sunDir = vec3(0.267261, -0.534522, 0.801784);
  //sunDir = vec3(0.7071067812, 0, -0.7071067812);

  sunDir = (M * vec4(sunDir, 0.0)).xyz;

  gl_Position = P * M * vec4(vertexPosition, 1.0);

  fragmentPosition = vec3(M * vec4(vertexPosition, 1.0));

  fragmentColor = vertexColor;
  fragmentUV = vec2(vertexUV.x, 1.0 - vertexUV.y);

  fragmentNormal = (M * vec4(vertexNormal, 0)).xyz;

  eyePosition = (M * vec4(vertexPosition, 1.0)).xyz;
}
