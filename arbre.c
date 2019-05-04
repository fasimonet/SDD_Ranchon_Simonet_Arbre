#include "arbre.h"

int is_uppercase(char c)
{
	return (c > 64 && c < 91) ? 1 : 0;
}

char lower(char c)
{
	return is_uppercase(c) ? c + 32 : c;
}

int start_with(char * mot, char * motif)
{
	int i,
	    taille_motif = strlen(motif),
	    taille_mot = strlen(mot),
	    code_retour = 0;

	if ( taille_motif <= taille_mot )
	{
		for (i = 0; i < taille_motif && !code_retour; ++i )
		{
			if ( lower(mot[i]) != motif[i] )
			{
				code_retour = 1;
			}
		}
	}
	else
	{
		code_retour = 1;
	}

	return code_retour;
}

void afficher_mot(char * mot)
{
	int i,
	    taille = strlen(mot),
	    inc = 0;

	for (i = 0; i < taille; ++i, inc = 0)
	{
		if ( is_uppercase(mot[i]) )
		{
			inc = 32;
		}

		printf("%c", mot[i] + inc);
	}

	printf("\n");
}

/**************************************************************************/

noeud_t * init_arbre()
{
	return NULL;
}

noeud_t * creer_noeud(char c)
{
	noeud_t * nv = (noeud_t*) malloc(sizeof(noeud_t));

	if ( nv )
	{
		nv->val = c;
		nv->lv = NULL;
		nv->lh = NULL;
	}
	else
	{
		fprintf(stderr, "Erreur d'allocation mémoire.\n");
	}
	
	return nv;
}

noeud_t ** recherche_prec_horizontal(noeud_t ** prec, char c, int * existe)
{
	noeud_t * fils = *prec;

	while (fils && lower(fils->val) < c)
	{
		prec = &(fils->lh);
		fils = fils->lh;
	}

	*existe = (fils && lower(fils->val) == c) ? 1 : 0;

	return prec;
}

void inserer_noeud(noeud_t ** arbre, char * mot)
{
	noeud_t ** cour = arbre,
			** prec,
			*  nv;
	int        existe = 1,
		       i = 0,
		       taille = strlen(mot);

	while ( existe )
	{
		prec = recherche_prec_horizontal(cour, mot[i], &existe);

		if ( existe )
		{
			cour = &((*prec)->lv);
			++i;
		}
	}

	while ( i < taille )
	{
		if ( i == taille - 1 )
		{
			mot[i] -= 32;
		}

		nv = creer_noeud(mot[i]);

		nv->lh = *prec;
		*prec = nv;

		prec = &(nv->lv);
		++i;
	}
}

void liberer_arbre(noeud_t * arbre)
{
	noeud_t * cour = arbre,
	        * tmp;
	pile_t  * p = initialiser_pile(10);
	int       ok;

	while ( cour )
	{
		empiler(p, &ok, cour);

		cour = cour->lv;
		while ( !cour && !est_pile_vide(*p) )
		{
			depiler(p, &ok, &tmp);
			cour = tmp->lh;
			free(tmp);
		}
	}

	liberer_pile(p);
}

void liberer_dico(char ** dico, int taille)
{
	int i;

	for (i = 0; i < taille; ++i)
	{
		free(dico[i]);
	}

	free(dico);
}

void afficher_prefixe(noeud_t * noeud, char * motif)
{
	noeud_t * cour = noeud;
	pile_t  * p = initialiser_pile(10);
	int       ok;
	char      mot[30] = "";

	while ( cour )
	{
		empiler(p, &ok, cour);
		mot[strlen(mot)] = cour->val;

		if ( is_uppercase(cour->val) )
		{
			printf("%s", motif);
			afficher_mot(mot);
		}

		cour = cour->lv;

		while ( !cour && !est_pile_vide(*p) )
		{
			depiler(p, &ok, &cour);
			mot[strlen(mot)-1] = 0;

			cour = cour->lh;
		}
	}

	liberer_pile(p);
}

void afficher_motif(noeud_t ** arbre, char * motif)
{
	noeud_t ** cour = arbre,
			** prec;
	int        existe = 1,
		       i = 0,
		       taille = strlen(motif);

	while ( existe && i < taille )
	{
		prec = recherche_prec_horizontal(cour, motif[i], &existe);

		if ( existe )
		{
			cour = &((*prec)->lv);
			++i;
		}
	}

	if ( existe )
	{
		if ( is_uppercase((*prec)->val) )
		{
			printf("%s\n", motif);
		}

		afficher_prefixe((*prec)->lv, motif);
	}
}
