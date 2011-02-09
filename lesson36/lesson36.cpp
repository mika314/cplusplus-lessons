// Урок 36
// Часы
#include <GL/glut.h>
#include <cmath>
#include <ctime>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
  for (int i = 0; i < 12; ++i)
  {
      float x = sin(2 * M_PI / 12 * i);
      float y = cos(2 * M_PI / 12 * i);
      glVertex2f(400 * x, 400 * y);
      glVertex2f(380 * x, 380 * y);
  }
  time_t t = time(0);
  tm *lt = localtime(&t);
  int h = lt -> tm_hour;
  int m = lt -> tm_min;
  int s = lt -> tm_sec;
  float x = sin(2 * M_PI * (h * 60 + m) / 12 / 60);
  float y = cos(2 * M_PI * (h * 60 + m) / 12 / 60);
  glVertex2f(0, 0);
  glVertex2f(200 * x, 200 * y);
  x = sin(2 * M_PI * m / 60);
  y = cos(2 * M_PI * m / 60);
  glVertex2f(0, 0);
  glVertex2f(350 * x, 350 * y);

  x = sin(2 * M_PI * s / 60);
  y = cos(2 * M_PI * s / 60);
  glVertex2f(0, 0);
  glVertex2f(380 * x, 380 * y);
  glEnd();
  glutSwapBuffers();
}

void timer(int = 0)
{
  display();
  glutTimerFunc(10, timer, 0);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(20, 1050 - 480 - 20);
  glutCreateWindow("Clock");
  glClearColor(0, 0, 0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho (-400, 400, -400, 400, -400, 400);
  glutDisplayFunc(display);
  timer();
  glutMainLoop();
}
