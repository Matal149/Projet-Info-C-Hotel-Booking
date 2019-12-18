#include <stdio.h>
#include <string.h>
#include "keywords.h"
#include "e_mail.h"

#define TAILLE_KEYWORD 15

typedef struct{
	KEYWORDS keyword;
	email reponse;
	//~ char reponse[TAILLE_CORPS];
}REPONSE;

FILE*ouvrirReponse(char*nom_fichier);
void fermerReponse(FILE*fichier_ouvert);
void ajoutReponse(FILE *fichier);
void afficheReponse(FILE *fichier);
void listerReponse(FILE *fichier);
void afficherReponse(REPONSE*reponse);
