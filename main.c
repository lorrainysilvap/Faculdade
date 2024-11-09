#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int valor;
  struct No *esquerda;
  struct No *direita;
} No;

No *inserir(No *raiz, int valor);
No *criarNo(int valor);


int imprimiremOrdem(No* raiz) {
  if (raiz == NULL) {
    return 0;
  }
  imprimiremOrdem(raiz -> esquerda);
  printf("%d\n", raiz -> valor);
  imprimiremOrdem(raiz -> direita);
  return 0;
}

int imprimirPreOrdem(No* raiz) {
  if (raiz == NULL) {
    return 0;
  }
  printf("%d\n", raiz -> valor);
  imprimirPreOrdem(raiz -> esquerda);
  imprimirPreOrdem(raiz -> direita);
  return 0;
}

int imprimirPosOrdem(No* raiz) {
  if (raiz == NULL) {
    return 0;
  }
  imprimirPosOrdem(raiz -> esquerda);
  imprimirPosOrdem(raiz -> direita);
  printf("%d\n", raiz -> valor);
  return 0;
}

int main() {
  No *raiz = NULL;
  raiz = inserir(raiz, 15);
  raiz = inserir(raiz, 11);
  raiz = inserir(raiz, 8);
  raiz = inserir(raiz, 7);
  raiz = inserir(raiz, 9);
  raiz = inserir(raiz, 13);
  raiz = inserir(raiz, 12);
  raiz = inserir(raiz, 14);
  raiz = inserir(raiz, 19);
  raiz = inserir(raiz, 17);
  raiz = inserir(raiz, 16);
  raiz = inserir(raiz, 18);
  raiz = inserir(raiz, 40);
  raiz = inserir(raiz, 35);
  raiz = inserir(raiz, 42);

  printf("valores em ordem:\n");
  imprimiremOrdem(raiz);
  printf("-------------------------");

  printf("\nvalores em pre-ordem:\n");
  imprimirPreOrdem(raiz);
  printf("-------------------------");

  printf("\nvalores em pos-ordem:\n");
  imprimirPosOrdem(raiz);
  printf("-------------------------");
  
  return 0;
}
No* inserir(No *raiz, int valor) {
  if (raiz == NULL) {
    return criarNo(valor);
  }
  if (valor < raiz->valor) {
    raiz->esquerda = inserir(raiz->esquerda, valor);
  } else if (valor > raiz->valor) {
    raiz->direita = inserir(raiz->direita, valor);
  }
  return raiz;
}

No* criarNo(int valor) {
  No* novoNo = (No*)malloc(sizeof(No));
  novoNo->valor = valor;
  novoNo->esquerda = NULL;
  novoNo->direita = NULL;
  return novoNo;
}

