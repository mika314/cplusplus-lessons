// Урок24
// Рисование в полярных координатах
#include <GL/glut.h>
#include <cmath>
using namespace std;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_LOOP);
  for (float a = 0; a < 2 * M_PI; a += 0.01)
  {
    float r = 0.2 * (1 + sin(a)) * (1 + 0.9 * 
				    cos(8 * a)) * 
      (1 + 0.1 * cos(24 * a));
    glVertex2f(r * cos(a), r * sin(a));
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
  glutCreateWindow("Drawing in polar coordinates");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
}
