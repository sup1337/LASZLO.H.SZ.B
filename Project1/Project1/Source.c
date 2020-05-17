#include "header.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
char** beolvasPalya(const char* fajlNev);
void kirajzolPalya(char** palya);

int hossz, szel;
int score = 0;


void Game() {



	//printf("score = %i '\n'", score);
	time_t currentTime, startTime;
	startTime = time(NULL);
	int index = 1;
	char** palya;
	srand(time(NULL));
	int RandomPalya = rand() % 3;
	palya = beolvasPalya("be.txt");
	if (RandomPalya == 0){
		palya = beolvasPalya("be.txt");
}
	else if (RandomPalya == 1) {
		palya = beolvasPalya("be1.txt");
	}
	else if (RandomPalya == 2) {
		palya = beolvasPalya("be2.txt");
	}
	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya[jatekosX][jatekosY] = 'P';
	//kirajzolPalya(palya);
	srand(time(NULL));
	int v = rand() % 2;
	while (1) {
		printf("score = %i** \n", score );

		currentTime = time(NULL);
		kirajzolPalya(palya);
		printf("jobb: j\nle: l\n");
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

		if (palya[jatekosX][jatekosY] == 'R') {
			palya[jatekosX][jatekosY] = 'P';
			palya[elozoX][elozoY] = '0';
			score++;
				Game();
		}


		//Sleep(300);
		system("CLS");
		//	/*if (currentTime - startTime > 10) {
		//		printf("Time limit exceeded!\n Game over\n");
		//		break;*/
		//}
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
		char** palya = (char**)(calloc(hossz, sizeof(char*)));
		//ellenorzes
		for (int i = 0; i < hossz; ++i) {
			palya[i] = (char*)(calloc(szel, sizeof(char)));
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
		//srand(time(NULL));
		int v = rand() % 2;
		for (int i = 0; i < hossz; ++i) {
			for (int j = 0; j < szel; ++j) {
				if (palya[i][j] == '3' && (i == 0 || i == hossz - 1)) {
					printf("#");
				}
				else if (palya[i][j] == '3') {
					printf("#");
				}
				if (palya[i][j] == '0') {
					printf(" ");
				}
				if (palya[i][j] == '1') {
					printf("#");
				}
				if (palya[i][j] == 'R') {
					printf("X");
				}
				if (palya[i][j] == 'P') {
					printf("@");
				}
				if (palya[i][j] == '4' && v == 1) {
					printf("#");
				}
				else if (palya[i][j] == '4' && v == 0) {
					printf(" ");
				}
				if (palya[i][j] == '5' && v == 0) {
					printf("#");
				}
				else if (palya[i][j] == '5' && v == 1) {
					printf(" ");
				}

			}
			printf("\n");

		}


		printf("\n");
		system("pause");
	}


