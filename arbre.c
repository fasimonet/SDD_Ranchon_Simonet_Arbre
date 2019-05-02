#include "arbre.h"

noeud_t* init_arbre()
{
	return NULL;
}

noeud_t* creer_noeud(char val)
{
	noeud_t * nv;
	nv = (noeud_t*) malloc(sizeof(noeud_t));
	if ( nv == NULL )
	{
		fprintf(stderr, "Erreur d'allocation mémoire.\n");
	}
	else
	{
		nv->val = val;
		nv->lv = NULL;
		nv->lh = NULL;
	}
	
	return nv;
}

noeud_t** recherche_prec_horizontal(noeud_t** prec, char val)
{
	noeud_t *fils = *prec;
	while (fils && fils->val < val)
	{
		fils = fils->lh;
		prec = &(fils->lh);
	}
	return prec;
}

noeud_t* liberer_arbre(noeud_t* arbre)
{

}

void afficher_prefixe(noeud_t * noeud)
{
	pile_t * p = initialiser_pile(10);
	int ok;

	while ( ! est_pile_vide(*p) || noeud != NULL )
	{
		printf(""FORMAT"\n", noeud->val);
		empiler(p, &ok, noeud->val);

		if ( ok )
		{
			noeud = noeud->lv;
			/*
			while ( noeud && !est_pile_vide(*p) )
			{
				depiler(p, &ok, &(noeud->val));
				if ( ok )
				{
					noeud = noeud->lh;
				}
			}
			*/
		}
	}
}



















