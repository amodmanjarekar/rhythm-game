#pragma once

#include <raylib.h>

#include "configs.hpp"

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