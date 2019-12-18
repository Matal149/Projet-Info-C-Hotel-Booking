#include "e_mail.h"
#include <stdio.h>
#include <string.h>

void afficherMail(email*mail);
email saisieMail(FILE *fichier);
void envoiReponseMail(FILE *fichier_reponses, email mailRecu, FILE* fichier_mailEnvoyes);

