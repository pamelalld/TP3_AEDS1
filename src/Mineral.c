#include "../include/Mineral.h"
#include <stdio.h>
#include <string.h>


/**
 * @brief Inicializa um TAD mineral, atribuindo seu nome.
 */
void inicializa_mineral(Mineral* mineral,char *nome){
    strcpy(mineral->nome,nome);
}
char* get_nome(Mineral* mineral){
    return(mineral->nome);
}