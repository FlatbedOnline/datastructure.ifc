dinamica: pilhadinamica.o benchmark.o main_pilhadinamica.o
	gcc pilhadinamica.o benchmark.o main_pilhadinamica.o -o dinamica

estatica: pilhaestatica.o benchmark.o main_pilhaestatica.o
	gcc pilhaestatica.o benchmark.o main_pilhaestatica.o -o estatica

estatica_teste: pilhaestatica.o biblioteca.o benchmark.o main_es_teste.o
	gcc pilhaestatica.o biblioteca.o benchmark.o main_es_teste.o -o estatica_teste

dinamica_teste: pilhadinamica.o biblioteca.o benchmark.o main_di_teste.o
	gcc pilhadinamica.o biblioteca.o benchmark.o main_di_teste.o -o dinamica_teste

main_pilhadinamica.o: main_pilhadinamica.c
	gcc -c main_pilhadinamica.c -o main_pilhadinamica.o

main_pilhaestatica.o: main_pilhaestatica.c
	gcc -c main_pilhaestatica.c -o main_pilhaestatica.o

main_es_teste.o: main_es_teste.c
	gcc -c main_es_teste.c -o main_es_teste.o

main_di_teste.o: main_di_teste.c
	gcc -c main_di_teste.c -o main_di_teste.o

benchmark.o: benchmark/benchmark.c
	gcc -c benchmark/benchmark.c -o benchmark.o

pilhadinamica.o: src/pilhadinamica.c
	gcc -c src/pilhadinamica.c -o pilhadinamica.o

pilhaestatica.o: src/pilhaestatica.c
	gcc -c src/pilhaestatica.c -o pilhaestatica.o

biblioteca.o: src/biblioteca.c src/biblioteca.h
	gcc -c src/biblioteca.c -o biblioteca.o

clean:
	rm -f *.o dinamica estatica dinamica_teste estatica_teste
