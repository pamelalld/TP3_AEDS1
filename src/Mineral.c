#include "../include/Mineral.h"
#include <stdio.h>
#include <string.h>



void inicializa_mineral(Mineral* mineral,char *nome){
    strcpy(mineral->nome,nome);
}
char* get_nome(Mineral* mineral){
    return(mineral->nome);
}