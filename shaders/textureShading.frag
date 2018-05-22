//
//  textureShading.frag
//  renderEngineCpp
//
//  Created by Jaap Wijnen on 22/05/2018.
//  Licensed under the terms of the MIT license
//

#version 330
//The fragment shader operates on each pixel in a given polygon

in vec3 fragmentPosition;
in vec4 fragmentColor;
in vec2 fragmentUV;
in vec3 fragmentNormal;
in vec3 eyePosition;
in vec3 sunDir;

//This is the 3 component float vector that gets outputted to the screen
//for each pixel.
out vec4 color;

//uniform sampler2D mySampler;

void main() {

  float ambientIntensity = 0.3;
  float diffuseIntensity = 0.5;
  float shininess = 8.0;
  float specularIntensity = 0.2;

  vec3 lightColor = vec3(1, 1, 1);

  vec3 ambientColor = lightColor * ambientIntensity;

  vec3 normal = normalize(fragmentNormal);
  float diffuseFactor = clamp(-dot(normal, sunDir), 0.0, 1.0);
  vec3 diffuseColor = lightColor * diffuseIntensity * diffuseFactor;

  vec3 eye = normalize(eyePosition);
  // reflection also appears on back of models as reflect doesnt care about negative normals
  vec3 reflection = reflect(sunDir, normal);
  float specularFactor = pow(clamp(-dot(reflection, eye), 0.0, 1.0), shininess);
  vec3 specularColor = lightColor * specularIntensity * specularFactor;

  color = fragmentColor * vec4((ambientColor + diffuseColor + specularColor), 1);
}
