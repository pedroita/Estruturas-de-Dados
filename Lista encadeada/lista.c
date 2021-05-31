#include <stdio.h>
#include <stdlib.h>
int lista[10];
int cont=0;
void lista(int elemento,int pos)
{
  int i;
  //add inicio
  if (pos==0)
  {
    for (i=cont;i>0;i--)
    {
      lista[i]=lista[i-1];
    }
   lista[0]=elemento;
   cont++; 
  }else if (pos==cont)
  {//add final
    lista[cont]=elemento;
    cont++;
  }else
  {// add meio
    int i;
    for (i=cont;i>pos;i--)
    {
    lista[i]=lista[i-1] 
    }  
  lista[pos]=elemento;
  cont++
}
 
}
/*função remover*/

int remover(int pos) 
{
  if (pos < cont) 
  {
    if (pos == 0) 
    {
      int aux = lista[pos];
      int i;
      for (i = 0; i < cont; i++) 
      {
        lista[i] = lista[i + 1];
        /*remover inicio*/
      }
      cont--;
    } else if (pos == cont - 1) 
    {
      int aux = lista[pos];
      cont--;
      /*remover final*/
    }
    else 
    {
      int i;
      aux lista[pos];
      if (pos>0 && pos<cont){
      for (i=cont;i<pos;i--){
       lista[i]=lista[i-1];
       /*remover no meio*/
      }
      cont++;
     }
      
    }
  }
}

int buscar (int pos)
{
  if (pos==0) /* no caso da posição está zerada*/
  { 
    return pos;
  } if (pos>0 && pos==cont) 
  {
    return cont;
  }
  else if (pos>0 && pos<cont)
  {
    int i;
    for (i=cont;i<pos;i--) /* buscar no meio*/
    {
      return lista[i-1];
    }
  }
  else 
  {
    printf ("ERRO 404");
  }
}

void alterar (int elemento , int pos)
{
  int aux=lista[0];
  if (pos==0) /* Alterar no inicio */
  {
    int i;
    for (i=pos;i>0;i--)
    {
      lista[i]=lista[i-1];
    }
    lista[0]== elemento;
    cont++;
  }if (pos>0 && pos==cont) /*alterar no fim*/
  {
    lista[cont]=elemento ;
    cont++;
  }else if (pos>0 && pos<cont-1)/* no meio*/
  {
    int aux=lista[pos-1];
    int i;
    for (i=cont;i>0;i-- ){
      lista[pos]=lista[pos-1];
    }
    lista[pos-1]=elemento;
    cont ++;
  }

}