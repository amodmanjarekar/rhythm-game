#include <raylib.h>

#include "configs.h"
#include "game.h"
#include "directions.h"
#include "song.h"

int main()
{
  InitWindow(screenWidth, screenHeight, "Rhythm");
  SetTargetFPS(frameRate);

  InitAudioDevice();

  Song song = Song();
  Game game = Game(song);

  song.PlaySong();

  while (!WindowShouldClose())
  {
    if (song.IsSongPlaying())
      song.UpdateSong();

    BeginDrawing();

    ClearBackground(WHITE);

    game.Update();

    DrawText(game.lastHit.c_str(), 10, 10, 30, BLACK);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}