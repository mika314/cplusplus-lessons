// Урок 41
// Волновой алгоритм
#include <GL/glut.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 24;
const int WALL = 9999;
int map[N][N];
vector<pair<int, int> > wave;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (map[i][j] == WALL)
                glColor3f(1, 1, 1);
            else if (map[i][j] == -1)
                glColor3f(0, 0, 0);
            else
                glColor3f(map[i][j] / 48.0, 0, 0);
            glVertex2f((i) * 480 / N, (j) * 480 / N);
            glVertex2f((i + 1) * 480 / N, (j) * 480 / N);
            glVertex2f((i + 1) * 480 / N, (j + 1) * 480 / N);
            glVertex2f((i) * 480 / N, (j + 1) * 480 / N);
        }
    for (vector<pair<int, int> >::iterator i = wave.begin(); i != wave.end(); ++i)
    {
        glColor3f(0, 1, 0);
        glVertex2f((i -> first) * 480 / N, (i -> second) * 480 / N);
        glVertex2f((i -> first + 1) * 480 / N, (i -> second) * 480 / N);
        glVertex2f((i -> first + 1) * 480 / N, (i -> second + 1) * 480 / N);
        glVertex2f((i -> first) * 480 / N, (i -> second + 1) * 480 / N);
    }
    glEnd();
    glutSwapBuffers();
}

void timer(int = 0)
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (rand() % 4 == 0)
                map[i][j] = WALL;
            else
                map[i][j] = -1;
        }
    for (int i = 0; i < N; ++i)
    {
        map[i][0] = WALL;
        map[0][i] = WALL;
        map[i][N - 1] = WALL;
        map[N - 1][i] = WALL;
    }
    vector<pair<int, int> > oldWave;
    oldWave.push_back(pair<int, int>(1, 1));
    int nstep = 0;
    map[1][1] = nstep;
    const int dx[] = { 0, 1, 0, -1 };
    const int dy[] = { -1, 0, 1, 0 };
    while (oldWave.size() > 0)
    {
        ++nstep;
        wave.clear();
        for (vector<pair<int, int> >::iterator i = oldWave.begin(); i != oldWave.end(); ++i)
        {
            for (int d = 0; d < 4; ++d)
            {
                int nx = i -> first + dx[d];
                int ny = i -> second + dy[d];
                if (map[nx][ny] == -1)
                {
                    wave.push_back(pair<int, int>(nx, ny));
                    map[nx][ny] = nstep;
                    display();
                    if (nx == N - 2 && ny == N - 2)
                        goto done;
                    for (int b = 0; b < 10000; ++b)
                    {}
                }
            }
        }
        oldWave = wave;
    }
 done:
    int x = N - 2;
    int y = N - 2;
    wave.clear();
    wave.push_back(pair<int, int>(x, y));
    while (map[x][y] != 0)
    {
        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (map[x][y] - 1 == map[nx][ny])
            {
                x = nx;
                y = ny;
                wave.push_back(pair<int, int>(x, y));
                break;
            }
        }
    }
    display();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(20, 1050 - 480 - 20);
    glutCreateWindow("Sample Algorithm");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0, 480, 480, 0, -1, 1);
    glutDisplayFunc(display);
    glutTimerFunc(10, timer, 0);
    glutMainLoop();
}
