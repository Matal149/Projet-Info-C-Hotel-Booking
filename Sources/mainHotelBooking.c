/*
 * mainHotelBooking.c
 * 
 */


#include <stdio.h>
#include "../Headers/gestion_de_fichier.h"
//~ #include "../Headers/traitement_de_mail.h"
//~ #include "../Headers/e_mail.h"
//~ #include "../Headers/keywords.h"
#include "../Headers/reponses.h"

void menuGeneral(FILE* fichier_coordonnees, FILE* fichier_keywords, FILE* fichier_mail, FILE* fichier_mailEnvoyes);

int main(int argc, char **argv)
{
	/* Initialisation des fichiers du programme */
	FILE*fichier_coordonnees=NULL;
	FILE*fichier_keywords=NULL;
	FILE*fichier_mail=NULL;
	FILE*fichier_mailEnvoyes=NULL;

	/* Ouverture des fichiers du programme */
	fichier_coordonnees = ouvrir("coordonnees.bin");
	fichier_keywords = ouvrirReponse("reponses.bin");
	fichier_mail = ouvrir("mailsRecu.bin");
	fichier_mailEnvoyes = ouvrir("mailsEnvoyes.bin");
	
	menuGeneral(fichier_coordonnees, fichier_keywords, fichier_mail, fichier_mailEnvoyes);
	
	/* Fermeture des fichiers du programme */
	fermer(fichier_coordonnees);
	fermer(fichier_keywords);
	fermer(fichier_mail);
	fermer(fichier_mailEnvoyes);
	
	return 0;
}


/* Fonction gérer les évènements des touches appuyées */
void menuGeneral(FILE* fichier_coordonnes, FILE* fichier_keywords, FILE* fichier_mail, FILE* fichier_mailEnvoyes)
{
	char choixGeneral;
	do
	{
		printf("\tChoix du mode d'utilisation :\n");
		printf("\t1 : administrateur | 2 utilisateur \n");
		printf("\tQuitter................................: Q\n");
		printf(" Votre choix: ");
		scanf("%c",&choixGeneral);
		getchar();
		
		switch(choixGeneral)
		{
			case '1': 
				printf("\t\tMODE ADMINISTRATEUR\n");
				char choixAdminMode;
				printf("Ajouter une nouvelle coordonnees............: A\n");
				printf("Consultation d'une coordonnees..............: C\n");
				printf("Lister toutes les coordonnees...............: L\n");
				printf("Supprimer les coordonnees d'un client.......: S\n");
				
				printf("Ajouter une nouvelle reponse................: R\n");
				printf("Consultation d'une reponse..................: F\n");
				printf("Lister toutes les reponses..................: D\n");
				printf("Quitter et revenir au menu antérieur........: Q\n");
				printf(" votre choix: ");

				scanf("%c",&choixAdminMode);
				getchar();
				switch(choixAdminMode)
				{
					case 'a':
					case 'A':
						ajout(fichier_coordonnes);
					break;
					
					case 'c':
					case 'C':
						affiche(fichier_coordonnes);
					break;
					
					case 'l':
					case 'L':
						lister(fichier_coordonnes);
					break;
					
					case 's':
					case 'S':
						//~ supprimerCoordonnes(fichier_coordonnes);
						printf("Fonctionnalité en cours de développement\n");
					break;
					
					case 'r':
					case 'R':
						ajoutReponse(fichier_keywords);
					break;
					
					case 'f':
					case 'F':
						afficheReponse(fichier_keywords);
					break;
					
					case 'd':
					case 'D':
						listerReponse(fichier_keywords);
					break;
				}
				break;
			
			case '2':
				printf("\tMODE UTILISATEUR\n");
				email mail;
				mail = saisieMail(fichier_mail);
				afficherMail(&mail);
				envoiReponseMail(fichier_keywords, mail, fichier_mailEnvoyes);

				break;
				
			case 'q':
			case 'Q':
				printf("sorti du menu\n");
				break;
				
			default :
				printf("Commande inconnu [%c]\n",choixGeneral);
				break;
		}
		printf("\n\n");
	}while (choixGeneral != 'q' && choixGeneral != 'Q');
}

