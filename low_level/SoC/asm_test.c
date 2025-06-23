#include "CPU/CPU.h"
#include "CPU/CPU_test.h"
#include <stdio.h>

int main(){
    cpu sm83 = init_cpu();
    mem_empl ram_add = 100;
    mem_empl reg_A = A;
    print_mem_emp(ram_add);
    printf("\n");
    print_mem_emp(reg_A);
    printf("\n");
    print_cpu_contents(sm83);
    printf("\n");
    free_cpu(sm83);
    return 0;
}