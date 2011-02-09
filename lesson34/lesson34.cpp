// Урок 34
// Рисуем фрактал Мандельброта
#include <GL/glut.h>
#include <cmath>
#include <complex>

typedef std::complex<double> Complex;

Complex sqr(const Complex &v)
{
    return pow(v, 2);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
  for (int y = 0; y < 200; ++y)
      for (int x = 0; x < 200; ++x)
      {
          Complex z(0, 0);
          int i = 0;
          while (i < 1000 && abs(z) < 2)
          {
              z = sqr(z) + Complex(1.0 * (x - 100) / 70, 
                                   1.0 * (y - 100) / 70);
              ++i;
          }
          if (abs(z) >= 2)
          {
              float col = (50.0 - i) / 50.0;
              glColor3f(col, col, col);
              glVertex2f(x, y);
          }
      }
  glEnd();
  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(200, 200);
  glutInitWindowPosition(20, 810);
  glutCreateWindow("Mandelbrot");
  glClearColor(0, 0, 0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 200, 200, 0, -1, 1);
  glutDisplayFunc(display);
  glutMainLoop();
}
