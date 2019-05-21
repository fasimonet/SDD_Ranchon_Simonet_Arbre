#include "arbre.h"
#include "fichier.h"
#include <stdio.h>

int main()
{
	int existe,
		i;
	char mot[TAILLE_MAX] = "c";

	noeud_t  * arbre,
			 * arbre_vide,
			 * arbre_a,
			 * arbre_c,
			 * arbre_a_c,
			 * arbre_artiste_lit,
			 * noeud3, 
			 ** prec,
			 ** prec1,
			 ** prec2;

	/* ---------------------------- */
	/* INITIALISATION DES VARIABLES */
	/* ---------------------------- */
	arbre_a_c = creer_noeud('c');
	mot[0] = 'a';
	inserer_mot(&arbre_a_c, mot);

	arbre_a = creer_noeud('a');

	arbre_artiste_lit = construction_arbre("fic_artiste_lit.txt");

	i = 0;

	/* -------------------------------- */
	/* TEST : initialisation de l'arbre */
	/* -------------------------------- */
	arbre_vide = init_arbre();

	/* ------------------------- */
	/* TEST : affichage d'un mot */
	/* ------------------------- */
	afficher_mot("bonjour");

	/* -------------------------- */
	/* TEST : creation d'un noeud */
	/* -------------------------- */
	arbre_c = creer_noeud('c');

	/* ----------------------------------------- */
	/* TEST : recherche horizontale du precedent */
	/* ----------------------------------------- */

	/* Cas 1 : Test du precedent parmi les freres (arbre vide) */
	prec = &arbre_vide;
	recherche_prec_horizontal(&prec, 'b', &existe);

	/* Cas 2 : Test du precedent parmi les freres (precedent en tete) */
	prec = &arbre_c;
	recherche_prec_horizontal(&prec, 'a', &existe);

	/* Cas 3 : Test du precedent parmi les freres (precedent au milieu) */
	prec = &arbre_a_c;
	recherche_prec_horizontal(&prec, 'b', &existe);

	/* Cas 4 : Test du precedent parmi les freres (precedent en fin) */
	prec = &arbre_a;
	recherche_prec_horizontal(&prec, 'b', &existe);

	/* Cas 5 : Test du precedent parmi les freres (element existe deja) */
	prec = &arbre_a_c;
	recherche_prec_horizontal(&prec, 'c', &existe);

	/* -------------------------------------------------------------------------------------------------- */
	/* TEST : recherche du precedent dans un arbre pour se positionner avant l'insertion d'un nouveau mot */
	/* -------------------------------------------------------------------------------------------------- */

	/* Cas 1 : Le mot existe deja dans l'arbre */
	prec = &arbre_artiste_lit;
	strcpy(mot, "art");
	prec = recherche_prec(prec, &existe, &i, mot, strlen(mot));

	/* Cas 2 : Le mot n'existe pas dans l'arbre */
	prec = &arbre_artiste_lit;
	strcpy(mot, "cru");
	prec = recherche_prec(prec, &existe, &i, mot, strlen(mot));

	/* PAS FINI MAIS JE (Fabien) LE FINIS MERCREDI */

	/* -------------------------------------------------------------------------------------------------- */
	/* La suite des tests */
	/* -------------------------------------------------------------------------------------------------- */

	/* A FINIR */

	arbre = construction_arbre("fic.txt");
	if ( arbre )
	{
		afficher_prefixe(arbre, "");

		printf("-----------\n");

		afficher_motif(arbre, "ban");

		liberer_arbre(arbre);

		arbre = init_arbre();
	}

	return 0;
}
