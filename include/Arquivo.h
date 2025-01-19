#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <stdio.h>
#include "Rocha.h"
//#include "Compartimento.h"

typedef struct {
    FILE *Arquivo;//ponteiro para arquivo
}Arquivo;

void abrearquivo(char *nomeArquivo, Arquivo* arquivo);
void fechaArquivo(Arquivo *arquivo);
int qtdoperacao(Arquivo *arquivo);
RochaMineral ler_rocha(Arquivo *arquivo);

#endif