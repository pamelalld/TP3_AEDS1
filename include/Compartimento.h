#ifndef COMPARTIMENTO_H
#define COMPARTIMENO_H

#include <stdio.h>
#include "Rocha.h"

#define Max_tam 1000
#define tam_inicial 0

typedef struct lista_rochas {
    RochaMineral arranjo_rochas[Max_tam];
    int primeiro, prox_disponivel;
} lista_rochas;

void inicializa_compartimento(lista_rochas* lista);
void exibe_compartimento(lista_rochas* lista);
int insere_nova_rocha(lista_rochas* lista, RochaMineral nova_rocha);
void insertion_sort(lista_rochas *vetor,int n);
void ordena_insertion(int n,lista_rochas *vetor,int *comp,int *trocas);
void particao(int esq, int dir, int *i,int *j, RochaMineral *vetor, int *comparacoes, int *trocas);
void ordena_quick(int esq, int dir, RochaMineral *vetor, int *comparacoes,int *trocas);
void quicksort (RochaMineral *vetor, int n);

#endif