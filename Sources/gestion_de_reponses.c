#include "../Headers/reponses.h"
#include <stdio.h>
#include <string.h>
#define DEMANDE_CONFIRMATION 0

FILE*ouvrir(char*nom_fichier)
{
	FILE*f=NULL;
	printf("ouverture du fichier [%s]\n",nom_fichier);
/* fopen mode a = append = "ajouter a la fin" ouvre le fichier s'il */
/* existe et place le pointeur a la fin si le fichier n'existe pas  */
/* le fichier est cree */
	f=fopen(nom_fichier,"a");
	fclose(f);
	f=fopen(nom_fichier,"r+");
	return f;	
}

void fermer(FILE*fichier_ouvert)
{
	printf("fermeture du fichier\n");
	fclose (fichier_ouvert);
}

void ajout(FILE *fichier)
{
	REPONSE new_coordonnees;
	char choix;
	
	printf("ajout\n");
	/*memset memory set , force la valeur d'un champs de donnees */
	memset(&new_reponse,0,sizeof(new_reponse));
	
	/* pour ajouter un nouveau client on le place a la fin*/
	fseek(fichier,0,SEEK_END);
	
	printf("saisir mot cle : ");
	scanf("%s",new_reponse.keyword);
	printf("saisir reponse : ");
	scanf("%s",new_reponse.reponse);
	getchar();
	
	affichercoordonnees(&new_coordonnees);
	if( DEMANDE_CONFIRMATION == 1)
	{
		printf("confirmer l'ajout de coordonnees? ( Y/n ) : ");
		scanf("%c",&choix);getchar();
		if( choix == 'n' || choix == 'N')
		{
			printf("abandon creation de coordonnees \n");
			return;
		}
	}
	fwrite(&new_coordonnees,sizeof(COORDONNEES),1,fichier);
	printf("coordonnees cree\n");	
}

void affiche(FILE *fichier)
{
	COORDONNEES coordonnees;
	char nom_recherche[TAILLE_NOM];
	char prenom_recherche[TAILLE_NOM];
	char choix;
	printf("affiche\n");
	
	printf("choix du critere de recherche d'un client :\n");
	printf("1 : nom | 2 prenom \n");
	scanf("%c",&choix);getchar();
	switch(choix)
	{
		case '1':
			printf("saisi du nom a rechercher : ");
			scanf("%s",nom_recherche);getchar();
			break;
			
		case '2':
			printf("saisi du prenom a rechercher : ");
			scanf("%s",prenom_recherche);getchar();
			break;
			
		default :
			printf("critere inconnu : abandon \n");
			return;
	}
	
/*positionnement du curseur au debut du ficher */
	fseek(fichier ,0,SEEK_SET);
/* on va lire des CLIENT du fichier un par un jusqua la fin du fichier*/
	while(fread(&coordonnees,sizeof(COORDONNEES),1,fichier)!=0)
	{	
/* pour chaque mode de recherche on va appliquer la bonne comparaison*/
		if(choix == '1')
		{
			if(strcmp(nom_recherche,coordonnees.nom)==0)
			{
				printf("coordonnees trouve\n");
				affichercoordonnees(&coordonnees);
				return;
			}
		}
		else if ( choix == '2')
		{
			if(strcmp(prenom_recherche,coordonnees.prenom)==0)
			{
				printf("coordonnees trouve\n");
				affichercoordonnees(&coordonnees);
				return;
			}
		}
	}
/* si on est arrive ici on n'a donc pas trouver le client */	
	printf("Client introuvable \n");
	
}

void lister(FILE *fichier)
{
	COORDONNEES coordonnees;
	int nombre_client=0;
	printf("lister\n");
	/*positionnement du curseur au debut du ficher */
	fseek(fichier ,0,SEEK_SET);
/* on va lire des CLIENT du fichier un par un jusqua la fin du fichier*/
	while(fread(&coordonnees,sizeof(COORDONNEES),1,fichier)!=0)
	{	
		affichercoordonnees(&coordonnees);
		nombre_client++;
	}
/* non demander par l'exo mais c'est facile a compter */
	printf("il y a %d clients\n",nombre_client);
}

void affichercoordonnees(COORDONNEES*coordonnees)
{
	if(coordonnees==NULL)return;
	printf("nom : %s\n",coordonnees->nom);
	printf("prenom : %s\n",coordonnees->prenom);
	printf("adresse mail : %s\n",coordonnees->adresse_mail);
}
