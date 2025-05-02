#ifndef __CARD_H__
#define __CARD_H__

#include "../libraries.h"
#include "type.h"

typedef struct card_s* card;

// Funcs

/*
O(1) amorti
Entree : Un entier et une couleur
Sortie : une carte
Pre-condition : L'entier appartient l'intervalle entier [1, 13]
Post-condition : aucune
*/
card init_card(int, suit);


/*
O(1) amorti
Entree : une carte
Sortie : rien
Pre-condition : la carte n'est pas nulle
Post-condition : la carte n'est plus accessible
*/
void free_card(card);


/*
O(1)
Entree : une carte
Sortie : un entier
Pre-condition : la carte n'est pas nulle
Post-condition : l'entier représente la valeur de la carte
*/
unsigned int get_val(card);

/*
O(1)
Entree : une carte
Sortie : une couleur
Pre-condition : la carte n'est pas nulle
Post-condition : la couleur de la carte
*/
suit get_suit(card);

/*
O(1) amorti
Entree : une carte
Sortie : une carte
Pre-condition : la carte n'est pas vide
Post-condition : la carte est copié
*/
card copy_card(card);

/*
O(1)
Entree : une carte
Sortie : aucune
Pre-condition : la carte n'est pas vide
Post-condition : les données de la carte sont affichées
*/
void print_card(card);

#endif