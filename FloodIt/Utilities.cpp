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

// Thank you, bro @Krystian
// Check if two items are adjacent
bool Utilities::isAdjacent(int x1, int y1, int x2, int y2)
{
	return ((std::abs(x1 - x2) == 1 && std::abs(y1 - y2) == 0) || (std::abs(x1 - x2) == 0 && std::abs(y1 - y2) == 1));
}