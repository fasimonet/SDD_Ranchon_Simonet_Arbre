#include "arbre.h"
#include "fichier.h"
#include <stdio.h>

int main()
{
	noeud_t * arbre = init_arbre();
	char ** dico;
	int taille, i;

	taille = charger_fichier("fic.txt", &dico);

	for (i = 0; i < taille; ++i)
	{
		inserer_noeud(&arbre, dico[i]);
	}

	afficher_prefixe(arbre);

	return 0;
}
