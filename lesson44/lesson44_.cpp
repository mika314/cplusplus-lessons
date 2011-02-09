// Урок 44
// Рисование трехмерных графиков
#include <GL/glut.h>
#include <cmath>

float f(float x, float y, float t)
{
    return sin(x * 0.05 + t * 0.1) * cos(y * 0.05 + t * 0.1) * 48;
}

float t = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(0, 0, -800);
    glRotatef(-30, 1, 0, 0);
    for (float x = -480; x < 480; x += 10)
    {
        glBegin(GL_LINE_STRIP);
        for (float y = -480; y < 480; y += 10)
        {
            glVertex3f(x, y, f(x, y, t));
        }
        glEnd();
    }
    for (float y = -480; y < 480; y += 10)
    {
        glBegin(GL_LINE_STRIP);
        for (float x = -480; x < 480; x += 10)
        {
            glVertex3f(x, y, f(x, y, t));
        }
        glEnd();
    }
    glPopMatrix();
    glutSwapBuffers();
}

void timer(int = 0)
{
    t += 0.1;
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
    glutDisplayFunc(display);
    timer();
    glutMainLoop();
}
