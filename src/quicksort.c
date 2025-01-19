#include "../include/quicksort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void particao(int esq, int dir, int *i,int *j, RochaMineral *vetor, int *comparacoes, int *trocas){
    RochaMineral pivo, aux;
    Inicializa_Rocha(&aux,&vetor[0].minerais,vetor[0].peso,vetor[0].latitude,vetor[0].longitude);
    *i = esq; *j = dir;
    pivo = vetor[(*i + *j) / 2]; 
    do{
        while (pivo.peso > vetor[*i].peso){
            (*i)++;
            (*comparacoes)++;
            }
        while (pivo.peso < vetor[*j].peso){
            (*j)--;
            (*comparacoes)++;
            }
        if (*i <= *j){
            copia_Rocha(&aux,&vetor[*i].minerais,vetor[*i].peso,vetor[*i].latitude,vetor[*i].longitude,vetor[*i].categoria);
            copia_Rocha(&vetor[*i],&vetor[*j].minerais,vetor[*j].peso,vetor[*j].latitude,vetor[*j].longitude,vetor[*j].categoria);
            copia_Rocha(&vetor[*j],&aux.minerais,aux.peso,aux.latitude,aux.longitude,aux.categoria);

            (*trocas)++;
            
            (*i)++;
            (*j)--;
        }
    } while (*i<= *j);
}

void ordena (int esq, int dir, RochaMineral *vetor, int *comparacoes,int *trocas){
    int i,j;
    particao(esq,dir,&i,&j,vetor,comparacoes,trocas);
    if (esq<j) {ordena(esq,j,vetor,comparacoes,trocas);}
    
    if (i<dir) {ordena(i,dir,vetor,comparacoes,trocas);}
}

void quicksort (RochaMineral *vetor, int n){
    int comparacoes=0;
    int trocas=0;
    ordena(0,n-1,vetor,&comparacoes,&trocas);

    for (int k=0;k<n;k++){
        printf("%s %.1f\n",vetor[k].categoria,vetor[k].peso);
    }
    printf("\n");
    printf("Comparacoes: %d\n",comparacoes);
    printf("Movimentacoes: %d\n",trocas);
    printf("Algoritmo: Quicksort");

}