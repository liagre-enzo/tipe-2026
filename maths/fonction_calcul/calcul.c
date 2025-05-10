#include "calcul.h"
#include <stdint.h>

uint256 factoriel(uint n){
    uint256 res = 1;
    for (uint i = 1; i <= n; i++){
        res *= i;
    }
    return res;
}

uint64 binom(uint k, uint n){
    uint256 fact_n_moins_k = factoriel(n-k);
    uint256 fact_n_sur_fact_k = 1;
    for (uint i = k+1; i <= n; i++){
        fact_n_sur_fact_k *= i;
    }
    uint64 binome = fact_n_sur_fact_k / fact_n_moins_k;
    return binome;
}

long double quotient(uint64 card_A, uint64 card_Omega){
    return (long double)card_A / card_Omega;
}