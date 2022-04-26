#include "DB.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include <ctype.h>
#pragma warning(disable : 4996)


char* trimString(char* str)
{
	char* end;

	while (isspace((unsigned char)*str)) str++;

	if (*str == 0)
		return str;

	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end)) end--;

	end[1] = '\0';

	return str;
}
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


	//Nacitani vzdalenosti
	int size = temp->pocetMest;
	temp->vzdalenosti = (double**)malloc(size*sizeof(double*));
	for (int i = 0; i < size; i++)
	{
		temp->vzdalenosti[i] = (double*)malloc(size*sizeof(double));
	}
	printf("Hotova alokace\n");

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fscanf(file,"%lf", &temp->vzdalenosti[i][j]);
		}
	}

	printf("Hotovo\n");
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
		/*
		int len = strlen(mesto);
		memcpy(tempMesto, &temp->mesto, len);
		tempMesto[len] = "\0";
		*/
		/*
		printf("databaze: %s\n",trimString(temp->mesto));
		printf("%d\n",strlen(trimString(temp->mesto)));
		printf("zadane: %s\n",mesto);
		printf("%d\n",strlen(mesto));
		*/
		if (strcmp(trimString(temp->mesto),mesto) == 0)
		{
			//printf("NASEL mesto v seznamu - %d.\n",i);
			return i;
		}
		temp = temp->dalsi;
	}
	//printf("Nenasel mesto v seznamu.\n");
	return -1;
}
double DejVzdalenostMeziMesty(tDatabaze* db, char* mesto1, char* mesto2) {
	int index1 = DejIndexMesta(db, mesto1);
	int index2 = DejIndexMesta(db, mesto2);
	if (index1 > -1 && index2 > -1)
	{
		return db->vzdalenosti[index1][index2];
	}
	return 0;
}
double SpocitejDelku(tDatabaze* db, tSeznamMest* seznam) { //Zkontrolovat funk4nost
	if (seznam == NULL)
	{
		printf("Seznam byl NULL\n");
		return 0;
	}
	double vzdalenost = 0;
	tSeznamMest *temp = seznam;
	while (temp->dalsi != NULL)
	{
		//printf("VZdalenost cykl\n");
		vzdalenost = vzdalenost + DejVzdalenostMeziMesty(db,temp->mesto,temp->dalsi->mesto);
		printf("vzdalenost postup - %f\n", vzdalenost);
		temp = temp->dalsi;
	}
	return vzdalenost;
}
void VypisVzdalenostiOdPocatku(tDatabaze* db, tSeznamMest* seznam) { //Zkontrolovat funk4nost
	tSeznamMest* start = seznam;
	tSeznamMest* temp = seznam;
	while (temp->dalsi != NULL)
	{
		printf("%f\n", DejVzdalenostMeziMesty(db, start->mesto, temp->dalsi->mesto));
		temp = temp->dalsi;
	}
}