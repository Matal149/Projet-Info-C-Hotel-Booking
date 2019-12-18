#include "../Headers/gestion_de_fichier.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
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
	COORDONNEES new_coordonnees;
	char choix;
	
	printf("Ajout d'un nouveau client à la base de données\n");
	/*memset memory set , force la valeur d'un champs de donnees */
	memset(&new_coordonnees,0,sizeof(new_coordonnees));
	
	/* pour ajouter un nouveau client on le place a la fin*/
	fseek(fichier,0,SEEK_END);
	
	printf("saisir le nom du client: ");
	scanf("%s",new_coordonnees.nom);
	printf("saisir le prenom du client: ");
	scanf("%s",new_coordonnees.prenom);
	printf("saisir l'adresse e-mail du client: ");
	scanf("%s",new_coordonnees.adresse_mail);
	
	do{
	printf("saisir l'importance du client [0;1] : ");
	scanf("%f",&new_coordonnees.importance);
	}while(new_coordonnees.importance <0 || new_coordonnees.importance >1);
	
	getchar();
	
	affichercoordonnees(&new_coordonnees);
	if( DEMANDE_CONFIRMATION == 1)
	{
		printf("Confirmer l'ajout du client à la base? ( Y/n ) : ");
		scanf("%c",&choix);getchar();
		if( choix == 'n' || choix == 'N')
		{
			printf("Abandon de l'ajout du client à la base de données \n");
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
	printf("Affiche les informations d'un client en fonction d'un critère de recherche\n");
	
	printf("Choix du critere de recherche d'un client :\n");
	printf("1 : nom | 2 prenom \n");
	scanf("%c",&choix);getchar();
	switch(choix)
	{
		case '1':
			printf("saisi du nom du client à rechercher dans la BDD: ");
			scanf("%s",nom_recherche);getchar();
			break;
			
		case '2':
			printf("saisi du prenom du client à rechercher dans la BDD : ");
			scanf("%s",prenom_recherche);getchar();
			break;
			
		default :
			printf("Critere de recherche inconnu : abandon \n");
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
				//~ printf("coordonnees trouve\n");
				affichercoordonnees(&coordonnees);
				return;
			}
		}
		else if ( choix == '2')
		{
			if(strcmp(prenom_recherche,coordonnees.prenom)==0)
			{
				//~ printf("coordonnees trouve\n");
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
	printf("lister les coordonnes des clients de la base de données\n");
	/*positionnement du curseur au debut du ficher */
	fseek(fichier ,0,SEEK_SET);
/* on va lire des CLIENT du fichier un par un jusqua la fin du fichier*/
	while(fread(&coordonnees,sizeof(COORDONNEES),1,fichier)!=0)
	{	
		affichercoordonnees(&coordonnees);
		nombre_client++;
	}
	printf("il y a %d clients\n",nombre_client);
}

void affichercoordonnees(COORDONNEES*coordonnees)
{
	if(coordonnees==NULL)return;
	printf("Nom du client: %s\n",coordonnees->nom);
	printf("Prenom du client: %s\n",coordonnees->prenom);
	printf("Adresse mail du client: %s\n",coordonnees->adresse_mail);
	printf("Importance du client : %f\n",coordonnees->importance);
}


void supprimerCoordonnes(FILE* fichier){
	COORDONNEES coordonnees;
	char nom_recherche[TAILLE_NOM];
	char prenom_recherche[TAILLE_NOM];
	char choix;
	char const *old_FileName = "coordonnees.bin";
    char *new_FileName = "coordonnees2.bin";
	FILE *new_FileCoordonnees=NULL;
	new_FileCoordonnees = ouvrir(new_FileName);

	printf("Supprimer un client de la base de données\n");
	
	printf("choix du critere de recherche pour supprimer une coordonnee :\n");
	printf("1 : nom | 2 prenom \n");
	scanf("%c",&choix);getchar();
	switch(choix)
	{
		case '1':
			printf("saisi du nom à supprimer : ");
			scanf("%s",nom_recherche);
			getchar();
			break;
			
		case '2':
			printf("saisi du prenom a rechercher : ");
			scanf("%s",prenom_recherche);
			getchar();
			break;
			
		default :
			printf("critere inconnu : abandon \n");
			return;
	}
	
/*positionnement du curseur au debut du ficher */
	fseek(fichier ,0,SEEK_SET);
/* on va lire des coordonnées CLIENT du fichier un par un jusqu'à la fin du fichier*/
	while(fread(&coordonnees,sizeof(COORDONNEES),1,fichier)!=0)
	{	
/* pour chaque mode de recherche on va appliquer la bonne comparaison*/
		if(choix == '1')
		{
			if((strcmp(nom_recherche,coordonnees.nom)==0) || (strcmp(prenom_recherche,coordonnees.prenom)==0))
			{
				printf("coordonnees trouvees donc on ne fait rien\n");
			}
		}
		else
		{
			fwrite(&coordonnees,sizeof(COORDONNEES),1,new_FileCoordonnees);
		}	
	}
	fermer(fichier);
	fermer(new_FileCoordonnees);
	remove(old_FileName);
    rename(new_FileName, old_FileName);
    ouvrir("coordonnees.bin");
/* si on est arrive ici on n'a donc pas trouver le client */	
	printf("Client introuvable \n");
}
