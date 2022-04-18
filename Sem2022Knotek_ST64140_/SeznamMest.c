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
		seznam = &novy;
		return seznam;
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
	for (int i = 0; i < index - 1; i++)
	{
		if (temp->dalsi == NULL)
		{
			return NULL;
		}
		temp = temp->dalsi;
	}
	if (temp->dalsi != NULL)
	{
		if (temp->dalsi->dalsi != NULL)
		{
			novy->dalsi = temp->dalsi->dalsi;
			temp->dalsi = novy;
		}else{
			temp->dalsi = novy;
		}
	}
	else {
		temp->dalsi = novy;
	}
	return seznam;
}

void VypisSeznam(tSeznamMest* seznam) {
	printf("ZacatekVypisu\n");
	if (seznam == NULL)
	{
		return;
	}
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