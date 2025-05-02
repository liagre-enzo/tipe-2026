#ifndef __DECK_H__
#define __DECK_H__

#include "../libraries.h"
#include "type.h"
#include "card.h"

typedef struct deck_s* deck;

// Funcs

/*
O(1) amorti
Entree : aucune
Sortie : un deck
Pre-condition : aucune
Post-condition : le deck est constitué des cartes de 52 cartes
*/
deck init_deck();

/*
O(taille du deck)
Entree : un deck
Sortie : aucune
Pre-condition : aucune
Post-condition : le deck n'est plus accessible
*/
void free_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-conditon : le deck n'est pas vide
Post-condition : l'entier représente la taille du deck
*/
unsigned int get_len_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre d'As dans le deck
*/
unsigned int get_ace_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de Rois dans le deck
*/
unsigned int get_king_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de Reines dans le deck
*/
unsigned int get_queen_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de Valets dans le deck
*/
unsigned int get_jack_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de dix dans le deck
*/
unsigned int get_ten_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de neufs dans le deck
*/
unsigned int get_nine_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de huits dans le deck
*/
unsigned int get_eight_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de septs dans le deck
*/
unsigned int get_seven_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de six dans le deck
*/
unsigned int get_six_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de cinqs dans le deck
*/
unsigned int get_five_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de quatres dans le deck
*/
unsigned int get_four_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de trois dans le deck
*/
unsigned int get_three_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de deux dans le deck
*/
unsigned int get_two_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de cartes trefles dans le deck
*/
unsigned int get_club_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de cartes pics dans le deck
*/
unsigned int get_spade_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de cartes coeurs dans le deck
*/
unsigned int get_heart_count_deck(deck);

/*
O(1)
Entree : un deck
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de cartes carreaux dans le deck
*/
unsigned int get_diamond_count_deck(deck);

/*
O(1) amorti
Entree : un deck et un entier
Sortie : une carte
Pre-condition : le deck n'est pas vide et l'entier est strictement inférieur à la taille
Post-condition : la carte est une copie de celle dans le deck (i.e. doit être free)
*/
card access_deck(deck, unsigned int);

/*
O(1)
Entree : un deck, un entier et une carte
Sortie : aucune
Pre-condition : le deck n'est pas vide et l'entier est inférieur strictement à la taile
Post-condition : la carte qui a été dans le deck n'est plus accesible
*/
void set_deck(deck, unsigned int, card);

/*
O(1) amorti
Entree : un deck et une carte
Sortie : aucune
Pre-condition : le deck n'est pas vide
Post-condition : la taille du deck a augmenté de 1
*/
void append_deck(deck, card);

/*
O(taille du deck) (même remarque que dans hand.h)
Entree : un deck et un entier
Sortie : aucune
Pre-condition : le deck n'est pas vide et l'entier est inférieur strictement à la main 
Post-condition : la taille du deck a diminué de 1 et la carte à l'indice de l'entier n'est plus accessible
*/
void del_deck(deck, unsigned int);

/*
O(taille du deck) (idem)
Entree : un deck et un entier
Sortie : une carte
Pre-condition : le deck n'est pas vide et l'entier est inférieur strictement à la main
Post-condition : la taille du deck a diminué de 1 et la carte à l'indice de l'entier n'est plus dans le deck
*/
card pop_deck(deck, unsigned int);

/*
O(taille du deck)
Entree : un deck
Sortie : aucune
Pre-condition : le deck n'est pas vide
Post-condition : aucune
*/
void print_deck(deck);

#endif