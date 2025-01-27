#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/Arquivo.h"
#include "../include/Rocha.h"
#define  Max_linha    255
#define Max_minerais    3

/**
 * @brief Abre um arquivo informado no main.
 * @param nomeArquivo Contém o nome do arquivo a ser aberto
 * @param arquivo Onde o ptr FILE será armazenado
 */
void abrearquivo(char *nomeArquivo, Arquivo* arquivo){
    arquivo->Arquivo = fopen(nomeArquivo,"r");//abre o arquivo no modo leitura
    //arquivo->Arquivo acesa o ponteiro FILE dentro de Arquivo que o ponteiro arquivo aponta
    
    if(arquivo->Arquivo == NULL){
        printf("Error arquivo\n");
        return;
    }
}
void fechaArquivo(Arquivo *arquivo){
    fclose(arquivo->Arquivo);
}
/**
 * @brief lê do arquivo um número que representa a quantidade de rochas presentes no array. 
 */
int qtdoperacao(Arquivo *arquivo){
    if (arquivo->Arquivo == NULL) {
        fprintf(stderr, "O arquivo não está aberto\n");
        exit(EXIT_FAILURE);
    }
    int n;
    fscanf((arquivo->Arquivo),"%d",&n);
    fgetc(arquivo->Arquivo);
    return n;
}


/**
 * @brief lê do arquivo uma rocha depois que a operação R é chamada.
 * @param arquivo Contém o arquivo que esta sendo lido.
 * @param id_rocha Id da amostra de rocha encontrada.
 * @return Retorna uma Rocha já categorizada.
 */
RochaMineral ler_rocha(Arquivo *arquivo){
    char linha[Max_linha];
    float lat_r,lon_r,peso;  
    RochaMineral coleta;
    
    if (fgets(linha, Max_linha, arquivo->Arquivo) == NULL) {
        printf("Erro ao ler linha do arquivo.\n");
        exit(EXIT_FAILURE);
    }   
    
    char*buffer =NULL;
    const char delim[2]= " ";
    buffer = strtok(linha,delim);
    if (buffer == NULL) {
        printf("Erro ao ler latitude.\n");
        exit(EXIT_FAILURE);
    }
    lat_r=atof(buffer);
    
    buffer = strtok(NULL,delim);
    if (buffer == NULL) {
        printf("Erro ao ler longitude.\n");
        exit(EXIT_FAILURE);
    }
    lon_r=atof(buffer);
    
    buffer= strtok(NULL,delim);
    if (buffer == NULL) {
        fprintf(stderr, "Erro ao ler peso.\n");
        exit(EXIT_FAILURE);
    }
    peso = atof(buffer);
    
    int i=0;
    char *minerais[Max_minerais];
    
      while ((buffer = strtok(NULL, delim)) != NULL) {
        if (i < Max_minerais) {
            minerais[i] = malloc(strlen(buffer) + 1); // Aloca espaço suficiente para a string
            if (minerais[i] == NULL) {
                printf("Erro ao alocar memória para minerais[%d].\n", i);
                exit(EXIT_FAILURE); // Encerra se a alocação falhar
            }

            strcpy(minerais[i], buffer); // Copia o nome do mineral

            // Remover o '\n' final, se presente
            if (minerais[i][strlen(minerais[i]) - 1] == '\n') {
                minerais[i][strlen(minerais[i]) - 1] = '\0';
            }

            i++;
        }
    }
    
    inicializa_lista_minerais(&coleta.minerais);
    for(int j=0;j<i;j++){
        Mineral mineral;
        inicializa_mineral(&mineral,minerais[j]);
        
        insere_mineral(&coleta.minerais,mineral);
    }
    
    Inicializa_Rocha(&coleta,&coleta.minerais,peso,lat_r,lon_r);
    
    return coleta;
}

