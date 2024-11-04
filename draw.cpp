#include "raylib.h"
#include <iostream>
#include <math.h>

#include "graph.h"
#include "classes.h"
using namespace std;

#define screenWidth 900
#define screenHeight 600
#define TargetFPS 60

int main() {
  char *motherchar = new char[2];
  Graph g;
  g.def();
  int x0 = 150, y0 = 300;
  int i = 0, n=g.get_size();
  int **a=g.get_vertices();
  int **b=g.iBFS(3);
  int **c=g.iDFS(3);

  SetTargetFPS(TargetFPS);
  InitWindow(screenWidth, screenHeight, "Прога");
  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawGraphs(x0, y0, n, motherchar, a, b, c);
    EndDrawing();
  }
  CloseWindow();

  return 0;
}

