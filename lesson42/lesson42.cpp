// Урок 42
// Броуновское движение
#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

const float DT = 0.01;

struct P
{
    float x;
    float y;
    float vx;
    float vy;
    float m;
};

vector<P> p;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (vector<P>::iterator i = p.begin(); i != p.end(); ++i)
    {
        if (i -> m <= 2)
        {
            glPointSize(2);
            glBegin(GL_POINTS);
            glVertex2f(i -> x, i -> y);
            glEnd();
        }
        else
        {
            glBegin(GL_LINES);
            for (int a = 0; a < 36; ++a)
            {
                float x = i -> m * cos(a * M_PI / 18);
                float y = i -> m * sin(a * M_PI / 18);
                glVertex2f(i -> x + x, i -> y + y);
                x = i -> m * cos((a + 1) * M_PI / 18);
                y = i -> m * sin((a + 1) * M_PI / 18);
                glVertex2f(i -> x + x, i -> y + y);
            }
            glEnd();
        }
    }
    glutSwapBuffers();
}

void timer(int = 0)
{
    for (vector<P>::iterator i = p.begin(); i != p.end(); ++i)
        for (vector<P>::iterator j = p.begin(); j != p.end(); ++j)
            if (i != j)
            {
                float d = sqrt((i -> x - j -> x) * (i -> x - j -> x) + (i -> y - j -> y) * (i -> y - j -> y));
                if (d < i -> m + j -> m)
                {
                    float f = 50 * (i -> m + j -> m - d);
                    i -> vx += f * (i -> x - j -> x) / d / i -> m * DT;
                    i -> vy += f * (i -> y - j -> y) / d / i -> m * DT;
                    j -> vx -= f * (i -> x - j -> x) / d / j -> m * DT;
                    j -> vy -= f * (i -> y - j -> y) / d / j -> m * DT;
                }
            }
    for (vector<P>::iterator i = p.begin(); i != p.end(); ++i)
    {
        i -> x += i -> vx * DT;
        i -> y += i -> vy * DT;
        if (i -> x < 0)
            i -> x += 480;
        if (i -> y < 0)
            i -> y += 480;
        if (i -> x > 480)
            i -> x -= 480;
        if (i -> y > 480)
            i -> y -= 480;
    }
    display();
    glutTimerFunc(10, timer, 0);
}

int main(int argc, char **argv)
{
    P p0 = { 480 / 2, 480 / 2, 0, 0, 40 };
    p.push_back(p0);
    for (int i = 0; i < 100; ++i)
    {
        P p0 = { rand() % 480, rand() % 480, rand() % 100000 / 500.0 - 100, rand() % 100000 / 500.0 - 100, 4 };
        p.push_back(p0);
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(20, 1050 - 480 - 20);
    glutCreateWindow("Brownian motion");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0, 480, 480, 0, -1, 1);
    glutDisplayFunc(display);
    timer();
    glutMainLoop();
}
