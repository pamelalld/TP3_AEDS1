#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Rocha.h"
#include "../include/Arquivo.h"
#include "../include/Compartimento.h"

#define Max_aqv 100
#define Max_linha 255
#define Max_minerais 3

int main(){

    char nome_arquivo[Max_aqv];
    Arquivo arq;
    char arquivo[50] = "arquivos\\";
    int qtd_rochas,algoritmo;


    printf("Digite o nome do arquivo:");
    scanf("%s", nome_arquivo);
    strcat(arquivo,nome_arquivo);
    
    abrearquivo(arquivo,&arq);

    qtd_rochas=qtdoperacao(&arq);


    RochaMineral compartimento[qtd_rochas];

    for (int i=0;i<qtd_rochas;i++){
        RochaMineral coleta = ler_rocha(&arq);
        copia_Rocha(&compartimento[i],&coleta.minerais,coleta.peso,coleta.latitude,coleta.longitude,coleta.categoria);
    }
    printf("Qual algoritmo deseja utilizar\n1-Quicksort\n2-Insertionsort\n");
    scanf("%d",&algoritmo);
    switch (algoritmo)
    {
    case 1:
        quicksort(compartimento,qtd_rochas);
        break;
    case 2:
        //insertion(compartimento,qtd_rochas);
        break;
    
    default:
        printf("Opcao invalida!\n");
        break;
    }
    return 0;
}
    
    