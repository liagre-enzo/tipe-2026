#include "hand.h"

struct hand_s{
    card* data;
    int len;
    int len_data;
};

hand init_hand(card* data);

void free_hand(hand h);

int get_len_hand(hand h);

card access_hand(hand h, int i);

void set_hand(hand h, int i, card c);

void append_hand(hand h, card c);

void del_hand(hand h, int i);

card pop_hand(hand h, int i);