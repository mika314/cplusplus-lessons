// Урок 22
// Немного об OpenGL
#include <GL/glut.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2f(0.25, 0.25);
  glVertex2f(0.75, 0.75);
  glColor3f(0.0, 1.0, 0.0);
  glVertex2f(0.75, 0.25);
  glVertex2f(0.25, 0.75);
  glColor3f(0.0, 0.0, 1.0);
  glVertex2f(0.50, 0.25);
  glVertex2f(0.50, 0.75);
  glEnd();
  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(240, 240);
  glutInitWindowPosition(100, 740);
  glutCreateWindow("Test");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
}
