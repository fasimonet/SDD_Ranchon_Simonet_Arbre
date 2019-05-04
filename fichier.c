#include "fichier.h"

int charger_fichier(char * name, char *** dico)
{
	char chaine[TAILLE_MAX];
	int taille = -1,
	    i;
	FILE * fe = fopen(name, "r");

	if ( fe )
	{
		fscanf(fe, "%d ", &taille);

		*dico = (char **) malloc(sizeof(char *) * taille);

		for (i = 0; i < taille; ++i)
		{
			fscanf(fe, "%s ", chaine);
			
			if ( chaine[strlen(chaine)-1] == '\n' )
			{
				chaine[strlen(chaine)-1] = 0;
			}

			(*dico)[i] = (char *) malloc(sizeof(char) * strlen(chaine));
			strcpy((*dico)[i], chaine);
		}
		fclose(fe);
	}

	return taille;
}