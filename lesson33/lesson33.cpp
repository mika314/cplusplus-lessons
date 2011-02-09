// Урок 33
// Моделирование сил притажения
#include <GL/glut.h>
#include <cmath>

struct Particle
{
  float x;
  float y;
  float vx;
  float vy;
  float m;
};

const int N = 4;

Particle particles[N];

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
  for (int i = 0; i < N; ++i)
    glVertex2f(particles[i].x, particles[i].y);
  glEnd();
    
  glutSwapBuffers();
}

void timer(int = 0)
{
  for (int i = 0; i < N; ++i)
  {
    Particle &p0 = particles[i];
    for (int j = 0; j < N; ++j)
    {
      if (j == i)
	continue;
      const Particle &p = particles[j];
      float d = sqrt((p0.x - p.x) * (p0.x - p.x) +
		     (p0.y - p.y) * (p0.y - p.y));
      if (d > 3)
      {
	p0.vx += 0.0007 * p.m / d / d * (p.x - p0.x) / d;
	p0.vy += 0.0007 * p.m / d / d * (p.y - p0.y) / d;
      }
    }
    p0.x += p0.vx;
    p0.y += p0.vy;
  }
  display();
  glutTimerFunc(1, timer, 0);
}

int main(int argc, char **argv)
{
  particles[0].x = 100;
  particles[0].y = 100;
  particles[0].vx = 0;
  particles[0].vy = 0;
  particles[0].m = 1000;

  particles[1].x = 130;
  particles[1].y = 100;
  particles[1].vx = 0;
  particles[1].vy = -0.1;
  particles[1].m = 7;

  particles[2].x = 30;
  particles[2].y = 100;
  particles[2].vx = 0;
  particles[2].vy = 0.1;
  particles[2].m = 10;

  particles[3].x = 25;
  particles[3].y = 100;
  particles[3].vx = 0;
  particles[3].vy = 0.11;
  particles[3].m = 0.1;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(200, 200);
  glutInitWindowPosition(20, 810);
  glutCreateWindow("Gravitation");
  glClearColor(0, 0, 0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 200, 200, 0, -1, 1);
  glutDisplayFunc(display);
  timer();
  glutMainLoop();
}
