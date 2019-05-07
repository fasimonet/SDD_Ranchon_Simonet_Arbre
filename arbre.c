#include "arbre.h"

/* ---------------------------------------------------------------------------------------------------- */
/* Nom du fichier : arbre.c                                                                             */
/* Date de creation : 05/05/2019                                                                        */
/* Auteurs : Flavio RANCHON et Fabien SIMONET (G21)                                                     */
/* Objectif : manipuler les arbres                                                                      */
/* Fonctions :                                                                                          */
/*  - afficher_mot                                                                                   	*/
/*  - init_arbre                                                                                      	*/
/*  - creer_noeud                                                                                     	*/
/*  - recherche_prec_horizontal                                                                       	*/
/*  - inserer_noeud											*/
/*  - liberer_arbre											*/
/*  - liberer_dico											*/
/*  - afficher_prefixe											*/
/*  - afficher_motif											*/
/* ---------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------------------------- */
/* afficher_mot         			Affiche un mot           				*/
/*                                                                                                      */
/* En entree:                                                                                           */
/*     * mot 	le mot a afficher									*/
/*                                                                                                      */
/* En sortie:                                                 						*/
/*	Aucune sortie                                                              			*/
/*													*/
/* Principe:                                                                                           	*/
/*      Pour chaque lettre du mot à afficher                                                            */
/*      	Si la lettre est en majuscule                                                        	*/
/*			Mettre cette lettre en minuscule						*/
/*		Fsi											*/
/*		Afficher cette lettre									*/
/*	Fait												*/
/*                                                                                                      */
/* Lexique:                                                                                            	*/
/*      i	compteur pour incrementer les lettres du mot a afficher                          	*/
/*	taille	taille du mot a afficher								*/
/*	inc	element permettant de modifier le code ASCII d'une lettre afin de 			*/
/*		la mettre en minuscule									*/
/* ---------------------------------------------------------------------------------------------------- */
void afficher_mot(char * mot)
{
	int i,
	    taille = strlen(mot);

	for (i = 0; i < taille; ++i)
	{
		printf("%c", tolower(mot[i]));
	}

	printf("\n");
}
/* ---------------------------------------------------------------------------------------------------- */
/* initialiser_file         			Initialise un arbre           				*/
/*                                                                                                      */
/* En entree:                                                                                           */
/*      Aucune entrée                                   						*/
/*                                                                                                      */
/* En sortie: 												*/
/*	Un pointeur sur une structure de type noeud_t                                          		*/
/*                                                                                                      */
/* Principe:                                                                                           	*/
/*      Au départ un arbre n'a aucun noeud donc un renvoie une structure nulle				*/
/*                                                                                                      */
/* Lexique:                                                                                            	*/
/*      Aucune variable                                                     				*/
/* ---------------------------------------------------------------------------------------------------- */
noeud_t * init_arbre()
{
	return NULL;
}

/* ---------------------------------------------------------------------------------------------------- */
/* creer_noeud         			Cree un noeud de l'arbre           				*/
/*                                                                                                      */
/* En entree:                                                                                           */
/*      c 	la lettre que le nouveau noeud doit contenir						*/
/*                                                                                                      */
/* En sortie:                                                 						*/
/*	Un pointeur vers le nouveau noeud                                                              	*/
/*													*/
/* Principe:                                                                                           	*/
/*      Allouer la memoire pour un element de type noeud_t et recuperer le pointeur vers cette memoire 	*/
/*      Si le pointeur pointe sur une zone memoire existante                                      	*/
/*		Initialiser la lettre dans le nouveau noeud avec le caractere passe en parametre	*/
/*		Initialiser le lien vertical a nul							*/
/*		Initialiser le lien horizontal a nul							*/		
/*      Sinon                                                                                           */
/*         	Ecrire une erreur                     							*/
/*	Fsi												*/
/*                                                                                                      */
/* Lexique:                                                                                            	*/
/*    * nv	Un pointeur vers le nouveau noeud alloue                      				*/
/* ---------------------------------------------------------------------------------------------------- */
noeud_t * creer_noeud(char c)
{
	noeud_t * nv = (noeud_t *) malloc(sizeof(noeud_t));

	if ( nv )
	{
		nv->val = c;
		nv->lv  = NULL;
		nv->lh  = NULL;
	}
	else
	{
		fprintf(stderr, "Erreur d'allocation mémoire.\n");
	}
	
	return nv;
}

/* ---------------------------------------------------------------------------------------------------- */
/* recherche_prec_horizontal         	Recherche le precedent d'un noeud parmi les freres 		*/
/*						    dans une branche d'un arbre           		*/
/*                                                                                                      */
/* En entree:                                                                                           */
/*   ** prec 	un pointeur vers un pointeur de noeud							*/
/*	c	le caractere du noeud dont on cherche le precedent					*/
/*    * existe	booleen pour savoir si le noeud dont on cherche le precedent existe			*/
/*                                                                                                      */
/* En sortie:                                                 						*/
/*	Un pointeur vers le pointeur sur le precedent                                       		*/
/*													*/
/* Principe:                                                                                           	*/
/*      Initialiser le noeud fils                                                               	*/
/*      Tant que le noeud courant n'est pas nul et alors que la valeur du noeud fils est inferieure au 	*/
/*	caractere recherche                                                              		*/
/*      	Avancer le precedent sur le lien horizontal                                           	*/
/*      	Avancer le noeud fils sur le lien horizontal                     			*/
/*	Fait												*/
/*	Si le noeud fils existe et que la valeur du noeud correspond au caractere recherche		*/
/*		Mettre le booleen existe a vrai								*/
/*	Sinon												*/
/*		Mettre le booleen existe a faux								*/
/*	Fsi												*/
/*	Retourner le precedent										*/
/*                                                                                                      */
/* Lexique:                                                                                            	*/
/*    * fils	pointeur vers le noeud courant                                                     	*/
/* ---------------------------------------------------------------------------------------------------- */
noeud_t ** recherche_prec_horizontal(noeud_t ** prec, char c, int * existe)
{
	noeud_t * cour = *prec;

	while (cour && tolower(cour->val) < c)
	{
		prec = &(cour->lh);
		cour =   cour->lh;
	}

	*existe = (cour && tolower(cour->val) == c);

	return prec;
}

/* ---------------------------------------------------------------------------------------------------- */
/* recherche_prec         	Recherche le precedent d'un noeud dans un arbre	 			*/
/*						               						*/
/*                                                                                                      */
/* ---------------------------------------------------------------------------------------------------- */
noeud_t ** recherche_prec(noeud_t ** cour, int *existe, int *i, char *mot, int taille)
{
	noeud_t ** prec = NULL;

	while ( *existe && *i < taille )
	{
		prec = recherche_prec_horizontal(cour, mot[*i], existe);

		if ( *existe )
		{
			cour = &((*prec)->lv);
			++(*i);
		}
	}

	return prec;
}

/*************************************************************************************************************/


void inserer_noeud(noeud_t ** arbre, char * mot)
{
	noeud_t ** prec,
			*  nv;
	int        existe = 1,
		       i = 0,
		       taille = strlen(mot);

	prec = recherche_prec(arbre, &existe, &i, mot, taille);

	/* Si le mot existe déjà, alors on met la dernière (pointé par prec) en majuscule */
	if ( i == taille )
	{
		(*prec)->val = toupper((*prec)->val);
	}
	else
	{
		/* Le mot n'existe pas donc on met la dernière lettre en majuscule et on insère le reste du mot */
		mot[taille-1] = toupper(mot[taille-1]);
		while ( i < taille )
		{
			nv = creer_noeud(mot[i]);

			nv->lh = *prec;
			*prec = nv;

			prec = &(nv->lv);

			++i;
		}
	}
}

/* ---------------------------------------------------------------------------------------------------- */
/* liberer_arbre         			Libere un arbre           				*/
/*                                                                                                      */
/* En entree:                                                                                           */
/*	taille	le nombre de mots dans le dictionnaire							*/ 
/*                                                                                                      */
/* En sortie:                                                 						*/
/*	Aucune sortie                                                              			*/
/*													*/
/* Principe:                                                                                           	*/
/*	Initialiser une pile										*/
/*	Tant que le noeud courant n'est pas nul								*/
/*		Empiler le noeud courant								*/
/*		Descendre le noeud courant sur le lien vertical						*/
/*		Tant que le noeud courant est nul et que la pile n'est pas vide				*/
/*			Depiler 									*/
/*			Definir le noeud courant sur le lien horizontal de du noeud depile		*/
/*			Liberer le noeud depile								*/
/*		Fait											*/
/*	Liberer la pile											*/
/*                                                                                                      */
/* Lexique:                                                                                            	*/
/*    * cour	pointeur vers le noeud courant                                                     	*/
/*    * tmp	pointeur vers le noeud permettant de recuperer les noeuds depiles			*/
/*    * p	pointeur vers la pile									*/
/*	ok	booleen pour verifier le bon deroulement de l'empilement et du depilement 		*/
/* ---------------------------------------------------------------------------------------------------- */
void liberer_arbre(noeud_t * arbre)
{
	noeud_t * cour = arbre,
	        * tmp;
	pile_t  * p = initialiser_pile(10);
	int       ok;

	while ( cour )
	{
		empiler(p, &ok, cour);

		cour = cour->lv;
		while ( !cour && !est_pile_vide(*p) )
		{
			depiler(p, &ok, &tmp);
			cour = tmp->lh;
			free(tmp);
		}
	}

	liberer_pile(p);
}

/* ---------------------------------------------------------------------------------------------------- */
/* liberer_dico         		Libere un dictionnaire de mots           			*/
/*                                                                                                      */
/* En entree:                                                                                           */
/*   ** dico	un dictionnaire de mots a liberer							*/
/*	taille	le nombre de mots dans le dictionnaire							*/ 
/*                                                                                                      */
/* En sortie:                                                 						*/
/*	Aucune sortie                                                              			*/
/*													*/
/* Principe:                                                                                           	*/
/*      Pour chaque ligne (<=> mot) dans le dictionnaire                                          	*/
/*          Liberer la ligne (<=> le mot)                                                           	*/
/*      Fait                                                                                           	*/
/*      Liberer le dictionnaire                    							*/
/*													*/
/* Explications complémentaires:									*/
/*	Ici on a un tableau contenant plusieurs tableaux. 						*/
/*	Il faut donc liberer tous les tableaux contenus dans le tableau principal.			*/
/*	Et enfin supprimer le tableau principal.							*/
/*                                                                                                      */
/* Lexique:                                                                                            	*/
/*      Aucune variable                                                     				*/
/* ---------------------------------------------------------------------------------------------------- */
void liberer_dico(char ** dico, int taille)
{
	int i;

	for (i = 0; i < taille; ++i)
	{
		free(dico[i]);
	}

	free(dico);
}

void afficher_prefixe(noeud_t * noeud, char * motif)
{
	noeud_t * cour = noeud;
	pile_t  * p = initialiser_pile(10);
	int       ok;
	char      mot[30] = "";

	while ( cour )
	{
		empiler(p, &ok, cour);
		mot[strlen(mot)] = cour->val;

		if ( isupper(cour->val) )
		{
			printf("%s", motif);
			afficher_mot(mot);
		}

		cour = cour->lv;

		while ( !cour && !est_pile_vide(*p) )
		{
			depiler(p, &ok, &cour);
			mot[strlen(mot)-1] = 0;

			cour = cour->lh;
		}
	}

	liberer_pile(p);
}

void afficher_motif(noeud_t ** arbre, char * motif)
{
	noeud_t ** prec;
	int        existe = 1,
			   i = 0,
			   taille = strlen(motif);

	prec = recherche_prec(arbre, &existe, &i, motif, taille);

	if ( existe )
	{
		if ( isupper((*prec)->val) )
		{
			printf("%s\n", motif);
		}

		afficher_prefixe((*prec)->lv, motif);
	}
}
