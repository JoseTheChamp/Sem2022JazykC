#include "DB.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#pragma warning(disable : 4996)



tDatabaze* NactiDatabazi(char* soubor)  //TODO zjistit od n2koho jak nacita 2rozmerne pole
{
	tDatabaze* temp = malloc(sizeof(tDatabaze));
	temp->pocetMest = 0;
	FILE* file;
	char line[DELKA_MESTA] = { 0 }; //TODO know what this inicialization is.
	file = fopen(soubor, "r");
	printf("Otevirani souboru\n");
	if (!file)
	{
		perror(soubor);
		return EXIT_FAILURE;
	}
	printf("nacitani mesta\n");
	while (fgets(line,DELKA_MESTA,file)[0] != '-')
	{
		if (temp->pocetMest == 0)
		{
			temp->seznam = VytvorMesto(line);
			temp->pocetMest = temp->pocetMest + 1;
		}
		else {
			PridejNaKonec(temp->seznam, VytvorMesto(line));
			temp->pocetMest = temp->pocetMest + 1;
		}
	}
	printf("Nacteny mesta\n");
	VypisSeznam(temp->seznam);


	//Nacitani vzdalenosti
	int size = temp->pocetMest;
	temp->vzdalenosti = (double**)malloc(size*sizeof(double*));
	for (int i = 0; i < size; i++)
	{
		temp->vzdalenosti[i] = (double*)malloc(size*sizeof(double));
	}
	printf("Hotova alokace\n");
	char s[6];
	int index = 0;
	char c;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			while ((c =  getc(file)) != '\t')
			{
				s[index++] = c;
			}
			index = 0;
			puts(s);
;			temp->vzdalenosti[i][j] = strtod(s,NULL);
		}
	}
	printf("Hotovo\n");
	printf("%d\n",temp->vzdalenosti[2][2]);
	printf("%d\n", temp->vzdalenosti[3][1]);
	return temp;
}
void ZrusDatabazi(tDatabaze* db) {//Nevi jestli funguje
	for (int i = 0; i < db->pocetMest; i++)
		free(db->vzdalenosti[i]);

	free(db->vzdalenosti);
	free(db);
}
int DejIndexMesta(tDatabaze* db, char* mesto) { //TODO otestovat
	tSeznamMest *temp = db->seznam;
	for (int i = 0; i < db->pocetMest; i++)
	{
		if (strcmp(temp->mesto,mesto))
		{
			return i;
		}
		temp = temp->dalsi;
	}
}
double DejVzdalenostMeziMesty(tDatabaze* db, char* mesto1, char* mesto2) {
	return db->vzdalenosti[DejIndexMesta(db, mesto1)][DejIndexMesta(db, mesto2)];
}
double SpocitejDelku(tDatabaze* db, tSeznamMest* seznam) { //Zkontrolovat funk4nost
	if (seznam == NULL)
	{
		return 0;
	}
	double vzdalenost = 0;
	tSeznamMest *temp = seznam;
	while (temp->dalsi != NULL)
	{
		vzdalenost = vzdalenost + DejVzdalenostMeziMesty(db,temp->mesto,temp->dalsi->mesto);
		temp = temp->dalsi;
	}
	return vzdalenost;
}
void VypisVzdalenostiOdPocatku(tDatabaze* db, tSeznamMest* seznam) { //Zkontrolovat funk4nost
	tSeznamMest* start = seznam;
	tSeznamMest* temp = seznam;
	while (temp->dalsi != NULL)
	{
		printf("%d", DejVzdalenostMeziMesty(db, start, temp->dalsi->mesto));
		temp = temp->dalsi;
	}
}