#ifndef __DECK_H__
#define __DECK_H__

#include "libraries.h"
#include "type.h"
#include "card.h"

typedef struct deck_s deck;

// Funcs

deck init_deck(card*);

void free_deck(deck);

int get_len_deck(deck);

card access_deck(deck, int);

void set_deck(deck, int, card);

void append_deck(deck, card);

void del_deck(deck, int);

card pop_deck(deck, int);;

#endif