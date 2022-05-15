#include "Menumain.h"
#include <windows.h>
////////////////////////////////////////////////////////////////    LA fonct DC   ////////////////////////////////////////////////////////////////////
void DC(char ch,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%c",ch);
		}
		printf("\n\n");
}
////////////////////////////////////////////////////////////////    La fonction LC ////////////////////////////////////////////////////////////////////
void LC(char ch,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%c",ch);
		}

}
////////////////////////////////////////////////////////////////    MenuMain  ////////////////////////////////////////////////////////////////////
void menumain(){
	int choix;
	
	do{
	printf("\n\n");	
	SetColor(11);
	printf("\n\t\t------------------------ Cabinet Medicale -------------------------\n");
	printf("\t\t");DC('*',67);printf("\n");
	printf("\t\t\t\t\t1- Gestion des patients\n\n");
	printf("\t\t\t\t\t2- Gestion des Rendez-Vous\n\n");
	printf("\t\t\t\t\t3- Gestion des factures\n\n");
	printf("\t\t\t\t\t4- Certificat Medical\n\n");
	printf("\t\t\t\t\t5- Gestion des employes\n\n");
	printf("\t\t\t\t\t0- Exit\n\n");
	printf("\n\t\tdonner votre choix : ");
	scanf("%d",&choix);
	SetColor(15);
	switch (choix){
		case 1:system("cls");MenuPatient(); break;
		case 2:system("cls");menuRDV();break;
		case 3:system("cls");MenuFacture();break;
		case 4:system("cls");CertificatMedical();break;
		case 5:system("cls");MenuEmploye();break;
		case 0:printf("\t\t");DC('_',67);SetColor(10);printf("\t\tBonne ");SetColor(15);printf("journ%ce\n",-126);exit(-1);break;
		default:system("cls");
			SetColor(12);printf("\n\t\tDesole votre choix n'existe pas essayer une autre fois\n");SetColor(15);
			DC('_',70);
			break;
	}
	}while((int)(choix) != 0);
}
////////////////////////////////////////////////////////////////    LOGIN   ////////////////////////////////////////////////////////////////////
void Login(){
	 int i=0;FILE *fich;
	 char ch,Mot_de_pass[50],Nom_Utilisateur[50],path[]="employe\\",val_pass[]="azertyui",Nom[15];
	 printf("\n\n\n");
	 SetColor(15);
	 printf("\n\t\tDonner votre nom d'utilsateur(CIN) SVP.\n");
	 printf("\n\t\tNom d'Utilisateur:\t");
	 SetColor(14);scanf("%s",Nom_Utilisateur);SetColor(15);
	 strcat(path,Nom_Utilisateur);
	 strcat(path,".txt");
	 fich=fopen(path,"r");
	 if(fich==NULL){
	 	system("cls");
	 	SetColor(12);printf("\n\t\tLe Nom d'Utilisateur est non valid%c.SVP r%cssayer.\n\n",-126,-126);SetColor(15);
	 	Login();}
	else{
	 	fscanf(fich,"%s",Nom);
	 	fclose(fich);
	 printf("\n\t\t");DC('_',60);
	 printf("\n\t\tDonner votre mot de pass SVP.Pour confirm%c taper ENTRER.\n",(-126));
     printf("\n\t\tMot de pass:\t");
     while(1){
     	ch=getch();
     	if(ch == ENTRER){
     		Mot_de_pass[i]='\0';
     		break;
          }
     	else if(ch == EFFACER){
     		if(i>0){
			i--;
     		printf("\b \b");
          }
     	}	
     	else{
     		Mot_de_pass[i]=ch;
     		i++;
     		SetColor(14);printf("*");
     	}
     }
     SetColor(15);
     if(strcmp(Mot_de_pass,val_pass) == 0){
     	system("cls");
     	SetColor(10);printf("\n\t\tMot de pass valid%c",-126);SetColor(15);printf(",Bonjour Mr(Mme)\"%s\".\n\n",Nom);
     	menumain();
	 }
	 else{
	 	system("cls");
	 	SetColor(12);printf("\n\t\tMot de pass non valid%c.SVP r%cssayer.\n\n",-126,-126);SetColor(15);
	 	Login();
	 }
}
}

////////////////////////////////////////////////////////////////    La fonction set color  ////////////////////////////////////////////////////////////////////
void SetColor(int ForgC){
 WORD wColor;
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
////////////////////////////////////////////////////////////////    FIN FICHIER   ////////////////////////////////////////////////////////////////////
