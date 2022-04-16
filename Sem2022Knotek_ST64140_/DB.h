#include "SeznamMest.h"

typedef struct {
	int pocetMest;
	tSeznamMest* seznam;
	double** vzdalenosti;
} tDatabaze;


tDatabaze* NactiDatabazi(char* soubor);
void ZrusDatabazi(tDatabaze* db);
int DejIndexMesta(tDatabaze* db, char* mesto);
double DejVzdalenostMeziMesty(tDatabaze* db, char* mesto1, char* mesto2);
double SpocitejDelku(tDatabaze* db, tSeznamMest* seznam);
void VypisVzdalenostiOdPocatku(tDatabaze* db, tSeznamMest* seznam);