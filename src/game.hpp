#pragma once

#include <raylib.h>
#include <raymath.h>
#include <vector>

#include "configs.hpp"
#include "directions.hpp"
#include "arrow.hpp"
#include "get_map_arrows.hpp"
#include "song.hpp"

class Game
{
public:
  Game(Song currentSong);
  Vector2 center;
  std::string lastHit;

  void Update();

private:
  Direction shieldFaceDir;
  int gameTick;
  int lastTick;
  std::vector<Arrow *> arrowsAll;
  std::vector<Arrow *> arrowsOnScreen;
  Song song;

  void DrawEnv();
  void DrawShield();
  void UpdateShieldDir();
};