/*
 * mainHotelBooking.c
 * 
 */


#include <stdio.h>
#include "../Headers/gestion_de_fichier.h"
//~ #include "../Headers/e_mail.h"
//~ #include "../Headers/keywords.h"
#include "../Headers/reponses.h"

void menuGeneral(FILE* fichier_coordonnees, FILE* fichier_keywords);

int main(int argc, char **argv)
{
	/* Test fontion gestion_de_fichier.c*/
	FILE*fichier_coordonnees=NULL;
	FILE*fichier_keywords=NULL;

	fichier_coordonnees = ouvrir("coordonnees.bin");
	fichier_keywords = ouvrirReponse("reponses.bin");
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
				char choix1;
				printf("Ajouter une nouvelle coordonnees............: A\n");
				printf("Consultation d'une coordonnees..............: C\n");
				printf("Lister toutes les coordonnees...............: L\n");
				printf("Ajouter une nouvelle reponse................: R\n");
				printf("Consultation d'une reponse..................: F\n");
				printf("Lister toutes les reponses..................: D\n");
				printf("Quitter et revenir au menu antérieur........: Q\n");
				printf(" votre choix: ");

				scanf("%c",&choix1);
				getchar();
				
				switch(choix1)
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

