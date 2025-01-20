#include "../include/insertion.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void ordena(int n,lista_rochas *vetor,int *comp,int *trocas){
    int i,j;
    RochaMineral tmp;
    Inicializa_Rocha(&tmp,&vetor[0].arranjo_rochas->minerais,vetor[0].arranjo_rochas->peso,vetor[0].arranjo_rochas->latitude,vetor[0].arranjo_rochas->longitude);
    for(i=1;i<n;i++){
        copia_Rocha(&tmp,&vetor->arranjo_rochas->minerais, vetor->arranjo_rochas[i].peso, vetor->arranjo_rochas[i].latitude, vetor->arranjo_rochas[i].longitude, vetor->arranjo_rochas[i].categoria); // rocha atual
        for(j = i-1;j >= 0;j--){
            (*comp)++; // Incrementa o contador de comparações
            if (tmp.peso < vetor->arranjo_rochas[j].peso){
            copia_Rocha(&vetor->arranjo_rochas[j + 1], &vetor->arranjo_rochas[j].minerais, vetor->arranjo_rochas[j].peso, vetor->arranjo_rochas[j].latitude, vetor->arranjo_rochas[j].longitude, vetor->arranjo_rochas[j].categoria);
            (*trocas)++; // Incrementa o contador de trocas
            }else{
                break;//encerra as comparacoes quando tmp>=a[j]
            }
        }
        // Insere o tmp na posição correta
        copia_Rocha(&vetor->arranjo_rochas[j + 1],&tmp.minerais, tmp.peso, tmp.latitude, tmp.longitude, tmp.categoria);
    }
        
}
void insertion_sort(lista_rochas *vetor,int n){
    int comparacoes=0;
    int trocas=0;
    ordena(n,vetor,&comparacoes,&trocas);
    for (int k=0;k<n;k++){
        printf("%s %.2f\n",vetor[k].arranjo_rochas->categoria,vetor[k].arranjo_rochas->peso);//arrumar 
    }
    printf("Comparacoes: %d\n",comparacoes);
    printf("Movimentacoes: %d\n",trocas);
    printf("Algoritmo: Insertion sort\n");
}