#include "stdio.h"
#include "agenda.h"
#include "stdlib.h"
#include "stdbool.h"



int main(int argc, char* argv[]) {

    //verifica se argumentos foram passados
    if (argc != 2) {
        printf("Argumento faltante: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }
    
    //ler o arquivo
    FILE* arquivo_entrada = fopen(argv[1], "r");
    if (arquivo_entrada == NULL) {
        printf("Erro ao ler o arquivo.\n");
        return 1;
    }

    //array das funções 
    bool(*array_funcao[])(evento_t*, lista_eventos_t**) = {
        lista_eventos_adicionar_inicio,
        lista_eventos_adicionar_fim,
        lista_eventos_adicionar_ordenado
    };

    char* testes[] = {"Inicio", "Fim", "Ordenado"};
    int num_testes = sizeof(testes) / sizeof(testes[0]);

    for (int i = 0; i < num_testes; i++){
        //reinicia lista
        lista_eventos_t* lista = NULL;

        //retorna para o início do arquivo 
        rewind(arquivo_entrada);
        
        //instancias para os dados dos eventos
        double tempo;
        int alvo, tipo;
        int cont=0;

        //percorre as linhas do arquivo
        printf("Inserindo no %s da lista...\n", testes[i]);
        while (!feof(arquivo_entrada)){
            cont++;
            //lê linha;
            if (fscanf(arquivo_entrada, "%lf\t%d\t%d\n", &tempo, &alvo, &tipo) != 3) {
                printf("Erro na leitura");
                break;
            }
            
            //cria evento
            evento_t* evento = criar_evento(tempo, alvo, tipo);
            
            //chama a função da rodade atual: inicio, fim ou ordenado
            if (evento != NULL) array_funcao[i](evento, &lista);
        }

        lista_eventos_listar(lista);
        printf("Total de eventos: %d\n", cont);
        printf("---------FIM---------\n");
    }
    
    
    return 0; 
}