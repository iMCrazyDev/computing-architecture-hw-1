# makefile for task.asm


task: container.h main.cpp circle.h color.h rectangle.h rnd.h shape.h triangle.h utils.h calc.o
	g++ -g -o task main.cpp calc.o -no-pie


calc.o: calc.asm
	nasm -f elf64 -g -F dwarf calc.asm -l calc.lst