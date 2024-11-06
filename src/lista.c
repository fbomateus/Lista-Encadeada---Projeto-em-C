#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

// Função para criar uma lista vazia
Lista* criarLista() {
    return NULL;
}

// Função para verificar se a lista está vazia
int verificarVazia(Lista* l) {
    return (l == NULL);
}

// Função para inserir um elemento no início da lista
Lista* inserirLista(Lista* l, int valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = l;
    return novo;
}

// Função para exibir a lista
void exibirLista(Lista* l) {
    Lista* p;
    if (verificarVazia(l)) {
        printf("A lista está vazia.\n");
        return;
    }
    for (p = l; p != NULL; p = p->prox) {
        printf("%d -> ", p->info);
    }
    printf("NULL\n");
}

// Função para buscar um elemento na lista
Lista* buscarLista(Lista* l, int valor) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == valor) {
            return p;
        }
    }
    return NULL;
}

// Função para excluir um elemento da lista
Lista* excluirLista(Lista* l, int valor) {
    Lista* anterior = NULL;
    Lista* p = l;
    
    // Procura o elemento na lista
    while (p != NULL && p->info != valor) {
        anterior = p;
        p = p->prox;
    }
    
    // Elemento não encontrado
    if (p == NULL) {
        printf("Elemento %d não encontrado.\n", valor);
        return l;
    }
    
    // Remove o elemento
    if (anterior == NULL) {
        // O elemento está no início
        l = p->prox;
    } else {
        // O elemento está no meio ou no final
        anterior->prox = p->prox;
    }
    free(p);
    printf("Elemento %d excluído.\n", valor);
    return l;
}

// Função para liberar a lista
void liberarLista(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* temp = p->prox;
        free(p);
        p = temp;
    }
    printf("Lista liberada.\n");
}

// Função para inserir elementos em ordem crescente
Lista* inserirEmOrdem(Lista* l, int valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;
    
    // Insere no início se a lista está vazia ou o valor é menor que o primeiro elemento
    if (verificarVazia(l) || l->info >= valor) {
        novo->prox = l;
        return novo;
    }
    
    // Procura o local correto para inserção
    Lista* p = l;
    while (p->prox != NULL && p->prox->info < valor) {
        p = p->prox;
    }
    novo->prox = p->prox;
    p->prox = novo;
    return l;
}

int main() {
    Lista* lista = criarLista();

    lista = inserirEmOrdem(lista, 3);
    lista = inserirEmOrdem(lista, 1);
    lista = inserirEmOrdem(lista, 5);
    lista = inserirEmOrdem(lista, 2);
    exibirLista(lista);

    printf("Buscando elemento 5:\n");
    Lista* encontrado = buscarLista(lista, 5);
    if (encontrado) {
        printf("Elemento %d encontrado.\n", encontrado->info);
    } else {
        printf("Elemento não encontrado.\n");
    }

    lista = excluirLista(lista, 3);
    exibirLista(lista);

    liberarLista(lista);
    
    return 0;
}
