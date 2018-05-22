# Render Engine
Render engine written in C++ and OpenGL

Heavily influenced by the [Making Games With Ben](https://www.youtube.com/watch?v=FxCC9Ces1Yg&list=PLSPw4ASQYyymu3PfG9gxywSPghnSMiOAW) tutorials and other tutorials on 3d and OpenGL.

This project is licensed under the terms of the MIT license.

This project has the following requirements
- SDL 2.0
- glm
- glew (on linux)

## macOS
Download SDL2 from https://www.libsdl.org/download-2.0.php#source
copy the .framework file to the frameworks folder

- to build `make`
- to run `make run`

## Linux

SDL2 might have to be installed differently check
http://lazyfoo.net/tutorials/SDL/01_hello_SDL/linux/index.php
for some pointers.
It might or might not work with the -framework flags in the makefile. I'm not sure how that works on linux.
Also OpenGL includes on macOS are as follows
`#include <OpenGL/gl3.h>`
on Linux these might be different such as `#include <GL/glew.h>`

- to build `make`
- to run `make run`
