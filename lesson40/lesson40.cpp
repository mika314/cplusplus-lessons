// Урок 40
// Обход доски шахматным конем [продолжение]
#include <GL/glut.h>
#include <vector>
#include <map>
using namespace std;

const int N = 80;
bool board[N][N];
struct Position
{
    int x;
    int y;
};
vector<Position> solution;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    const int step = 480 / N;
    glBegin(GL_QUADS);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if ((i + j) % 2)
                glColor3f(0.5, 0.5, 0.5);
            else
                glColor3f(0, 0, 0);
            const int x = i * step;
            const int y = j * step;
            glVertex2f(x, y);
            glVertex2f(x + step, y);
            glVertex2f(x + step, y + step);
            glVertex2f(x, y + step);
        }
    glEnd();
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(0, 1, 0);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j])
            {
                const int x = i * step + step / 2;
                const int y = j * step + step / 2;
                glVertex2f(x, y);
            }
    glEnd();
    glPointSize(1);
    glBegin(GL_LINE_STRIP);
    for (vector<Position>::iterator i = solution.begin(); i != solution.end(); ++i)
    {
        const int x = i -> x * step + step / 2;
        const int y = i -> y * step + step / 2;
        glVertex2f(x, y);
    }
    glEnd();
    glutSwapBuffers();
}

bool solve(int x, int y)
{
    board[x][y] = true;
    Position tmp = { x, y };
    solution.push_back(tmp);
    display();
    if (solution.size() == N * N)
        return true;
    
    /*
      .1.2.
      3...4
      ..x..
      5...6
      .7.8.
     */

    const struct
    {
        int dx;
        int dy;
    } moves[] =
          {
              { -1, -2 },
              { 1, -2 },
              { -2, -1 },
              { 2, -1 },
              { -2, 1 },
              { 2, 1 },
              { -1, 2 },
              { 1, 2 }
          };
    multimap<int, int> seq;
    for (size_t i = 0; i < sizeof(moves) / sizeof(*moves); ++i)
    {
        const int x0 = x + moves[i].dx;
        const int y0 = y + moves[i].dy;
        int c = 0;
        for (size_t j = 0; j < sizeof(moves) / sizeof(*moves); ++j)
        {
            const int x1 = x0 + moves[j].dx;
            const int y1 = y0 + moves[j].dy;
            if (x1 >= 0 && x1 < N &&
                y1 >= 0 && y1 < N &&
                !board[x1][y1])
                ++c;
        }
        seq.insert(pair<int, int>(c, i));
    }
    for (multimap<int, int>::iterator i = seq.begin(); i != seq.end(); ++i)
    {
        const int x0 = x + moves[i -> second].dx;
        const int y0 = y + moves[i -> second].dy;
        if (x0 >= 0 && x0 < N &&
            y0 >= 0 && y0 < N &&
            !board[x0][y0] &&
            solve(x0, y0))
            return true;
    }
    
    board[x][y] = false;
    solution.pop_back();
    return false;
}

void timer(int = 0)
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = false;
    solution.clear();
    
    solve(0, 0);
    display();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(20, 1050 - 480);
    glutCreateWindow("Knight's tour");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (0, 480, 480, 0, -1, 1);
    glutDisplayFunc(display);
    glutTimerFunc(10, timer, 0);
    glutMainLoop();
}
