# Permet d'éxecuter la compilation dans n'importe quel répertoire
pwd > ~/pwd_tmp_emugb_sh.txt

# Compilation cpu
cd ~/Workspace/tipe-2026/low_level/SoC/CPU
gcc -Werror -Wall -Wextra -fsanitize=address -c CPU.c

# Compilation gameboy
cd ../../Gameboy
gcc -Werror -Wall -Wextra -fsanitize=address -c Gameboy.c

# Compilation de l'émulateur
cd ..
gcc -Werror -Wall -Wextra -fsanitize=address -o emugb SoC/CPU/CPU.o Gameboy/Gameboy.o emu.c

# ouverture de la rom
./emugb $@ #/!\ requiert un chemin absolu

#retour au point de départ
echo ~/pwd_tmp_emugb_sh.txt | cd
rm ~/pwd_tmp_emugb_sh.txt
