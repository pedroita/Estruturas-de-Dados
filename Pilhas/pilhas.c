#include <stdio.h>
#include <stdlib.h>
typedef struct no
{
    int id;
    struct no*prox;


}NO;

NO *topo = NULL;
int tam=0;

void add (int id)
{
  NO *NOVO = malloc(sizeof(NO));
  NOVO->id=id;
  NOVO->prox=NULL;
  if(topo==NULL){
    topo=NOVO;
  }else{
    NOVO->prox=topo;
    topo=NOVO;
  }
}

int remover()
{
    if (tam>0){
        NO *lixo =topo;
    topo=topo->prox;
    int retorno = lixo->id;
    free(lixo);
    tam--;
    return retorno;
    }else{
        printf ("lista vazia");
        return -1;
    }
}

void imprimir(){
    NO *aux =topo;
    while(aux!=NULL){
        printf ("\n%d",aux->id);
        aux= aux->prox;
    }

}
int main ()
{
    add(5);
    add(9);
    imprimir();
    return 0;

}
