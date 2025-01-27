compile: src/Compartimento.c src/Arquivo.c src/ListadeMinerais.c src/Mineral.c src/Rocha.c src/main.c
	gcc -o bin/main src/Compartimento.c src/Arquivo.c src/ListadeMinerais.c src/Rocha.c src/Mineral.c src/main.c -g -Wall

	