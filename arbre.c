#include "arbre.h"

char lower(char val)
{
	if ( val > 64 && val < 91  )
		val += 32;

	return val;
}

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

noeud_t** recherche_prec_horizontal(noeud_t ** prec, char val, int * existe)
{
	noeud_t * fils = *prec;

	while (fils && lower(fils->val) < val)
	{
		prec = &(fils->lh);
		fils = fils->lh;
	}

	*existe = (fils && lower(fils->val) == val) ? 1 : 0;

	return prec;
}

void inserer_noeud(noeud_t ** arbre, char mot[5])
{
	int existe, 
		i = 0, 
		taille = strlen(mot);

	noeud_t ** cour = arbre,
			** prec,
			*  nv;

	do
	{
		prec = recherche_prec_horizontal(cour, mot[i], &existe);

		if ( existe )
		{
			cour = &((*prec)->lv);
			++i;
		}
	} while ( existe );

	while ( i < taille )
	{
		if ( i == taille - 1 )
			mot[i] -= 32;

		nv = creer_noeud(mot[i++]);
		nv->lh = *prec;
		*prec = nv;
		prec = &(nv->lv);
	}
}

noeud_t* liberer_arbre(noeud_t* arbre)
{
	printf("%c\n", arbre->val);
	return NULL;
}

void afficher_prefixe(noeud_t * noeud)
{
	noeud_t * cour = noeud;

	pile_t * p = initialiser_pile(10);
	int ok;
	char mot[10] = "";

	while ( cour )
	{
		empiler(p, &ok, cour);
		mot[strlen(mot)] = cour->val;

		if ( cour->val > 64 && cour->val < 91 )
		{
			mot[strlen(mot)-1] = mot[strlen(mot)-1] + 32;
			printf("%s\n", mot);
		}

		cour = cour->lv;

		while ( !cour && !est_pile_vide(*p) )
		{
			depiler(p, &ok, &cour);
			mot[strlen(mot)-1] = 0;

			cour = cour->lh;
		}
	}
}
