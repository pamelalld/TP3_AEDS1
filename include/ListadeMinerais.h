#ifndef LISTA_MINERAIS_H
#define LISTA_MINERAIS_H

#define MAX_MINERAIS 3
#define TAM_INICIAL 0

#include"Mineral.h"

typedef struct Lista_minerais{

Mineral arranjo_minerais[MAX_MINERAIS];
int primeiro,prox_disponivel; //prox_disponivel também indica a quantidade de minerais na lista

} Lista_minerais;

void inicializa_lista_minerais(Lista_minerais* lista);
int verifica_l_vazia(Lista_minerais* lista);
int insere_mineral(Lista_minerais* lista,Mineral item);
void imprime_lista_minerais(Lista_minerais lista);


#endif