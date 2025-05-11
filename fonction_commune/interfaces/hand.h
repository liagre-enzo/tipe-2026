#ifndef __HAND_H__
#define __HAND_H__

#include "../libraries.h"
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
uint get_len_hand(hand);

/*
O(1)
Entree : une main, un entier
Sortie : un entier
Pre-condition : la main n'est pas vide et l'entier représente une carte
Post-condition : l'entier représente le nombre de cartes de valeur dans la main
*/
uint get_card_count_hand(hand, uint);

/*
O(1)
Entree : une main, une couleur
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de cartes de la couleur dans la main
*/
uint get_suit_count_hand(hand, suit);

/*
O(1) amorti
Entree : une main et un entier
Sortie : une cate
Pre-condition :la carte n'est pas vide et l'entier est strictement inférieur à la taille
Post-condition : la carte est une copie de celle dans la main (i.e. doit être free)
*/
card access_hand(hand, uint);

/*
O(1) amorti
Entree : une main un entier et une carte
Sortie : aucune
Pre-condition : la main n'est pas vide et l'entier est strictement inférieur à la taille
Post-condition : la carte présente avant dans la main n'est plus accessible.
*/
void set_hand(hand, uint, card);

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
Pre-condition : la main n'est pas vide et l'entier est strictement inférieur à la taille
Post-condition : la taille de la main a diminuée de 1 et la carte à l'indice choisi n'est plus accessible
*/
void del_hand(hand, uint);

/*
O(taille de la main) (idem que précédemment)
Entree : une main et un entier
Sorti : une carte
Pre-condition : la main n'est pas vide et l'entier est strictement inférieur à la taille
Post-condition : la taille de la main a diminuée de 1 la carte est celle de l'indice choisi
*/
card pop_hand(hand, uint);

/*
O(taille de la main)
Entree : une main, un tableau d'entier et un entier
Sortie : aucune
Pre-condition : la main n'est pas vide, le tableau d'entier est un tableau d'indices du deck, l'entier représente la taille du tableau, le tableau 
DOIT être rangé dans l'ordre croissant
Post-condition : les cartes aux indices du tableau ne sont plus accessibles
*/
void del_array_hand(hand, uint*, uint);

/*
O(taille de la main)
Entree : une main
Sortie : aucune
Pre-condition : la main n'est pas vide
Post-condition : aucune
*/
void print_hand(hand);

#endif