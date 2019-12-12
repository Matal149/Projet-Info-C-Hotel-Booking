#include <stdio.h>
#include <string.h>
#include "keywords.h"
#include "e_mail.h"

#define TAILLE_KEYWORD 15

typedef struct{
	KEYWORDS keyword;
	email reponse;
}REPONSE;

FILE*ouvrir(char*nom_fichier);
void fermer(FILE*fichier_ouvert);
void ajout(FILE *fichier);
void affiche(FILE *fichier);
void lister(FILE *fichier);
void afficherreponse(REPONSE*reponse);
