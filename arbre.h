/* ---------------------------------------------------------------------------------------------------- */
/* Nom du fichier : arbre.h                                                                            	*/
/* Date de creation : 05/05/2019                                                                     	*/
/* Auteurs : Flavio RANCHON et Fabien SIMONET (G21)                                                 	*/
/* Objectif : repertorier les prototypes des fonctions de manipulation d'arbre                          */
/* ---------------------------------------------------------------------------------------------------- */

#ifndef ARBRE_H
#define ARBRE_H

/* ------------------------------ */
/*     Inclusion des fichiers     */
/* ------------------------------ */
#include "pile.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* ------------------------------ */
/*   Déclaration des structures   */
/* ------------------------------ */
typedef struct maillon
{
	char val;
	struct maillon * lv;
	struct maillon * lh;
} noeud_t;

/* ------------------------------ */
/*   Déclaration des prototypes   */
/* ------------------------------ */
noeud_t* init_arbre();

noeud_t* creer_noeud(char val);

noeud_t** recherche_prec_horizontal(noeud_t ** prec, char val, int * existe);
noeud_t ** recherche_prec(noeud_t ** cour, int *existe, int *i, char *mot, int taille);

void inserer_noeud(noeud_t ** arbre, char mot[5]);

void liberer_arbre(noeud_t * arbre);
void liberer_dico(char ** dico, int taille);

void afficher_prefixe(noeud_t * noeud, char * motif);
void afficher_motif(noeud_t ** noeud, char motif[5]);

#endif
