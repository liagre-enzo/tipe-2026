#ifndef __HAND_H__
#define __HAND_H__

#include "libraries.h"
#include "type.h"
#include "card.h"

typedef struct hand_s* hand;

// Funcs

/*
O(1) amorti
Entree : aucune
Sortie : une carte
Pre-condition : aucune
Post-condition : la main ne contient aucune cartes
*/
hand init_hand();

/*
O(taille de la main)
Entree : une main
Sortie : aucune
Pre-condition : aucune
Post-condition : la main n'est plus accessible
*/
void free_hand(hand);

/*
O(1)
Entree : une main
Sortie : la taille
Pre-condition : La main n'est pas vide
Post-condition : aucune
*/
int get_len_hand(hand);

/*
O(1)
Entree : une main et un entier
Sortie : une cate
Pre-condition :la carte n'est ni vide ni taille nulle
Post-condition : aucune
*/
card access_hand(hand, int);

/*
O(1) amorti
Entree : une main un entier et une carte
Sortie : aucune
Pre-condition : la main n'est pas vide et l'entier vérifie les bornes de la main
Post-condition : la carte présente avant dans la main n'est plus accessible.
*/
void set_hand(hand, int, card);

/*
O(1) amorti
Entree : une main et une carte
Sortie : aucunne
Pre-condition : la main n'est pas vide
Post-condition : la taille de la main a augmenter de 1
*/
void append_hand(hand, card);

/*
O(taille de la main) (en réalité c'est du O(taille de la main - l'indice choisi))
Entree : une main et un entier
Sorti : rien
Pre-condition : la main n'est pas vide et l'entier vérifie les bornes de la main
Post-condition : la taille de la main a diminuée de 1 et la carte à l'indice choisi n'est plus accessible
*/
void del_hand(hand, int);

/*
O(taille de la main) (idem que précédemment)
Entree : une main et un entier
Sorti : une carte
Pre-condition : la main n'est pas vide et l'entier vérifie les bornes de la main
Post-condition : la taille de la main a diminuée de 1 la carte est celle de l'indice choisi
*/
card pop_hand(hand, int);

#endif