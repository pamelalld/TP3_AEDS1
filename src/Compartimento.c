#include <stdio.h>
#include <stdlib.h>
#include "../include/Compartimento.h"

void incializa_compartimento(lista_rochas* lista){
    
    lista->primeiro=TAM_INICIAL;
    lista->prox_disponivel=lista->primeiro;

}

void exibe_compartimento(lista_rochas* lista){
    for(int i=0;i<lista->prox_disponivel;i++){
        printf("Categoria: %s",lista->arranjo_rochas->categoria);
        printf("Peso: %.2f - ",lista->arranjo_rochas[i].peso);
        
    }
    
}

int insere_nova_rocha(lista_rochas* lista,RochaMineral nova_rocha){ 
        
        if(lista->prox_disponivel==Max_tam){
            printf("Lista cheia\n");
            return 0;
        }else{
            lista->arranjo_rochas[lista->prox_disponivel]=nova_rocha;
            lista->prox_disponivel++;
            
        }
        
        return 1;

}

void ordena_insertion(int n,lista_rochas *vetor,int *comp,int *trocas){
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

void ordena_quick(int esq, int dir, RochaMineral *vetor, int *comparacoes,int *trocas){
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