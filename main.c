#include "arbre.h"
#include <stdio.h>

int main(/*int argc, char ** argv*/)
{
	noeud_t * arbre = init_arbre();
	char mot[5] = "azer";
	char mot2[5] = "qsdf";
	char mot3[5] = "arbre";

	inserer_noeud(&arbre, mot);
	inserer_noeud(&arbre, mot2);
	inserer_noeud(&arbre, mot3);

	afficher_prefixe(arbre);

	return 0;
}
