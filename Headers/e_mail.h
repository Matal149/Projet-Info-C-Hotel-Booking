#include <stdio.h>
#include <string.h>

#define TAILLE_CORPS 200
#define TAILLE_OBJET 60
#define TAILLE_MAIL 40

typedef struct
{
	char EM[TAILLE_MAIL];
	char DEST[TAILLE_MAIL];
	char OBJ[TAILLE_OBJET];
	char CORPS[TAILLE_CORPS];	
}email;

void afficherMail(email*mail);
email saisieMail(FILE *fichier);
void envoiReponseMail(FILE *fichier_reponses, email mailRecu, FILE* fichier_mailEnvoyes);

