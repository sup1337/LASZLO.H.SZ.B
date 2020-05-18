#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdbool.h>

void Game();

char** beolvasPalya(const char* fajlNev);

void kirajzolPalya(char** palya);

char** nehezsegiszint(char** palya);


#endif // HEADER_H
