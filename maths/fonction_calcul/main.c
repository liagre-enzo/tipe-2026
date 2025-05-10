#include "calcul.h"
#include <stdio.h>

int main(){
    uint64 b1 = binom(8, 52);
    uint64 b2 = binom(7, 52);
    long double proba = quotient(b2, b1);
    printf("%Lf",proba);
}