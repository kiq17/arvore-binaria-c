#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int chave;
  struct No *esquerda, *direita;
}No;


typedef struct{
  No *raiz;
  int quant;
}Arvore;


void inserirNaEsquerda();
void inserirNaDireita();
void imprimirNos();

void inserirNaEsquerda(No *no, int valor, Arvore *arv){
  
  if(no->esquerda == NULL){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    
    no->esquerda = novo;
    arv->quant++;
  } else{ 
    if(valor < no->esquerda->chave){
      inserirNaEsquerda(no->esquerda, valor, arv);
    }
    
    if(valor > no->esquerda->chave){
      inserirNaDireita(no->esquerda, valor, arv);
    }
  }
}

void inserirNaDireita(No *no, int valor, Arvore *arv){
  
  if(no->direita == NULL){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    
    no->direita = novo;
    arv->quant++;
  } else{ 
    if(valor > no->direita->chave){
      inserirNaDireita(no->direita, valor, arv);
    } 
    
    if(valor < no->direita->chave){
      inserirNaEsquerda(no->direita, valor, arv);
    }
  }

}

void inserir(Arvore *arv, int valor){
  
  if(arv->raiz == NULL){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    arv->raiz = novo;
    arv->quant++;
  }else{ 
      if(valor < arv->raiz->chave){
        inserirNaEsquerda(arv->raiz, valor, arv);
      } 
    
      if(valor > arv->raiz->chave){
        inserirNaDireita(arv->raiz, valor, arv);
      }
  }
}


void imprimir(Arvore *arv){
  printf("Raiz da arvore: %d \n", arv->raiz->chave);
  printf("Quantidade de nós: %d \n", arv->quant);
  imprimirNos(arv->raiz);
  printf("\n");
}


void imprimirNos(No *raiz){
  if(raiz != NULL){
    imprimirNos(raiz->esquerda);
    printf("%d ", raiz->chave);
    imprimirNos(raiz->direita);
  }
 
}

int busca(No *raiz, int valor){
  if(raiz == NULL){
    return -1;
  } else{
    if(raiz->chave == valor){
      return raiz->chave; 
    } else{
      if(raiz->chave > valor){
        return busca(raiz->direita, valor);
      } else{
        return busca(raiz->esquerda, valor);
      }
    }
  }
}

void preOrdem(No *raiz){
  if(raiz != NULL){
    printf("%d ", raiz->chave);
    if(raiz->esquerda != NULL){
      preOrdem(raiz->esquerda);
    } 
      
    if(raiz->direita != NULL){
       preOrdem(raiz->direita);
    }
  }  
}

void simetrico(No *raiz){
  if(raiz != NULL){
    if(raiz->esquerda != NULL){
      simetrico(raiz->esquerda);
    } 

    printf("%d ", raiz->chave);
      
    if(raiz->direita != NULL){
       simetrico(raiz->direita);
    }
  }  
}

void posOrdem(No *raiz){
  if(raiz != NULL){
    if(raiz->esquerda != NULL){
      posOrdem(raiz->esquerda);
    } 
    if(raiz->direita != NULL){
       posOrdem(raiz->direita);
    }

    printf("%d ", raiz->chave);
  }  
}

int main(){
  int opcao, valor;
  Arvore arv;
  arv.raiz = NULL;
  arv.quant = 0;

  do{
        printf("\n1- Para inserir \n2- Para imprmir a arvore\n3- Percurso pré-ordem\n4- Percurso em ordem simétrica\n5- Percurso pós-ordem\n6- Para sair\n");
      scanf("%d", &opcao);
      switch(opcao){
         case 1:
                printf("Qual valor você que inserir?\n");
                scanf("%d", &valor);
                inserir(&arv, valor);
                break;
            case 2:
                printf("\nImpressão da arvore:\n");
                imprimir(&arv);
                break;
            case 3:
                printf("\nPercurso pré-ordem:");
                preOrdem(arv.raiz);
                break;
            case 4:
                printf("\nPercurso em ordem simétrica:");
                simetrico(arv.raiz);
                break;
            case 5:
                printf("\nPercurso pós-ordem:");
                posOrdem(arv.raiz);
                break;
            case 6:
                printf("Finalizando...");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 6);
  return 0;
}