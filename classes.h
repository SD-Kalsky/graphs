#include "raylib.h"
#include <iostream>
#include <math.h>
using namespace std;

void makeVertice(int x0, int y0, int x, int y, char *c);
char *toChar(char *t, int n);
void makeVertices(int x0, int y0, int n, char *c);
void makeLine(int x0, int y0, int n, int a, int b);
void makeLines(int x0, int y0, int n, int **a);
void makeConnections(int x0, int y0, int n, int **a);

void makeVertice(int x, int y, char *c) {

  DrawText(c, x - 2, y - 18, 14, BLACK);
  DrawCircle(x, y, 5, MAROON);
}

void makeVertices(int x0, int y0, int n, char *motherchar) {
  int i = 0;
  while (i < n) {
    makeVertice(x0 + sin(6.28 / n * i) * 100, y0 + cos(6.28 / n * i) * 100,
                toChar(motherchar, i));
    i++;
  }
}
void makeLine(int x0, int y0, int n, int a, int b) {
  int i = 0;
  DrawLine(x0 + sin(6.28 / n * a) * 100, y0 + cos(6.28 / n * a) * 100,
        x0 + sin(6.28 / n * b) * 100, y0 + cos(6.28 / n * b) * 100, BLACK);

}

void makeLines(int x0, int y0, int n, int **a) {
  int i = 0;
  while (i < n-1) {
    makeLine(x0, y0, n,a[i][0],a[i][1]);
    i++;
  }
}


void makeConnections(int x0, int y0, int n, int **a) {
  int i = 0, j;
  while (i < n) {
    j=1;
  while (j < a[i][0]) {
    DrawLine(x0 + sin(6.28 / n * i) * 100, y0 + cos(6.28 / n * i) * 100,
      x0 + sin(6.28 / n * a[i][j]) * 100, y0 + cos(6.28 / n * a[i][j]) * 100, BLACK);
      j++;
  }
  i++;
  }
}

char *toChar(char *c, int n) {
  c[0] = '0';
  if (n >= 0 and n < 10) {
    c[0] = 48 + n;
    c[1] = ' ';
  } else if (n > 9 and n < 100) {
    c[0] = 48 + n / 10;
    c[1] = 48 + n % 10;
  }
  return c;
}

void drawGraphs(int x0, int y0, int n, char* motherchar, int** a, int** b, int** c)
{
    makeVertices(x0, y0, n, motherchar);
    makeConnections(x0, y0, n, a);
    makeVertices(x0+300, y0, n, motherchar);
    makeLines(x0+300, y0, n, b);
    makeVertices(x0+600, y0, n, motherchar);
    makeLines(x0+600, y0, n, c);
}