#include <stdio.h>
#include <string.h>
#include "coordonnees.h"


FILE*ouvrir(char*nom_fichier);
void fermer(FILE*fichier_ouvert);
void ajout(FILE *fichier);
void affiche(FILE *fichier);
void lister(FILE *fichier);
void affichercoordonnees(COORDONNEES*coordonnees);
