#include "CertificatMed.h"
/*----------------------- fonction qui ecrit un certificat médical -------------------------*/
void CertificatMedical(){
	Cert_Med new_Cert;
	new_Cert=champCertificat();
	new_Cert.dt_cert=date_actuel();
	system("cls");
	printf("\n\t\t    ------------------------CERTIFICAT MEDICAL---------------------------\n");
	printf("\t\t    *********************************************************************\n\n");
	printf("\t\t\tJe soussign%c(e), Dr\t EL Jamali Mohammed  ,Docteur en m%cdecine,\n\n",-126,-126);
	printf("\t\t\tcertifie que l'examen de M:Mme\t %s %s\n\n",new_Cert.Nom_Cert,new_Cert.Prenom_Cert);
	printf("\t\t\tDate de naissance :\t");
	printf("%d/%d/%d",new_Cert.dt_naiss_Cert.jour,new_Cert.dt_naiss_Cert.mois,new_Cert.dt_naiss_Cert.annee);
	printf("\t\tAge :  %d\n\n",new_Cert.Age_Cert);
	printf("\t\t\tne r%cv%cle pas de contre-indication %c la pratique de la cource\n",-126,138,133);
	printf("\t\t\t%c pied conp%ctition.\n\n",133);
	printf("\t\t\tCertificat %ctabli %c : \tMarrakech\n\n",130,133);
	printf("\t\t\tDate : \t %02d/%02d/%02d\n\n",new_Cert.dt_cert.jour,new_Cert.dt_cert.mois,new_Cert.dt_cert.annee);
	printf("\t\t\t\t\t\tSignature du M%cdecin :\n\n",-126);
	printf("\t\t\t\t\t\tTampon du m%cdecin : \n",-126);
	
	/*---------------------------------------------------*/ 
	FILE *FCert;
	FCert=fopen("Cert_Medical\\Certificat_Med.txt","w");
	fprintf(FCert,"\n\t\t    ------------------------CERTIFICAT MEDICAL---------------------------\n");
	fprintf(FCert,"\t\t    *********************************************************************\n\n");
	fprintf(FCert,"\t\t\tJe soussigné(e), Dr\t EL Jamali Mohammed  , Docteur en mécdecine,\n\n");
	fprintf(FCert,"\t\t\tcertifie que l'examen de M:Mme\t %s %s\n\n",new_Cert.Nom_Cert,new_Cert.Prenom_Cert);
	fprintf(FCert,"\t\t\tDate de naissance :\t");
	fprintf(FCert,"%d/%d/%d",new_Cert.dt_naiss_Cert.jour,new_Cert.dt_naiss_Cert.mois,new_Cert.dt_naiss_Cert.annee);
	fprintf(FCert,"\t\tAge :  %d\n\n",new_Cert.Age_Cert);
	fprintf(FCert,"\t\t\tne révèle pas de contre-indication à la pratique de la cource\n");
	fprintf(FCert,"\t\t\tà pied conpétition.\n\n");
	fprintf(FCert,"\t\t\tCertificat établi à : \tMarrakech\n\n");
	fprintf(FCert,"\t\t\tDate : \t %02d/%02d/%02d\n\n",new_Cert.dt_cert.jour,new_Cert.dt_cert.mois,new_Cert.dt_cert.annee);
	fprintf(FCert,"\t\t\t\t\t\tSignature du Médecin :\n\n");
	fprintf(FCert,"\t\t\t\t\t\tTampon du médecin : \n");
	fclose(FCert);
	
	/*------------------pour quitter la page et afficher le menu principal---------------------*/
	int a;
	printf("\n\t1- retour au menu principal  ");
	do { scanf("%d",&a); }  while(a!=1);
	system("cls");  menumain();
}

Cert_Med champCertificat(){
	Cert_Med new_Cert;
	FILE *FCert;
	char aide[20], CIN[12];
	printf("\n\t\tentrer le CIN du patient s'il vous plait :  ");
	scanf("%s",CIN);
	strcpy(aide,CIN);
	char chemin[]="patient\\";
	strcat(chemin,aide);
	strcat(chemin,".txt");
	FCert=fopen(chemin,"r");
	if (FCert==NULL){  
      SetColor(12);printf("\n\t\tdesole !! ce fichier %s n'existe pas.\n",chemin);SetColor(15);
      menumain();
    }
    else{
    	fscanf(FCert,"%s%s%s",new_Cert.Nom_Cert,new_Cert.Prenom_Cert,new_Cert.CIN_cert);
	    fscanf(FCert,"%d%d%d",&new_Cert.dt_naiss_Cert.jour,&new_Cert.dt_naiss_Cert.mois,&new_Cert.dt_naiss_Cert.annee);
	    fscanf(FCert,"%d",&new_Cert.Age_Cert);
	    fclose(FCert);
		return new_Cert;
	}
}
