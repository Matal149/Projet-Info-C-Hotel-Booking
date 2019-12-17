/*
 * mainHotelBooking.c
 * 
 */


#include <stdio.h>
#include "../Headers/gestion_de_fichier.h"
#include "../Headers/e_mail.h"
#include "../Headers/keywords.h"

void menu(FILE *fichier);

int main(int argc, char **argv)
{
	/* Test fontion gestion_de_fichier.c*/
	//~ FILE*fichier_coordonnes=NULL;
	//~ fichier_coordonnes = ouvrir("coordonnees.bin");
	//~ ajout(fichier_coordonnes);
	//~ affiche(fichier_coordonnes);
	//~ lister(fichier_coordonnes);
	
	
	//~ menu(fichier_compte);
	
	return 0;
}



void menu(FILE *fichier)
{
	char choix;
	do
	{
		printf("Ajouter d'un nouveau client............: A\n");
		printf("Consultation d'un compte client........: C\n");
		printf("Lister tous les comptes de clients.....: L\n");
		printf("Opération sur un compte client.........: O\n");
		printf("Quitter................................: Q\n");
		printf(" votre choix: ");

		scanf("%c",&choix);
		getchar();
		
		switch(choix)
		{
			case 'a':
			case 'A': 
				ajout(fichier);
				break;
			
			case 'c':
			case 'C':
				affiche(fichier);
				break;
				
			case 'l':
			case 'L':
				lister(fichier);
				break;
			
			case 'o':
			case 'O':
				operation(fichier);
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

