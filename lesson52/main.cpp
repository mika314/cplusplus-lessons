// Урок 52 Спрайты
#include "animation.h"
#include "GL/glut.h"

int n = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f((n % 10) * 0.1, 0);
    glVertex2f(n * 20 - 150, 0);
  
    glTexCoord2f((n % 10 + 149.0 / 150.0) * 0.1, 0);
    glVertex2f(n * 20, 0);

    glTexCoord2f((n % 10 + 149.0 / 150.0) * 0.1, 1);
    glVertex2f(n * 20, 150);

    glTexCoord2f(n % 10 * 0.1, 1);
    glVertex2f(n * 20 - 150, 150);
    glEnd();
    glutSwapBuffers();
}

void timer(int = 0)
{
    ++n;
    n %= 50;
    glutTimerFunc(100, timer, 0);
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(848, 150);
    glutInitWindowPosition(0, 200);
    glutCreateWindow("Sprites");
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 848, 150, 0, -1.0, 1.0);
    glutDisplayFunc(display);

    loadAnimation();
    glEnable(GL_TEXTURE_2D);
    timer();
    glutMainLoop();
}
