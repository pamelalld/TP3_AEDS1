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

