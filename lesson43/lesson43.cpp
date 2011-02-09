// Урок 43
// Работа с мышкой
#include <GL/glut.h>
#include <cstdlib>
#include <cmath>
using namespace std;

int x = 0;
int y = 0;
bool down = false;

const int N = 1000;

struct P
{
    float x;
    float y;
    float vx;
    float vy;
    float r;
    float g;
    float b;
} p[N];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    glBegin(GL_POINTS);
    for (int i = 0; i < N; ++i)
    {
        glColor3f(p[i].r, p[i].g, p[i].b);
        glVertex2f(p[i].x, p[i].y);
    }
    glEnd();
    glutSwapBuffers();
}

void timer(int = 0)
{
    display();
    for (int i = 0; i < N; ++i)
    {
        p[i].x += p[i].vx;
        p[i].y += p[i].vy;
        if (down)
        {
            float d = sqrt((p[i].x - x) * (p[i].x - x) + (p[i].y - y) * (p[i].y - y));
            p[i].x += 5 * (x - p[i].x) / d;
            p[i].y += 5 * (y - p[i].y) / d;
        }
    }
    glutTimerFunc(10, timer, 0);
}

void mouse(int button, int state, int ax, int ay)
{
    x = ax;
    y = ay;
    down = state == GLUT_DOWN;
}

void motion(int ax, int ay)
{
    x = ax;
    y = ay;
}

int main(int argc, char **argv)
{
    for (int i = 0; i < N; ++i)
    {
        p[i].x = rand() % 480;
        p[i].y = rand() % 480;
        p[i].vx = rand() % 480 / 100.0 - 2.4;
        p[i].vy = rand() % 480 / 100.0 - 2.4;
        p[i].r = rand() % 200 / 200.0;
        p[i].g = rand() % 200 / 200.0;
        p[i].b = rand() % 200 / 200.0;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(20, 1050 - 480 - 20);
    glutCreateWindow("Mouse");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0, 480, 480, 0, -1, 1);
    glutDisplayFunc(display);
    timer();
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(motion);
    glutMainLoop();
}
