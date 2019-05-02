#include "arbre.h"
#include <stdio.h>

int main(int argc, char ** argv)
{
	noeud_t * arbre = init_arbre();
	noeud_t * nouveau = creer_noeud('a');

	arbre = nouveau;
	afficher_prefixe(arbre);

	return 0;
}
