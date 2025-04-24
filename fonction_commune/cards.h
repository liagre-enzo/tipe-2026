#ifndef __CARTES_H__
#define __CARTES_H__

#include "libraries.h"

enum suit_e {
    heart,
    diamond,
    spade,
    club
};

typedef enum suit_e suit;

struct carte_s {
    int valeur; // an integer in [1, 13] where 11 is the jack, etc
    suit color;
};
typedef struct carte_s carte;

enum hand_e {
    flsuh_five,      //16
    flush_house,     //14
    five_kind,       //12
    royal_flush,     //8
    straight_flush,  //8
    four_kind,       //7
    full_house,      //4
    flush,           //4
    straight,        //4
    three_kind,      //3
    two_pair,        //2
    pair,            //2
    high_card        //1
};

typedef enum hand_e hand;

hand best_hand(carte[8]);



#endif