all: geninput fgetc mistake1 mistake2 sample1 sample2

geninput: geninput.cpp
	g++ -o geninput geninput.cpp

fgetc: fgetc.c
	gcc -o fgetc fgetc.c

mistake1: mistake1.c
	gcc -o mistake1 mistake1.c
	
mistake2: mistake2.c
	gcc -o mistake2 mistake2.c

sample1: sample1.c
	gcc -o sample1 sample1.c
	
sample2: sample2.c
	gcc -o sample2 sample2.c