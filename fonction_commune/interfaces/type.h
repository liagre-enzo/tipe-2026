#ifndef __TYPE_H__
#define __TYPE_H__

// Enums
enum suit_e {
    heart,
    diamond,
    spade,
    club
};

enum poker_hand_e {
    flsuh_five,      //x16
    flush_house,     //x14
    five_kind,       //x12
    royal_flush,     //x8
    straight_flush,  //x8
    four_kind,       //x7
    full_house,      //x4
    flush,           //x4
    straight,        //x4
    three_kind,      //x3
    two_pair,        //x2
    pair,            //x2
    high_card        //x1
};

// Aliases
typedef enum suit_e suit;

typedef enum poker_hand_e poker_hand;

#endif