#include "deck.h"
#include "card.h"
#include "hand.h"
#include <stdio.h>

struct deck_s{
    card* data;
    uint len;
    uint len_data;

    // compteur pour chaque carte / couleur
    uint* card_count;
};

void change_card_count_deck(deck d, uint value, int k){
    d->card_count[value - 1] += k;
}

void change_suit_count_deck(deck d, suit s, int k){
    if(s == club){
        d->card_count[13] += k;
    }
    else if (s == heart){
        d->card_count[14] += k;
    }
    else if (s == spade){
        d->card_count[15] += k;
    }
    else{
        d->card_count[16] += k;
    }
}

void swit_deck(deck arr, uint i, uint j){
    card tmp = arr->data[i];
    arr->data[i] = arr->data[j];
    arr->data[j] = tmp;
}

uint leq_deck(card c1, card c2){
    uint boolean = 0;
    switch(get_suit(c2)){
        case club:
            if(get_suit(c1) == club){
                boolean = 1;
            }
            break;
        case heart:
            if(get_suit(c1) == club || get_suit(c1) == heart){
                boolean = 1;
            }
            break;
        case spade:
            if(get_suit(c1) == club || get_suit(c1) == heart || get_suit(c1) == spade){
                boolean = 1;
            }
            break;
        default:
            boolean = 1;
    }
    return get_val(c1) < get_val(c2) || (get_val(c1) == get_val(c2) && boolean);
}

int partition_deck(deck arr, int start, int stop){
    int k = start;
    for (int i = start; i < stop; i++){
        if (leq_deck(arr->data[i], arr->data[stop])){
            swit_deck(arr, k, i);
            k++;
        }
    }
    swit_deck(arr, k, stop);
    return k;
}

void quick_sort_deck(deck arr, int start, int stop){
    if(start < stop){
        int pivot = partition_deck(arr, start, stop);
        quick_sort_deck(arr, start, pivot - 1);
        quick_sort_deck(arr, pivot + 1, stop);
    }
}

// Fonctions d'interface

deck init_deck(){
    deck d = malloc(sizeof(struct deck_s));
    assert(d != NULL);

    d->len = 52;
    d->len_data = 60;
    d->data = malloc(60*sizeof(card));
    assert(d->data != NULL);
    
    d->card_count = malloc(17 * sizeof(uint));
    assert(d->card_count != NULL);

    for (uint i = 0; i < 13; i++){
        d->data[i] = init_card(i+1, club);
        d->data[i + 13] = init_card(i+1, heart);
        d->data[i + 26] = init_card(i+1, spade);
        d->data[i + 39] = init_card(i+1, diamond);
        d->card_count[i] = 4;
    }

    d->card_count[13] = 13;
    d->card_count[14] = 13;
    d->card_count[15] = 13;
    d->card_count[16] = 13;

    return d;
}

void free_deck(deck d){
    if (d != NULL){
        for(uint i = 0; i < d->len; i++){
            free_card(d->data[i]);
        }
        free(d->card_count);
        free(d->data);
        free(d);
    }
}

uint get_len_deck(deck d){
    assert(d != NULL);
    return d->len;
}

uint get_card_count_deck(deck d, uint value){
    assert(d != NULL);
    return d->card_count[value -1];
}

uint get_suit_count_deck(deck d, suit col){
    assert(d != NULL);
    if(col == club){
        return d->card_count[13];
    }
    else if (col == spade){
        return d->card_count[14];
    }
    else if (col == heart){
        return d->card_count[15];
    }
    return d->card_count[16];
}

card access_deck(deck d, uint i){
    assert(d != NULL && i < d->len);
    return copy_card(d->data[i]);
}

void set_deck(deck d, uint i, card c){
    assert(d != NULL && i < d->len);
    
    card tmp = d->data[i];
    change_card_count_deck(d, get_val(tmp), -1);
    change_suit_count_deck(d, get_suit(tmp), -1);

    d->data[i] = copy_card(c);
    free(tmp);

    change_card_count_deck(d, get_val(c), 1);
    change_suit_count_deck(d, get_suit(c), 1);
}

void append_deck(deck d, card c){
    assert(d != NULL);
    
    if (d->len >= d->len_data){
        card* tmp = malloc(2*(d->len_data)*sizeof(card));
        assert(tmp != NULL);
        
        for (uint i = 0; i < d->len; i++){
            tmp[i] = d->data[i];
        }
        
        free(d->data);
        d->data = tmp;
        d->len_data *= 2;
    }
    
    d->data[d->len] = copy_card(c);
    d->len ++;

    change_card_count_deck(d, get_val(c), 1);
    change_suit_count_deck(d, get_suit(c), 1);
}

void del_deck(deck d, uint i){
    assert(d != NULL && i < d->len);
    
    if (d->len-1 <= d->len_data / 4){
        card* tmp_arr = malloc(((d->len_data)/2)*sizeof(card));
        assert(tmp_arr != NULL);
        
        for(uint j = 0; j < d->len; j++){
            tmp_arr[i] = d->data[i];
        }
        
        d->len_data /= 2;
        free(d->data);
        d->data = tmp_arr;
    }

    card tmp = d->data[i];

    change_card_count_deck(d, get_val(tmp), -1);
    change_suit_count_deck(d, get_suit(tmp), -1);

    for(uint j = i; j < d->len - 1; j++){
        d->data[j] = d->data[j + 1];
    }
    
    free(tmp);
    d->len --;
}

card pop_deck(deck d, uint i){
    assert(d != NULL && i < d->len);

    if (d->len-1 <= d->len_data / 4){
        card* tmp_arr = malloc(((d->len_data)/2)*sizeof(card));
        assert(tmp_arr != NULL);
        
        for(uint j = 0; j < d->len; j++){
            tmp_arr[i] = d->data[i];
        }
        
        d->len_data /= 2;
        free(d->data);
        d->data = tmp_arr;
    }

    card tmp = d->data[i];
    for(uint j = i; j < d->len - 1; j++){
        d->data[j] = d->data[j + 1];
    }
    
    d->len --;
    
    change_card_count_deck(d, get_val(tmp), -1);
    change_suit_count_deck(d, get_suit(tmp), -1);
    
    return tmp;
}

void del_array_deck(deck d, uint* arr, uint len_arr){
    assert(d != NULL && len_arr < d->len);
    if(len_arr == 1){
        del_deck(d, arr[0]);
    }

    if (d->len-len_arr <= d->len_data / 4){
        card* tmp_arr = malloc(((d->len_data)/2)*sizeof(card));
        assert(tmp_arr != NULL);
        
        for (uint i = 0, i_tmp=0, i_arr = 0; i < d->len; i++){
            if(i == arr[i_arr]){
                change_card_count_deck(d, get_val(d->data[i]), -1);
                change_suit_count_deck(d, get_suit(d->data[i]), -1);
                free(d->data[i]);
                i_arr = (i_arr + 1) % len_arr;
            }
            else{
                tmp_arr[i_tmp] = d->data[i];
                i_tmp++;
            }
        }

        d->len_data /= 2;
        free(d->data);
        d->data = tmp_arr;
    }
    
    else{
        for (uint i = 0, i_tmp=0, i_arr = 0; i < d->len; i++){
            if(i == arr[i_arr]){
                change_card_count_deck(d, get_val(d->data[i]), -1);
                change_suit_count_deck(d, get_suit(d->data[i]), -1);
                free(d->data[i]);
                i_arr = (i_arr + 1) % len_arr;
            }
            else{
                d->data[i_tmp] = d->data[i];
                i_tmp++;
            }
        }
    }

    d->len = d->len - len_arr;
}

hand to_hand_deck(deck d, uint* arr, uint len_arr){
    assert(d != NULL && len_arr < d->len);
    if(len_arr == 1){
        del_deck(d, arr[0]);
    }
    hand main = init_hand();

    if (d->len-len_arr <= d->len_data / 4){
        card* tmp_arr = malloc(((d->len_data)/2)*sizeof(card));
        assert(tmp_arr != NULL);
        
        for (uint i = 0, i_tmp=0, i_arr = 0; i < d->len; i++){
            if(i == arr[i_arr]){
                change_card_count_deck(d, get_val(d->data[i]), -1);
                change_suit_count_deck(d, get_suit(d->data[i]), -1);
                append_hand(main, d->data[i]);
                free(d->data[i]);
                i_arr = (i_arr + 1) % len_arr;
            }
            else{
                tmp_arr[i_tmp] = d->data[i];
                i_tmp++;
            }
        }

        d->len_data /= 2;
        free(d->data);
        d->data = tmp_arr;
    }
    
    else{
        for (uint i = 0, i_tmp=0, i_arr = 0; i < d->len; i++){
            if(i == arr[i_arr]){
                change_card_count_deck(d, get_val(d->data[i]), -1);
                change_suit_count_deck(d, get_suit(d->data[i]), -1);
                append_hand(main, d->data[i]);
                free(d->data[i]);
                i_arr = (i_arr + 1) % len_arr;
            }
            else{
                d->data[i_tmp] = d->data[i];
                i_tmp++;
            }
        }
    }

    d->len = d->len - len_arr;
    return main;
}

void sort_deck(deck d){
    int stop = d->len - 1;
    quick_sort_deck(d, 0, stop);
}

void array_sort_deck(deck d, uint* arr, uint arr_len){
    for (uint i = 0; i < arr_len && i < d->len; i++){
        swit_deck(d, i, arr[i]);
    }
}

void print_deck(deck d){
    assert(d != NULL);
    
    for (uint i = 0; i < d->len; i++){
        printf("%d\t: ", i+1);
        
        print_card(d->data[i]);
        printf("\t");
        
        if((i+1) % 13 == 0){
            printf("\n");
        }
    }
}