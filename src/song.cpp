#include "song.hpp"

Song::Song()
{
  currentTrack = LoadMusicStream("resources/assets/ARHANT_shine.ogg");
}

void Song::PlaySong()
{
  PlayMusicStream(currentTrack);
}

void Song::UpdateSong()
{
  UpdateMusicStream(currentTrack);
}

float Song::GetSongSeconds()
{
  return GetMusicTimePlayed(currentTrack);
}

int Song::GetSongTick()
{
  float seconds = GetMusicTimePlayed(currentTrack);

  return (int)(seconds / tickTime);
}

bool Song::IsSongPlaying()
{
  return IsMusicStreamPlaying(currentTrack);
}
