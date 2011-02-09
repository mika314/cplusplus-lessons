// Урок 44
// Рисование трехмерных графиков
#include <GL/glut.h>
#include <cmath>

float f(float x, float y)
{
    return x * x / 1000+ y * y / 1000;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (float x = -480; x < 480; x += 10)
    {
        glBegin(GL_LINE_STRIP);
        for (float y = -480; y < 480; y += 10)
            glVertex3f(x, y, f(x, y));
        glEnd();
    }
    for (float y = -480; y < 480; y += 10)
    {
        glBegin(GL_LINE_STRIP);
        for (float x = -480; x < 480; x += 10)
            glVertex3f(x, y, f(x, y));
        glEnd();
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
    glutInitWindowPosition(20, 86);
    glutCreateWindow("3d plot");
    glClearColor(0, 0, 0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-100, 100, -100, 100, 100, 2000);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0, 0, -800);
    glRotatef(-30, 1, 0, 0);
    glutDisplayFunc(display);
    timer();
    glutMainLoop();
}
