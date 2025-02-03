#pragma once

#include <raylib.h>

// CONFIGURABLES
const int screenWidth = 800;
const int screenHeight = 450;
const int frameRate = 30;

const int shieldAreaRadius = 50;

const int bpm = 75;
const float speed = 5;

// CALCULATIONS
const float spawnRadius = 170;

const float beatTime = (float)60 / (float)bpm;
const float tickTime = beatTime / 4;

const float gap = (spawnRadius - shieldAreaRadius) / (speed * frameRate);
const float gapInTicks = gap / tickTime;

const Vector2 screenCenter = {screenWidth / 2, screenHeight / 2};