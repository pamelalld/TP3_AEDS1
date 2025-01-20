#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
 #else
    #include<unistd.h>

#endif

#include "../include/Rocha.h"
#include "../include/Arquivo.h"
#include "../include/Compartimento.h"

#define Max_aqv 100
#define Max_linha 255
#define Max_minerais 3

int menu(){
    char nome_arquivo[Max_aqv];
    Arquivo arq;
    char arquivo[50] = "arquivos\\";
    int qtd_rochas,algoritmo;
    lista_rochas compartimento;


    printf("Digite o nome do arquivo:");
    scanf("%s", nome_arquivo);
    strcat(arquivo,nome_arquivo);
    
    abrearquivo(arquivo,&arq);

    qtd_rochas=qtdoperacao(&arq);


    inicializa_compartimento(&compartimento);

    for (int i=0;i<qtd_rochas;i++){
        RochaMineral coleta = ler_rocha(&arq);
        insere_nova_rocha(&compartimento,coleta);
    }
    //exibe_compartimento(&compartimento);
    
    printf("======Selecione o algoritmo que deseja utilizar======\n1-Quicksort\n2-Insertionsort\n3-Sair\n");
    scanf("%d",&algoritmo);
    switch (algoritmo)
    {
    case 1:
        quicksort(&compartimento,qtd_rochas);
        break;
    case 2:
        insertion_sort(&compartimento,qtd_rochas);
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
    // Fecha o arquivo após executar as operações
    fechaArquivo(&arq);
    return 0;

}
int main(){
    int chave = 1;
    #if defined(_WIN32) || defined(_WIN64)

    LARGE_INTEGER inicio, fim, frequency;
    double decorrido;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&inicio);
    #else
        struct timespec inicio, fim;
        // Marca o tempo de início
        clock_gettime(CLOCK_MONOTONIC, &inicio);

    #endif
    while(chave){
        // Captura o tempo inicial
        chave = menu();
    }
    #if defined(_WIN32) || defined(_WIN64)

    // Captura o tempo final
    QueryPerformanceCounter(&fim);
     // Calcula o tempo total do programa
    decorrido = (fim.QuadPart - inicio.QuadPart)/frequency.QuadPart;
    printf("Tempo total gasto: %.2f segundos\n", decorrido);
    printf("Programa encerrado.\n");
    #else
    // Marca o tempo de fim
    clock_gettime(CLOCK_MONOTONIC, &fim);

    // Calcula a diferença em nanossegundos
    long segundos = fim.tv_sec - inicio.tv_sec;
    long nanosegundos = fim.tv_nsec - inicio.tv_nsec;

    // Ajusta caso haja underflow nos nanossegundos
    if (nanosegundos < 0) {
        segundos--;
        nanosegundos += 1000000000;
    }

    // Imprime o resultado
    printf("Tempo de execução: %ld.%09lds\n", segundos, nanosegundos);
    #endif

    return 0;
}