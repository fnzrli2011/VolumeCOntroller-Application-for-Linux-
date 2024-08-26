#include <cstdio>
#include <raylib.h>
#include <cstdlib>

using namespace std;

int main (int argc, char *argv[]) {
  const int width = 500;
  const int height = 200;
  
  InitWindow(width,height,"Volume");

  float volume = 0.5f;
  char command[64];
  char volumeText[64];
  SetTargetFPS(60);
  while(!WindowShouldClose()){
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
      volume = (float)GetMouseX() / width;
      snprintf(command, sizeof(command), "pactl set-sink-volume @DEFAULT_SINK@ %d%%", (int)(volume * 100));
      system(command);
    }
    snprintf(volumeText, sizeof(volumeText), "%d%%", (int)(volume * 100));


    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangle(50, 100, width - 100, 30,LIGHTGRAY);
    DrawRectangle(50, 100, (int)((width - 100) * volume), 30, MAROON);
    DrawText(volumeText, width - 80, 140, 20, BLACK);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
