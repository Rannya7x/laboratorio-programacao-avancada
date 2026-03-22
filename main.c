#include "stdio.h"
#include "agenda.h"
#include "stdlib.h"



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

    //cria lista
    lista_eventos_t* lista = NULL;
    //instancias para os dados dos eventos
    double tempo;
    int alvo, tipo;
    int cont=0;

    //percorre as linhas do arquivo
    printf("Inserindo no início da lista...\n");
    while (!feof(arquivo_entrada)){
        cont++;
        //lê linha;
        if (fscanf(arquivo_entrada, "%lf\t%d\t%d\n", &tempo, &alvo, &tipo) != 3) {
            printf("Erro na leitura");
            break;
        }
        
        //cria evento
        evento_t* evento = criar_evento(tempo, alvo, tipo);

        if (evento != NULL) lista_eventos_adicionar_inicio(evento, &lista);
    }

    //libera memoria do arquivo
    fclose(arquivo_entrada);

    lista_eventos_listar(lista);
    printf("Total de eventos: %d\n", cont);
    printf("---------FIM---------\n");
    
    return 0; 
}