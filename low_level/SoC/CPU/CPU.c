#include "CPU.h"
#include "CPU_test.h"

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


//fonctions de test

void print_cpu_contents(cpu sm83){
    printf("A = %d\tF = %d\n", sm83->A, sm83->F);
    printf("B = %d\tC = %d\t\tSP = %d\n", sm83->B, sm83->C, sm83->SP);
    printf("D = %d\tE = %d\t\tPC = %d\n", sm83->D, sm83->E, sm83->PC);
    printf("H = %d\tL = %d", sm83->H, sm83->L);
}

void print_mem_emp(enum mem_empl_e e){
    switch (e) {
        case A:
            printf("A");
            break;
        case F:
            printf("F");
            break;
        case B:
            printf("B");
            break;
        case C:
            printf("C");
            break;
        case D:
            printf("D");
            break;
        case E:
            printf("E");
            break;
        case H:
            printf("H");
            break;
        case L:
            printf("L");
            break;
        case SP:
            printf("SP");
            break;
        case PC:
            printf("PC");
            break;
        default:
            if(0 <= e && e <= 8192){
                printf("%d", e);
            }
            else{
                printf("invalid address");
            }
    }
}