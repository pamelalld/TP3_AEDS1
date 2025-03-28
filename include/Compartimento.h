#ifndef COMPARTIMENTO_H
#define COMPARTIMENO_H

#include <stdio.h>
#include "Rocha.h"

#define tam_inicial 0

typedef struct lista_rochas {
    RochaMineral *arranjo_rochas;
    int Max_tam;
    int primeiro, prox_disponivel;
} lista_rochas;

void inicializa_compartimento(lista_rochas* lista,int max_tam);
void exibe_compartimento(lista_rochas* lista);
int insere_nova_rocha(lista_rochas* lista, RochaMineral nova_rocha,int max_tam);
void insertion_sort(lista_rochas *vetor,int n);
void ordena_insertion(int n,lista_rochas *vetor,int *comp,int *trocas);
void particao(int esq, int dir, int *i,int *j, lista_rochas *vetor, int *comparacoes, int *trocas);
void ordena_quick(int esq, int dir, lista_rochas *vetor, int *comparacoes,int *trocas);
void quicksort (lista_rochas *vetor, int n);

#endif