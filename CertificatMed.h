#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CERTIFICATMED_H_INCLUDED
#define CERTIFICATMED_H_INCLUDED

#include"rdv.h"
#include"patient.h"
#include "Menumain.h"

typedef struct{
	char Nom_Cert[20];
	char Prenom_Cert[20];
	char CIN_cert[12];
	date dt_naiss_Cert;
	int Age_Cert;
	date dt_cert;
}Cert_Med;

Cert_Med champCertificat();
void CertificatMedical();

#endif
