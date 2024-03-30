#pragma once
#ifndef _NORMAL_H_
#define _NORMAL_H_

#include "Struct.h"
#include "Console.h"
#include "NormalCheck.h"
#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

#include "Struct.cpp"
#include "Console.cpp"
#include "NormalCheck.cpp"
// #include "Menu.cpp"

// #include "Normal.cpp"

void initBoard(Normal**&);
void deleteBoard(Normal**);
void renderBoard(Normal**);
void normalMode(Player&);
#endif