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
	REPONSE new_reponse;
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
	
	afficherreponse(&new_reponse);
	if( DEMANDE_CONFIRMATION == 1)
	{
		printf("confirmer l'ajout de reponse? ( Y/n ) : ");
		scanf("%c",&choix);getchar();
		if( choix == 'n' || choix == 'N')
		{
			printf("abandon creation de reponse \n");
			return;
		}
	}
	fwrite(&new_reponse,sizeof(REPONSE),1,fichier);
	printf("reponse cree\n");	
}

void affiche(FILE *fichier)
{
	REPONSE reponse;
	char keyword_recherche[TAILLE_KEYWORD];
	
	printf("affiche\n");
	printf("saisi du mot cle a rechercher : ");
	scanf("%s",keyword_recherche);getchar();			
}
	
/*positionnement du curseur au debut du ficher */
	fseek(fichier ,0,SEEK_SET);
/* on va lire des CLIENT du fichier un par un jusqua la fin du fichier*/
	while(fread(&reponse,sizeof(REPONSE),1,fichier)!=0)
	{	

			if(strcmp(keyword_recherche,reponse.keyword)==0)
			{
				printf("reponse trouve\n");
				afficherreponse(&reponse);
				return;
			}
		
	}
/* si on est arrive ici on n'a donc pas trouver le client */	
	printf("Reponse introuvable \n");
	
}

void lister(FILE *fichier)
{
	REPONSE reponse;
	int nombre_reponse=0;
	printf("lister\n");
	/*positionnement du curseur au debut du ficher */
	fseek(fichier ,0,SEEK_SET);
/* on va lire des CLIENT du fichier un par un jusqua la fin du fichier*/
	while(fread(&reponse,sizeof(REPONSE),1,fichier)!=0)
	{	
		afficherreponse(&reponse);
		nombre_reponse++;
	}
/* non demander par l'exo mais c'est facile a compter */
	printf("il y a %d clients\n",nombre_client);
}

void affichercoordonnees(REPONSE*reponse)
{
	if(reponse==NULL)return;
	printf("mot cle : %s\n",reponse->keyword);
	printf("Reponse : %s\n",reponse->reponse);
}