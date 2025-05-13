#ifndef __MANIP_H__
#define __MANIP_H__

#include "libraries.h"
#include "interfaces/type.h"
#include "interfaces/card.h"
#include "interfaces/hand.h"
#include "interfaces/deck.h"

/*
O(1)
Entree : deux mains de poker
Sortie : un entier (0 ou 1)
Pre-condition : aucune
Post-condtion : vérifie si la première main est inférieure ou égale à la 2eme main
*/
uint leq_poker_hand(poker_hand, poker_hand);

#endif