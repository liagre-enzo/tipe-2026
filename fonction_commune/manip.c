#include "manip.h"
#include "interfaces/type.h"

uint leq_poker_hand(poker_hand p1, poker_hand p2){
    switch (p2){
        case flush_five:
            return 1;

        case flush_house:
            return p1 != flush_five;

        case five_kind:
            return p1 != flush_five && p1 != flush_house;

        case royal_flush:
            return p1 != flush_five && p1 != flush_house && p1 != five_kind;

        case straight_flush:
            return p1 != flush_five && p1 != flush_house 
            && p1 != five_kind && p1 != royal_flush;

        case four_kind:
            return p1 != flush_five && p1 != flush_house && p1 != five_kind 
            && p1 != royal_flush && p1 != straight_flush;

        case full_house:
            return p1 != flush_five && p1 != flush_house && p1 != five_kind 
            && p1 != royal_flush && p1 != straight_flush && p1 != four_kind;

        case flush:
            return p1 == high_card || p1 == pair || p1 == two_pair 
            || p1 == three_kind || p1 == straight_flush || p1 == flush;

        case straight:
            return p1 == high_card || p1 == pair || p1 == two_pair 
            || p1 == three_kind || p1 == straight_flush;

        case three_kind:
            return p1 == high_card || p1 == pair || p1 == two_pair 
            || p1 == three_kind;

        case two_pair:
            return p1 == high_card || p1 == pair || p1 == two_pair;

        case pair:
            return p1 == high_card || p1 == pair;

        case high_card:
            return p1 == high_card;

    }
}

