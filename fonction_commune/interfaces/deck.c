#include "deck.h"
#include "card.h"

struct deck_s{
    card* data;
    uint len;
    uint len_data;

    // compteur pour chaque cartes
    uint ace_count;
    uint king_count;
    uint queen_count;
    uint jack_count;
    uint ten_count;
    uint nine_count;
    uint eight_count;
    uint seven_count;
    uint six_count;
    uint five_count;
    uint four_count;
    uint three_count;
    uint two_count;

    // compteur pour chaque couleur
    uint club_count;
    uint spade_count;
    uint heart_count;
    uint diamond_count;
};

deck init_deck(){
    deck d = malloc(sizeof(struct deck_s));
    assert(d != NULL);

    d->len = 52;
    d->len_data = 60;
    d->data = malloc(60*sizeof(card));
    assert(d->data != NULL);
    
    d->ace_count = 4;
    d->king_count = 4;
    d->queen_count = 4;
    d->jack_count = 4;
    d->ten_count = 4;
    d->nine_count = 4;
    d->eight_count = 4;
    d->seven_count = 4;
    d->six_count = 4;
    d->five_count = 4;
    d->four_count = 4;
    d->three_count = 4;
    d->two_count = 4;
    
    d->club_count = 13;
    d->spade_count = 13;
    d->heart_count = 13;
    d->diamond_count = 13;

    for (uint i = 0; i < 13; i++){
        d->data[i] = init_card(i+1, club);
        d->data[i + 13] = init_card(i+1, spade);
        d->data[i + 26] = init_card(i+1, heart);
        d->data[i + 39] = init_card(i+1, diamond);
    }

    return d;
}

void change_card_count_deck(deck d, uint value, int k){
    if (value == 1){
        d->ace_count += k;
    }
    else if(value == 2){
        d->two_count += k;
    }
    else if(value == 3){
        d->three_count += k;
    }
    else if(value == 4){
        d->four_count += k;
    }
    else if(value == 5){
        d->five_count += k;
    }
    else if(value == 6){
        d->six_count += k;
    }
    else if(value == 7){
        d->seven_count += k;
    }
    else if(value == 8){
        d->eight_count += k;
    }
    else if(value == 9){
        d->nine_count += k;
    }
    else if(value == 10){
        d->ten_count += k;
    }
    else if(value == 11){
        d->jack_count += k;
    }
    else if(value == 12){
        d->queen_count += k;
    }
    else{
        d->king_count += k;
    }
}

void change_suit_count_deck(deck d, suit s, int k){
    if(s == club){
        d->club_count += k;
    }
    else if (s == spade){
        d->spade_count += k;
    }
    else if (s == heart){
        d->heart_count += k;
    }
    else{
        d->diamond_count += k;
    }
}

void free_deck(deck d){
    if (d != NULL){
        for(uint i = 0; i < d->len; i++){
            free_card(d->data[i]);
        }
        free(d->data);
        free(d);
    }
}

uint get_len_deck(deck d){
    assert(d != NULL);
    return d->len;
}

uint get_ace_count_deck(deck d){
    assert(d != NULL);
    return d->ace_count;
}

uint get_king_count_deck(deck d){
    assert(d != NULL);
    return d->king_count;
}

uint get_queen_count_deck(deck d){
    assert(d != NULL);
    return d->queen_count;
}

uint get_jack_count_deck(deck d){
    assert(d != NULL);
    return d->jack_count;
}

uint get_ten_count_deck(deck d){
    assert(d != NULL);
    return d->ten_count;
}

uint get_nine_count_deck(deck d){
    assert(d != NULL);
    return d->nine_count;
}

uint get_eight_count_deck(deck d){
    assert(d != NULL);
    return d->eight_count;
}

uint get_seven_count_deck(deck d){
    assert(d != NULL);
    return d->seven_count;
}

uint get_six_count_deck(deck d){
    assert(d != NULL);
    return d->six_count;
}

uint get_five_count_deck(deck d){
    assert(d != NULL);
    return d->five_count;
}

uint get_four_count_deck(deck d){
    assert(d != NULL);
    return d->four_count;
}

uint get_three_count_deck(deck d){
    assert(d != NULL);
    return d->three_count;
}

uint get_two_count_deck(deck d){
    assert(d != NULL);
    return d->two_count;
}

uint get_club_count_deck(deck d){
    assert(d != NULL);
    return d->club_count;
}

uint get_spade_count_deck(deck d){
    assert(d != NULL);
    return d->spade_count;
}

uint get_heart_count_deck(deck d){
    assert(d != NULL);
    return d->heart_count;
}

uint get_diamond_count_deck(deck d){
    assert(d != NULL);
    return d->diamond_count;
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