#!/bin/sh

gcc -c -o Date.o Date.cpp
gcc -c -o get.o get.cpp
gcc -c -o interpolation.o interpolation.cpp
gcc -c -o TermStructure.o Termstructure.cpp
gcc -c -o main.o main.cpp
gcc -o lecture main.o TermStructure.o interpolation.o get.o Date.o -lm
