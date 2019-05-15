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
noeud_t * construction_arbre(char * name)
{
	char chaine[TAILLE_MAX];
	FILE * fe = fopen(name, "r");
	noeud_t * arbre = init_arbre();

	if ( fe )
	{
		while ( !feof(fe) )
		{
			fscanf(fe, "%s ", chaine);
			
			if ( chaine[strlen(chaine)-1] == '\n' )
			{
				chaine[strlen(chaine)-1] = 0;
			}

			inserer_mot(&arbre, chaine);
		}
		fclose(fe);
	}
	else
	{
		fprintf(stderr, "Fichier '%s' inexistant\n", name);
	}

	return arbre;
}
