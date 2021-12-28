p1: p1.cpp
	g++ -g -std=c++11 -O3 -Wall -o p1 p1.cpp -lm

#p1: p1.c
#	gcc -O3 -ansi -Wall -o p1 p1.c -lm

random_k: random_k.cpp
	g++ -O3 -Wall -o random_k random_k.cpp -lm

clean:
	rm -f *.o p1
