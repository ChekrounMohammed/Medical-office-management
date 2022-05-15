#include"rdv.h"
#include"patient.h"


/*------------------------menu pour la gestion des RDV--------------------------------*/
void menuRDV(){

	int choixRDV;
	SetColor(11);
	printf("\n\t\t------------------------Gestion des Rendez-Vous-------------------------\n");
	printf("\t\t************************************************************************\n\n");
	printf("\t\t\t\t\t  1- Ajouter RDV\n\n");
	printf("\t\t\t\t\t  2- Modifier RDV\n\n");
	printf("\t\t\t\t\t  3- Supprimer RDV\n\n");
	printf("\t\t\t\t\t  4- Afficher un RDV\n\n");
	printf("\t\t\t\t\t  5- Affichier la liste des RDV\n\n");
	printf("\t\t\t\t\t  6- mis-a-jour des RDV\n\n");
	printf("\t\t\t\t\t  7- retour au menu precendent\n\n"); 
	printf("\n\n");
	do{
		printf("\t\t veuillez entrer votre choix :  ");
		scanf("%d",&choixRDV);
		SetColor(15);
		printf("\n\n");
		switch(choixRDV){
			case 1:system("cls");ajouterRDV(hr_RDV,dt_RDV);break;
			case 2:system("cls");modifierRDV();break;
			case 3:system("cls");supprimerRDV();break;
			case 4:system("cls");affichierRDV();break;
			case 5:system("cls");afficherListRDV();break;
			case 6:system("cls");mis_a_jourRDV();break;
			case 7:system("cls");menumain();break;
			default:
				system("cls");
				SetColor(12);printf("\t\tdesole !!\t vous avez entrer le mauvais choix\n");SetColor(15);break;
		}
	}while(choixRDV<1 || choixRDV>7);
}


/*-------------------------fonction qui ajoute un rendez-vous-------------------------*/
void ajouterRDV(heure hr_RDV,date dt_RDV){
	RDV newRDV;
	FILE *dt_hr;
	dt_hr=fopen("repRDV\\dt_hr_dernierRDV.txt","r");
	if(dt_hr==NULL){  
      SetColor(12);printf("\n\t\tdesole !! fichier repRDV\\dt_hr_dernierRDV.txt n'existe pas.\n");SetColor(15);
      menumain();
    }
    else{
    	fscanf(dt_hr,"%02d%02d%4d",&newRDV.dt_RDV.jour,&newRDV.dt_RDV.mois,&newRDV.dt_RDV.annee);
    	fscanf(dt_hr,"%02d%02d",&newRDV.Hr_RDV.Hr,&newRDV.Hr_RDV.Mn);
    	fclose(dt_hr);
	}
	printf("\n\t\tentrer le CIN du patient :  ");
	scanf("%s",newRDV.CIN_patient);
/*------------------tester si le fichier de ce patient existe ou pas------------------*/
	FILE *FRDV,*FP;
	char aide[12];
	strcpy(aide,newRDV.CIN_patient);
	char chemin[]="patient\\";
	strcat(chemin,aide);
	strcat(chemin,".txt");
	FP=fopen(chemin,"r");
	if (FP==NULL){  
      SetColor(12);printf("\n\t\tdesole !! ce fichier %s n'existe pas.\n",chemin);SetColor(15);
      printf("\n\t\tveuillez ajouter ce patient\n");
    }
    else{
    	printf("\n\t\tcommentaire : ");
    	scanf("%s",newRDV.commentaire);
    	fscanf(FP,"%s%s",newRDV.Nom_patient,newRDV.Prenom_patient);
    	FRDV=fopen("repRDV\\fichierDesRDV.txt","a");
    	fprintf(FRDV,"%-15s%-15s%-10s\t",newRDV.Nom_patient,newRDV.Prenom_patient,newRDV.CIN_patient);
    	fprintf(FRDV,"%02d %02d %02d\t",newRDV.dt_RDV.jour,newRDV.dt_RDV.mois,newRDV.dt_RDV.annee);
    	fprintf(FRDV,"%02d %02d\t%-15s\n",newRDV.Hr_RDV.Hr,newRDV.Hr_RDV.Mn,newRDV.commentaire);
    	fclose(FP);
		fclose(FRDV);
    	if(newRDV.Hr_RDV.Hr<16) newRDV.Hr_RDV.Hr++;
    	else{
    		int mth,jj;
    		newRDV.Hr_RDV.Hr=9;        
			newRDV.Hr_RDV.Mn=0;
    		mth=newRDV.dt_RDV.mois;
    		jj=newRDV.dt_RDV.jour;
    		if(mth==2 && jj==29){
    			newRDV.dt_RDV.mois++;
    			newRDV.dt_RDV.jour=1;
			}
			else if((mth==1 || mth==3 || mth==5 || mth==7 || mth==8 || mth==10) && jj==31){
				newRDV.dt_RDV.mois++;
				newRDV.dt_RDV.jour=1;
			}
			else if(mth==12 && jj==31){
				newRDV.dt_RDV.mois=1;
				newRDV.dt_RDV.jour=1;
				newRDV.dt_RDV.annee++;
			}
			else if((mth==4 || mth==6 || mth==9 || mth==11) && jj==30){
				newRDV.dt_RDV.mois++;
				newRDV.dt_RDV.jour=1;
			}
			else newRDV.dt_RDV.jour++;
		}
		dt_hr=fopen("repRDV\\dt_hr_dernierRDV.txt","w");
		fprintf(dt_hr,"%02d %02d %4d\n",newRDV.dt_RDV.jour,newRDV.dt_RDV.mois,newRDV.dt_RDV.annee);
		fprintf(dt_hr,"%02d %02d",newRDV.Hr_RDV.Hr,newRDV.Hr_RDV.Mn);
		fclose(dt_hr);
		SetColor(10);printf("\n\t\tLe rendez-vous est bien ajout%c\n",-126);SetColor(15);
	}
	int a;
	printf("\n\t1- retour au menu pr%ccedent  ",-126);
	do { scanf("%d",&a); }  while(a!=1);
	system("cls"); menuRDV();
}


/*----------------------fonction qui supprime un rendez-vous--------------------------*/
void supprimerRDV(){
	RDV delateRDV;
	char CIN[15]="",oldCIN[15]="";
	FILE *FRDV,*aide;
	printf("\t\tvotre CIN s'il vous plait :  ");
	scanf("%s",CIN);
	FRDV=fopen("repRDV\\fichierDesRDV.txt","r");
	if(FRDV==NULL){
		SetColor(12);printf("\n\t\tdesole !! le fichier fichierDesRDV.txt n'existe pas.\n");SetColor(15);
		int a;
		printf("\n\t1- retour au menu pr%ccedent  ",-126);
		do { scanf("%d",&a); }  while(a!=1);
		system("cls"); menuRDV();
	}
	else{
		int trouve=0;
		aide=fopen("repRDV\\fichieraide.txt","w");
		while(!feof(FRDV)){
			fscanf(FRDV,"%s%s%s",delateRDV.Nom_patient,delateRDV.Prenom_patient,delateRDV.CIN_patient);
			fscanf(FRDV,"%d%d%d",&delateRDV.dt_RDV.jour,&delateRDV.dt_RDV.mois,&delateRDV.dt_RDV.annee);
			fscanf(FRDV,"%d%d%s",&delateRDV.Hr_RDV.Hr,&delateRDV.Hr_RDV.Mn,delateRDV.commentaire);
			if(strcmp(delateRDV.CIN_patient,CIN)!=0){
				if(strcmp(delateRDV.CIN_patient,oldCIN)!=0){
					fprintf(aide,"%s\t%s\t%s\t",delateRDV.Nom_patient,delateRDV.Prenom_patient,delateRDV.CIN_patient);
					fprintf(aide,"%02d %02d %02d\t",delateRDV.dt_RDV.jour,delateRDV.dt_RDV.mois,delateRDV.dt_RDV.annee);
					fprintf(aide,"%02d %02d\t%s\n",delateRDV.Hr_RDV.Hr,delateRDV.Hr_RDV.Mn,delateRDV.commentaire);
					strcpy(oldCIN,delateRDV.CIN_patient);
				}	
			}
			else trouve=1;
		}
		fclose(aide);
		fclose(FRDV);
		
		if(trouve==0) { SetColor(12);printf("\n\t ce rendez-vous n'existe pas.\n");SetColor(15);}
		else{
			int choix;
			printf("\n\t\tvous etes sur que vous voulez supprimer ce rendez-vous\n\t\t1- oui\n\t\t2- non\n");
			do{
				printf("\n\t\tentrer votre choix ici : ");
				scanf("%d",&choix);
			}while(choix != 1 && choix != 2);
			if(choix==1){
				int test;
		    	test=remove("repRDV\\fichierDesRDV.txt");
				if(test==0){
					rename("repRDV\\fichieraide.txt","repRDV\\fichierDesRDV.txt");
					SetColor(10);printf("\n\t\tvotre rendez-vous a ete bien supprime\n");SetColor(15);
				}
				
			}
			else{ SetColor(12);printf("\n\t\tfichier n'est pas supprime\n");SetColor(15);}
		}
	}
	int a;
	printf("\n\t1- retour au menu pr%ccedent  ",-126);
  	printf("\n\t2- continue ");
	scanf("%d",&a);
	if(a==1){ system("cls"); menuRDV(); }
}


/*---------------------------fonction pour modifier un RDV----------------------------*/
void modifierRDV(){
	supprimerRDV();
	printf("\n\tCr%cer le nouveau Rendez-vous\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",130);
	ajouterRDV(hr_RDV,dt_RDV);
	SetColor(10);printf("\n\t\tvotre rendez-vous est bien modifier.\n");SetColor(15);
}


/*----------------fonction pour afficher un RDV d'un patient déjà existe--------------*/
void affichierRDV(){
	RDV afficheRDV;
	char CIN[15];
	FILE *FRDV;
	printf("\n\t\tvotre CIN s'il vous plait :  ");
	scanf("%s",CIN);
	FRDV=fopen("repRDV\\fichierDesRDV.txt","r");
	if(FRDV==NULL){
		SetColor(12);printf("\n\tdesole !! le fichier fichierDesRDV.txt n'existe pas.\n");SetColor(15);
	}
	else{
		int trouve=0;
		char ligne[100];
		while(!feof(FRDV)){
			fscanf(FRDV,"%s%s%s",afficheRDV.Nom_patient,afficheRDV.Prenom_patient,afficheRDV.CIN_patient);
			fscanf(FRDV,"%d%d%d",&afficheRDV.dt_RDV.jour,&afficheRDV.dt_RDV.mois,&afficheRDV.dt_RDV.annee);
			fscanf(FRDV,"%d%d%s",&afficheRDV.Hr_RDV.Hr,&afficheRDV.Hr_RDV.Mn,afficheRDV.commentaire);
			if(strcmp(afficheRDV.CIN_patient,CIN)==0){
				trouve=1;
				printf("\n\t\t--------------------------Votre rendez-Vous--------------------------\n");
				printf("\n\t\t%s\t%s\t%s\t",afficheRDV.Nom_patient,afficheRDV.Prenom_patient,afficheRDV.CIN_patient);
				printf("%02d/%02d/%02d\t",afficheRDV.dt_RDV.jour,afficheRDV.dt_RDV.mois,afficheRDV.dt_RDV.annee);
				printf("%02d:%02d\t%s\n",afficheRDV.Hr_RDV.Hr,afficheRDV.Hr_RDV.Mn,afficheRDV.commentaire);
				break;
			}
		}
	if(!trouve)  {SetColor(12);printf("\n\tdesole ce rendez-vous n'existe pas\n");SetColor(15);}
	}fclose(FRDV);
	int a;
	printf("\n\t1- retour au menu pr%ccedent  ",-126);
	do { scanf("%d",&a); }  while(a!=1);
	system("cls"); menuRDV();	
}


/*-----------------------fonction pour afficher la liste des RDV----------------------*/
void afficherListRDV(){
	RDV afficheRDV;
	FILE *FRDV;
	char CIN[12]="";
	RDV *p;
	FRDV=fopen("repRDV\\fichierDesRDV.txt","r");
	if(FRDV==NULL){
		SetColor(12);printf("desole !! le fichier fichierDesRDV.txt n'existe pas.\n");SetColor(15);
	}
	else{
		printf("\n\t\t---------------------------Liste des Rendez-Vous------------------------------\n");
		printf("\t\t******************************************************************************\n\n");
		while(!feof(FRDV)){
			fscanf(FRDV,"%s%s%s",afficheRDV.Nom_patient,afficheRDV.Prenom_patient,afficheRDV.CIN_patient);
			fscanf(FRDV,"%d%d%d",&afficheRDV.dt_RDV.jour,&afficheRDV.dt_RDV.mois,&afficheRDV.dt_RDV.annee);
			fscanf(FRDV,"%d%d%s",&afficheRDV.Hr_RDV.Hr,&afficheRDV.Hr_RDV.Mn,afficheRDV.commentaire);
			if(strcmp(afficheRDV.CIN_patient,CIN)!=0){
				printf("\t\t%-15s%-15s%-10s\t",afficheRDV.Nom_patient,afficheRDV.Prenom_patient,afficheRDV.CIN_patient);
				printf("%02d/%02d/%02d\t",afficheRDV.dt_RDV.jour,afficheRDV.dt_RDV.mois,afficheRDV.dt_RDV.annee);
				printf("%02d:%02d\t%-15s\n",afficheRDV.Hr_RDV.Hr,afficheRDV.Hr_RDV.Mn,afficheRDV.commentaire);
				strcpy(CIN,afficheRDV.CIN_patient);
			}
		}
	}
	fclose(FRDV);
	int a;
	printf("\n\t1- retour au menu pr%ccedent  ",-126);
	do { scanf("%d",&a); }  while(a!=1);
	system("cls"); menuRDV();
}


/*------------------fonction pour supprimer les enciens rendez-vous-------------------*/
void mis_a_jourRDV(){
	FILE *FRDV,*aide;
	RDV aideRDV;
	date dt_actuel;
	dt_actuel=date_actuel();
	FRDV=fopen("repRDV\\fichierDesRDV.txt","r");
	if(FRDV==NULL){
		SetColor(12);printf("desole !! le fichier fichierDesRDV.txt n'existe pas.\n");SetColor(15);
		int a;
		printf("\n\t1- retour au menu pr%ccedent  ",-126);
		do { scanf("%d",&a); }  while(a!=1);
		system("cls"); menuRDV();
	}
	aide=fopen("repRDV\\aidefichier.txt","w");
	char CIN[12]="";
	while(!feof(FRDV)){
		fscanf(FRDV,"%s%s%s",aideRDV.Nom_patient,aideRDV.Prenom_patient,aideRDV.CIN_patient);
		fscanf(FRDV,"%d%d%d",&aideRDV.dt_RDV.jour,&aideRDV.dt_RDV.mois,&aideRDV.dt_RDV.annee);
		fscanf(FRDV,"%d%d%s",&aideRDV.Hr_RDV.Hr,&aideRDV.Hr_RDV.Mn,aideRDV.commentaire);
		if(strcmp(aideRDV.CIN_patient,CIN)!=0){
			if(aideRDV.dt_RDV.jour>=dt_actuel.jour && aideRDV.dt_RDV.mois>=dt_actuel.mois &&aideRDV.dt_RDV.annee>=dt_actuel.annee){
				fprintf(aide,"%s\t%s\t%s\t",aideRDV.Nom_patient,aideRDV.Prenom_patient,aideRDV.CIN_patient);
				fprintf(aide,"%02d %02d %02d\t",aideRDV.dt_RDV.jour,aideRDV.dt_RDV.mois,aideRDV.dt_RDV.annee);
				fprintf(aide,"%02d %02d\t%s\n",aideRDV.Hr_RDV.Hr,aideRDV.Hr_RDV.Mn,aideRDV.commentaire);
				strcpy(CIN,aideRDV.CIN_patient);
			}
		}
	}
	fclose(aide);
	fclose(FRDV);
	
	int var;
	printf("\n\t\tvous etes sur que vous voulez faire un  mis-a-jour pour le fichier repRDV\\fichierDesRDV.txt.");
	printf("\n\t\t1- oui\n\t\t2- non\n");
	do{
		printf("\n\t\tentrer votre choix ici : ");
		scanf("%d",&var);
	}while(var != 1 && var != 2);
	if(var==1){
		int test;
		test=remove("repRDV\\fichierDesRDV.txt");
		if(test==0){
			rename("repRDV\\aidefichier.txt","repRDV\\fichierDesRDV.txt");
			SetColor(10);printf("\n\t\tle mis %c jour a ete bien fait\n",133);SetColor(15);
		}
		else {SetColor(12);printf("le mis a jour n'est pas fait\n");SetColor(15);}
	}
	int a;
	printf("\n\t1- retour au menu pr%ccedent  ",-126);
	do { scanf("%d",&a); }  while(a!=1);
	system("cls"); menuRDV();
}


/*-----------------------fonction qui donne la date actuel----------------------------*/
date date_actuel(){
	date dt_actuel;
	time_t now;
	time (&now);
	struct tm *local = localtime(&now);
	dt_actuel.jour = local->tm_mday;
	dt_actuel.mois = local->tm_mon + 1;
	dt_actuel.annee = local->tm_year + 1900;
	return dt_actuel;
}
