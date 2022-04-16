#include "SeznamMest.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#pragma warning(disable : 4996)

tSeznamMest* VytvorMesto(char* mesto)
{
	tSeznamMest* temp = malloc(sizeof(tSeznamMest));
	strcpy(temp->mesto, mesto);
	temp->dalsi = NULL;
	return temp;
}

tSeznamMest* PridejNaKonec(tSeznamMest* seznam, tSeznamMest* novy) {
	if (seznam == NULL)
	{
		return novy;
	}
	tSeznamMest* temp = seznam;
	int index = 0;
	while (temp->dalsi != NULL)
	{
		index++;
		temp = temp->dalsi;
	}
	if (!(index > DELKA_MESTA - 1))
	{
		temp->dalsi = novy;
		return seznam;
	}
}

tSeznamMest* PridejNaIndex(tSeznamMest* seznam, int index, tSeznamMest* novy) {
	tSeznamMest* temp = seznam;
	if (seznam == NULL)
	{
		seznam = novy;
		return seznam;
	}
	for (int i = 0; i < index - 1; i++)
	{

	}
	return NULL; //TODO predstiram ze to funguje
}

void VypisSeznam(tSeznamMest* seznam) {
	printf("%s", seznam->mesto);
	tSeznamMest* temp = seznam;
	while (temp->dalsi != NULL)
	{
		temp = temp->dalsi;
		printf("%s", temp->mesto);
	}
}

tSeznamMest* OdeberPrvek(tSeznamMest* seznam, int index) {
	if (seznam == NULL)
	{
		return NULL;
	}
	tSeznamMest* temp = seznam;
	for (int i = 0; i < index-1; i++)
	{
		if (temp->dalsi != NULL)
		{
			temp = temp->dalsi;
		}
		else {
			return NULL;
		}
	}
	free(temp->dalsi);
	temp->dalsi = NULL;
	return seznam;
}

void ZrusSeznam(tSeznamMest* seznam) {
	if (seznam->dalsi != NULL)
	{
		ZrusSeznam(seznam->dalsi);
	}
	seznam = NULL;
	free(seznam);
}