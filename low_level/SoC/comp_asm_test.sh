pwd > /home/enzo/tmp.txt
cd ~/Workspace/tipe-2026/low_level/SoC/CPU
gcc -Werror -Wall -Wextra -fsanitize=address -c CPU.c
cd ~/Workspace/tipe-2026/low_level/SoC/
gcc -Werror -Wall -Wextra -fsanitize=address -o exec CPU/CPU.o asm_test.c
./exec
echo /home/enzo/tmp.txt | cd
rm /home/enzo/tmp.txt