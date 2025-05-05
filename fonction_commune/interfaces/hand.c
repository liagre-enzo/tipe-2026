#include "hand.h"
#include "card.h"

struct hand_s{
    card* data;
    unsigned int len;
    unsigned int len_data;

    // compteur pour chaque cartes
    unsigned int ace_count;
    unsigned int king_count;
    unsigned int queen_count;
    unsigned int jack_count;
    unsigned int ten_count;
    unsigned int nine_count;
    unsigned int eight_count;
    unsigned int seven_count;
    unsigned int six_count;
    unsigned int five_count;
    unsigned int four_count;
    unsigned int three_count;
    unsigned int two_count;

    // compteur pour chaque couleur
    unsigned int club_count;
    unsigned int spade_count;
    unsigned int heart_count;
    unsigned int diamond_count;
};

hand init_hand(){
    hand h = malloc(sizeof(struct hand_s));
    assert(h != NULL);
    
    h->len = 0;
    h->len_data = 10;
    h->data = malloc(10 * sizeof(card));
    assert(h->data != NULL);

    h->ace_count = 0;
    h->king_count = 0;
    h->queen_count = 0;
    h->jack_count = 0;
    h->ten_count = 0;
    h->nine_count = 0;
    h->eight_count = 0;
    h->seven_count = 0;
    h->six_count = 0;
    h->five_count = 0;
    h->four_count = 0;
    h->three_count = 0;
    h->two_count = 0;
    
    h->club_count = 0;
    h->spade_count = 0;
    h->heart_count = 0;
    h->diamond_count = 0;
    
    return h;
}

void change_card_count_hand(hand h, unsigned int value, int k){
    if (value == 1){
        h->ace_count += k;
    }
    else if(value == 2){
        h->two_count += k;
    }
    else if(value == 3){
        h->three_count += k;
    }
    else if(value == 4){
        h->four_count += k;
    }
    else if(value == 5){
        h->five_count += k;
    }
    else if(value == 6){
        h->six_count += k;
    }
    else if(value == 7){
        h->seven_count += k;
    }
    else if(value == 8){
        h->eight_count += k;
    }
    else if(value == 9){
        h->nine_count += k;
    }
    else if(value == 10){
        h->ten_count += k;
    }
    else if(value == 11){
        h->jack_count += k;
    }
    else if(value == 12){
        h->queen_count += k;
    }
    else{
        h->king_count += k;
    }
}

void change_suit_count_hand(hand h, suit s, int k){
    if(s == club){
        h->club_count += k;
    }
    else if (s == spade){
        h->spade_count += k;
    }
    else if (s == heart){
        h->heart_count += k;
    }
    else{
        h->diamond_count += k;
    }
}

void free_hand(hand h){
    if (h != NULL){
        for (unsigned int i = 0; i < h->len; i++){
            free_card(h->data[i]);
        }
        free(h->data);
        free(h);
    }
}

unsigned int get_len_hand(hand h){
    assert(h != NULL);
    return h->len;
}

unsigned int get_ace_count_hand(hand h){
    assert(h != NULL);
    return h->ace_count;
}

unsigned int get_king_count_hand(hand h){
    assert(h != NULL);
    return h->king_count;
}

unsigned int get_queen_count_hand(hand h){
    assert(h != NULL);
    return h->queen_count;
}

unsigned int get_jack_count_hand(hand h){
    assert(h != NULL);
    return h->jack_count;
}

unsigned int get_ten_count_hand(hand h){
    assert(h != NULL);
    return h->ten_count;
}

unsigned int get_nine_count_hand(hand h){
    assert(h != NULL);
    return h->nine_count;
}

unsigned int get_eight_count_hand(hand h){
    assert(h != NULL);
    return h->eight_count;
}

unsigned int get_seven_count_hand(hand h){
    assert(h != NULL);
    return h->seven_count;
}

unsigned int get_six_count_hand(hand h){
    assert(h != NULL);
    return h->six_count;
}

unsigned int get_five_count_hand(hand h){
    assert(h != NULL);
    return h->five_count;
}

unsigned int get_four_count_hand(hand h){
    assert(h != NULL);
    return h->four_count;
}

unsigned int get_three_count_hand(hand h){
    assert(h != NULL);
    return h->three_count;
}

unsigned int get_two_count_hand(hand h){
    assert(h != NULL);
    return h->two_count;
}

unsigned int get_club_count_hand(hand h){
    assert(h != NULL);
    return h->club_count;
}

unsigned int get_spade_count_hand(hand h){
    assert(h != NULL);
    return h->spade_count;
}

unsigned int get_heart_count_hand(hand h){
    assert(h != NULL);
    return h->heart_count;
}

unsigned int get_diamond_count_hand(hand h){
    assert(h != NULL);
    return h->diamond_count;
}

card access_hand(hand h, unsigned int i){
    assert(h != NULL && i < h->len);
    return copy_card(h->data[i]);
}

void set_hand(hand h, unsigned int i, card c){
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
        for (unsigned int i = 0; i < h->len; i++){
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

void del_hand(hand h, unsigned int i){
    assert(h != NULL && i < h->len);
    
    if (h->len-1 <= h->len_data / 4){
        card* tmp_arr = malloc(((h->len_data)/2)*sizeof(card));
        assert(tmp_arr != NULL);
        
        for(unsigned int j = 0; j < h->len; j++){
            tmp_arr[i] = h->data[i];
        }
        
        h->len_data /= 2;
        free(h->data);
        h->data = tmp_arr;
    }

    card tmp = h->data[i];
    for(unsigned int j = i; j < h->len - 1; j++){
        h->data[j] = h->data[j + 1];
    }
    
    change_card_count_hand(h, get_val(tmp), -1);
    change_suit_count_hand(h, get_suit(tmp), -1);

    free(tmp);
    h->len --;
}

card pop_hand(hand h, unsigned int i){
    assert(h != NULL && i < h->len);

    if (h->len-1 <= h->len_data / 4){
        card* tmp_arr = malloc(((h->len_data)/2)*sizeof(card));
        assert(tmp_arr != NULL);
        for(unsigned int j = 0; j < h->len; j++){
            tmp_arr[i] = h->data[i];
        }
        h->len_data /= 2;
        free(h->data);
        h->data = tmp_arr;
    }

    card tmp = h->data[i];
    for(unsigned int j = i; j < h->len - 1; j++){
        h->data[j] = h->data[j + 1];
    }

    change_card_count_hand(h, get_val(tmp), -1);
    change_suit_count_hand(h, get_suit(tmp), -1);

    h->len --;
    return tmp;
}

void print_hand(hand h){
    assert(h != NULL);
    for (unsigned int i = 0; i < h->len; i++){
        printf("%d :", i+1);
        
        print_card(h->data[i]);
        printf("\t");
        
        if((i+1) % 10 == 0){
            printf("\n");
        }
    }
}