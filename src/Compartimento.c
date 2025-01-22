#include <stdio.h>
#include <stdlib.h>
#include "../include/Compartimento.h"

void inicializa_compartimento(lista_rochas* lista){
    
    lista->primeiro=TAM_INICIAL;
    lista->prox_disponivel=lista->primeiro;

}

void exibe_compartimento(lista_rochas* lista){
    for(int i=0;i<lista->prox_disponivel;i++){
        printf("Categoria: %s- ",lista->arranjo_rochas[i].categoria);
        printf("Peso: %.2f\n",lista->arranjo_rochas[i].peso);
        
    }
    
}

int insere_nova_rocha(lista_rochas* lista,RochaMineral nova_rocha){ 
        
        if(lista->prox_disponivel==Max_tam){
            printf("Lista cheia\n");
            return 0;
        }else{
            copia_Rocha(&lista->arranjo_rochas[lista->prox_disponivel],&nova_rocha.minerais,nova_rocha.peso,nova_rocha.latitude,nova_rocha.longitude,nova_rocha.categoria);
            lista->prox_disponivel++;
            
        }
        
        return 1;

}

void ordena_insertion(int n,lista_rochas *vetor,int *comp,int *trocas){
    int i,j;
    RochaMineral tmp;
    Inicializa_Rocha(&tmp,&vetor->arranjo_rochas[0].minerais,vetor->arranjo_rochas[0].peso,vetor->arranjo_rochas[0].latitude,vetor->arranjo_rochas[0].longitude);
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
        (*trocas)++; // Incrementa o contador de trocas
    }
        
}
void insertion_sort(lista_rochas *vetor,int n){
    int comparacoes=0;
    int trocas=0;
    ordena_insertion(n,vetor,&comparacoes,&trocas);
    for (int k=0;k<n;k++){
        printf("%s %.2f\n",vetor->arranjo_rochas[k].categoria,vetor->arranjo_rochas[k].peso);//arrumar 
    }
    printf("\nComparacoes: %d\n",comparacoes);
    printf("Movimentacoes: %d\n",trocas);
    printf("Algoritmo: Insertion sort\n");
}


void particao(int esq, int dir, int *i,int *j, lista_rochas *vetor, int *comparacoes, int *trocas){
    RochaMineral pivo, aux;
    Inicializa_Rocha(&aux,&vetor->arranjo_rochas[0].minerais,vetor->arranjo_rochas[0].peso,vetor->arranjo_rochas[0].latitude,vetor->arranjo_rochas[0].longitude);
    *i = esq; *j = dir;
    pivo = vetor->arranjo_rochas[(*i + *j) / 2]; 
    do{
        while (pivo.peso > vetor->arranjo_rochas[*i].peso){
            (*i)++;
            (*comparacoes)++;
            }
        while (pivo.peso < vetor->arranjo_rochas[*j].peso){
            (*j)--;
            (*comparacoes)++;
            }
        if (*i <= *j){
            copia_Rocha(&aux,&vetor->arranjo_rochas[*i].minerais,vetor->arranjo_rochas[*i].peso,vetor->arranjo_rochas[*i].latitude,vetor->arranjo_rochas[*i].longitude,vetor->arranjo_rochas[*i].categoria);
            copia_Rocha(&vetor->arranjo_rochas[*i],&vetor->arranjo_rochas[*j].minerais,vetor->arranjo_rochas[*j].peso,vetor->arranjo_rochas[*j].latitude,vetor->arranjo_rochas[*j].longitude,vetor->arranjo_rochas[*j].categoria);
            copia_Rocha(&vetor->arranjo_rochas[*j],&aux.minerais,aux.peso,aux.latitude,aux.longitude,aux.categoria);

            (*trocas)++;
            
            (*i)++;
            (*j)--;
        }
    } while (*i<= *j);
}

void ordena_quick(int esq, int dir, lista_rochas *vetor, int *comparacoes,int *trocas){
    int i,j;
    particao(esq,dir,&i,&j,vetor,comparacoes,trocas);
    if (esq<j) {ordena_quick(esq,j,vetor,comparacoes,trocas);}
    
    if (i<dir) {ordena_quick(i,dir,vetor,comparacoes,trocas);}
}

void quicksort (lista_rochas *vetor, int n){
    int comparacoes=0;
    int trocas=0;
    ordena_quick(0,n-1,vetor,&comparacoes,&trocas);

    for (int k=0;k<n;k++){
        printf("%s %.1f\n",vetor->arranjo_rochas[k].categoria,vetor->arranjo_rochas[k].peso);
    }
    printf("\nComparacoes: %d\n",comparacoes);
    printf("Movimentacoes: %d\n",trocas);
    printf("Algoritmo: Quicksort\n");

}