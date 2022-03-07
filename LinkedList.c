/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Segundo Semestre de 2021                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP 1 - Lista Ligada de Produtos                               **/
/**                                                                 **/
/**   <Augusto Prado Yassuda>                   <12543210>          **/
/**                                                                 **/
/*********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#define NUMTIPOS 10
#define true 1
#define false 0

typedef int bool;

typedef struct aux {
  int id;
  int quantidade;
  int valorUnitario;
  struct aux* proxProd;
} REGISTRO, * PONT;

typedef struct {
  PONT LISTADELISTAS[NUMTIPOS];
} LISTADEPRODUTOS, * PLISTA;

PLISTA criarLista();

int tamanho(PLISTA l);

int consultarValorUnitario(PLISTA l, int id);

PONT buscarID(PLISTA l, int id);

PONT buscarIDTipo(PLISTA l, int id, int tipo);

bool inserirNovoProduto(PLISTA l, int id, int tipo, int quantidade, int valor);

bool atualizarValorDoProduto(PLISTA l, int id, int valor);

bool removerItensDeUmProduto(PLISTA l, int id, int quantidade);

PLISTA criarLista(){
  PLISTA res = (PLISTA) malloc(sizeof(LISTADEPRODUTOS));
  int x;
  for (x=0;x<NUMTIPOS;x++){
    res->LISTADELISTAS[x]=(PONT) malloc(sizeof(REGISTRO));
    res->LISTADELISTAS[x]->id=-1;
    res->LISTADELISTAS[x]->quantidade=0;
    res->LISTADELISTAS[x]->valorUnitario=0;
    res->LISTADELISTAS[x]->proxProd=NULL;
  }
  return res;
}

int tamanho(PLISTA l){
  int tam = 0;
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual) {
      atual = atual->proxProd;
      tam++;
    }
  }
  return tam;
}

PONT buscarID(PLISTA l, int id){
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual) {
      if (atual->id == id) return atual;
      atual = atual->proxProd;
    }
  }
  return NULL;
}

PONT buscarTipo(PLISTA l, int id){
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual) {
      if (atual->id == id) return x;
      atual = atual->proxProd;
    }
  }
  return NULL;
}

PONT buscarIDTipo(PLISTA l, int id, int tipo){
  if (tipo<0 || tipo>=NUMTIPOS) return NULL;
  PONT atual = l->LISTADELISTAS[tipo]->proxProd;
  while (atual) {
    if (atual->id == id) return atual;
    atual = atual->proxProd;
  }
  return NULL;
}

void exibirLog(PLISTA f){
  int numElementos = tamanho(f);
  printf("Log lista [elementos: %i]\n", numElementos);
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    printf("  #TIPO: %i -> ", x);
    atual = f->LISTADELISTAS[x]->proxProd;
    while (atual){
      printf(" [%i;%i;%i;$%i]", atual->id, atual->quantidade, atual->valorUnitario, atual->quantidade*atual->valorUnitario);
      atual = atual->proxProd;
    }
    printf("\n");
  }
  printf("\n");
}

int consultarValorUnitario(PLISTA l, int id){
  int x;
  PONT atual;
  for (x=0;x<NUMTIPOS;x++){
    atual = l->LISTADELISTAS[x]->proxProd;
    while (atual) {
      if (atual->id == id) return atual->valorUnitario;
      atual = atual->proxProd;
    }
  }
  return 0;
}

bool inserirNovoProduto(PLISTA l, int id, int tipo, int quantidade, int valor){
	
  if (tipo < 0 ||  tipo > (NUMTIPOS - 1) ||  id < 0 || quantidade < 0 || valor < 0 ) return false;
  if(buscarID(l, id) != NULL) return false;
  double q,v;
        PONT novo = (PONT) malloc(sizeof(REGISTRO));     

        if(l->LISTADELISTAS[tipo]->proxProd == NULL){
            //lista vazia
            l->LISTADELISTAS[tipo]->proxProd = novo;         
            novo->id = id;
            novo->quantidade=quantidade;
            novo->valorUnitario = valor;
            novo->proxProd = NULL; 
            return true;
        }
        novo->id = id;
        novo->quantidade=quantidade;
        novo->valorUnitario=valor;
        double total = valor*quantidade;
        PONT ant = l->LISTADELISTAS[tipo];
        PONT prox = l->LISTADELISTAS[tipo]->proxProd;



        while((novo->quantidade * novo->valorUnitario) > (prox->valorUnitario * prox->quantidade)){ 

            if(prox->proxProd == NULL){
              ant = prox;
              prox->proxProd = novo;
              novo->proxProd = NULL;
              return true;
            }
            ant = prox;
            prox = prox->proxProd;
        }
        novo->proxProd = prox;
        ant->proxProd = novo; 
        return true;
        return false;

}

int tamanhoLista(PLISTA l, int tipo){
  int tam = 0;
  PONT atual = l->LISTADELISTAS[tipo]->proxProd;
  PONT ant = l->LISTADELISTAS[tipo];
  /*if(atual->proxProd == NULL && ant->proxProd == atual){
      tam = 1;
      printf("so ha um produto");
      return tam;
      }	*/
  while(atual){
    atual = atual->proxProd;
    tam++;
  }
  return tam;
}

bool removerItensDeUmProduto(PLISTA l, int id, int quantidade){
  		PONT atual = buscarID(l, id);
  		int tipo = buscarTipo(l, id);
  		PONT prox = l->LISTADELISTAS[tipo]->proxProd; // 1º produto
  		PONT ant = l->LISTADELISTAS[tipo];
  		if((atual == NULL) || (atual->id == NULL) ||  id <  0 || quantidade <= 0 ){
      		return false;
 		}
		
  		atual->quantidade = atual->quantidade - quantidade;
  		
  		if(atual->quantidade < 0){
  		    return false;
		}
		
		if(prox->proxProd == NULL && ant->proxProd != NULL){ // so tem um item na lista
		if(atual->quantidade == 0){
			ant->proxProd = NULL;
			free(atual);
		}
		return true;
		}
		
		while(prox->proxProd != NULL){
			if(prox->id == atual->id){
				break;
			}
			ant = prox;
			prox = prox->proxProd;
		}
		ant->proxProd = atual->proxProd; // retira o atual da lista
		
		prox = l->LISTADELISTAS[tipo]->proxProd;
		ant = l->LISTADELISTAS[tipo];
  		while((atual->quantidade * atual->valorUnitario) > (prox->valorUnitario * prox->quantidade)){ //inserindo atual no lugar correto
  			if(prox->proxProd == NULL){
  				ant->proxProd = prox;
  				prox->proxProd = atual;
  				atual->proxProd = NULL;
  				return true;
			  }
			  ant = prox;
			  prox = prox->proxProd;
             
  		}
  		atual->proxProd = prox;
  		ant->proxProd = atual;
  		if(atual->quantidade == 0){
  			ant->proxProd = atual->proxProd;
			free(atual);
		}
		return true;
      return false;
}

bool atualizarValorDoProduto(PLISTA l, int id, int valor){

  /* COMPLETAR */
  
		PONT atual = buscarID(l, id);
  		int tipo = buscarTipo(l, id);
  		PONT prox = l->LISTADELISTAS[tipo]->proxProd; // 1º produto
  		PONT ant = l->LISTADELISTAS[tipo];
  		if((atual == NULL)|| (atual->id == NULL) || id <  0 || valor <= 0 ){
      		return false;
 		}
  		atual->valorUnitario = valor;
		if(prox->proxProd == NULL && ant->proxProd != NULL){ // so tem um item na lista
		return true;
		}
		
		while(prox->proxProd != NULL){
			if(prox->id == atual->id){
				break;
			}
			ant = prox;
			prox = prox->proxProd;
		}
		ant->proxProd = atual->proxProd; // retira o atual da lista
		
		prox = l->LISTADELISTAS[tipo]->proxProd;
		ant = l->LISTADELISTAS[tipo];
  		while((atual->quantidade * atual->valorUnitario) > (prox->valorUnitario * prox->quantidade)){ //inserindo atual no lugar correto
  			if(prox->proxProd == NULL){
  				ant->proxProd = prox;
  				prox->proxProd = atual;
  				atual->proxProd = NULL;
  				return true;
			  }
			  ant = prox;
			  prox = prox->proxProd;
             
  		}
  		atual->proxProd = prox;
  		ant->proxProd = atual;
		return true;
  return false;
}



int main() {
  PLISTA f = criarLista();
  int id;
  int tipo;
  int quantidade;
  int valor;
  bool res;

  printf("################# INSERINDO #######################\n");

  exibirLog(f);
  res = inserirNovoProduto(f, 2, 1, 22, 23);
  if(res) printf("Insercao retornou true (1)\n");
  else printf("Insercao retornou false (1)\n");
  exibirLog(f);
  res = inserirNovoProduto(f, 4, 4, 4, 4);
  if(res) printf("Insercao retornou true (2)\n");
  else printf("Insercao retornou false (2)\n");
  exibirLog(f);
  res = inserirNovoProduto(f, 6, 1, 8, 9);
  if(res) printf("Insercao retornou true (3)\n");
  else printf("Insercao retornou false (3)\n");
  exibirLog(f);
  res = inserirNovoProduto(f, 3, 1, 22, 23);
  if(res) printf("Insercao retornou true (4)\n");
  else printf("Insercao retornou false (4)\n");
  exibirLog(f);

  res = inserirNovoProduto(f, -5, 6, 7, 8);
  if(res) printf("Insercao retornou true (5)\n");
  else printf("Insercao retornou false (5)\n");
  exibirLog(f);

  res = inserirNovoProduto(f, 5, -6, 7, 8);
  if(res) printf("Insercao retornou true (6)\n");
  else printf("Insercao retornou false (6)\n");
  exibirLog(f);

  res = inserirNovoProduto(f, 5, 6, -7, 8);
  if(res) printf("Insercao retornou true (7)\n");
  else printf("Insercao retornou false (7)\n");
  exibirLog(f);

  res = inserirNovoProduto(f, 5, 6, 7, -8);
  if(res) printf("Insercao retornou true (8)\n");
  else printf("Insercao retornou false (8)\n");
  exibirLog(f);
 
  res = inserirNovoProduto(f, 3, 1, 9, 9);
  if(res) printf("Insercao retornou true (9)\n");
  else printf("Insercao retornou false (9)\n");
  exibirLog(f);


  printf("################# REMOVENDO #######################\n");
  res = removerItensDeUmProduto(f, 4, 1);
  if(res) printf("Remocao retornou true (1)\n");
  else printf("Remocao retornou false (1)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 2, 1);
  if(res) printf("Remocao retornou true (2)\n");
  else printf("Remocao retornou false (2)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 3, 22);
  if(res) printf("Remocao retornou true (3)\n");
  else printf("Remocao retornou false (3)\n");
  exibirLog(f);


  res = removerItensDeUmProduto(f, 20, 1);
  if(res) printf("Remocao retornou true (4)\n");
  else printf("Remocao retornou false (4)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 5, 10);
  if(res) printf("Remocao retornou true (5)\n");
  else printf("Remocao retornou false (5)\n");
  exibirLog(f);

  res = removerItensDeUmProduto(f, 4, 0);
  if(res) printf("Remocao retornou true (6)\n");
  else printf("Remocao retornou false (6)\n");
  exibirLog(f);



  printf("################# ATUALIZANDO VALOR #######\n");

  res = atualizarValorDoProduto(f, 6, 1);
  if(res) printf("Atualizacao retornou true (1)\n");
  else printf("Atualizacao retornou false (1)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 6, 600);
  if(res) printf("Atualizacao retornou true (2)\n");
  else printf("Atualizacao retornou false (2)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 6, 20);
  if(res) printf("Atualizacao retornou true (3)\n");
  else printf("Atualizacao retornou false (3)\n");
  exibirLog(f);


  res = atualizarValorDoProduto(f, 6, 0);
  if(res) printf("Atualizacao retornou true (4)\n");
  else printf("Atualizacao retornou false (4)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 6, -100);
  if(res) printf("Atualizacao retornou true (5)\n");
  else printf("Atualizacao retornou false (5)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 61, 600);
  if(res) printf("Atualizacao retornou true (6)\n");
  else printf("Atualizacao retornou false (6)\n");
  exibirLog(f);

 

  res = atualizarValorDoProduto(f, 6, 3);
  if(res) printf("Atualizacao retornou true (7)\n");
  else printf("Atualizacao retornou false (7)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 4, 200);
  if(res) printf("Atualizacao retornou true (8)\n");
  else printf("Atualizacao retornou false (8)\n");
  exibirLog(f);

  res = atualizarValorDoProduto(f, 2, 20);
  if(res) printf("Atualizacao retornou true (9)\n");
  else printf("Atualizacao retornou false (9)\n");
  exibirLog(f);




  return 0;
}