// Урок 23
// Что будет, если долго подбрасывать монетку
#include <GL/glut.h>
#include <cstdlib>

const int SER_COUNT = 240;

int r()
{
  int r = 0;
  for (int i = 0; i < SER_COUNT; ++i)
    if (rand() % 2)
      r++;
  return r;
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  int q[SER_COUNT + 1];
  for (int i = 0; i <= SER_COUNT; ++i)
    q[i] = 0;
  for (int i = 0; i < 1000000; ++i)
    q[r()]++;
  int max = 0;
  for (int i = 0; i <= SER_COUNT; ++i)
    if (max < q[i])
      max = q[i];
  glBegin(GL_POINTS);
  glColor3f(0.0, 0.0, 0.0);
  for (int i = 0; i <= SER_COUNT; ++i)
    glVertex2f(i, SER_COUNT * q[i] / max);
  glEnd();

  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(240, 240);
  glutInitWindowPosition(100, 740);
  glutCreateWindow("Coin");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 240.0, 0.0, 240.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
}
