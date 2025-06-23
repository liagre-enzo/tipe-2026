#ifndef __CPU_H__
#define __CPU_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t u8;

typedef uint16_t u16;

// Inplémentation du Sharp SM83 CPU

typedef struct cpu_s* cpu;

enum mem_empl_e{
    A = -10,    //register A
    F = -9,     //register F
    B = -8,     //register B
    C = -7,     // .
    D = -6,     // .
    E = -5,     // .
    H = -4,
    L = -3,
    SP = -2,
    PC = -1,
};

typedef enum mem_empl_e mem_empl ;

// Fonction de construction
cpu init_cpu();

// Fonction de destruction
void free_cpu(cpu);



#endif