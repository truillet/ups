#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum valeur {SEPT=7, HUIT=8, NEUF=9, DIX=10, VALET=11, DAME=12, ROI=13, AS=14};
enum couleur {TREFLE=1, CARREAU, PIQUE, COEUR};

typedef struct carte
{
	enum valeur v;
	enum couleur c;
} Carte;


void initjeu(Carte[]);

/**
 *
 */
void initjeu(Carte jeu[]) 
{
    int i,j,carte;
	carte =0;
	for (i=SEPT;i<=AS;i++) {
		for (j=CARREAU;j<=COEUR;j++) {
			jeu[carte].c=j;
			jeu[carte].v=i;
			carte++;
		}
	}
}

/** 
  *
  */
char* toCouleur(int c) {
	char* valeur=malloc(10); /** allocation of 10 characters */
	
	switch (c) {
		case CARREAU:
			strcpy(valeur,"CARREAU");
			break;
		case PIQUE:
			strcpy(valeur,"PIQUE");
			break;
		case TREFLE:
			strcpy(valeur,"TREFLE");
			break;
		case COEUR:
			strcpy(valeur,"COEUR");
			break;
		default:
			strcpy(valeur,"UNDEFINED");
			break;
	}	
	return(valeur);
}

/** 
  *
  */
char* toValeur(int v) {
	char* valeur=malloc(10); /** allocation of 10 characters */
	
	switch (v) {
		case SEPT:
			strcpy(valeur,"SEPT");
			break;
		case HUIT:
			strcpy(valeur,"HUIT");
			break;
		case NEUF:
			strcpy(valeur,"NEUF");
			break;
		case DIX:
			strcpy(valeur,"DIX");
			break;
		case VALET:
			strcpy(valeur,"VALET");
			break;
		case DAME:
			strcpy(valeur,"DAME");
			break;
		case ROI:
			strcpy(valeur,"ROI");
			break;
		case AS:
			strcpy(valeur,"AS");
			break;			
		default:
			strcpy(valeur,"UNDEFINED");
			break;
	}	
	return(valeur);
}

/**
 * 
 */
void affiche_carte(Carte X) /* affiche une carte (valeur,couleur)*/
{
    printf("%s de %s\n", toValeur(X.v), toCouleur(X.c));
}

/**
 * 
 */
void affiche(Carte jeu[], int N) /* affiche N cartes */
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("Carte[%d] : ", i);
        affiche_carte(jeu[i]);
    }
}

/*
 *
 */
 int alea32() {
	 return(rand() % 32);
 }

/*
 *
 */
void permute(Carte *carte1, Carte *carte2) {
	Carte c;
	 
	/** permutation circulaire */
	c.v = carte1->v;
	c.c = carte1->c;
	carte1->v = carte2->v;
	carte1->c = carte2->c;
	carte2->v = c.v;
	carte2->c = c.c;
} 
 
/*
 *
 */
void melange(Carte jeu []) {
	int i;
	for (i=0;i<50;i++) {
		permute(&jeu[alea32()], &jeu[alea32()]);
	}
}
 
/*
 *
 */
 void distribue(Carte jeu[], Carte jeu1[], Carte jeu2[]) {
	int i;
	for (i=0;i<16;i++) {
		jeu1[i]=jeu[2*i];
		jeu2[i]=jeu[2*i + 1];
	}
 } 
 
/*
 *
 */
 void joue1coup(Carte jeu1[], Carte jeu2[], int *N1, int *N2) {
	/** comparer la première carte du tas */
	/** les ajouter au gagnant et mettre à jour le nombre de cartes */
	if (jeu1[0].v> jeu2[0].v) {
		// le joueur 1 a gagné
		printf("J1 gagne\n");
		// on recopie sa carte en dernière position
		// on ajoute la carte de l'adversaire
		jeu1[*N1] = jeu1[0];
		jeu1[*N1+1] = jeu2[0];
		// on met à jour les cartes
		*N1 = *N1+1;
		*N2 = *N2-1;
	}
	else {
		if (jeu1[0].v < jeu2[0].v) {
			printf("J2 gagne\n");
			// le joueur 2 a gagné
			jeu2[*N1] = jeu2[0];
			jeu2[*N1+1] = jeu1[0];
			// on met à jour les cartes
			*N1 = *N1-1;
			*N2 = *N2+1;
		}
		else { /**  ==, on compare les couleurs */
			if (jeu1[0].c> jeu2[0].c) {
				printf("J1 gagne par la couleur\n");
				// le joueur 1 a gagné
				jeu1[*N1] = jeu1[0];
				jeu1[*N1+1] = jeu2[0];
				// on met à jour les cartes
				*N1 = *N1+1;
				*N2 = *N2-1;
			}
			else { /** le joueur 2 a gagné */
				printf("J2 gagne par la couleur\n");
				jeu2[*N1] = jeu2[0];
				jeu2[*N1+1] = jeu1[0];
				// on met à jour les cartes
				*N1 = *N1-1;
				*N2 = *N2+1;
			}
		}
	}		
	/** déplacer les cartes */
	/** * de 1 à N, copier dans 0 à N-1 */
	int i;
	for (i=0;i<*N1-1;i++)
		jeu1[i] = jeu1[i+1];
	for (i=0;i<*N2-1;i++)
		jeu2[i] = jeu2[i+1];	
 }  
 
/**
  *
  */
int main(int argc, char *argv[])
{
    Carte jeu[32];
    Carte jeuJ1[32]; /** cartes du joueur 1 */
    Carte jeuJ2[32];
    int NJ1 = 16; /** Nombre de cartes du joueur 1 */
    int NJ2 = 16;
	srand((unsigned) time(NULL)); /** génération de la graine aléatoire */
    initjeu(jeu);
	melange(jeu);
	distribue(jeu,jeuJ1,jeuJ2);
    printf(" __ Jeu Joueur1 __\n");
	affiche(jeuJ1,16);	
    printf(" __ Jeu Joueur2 __\n");
	affiche(jeuJ2,16);	
	
	int NBcoups = 0;
	
	while ((NJ1 > 0) && (NJ2>0)) {
		joue1coup(jeuJ1, jeuJ2, &NJ1, &NJ2);
		NBcoups++;
		printf("J1 : %d cartes, J2 : %d cartes\n",NJ1,NJ2);
	}
	if (NJ1 ==0) {
		printf("Le joueur 2 a gagné");		
	}
	else
		printf("Le joueur 1 a gagné");
	printf(" en %d coups\n",NBcoups);
	
    return 0;
}
