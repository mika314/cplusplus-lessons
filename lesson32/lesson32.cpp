// Урок 32
// Красивый спецэффект
#include <GL/glut.h>
#include "vica.h"
#include <cstdlib>
#include <cmath>

typedef float Color[3];

struct Pixel
{
  float x;
  float y;
  int x0;
  int y0;
  Color color;
};

Pixel bitmap[height][width];

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
  for (int y = 0; y < height; ++y)
    for (int x = 0; x < width; ++x)
    {
      Pixel &p = bitmap[y][x];
      glColor3f(p.color[0], p.color[1], p.color[2]);
      glVertex2f(p.x, p.y);
      float d = sqrt((p.x0 - p.x) * (p.x0 - p.x) +
		     (p.y0 - p.y) * (p.y0 - p.y));
      if (d > 0.1)
      {
	p.x += 0.1 * (p.x0 - p.x) / d;
	p.y += 0.1 * (p.y0 - p.y) / d;
      }
      else
      {
	p.x = p.x0;
	p.y = p.y0;
      }
    }
  glEnd();
  glutSwapBuffers();
}

void timer(int = 0)
{
  display();
  glutTimerFunc(1, timer, 0);
}

int main(int argc, char **argv)
{
  const char *d = header_data;
  Color pixel;
  for (int y = 0; y < height; ++y)
    for (int x = 0; x < width; ++x)
    {
      HEADER_PIXEL(d, pixel);
      Pixel &p = bitmap[y][x];
      p.color[0] = pixel[0] / 255.0;
      p.color[1] = pixel[1] / 255.0;
      p.color[2] = pixel[2] / 255.0;
      p.x0 = x;
      p.y0 = y;
      p.x = rand() % width;
      p.y = rand() % height;
    }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(200, 200);
  glutInitWindowPosition(20, 810);
  glutCreateWindow("Spec-effect");
  glClearColor(0, 0, 0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 200, 200, 0, -1, 1);
  glutDisplayFunc(display);
  timer();
  glutMainLoop();
}
