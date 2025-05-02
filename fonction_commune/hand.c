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
    card tmp = h->data[i];
    h->data[i] = c;
    free(tmp);
}

void append_hand(hand h, card c){
    assert(h != NULL);
    if (h->len >= h->len_data){
        card* tmp = malloc(2*(h->len_data)*sizeof(card));
        for (int i = 0; i < h->len; i++){
            tmp[i] = h->data[i];
        }
        free(h->data);
        h->data = tmp;
        h->len_data *= 2;
    }
    h->data[h->len] = c;
    h->len ++;
}

void del_hand(hand h, int i){
    assert(h != NULL && 0 <= i && i < h->len);
    
    if (h->len-1 <= h->len_data / 4){
        card* tmp_arr = malloc(((h->len_data)/2)*sizeof(card));
        for(int j = 0; j < h->len; j++){
            tmp_arr[i] = h->data[i];
        }
        h->len_data /= 2;
        free(h->data);
        h->data = tmp_arr;
    }

    card tmp = h->data[i];
    for(int j = i; j < h->len - 1; j++){
        h->data[j] = h->data[j + 1];
    }
    free(tmp);
    h->len --;
}

card pop_hand(hand h, int i){
    assert(h != NULL && 0 <= i && i < h->len);

    if (h->len-1 <= h->len_data / 4){
        card* tmp_arr = malloc(((h->len_data)/2)*sizeof(card));
        for(int j = 0; j < h->len; j++){
            tmp_arr[i] = h->data[i];
        }
        h->len_data /= 2;
        free(h->data);
        h->data = tmp_arr;
    }

    card tmp = h->data[i];
    for(int j = i; j < h->len - 1; j++){
        h->data[j] = h->data[j + 1];
    }
    h->len --;
    return tmp;
}