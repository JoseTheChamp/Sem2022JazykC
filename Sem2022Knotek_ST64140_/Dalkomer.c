#define _CRTDBG_MAP_ALLOC	
#include<stdio.h>
#include"SeznamMest.h"
#include"DB.h"
#pragma warning(disable : 4996)

void VypisNabidku() {
	printf("1)Vypis vsechna mesta.\n");
	printf("2)Pridej mesto.\n");
	printf("3)Pridej mesto na index.\n");
	printf("4)Odeber mesto.\n");
	printf("5)Zrus senzam.\n");
	printf("6)Vypis mesta.\n");
	printf("7)Delka cesty.\n");
	printf("8)Dilci vzdalenosti.\n");
	printf("9)Konec.\n");
}

void main() {
	char operace = 'n';
	int pokracovat = 1;
	tSeznamMest* seznamMest = NULL;
	tDatabaze* databaze = NactiDatabazi("mesta.txt");

	while (pokracovat)
	{
		printf("--------------------------------\n");
		if (seznamMest == NULL)
		{
			printf("JN\n");
		}
		else {
			printf("NN\n");
		}
		VypisNabidku();
		scanf(" %c", &operace);
		printf("--------------------------------\n");
		char nazev[DELKA_MESTA];
		int index = 0;
		switch (operace)
		{
		case '1':
			printf("Tyto mesta jsou v databazi: \n");
			VypisSeznam(databaze->seznam);
			break;
		case '2':
			printf("Zadej jmeno mesta(max %d):\n", DELKA_MESTA);
			scanf("%s", &nazev);
			if (seznamMest == NULL)
			{
				seznamMest = VytvorMesto(nazev);
			}
			else {
				PridejNaKonec(seznamMest, VytvorMesto(nazev));
			}
			break;
		case '3':
			printf("Zadej jmeno mesta(max %d):\n", DELKA_MESTA);
			scanf("%s", &nazev);
			printf("Zadej index na ktery chces mesto vlozit: \n");
			scanf("%d", index);
			PridejNaIndex(seznamMest, index, VytvorMesto(nazev));
			break;
		case '4':
			printf("Zadej odebirany index: \n");
			scanf("%d", index);
			OdeberPrvek(seznamMest, index);
			break;
		case '5':
			printf("Seznam byl zrusen: \n");
			ZrusSeznam(seznamMest);
			break;
		case '6':
			printf("V seznamu jsou tyto mesta: \n");
			VypisSeznam(seznamMest);
			break;
		case '7':
			printf("Zobrazeni delky cesty: \n");
			printf("%f",SpocitejDelku(databaze, seznamMest));
			break;
		case '8':
			printf("Zobrazeni dilcich vzdalenosti: \n");
			VypisVzdalenostiOdPocatku(databaze, seznamMest);
			break;
		case '9':
			pokracovat = 0;
			break;
		case 'v':
			for (int i = 0; i < databaze->pocetMest; i++)
			{
				for (int j = 0; j < databaze->pocetMest; j++)
				{
					printf("%f ", databaze->vzdalenosti[i][j]);
				}
				printf("\n");
			}
			break;
		default:
			printf("Tato operace neni na vyber!!\n");
			break;
		}
	}
}







/*

void main()
{
	MainLoop();
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

void VypisVsechnaMesta(tDatabaze* databaze) {
	printf("Tyto města jsou v databázi: \n");

}

void PridejMesto(tSeznamMest* seznamMest) {
	printf("Zadej jmeno města(max %d):\n", DELKA_MESTA);
	char nazev[DELKA_MESTA];
	scanf("%s", nazev); //nekolirat pouzite & ale nevim jestli tam ma byt
	PridejNaKonec(seznamMest, VytvorMesto(nazev));
}

void PridejMestoNaIndex(tSeznamMest* seznamMest) { //TOD az bude fungovat


}

void OdeberMesto(tSeznamMest* seznamMest) {
	printf("Zadej odebíraný index: \n");
	int index = 0;
	scanf("%d", index);
	OdeberMesto(seznamMest, index);
}

void ZrusSeznamDalkomer(tSeznamMest* seznamMest) {
	printf("Seznam byl zrušen: \n");
	ZrusSeznam(seznamMest);
}

void VypisMesta(tSeznamMest* seznamMest) {
	printf("V seznamu jsou tyto města: \n");
	VypisSeznam(seznamMest);
}

void DelkaCesty(tSeznamMest* seznamMest, tDatabaze* databaze) {
	printf("Zobrazení délky cesty: \n");
	DelkaCesty(databaze, seznamMest);
}

void DilciVzdalenosti(tSeznamMest* seznamMest, tDatabaze* databaze) {
	printf("obrazení dílčích vzdáleností: \n");
	DilciVzdalenosti(databaze, seznamMest);
}

void MainLoop() {
	char operace;
	int pokracovat = 1;
	tSeznamMest* seznamMest = NULL;
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
			ZrusSeznamDalkomer(seznamMest);
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
*/