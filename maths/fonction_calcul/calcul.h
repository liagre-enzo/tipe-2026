#ifndef __CALCUL_H__
#define __CALCUL_H__

#include "libraries.h"

typedef unsigned _BitInt(1024) uint1024;

/*
O(n)
Entree : un entier
Sortie : un entier (sur 256 bits)
Pre-condition : n < 58
Post-condition : factoriel de l'entier en paramètre
*/
uint1024 factoriel(unsigned int n);

/*
Note :

On ne va pricipalement manipuler que des coefficitent binomiaux.
Au pire les coefficient que l'on manipule sont de l'ordre du E+14 < 2^{64}.
On se ramène donc directement à des long long int pour pouvoir les manipuler plus facilement.
*/

/*
O(n)
Entree : deux entiers
Sortie : un entier (sur 64 bits)
Pre-conditon : k <= n < 58
post condition: le coeff binomial k parmis n
*/
uint1024 binom(uint k, uint n);



#endif