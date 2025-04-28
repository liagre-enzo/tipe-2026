#ifndef __CARD_H__
#define __CARD_H__

#include "libraries.h"
#include "type.h"

typedef struct card_s* card;

// Funcs

card init_card(int, suit);

void free_card(card);

int get_val(card);

suit get_suit(card);

#endif