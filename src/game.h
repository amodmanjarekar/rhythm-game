#pragma once

#include <raylib.h>
#include <raymath.h>
#include <vector>

#include "configs.h"
#include "directions.h"
#include "arrow.h"
#include "get_map_arrows.h"
#include "song.h"

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