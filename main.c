#include <stdio.h>
#include <stdlib.h>

typedef struct Bst{
    int valor;
    int cor;
    struct Bst* esquerda;
    struct Bst* direita;
}Bst;

int corPai = 0;

void Inserir(Bst** raiz, int valor, int cor){
    if(!(*raiz)){
        *raiz = (Bst*) malloc(sizeof(Bst));
        (*raiz)->valor = valor;
        (*raiz)->direita = NULL;
        (*raiz)->cor = cor;
        (*raiz)->esquerda = NULL;
    }
    else{
        Bst* auxiliar = *raiz;
        Bst* aux;
        int esc = 0;
        while(auxiliar != NULL){
            aux = auxiliar;
            if(auxiliar->valor > valor){
                auxiliar = auxiliar->direita;
                esc = 0;
            }else{
                auxiliar = auxiliar->esquerda;
                esc = 1;
            }
        }
        auxiliar = (Bst*) malloc(sizeof(Bst));
        auxiliar->valor = valor;
        auxiliar->direita = NULL;
        auxiliar->esquerda = NULL;
        auxiliar->cor = cor;
        if(esc == 0){
            aux->direita = auxiliar;
        }else{
            aux->esquerda = auxiliar;
        }
    }
}

int Buscar(Bst* arvore, int valor){
    Bst* auxiliar = arvore;
    while(auxiliar != NULL){
        if(auxiliar->valor == valor){
            return 1;
        }else{
            if(auxiliar->valor > valor){
                auxiliar = auxiliar->direita;
            }else{
                auxiliar = auxiliar->esquerda;
            }
        }
    }
    return 0;
}

int Verifica(Bst* raiz){
    if(raiz == NULL){
        return 1;
    }
    else{
        if((raiz->cor == 1) && (corPai == 1)){
            return 0;
        }else{
            corPai = raiz->cor;
            Verifica(raiz->direita);
            Verifica(raiz->esquerda);
        }
    }
}

int main()
{
    printf("Olá Usuario!\n");

    int valor;
    int cor;
    Bst* arvore = NULL;
    while(1){
        printf("Inserir: ");
        scanf("%i*c", &valor);
        printf("Cor: ");
        scanf("%i*c", &cor);
        if(valor == 0){
            break;
        }
        Inserir(&arvore, valor, cor);
    }

    while(1){
        printf("Buscar: ");
        scanf("%i", &valor);
        if(valor == 0){
            break;
        }
        if(Buscar(arvore, valor)){
            printf("Valor encontrado\n");
        }else{
            printf("Valor não encontrado\n");
        }
    }

    if(Verifica(arvore)){
        printf("É uma RBT\n");
    }else{
        printf("Não é uma RBT\n");
    }

    return 0;
}
