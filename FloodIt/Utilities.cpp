#include "Utilities.h"

// Draw Rectangles
void Utilities::drawRect(float x, float y, float width, float height)
{
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + width);
	glVertex2f(x, y + width);
	glEnd();
}