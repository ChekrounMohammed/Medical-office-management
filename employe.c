#include "employe.h"
#include "Menumain.h"
#include "fichier.h"
#include"patient.h"
////////////////////////////////////////////////menu pour la gestion des employées////////////////////////////////////////////////
void MenuEmploye(){
	int choixemploye,i=0,a;
	char nomutil[30],ch;
	char password[14],passtest[14];
	char secretaire[]="secretaire";
	printf("\n\t\tsaisissez votre nom d'utilisateur :\t");
		SetColor(14);scanf("%s",nomutil);	SetColor(15);
	if(strcmp(secretaire,nomutil)!=0){
		system("cls");
		SetColor(12);printf("\n\t\tvous n'avez pas d'acces !\n\n");SetColor(15);
		MenuEmploye();
	}
	FILE *utilisateur;
	char chemin[]="employe\\";
	strcat(chemin,nomutil);
	strcat(chemin,".txt");
	utilisateur=fopen(chemin,"r");
	if(!utilisateur){
		system("cls");
		SetColor(12);printf("\n\t\tvotre nom d'utilisateur n'est pas valable\n\n");SetColor(15);
		menumain();
		exit(-1);
	}
	do{
		printf("\n\t\tsaisissez votre password (14 caractères maximum ) : ");
	for(i=0;i<14;i++){
		ch=getch();
		if(ch=='\r') break;
		password[i]=ch;
		ch='*';
			SetColor(14);printf("%c",ch);
	}
		SetColor(15);
	password[i]='\0';
	fscanf(utilisateur,"%s",passtest);
	if(strcmp(password,passtest)){
		system("cls");
		SetColor(12);printf("\n\t\tVotre mot de passe est invalide\n\n");SetColor(15);
		menumain();
	}else{
		system("cls");
		SetColor(10);printf("\n\t\tMot de pass valid%c\n",-126);SetColor(15);
			do{
		SetColor(11);		
		printf("\n\t\t------------------------Gestion des employees------------------------\n");
		printf("\t\t*********************************************************************\n\n");
		printf("\t\t\t\t\t 1- Ajouter un employe\n\n");
		printf("\t\t\t\t\t 2- Modifier employe\n\n");
		printf("\t\t\t\t\t 3- Supprimer employe\n\n");
		printf("\t\t\t\t\t 4- Afficher employe\n\n");
		printf("\t\t\t\t\t 5- Demander un congee\n\n");
		printf("\t\t\t\t\t 6- Retour Au menu principal\n\n");

		printf("\n\t\tentrez votre choix : ");
		scanf("%d",&choixemploye);
		SetColor(15);
		switch(choixemploye){
			case 1:
				system("cls");
				AjouterEmploye();//ajouter employe
				break;
			case 2:
				system("cls");
				 Modifieremploye();
				break;
			case 3:
				system("cls");
				supprimemploye();
				break;
			case 4:
				system("cls");
				Afficheremploye();
				break;
			case 5:
				system("cls");
				demandercongee();
				break;
			case 6:
				system("cls");
				menumain();
				break;
			default:
				system("cls");
				SetColor(12);printf("desole votre choix n'existe pas essayer une autre fois\n");SetColor(15);
				break;
		}
		printf("\n\t1- retour au menu pr%ccedent  ",-126);
		scanf("%d",&a);
		system("cls");
	}while(choixemploye!=6 || a!=1 );
	}
	i++;
	}while(strcmp(password,passtest) && i<3);
	fclose(utilisateur);
}
////////////////////////////////////////////////ajouter des employées////////////////////////////////////////////////
void AjouterEmploye(){
	employe A;
	printf("\n\t\tNom :\t");
	scanf("%s",A.Nom);
	printf("\n\t\tPrenom :\t");
	scanf("%s",A.Prenom);
	printf("\n\t\tCIN :\t");
	scanf("%s",A.CIN);
do{
	printf("\n\t\tLa Date De N aissance :");
    printf("\n\t\t  Le jour:\t");scanf("%d",&A.dt_naiss.jour);
	printf("\n\t\t  Le mois:\t");scanf("%d",&A.dt_naiss.mois);
	printf("\n\t\t  Le annee:\t");scanf("%d",&A.dt_naiss.annee);}while(Teste_date( A.dt_naiss.jour, A.dt_naiss.mois, A.dt_naiss.annee)==0);
	printf("\n\t\tAge : ");
	scanf("%d",&A.Age);
	printf("\n\t\tSituation familiale :\t");
	scanf("%s",A.st_familiale);
	printf("\n\t\tSEX :\t");
	scanf("%s",A.sex);
	printf("\n\t\tTelephone :\t");
	scanf("%s",A.telephone);
	printf("\n\t\tEmail :\t");
	scanf("%s",A.Email);
	printf("\n\t\tAdresse (EX: N Avenue Ville):\t");
	scanf("%d%s%s",&A.adresse.Num_mai,A.adresse.avenue,A.adresse.ville);
	printf("\n\t\tSALAIRE :");
	scanf("%d",&A.salaire);
	//creer un fichier pour ce employe et inserer tous ces données 
	FILE *F_EMPLO;
	char aide[12];
	strcpy(aide,A.CIN);
	char chemin[]="employe\\";
	strcat(chemin,aide);
	strcat(chemin,".txt");
	createFile(F_EMPLO,chemin);
	F_EMPLO=fopen(chemin,"a");
	fprintf(F_EMPLO,"%s\n%s\n%s\n",A.Nom,A.Prenom,A.CIN);
	fprintf(F_EMPLO,"%d %d %d\n",A.dt_naiss.jour,A.dt_naiss.mois,A.dt_naiss.annee);
	fprintf(F_EMPLO,"%d\n%s\n%s\n",A.Age,A.st_familiale,A.sex);
	fprintf(F_EMPLO,"%s\n%s\n",A.telephone,A.Email);
	fprintf(F_EMPLO,"%d %s %s\n",A.adresse.Num_mai,A.adresse.avenue,A.adresse.ville);
	fprintf(F_EMPLO,"%d\n",A.salaire);
	SetColor(10);printf("\n\t\tle nouveau employe est cr%c%c\n",130,130);SetColor(15);
	fclose(F_EMPLO);
}
////////////////////////////////////////////////modifier des employées////////////////////////////////////////////////
void Modifieremploye(){
	int choix;FILE *fich;employe malade;char fich_nom[20];
	printf("\n\t\tDonner le CIN du employe a modifier SVP :\t");
	scanf("%s",fich_nom);
	char path[]="employe\\";
	strcat(path,fich_nom);
	strcat(path,".txt");
	fich=fopen(path,"r");
	if(fich==NULL){
		SetColor(12);printf("\n\t\terreur !!! le fichier %s n'existe pas\n",path);SetColor(15);
		int a;
		printf("\n\t1- retour au menu pr%ccedent  ",-126);
		do { scanf("%d",&a); }  while(a!=1);
		system("cls");MenuEmploye();
	}
	   
    fscanf (fich,"%s\n%s\n%s\n%d\t%d\t%d\n%d\n%s\n%s\n%s\n%s\n%d\t%s\t%s\n%d",malade.Nom,malade.Prenom,malade.CIN,&malade.dt_naiss.jour,&malade.dt_naiss.mois,&malade.dt_naiss.annee,&malade.Age,malade.st_familiale,malade.sex,malade.telephone,&malade.Email,&malade.adresse.Num_mai,malade.adresse.avenue,malade.adresse.ville,&malade.salaire);
    fclose(fich);
	do{
	SetColor(11);
	printf("\n\t\t-------------------------- Modification Employ%c ---------------------------\n",130);
	printf("\t\t****************************************************************************\n\n");
	printf("\t\t\t\t\t  1- Modifier Le nom\n\n");
	printf("\t\t\t\t\t  2- Modifier Le Prenom\n\n");
	printf("\t\t\t\t\t  3- Modifier Le CIN\n\n");
	printf("\t\t\t\t\t  4- Modifier La Date Naissaince\n\n");
	printf("\t\t\t\t\t  5- Modifier L'Age'\n\n");
	printf("\t\t\t\t\t  6- Modifier La Situation Familliale\n\n");
	printf("\t\t\t\t\t  7- Modifier Le sex\n\n");
	printf("\t\t\t\t\t  8- Modifier Le N° de telephone\n\n");
	printf("\t\t\t\t\t  9- Modifier L'Adresse\n\n");
	printf("\t\t\t\t\t  10- Modifier L'Adresse E-mail\n\n");
	printf("\t\t\t\t\t  11-Modifier le salaire \n\n");
	printf("\t\t\t\t\t  0- Retour Au menu precedent\n\n");

	printf("\n\t\tdonner votre choix : ");
	scanf("%d",&choix);
	SetColor(15);

	switch (choix){
		case 1:printf("\n\t\tEntrer le nouveau Nom :\t");
		       scanf("%s",malade.Nom);
			   break;
		case 2:printf("\n\t\tEntrer le nouveau Prenom :\t");
		       scanf("%s",malade.Prenom);
			   break;
		case 3:printf("\n\t\tEntrer le nouveau CIN :\t");
		      char ch1[20],path1[]="employe\\";
		      scanf("%s",malade.CIN);
		      strcpy(ch1,malade.CIN);
		      strcat(ch1,".txt");
		      strcat(path1,ch1);
		      if(test_existance(path1)){
			  	printf("\n\t\tCet Employ%c est d%cj%c existe.\n",130,130,133);
			  	int a;
				printf("\n\t1- retour au menu pr%ccedent  ",-126);
				do { scanf("%d",&a); }  while(a!=1);
				system("cls");MenuEmploye();
			  }
		      rename(path,path1);
		      strcpy(path,path1);
			  break;
		case 4:printf("\n\t\tEntrer la nouvelle Date de naissance\n");
					do{
		            printf("\t\t  Le jour :\t");scanf("%d",&malade.dt_naiss.jour);
					printf("\n\t  Le mois :\t");scanf("%d",&malade.dt_naiss.mois);
					printf("\n\t  Le annee :\t");scanf("%d",&malade.dt_naiss.annee);}while(Teste_date( malade.dt_naiss.jour, malade.dt_naiss.mois, malade.dt_naiss.annee)==0);
		       break;
		case 5:printf("\n\t\tEntrer le nouveau Age :\t");
		       scanf("%d",&malade.Age);
			   break;
		case 6:printf("\n\t\tEntrer la nouvelle situation familiale :\t");
		       scanf("%s",malade.st_familiale);
			   break;
		case 7:printf("\n\t\tEntrer le nouveau sex :\t");		       
		       scanf("%s",malade.sex);
			   break;
		case 8:printf("\n\t\tEntrer le nouveau N de telphone :\t");		       
		       scanf("%s",malade.telephone);
			   break;
		case 9:printf("\n\t\tEntrer la nouvelle Adresse\n");
		            printf("\n\t\t  Le Numero de maison :\t");scanf("%d",&malade.adresse.Num_mai);
		            printf("\n\t\tL'avenue :\t");scanf("%s",malade.adresse.avenue);
		            printf("\n\t\tLa ville :\t");scanf("%s",malade.adresse.ville);	
		       break;
		case 10:printf("\n\t\tEntrer la nouvelle adresse e-mail :\t");     
		       scanf("%s",malade.Email);
			   break;
		case 11:printf("\n\t\tEntrer le nouveau salaire :\t");
				scanf("%d",&malade.salaire);
				break;
		case 0: break;
		default:
			system("cls");
			SetColor(12);printf("\n\t\tDesole votre choix n'existe pas essayer une autre fois\n");SetColor(15);
			break;
	}
	}while(choix < 0 || choix >11 || choix !=0);
		fich=fopen(path,"w");
	fprintf(fich,"%s\n%s\n%s\n%d\t%d\t%d\n%d\n%s\n%s\n%s\n%s\n%d\t%s\t%s\n%d\n",malade.Nom,malade.Prenom,malade.CIN,malade.dt_naiss.jour,malade.dt_naiss.mois,malade.dt_naiss.annee,malade.Age,malade.st_familiale,malade.sex,malade.telephone,malade.Email,malade.adresse.Num_mai,malade.adresse.avenue,malade.adresse.ville,malade.salaire);
		SetColor(10);printf("\nles modification sont faites correctement \n");	SetColor(15);
	fclose(fich);
}
////////////////////////////////////////////////supprimer des employées////////////////////////////////////////////////
void supprimemploye(){
		char ch[20],ch1[40],path[]="employe\\",ch_temp;
	printf("\n\t\tDonner le CIN du employe a supprimer :\t");
	scanf("%s",ch);
	strcat(path,ch);
	strcat(path,".txt");
    if(test_existance(path) == 0){ system("cls");SetColor(12);printf("\n\t\tCe fichier n'existe pas !!\n\n");SetColor(15);MenuEmploye();}
	else{
	do{
	printf("\n\t\tEst Ce Que Vous Voulez Vraiment Effacer Le Fichier\n\n\t\t1) Oui\n\t\t2) Non \n");
	ch_temp=getch();	
	if(ch_temp=='1'){
	remove(path);
	SetColor(10);printf("\n\t\tle fichier %s est supprime.\n",path);SetColor(15);
	}
	else if(ch_temp=='2'){
		SetColor(12);printf("\n\t\tle fichier %s n'est pas supprime\n",path);SetColor(10);
	}
}while(ch_temp!='1' && ch_temp!='2');
}
}
void Afficheremploye(){
	employe malade;FILE *fich;char temp[12];
	printf("\n\t\tDonner le CNI du employe a afficher :\t");
	scanf("%s",temp);
	system("cls");
	char path[]="employe\\";
	strcat(path,temp);
	strcat(path,".txt");
	fich=fopen(path,"r");
    if(!test_existance(path)){system("cls");SetColor(12);printf("\n\t\tce fichier n'existe pas !\n");SetColor(15);MenuEmploye();}
    fscanf (fich,"%s\n%s\n%s\n%d\t%d\t%d\n%d\n%s\n%s\n%s\n%s\n%d\t%s\t%s\n%d",malade.Nom,malade.Prenom,malade.CIN,&malade.dt_naiss.jour,&malade.dt_naiss.mois,&malade.dt_naiss.annee,&malade.Age,malade.st_familiale,malade.sex,malade.telephone,&malade.Email,&malade.adresse.Num_mai,malade.adresse.avenue,malade.adresse.ville,&malade.salaire);
	printf("\n\t\tNom:\t%s\n\n\t\tPrenom:\t%s\n\n\t\tCNI:\t%s\n",malade.Nom,malade.Prenom,malade.CIN);
	printf("\n\t\tDate De Naissance:\t%d / %d / %d\n",malade.dt_naiss.jour,malade.dt_naiss.mois,malade.dt_naiss.annee);
	printf("\n\t\tAge:\t%d\n\n\t\tSituation Familiale:\t%s\n\n\t\tsex:\t%s\n",malade.Age,malade.st_familiale,malade.sex);
	printf("\n\t\tN° De Tel:\t%s\n\n\t\tE-mail:\t%s\n",malade.telephone,malade.Email);
	printf("\n\t\tAdresse:\t%d\t%s\t%s\n\n\t\tSalaire:  %d Dhs\n",malade.adresse.Num_mai,malade.adresse.avenue,malade.adresse.ville,malade.salaire);
	fclose(fich);
}

// retourne 1 si l'année est bissextile et 0 si c'est le contraire
int bissextile (int a)
{
   if (a % 400 == 0)
        return 1;

   if (a % 100 ==0)
        return 0;

   if (a % 4 == 0)
        return 1;

   return 0;
}

// retourne la longueur du mois selon le mois et l'année
int longueurMois (int m, int a)
{

    switch(m)
    {
    case 1: return 31;
    case 2:
         if (bissextile(a))
         return 29;
         else
         return 28;
         break;
    case 3: return 31;break;
    case 4: return 30;break;
    case 5: return 31;break;
    case 6: return 30;break;
    case 7: return 31;break;
    case 8: return 31;break;
    case 9: return 30;break;
    case 10: return 31;break;
    case 11: return 30;break;
    case 12: return 31;break;
    default: return 0;break;
    }
}
int ajouterJours(int *j, int *mois, int *annee, int ajoute)
{
    int ajoute2;
    int ajout=ajoute;

    if (*j+ajoute<=longueurMois(*mois, *annee))
    *j=*j+ajoute;
    else
    {
        while(*j+ajoute>longueurMois(*mois, *annee))
        {
        ajoute2=ajoute-(longueurMois(*mois, *annee)-*j);
        if(ajoute2>(longueurMois(*mois+1, *annee))) {
        	*j=0;
        	 ajoute=ajoute2;
		}
        else {
        	*j=ajoute2;
        	ajoute=0;
		}
        if(*mois==12){
        	*mois=1;
        	(*annee)++;
		}else (*mois)++;
       
        }
    }
}
////////////////////////////////////////////////demande du congé////////////////////////////////////////////////
void demandercongee(){
	FILE *FICHCON;
	employe conge;
	printf("\n\t\tsaisissez votre CIN :\t");
	scanf("%s",conge.CIN);
	char temp[14];
	strcpy(temp,conge.CIN);
	char path[]="employe\\";
	strcat(path,temp);
	strcat(path,".txt");
	FICHCON=fopen(path,"r");
	if(!FICHCON){
		system("cls");
		SetColor(12);printf("\n\t\tcet employe n'existe pas \n");SetColor(15);
		demandercongee();
	}
	fclose(FICHCON);
	printf("\n\t\tnom :\t");
	scanf("%s",conge.Nom);
	printf("\n\t\tprenom :\t");
	scanf("%s",conge.Prenom);
	printf("\n\t\tadress (Num avenue ville ) :\t");
	scanf("%d%s%s",&conge.adresse.Num_mai,conge.adresse.avenue,conge.adresse.ville);
	int codepost;
	printf("\n\t\tcode postale :\t ");
	scanf("%d",&codepost);
	printf("\n\t\tEmail :\t");
	scanf("%s",conge.Email);
	date date_conge;
	printf("\n\t\tsaissez la date de debut de votre conge Ex:27 07 2020 :\t");
	scanf("%d%d%d",&date_conge.jour,&date_conge.mois,&date_conge.annee);
	int nbrjr;
	printf("\n\t\tsaisessez le nombre de jour souhait%ce dans votre congee :\t",130);
	scanf("%d",&nbrjr);
	system("cls");
	printf("\n-------------------------------------- demande du conge --------------------------------------\n");
	printf("**********************************************************************************************\n");
	FICHCON=fopen("employe/lettreconge.txt","w");
	system("cls");
	fprintf(FICHCON,"%s %s\n%s\n",conge.Nom,conge.Prenom,conge.CIN);
	fprintf(FICHCON,"%d %s %s\n%d\n%s\n\n",conge.adresse.Num_mai,conge.adresse.avenue,conge.adresse.ville,codepost,conge.Email);
	fprintf(FICHCON,"\tCabinet Nom du cabinet\n\ta l'attention du service du ressources\n\t\t\t\t\thumaines \n   Objet:demande du conge\n\n");
	fprintf(FICHCON,"Madame/Monsieur, \n\n");
	fprintf(FICHCON,"Au %d/%d/%d, j'ai acquis %d jours de conges payes au titre de l'annee %d.\n",date_conge.jour,date_conge.mois,date_conge.annee,nbrjr,date_conge.annee);
	fprintf(FICHCON,"Je souhaiterais prendre ces jours pour la periode allant du %d/%d/%d ",date_conge.jour,date_conge.mois,date_conge.annee);
	int njour=date_conge.jour,nmois=date_conge.mois,nannee=date_conge.annee;
	ajouterJours(&date_conge.jour,&date_conge.mois,&date_conge.annee,nbrjr);
	fprintf(FICHCON,"au %d/%d/%d inclus.\nPar la présente, je sollicite votre accord pour pouvoir m'absenter à ces dates.\n Je vous prie de bien vouloir m'informer de votre décision par écrit.\nDans l'attente de votre réponse, Je vous prie d'agréer, Madame, Monsieur, mes salutations distinguées .\n",date_conge.jour,date_conge.mois,date_conge.annee,date_conge.annee);
	fprintf(FICHCON,"\n\t\t\tsingature : %s %s \n",conge.Nom,conge.Prenom);
	printf("%s %s\n%s\n",conge.Nom,conge.Prenom,conge.CIN);
	printf("%d %s %s\n%d\n%s\n\n",conge.adresse.Num_mai,conge.adresse.avenue,conge.adresse.ville,codepost,conge.Email);
	printf("\t\t\t\t\tCabinet HEALTHY EAVERTON\n\t\t\t\t\ta l'attention du service du ressources\n\t\t\t\t\thumaines \n   Objet:demande du conge\n\n");
	printf("Madame/Monsieur, \n\n");
	printf("Au %d/%d/%d, j'ai acquis %d jours de conges payes au titre de l'annee %d.\n",njour,nmois,nannee,nbrjr,nannee);
	printf("Je souhaiterais prendre ces jours pour la période allant du %d/%d/%d ",njour,nmois,nannee);
	printf("au %d/%d/%d inclus.\nPar la presente, je sollicite votre accord pour pouvoir m'absenter à ces dates.\n Je vous prie de bien vouloir m'informer de votre decision par écrit.\nDans l'attente de votre reponse, Je vous prie d'agreer, Madame, Monsieur, mes salutations distinguées .\n",date_conge.jour,date_conge.mois,date_conge.annee,date_conge.annee);
	printf("\n\t\t\tsingature : %s %s \n",conge.Nom,conge.Prenom);
	fclose(FICHCON);
	char a;
	printf("\n\tvous voulez envoyez la lettre a l'administration ??  \n\n\t1: oui\n\t0: non\n");
	printf("\n\tEntrer votre choix:  ");scanf("%d",&a);
	system("cls");
	if(a) {
		SetColor(10);printf("\n\tla lettre est envoye a l'administration\n");SetColor(15);
		printf("\t________________________________________\n\n");
	}
	else {
		remove("employe/lettreconge.txt");
		system("cls");
		SetColor(12);printf("\n\tla lettre est supprimee\n");SetColor(15);
		printf("\t________________________\n\n");
	}
	int b;
	printf("\n\t2- ecrire une autre demande \n\n\tappuiyez sur un autre nombre sinon\t ");
	scanf("%d",&b);
	if(b==2) demandercongee();
}

