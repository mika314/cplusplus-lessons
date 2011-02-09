#include <iostream>
#include <cmath>
using namespace std;

float dist2(float v, float a)
{
  return v * v * sin(2 * a * M_PI / 180) / 9.81;
}

float dist(float v, float a)
{
  float x = 0;
  float y = 0;
  float vx = v * cos(a * M_PI / 180);
  float vy = v * sin(a * M_PI / 180);
  float dt = 0.0001;
  while (y >= 0)
  {
    x += vx * dt;
    y += vy * dt;
    vy -= 9.81 * dt;
  }
  return x;
}

int main()
{
  cout << dist(10, 45) << endl;
  cout << dist2(10, 45) << endl;
}
