#include <stdio.h>
#include <string.h>

#define TAILLE_CORPS 500
#define TAILLE_OBJET 60
#define TAILLE_MAIL 40
#define REPONSE_DEFAVORABLE_MAIL "Veuillez nous excuser mais notre service de réponse de mail automatique n'a pas été en mesure de générer un mail avec les informations que vous nous avez fourni.\nVous pouvez nous renvoyer un mail en précisant dans le corps de votre mail, la ville où vous souhaitez reserver une chambre."

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

