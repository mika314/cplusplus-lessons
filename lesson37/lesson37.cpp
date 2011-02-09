// Урок 37
// Моделирование груза на пружине
#include <GL/glut.h>
#include <cmath>

struct Load
{
    float y;
    float vy;
};

Load load = { 350, 0 };

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2f(200, 0);
    glVertex2f(200, load.y);
    for (int i = 0; i < 36; ++i)
    {
        glVertex2f(200 + 5 * cos(2 * M_PI * i / 36), load.y + 5 * sin(2 * M_PI * i / 36));
        glVertex2f(200 + 5 * cos(2 * M_PI * (i + 1) / 36), load.y + 5 * sin(2 * M_PI * (i + 1) / 36));
    }
    glEnd();
    glutSwapBuffers();
}

void timer(int = 0)
{
    float f = 0;
    if (load.y > 200)
        f = 0.001 * (load.y - 200);
    f -= 0.1;
    load.vy -= f;
    load.y += load.vy;
    display();
    glutTimerFunc(10, timer, 0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(20, 1050 - 450);
    glutCreateWindow("Load");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 400, 400, 0, -1, 1);
    glutDisplayFunc(display);
    timer();
    glutMainLoop();
}
