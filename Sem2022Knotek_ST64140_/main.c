#define _CRTDBG_MAP_ALLOC	
#include<stdio.h>
#include"SeznamMest.h"
#include"DB.h"

void AKAmain()
{
	printf("This is main function\n");
		
		tSeznamMest* mujSeznam = VytvorMesto("Praha");
		PridejNaKonec(mujSeznam, VytvorMesto("Ostrava"));
		PridejNaKonec(mujSeznam, VytvorMesto("Pardubice"));
		VypisSeznam(mujSeznam);
		//OdeberPrvek(mujSeznam,2);
		//VypisSeznam(mujSeznam);
		ZrusSeznam(mujSeznam);
		
		/*
		tSeznamMest* mujSeznam = VytvorMesto("Praha");
		VypisSeznam(mujSeznam);
		ZrusSeznam(mujSeznam);
		free(mujSeznam);
		*/

	//NactiDatabazi("mesta.txt");

	if (_CrtDumpMemoryLeaks() != 0) {
		printf("Nebyla provedena dealokace");
	}
}