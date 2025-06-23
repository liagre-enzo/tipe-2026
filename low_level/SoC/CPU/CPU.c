#include "CPU.h"

//definition du cpu

struct cpu_s{
    u8 A;   u8 F;
    u8 B;   u8 C;
    u8 D;   u8 E;
    u8 H;   u8 L;
    u16 SP; u16 PC;
};

cpu init_cpu(){
    cpu sm83 = malloc(sizeof(struct cpu_s));
    sm83->A = 0;    sm83->F = 0;
    sm83->B = 0;    sm83->C = 0;
    sm83->D = 0;    sm83->E = 0;
    sm83->H = 0;    sm83->L = 0;
    sm83->SP = 0;   sm83->PC = 0;
    return sm83;
}

void free_cpu(cpu sm83){
    free(sm83);
}

// instruction set architecture
