#include <stdio.h>
#include <stdlib.h>
//20.08.20
//criar um no
typedef struct no
{
    int valor;

    struct no* prox;
    struct no* ant;

}NO;
//amazenzar o valores de no
NO * inicio = NULL;
NO * fim = NULL;
int tam =0;
//função adicioar
void adicionar (int valor, int pos)
{
    //inicialiar um no
    if (pos>=0 && pos<=tam)
    {
        //alocar o valor do no
        NO*NOVO=(NO*)malloc (sizeof(NO));
        NOVO->valor=valor;
        NOVO->prox=NULL;
        NOVO->ant=NULL;
        if (inicio==NULL){
            inicio=NOVO;
            fim=NOVO;
        }else if(pos==0)
        {
            NOVO->prox=inicio;
            inicio->ant=NOVO;
            inicio=NOVO;

        }else if (pos==tam)
        {
            fim->prox=NOVO;
            NOVO->ant=fim;
            fim=NOVO;

        }else
        {
            int i;
            NO * aux=inicio;
            for (i=0;i<pos;i++)
            {
                aux=aux->prox;
            }
            NOVO->prox=aux;
            NOVO->ant=aux->ant;
            aux->ant->prox=NOVO;
            aux->ant=NOVO;
        }
    }
    tam++;
}

void remover(int pos){
    NO *lixo;
    if(tam == 1 && pos == 0){ //lista tem 1 elemento
        lixo = inicio;
        inicio = NULL;
        fim = NULL;
        tam--;
        free(lixo);
    }else if(pos == 0){ // nao esta vazia e inicio
        lixo = inicio;
        inicio = inicio->prox;
        inicio->ant = NULL;
        tam--;
        free(lixo);
    }else if(pos == tam -1){ //remover no fim
        lixo = fim;
        fim->ant->prox = NULL;
        fim = fim->ant;
        tam--;
        free(lixo);
    }else if(pos >0 && pos <tam-1){//no meio :O
        NO *aux = inicio;
        int i;
        for(i=0; i<pos; i++){
            aux=aux->prox;
        }
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        tam--;
        free(aux);
    }
}

void imprimirEmOrdem(){
    NO *aux = inicio;
    printf("Em ordem:\n");
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");

}
int  main (){

    adicionar(5,0);
    adicionar(6,0);
    adicionar(7,2);
    adicionar(8,1);
    imprimirEmOrdem();
    remover(2);
    imprimirEmOrdem();
}
