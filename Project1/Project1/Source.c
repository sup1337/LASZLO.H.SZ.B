#include "header.h"
#include <stdlib.h>
char** beolvasPalya(const char* fajlNev);
void kirajzolPalya(char** palya);

int hossz, szel;

void Game() {

	int score = 0;
		//printf("score = %i '\n'", score);
	time_t currentTime, startTime;
	startTime = time(NULL);
	int index = 1;
	char** palya;
	palya = beolvasPalya("be.txt");
	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya[jatekosX][jatekosY] = 'P';
	//kirajzolPalya(palya);
	while (1) {
		printf("score = %i \n", score);
		currentTime = time(NULL);
		kirajzolPalya(palya);
		printf("jobb: j\nle: l\n");
		char option = getch();
		elozoX = jatekosX;
		elozoY = jatekosY;
		if (option == 'd') {
			jatekosY++;
		}
		else if (option == 's') {
			jatekosX++;
		}
		else if (option == 'a') {
			jatekosY--;
		}
		else if (option == 'w') {
			jatekosX--;
		}
		
		if (palya[jatekosX][jatekosY] == '0') {
			palya[jatekosX][jatekosY] = 'P';
			palya[elozoX][elozoY] = '0';
			
		}
		if (palya[jatekosX][jatekosY] == '3' || palya[jatekosX][jatekosY] == '1') {
			jatekosX--;
			jatekosY--;
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
			}
			printf("\n");
		}
		system("pause");
	}


