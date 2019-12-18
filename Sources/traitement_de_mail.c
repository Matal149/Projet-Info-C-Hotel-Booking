#include "../Headers/reponses.h"
#include <stdio.h>
#include <string.h>
#define DEMANDE_CONFIRMATION 1

void afficherMail(email*mail);
email saisieMail(FILE *fichier);
void envoiReponseMail(FILE *fichier_reponses, email mailRecu, FILE* fichier_mailEnvoyes);

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

email saisieMail(FILE *fichier)
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
	printf("saisir l'adresse du destinataire : ");
	scanf("%s",new_mail.DEST);
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


void envoiReponseMail(FILE* fichier_reponses, email mailRecu, FILE* fichier_mailEnvoyes)
{
	REPONSE reponse_automatique;
	email new_mail;
	//~ char choix;
	
	printf("envoi reponse mail\n");
	/*memset memory set , force la valeur d'un champs de donnees */
	memset(&new_mail,0,sizeof(new_mail));
	
	memset(&reponse_automatique,0,sizeof(reponse_automatique));
	
	/* pour ajouter un nouveau client on le place a la fin*/
	fseek(fichier_reponses,0,SEEK_SET);
	
	//~ while(fread(&reponse,sizeof(REPONSE),1,fichier_reponses)!=0)
	//~ {
		//~ printf("CACA\n");
		//~ if(strstr(mailRecu.CORPS, *reponse.keyword.villes) != NULL){
			//~ *new_mail.EM = *mailRecu.DEST;
			//~ *new_mail.DEST = *mailRecu.EM;
			//~ *new_mail.CORPS = *reponse.reponse.CORPS;
			//~ fwrite(&new_mail,sizeof(email),1,fichier_mailEnvoyes);
			//~ printf("reponse trouve\n");
			//~ return;
		//~ }
	//~ }
	printf("CORPS MAIL RECU = %s\n", mailRecu.CORPS);
	while(fread(&reponse_automatique,sizeof(REPONSE),1,fichier_reponses)!=0)
	{	
		if(strstr(mailRecu.CORPS, *reponse_automatique.keyword.villes) != NULL)
		{
			//~ *new_mail.EM = *mailRecu.DEST;
			strcat(new_mail.EM , mailRecu.DEST);

			//~ *new_mail.DEST = *mailRecu.EM;
			//~ strcpy(new_mail.OBJ, "RE : ");
			strcat(new_mail.DEST , mailRecu.EM);
			
			strcpy(new_mail.OBJ, "RE : ");
			strcat(new_mail.OBJ , mailRecu.OBJ);
			
			//~ *new_mail.CORPS = *reponse_automatique.reponse.CORPS;
			strcat(new_mail.CORPS , reponse_automatique.reponse.CORPS);
			fwrite(&new_mail,sizeof(email),1,fichier_mailEnvoyes);
			afficherMail(&new_mail);
			printf("reponse trouve\n");
			return;
		}
	}
	
/* si on est arrive ici on n'a donc pas trouver le client */	
	printf("Reponse introuvable \n");
}
