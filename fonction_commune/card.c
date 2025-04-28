#include "card.h"

struct card_s {
    int value; // an integer in [1, 13] where 11 is the jack, etc
    suit color;
};


card init_card(int val, suit col){
    card c = malloc(sizeof(struct card_s));
    assert(c != NULL);

    c->color = col;
    if(val % 14 == 0){
        c->value = 1;
    } 
    else{
        c->value = val % 14;
    }

    return c;
}

void free_card(card c){
    if (c != NULL){
        free(c);
    }
}

int get_val(card c){
    assert (c != NULL);
    return c->value;
}

suit get_suit(card c){
    assert (c != NULL);
    return c->color;
}

