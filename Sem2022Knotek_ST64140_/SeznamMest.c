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
	printf("Zacatek pridani");
	tSeznamMest *temp = seznam;
	int i = 0;
	printf("Pred cyklem");
	while (temp->dalsi != NULL && i < index-1) {
		printf("%d - skok\n",i);
		i = i + 1;
		temp = temp->dalsi;
	}
	printf("Po cyklu");
	if (temp->dalsi != NULL)
	{
		if (temp->dalsi->dalsi != NULL)
		{
			printf("%d index - ma 2 nasledniky\n");
			tSeznamMest *naslednik = temp->dalsi->dalsi;
			ZrusSeznam(temp->dalsi);
			temp->dalsi = novy;
			novy->dalsi = naslednik;
		}
		else {
			printf("%d index - ma 1 nasledniky\n");
			ZrusSeznam(temp->dalsi);
			temp->dalsi = novy;
		}
	}
	else {
		printf("%d index - nema nasledniky\n");
		temp->dalsi = novy;
	}


}

void VypisSeznam(tSeznamMest* seznam) {
	printf("ZacatekVypisu\n");
	if (seznam == NULL)
	{
		return;
	}
	printf("%s\n", seznam->mesto);
	tSeznamMest* temp = seznam;
	while (temp->dalsi != NULL)
	{
		temp = temp->dalsi;
		printf("%s\n", temp->mesto);
	}
}

tSeznamMest* OdeberPrvek(tSeznamMest* seznam, int index) {
	if (seznam == NULL)
	{
		return NULL;
	}
	if (seznam->dalsi == NULL)
	{
		free(seznam);
		seznam = NULL;
		return NULL;
	}
	tSeznamMest* temp = seznam;
	for (int i = 0; i < index-1; i++)
	{
		if (temp->dalsi != NULL)
		{
			temp = temp->dalsi;
		}else {
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