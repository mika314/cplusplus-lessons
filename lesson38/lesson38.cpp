// Урок 38
// Моделирование резинки
#include <GL/glut.h>
#include <vector>
#include <cmath>
using namespace std;

const int DELTA_T = 10000; // micro seconds

struct Particle
{
    float x;
    float y;
    float vx;
    float vy;
};

class Rubber
{
    vector<Particle> p_;
public:
    Rubber()
    {
        const int N = 60;
        for (int i = 0; i < N; ++i)
        {
            Particle tmp = { 200 + i * 200 / N, i * 20 / N, 0, 0 };
            p_.push_back(tmp);
        }
    }
    void draw() const
    {
        glBegin(GL_LINE_STRIP);
        for (vector<Particle>::const_iterator i = p_.begin(); i != p_.end(); ++i)
            glVertex2f(i -> x, i -> y);
        glEnd();
        glBegin(GL_LINE_STRIP);
        const Particle &p = *p_.rbegin();
        for (int i = 0; i < 36; ++i)
            glVertex2f(p.x + 5 * cos(2 * M_PI * i / 36), p.y + 5 * sin(2 * M_PI * i / 36));
        glEnd();
    }
    void tick()
    {
        for (int i = 1; i < p_.size(); ++i)
        {
            float ax = 0;
            float ay = 0;
            float a = 0;
            Particle &p0 = p_[i - 1];
            Particle &p1 = p_[i];

            float d = sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y));
            const float rest = 180.0 / p_.size();
            if (d > rest)
                a = 5.0 * (d - rest);
            // if (d < 1)
            //     a =- 1.0 * (2 - d);

            ax = a * (p0.x - p1.x) / d;
            ay = a * (p0.y - p1.y) / d;
            p1.vx += ax * DELTA_T / 1000000.0;
            p1.vy += ay * DELTA_T / 1000000.0;
            if (i != 1)
            {
                p0.vx -= ax * DELTA_T / 1000000.0;
                p0.vy -= ay * DELTA_T / 1000000.0;
            }
        }
        Particle &p = *p_.rbegin();
        p.vy += 5.0 * DELTA_T / 1000000.0;
        for (vector<Particle>::iterator i = p_.begin(); i != p_.end(); ++i)
        {
            i -> vx *= (1 - 0.00004);
            i -> vy *= (1 - 0.00004);
            i -> x += i -> vx * DELTA_T / 1000000.0;
            i -> y += i -> vy * DELTA_T / 1000000.0;
        }
    }
};

Rubber rubber;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    rubber.draw();
    glutSwapBuffers();
}

void timer(int = 0)
{
    for (int i = 0; i < 400000 / DELTA_T; ++i)
        rubber.tick();
    display();
    glutTimerFunc(10, timer, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(20, 1050 - 480 - 20);
    glutCreateWindow("Rubber band");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 400, 400, 0, -1, 1);
    glutDisplayFunc(display);
    timer();
    glutMainLoop();
}
