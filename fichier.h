/* ---------------------------------------------------------------------------------------------------- */
/* Nom du fichier : fichier.h                                                                           */
/* Date de creation : 05/05/2019                                                                     	*/
/* Auteurs : Flavio RANCHON et Fabien SIMONET (G21)                                                 	*/
/* Objectif : repertorier les prototypes des fonctions de fichier                          		*/
/* ---------------------------------------------------------------------------------------------------- */

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
