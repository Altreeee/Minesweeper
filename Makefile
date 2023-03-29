all:main main.o utilize.o clean

main:main.o utilize.o
		gcc  $^ -o $@ -lsx 

main.o:main.c w.h
		gcc -c $^ -lsx 

utilize.o:utilize.c
		gcc  -c $^ -lsx 

clean:
	rm -rf main.o utilize.o w.h.gch
