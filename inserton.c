#include <stdio.h>
#include <stdlib.h>
void ordena(int n,item *vetor,int comp,int trocas){
    int i,j;
    item tmp;
    for(i=1;i<n;i++){
        tmp=vetor[i];
        for(j=i-1;j>=0 && tmp < vetor[j],j--){
            vetor[j+1] = vetor[j];
            vetor[j+1]= tmp;
        }
    }
}
void insertion_sort(ListadeRochas *vetor,int n){
    int comparacoes=0;
    int trocas=0;
    ordena(n,vetor,&comparacoes,&trocas);
    for (int k=0;k<n;k++){
        printf("%s %f\n",ListadeRochas,item.peso);
    }
    printf("Comparacoes: %d\n",comparacoes);
    printf("Movimentacoes: %d\n",trocas);
    printf("Algoritmo: Insertion sort");
}