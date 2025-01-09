#!/bin/bash

make
./program text "std" "asf .,/ ! "
mv text.replace text.replace1
./program text "int" "v  ki d ,.?"
mv text.replace text.replace2
make fclean
