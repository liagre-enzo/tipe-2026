#include "hand.h"

struct hand_s{
    card* data;
    int len;
    int len_data;
};

hand init_hand(){
    hand h = malloc(sizeof(struct hand_s));
    assert(h != NULL);
    
    h->len = 0;
    h->len_data = 10;
    h->data = malloc(10 * sizeof(card));
    
    return h;
}

void free_hand(hand h){
    if (h != NULL){
        for (int i = 0; i < h->len; i++){
            free_card(h->data[i]);
        }
        free(h->data);
        free(h);
    }
}

int get_len_hand(hand h){
    assert(h != NULL);
    return h->len;
}

card access_hand(hand h, int i){
    assert(h != NULL && h->len > 0);
    if (i >= h->len){
        return h->data[h->len -1];
    }
    else if (i <= 0) {
        return h->data[0];
    }
    return h->data[i];
}

void set_hand(hand h, int i, card c){
    assert(h != NULL && 0 <= i && i < h->len);
    h->data[i] = c;
}

void append_hand(hand h, card c){
    
}

void del_hand(hand h, int i);

card pop_hand(hand h, int i);