compile: pilhadinamica.o benchmark.o main.o
	gcc pilhadinamica.o benchmark.o main.o -o app

main.o:
	gcc -c main.c -o main.o

benchmark.o:
	gcc -c benchmark/benchmark.c -o benchmark.o

pilhadinamica.o:
	gcc -c src/pilhadinamica.c -o pilhadinamica.o

clean:
	rm -f *.o
