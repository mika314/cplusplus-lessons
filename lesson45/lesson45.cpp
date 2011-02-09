// Урок 45
// Волны
#include <GL/glut.h>
#include <cmath>

const float K = 40;
const float DT = 0.03;

float sqr(float x)
{
    return x * x;
}

struct P
{
    P(): z(0), vz(0) {}
    float x;
    float y;
    float z;
    float vz;
};

const int N = 48;

P p[N][N];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (int x = 0; x < N; ++x)
    {
        glBegin(GL_LINE_STRIP);
        for (int y = 0; y < N; ++y)
            glVertex3f(p[x][y].x, p[x][y].y, p[x][y].z * 10);
        glEnd();
    }
    for (int y = 0; y < N; ++y)
    {
        glBegin(GL_LINE_STRIP);
        for (int x = 0; x < N; ++x)
            glVertex3f(p[x][y].x, p[x][y].y, p[x][y].z * 10);
        glEnd();
    }
    glutSwapBuffers();
}

void timer(int = 0)
{
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};
    if (rand() % 500 == 0)
        p[rand() % (N - 2) + 1][rand() % (N - 2) + 1].vz += 150;
    for (int y = 1; y < N - 1; ++y)
        for (int x = 1; x < N - 1; ++x)
        {
            P &p0 = p[x][y];
            for (int i = 0; i < 4; ++i)
            {
                P &p1 = p[x + dx[i]][y + dy[i]];
                const float d = sqrt(sqr(p0.x - p1.x) + sqr(p0.y - p1.y) + sqr(p0.z - p1.z));
                p0.vz += K * (p1.z - p0.z) / d * DT;
                p0.vz *= 0.999;
            }

        }
    for (int y = 1; y < N - 1; ++y)
        for (int x = 1; x < N - 1; ++x)
        {
            P &p0 = p[x][y];
            p0.z += p0.vz * DT;
        }
    display();
    glutTimerFunc(1, timer, 0);
}

int main(int argc, char **argv)
{
    for (int x = 0; x < N; ++x)
        for (int y = 0; y < N; ++y)
        {
            p[x][y].x = x * 480 / N;
            p[x][y].y = y * 480 / N;
        }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(852, 480);
    glutInitWindowPosition(0, 86);
    glutCreateWindow("3d plot");
    glClearColor(0, 0, 0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-100, 100, -100, 100, 100, 2000);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(-240, -240, -200);
    glRotatef(-30, 1, 0, 0);
    glutDisplayFunc(display);
    timer();
    glutMainLoop();
}
