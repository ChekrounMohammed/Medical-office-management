#include "fichier.h"
#include"patient.h"
////////////////////////////////////////////////////////////////   CREATION  ////////////////////////////////////////////////////////////////////
void createFile(FILE *fich,char fichier[]){
	fich=fopen(fichier,"w");
	if(fich==NULL){
		printf("\n\t\til y'a une erreur on peut pas ouvrir le fichier");
		exit(-1);
	} 
	fclose(fich);
}
////////////////////////////////////////////////////////////////    TEST_EXISTANCE   ////////////////////////////////////////////////////////////////////
int test_existance(char ch[]){
	FILE *fich;
	fich=fopen(ch,"r");
	if(fich==NULL){fclose(fich);return 0;}
	else{fclose(fich);return 1;}
}
////////////////////////////////////////////////////////////////    SUPPRIMER FICHIER  ////////////////////////////////////////////////////////////////////
void remove_file(){
	SetColor(15);
	char ch[20],ch1[40],path[]="patient\\",ch_temp;
	printf("\n\n\n\n");	
	printf("\n\t\tDonner le CIN du patient a supprimer :\t");
	scanf("%s",ch);
	strcat(path,ch); 
	strcat(path,".txt");
    if(test_existance(path) == 0){SetColor(12);printf("\n\t\tCe fichier n'existe pas !!\n");SetColor(15);}
	else{
		do{
			DC('=',70);
			printf("\n\t\tEst Ce Que Vous Voulez Vraiment Effacer Le Fichier\n\n\t\t1) Oui\n\t\t2) Non \n");
			printf("\n\t\tDonner votre choix SVP:\t");
			ch_temp=getch();	
			if(ch_temp=='1'){
				remove(path);
				SetColor(10);printf("\n\n\t\tle fichier %s est supprime\n",path);SetColor(15);
			}
			else if(ch_temp=='2'){
				SetColor(12);printf("\n\t\tle fichier %s n'est pas supprime\n",path);SetColor(15);
			}
		}while(ch_temp!='1' && ch_temp!='2');
	}
	char ch23;
	printf("\n\tAppuyez sur une touche pour revenir au menu prc%cedent\n",-126);
	ch23=getch();
	system("cls");
}

////////////////////////////////////////////////////////////////   FIN FICHIER  ////////////////////////////////////////////////////////////////////
