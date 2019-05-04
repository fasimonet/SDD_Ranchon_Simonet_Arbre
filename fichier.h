#ifndef FICHIER_H
#define FICHIER_H

/* ------------------------------ */
/*     Inclusion des fichiers     */
/* ------------------------------ */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ------------------------------ */
/*   Déclaration des constantes   */
/* ------------------------------ */
#define TAILLE_MAX 100

/* ------------------------------ */
/*   Déclaration des prototypes   */
/* ------------------------------ */
int charger_fichier(char * name, char *** dico);

#endif