#pragma once

#include <string>
#include <iostream>

#include "components/speaker.hpp"

int ReadInt();

int ReadNumberInRange( int from, int to );

bool ReadYesNo();

SoundState ReadSoundState();

double ReadDouble();
