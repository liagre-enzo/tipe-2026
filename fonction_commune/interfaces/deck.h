#ifndef __DECK_H__
#define __DECK_H__

#include "../libraries.h"
#include "type.h"
#include "card.h"
#include "hand.h"

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
uint get_len_deck(deck);

/*
O(1)
Entree : un deck, un entier
Sortie : un entier
Pre-condition : le deck n'est pas vide et l'entier représente une carte
Post-condition : l'entier représente le nombre de cartes de valeur dans le deck
*/
uint get_card_count_deck(deck, uint);

/*
O(1)
Entree : un deck, une couleur
Sortie : un entier
Pre-condition : le deck n'est pas vide
Post-condition : l'entier représente le nombre de cartes de valeur dans le deck
*/
uint get_suit_count_deck(deck d, suit col);

/*
O(1) amorti
Entree : un deck et un entier
Sortie : une carte
Pre-condition : le deck n'est pas vide et l'entier est strictement inférieur à la taille
Post-condition : la carte est une copie de celle dans le deck (i.e. doit être free)
*/
card access_deck(deck, uint);

/*
O(1)
Entree : un deck, un entier et une carte
Sortie : aucune
Pre-condition : le deck n'est pas vide et l'entier est inférieur strictement à la taile
Post-condition : la carte qui a été dans le deck n'est plus accesible
*/
void set_deck(deck, uint, card);

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
void del_deck(deck, uint);

/*
O(taille du deck) (idem)
Entree : un deck et un entier
Sortie : une carte
Pre-condition : le deck n'est pas vide et l'entier est inférieur strictement à la main
Post-condition : la taille du deck a diminué de 1 et la carte à l'indice de l'entier n'est plus dans le deck
*/
card pop_deck(deck, uint);

/*
O(taille du deck)
Entree : un deck, un tableau d'entier et un entier
Sortie : aucune
Pre-condition : le deck n'est pas vide, le tableau d'entier est un tableau d'indices du deck, l'entier représente la taille du tableau, le tableau 
DOIT être rangé dans l'ordre croissant
Post-condition : les cartes aux indices du tableau ne sont plus accessibles
*/
void del_array_deck(deck, uint*, uint);

/*
Même fonction que précédement mais transforme les cartes supprimées en main
O(taille du deck)
Entree : un deck, un tableau d'entier et un entier
Sortie : une main
Pre-condition : le deck n'est pas vide, le tableau d'entier est un tableau d'indices du deck, l'entier représente la taille du tableau, le tableau 
DOIT être rangé dans l'ordre croissant
Post-condition : les cartes aux indices du tableau sont placées dans une main
*/
hand to_hand_deck(deck, uint*, uint);

/*
O(taille du deck)
Entree : un deck
Sortie : aucune
Pre-condition : le deck n'est pas vide
Post-condition : aucune
*/
void print_deck(deck);

#endif