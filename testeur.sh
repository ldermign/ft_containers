#!/bin/bash

# alias ftstd="cat ft.txt && cat std.txt"
# alias valft="valgrind --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes ./ft_containers"

RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

make

./ft_containers > ft.txt
./std_containers > std.txt

diff -y -W 60 --suppress-common-lines ft.txt std.txt > results.txt
comp_value=$?

if [ $comp_value -eq 1 ]
then
    printf $RED"\nSomething's wrong in tests.\n"$BLUE"\n\tFT\t\t\t\tSTD\n-----------------------------|------------------------------\n"$RESET
	cat results.txt
	printf "\n"
else
    printf $GREEN"\nNo mistake were made!\n\n"$RESET
fi

# rm -rf ft.txt std.txt
