#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/Compartimento.h"

/**
 * @brief Faz a inicialização do compartimento, uma lista vetorial de tamanho max_tam.
 */
void inicializa_compartimento(lista_rochas* lista,int max_tam){
    
    lista->primeiro=TAM_INICIAL;
    lista->prox_disponivel=lista->primeiro;
    lista->arranjo_rochas=(RochaMineral* )calloc(sizeof(RochaMineral),max_tam);
    lista->Max_tam=max_tam;

}
/**
 * @brief exibe as informações das rochas contidas no compartimento.
 */
void exibe_compartimento(lista_rochas* lista){
    for(int i=0;i<lista->prox_disponivel;i++){
        printf("Categoria: %s- ",lista->arranjo_rochas[i].categoria);
        printf("Peso: %.2f\n",lista->arranjo_rochas[i].peso);
        
    }
    
}
/**
 * @brief Faz a inserção de uma nova rocha no final do vetor compartimento.
 */
int insere_nova_rocha(lista_rochas* lista,RochaMineral nova_rocha,int max_tam){ 
        
        if(lista->prox_disponivel==max_tam){
            printf("Lista cheia\n");
            return 0;
        }else{
            copia_Rocha(&lista->arranjo_rochas[lista->prox_disponivel],&nova_rocha.minerais,nova_rocha.peso,nova_rocha.latitude,nova_rocha.longitude,nova_rocha.categoria);
            lista->prox_disponivel++;
            
        }
        
        return 1;

}
/**
 * @brief Uma das funções necessárias para o funcionamento do método de ordenação Insertionsort.
 */
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
            }
            else{
                break;//encerra as comparacoes quando tmp>=a[j]
            }
        }
        // Insere o tmp na posição correta
        copia_Rocha(&vetor->arranjo_rochas[j + 1],&tmp.minerais, tmp.peso, tmp.latitude, tmp.longitude, tmp.categoria);
        (*trocas)++; // Incrementa o contador de trocas

    }   
}

/**
 * @brief Função principal do método Insertionsort, faz a chamada recursiva da função ordena_insertion.
 */
void insertion_sort(lista_rochas *vetor,int n){
    int comparacoes=0;
    int trocas=0;
    clock_t ti, tf;
    
    ti= clock ();
    ordena_insertion(n,vetor,&comparacoes,&trocas);
    
    tf =clock ()-ti;
    
    exibe_compartimento(vetor);

    printf("\nComparacoes: %d\n",comparacoes);
    printf("Movimentacoes: %d\n",trocas);
    printf("Tempo de execução %.2lf segundos\n",(double)tf/CLOCKS_PER_SEC);

    printf("Algoritmo: Insertion sort\n");
}

/**
 * @brief Funcionalidade essencial para método de ordenação quicksort, faz a divisão e organização de partições, favorecendo o processo de ordenação.
 */
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
/**
 * @brief Organiza a posição dos elementos no vetor a partir de chamada recursiva da função particao.
 */
void ordena_quick(int esq, int dir, lista_rochas *vetor, int *comparacoes,int *trocas){
    int i,j;
    particao(esq,dir,&i,&j,vetor,comparacoes,trocas);
    if (esq<j) {ordena_quick(esq,j,vetor,comparacoes,trocas);}
    
    if (i<dir) {ordena_quick(i,dir,vetor,comparacoes,trocas);}
}

/**
 * @brief Função principal do método Quicksort.
 */
void quicksort (lista_rochas *vetor, int n){
    int comparacoes=0;
    int trocas=0;
    clock_t ti, tf;

    ti= clock ();

    ordena_quick(0,n-1,vetor,&comparacoes,&trocas);

    tf =clock ()-ti;
    
    exibe_compartimento(vetor);

    printf("\nComparacoes: %d\n",comparacoes);
    printf("Movimentacoes: %d\n",trocas);
    printf("Tempo de execução %.2lf segundos\n",(double)tf/CLOCKS_PER_SEC);
    printf("Algoritmo: Quicksort\n");

}

