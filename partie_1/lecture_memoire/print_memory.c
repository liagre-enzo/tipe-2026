#include "../libraries.h"
#include "reading.h"

int main(int argc, char* argv[]){
    int address1 = atoi(argv[2]);
    int address2 = atoi(argv[3]);
    print_section_of_memory(address1, address2);
    return 0;
}