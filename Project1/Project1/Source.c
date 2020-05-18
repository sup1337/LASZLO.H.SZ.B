#include "header.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
char** beolvasPalya(const char* fajlNev);
void kirajzolPalya(char** palya);

int hossz, szel;
int score = 0;

void nehezsegiszint(palya) {
	srand(time(NULL));
	printf("Chose Dificulty : \n e = easy \n n = normal \h = hard");
	char option = getch();
	if (option == 'e') {
		int RandomPalya = rand() % 3;
		switch (RandomPalya) {
		case 0: palya = beolvasPalya("e1.txt");
		case 1: palya = beolvasPalya("e2.txt");
		case 2: palya = beolvasPalya("e3.txt");
		}
	}
	else if (option == 'n') {
		int RandomPalya = rand() % 3;
		switch (RandomPalya) {
		case 0: palya = beolvasPalya("be.txt");
		case 1: palya = beolvasPalya("be1.txt");
		case 2: palya = beolvasPalya("be2.txt");
		}
	}
	else if (option == 'h') {
		int RandomPalya = rand() % 3;
		switch (RandomPalya) {
		case 0: palya = beolvasPalya("h1.txt");
		case 1: palya = beolvasPalya("h2.txt");
		case 2: palya = beolvasPalya("h3.txt");
		}
	}
}

void Game() {



	//printf("score = %i '\n'", score);
	time_t currentTime, startTime;
	startTime = time(NULL);
	int index = 1;
	char** palya;
	srand(time(NULL));
	//palya kivalasztasa
	void nehezsegiszint(palya);
	int elozoX, elozoY;
	int jatekosX = 1, jatekosY = 1;
	palya[jatekosX][jatekosY] = 'P';
	srand(time(NULL));
	int v = rand() % 2;
	while (1) {
		//pont kijelzo 
		printf("\033[0;31m");
		printf("Money = %i$ \n", score);	
		printf("\033[0m");

		currentTime = time(NULL);
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
		//hozzaad a pontokhoz
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
		//Szinekkel
		int v = rand() % 2;
		for (int i = 0; i < hossz; ++i) {
			for (int j = 0; j < szel; ++j) {
				if (palya[i][j] == '3' && (i == 0 || i == hossz - 1)) {
					printf("\033[0;32m");
					printf("%c", 219);
					printf("\033[0m");
				}
				else if (palya[i][j] == '3') {
					printf("\033[0;32m");
					printf("%c",219);
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
		system("pause");
	}
	

