#include "Header.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
char** beolvasPalya(const char* fajlNev);
void kirajzolPalya(char** palya);

int hossz, szel;
int score = 0;

char** nehezsegiszint(palya) {
	int elozoX, elozoY;
	srand(time(NULL));
	int RandomPalya = rand() % 3;
	printf("Chose Dificulty : \n e = easy \n n = normal \n h = hard \n");
	char option = getch();
	if (option == 'e') {
		switch (RandomPalya) {
		case 0: palya = beolvasPalya("e1.txt");
			break;
		case 1: palya = beolvasPalya("e2.txt");
			break;
		case 2: palya = beolvasPalya("e3.txt");
			break;
		}
	}
	else if (option == 'n') {
		switch (RandomPalya) {
		case 0: palya = beolvasPalya("be.txt");
			break;
		case 1: palya = beolvasPalya("be1.txt");
			break;
		case 2: palya = beolvasPalya("be2.txt");
			break;
		}
	}
	else if (option == 'h') {
		switch (RandomPalya) {
		case 0: palya = beolvasPalya("h1.txt");
			break;
		case 1: palya = beolvasPalya("h2.txt");
			break;
		case 2: palya = beolvasPalya("h3.txt");
			break;
		}
	}
	return palya;
}

void Game() {
	int index = 1;
	//A maximalis palyameret megadasa 
	char** palya = (char**)(calloc(100, sizeof(char*)));
	for (int i = 0; i < 100; ++i) {
		palya[i] = (char*)(calloc(100, sizeof(char)));
	}
	palya = nehezsegiszint(palya);

	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya[jatekosX][jatekosY] = 'P';
	srand(time(NULL));
	int v = rand() % 2;
	while (1) {
		//Pont Kijelzo 
		printf("\033[0;31m");
		printf("Money = %i$ \n", score);
		printf("\033[0m");
		kirajzolPalya(palya);
		printf("Press W , A , S , D For move character");
		char option = getch();
		elozoX = jatekosX;
		elozoY = jatekosY;

		if (option == 'd') {
			jatekosY++;
			if (palya[jatekosX][jatekosY] == '3' || palya[jatekosX][jatekosY] == '1') {
				jatekosY--;
			}

		}
		else if (option == 's') {
			jatekosX++;
			if (palya[jatekosX][jatekosY] == '3' || palya[jatekosX][jatekosY] == '1') {
				jatekosX--;
			}
		}
		else if (option == 'a') {
			jatekosY--;
			if (palya[jatekosX][jatekosY] == '3' || palya[jatekosX][jatekosY] == '1') {
				jatekosY++;
			}
		}
		else if (option == 'w') {
			jatekosX--;
			if (palya[jatekosX][jatekosY] == '3' || palya[jatekosX][jatekosY] == '1') {
				jatekosX++;
			}
		}

		if (palya[jatekosX][jatekosY] == '0') {
			palya[jatekosX][jatekosY] = 'P';
			palya[elozoX][elozoY] = '0';

		}
		//Hozzaad a pontokhoz
		if (palya[jatekosX][jatekosY] == 'R') {
			palya[jatekosX][jatekosY] = 'P';
			palya[elozoX][elozoY] = '0';
			score++;
			Game();
		}
		system("CLS");

	}
}

char** beolvasPalya(const char* fajlNev)
{
	FILE* fin = fopen(fajlNev, "rt");
	if (!fin) {
		printf("Sikertelen");
		exit(1);
	}
	fscanf(fin, "%i%i\n", &hossz, &szel);
	char** palya = (char**)(calloc(100, sizeof(char*)));
	for (int i = 0; i < 100; ++i) {
		palya[i] = (char*)(calloc(100, sizeof(char)));
	}
	for (int i = 0; i < hossz; ++i) {
		for (int j = 0; j < szel; ++j) {
			fscanf(fin, "%c\n", &palya[i][j]);
		}
	}
	return palya;
}

void kirajzolPalya(char** palya)
{
	//Szinekkel
	int v = rand() % 2;
	for (int i = 0; i < hossz; ++i) {
		for (int j = 0; j < szel; ++j) {
			if (palya[i][j] == '3') {
				printf("\033[0;32m");
				printf("%c", 219);
				printf("\033[0m");
			}
			if (palya[i][j] == '0') {
				printf(" ");
			}
			if (palya[i][j] == 'R') {
				printf("\033[0;36m");
				printf("$");
				printf("\033[0m");
			}
			if (palya[i][j] == 'P') {
				printf("\033[0;33m");
				printf("%c", 254);
				printf("\033[0m");
			}
		}
		printf("\n");
	}
	printf("\n");
}


