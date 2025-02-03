#pragma once

#include <raylib.h>

#include "configs.h"

class Song
{
public:
  Song();

  void PlaySong();
  void UpdateSong();
  float GetSongSeconds();
  int GetSongTick();
  bool IsSongPlaying();

private:
  Music currentTrack;
};