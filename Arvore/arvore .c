#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    //...
    struct no *esq;
    struct no *dir;
}NO;

NO* raiz = NULL;

void in_ordem(NO* pt){
    if(pt->esq != NULL){
         in_ordem(pt->esq);
    }
    printf("%d-", pt->chave);
    //qualquer processamento! Ex: imprimindo
    if(pt->dir != NULL){
       in_ordem(pt->dir);
    }
}

void pre_ordem(NO* pt)
{
    printf ("%d-",pt->chave);
    if(pt->esq!=NULL){
        pre_ordem(pt->esq);
    }
    if (pt->dir!=NULL){
        pre_ordem(pt->dir);
    }


}

void pos_ordem(NO * pt)
{
    if(pt->esq!=NULL)
    {
        pos_ordem(pt->esq);
    }
    if(pt->dir!=NULL)
    {
        pos_ordem(pt->dir);
    }

    printf("%d-",pt->chave);


}



NO* busca_arvore (int x, NO* pt){
    if(pt == NULL){
        return NULL; //vazia :D
    }else if(x == pt->chave){
        return pt; // encontrei :D
    }else if(x < pt->chave){ //lado esq
        if(pt->esq == NULL){ //eu n posso
            return pt;
        }else{
            return busca_arvore(x, pt->esq);
        }
    }else { //lado dir
        if(pt->dir == NULL){ //eu n posso
            return pt;
        }else{
            return busca_arvore(x, pt->dir);
        }
    }
}

void insercao_arvore(int x){
    NO* pt = busca_arvore(x, raiz); // usa a busca para encontrar
                                // a posicao do no novo
    if(pt == NULL || pt->chave != x){
        NO* novo = (NO*) malloc (sizeof(NO));
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;

        if(pt == NULL){ //vazia - raiz
            raiz = novo;
        }else if(x < pt->chave){ //elemento x <pt-> chave - esq
            pt->esq = novo;
        }else{                  //elemento x >pt-> chave - dir
            pt->dir = novo;
        }
    }else{
         printf("insercao invalida! :/");
    }
}

//REMOCAO...
NO * retirar (NO* pt,int x){
    if (pt==NULL){
        return NULL;
    }else if (x<pt->chave){
        pt->esq=retirar(pt->esq,x);
    }else if (x>pt->chave){
        pt->dir=retirar(pt->dir,x);
    }else {
        if (pt->esq==NULL && pt->dir==NULL){
            free(pt);
            return NULL;
        }else if (pt->esq==NULL){
            NO * aux=pt;
            pt=pt->dir;
            free(aux);
        }else if (pt->dir==NULL){
            NO * aux=pt;
            pt=pt->esq;
            free(aux);
        }else{
            NO * aux= pt->esq;
            while (aux->dir!= NULL){
                aux=aux->dir;
            }
            pt->chave=aux->chave;
            aux->chave=x;
            pt->esq=retirar(pt->esq,x);
        }
    }
    return pt;
}
int main(){
insercao_arvore(99);
    insercao_arvore(300);
    insercao_arvore(23);
    insercao_arvore(3);
    insercao_arvore(15);
    insercao_arvore(91);
    insercao_arvore(92);
    insercao_arvore(39);
    insercao_arvore(4);
    insercao_arvore(11);
    insercao_arvore(88);
    insercao_arvore(77);
    insercao_arvore(2020);
    insercao_arvore(1999);
    insercao_arvore(44);
    insercao_arvore(2018);
    insercao_arvore(55);
    insercao_arvore(79);
    insercao_arvore(7);
    insercao_arvore(678);
    insercao_arvore(21);
    insercao_arvore(2016);
    insercao_arvore(66);
    insercao_arvore(2021);
    printf ("\nValores da arvore antes de remover em ordem\n");
    in_ordem(raiz);
    printf("\n Valores da arvore antes de remover em pre-ordem\n");
    pre_ordem(raiz);
    printf("\n Valores da arvore antes de remover em pos-ordem\n");
    pos_ordem(raiz);

    retirar(raiz,99);
    retirar(raiz,3);
    retirar(raiz,11);
    retirar(raiz,2018);
    retirar(raiz,678);
    retirar(raiz,2021);
    retirar(raiz,88);
    retirar(raiz,66);
    retirar(raiz,23);
    retirar(raiz,1999);
    retirar(raiz,79);
    retirar(raiz,15);
    retirar(raiz,7);
    retirar(raiz,21);
    retirar(raiz,300);
    printf("\nValores apos a remocao em ordem\n");
    in_ordem(raiz);
    printf("\nValores apos a remocao pre-ordem\n");
    pre_ordem(raiz);
    printf("\nValores apos a remocao em pos-ordem\n");
    pos_ordem(raiz);

   return 0;
}
