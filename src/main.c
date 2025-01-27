#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Rocha.h"
#include "../include/Arquivo.h"
#include "../include/Compartimento.h"

#define Max_aqv 100
#define Max_linha 255
#define Max_minerais 3

int menu(){

    char nome_arquivo[Max_aqv];
    Arquivo arq;
    arq.Arquivo=NULL;
    char arquivo[50] = "arquivos/";
    int qtd_rochas,algoritmo;
    lista_rochas compartimento;


    printf("Digite o nome do arquivo:");
    scanf("%s", nome_arquivo);
    strcat(arquivo,nome_arquivo);
    
    abrearquivo(arquivo,&arq);

    qtd_rochas=qtdoperacao(&arq);


    inicializa_compartimento(&compartimento,qtd_rochas);

    for (int i=0;i<qtd_rochas;i++){
        RochaMineral coleta = ler_rocha(&arq);
        insere_nova_rocha(&compartimento,coleta,qtd_rochas);
    }
    
    printf("======Selecione o algoritmo que deseja utilizar======\n1-Quicksort\n2-Insertionsort\n3-Sair\n");
    scanf("%d",&algoritmo);
    switch (algoritmo)
    {
    case 1:
        quicksort(&compartimento,qtd_rochas);
        fechaArquivo(&arq);
        break;
    case 2:
        insertion_sort(&compartimento,qtd_rochas);
        fechaArquivo(&arq);
        break;
    case 3:
        printf("Execução finalizada\n");
        fechaArquivo(&arq);
        return 0;
        break;
    default:
        printf("Opção inválida!\n");
        fechaArquivo(&arq);
        return 1;
        break;
    }
    return 0;
}
int main(){
    int chave = 1;

     while(chave){
        chave = menu();
    }

    return 0;
}