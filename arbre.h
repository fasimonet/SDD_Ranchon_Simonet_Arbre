#ifndef ARBRE_H
#define ARBRE_H

#include "pile.h"
#include <stdio.h>
#include <string.h>

typedef struct maillon
{
	char val;
	struct maillon* lv;
	struct maillon* lh;
} noeud_t;

noeud_t* init_arbre();
noeud_t* creer_noeud(char val);
noeud_t** recherche_prec_horizontal(noeud_t ** prec, char val, int * existe);
void inserer_noeud(noeud_t ** arbre, char mot[5]);
noeud_t* liberer_arbre(noeud_t* arbre);
void afficher_prefixe(noeud_t *noeud);


#endif 
