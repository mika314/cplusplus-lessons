// Урок 4
// Оператор switch
#include <GL/glut.h>
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
  for (int i = 0; i < 100; ++i)
  {
      glVertex2f(rand() % 480, rand() % 480);
      glVertex2f(rand() % 480, rand() % 480);
  }
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
  glutInitWindowSize(480, 480); 
  glutInitWindowPosition(0, 130);
  glutCreateWindow("");
  glClearColor(0, 0, 0, 1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 480, 480, 0, 
	  -1.0, 1.0);
  glutDisplayFunc(display);
  timer(0);

  glutMainLoop();
}
