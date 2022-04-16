#pragma once
#define DELKA_MESTA 60

typedef struct SeznamMest {
	char mesto[DELKA_MESTA];
	struct SeznamMest* dalsi;
} tSeznamMest;

tSeznamMest* VytvorMesto(char* mesto);
tSeznamMest* PridejNaKonec(tSeznamMest* seznam, tSeznamMest* novy);
tSeznamMest* PridejNaIndex(tSeznamMest* seznam, int index, tSeznamMest* novy);
tSeznamMest* OdeberPrvek(tSeznamMest* seznam, int index);
void VypisSeznam(tSeznamMest* seznam);
void ZrusSeznam(tSeznamMest* seznam);