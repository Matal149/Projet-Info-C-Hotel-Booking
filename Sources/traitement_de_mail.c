#include "../Headers/reponses.h"
#include <stdio.h>
#include <string.h>
#define DEMANDE_CONFIRMATION 1

void afficherMail(email*mail);
email saisieMail(FILE *fichier);
void envoiReponseMail(FILE *fichier_reponses, email mailRecu, FILE* fichier_mailEnvoyes);


/* Fonction de saisir un mail */
email saisieMail(FILE *fichier)
{
	email new_mail;
	char choix;
	
	printf("ajout mail\n");
	/*memset memory set , force la valeur d'un champs de donnees */
	memset(&new_mail,0,sizeof(new_mail));
	
	/* pour ajouter un nouveau client on le place a la fin*/
	fseek(fichier,0,SEEK_END);
	
	do
	{
		printf("saisir votre adresse : ");
		scanf("%s",new_mail.EM);
	}while((strstr(new_mail.EM, "@") == NULL) );
	
	do
	{
		printf("saisir l'adresse du destinataire : ");
		scanf("%s",new_mail.DEST);
	}while((strstr(new_mail.DEST, "@") == NULL) );
	
	printf("saisir objet : ");
	scanf(" %[^\t\n]s",new_mail.OBJ);
	printf("saisir corps mail : ");
	scanf(" %[^\t\n]s",new_mail.CORPS);
	getchar();
	
	//~ afficherMail(&new_mail);
	if( DEMANDE_CONFIRMATION == 1)
	{
		printf("confirmer l'envoit du mail? ( Y/n ) : ");
		scanf("%c",&choix);getchar();
		if( choix == 'n' || choix == 'N')
		{
			printf("abandon creation de mail \n");
			return;
		}
	}
	fwrite(&new_mail,sizeof(email),1,fichier);
	printf("mail envoyé\n");
	return new_mail;
}

/* Fonction permettant d'afficher les informations composant un mail */
void afficherMail(email*mail)
{
	if(mail==NULL)return;
	printf("Affiche mail\n");
	printf("EM : %s\n",mail->EM);
	printf("DEST : %s\n",mail->DEST);
	printf("OBJ : %s\n",mail->OBJ);
	printf("CORPS : %s\n",mail->CORPS);
	printf("\n\n\n");
}

/* Fonction permettant d'envoyer une réponse type si un mot clé est détecter dans le corps du mail reçu */
void envoiReponseMail(FILE* fichier_reponses, email mailRecu, FILE* fichier_mailEnvoyes)
{
	REPONSE reponse_automatique;
	email new_mail;	
	printf("Envoi d'un mail de réponse automatique\n");
	memset(&new_mail,0,sizeof(new_mail));
	memset(&reponse_automatique,0,sizeof(reponse_automatique));
	fseek(fichier_reponses,0,SEEK_SET);

	//~ printf("CORPS MAIL RECU = %s\n", mailRecu.CORPS);
	while(fread(&reponse_automatique,sizeof(REPONSE),1,fichier_reponses)!=0)
	{
		if((strstr(mailRecu.CORPS, *reponse_automatique.keyword.villes) != NULL) || (strstr(mailRecu.OBJ, *reponse_automatique.keyword.villes) != NULL))
		{
			strcat(new_mail.EM , mailRecu.DEST);
			strcat(new_mail.DEST , mailRecu.EM);
			strcpy(new_mail.OBJ, "RE : ");
			strcat(new_mail.OBJ , mailRecu.OBJ);
			strcat(new_mail.CORPS , reponse_automatique.reponse.CORPS);
			fwrite(&new_mail,sizeof(email),1,fichier_mailEnvoyes);
			afficherMail(&new_mail);
			return;
		}
	}
	
/* si on est arrive ici on n'a donc pas trouver de mot clé pour générer une réponse favorable */	
	printf("Reponse introuvable \n");
	strcat(new_mail.EM , mailRecu.DEST);
	strcat(new_mail.DEST , mailRecu.EM);
	strcpy(new_mail.OBJ, "RE : ");
	strcat(new_mail.OBJ , mailRecu.OBJ);
	strcat(new_mail.CORPS , REPONSE_DEFAVORABLE_MAIL);
	fwrite(&new_mail,sizeof(email),1,fichier_mailEnvoyes);
	afficherMail(&new_mail);
}
