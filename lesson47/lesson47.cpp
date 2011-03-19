// Урок 47
// Анимация ханойской башни в OpenGL
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

struct State
{
    int n;
    int src;
    int dest;
    int tmp;
    int step;
};

vector<State> stack;
vector<int> rings[3];
int N;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < 3; ++i)
    {
        for (size_t j = 0; j < rings[i].size(); ++j)
        {
            const int RingCenter = i * 852 / 3 + 852 / 3 / 2;
            const int RingRadius = (852 / 3 / 2 - rings[i][j] * 852 / 3 / 2 / N);
            glVertex2f(RingCenter - RingRadius, 480 - j * 20);
            glVertex2f(RingCenter - RingRadius, 480 - j * 20 - 18);
            glVertex2f(RingCenter + RingRadius, 480 - j * 20 - 18);
            glVertex2f(RingCenter + RingRadius, 480 - j * 20);
        }
    }
    glEnd();
    glutSwapBuffers();
}

void timer(int = 0)
{
    if (stack.size() > 0)
    {
        State &state = stack.back();
        switch (state.step)
        {
        case 0:
            if (state.n == 0)
                stack.pop_back();
            else
            {
                ++state.step;
                State newState;
                newState.n = state.n - 1;
                newState.src = state.src;
                newState.dest = state.tmp;
                newState.tmp = state.dest;
                newState.step = 0;
                stack.push_back(newState);
            }
            break;
        case 1:
            cout << state.src << "->" << state.dest << endl;
            rings[state.dest].push_back(*rings[state.src].rbegin());
            rings[state.src].pop_back();
            ++state.step;
            State newState;
            newState.n = state.n - 1;
            newState.src = state.tmp;
            newState.dest = state.dest;
            newState.tmp = state.src;
            newState.step = 0;
            stack.push_back(newState);
            break;
        case 2:
            stack.pop_back();
            break;
        }
        glutPostRedisplay();
        glutTimerFunc(0, timer, 0);
    }
}

void init(int n, int src, int dest, int tmp)
{
    State state;
    state.n = n;
    state.src = src;
    state.dest = dest;
    state.tmp = tmp;
    state.step = 0;
    stack.push_back(state);
    N = n;
    for (int i = 0; i < n; ++i)
        rings[src].push_back(i);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(852, 480);
    glutInitWindowPosition(0, 86);
    glutCreateWindow("Tower");
    glClearColor(0, 0, 0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 852, 480, 0, -1, 1);
    glutDisplayFunc(display);
    
    init(20, 0, 1, 2);
    timer();
    glutMainLoop();
}
