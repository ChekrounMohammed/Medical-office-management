#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include "Menumain.h"
#include "patient.h"
#ifndef RDV_H_INCLUDED
#define RDV_H_INCLUDED

//char fichRDV[]="fichierDesRDV.txt";

typedef struct{
	int Hr;
	int Mn;
}heure;
heure hr_RDV;

date dt_RDV;

typedef struct{
	char Nom_patient[20];
	char Prenom_patient[20];
	char CIN_patient[13];
	date dt_RDV;
	heure Hr_RDV;
	char commentaire[50];
}RDV;


void menuRDV();
void ajouterRDV(heure hr_RDV,date dt_RDV);
void modifierRDV();
void supprimerRDV();
void affichierRDV();
void afficherListRDV();
date date_actuel();
void mis_a_jourRDV();
#endif
