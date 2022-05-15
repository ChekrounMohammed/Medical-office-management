#include "patient.h"
#include "Menumain.h"
#include "fichier.h"
////////////////////////////////////////////////////////////////  MenuPatient  ////////////////////////////////////////////////////////////////////
void MenuPatient(){
	int choixpatient;
	do{	
	    printf("\n\n\n");
	    SetColor(11);
		printf("\n\t\t------------------------ Gestion Des Patients -------------------------\n");
	    printf("\t\t");DC('*',71);printf("\n");
		printf("\t\t\t\t\t 1- Ajouter patient\n\n");
		printf("\t\t\t\t\t 2- Afficher patient\n\n");
		printf("\t\t\t\t\t 3- Modifier patient\n\n");
		printf("\t\t\t\t\t 4- Supprimer patient\n\n");
		printf("\t\t\t\t\t 5- Afficher l'archive des patients\n\n");
		printf("\t\t\t\t\t 0- Retour Au menu precedent\n");
        printf("\n\t\tdonner votre choix : ");
		scanf("%d",&choixpatient);
		SetColor(15);
		switch(choixpatient){
			case 1:system("cls");AjouterPatient();break;
			case 2:system("cls");AfficherPatient();break;
			case 3:system("cls");MenuModifier();break;
			case 4:system("cls");remove_file();break;
			case 5:system("cls");Afficher_ARCHIVE();break;
			case 0:system("cls");menumain();break;
			default:system("cls");
				SetColor(12);printf("\n\t\tdesole votre choix n'existe pas essayer une autre fois\n");SetColor(15);break;
		}
	}while((int)(choixpatient) != 0);
}
////////////////////////////////////////////////////////////////  MenuFacture  ////////////////////////////////////////////////////////////////////
void MenuFacture(){
	int choix;
	do{	printf("\n\n\n\n\n");
        SetColor(11);
		printf("\n\t\t------------------------ Gestion Des Factures ------------------------\n");
	    printf("\t\t");DC('*',71);printf("\n");
		printf("\t\t\t\t\t 1- Ecrire une facture\n\n");
		printf("\t\t\t\t\t 0- Retour Au menu precedent\n\n");
        printf("\n\t\tdonner votre choix : ");
		scanf("%d",&choix);
		SetColor(15);
		switch(choix){
			case 1:system("cls");fill_bill();break;
			case 0:system("cls");menumain();break;
			default:system("cls");
				SetColor(12);printf("\n\t\tdesole votre choix n'existe pas essayer une autre fois\n");SetColor(15);
				break;
		}
	}while((int) (choix) != 0);
}
///////////////////////////////////////////////////////////////   FACTURE  ////////////////////////////////////////////////////////////////////
void fill_bill(){
	SetColor(15);
	Bill facture;FILE *file,*file1;patient malade;char fich_nom[20],path1[]="patient\\",Nom_p[20],Prenom_p[20],Nom_copie[20],CIN_P[20];
	printf("\n\t\tDonner le CIN du Patient  SVP :\t");
	scanf("%s",fich_nom);
	strcpy(Nom_copie,fich_nom);
	strcat(path1,fich_nom);
	strcat(path1,".txt");
    if(test_existance(path1)==0){SetColor(12);printf("\n\t\tCe Patient n'existe pas dans La listes des patients !!\n\n");SetColor(15);DC('_',70);
	char ch23;
	printf("\n\tAppuyez sur une touche pour revenir au menu prc%cedent\n",-126);
	ch23=getch();
	system("cls");MenuFacture();
	}
    else{
    file1=fopen(path1,"r");
    fscanf(file1,"%s\n%s\n%s",Nom_p,Prenom_p,CIN_P);
	strcpy(facture.Nom,Nom_p);
	strcpy(facture.Prenom,Prenom_p);
	strcpy(facture.CIN,CIN_P);
    fclose(file1);
    char path[]="facture\\";
	strcat(path,"facture.txt");
	printf("\n\t\tfacture : ");
	scanf("%s",facture.Facture);
	printf("\n\t\tOrdonnance : ");
	scanf("%s",facture.Ordo);
	///////////////////////////////// Détermination De La Date Actuelle
	date DATE;time_t now;time(&now);hour heure;
	struct tm *temp_actu=localtime(&now);
	DATE.jour=temp_actu->tm_mday;
	DATE.mois=temp_actu->tm_mon+1;
	DATE.annee=temp_actu->tm_year+1900;
	heure.hour=temp_actu->tm_hour;
	heure.mint=temp_actu->tm_min;
	///////////////////////////////// Creation De La facture
    file=fopen(path,"w");
    fprintf(file,"========================   Nom De La Cabinet  ========================\n");
    fprintf(file,"\tNom :\t\t %s\n\n",facture.Nom);
    fprintf(file,"\tPrenom :\t %s\n\n",facture.Prenom);
    fprintf(file,"\tCIN :\t\t %s\n\n",facture.CIN);
    fprintf(file,"\tfacture :\t %s\n\n",facture.Facture);
    fprintf(file,"\tordonnance :\t %s\n\n",facture.Ordo);
    fprintf(file,"\tDate:\t\t %02d/%02d/%d | heure %02d:%02d\n\n",DATE.jour,DATE.mois,DATE.annee,heure.hour,heure.mint );
    fprintf(file,"=======================================================================\n");
    fprintf(file,"\n========================   Pour Nous Contacter  ========================\n");
    fprintf(file,"\tTEL :\t\t 0697769966\n");
    fprintf(file,"\tE-MAIL :\t CabineMedicale@gmail.com\n");
    fprintf(file,"\tADRESS : \t N°  adresse   adresse\n");
    fprintf(file,"===============================================================================================\n");
    fprintf(file,"\tNous sommes fi%cre de vous servir Mr(Mme) %s %s,on vous souhaite une bonne sant%c",-118,facture.Nom,facture.Prenom,-126);
    fclose(file);
    Afficher_facture(path);
	}
    
}
////////////////////////////////////////////////////////////////   AJOUTER PATIENT  ////////////////////////////////////////////////////////////////////
void AjouterPatient(){
	patient malade;char temp1[15],path1[]="patient\\";
	printf("\n\t\tNom : ");
	scanf("%s",malade.Nom);
	printf("\t\t");DC('_',70);
	printf("\t\tPrenom : ");
	scanf("%s",malade.Prenom);
	printf("\t\t");DC('_',70);
	printf("\t\tCIN : ");
	scanf("%s",malade.CIN);
	strcpy(temp1,malade.CIN);
	strcat(path1,temp1);
	strcat(path1,".txt");
	if(test_existance(path1)==1){SetColor(12);printf("\n\t\tIl existe D%cja un patient dont ce CNI!!\n\n",-118);SetColor(15);
	printf("\t\t");DC('_',70);
	char ch23;
	printf("\n\tAppuyez sur une touche pour revenir au menu prc%cedent\n",-126);
	ch23=getch();
	system("cls");MenuPatient();
	}
	else{
	do{
		printf("\t\t");DC('_',70);
		printf("\t\tLa Date De N aissance :\n");
	    printf("\n\t\t  Le jour:\t");scanf("%d",&malade.dt_naiss.jour);
		printf("\n\t\t  Le mois:\t");scanf("%d",&malade.dt_naiss.mois);
		printf("\n\t\t  Le annee:\t");scanf("%d",&malade.dt_naiss.annee);
	}while(Teste_date( malade.dt_naiss.jour, malade.dt_naiss.mois, malade.dt_naiss.annee)==0);
		printf("\t\t");DC('_',70);
		printf("\t\tAge : ");
		scanf("%d",&malade.Age);
		printf("\t\t");DC('_',70);
		printf("\t\tSituation familiale : ");
		scanf("%s",malade.st_familiale);
		printf("\t\t");DC('_',70);
		printf("\t\tProfession : ");
		scanf("%s",malade.profession);
		printf("\t\t");DC('_',70);
		printf("\t\tTelephone : ");
		scanf("%s",malade.telephone);
		printf("\t\t");DC('_',70);
		printf("\t\tEmail : ");
		scanf("%s",malade.Email);
		printf("\t\t");DC('_',70);
		printf("\t\tL'adresse :\n\n");
    	printf("\n\t\tLe N_maison:\t");scanf("%d",&malade.adresse.Num_mai);
		printf("\n\t\tL'avenue:\t");scanf("%s",malade.adresse.avenue);
		printf("\n\t\tLa ville:\t");scanf("%s",malade.adresse.ville);	
                                                     //  Ajoute du fichier patient
		FILE *fich;
		char temp[15];
		strcpy(temp,malade.CIN);
		char path[]="patient\\";
		strcat(path,temp);
		strcat(path,".txt");
		createFile(fich,path);
		fich=fopen(path,"a");
		fprintf(fich,"%s\n%s\n%s\n",malade.Nom,malade.Prenom,malade.CIN);
		fprintf(fich,"%d\t%d\t%d\n",malade.dt_naiss.jour,malade.dt_naiss.mois,malade.dt_naiss.annee);
		fprintf(fich,"%d\n%s\n%s\n",malade.Age,malade.st_familiale,malade.profession);
		fprintf(fich,"%s\n%s\n",malade.telephone,malade.Email);
		fprintf(fich,"%d\t%s\t%s",malade.adresse.Num_mai,malade.adresse.avenue,malade.adresse.ville);
		fclose(fich);
		SetColor(10);printf("\n\n\t\tLe Fichier Du Patient Est Bien Ajouter\n");SetColor(15);
                                                     //  Ajoute de information du patient dans l'archive
		char archive[]="patient\\Archive\\Archive_des_patient.txt";FILE *arch;
		arch=fopen("patient\\Archive\\Archive_des_patient.txt","a");
		fprintf(arch,"%s\t%s\t%s\t%d %d %d\t%s\t\t%s\t%s\n",malade.Nom,malade.Prenom,malade.CIN,malade.dt_naiss.jour,malade.dt_naiss.mois,malade.dt_naiss.annee,malade.profession,malade.telephone,malade.Email);
		fclose(arch);
	}
	char ch;
	printf("\n\n\tAppuyez sur une touche pour revenir au menu prc%cedent\n",-126);
	ch=getch();
	system("cls");MenuPatient();
	
}
////////////////////////////////////////////////////////////////    Afficher  ////////////////////////////////////////////////////////////////////
void AfficherPatient(){
	system("cls");
	SetColor(15);
	patient malade;FILE *fich;char temp[12];
	printf("\n\t\tDonner le CNI du patient a afficher :\t");
	scanf("%s",temp);
	char path[]="patient\\";
	strcat(path,temp);
	strcat(path,".txt");
	fich=fopen(path,"r");
    if(test_existance(path)==0){SetColor(12);printf("\n\t\tCe fichier n'existe pas !!\n");SetColor(15);
		char ch23;
		printf("\n\tAppuyez sur une touche pour revenir au menu prc%cedent\n",-126);
		ch23=getch();
		system("cls");MenuPatient();
	}
    else{
    	DC('=',70);
    	fscanf (fich,"%s\n%s\n%s\n%d\t%d\t%d\n%d\n%s\n%s\n%s\n%s\n%d\t%s\t%s",malade.Nom,malade.Prenom,malade.CIN,&malade.dt_naiss.jour,&malade.dt_naiss.mois,&malade.dt_naiss.annee,&malade.Age,malade.st_familiale,malade.profession,malade.telephone,&malade.Email,&malade.adresse.Num_mai,malade.adresse.avenue,malade.adresse.ville);
		printf("\n\t\tNom:\t\t\t%s\n\n\t\tPrenom:\t\t\t%s\n\n\t\tCNI:\t\t\t%s\n",malade.Nom,malade.Prenom,malade.CIN);
		printf("\n\t\tDate De Naissance:\t%d / %d / %d\n\n",malade.dt_naiss.jour,malade.dt_naiss.mois,malade.dt_naiss.annee);
		printf("\n\t\tAge:\t\t\t%d\n\n\t\tSituation Familiale:\t%s\n\n\t\tProfession:\t\t%s\n",malade.Age,malade.st_familiale,malade.profession);
		printf("\n\t\tN° De Tel:\t\t%s\n\n\t\tE-mail:\t\t\t%s\n",malade.telephone,malade.Email);
		printf("\n\t\tAdresse:\t\t%d\t%s\t%s\n\n",malade.adresse.Num_mai,malade.adresse.avenue,malade.adresse.ville);
		fclose(fich);
		DC('=',70);
		char ch;
		printf("\n\tAppuyez sur une touche pour revenir au menu prc%cedent\n",-126);
		ch=getch();
		system("cls");MenuPatient();
	}
}
/////////////////////////////////////////////////////////////////   Modifier   /////////////////////////////////////////////////////////////////////
void MenuModifier(){
	
	int choix;FILE *fich;patient malade;char fich_nom[20];
	printf("\n\t\tDonner le CIN du Patient a modifier SVP :\t");
	scanf("%s",fich_nom);
	char path[]="patient\\";
	strcat(path,fich_nom);
	strcat(path,".txt");
	fich=fopen(path,"r");
	if(test_existance(path)==0){SetColor(12);printf("\n\t\tIl n'existe pas un patient dont ce CNI!!\n");SetColor(15);
		char ch23;
		printf("\n\t\tAppuyez sur une touche pour revenir au menu prc%cedent\n",-126);
		ch23=getch();
		system("cls");}
	else{
    	fscanf (fich,"%s\n%s\n%s\n%d\t%d\t%d\n%d\n%s\n%s\n%s\n%s\n%d\t%s\t%s",malade.Nom,malade.Prenom,malade.CIN,&malade.dt_naiss.jour,&malade.dt_naiss.mois,&malade.dt_naiss.annee,&malade.Age,malade.st_familiale,malade.profession,malade.telephone,&malade.Email,&malade.adresse.Num_mai,malade.adresse.avenue,malade.adresse.ville);
    	fclose(fich);
		do{
		system("cls");	
		SetColor(11);
		printf("\n\t\t------------------------ Modification Des Fichiers -------------------------\n");
 		printf("\t\t");DC('*',76);printf("\n");
		printf("\t\t\t\t\t1- Modifier Le nom\n\n");
		printf("\t\t\t\t\t2- Modifier Le Prenom\n\n");
		printf("\t\t\t\t\t3- Modifier Le CIN\n\n");
		printf("\t\t\t\t\t4- Modifier La Date Naissaince\n\n");
		printf("\t\t\t\t\t5- Modifier L'Age'\n\n");
		printf("\t\t\t\t\t6- Modifier La Situation Familliale\n\n");
		printf("\t\t\t\t\t7- Modifier La Profession\n\n");
		printf("\t\t\t\t\t8- Modifier Le N° de telephone\n\n");
		printf("\t\t\t\t\t9- Modifier L'Adresse\n\n");
		printf("\t\t\t\t\t10- Modifier L'Adresse E-mail\n\n");
		SetColor(10);printf("\t\t\t\t\t0- Confirm%c les modification\n\n",-126);SetColor(15);
    	printf("\n\t\tdonner votre choix : ");
		scanf("%d",&choix);
		DC('_',50);
		SetColor(11);
	switch (choix){
		case 1:printf("\n\t\tEntrer le nouveau Nom :\t");
		       scanf("%s",malade.Nom);
			   break;
		case 2:printf("\n\t\tEntrer le nouveau Prenom :\t");
		       scanf("%s",malade.Prenom);
			   break;
		case 3:printf("\n\t\tEntrer le nouveau CIN :\t");
		      char ch1[20],path1[]="patient\\",temp[20],ch;
		      strcpy(temp,malade.CIN);
		      scanf("%s",malade.CIN);
		      strcpy(ch1,malade.CIN);
		      strcat(ch1,".txt");
		      strcat(path1,ch1);
		      if(test_existance(path1)==1){SetColor(12);printf("\n\t\tIl existe un patient dont ce CNI SVP,saisir votre vrai autre CNI \n");SetColor(15);
		      DC('=',50);
		      printf("\n\tAppuyez sur une touche pour revenir au menu prc%cedent\n",-126);
	          ch=getch();
			  strcpy(malade.CIN,temp);break;}
		      rename(path,path1);
		      strcpy(path,path1);
			  break;
		case 4:printf("\n\t\tEntrer la nouvelle Date de naissance\n");
		            printf("\n\t\t  Le jour:\t");scanf("%d",&malade.dt_naiss.jour);
		            printf("\n\t\t  Le mois:\t");scanf("%d",&malade.dt_naiss.mois);
		            printf("\n\t\t  Le annee:\t");scanf("%d",&malade.dt_naiss.annee);
		       break;
		case 5:printf("\n\t\tEntrer le nouveau Age :\t");
		       scanf("%d",&malade.Age);
			   break;
		case 6:printf("\n\t\tEntrer la nouvelle situation familiale :\t");
		       scanf("%s",malade.st_familiale);
			   break;
		case 7:printf("\n\t\tEntrer la nouvelle profession :\t");		       
		       scanf("%s",malade.profession);
			   break;
		case 8:printf("\n\t\tEntrer le nouveau N° de telphone :\t");		       
		       scanf("%s",malade.telephone);
			   break;
		case 9:printf("\n\t\tEntrer la nouvelle Adresse\n");
		            printf("\n\t\t  Le N_maison:\t");scanf("%d",&malade.adresse.Num_mai);
		            printf("\n\t\t  L'avenue:\t");scanf("%s",malade.adresse.avenue);
		            printf("\n\t\t  La ville:\t");scanf("%s",malade.adresse.ville);	
		       break;
		case 10:printf("\n\t\tEntrer la nouvelle adresse e-mail :\t");     
		       scanf("%s",malade.Email);
			   break;
		case 0: system("cls");break;
		default:
			system("cls");
			SetColor(12);printf("\n\t\tDesole votre choix n'existe pas essayer une autre fois\n");SetColor(15);
			char ch11;
			printf("\n\tAppuyez sur une touche pour revenir au menu prc%cedent\n",-126);
			ch11=getch();
			system("cls");MenuPatient();
			break;
	}
	}while((int) (choix) != 0);
		fich=fopen(path,"w");
		fprintf(fich,"%s\n%s\n%s\n%d\t%d\t%d\n%d\n%s\n%s\n%s\n%s\n%d\t%s\t%s",malade.Nom,malade.Prenom,malade.CIN,malade.dt_naiss.jour,malade.dt_naiss.mois,malade.dt_naiss.annee,malade.Age,malade.st_familiale,malade.profession,malade.telephone,malade.Email,malade.adresse.Num_mai,malade.adresse.avenue,malade.adresse.ville);
		fclose(fich);
                                                     //  Ajoute de information du patient dans l'archive
		char archive[]="patient\\Archive\\Archive_des_patient.txt";FILE *arch;
		arch=fopen("patient\\Archive\\Archive_des_patient.txt","a");
		fprintf(arch,"%s\t%s\t%s\t%d %d %d\t%s\t\t%s\t%s\n",malade.Nom,malade.Prenom,malade.CIN,malade.dt_naiss.jour,malade.dt_naiss.mois,malade.dt_naiss.annee,malade.profession,malade.telephone,malade.Email);
		fclose(arch);
	}
	
}
////////////////////////////////////////////////////////////////   TEST DATE  ////////////////////////////////////////////////////////////////////
int Teste_date(int jour,int mois,int annee){
      int indice;
      if((jour>31 || mois >12)||(mois==2 && jour>29)||(mois<=0 || jour <=0 || annee <=1878)){
       indice=0;}
      else if((mois==2 && jour>28) && (annee%4!=0)){indice=0;}
      else if(jour>30){
      if(mois<8 && mois%2==0){indice=0;}
      else if(mois>=8 && mois%2==1){indice=0;}
      else {  indice=1;}}
      else{ indice=1;}
      if(indice == 0){SetColor(12);printf("\n\t\tLa Date Que Vous avez entr%c est invalide !!\n\n",-126);SetColor(15);}
      return indice;
    }
////////////////////////////////////////////////////////////////  Afficher Facture  ////////////////////////////////////////////////////////////////////
void Afficher_facture(char CIN[]){
	system("cls");
	printf("\n\n\n");
    FILE *file12;char temp[201],ch;
	if(test_existance(CIN) == 0){SetColor(12);printf("\n\t\tCe fichier n'existe pas !!\n\n");SetColor(15);	
	char ch23;
	printf("\n\t\tAppuyez sur une touche pour revenir au menu prc%cedent\n",-126);
	ch23=getch();
	system("cls");}
	else{
		file12=fopen(CIN,"r");
		while(!feof(file12)){
		fgets(temp,200,file12);
		printf("%s",temp);
		temp[0]='\0';}
		fclose(file12);
		printf("\n");
	    printf("\n\t\tAppuyez sur une touche pour revenir au menu pr%ccedent\n",-126);
	    ch=getch();
	    system("cls");
	}
}
////////////////////////////////////////////////////////////////  Afficher L'archive  ////////////////////////////////////////////////////////////////////
void Afficher_ARCHIVE(){
	FILE *file12;patient malade;
	char *donnes[]={"Nom","Prenom","CIN","Dat_Naiss","Profession","N.TEL","E-mail"};
		system("cls");
		printf("\t\t\t");printf(" ");SetColor(14);LC('-',48);printf("\n");
		printf("\t\t\t");printf("|\t\t                    \t\t|\n");
		printf("\t\t\t");printf("|                    \t\t\t\t|\n\t\t\t|");SetColor(15);printf("\t\tArchive Des Patients\t\t");SetColor(14);printf("|\n");
		printf("\t\t\t");printf("|\t\t                    \t\t|\n");
		printf("\t\t\t");printf(" ");LC('-',48);printf("\n");SetColor(15);
		
		
		file12=fopen("patient\\Archive\\Archive_des_patient.txt","r");
		printf("\n\t ");SetColor(14);LC('-',113);SetColor(15);
	    printf("\n\t| %-15s %-15s %-10s %-8s  %-15s %-10s %-30s |\n",donnes[0],donnes[1],donnes[2],donnes[3],donnes[4],donnes[5],donnes[6]);
	    SetColor(14);printf("\t|"),LC('-',113);printf("|\n");SetColor(15);
		while(!feof(file12)){
	   	fscanf(file12,"%s %s %s %d %d %d %s %s %s %d %s %s\n",malade.Nom,malade.Prenom,malade.CIN,&malade.dt_naiss.jour,&malade.dt_naiss.mois,&malade.dt_naiss.annee,malade.profession,malade.telephone,malade.Email);
	    printf("\t| %-15s %-15s %-10s %-2d/%-2d/%-4d  %-15s %-10s %-30s|\n",malade.Nom,malade.Prenom,malade.CIN,malade.dt_naiss.jour,malade.dt_naiss.mois,malade.dt_naiss.annee,malade.profession,malade.telephone,malade.Email);
	    printf("\t|"),SetColor(14);LC('-',113);SetColor(15);printf("|\n");
	}
		fclose(file12);
		char ch;
		printf("\n\t\tAppuyez sur une touche pour revenir au menu prc%cedent\n",-126);
		ch=getch();
		system("cls");

}
////////////////////////////////////////////////////////////////   FIN FICHIER  ////////////////////////////////////////////////////////////////////
