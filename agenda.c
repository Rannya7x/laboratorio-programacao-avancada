//Conceitos básicos de estruturas de dados
//1. Lista encadeada

//1.1 Armazenar informações de um evento: double tempo, alvo, int tipo

//nó da árvore
#include "agenda.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
struct evento_t {
    double tempo;
    int alvo;
    int tipo;

};

typedef struct evento_t evento_t;

//1.2 Criar uma lista encadeada para armazenar os eventos
typedef struct lista_eventos_t {
    evento_t* evento;
    struct lista_eventos_t* proximo_evento;
} lista_eventos_t;

evento_t* criar_evento(double tempo, int alvo, int tipo) {
    evento_t* novo_evento = (evento_t*)malloc(sizeof(evento_t));
    novo_evento->tempo = tempo;
    novo_evento->alvo = alvo;
    novo_evento->tipo = tipo;

    return novo_evento;
}


bool lista_eventos_adicionar_inicio(evento_t* evento, lista_eventos_t** lista) {

    evento_t* novo_evento = criar_evento(evento->tempo, evento->alvo, evento->tipo);
    if (novo_evento == NULL){
        free(novo_evento);
        return false;
    }

    lista_eventos_t* nova_lista = (lista_eventos_t*)malloc(sizeof(lista_eventos_t));
    if(nova_lista == NULL ) return false;

    nova_lista->evento = novo_evento;
    nova_lista->proximo_evento = *lista;

    *lista = nova_lista;

    return true;
}
bool lista_eventos_adicionar_fim(evento_t* evento, lista_eventos_t** lista){
    evento_t* novo_evento = criar_evento(evento->tempo, evento->alvo, evento->tipo);
    lista_eventos_t* nova_lista = (lista_eventos_t*)malloc(sizeof(lista_eventos_t));
    
    if(evento == NULL) {
        free(novo_evento);
        return false;
    }
    
    nova_lista->evento = novo_evento;
    nova_lista->proximo_evento = NULL;   

    //lista vazia
    if(*lista == NULL) {
        *lista = nova_lista;
        return true;
    }
    //ponteiro caminhante
    lista_eventos_t* atual = *lista;
    while(atual->proximo_evento != NULL) {
        atual = atual->proximo_evento;
    }

    atual->proximo_evento = nova_lista;

    return true;
}

void lista_eventos_listar(lista_eventos_t* lista){
    lista_eventos_t* atual = lista;
    while (atual!=NULL){
        printf("Evento:\n tempo=%.2f,\n alvo=%d,\n tipo=%d",atual->evento->tempo, atual->evento->alvo, atual->evento->tipo);
        printf("\n");
        atual = atual->proximo_evento;
    }
}