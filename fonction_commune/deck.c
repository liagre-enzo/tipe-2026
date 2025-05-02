#include "deck.h"

struct deck_s{
    card* data;
    int len;
    int len_data;
};

deck init_deck();

void free_deck(deck d);

int get_len_deck(deck d);

card access_deck(deck d, int i);

void set_deck(deck d, int i, card c);

void append_deck(deck d, card c);

void del_deck(deck d, int i);

card pop_deck(deck d, int i);