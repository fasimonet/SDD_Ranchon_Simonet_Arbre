#include "arbre.h"
#include "fichier.h"
#include <stdio.h>

int main()
{
	noeud_t  * arbre = construction_arbre("fic.txt");

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
