#define TAILLE_CORPS 200
#define TAILLE_OBJET 60
#define TAILLE_MAIL 40

typedef struct
{
	char EM[TAILLE_MAIL];
	char OBJ[TAILLE_OBJET];
	char CORPS[TAILLE_CORPS];	
}email;
