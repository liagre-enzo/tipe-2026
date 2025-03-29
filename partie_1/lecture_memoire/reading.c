#include "reading.h"

void print_section_of_memory(int add_start, int add_end){
    char* p = (char *)add_start;
    for (int i = add_start; i <= add_end; i++){
        printf("%c", p[i]);
    }
    printf("\n");
}

void print_memory_map(char file_name[]);
