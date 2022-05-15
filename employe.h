#ifndef SOMETHING_H
#define SOMETHING_H
#include"patient.h"
#include<conio.h>
#include "Menumain.h"
typedef struct{
	char Nom[20];
	char Prenom[20];
	char CIN[10];
	char sex[5];
	date dt_naiss;
	int Age;
	char st_familiale[20];
	char telephone[11];
	Adress adresse;
	char Email[50];
	int salaire;
}employe;
void MenuEmploye();
void AjouterEmploye();
void Modifieremploye();
void supprimemploye();
void Afficheremploye();
void demandercongee();

#endif
