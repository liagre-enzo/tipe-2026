#include "card.h"
#include "type.h"
#include <stdio.h>

struct card_s {
    uint value; // an integer in [1, 13] where 11 is the jack, etc
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

uint get_val(card c){
    assert (c != NULL);
    return c->value;
}

suit get_suit(card c){
    assert (c != NULL);
    return c->color;
}

card copy_card(card c){
    assert(c != NULL);
    card new = malloc(sizeof(struct card_s));
    new->color = c->color;
    new->value = c->value;
    return new;
}

void print_card(card c){
    assert(c != NULL);
    if(c->value < 11){
        printf("%d", c->value);
    }
    else{
        if(c->value == 11){
            printf("J");
        }
        else if(c->value == 12){
            printf("Q");
        }
        else if(c->value == 13){
            printf("K");
        }
    }

    if(c->color == spade){
        printf("S");
    }
    else if(c->color == club){
        printf("C");
    }
    else if(c->color == heart){
        printf("H");
    }
    else if(c->color == diamond){
        printf("D");
    }
}

