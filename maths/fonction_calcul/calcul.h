#ifndef __CALCUL_H__
#define __CALCUL_H__

#include "libraries.h"

typedef unsigned _BitInt(256) uint256;
typedef unsigned long long int uint64 ;

/*
O(n)
Entree : un entier
Sortie : un entier (sur 256 bits)
Pre-condition : n < 58
Post-condition : factoriel de l'entier en paramètre
*/
uint256 factoriel(unsigned int n);

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
uint64 binom(uint k, uint n);

/*
O(1)
Entree : deux entiers
Sortie : un flotant
Pre-condition : card_A <= card_Omage (les notation ont un sens)
Post-condition : un réel dans [0, 1] = card_A / card_Omega
*/

long double quotient(uint64 card_A, uint64 card_Omega);


#endif