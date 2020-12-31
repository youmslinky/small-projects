#pragma once
#include <cstdint>
#include <cstring>
#include "util.h"

extern char state[8][8];
extern char nextState[8][8];

unsigned neighbors_count(unsigned col, unsigned row);
void calcNextState();
void lifeAnimationCycle();
uint64_t findStillLife();
