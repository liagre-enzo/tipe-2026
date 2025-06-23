#ifndef __CPU_H__
#define __CPU_H__

#include <stdint.h>
#include <stdlib.h>

typedef uint8_t u8;

typedef uint16_t u16;

// Inplémentation du Sharp SM83 CPU

typedef struct cpu_s* cpu;

// Fonction de construction
cpu init_cpu();

// Fonction de destruction
void free_cpu(cpu);


#endif