#ifndef SOMETHING_H1
#define SOMETHING_H1
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include "Menumain.h"
////////////////////////////////////////////////////////////////   Les prototypes des fonctions   ////////////////////////////////////////////////////////////////////
void createFile(FILE *fich,char fichier[]);
int test_existance(char ch[]);
void remove_file();
#endif
