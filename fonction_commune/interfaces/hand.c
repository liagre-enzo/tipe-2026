#include "hand.h"
#include "card.h"

struct hand_s{
    card* data;
    uint len;
    uint len_data;

    // compteur pour chaque cartes
    uint* card_count;
};

void change_card_count_hand(hand h, uint value, int k){
    h->card_count[value - 1] += k;
}

void change_suit_count_hand(hand h, suit s, int k){
    if(s == club){
        h->card_count[13] += k;
    }
    else if (s == spade){
        h->card_count[14] += k;
    }
    else if (s == heart){
        h->card_count[15] += k;
    }
    else{
        h->card_count[16] += k;
    }
}

void swit_hand(hand arr, uint i, uint j){
    card tmp = arr->data[i];
    arr->data[i] = arr->data[j];
    arr->data[j] = tmp;
}

uint leq_hand(card c1, card c2){
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

int partition_hand(hand arr, int start, int stop){
    int k = start;
    for (int i = start; i < stop; i++){
        if (leq_hand(arr->data[i], arr->data[stop])){
            swit_hand(arr, k, i);
            k++;
        }
    }
    swit_hand(arr, k, stop);
    return k;
}

void quick_sort_hand(hand arr, int start, int stop){
    if(start < stop){
        int pivot = partition_hand(arr, start, stop);
        quick_sort_hand(arr, start, pivot - 1);
        quick_sort_hand(arr, pivot + 1, stop);
    }
}

// Fonctions d'inteface

hand init_hand(){
    hand h = malloc(sizeof(struct hand_s));
    assert(h != NULL);
    
    h->len = 0;
    h->len_data = 10;
    h->data = malloc(10 * sizeof(card));
    assert(h->data != NULL);

    h->card_count = malloc(17 * sizeof(uint));
    assert(h->card_count != NULL);

    for (uint i = 0; i < 17; i++){
        h->card_count[i] = 0;
    }
    
    return h;
}

void free_hand(hand h){
    if (h != NULL){
        for (uint i = 0; i < h->len; i++){
            free_card(h->data[i]);
        }
        free(h->card_count);
        free(h->data);
        free(h);
    }
}

uint get_len_hand(hand h){
    assert(h != NULL);
    return h->len;
}

uint get_card_count_hand(hand h, uint value){
    assert(h != NULL);
    return h->card_count[value -1];
}

uint get_suit_count_hand(hand h, suit col){
    assert(h != NULL);
    if(col == club){
        return h->card_count[13];
    }
    else if (col == heart){
        return h->card_count[14];
    }
    else if (col == spade){
        return h->card_count[15];
    }
    return h->card_count[16];
}

card access_hand(hand h, uint i){
    assert(h != NULL && i < h->len);
    return copy_card(h->data[i]);
}

void set_hand(hand h, uint i, card c){
    assert(h != NULL && i < h->len);
    
    card tmp = h->data[i];
    
    change_card_count_hand(h, get_val(tmp), -1);
    change_suit_count_hand(h, get_suit(tmp), -1);
    
    h->data[i] = copy_card(c);
    free(tmp);

    change_card_count_hand(h, get_val(c), 1);
    change_suit_count_hand(h, get_suit(c), 1);
}

void append_hand(hand h, card c){
    assert(h != NULL);
    
    if (h->len >= h->len_data){
        card* tmp = malloc(2*(h->len_data)*sizeof(card));
        
        assert(tmp != NULL);
        for (uint i = 0; i < h->len; i++){
            tmp[i] = h->data[i];
        }
        
        free(h->data);
        h->data = tmp;
        h->len_data *= 2;
    }
    
    h->data[h->len] = copy_card(c);
    h->len ++;

    change_card_count_hand(h, get_val(c), 1);
    change_suit_count_hand(h, get_suit(c), 1);
}

void del_hand(hand h, uint i){
    assert(h != NULL && i < h->len);
    
    if (h->len-1 <= h->len_data / 4){
        card* tmp_arr = malloc(((h->len_data)/2)*sizeof(card));
        assert(tmp_arr != NULL);
        
        for(uint j = 0; j < h->len; j++){
            tmp_arr[i] = h->data[i];
        }
        
        h->len_data /= 2;
        free(h->data);
        h->data = tmp_arr;
    }

    card tmp = h->data[i];
    for(uint j = i; j < h->len - 1; j++){
        h->data[j] = h->data[j + 1];
    }
    
    change_card_count_hand(h, get_val(tmp), -1);
    change_suit_count_hand(h, get_suit(tmp), -1);

    free(tmp);
    h->len --;
}

card pop_hand(hand h, uint i){
    assert(h != NULL && i < h->len);

    if (h->len-1 <= h->len_data / 4){
        card* tmp_arr = malloc(((h->len_data)/2)*sizeof(card));
        assert(tmp_arr != NULL);
        for(uint j = 0; j < h->len; j++){
            tmp_arr[i] = h->data[i];
        }
        h->len_data /= 2;
        free(h->data);
        h->data = tmp_arr;
    }

    card tmp = h->data[i];
    for(uint j = i; j < h->len - 1; j++){
        h->data[j] = h->data[j + 1];
    }

    change_card_count_hand(h, get_val(tmp), -1);
    change_suit_count_hand(h, get_suit(tmp), -1);

    h->len --;
    return tmp;
}

void del_array_hand(hand h, uint* arr, uint len_arr){
    assert(h != NULL && len_arr < h->len);
    if(len_arr == 1){
        del_hand(h, arr[0]);
    }

    if (h->len-len_arr <= h->len_data / 4){
        card* tmp_arr = malloc(((h->len_data)/2)*sizeof(card));
        assert(tmp_arr != NULL);
        
        for (uint i = 0, i_tmp=0, i_arr = 0; i < h->len; i++){
            if(i == arr[i_arr]){
                change_card_count_hand(h, get_val(h->data[i]), -1);
                change_suit_count_hand(h, get_suit(h->data[i]), -1);
                free(h->data[i]);
                i_arr = (i_arr + 1) % len_arr;
            }
            else{
                tmp_arr[i_tmp] = h->data[i];
                i_tmp++;
            }
        }

        h->len_data /= 2;
        free(h->data);
        h->data = tmp_arr;
    }
    
    else{
        for (uint i = 0, i_tmp=0, i_arr = 0; i < h->len; i++){
            if(i == arr[i_arr]){
                change_card_count_hand(h, get_val(h->data[i]), -1);
                change_suit_count_hand(h, get_suit(h->data[i]), -1);
                free(h->data[i]);
                i_arr = (i_arr + 1) % len_arr;
            }
            else{
                h->data[i_tmp] = h->data[i];
                i_tmp++;
            }
        }
    }

    h->len = h->len - len_arr;
}

void sort_hand(hand h){
    int stop = h->len - 1;
    quick_sort_hand(h, 0, stop);
}

void print_hand(hand h){
    assert(h != NULL);
    for (uint i = 0; i < h->len; i++){
        printf("%d :", i+1);
        
        print_card(h->data[i]);
        printf("\t");
        
        if((i+1) % 10 == 0){
            printf("\n");
        }
    }
}