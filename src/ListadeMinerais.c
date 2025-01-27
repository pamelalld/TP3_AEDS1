#include <stdio.h>
#include <string.h>
#include "../include/ListadeMinerais.h"

/**
 * @brief Inicializa uma lista de minerais vazia (implementação com vetor).
 */
void inicializa_lista_minerais(Lista_minerais* lista){

    lista->primeiro=TAM_INICIAL;    //Inicia uma lista de minerais vazia.
    lista->prox_disponivel=lista->primeiro;
}
/**
 * @brief Verifica se uma determinada lista de minerais está vazia ou não.
 */
int verifica_l_vazia(Lista_minerais* lista){

    return(lista->primeiro==lista->prox_disponivel); 
    
}

/**
 * @brief Insere um mineral no final de uma lista de minerais.
 * @param lista Lista onde será feita a inserção.
 * @param item Mineral a ser inserido.
 */
int insere_mineral(Lista_minerais* lista,Mineral item){

        if(lista->prox_disponivel==MAX_MINERAIS+1){  //Se a lista estiver cheia a inserção não acontece.
            printf("Lista cheia\n");
            return 0;
        }
        else{
            lista->arranjo_minerais[lista->prox_disponivel]=item;
            lista->prox_disponivel++; //Atualiza a proxima posicao disponivel.
        }
        return 1;
    }

/**
 * @brief Imprime o nome de de todos minerais contidos numa lista (rocha).
 */   
void imprime_lista_minerais(Lista_minerais lista){

    for (int i=0;i<lista.prox_disponivel;i++){ // Imprime o nome de todos os minerais da lista.
        printf("%s ",get_nome(&lista.arranjo_minerais[i]));
    }            

}