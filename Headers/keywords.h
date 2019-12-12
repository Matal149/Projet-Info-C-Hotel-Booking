
#define NB_VILLES 10
#define TAILLE_VILLES 20

typedef struct{
	char villes[NB_VILLES][TAILLE_VILLES];// = {"Toulon", "Paris", "Lyon", "Poitiers", "Orange", "Toulouse", "Caen", "Marseille", "Rouen", "Troyes"};
	//char villes[NB_VILLES][TAILLE_VILLES] = {{"Toulon"}, {"Paris"}, {"Lyon"}, {"Poitiers"}, {"Orange"}, {"Toulouse"}, {"Caen"}, {"Marseille"}, {"Rouen"}, {"Troyes"}};
	char types_resrvation[10][25];// = {"week-end","weekend", "week end", "vacances"}; 
}KEYWORDS;
