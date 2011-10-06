// Урок 50
// Matrix Code
#include <GL/glut.h>
#include <iostream>
using namespace std;

struct Ch
{
  Ch(char ach = ' ', int alive = 0): 
    ch(ach), 
    live(alive)
  {}
  char ch;
  int live;
};

const int W = 852 / 9;
const int H = 480 / 15;

Ch screen[W][H];

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  for (int y = 0; y < H; ++y)
    for (int x = 0; x < W; ++x)
    {
      glRasterPos2f(x * 9, (y + 1) * 15);
      glColor3f(0, screen[x][y].live / 2000.0, 0);
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, screen[x][y].ch);
    }
  glutSwapBuffers();
}

void timer(int = 0)
{
  for (int y = 0; y < H; ++y)
    for (int x = 0; x < W; ++x)
      if (screen[x][y].live > 0)
        --screen[x][y].live;
  int x = rand() % W;
  for (int y = 0; y < H; ++y)
    if (screen[x][y].live <= 0)
    {
      screen[x][y].ch = rand() % 256;
      screen[x][y].live = 2000;
      break;
    }
  glutPostRedisplay();
  glutTimerFunc(0, timer, 0);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(852, 480);
  glutInitWindowPosition(0, 86);
  glutCreateWindow("Matrix Code");
  glClearColor(0, 0, 0, 1.0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 852, 480, 0, -1, 1);
  glutDisplayFunc(display);
  
  timer();
  glutMainLoop();
}
