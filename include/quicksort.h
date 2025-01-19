#ifndef QUICK_H
#define QUICK_H

#include "Rocha.h"

void particao(int esq, int dir, int *i,int *j, RochaMineral *vetor, int *comparacoes, int *trocas);
void ordena (int esq, int dir, RochaMineral *vetor, int *comparacoes,int *trocas);
void quicksort (RochaMineral *vetor, int n);

#endif