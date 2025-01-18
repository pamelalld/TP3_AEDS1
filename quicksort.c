void particao(int esq, int dir, int *i,int *j, item *vetor, int *comparacoes, int *trocas){
    item pivo, aux;
    *i = esq; *j = dir;
    pivo = vetor[(*i+*j)/2];
    do{
        while (pivo.peso > vetor[*i].peso){
            (*i)++;
            (*comparacoes)++;
            }
        while (pivo.peso < vetor[*j].peso){
            (*j)--;
            (*comparacoes)++;
            }
        if (*i <= *j){
            aux = vetor[*i];
            vetor[*i]=vetor[*j];
            vetor[*j]=aux;

            (*trocas)++;
            (*i)++;
            (*j)--;
        }
    } while (*i<= *j);
}


void ordena (int esq, int dir, item *vetor, int *comparacoes,int *trocas){
    int i,j;
    particao(esq,dir,&i,&j,vetor,comparacoes,trocas);
    if (esq<j) {ordena(esq,j,vetor,comparacoes,trocas);}
    
    if (i<dir) {ordena(i,dir,vetor,comparacoes,trocas);}
}



void quicksort (item *vetor, int n){
    int comparacoes=0;
    int trocas=0;
    ordena(0,n-1,vetor,&comparacoes,&trocas);

    for (int k=0;k<n;k++){
        printf("%s %f\n",item.nome,item.peso);
    }
    printf("Comparacoes: %d\n",comparacoes);
    printf("Movimentacoes: %d\n",trocas);

}