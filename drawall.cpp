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


    SetConfigFlags(FLAG_MSAA_4X_HINT);  // NOTE: Try to enable MSAA 4X
    InitWindow(screenWidth, screenHeight, "raylib [audio] example - module playing (streaming)");
    InitAudioDevice();
    Music music = LoadMusicStream("resources/summer.mp3");
    music.looping = false;
    float pitch = 1.0f;
    PlayMusicStream(music);
    float timePlayed = 0.0f;
    bool pause = false;

  SetTargetFPS(TargetFPS);
  InitWindow(screenWidth, screenHeight, "Прога");
  while (!WindowShouldClose()) {
    UpdateMusicStream(music);  
        if (IsKeyPressed(KEY_SPACE))
        {
            StopMusicStream(music);
            PlayMusicStream(music);
            pause = false;
        }
        if (IsKeyPressed(KEY_P))
        {
            pause = !pause;

            if (pause) PauseMusicStream(music);
            else ResumeMusicStream(music);
        }
        if (IsKeyDown(KEY_DOWN)) pitch -= 0.01f;
        else if (IsKeyDown(KEY_UP)) pitch += 0.01f;
        SetMusicPitch(music, pitch);
        timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music)*(screenWidth - 40);


    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawGraphs(x0, y0, n, motherchar, a, b, c);

    DrawRectangle(20, screenHeight - 20 - 12, screenWidth - 40, 12, LIGHTGRAY);
    DrawRectangle(20, screenHeight - 20 - 12, (int)timePlayed, 12, MAROON);
    DrawRectangleLines(20, screenHeight - 20 - 12, screenWidth - 40, 12, GRAY);
    DrawRectangle(10, 10, 225, 75, WHITE);
    DrawRectangleLines(10, 10, 225, 75, GRAY);
    DrawText("PRESS SPACE TO RESTART MUSIC", 20, 20, 10, BLACK);
    DrawText("PRESS P TO PAUSE/RESUME", 20, 35, 10, BLACK);
    DrawText("PRESS UP/DOWN TO CHANGE SPEED", 20, 50, 10, BLACK);
    DrawText(TextFormat("SPEED: %f", pitch), 20, 65, 10, MAROON);

    EndDrawing();
  }
  CloseWindow();

UnloadMusicStream(music); 
CloseAudioDevice();
  return 0;
}