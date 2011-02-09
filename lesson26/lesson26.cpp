// Урок26
// Салфетки
#include <GL/glut.h>
#include <cmath>
using namespace std;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  enum {N = 20};
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j)
    {
      glVertex2f(cos(2 * M_PI * i / N), 
		 sin(2 * M_PI * i / N));
      glVertex2f(cos(2 * M_PI * j / N), 
		 sin(2 * M_PI * j / N));
    }
  glEnd();
  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(240, 240);
  glutInitWindowPosition(100, 740);
  glutCreateWindow("");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
}
