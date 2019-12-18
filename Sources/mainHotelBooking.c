/*
 * mainHotelBooking.c
 * 
 */


#include <stdio.h>
#include "../Headers/gestion_de_fichier.h"
#include "../Headers/e_mail.h"
#include "../Headers/keywords.h"

void menuGeneral(FILE* fichier_coordonnees, FILE* fichier_keywords);

int main(int argc, char **argv)
{
	/* Test fontion gestion_de_fichier.c*/
	FILE*fichier_coordonnees=NULL;
	FILE*fichier_keywords=NULL;

	fichier_coordonnees = ouvrir("coordonnees.bin");
	fichier_keywords = ouvrir("reponses.bin");
	//~ ajout(fichier_coordonnes);
	//~ affiche(fichier_coordonnes);
	//~ lister(fichier_coordonnes);
	
	
	menuGeneral(fichier_coordonnees, fichier_keywords);
	
	return 0;
}



void menuGeneral(FILE* fichier_coordonnes, FILE* fichier_keywords)
{
	char choix;
	do
	{
		//~ printf("Ajouter d'un nouveau client............: A\n");
		//~ printf("Consultation d'un compte client........: C\n");
		//~ printf("Lister tous les comptes de clients.....: L\n");
		//~ printf("Opération sur un compte client.........: O\n");
		
		printf("Choix du mode d'utilisation :\n");
		printf("1 : administrateur | 2 utilisateur \n");
		printf("Quitter................................: Q\n");
		printf(" votre choix: ");

		scanf("%c",&choix);
		getchar();
		
		switch(choix)
		{
			case '1': 
				//~ menuAdministrateur(fichier);
				printf("MODE ADMIN\n");
				break;
			
			case '2':
				//~ menuUtilisateur(fichier);
				printf("MODE USER\n");
				break;
				
			case 'q':
			case 'Q':
				printf("sorti du menu\n");
				break;
				
			default :
				printf("Commande inconnu [%c]\n",choix);
				break;
		}
		printf("\n\n");
	}while (choix != 'q' && choix != 'Q');
}

