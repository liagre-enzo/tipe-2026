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
unsigned int get_len_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre d'As dans la main
*/
unsigned int get_ace_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de Rois dans la main
*/
unsigned int get_king_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de Reines dans la main
*/
unsigned int get_queen_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de Valets dans la main
*/
unsigned int get_jack_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de dix dans la main
*/
unsigned int get_ten_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de neufs dans la main
*/
unsigned int get_nine_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de huits dans la main
*/
unsigned int get_eight_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de septs dans la main
*/
unsigned int get_seven_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de six dans la main
*/
unsigned int get_six_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de cinqs dans la main
*/
unsigned int get_five_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de quatres dans la main
*/
unsigned int get_four_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de trois dans la main
*/
unsigned int get_three_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de deux dans la main
*/
unsigned int get_two_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de cartes trefles dans la main
*/
unsigned int get_club_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de cartes pics dans la main
*/
unsigned int get_spade_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de cartes coeurs dans la main
*/
unsigned int get_heart_count_hand(hand);

/*
O(1)
Entree : une main
Sortie : un entier
Pre-condition : la main n'est pas vide
Post-condition : l'entier représente le nombre de cartes carreaux dans la main
*/
unsigned int get_diamond_count_hand(hand);

/*
O(1) amorti
Entree : une main et un entier
Sortie : une cate
Pre-condition :la carte n'est pas vide et l'entier est strictement inférieur à la taille
Post-condition : la carte est une copie de celle dans la main (i.e. doit être free)
*/
card access_hand(hand, unsigned int);

/*
O(1) amorti
Entree : une main un entier et une carte
Sortie : aucune
Pre-condition : la main n'est pas vide et l'entier est strictement inférieur à la taille
Post-condition : la carte présente avant dans la main n'est plus accessible.
*/
void set_hand(hand, unsigned int, card);

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
void del_hand(hand, unsigned int);

/*
O(taille de la main) (idem que précédemment)
Entree : une main et un entier
Sorti : une carte
Pre-condition : la main n'est pas vide et l'entier est strictement inférieur à la taille
Post-condition : la taille de la main a diminuée de 1 la carte est celle de l'indice choisi
*/
card pop_hand(hand, unsigned int);

/*
O(taille de la main)
Entree : une main
Sortie : aucune
Pre-condition : la main n'est pas vide
Post-condition : aucune
*/
void print_hand(hand);

#endif