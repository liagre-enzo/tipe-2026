#include "calcul.h"
#include <stdint.h>

uint1024 factoriel(uint n){
    uint1024 res = 1;
    for (uint i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

uint1024 binom(uint k, uint n){
    uint1024 fact_n_moins_k = factoriel(n-k);
    uint1024 fact_n_sur_fact_k = 1;
    for (uint i = k+1; i <= n; i++){
        fact_n_sur_fact_k *= i;
    }
    uint1024 binome = fact_n_sur_fact_k / fact_n_moins_k;
    return binome;
}

