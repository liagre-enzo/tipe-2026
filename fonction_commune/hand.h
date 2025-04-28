#ifndef __HAND_H__
#define __HAND_H__

#include "libraries.h"
#include "type.h"
#include "card.h"

typedef struct hand_s* hand;

// Funcs

hand init_hand(card*);

void free_hand(hand);

int get_len_hand(hand);

card access_hand(hand, int);

void set_hand(hand, int, card);

void append_hand(hand, card);

void del_hand(hand, int);

card pop_hand(hand, int);

#endif