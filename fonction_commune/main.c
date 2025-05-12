#include "interfaces/deck.h"
#include "interfaces/hand.h"
#include <stdio.h>

int main(){
    deck d = init_deck();

    print_deck(d);
    printf("\n");

    uint sort[52] = {
        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
        26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
        26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
    };

    array_sort_deck(d, sort, 52);

    print_deck(d);
    printf("\n");

    sort_deck(d);

    print_deck(d);
    printf("\n");

    uint pioche[8] = {7, 9, 16, 20, 31, 39,44, 51};
    
    hand h = to_hand_deck(d, pioche, 8);

    print_hand(h);
    printf("\n\n");

    print_deck(d);
    printf("\n");

    free_deck(d);
    free_hand(h);
    
    return 0;
}