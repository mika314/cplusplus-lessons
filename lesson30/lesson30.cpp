// Урок 30
// Вращающийся куб
#include <GL/glut.h>
#include <cmath>

int a = 0;
float b = 0;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glTranslatef(0, 0, -300);
  glRotatef(a, sin(b / 100) + 1, cos(b / 200) + 1, sin(b / 300) + 1);
  glBegin(GL_LINE_STRIP);
  glVertex3f(-50, -50, -50);
  glVertex3f(50, -50, -50);
  glVertex3f(50, 50, -50);
  glVertex3f(-50, 50, -50);
  glVertex3f(-50, -50, -50);
  glEnd();
  glBegin(GL_LINE_STRIP);
  glVertex3f(-50, -50, 50);
  glVertex3f(50, -50, 50);
  glVertex3f(50, 50, 50);
  glVertex3f(-50, 50, 50);
  glVertex3f(-50, -50, 50);
  glEnd();
  glBegin(GL_LINES);
  glVertex3f(-50, -50, 50);
  glVertex3f(-50, -50, -50);
  glVertex3f(50, -50, 50);
  glVertex3f(50, -50, -50);
  glVertex3f(50, 50, 50);
  glVertex3f(50, 50, -50);
  glVertex3f(-50, 50, 50);
  glVertex3f(-50, 50, -50);
  glEnd();
  glPopMatrix();
  glutSwapBuffers();
}

void timer(int = 0)
{
  ++a;
  ++b;
  display();
  glutTimerFunc(10, timer, 0);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(200, 200);
  glutInitWindowPosition(20, 810);
  glutCreateWindow("Cube");
  glClearColor(0, 0, 0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //glOrtho (-100, 100, -100, 100, -100, 100);
  gluPerspective(45, 1, 0, 100);
  glutDisplayFunc(display);
  timer();
  glutMainLoop();
}
