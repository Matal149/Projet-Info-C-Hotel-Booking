#include "../Headers/e_mail.h"
#include <stdio.h>
#include <string.h>
#define DEMANDE_CONFIRMATION 1

void afficherMail(email*mail);
void saisieMail(FILE *fichier);

//~ FILE*ouvrirReponse(char*nom_fichier)
//~ {
	//~ FILE*f=NULL;
	//~ printf("ouverture du fichier [%s]\n",nom_fichier);
//~ /* fopen mode a = append = "ajouter a la fin" ouvre le fichier s'il */
//~ /* existe et place le pointeur a la fin si le fichier n'existe pas  */
//~ /* le fichier est cree */
	//~ f=fopen(nom_fichier,"a");
	//~ fclose(f);
	//~ f=fopen(nom_fichier,"r+");
	//~ return f;	
//~ }

//~ void fermerReponse(FILE*fichier_ouvert)
//~ {
	//~ printf("fermeture du fichier\n");
	//~ fclose (fichier_ouvert);
//~ }

void saisieMail(FILE *fichier)
{
	email new_mail;
	char choix;
	
	printf("ajout mail\n");
	/*memset memory set , force la valeur d'un champs de donnees */
	memset(&new_mail,0,sizeof(new_mail));
	
	/* pour ajouter un nouveau client on le place a la fin*/
	fseek(fichier,0,SEEK_END);
	
	printf("saisir votre adresse : ");
	scanf("%s",new_mail.EM);
	printf("saisir objet : ");
	scanf(" %[^\t\n]s",new_mail.OBJ);
	printf("saisir corps mail : ");
	scanf(" %[^\t\n]s",new_mail.CORPS);
	getchar();
	
	afficherMail(&new_mail);
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
	fwrite(&new_mail,sizeof(email),1,fichier);
	printf("reponse cree\n");	
}

void afficherMail(email*mail)
{
	if(mail==NULL)return;
	printf("EM : %s\n",mail->EM);
	printf("OBJ : %s\n",mail->OBJ);
	printf("CORPS : %s\n",mail->CORPS);
}
