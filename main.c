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
			 * arbre_insertion,
			 ** prec;

	/* ---------------------------- */
	/* INITIALISATION DES VARIABLES */
	/* ---------------------------- */
	arbre_a_c = creer_noeud('c');
	mot[0] = 'a';
	inserer_mot(&arbre_a_c, mot);

	arbre_a = creer_noeud('a');

	arbre_artiste_lit = construction_arbre("fic_artiste_lit.txt");

	arbre_insertion = init_arbre();

	i = 0;

	/* -------------------------------- */
	/* TEST : initialisation de l'arbre */
	/* -------------------------------- */
	arbre_vide = init_arbre();

	/* ------------------------- */
	/* TEST : affichage d'un mot */
	/* ------------------------- */
	afficher_mot("boNjouR");

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

	/* -------------------------------------------------------------------------------------------------- */
	/* TEST : Insertion d'un nouveau mot */
	/* -------------------------------------------------------------------------------------------------- */

	/* Cas 1 : Insertion d'un premier element dans un arbre vide */
	prec = &arbre_insertion;
	strcpy(mot, "lit");
	inserer_mot(prec, mot);

	/* Cas 2 : Insertion d'un mot en tête d'un arbre non vide */
	strcpy(mot, "artiste");
	inserer_mot(prec, mot);

	/* Cas 3 : Insertion d'un mot au milieu dans arbre non vide */
	strcpy(mot, "bruit");
	inserer_mot(prec, mot);

	/* Cas 4 : Insertion d'un mot en fin dans arbre non vide */
	strcpy(mot, "velo");
	inserer_mot(prec, mot);

	/* Cas 5 : Insertion d'un mot déjà existant dans arbre non vide */
	strcpy(mot, "bruit");
	inserer_mot(prec, mot);

	/* Cas 6 : Insertion d'un mot ayant une racine déjà existante dans l'arbre */
	strcpy(mot, "lire");
	inserer_mot(prec, mot);

	/* Cas 7 : Insertion d'un mot d'un caractère */
	strcpy(mot, "y");
	inserer_mot(prec, mot);


	/* ------------------------ */
	/* TEST : Affichage prefixe */
	/* ------------------------ */

	/* Cas 1 : Arbre vide */
	printf("Debut affichage arbre vide\n");
	afficher_prefixe(arbre_vide, "");
	printf("Fin affichage arbre vide\n");

	/* Cas 2 : Arbre non vide */
	printf("Debut affichage arbre non vide\n");
	afficher_prefixe(arbre_artiste_lit, "");
	printf("Fin affichage arbre non vide\n");


	/* ------------------------ */
	/* TEST : Affichage motif   */
	/* ------------------------ */

	/* Cas 1 : Aucun mot ne contient le motif */
	printf("Recherche du motif 'football' :\n");
	afficher_motif(arbre_insertion, "football");
	printf("Fin de la recherche du motif 'football'\n");

	/* Cas 2 : Au moins 1 mot contient le motif */
	printf("Recherche du motif 'li' :\n");
	afficher_motif(arbre_insertion, "li");
	printf("Fin de la recherche du motif 'li'\n");
	
	/* Cas 3 : Le motif est un mot */
	printf("Recherche du motif 'lire' :\n");
	afficher_motif(arbre_insertion, "lire");
	printf("Fin de la recherche du motif 'lire'\n");


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
