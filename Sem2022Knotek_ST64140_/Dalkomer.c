#define _CRTDBG_MAP_ALLOC	
#include<stdio.h>
#include"SeznamMest.h"
#include"DB.h"

void AKAmain()
{

}

void VypisNabidku() {
	printf("1)Vypiš všechna města.\n");
	printf("2)Přidej město.\n");
	printf("3)Přidej město na index.\n");
	printf("4)Odeber město.\n");
	printf("5)Zruš senzam.\n");
	printf("6)Vypiš města.\n");
	printf("7)Délka cesty.\n");
	printf("8)Dílčí vzdálenosti.\n");
	printf("9)Konec.\n");
}
void MainLoop() {
	char operace;
	int pokracovat = 1;
	tSeznamMest* seznamMest;
	tDatabaze* databaze = NactiDatabazi("mesta.txt");

	while (pokracovat)
	{
		printf("--------------------------------");
		VypisNabidku();
		operace = scanf("%c", &operace);
		printf("--------------------------------");
		switch (operace)
		{
		case '1':
			VypisVsechnaMesta(databaze);
			break;
		case '2':
			PridejMesto(seznamMest);
			break;
		case '3':
			PridejMestoNaIndex(seznamMest);
			break;
		case '4':
			OdeberMesto(seznamMest);
			break;
		case '5':
			ZrusSeznam(seznamMest);
			break;
		case '6':
			VypisMesta(seznamMest);
			break;
		case '7':
			DelkaCesty(seznamMest,databaze);
			break;
		case '8':
			DilciVzdalenosti(seznamMest,databaze);
			break;
		case '9':
			pokracovat = 0;
			break;
		default:
			printf("Tato operace není na výběr!!");
			break;
		}
	}
}

void VypisVsechnaMesta(tDatabaze *databaze) {

}

void PridejMesto(tSeznamMest *seznamMest) {
	printf("Zadej jmeno města(max %d):\n",DELKA_MESTA);
	char nazev[DELKA_MESTA];
	scanf("%s", nazev); //nekolirat pouzite & ale nevim jestli tam ma byt
	PridejNaKonec(seznamMest,VytvorMesto(nazev));
}

void PridejMestoNaIndex(tSeznamMest* seznamMest) { //TOD az bude fungovat

}

void OdeberMesto(tSeznamMest* seznamMest) {
	printf("Zadej odebíraný index: \n");
	int index;
	scanf("%d", index);
	OdeberMesto(seznamMest, index);
}

void ZrusSeznam(tSeznamMest* seznamMest) {
	ZrusSeznam(seznamMest);
}

void VypisMesta(tSeznamMest* seznamMest) {
	VypisSeznam(seznamMest);
}

void DelkaCesty(tSeznamMest* seznamMest,tDatabaze *databaze){
	DelkaCesty(databaze,seznamMest);
}

void DilciVzdalenosti(tSeznamMest *seznamMest, tDatabaze* databaze) {
	DilciVzdalenosti(databaze,seznamMest);
}