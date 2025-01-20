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

#endif