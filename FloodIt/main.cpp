#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <sstream>
#include <math.h>
#include "Utilities.h"
#include <ctime>
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") // Get rid of console

int screenSize = 500; // Square Screen (width and height)
void Draw();
void Update(int value);
void drawEverySquare();
void drawColor(Color color);
void drawOption(int x, Color color);
void handleKeyboard(unsigned char key, int xmouse, int ymouse);
void checkColumn();
void checkRow();

Color board[17][17];
bool doIChange[17][17];
Color selectedColor;

int main(int argc, char** argv)
{
	srand(time(0));

	// Initialize
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - screenSize) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - screenSize) / 2); // Center the screen
	glutInitWindowSize(screenSize, screenSize);
	glutCreateWindow("Flood It");

	// Set up callback functions
	glutDisplayFunc(Draw);
	glutKeyboardFunc(handleKeyboard);
	glutTimerFunc(1000 / 60, Update, 0);

	// Set this game up to be 2D
	glViewport(0, 0, screenSize, screenSize);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, screenSize, 0.0f, screenSize, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Set Colors
	glColor3f(1.0f, 1.0f, 1.0f);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	// Initialize Board
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			board[i][j] = Color(rand() % 6);
			doIChange[i][j] = false;
		}
	}
	doIChange[0][0] = true;

	glutMainLoop();
	return 0;
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	drawEverySquare();

	glutSwapBuffers();
}

void Update(int value)
{
	glutTimerFunc(1000 / 60, Update, 0);
	glutPostRedisplay();
}

void drawEverySquare()
{
	//std::string s;
	//s = std::to_string(testArray[0][1]);
	//glRasterPos2f(100, 10);
	//glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)s.c_str());
	
	int posX = 80;
	int posY = 425;
	for (int row = 0; row < 17; row++)
	{
		posY = 425;
		for (int column = 0; column < 17; column++)
		{
			drawColor(board[row][column]);
			Utilities::drawRect(posX, posY, 20, 20);
			posY -= 20;
		}
		posX += 20;
	}

	// Draw the options at the bottom
	posX = 110;
	for (int i = 0; i < 6; i++)
	{
		drawOption(posX, Color(i));
		posX += 50;
	}
}

// Draws a square at the bottom
void drawOption(int x, Color color)
{
	// Draw the big box
	drawColor(color);
	Utilities::drawRect(x-3, 37, 46, 46);

	// Draw the smaller grey box
	drawColor(GREY);
	Utilities::drawRect(x-2, 38, 44, 44);

	// Draw the small box
	drawColor(color);
	Utilities::drawRect(x, 40, 40, 40);
}

void checkRow()
{
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			if (!doIChange[j][i])
			{
				if (board[j][i] == selectedColor)
				{
					doIChange[j][i] = true;
				}
				else
					return;
			}
		}
	}
}

void checkColumn()
{
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			if (!doIChange[i][j])
			{
				if (board[i][j] == selectedColor)
				{
					doIChange[i][j] = true;
				}
				else
					return;
			}
		}
	}
}

void playOption()
{
	Color currentColor = board[0][0];
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			checkColumn();
			checkRow();
		}
	}
	
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			if (doIChange[i][j] == true)
			{
				board[i][j] = selectedColor;
			}
		}
	}
}

void handleKeyboard(unsigned char key, int xmouse, int ymouse)
{
	switch (key)
	{
	case '1':
		std::cout << "1" << std::endl;
		selectedColor = RED;
		break;
	case '2':
		std::cout << "2" << std::endl;
		selectedColor = GREEN;
		break;
	case '3':
		std::cout << "3" << std::endl;
		selectedColor = BLUE;
		break;
	case '4':
		std::cout << "4" << std::endl;
		selectedColor = YELLOW;
		break;
	case '5':
		std::cout << "5" << std::endl;
		selectedColor = ORANGE;
		break;
	case '6':
		std::cout << "6" << std::endl;
		selectedColor = PINK;
		break;
	}
	playOption();
}

void drawColor(Color color)
{
	switch (color)
	{
	case RED:
		glColor3f(1, 0, 0);
		break;
	case GREEN:
		glColor3f(0, 1, 0);
		break;
	case BLUE:
		glColor3f(0, 0, 1);
		break;
	case YELLOW:
		glColor3f(1, 1, 0);
		break;
	case ORANGE:
		glColor3f(1, 0.5f, 0);
		break;
	case PINK:
		glColor3f(1, 0.43, 0.78);
		break;
	case GREY:
		glColor3f(0.1f, 0.1f, 0.1f);
		break;
	default:
		glColor3f(0, 0, 0);
		break;
	}
}