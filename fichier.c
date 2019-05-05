#include "fichier.h"

/* ---------------------------------------------------------------------------------------------------- */
/* charger_fichier         Charge le contenu d'un fichier dans un dictionnaire de mots            	*/
/*                                                                                                      */
/* En entree:                                                                                           */
/*    * name 	le nom du fichier a charger								*/
/*  *** dico	le dictionnaire a remplir								*/
/*                                                                                                      */
/* En sortie:                                                 						*/
/*	le nombre de mots dans le dictionnaire                                                        	*/
/*													*/
/* Principe:                                                                                           	*/
/*      Ouvrir le fichier en lecture                                                              	*/
/*	Si l'ouverture du fichier s'est bien deroulee							*/
/*		Lire la taille du fichier								*/
/*		Allouer la memoire du dictionnaire et recuperer le pointeur vers cette memoire		*/
/*		Pour chaque ligne du fichier								*/
/*			Lire le mot 									*/
/*			Si un retour chariot a ete lu a la fin du mot					*/
/*				Le remplacer par un delimiteur de fin de mot				*/
/*			Fsi										*/
/*			Allouer la memoire d'un mot du dictionnaire et recuperer le pointeur vers 	*/
/*			cette memoire									*/
/*			Copier le mot lu precedemment dans le mot dont la memoire vient d'etre allouee	*/
/*		Fait											*/
/*		Fermer le fichier									*/
/*	Fsi												*/
/*	Retourner le nombre de mots du dictionnaire							*/
/*													*/
/* Lexique:                                                                                            	*/
/*      chaine	tableau pour lire les mots du fichiers                         				*/
/*	taille	nombre de mots dans le dictionnaire							*/
/*	i	compteur pour l'incrementation de la boucle pour					*/
/* ---------------------------------------------------------------------------------------------------- */
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
