#pragma once

#include <string>
#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "GL/freeglut.h"
#pragma comment(lib, "OpenGL32.lib")

enum Color
{
	RED,
	GREEN,
	BLUE,
	YELLOW,
	ORANGE,
	PINK,
	BLACK,
	GREY
};

class Utilities
{
public:
	// Draw rectangles
	static void drawRect(float x, float y, float width, float height);
};